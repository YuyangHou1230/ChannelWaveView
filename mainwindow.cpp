#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRandomGenerator>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int size = QRandomGenerator::global()->bounded(4,20);
    QList<int> datas;
    for(int i=0; i < size; i++){
        int value = QRandomGenerator::global()->bounded(0,  100);
        datas.append(value);
    }

    qDebug() << "size:" << size << "data:" << datas;

    ui->widget->setData(datas);

    static int mode = 0;
    mode = (mode +1) % 3 ;
    ui->widget->setViewMode(WaveView::ViewMode(mode));
}
