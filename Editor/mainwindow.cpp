#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <custom.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Custom custom;
}

MainWindow::~MainWindow()
{
    delete ui;
}

