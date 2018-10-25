#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSystemTrayIcon>
#include <QMainWindow>
#include <QSettings>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QSettings* settings;
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();

    void on_actionAboutQT_triggered();

    void on_pushButton_clicked();

    void on_actionExit_triggered();

    void on_actionOpen_triggered();

    void on_HideWindowByDefault_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *mSystemTrayIcon;
    QMenu *systemTrayMenu;
    QAction* actionExit;
    QAction* actionOpen;

};

#endif // MAINWINDOW_H
