#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gScene = QSharedPointer<GScene>::create(this);
    ui->verticalLayout->addWidget(gScene.data());

    connect(&timer, &QTimer::timeout, this, [=]()
            {
                ui->label_7->setText(QString::number(gScene->getVecEllipse().size()) + " целей");
            });

    timer.start(300);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->label_3->setText(QString::number(gScene->DBscaning(ui->lineEdit->text().toInt(), ui->lineEdit_2->text().toInt()), 10) + " за мсек");
}


void MainWindow::on_pushButton_3_clicked()
{
    gScene->mouseMoveCreate();
}


void MainWindow::on_pushButton_4_clicked()
{
    gScene->cleaning();
}

