#include "mainwindow.h"
#include "layout_macros.h"

#include <fmt/format.h>

#include <QEvent>
#include <QKeyEvent>
#include <QShortcut>
#include <QBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto w = this;
    {add_central_widget(QWidget(this), QVBoxLayout(w));
        {append_widget(QLabel(parent));
            w->setText(
                "This window has a QShortcut bound to Key_A, and logs all QKeyEvent and QShortcut activations to console.\n"
                "Test keypresses on various OSes and key layouts!"
            );
        }
    }

    {
        auto s = new QShortcut(this);
        s->setKey(Qt::Key_A);
        connect(s, &QShortcut::activated, this, [] {
            fmt::print(stderr, "QShortcut::activated\n");
        });
    }
}

MainWindow::~MainWindow()
{
}

bool MainWindow::event(QEvent *event)
{
    switch (event->type()) {
    // Base class (QMainWindow::event()) is never called.
    // If we return true, event does not bubble to parent widgets.

    case QEvent::KeyPress:
        return keyPressed(dynamic_cast<QKeyEvent*>(event));

    case QEvent::KeyboardLayoutChange:
        // Event is never sent. We cannot detect keyboard layout changes.
        // https://bugreports.qt.io/browse/QTBUG-27681
        fmt::print(stderr, "QEvent::KeyboardLayoutChange");
        return true;

    case QEvent::KeyRelease:
        return keyReleased(dynamic_cast<QKeyEvent*>(event));

    default:
        return QMainWindow::event(event);
    }
}

static constexpr auto str = FMT_STRING(
R"({}
    key={}
    scancode={}
    vkey={}
    mod={}
)"
);

bool MainWindow::keyPressed(QKeyEvent *event)
{
    // TODO print
    fmt::print(stderr, str, "QEvent::KeyPress", event->key(), event->nativeScanCode(), event->nativeVirtualKey(), event->nativeModifiers());
    return true;
}

bool MainWindow::keyReleased(QKeyEvent *event)
{
    // TODO print
    fmt::print(stderr, str, "QEvent::KeyRelease", event->key(), event->nativeScanCode(), event->nativeVirtualKey(), event->nativeModifiers());
    return true;
}
