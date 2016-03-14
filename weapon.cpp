#include "Weapon.h"

#include <QTimer>                 ///< To spawn using a timer
#include <QList>
#include <QGraphicsScene>         ///< Graphics Scene
#include <stdlib.h>               ///<rand()-> really large int
#include <QMediaPlayer>

#include "Enemy.h"
#include "Game.h"

extern Game * game;         ///< External global object, please don't get mad

Weapon::Weapon():QObject(), QGraphicsPixmapItem()
{
    if(game->score->getScore() <= 5){

        int random_number = rand() % 800; ///< Set a random position for the treasure chest

    setPos(random_number, 0);         ///< Draw the rectangle of the treasure chest
    setPixmap(QPixmap(":/new/images/TreasureChes.png"));
    setTransformOriginPoint(50,50);

    ///Connecting the treasure chest
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));   ///< object whose signal you want to connect, constructor, move.

    timer->start(50);       ///< setting timer's time to 50 milliseconds.

    }
}

///Moves the treasure chest down
void Weapon::move()
{
    ///if treasureChest collides with player, destroy the chest and give the player a random weapon
    QList<QGraphicsItem*> colliding_chest = collidingItems();
    for (int i = 0, n = colliding_chest.size(); i < n; ++i){
        if (typeid(*(colliding_chest[i])) == typeid(Player)){
            game->score->increase();

            ///playing the treasure chest collection sound
            QMediaPlayer * treasure = new QMediaPlayer();
            treasure->setMedia(QUrl("qrc:/new/images/coin.wav"));
            treasure->play();

            ///If treasure chest collides with player, remove the chest
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    ///moving chest down
    setPos(x(),y()+5); ///< x() = current x, y() = current y

    ///delete the enemy when it's off the screen
    if (pos().y()+ 10 < 0){
        scene()->removeItem(this);
        delete this;
    }
}
