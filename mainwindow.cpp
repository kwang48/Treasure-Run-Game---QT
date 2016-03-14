/**
  Katherine Wang
  Assignment 5
  Description: Main window
  */
#include "mainwindow.h"
#include "ui_mainwindow.h"

Game * game;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    game = new Game();  ///< Opening the game
}
