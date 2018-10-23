#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mSystemTrayIcon = new QSystemTrayIcon(this);
    mSystemTrayIcon->setIcon(QIcon(":/iris_logo.png"));
    mSystemTrayIcon->setVisible(true);

    systemTrayMenu = new QMenu("Context menu");
    systemTrayMenu->setToolTipsVisible(true);

    actionOpen=systemTrayMenu->addAction("Open");
    connect(actionOpen, SIGNAL(triggered()), this, SLOT(on_actionOpen_triggered()));
    actionExit=systemTrayMenu->addAction("Exit");
    connect(actionExit, SIGNAL(triggered()), this, SLOT(on_actionExit_triggered()));

    mSystemTrayIcon->setContextMenu(systemTrayMenu);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionOpen_triggered()
{
    bool isHidden = this->isHidden();

    if (isHidden)
        this->show();
    else
        this->hide();

}

void MainWindow::on_actionAboutQT_triggered()
{
    QMessageBox::aboutQt(this, tr("Information about Qt"));
}

void MainWindow::on_pushButton_clicked()
{
     mSystemTrayIcon->showMessage(tr("Message"), tr("Iris is the best software!"));
}
