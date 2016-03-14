/**
 * Name Katherine Wang
 * Assignment 5
 * Description Opens the game class UI
 */
//#include "game.h"
#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ///creating a main window object
    MainWindow w;

    ///opening the main window object that leads to the instructions and start option
    w.show();

    return a.exec();
}
