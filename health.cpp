#include "Health.h"
#include <QFont>
#include "Enemy.h"
#include "Game.h"

extern Game * game;

///Creates the health score
Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    /// initialize the health to 100
    health = 100;

    /// draw the text
    setPlainText(QString("Health: ") + QString::number(health)); ///< Health: 100
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}


///Decreases the health
void Health::decrease(){
    health = health - 2;
    setPlainText(QString("Health: ") + QString::number(health)); ///< Health: 99
    if (health <= 0){
        setPlainText(QString("You died - GAME OVER")); ///< Dead, display game over
        setPos(x()+250, y()+300);
        setFont(QFont("times",30));
    }
}

///Returns the health
int Health::getHealth(){
    return health;
}
