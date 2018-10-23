#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSystemTrayIcon>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();

    void on_actionAboutQT_triggered();

    void on_pushButton_clicked();

    void on_actionExit_triggered();

    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *mSystemTrayIcon;
    QMenu *systemTrayMenu;
    QAction* actionExit;
    QAction* actionOpen;
};

#endif // MAINWINDOW_H
