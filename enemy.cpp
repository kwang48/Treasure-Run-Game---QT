/*
 * Name Katherine Wang
 * Assignment 5
 * Description Enemy class that creates an enemy and moves the enemy.
 *  Also has a function that will delete both the enemy and the player
 *  when they collide.
 */

#include "Enemy.h"

#include <QTimer>                 ///< To spawn using a timer
#include <QGraphicsScene>         ///< Graphics Scene
#include <QList>
#include <stdlib.h>               ///<rand()-> really large int
#include <QMediaPlayer>           ///< sound effect

#include "Game.h"
#include "Player.h"
#include "Score.h"


extern Game * game;

/**
 * @brief Enemy::Enemy constructor that creates the enemy and rotates the picture.
 * It also connects the enemy to the UI.
 */

Enemy::Enemy(QGraphicsItem * parent):QObject(), QGraphicsPixmapItem(parent)
{
    ///If the score reaches 6, stop spawning enemies
    if(game->score->getScore() <=5){
    int random_number = rand() % 700;           ///< Set a random position for the enemy
    setPos(random_number, 0);

    /**Draw the enemy size (rectangle)*/
    setPixmap(QPixmap(":/new/images/monster_attack.gif"));

    setTransformOriginPoint(50,50);
    setRotation(260);

    ///connect and make a timer that makes the enemy move
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));   ///< object whose signal you want to connect, constructor, move.

    timer->start(45);       ///< setting timer's time to 50 milliseconds.
    }
}

/**
 * @brief Enemy::move  Moves the enemy vertically downwards. Will delete when the enemy is off the screen.
 * Also causes the player to disappear if the player collides with a monster.
 */
void Enemy::move()
{
    ///if enemy collides with player, destroy both.
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){

            ///playing monster growl
            QMediaPlayer * monster = new QMediaPlayer();
            monster->setMedia(QUrl("qrc:/new/images/Monster Growl-SoundBible.com-344645592.mp3"));
            monster->play();

            ///decrease the health
            game->health->decrease();

            ///when the health is = 0
            if(game->health->getHealth() == 0){

                ///remove both
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                delete colliding_items[i];
                delete this;
                return;
            }
        }
    }

    ///For every score, increase the speed of the monsters.
if(game->score->getScore() < 2){
    ///moving enemy down
    setPos(x(),y()+8); ///< x() = current x, y() = current y
}
else if (game->score->getScore() >= 2 && game->score->getScore() < 4){
    ///moving enemy down faster
    setPos(x(),y()+13); ///< x() = current x, y() = current y
}
else
    ///moving enemy down even faster
    setPos(x(),y()+25); ///< x() = current x, y() = current y

    ///delete the enemy when it's off the screen
    if (pos().y()+ 10 < 0){
        scene()->removeItem(this);
        delete this;
    }
}
