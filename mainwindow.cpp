#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QSettings>

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

    settings = new QSettings("Iris Tech", "Iris");
    int showOrHide = settings->value("ShowOrHide", -1).toInt();
    if (showOrHide==-1)
    {
        settings->setValue("ShowOrHide", 0);
        hide();
    }
    else
    {
        if (showOrHide==0)
        {
            hide();
            ui->HideWindowByDefault->setCheckState(Qt::Checked);

        }
        if (showOrHide==1)
        {
            show();
            ui->HideWindowByDefault->setCheckState(Qt::Unchecked);
        }
    }


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


void MainWindow::on_HideWindowByDefault_stateChanged(int arg1)
{
    if (arg1==0)
    {
        settings->setValue("ShowOrHide", 1);
    }
    else
    {
        settings->setValue("ShowOrHide", 0);

    }
}
