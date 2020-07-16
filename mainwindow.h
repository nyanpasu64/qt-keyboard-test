#pragma once

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool event(QEvent *event) override;
    bool keyPressed(QKeyEvent* event);
    bool keyReleased(QKeyEvent* event);
};
