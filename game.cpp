/**
  Katherine Wang
  Assignment 5
  Description: This class creates the visual interface and also spawns the player and the enemies.
  */

#include "Game.h"

#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>

#include <QMediaPlayer>
#include <QImage>

#include "Weapon.h"

Game::Game(QWidget * parent)



{
///---------------SCENE--------------///

    scene = new QGraphicsScene();                         ///< Create a scene
    scene->setSceneRect(0,0,800,600);                     ///< Setting the scene max, 800 by 600
    setBackgroundBrush(QBrush(QImage(":/new/images/Black-Brick-Wall-Background.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); ///<Disabling scroll bars
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   ///<Disabling scroll bars
    setFixedSize(800,600);                                 ///< Scene is 800 by 600, but will still expand

///------------End Scene-------------//

///------------Player Creation--------//
    ///Create an item to put into the scene
    player = new Player();
    player->setPos(400,450);
    ///make the player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    ///add the player to the scene
    scene->addItem(player);

///-----------End Player Creation--------//

    ///---Creating score and health---//
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);
    ///---End score/health creation---//

    ///---Enemies and treasure chest creation--//

    ///spawn enemies:
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), player, SLOT(spawnEnemies()));
    timer->start(1200);             ///< Create an ememy every 2000 miliseconds.

    ///Spawn a treasure chest
    QTimer * timer_chest = new QTimer();
    QObject::connect(timer_chest, SIGNAL(timeout()), player, SLOT(spawnTreasure()));
    timer_chest->start(8000);       ///< Create a treasure chest every 8000 miliseconds.
    ///--- End enemies and treasure chest spawns---//

    ///Creating background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/new/images/bensound-epic.mp3"));
    music->play();

    show();

}

