#include "mainwindow.h"
#include "layout_macros.h"

#include <QEvent>
#include <QKeyEvent>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    {
        auto s = new QShortcut(this);
        s->setKey(Qt::Key_A);
        connect(s, &QShortcut::activated, this, [] {
            // TODO print
        });
    }
}

MainWindow::~MainWindow()
{
}

bool MainWindow::event(QEvent *event)
{
    switch (event->type()) {
    // does it bubble up??
    case QEvent::KeyPress:
        return keyPressed(dynamic_cast<QKeyEvent*>(event));
    case QEvent::KeyRelease:
        return keyReleased(dynamic_cast<QKeyEvent*>(event));
    default:
        return QMainWindow::event(event);
    }
}

bool MainWindow::keyPressed(QKeyEvent *event)
{
    // TODO print
    return true;
}

bool MainWindow::keyReleased(QKeyEvent *event)
{
    // TODO print
    return true;
}
