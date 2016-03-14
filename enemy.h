/*
 * Name Katherine Wang
 * Final Game Assignment
 * Description Enemy class that creates an enemy and moves the enemy.
 *  Also has a function that will delete both the enemy and the player
 *  when they collide.
 */

#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>    ///<For implementing graphics
#include <QObject>                ///<for signalling slots
#include <QGraphicsItem>          ///< To make the graphic item

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT        ///< signalling slots
public:
    Enemy(QGraphicsItem * parent=0);        ///< enemy constructor

public slots:       ///< slot marks a signal to a specific reaction
   void move();     ///< will make the enemy move
};


#endif // ENEMY

