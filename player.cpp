/**
    Name Katherine Wang
    Assignment 5
    Description: This class creates the player (the character). Also allows movement
    of the character and spawns enemies.
  */

#include "Player.h"

#include <QGraphicsScene>
#include <QKeyEvent>

#include "Enemy.h"
#include "Weapon.h"


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    ///set the player image
    setPixmap(QPixmap(":/new/images/playerImg.gif"));
    setTransformOriginPoint(100,100);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    ///---Moving the player to the Left---//
    if(event->key() == Qt::Key_Left){
        ///If the position of the player is greater than 0 on the x-axis, to avoid going off screen
        if (pos().x() > 0)
            ///move the character to the left by 10 pixels
            setPos(x()-25,y());
    }
    ///---Moving the player right---//
    else if (event->key() == Qt::Key_Right){
        ///If the position of the player is less than 800 on the y-axis, to avoid going off screen
        if (pos().x()+10 < 650)
            ///move the character to the right by 10 pixels
            setPos(x()+25,y());
    }
}

///Creates an enemy
void Player::spawnEnemies(){
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

///Creates a treasure chest
void Player::spawnTreasure(){
    Weapon * weapon = new Weapon();
    scene()->addItem(weapon);
}
