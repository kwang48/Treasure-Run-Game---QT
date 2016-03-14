/** The weapon file implements treasure chests into the game, which are required to win the game.
  *
  */
#ifndef WEAPON_H
#define WEAPON_H

#include <QGraphicsPixmapItem>    ///<For implementing graphics
#include <QGraphicsItem>
#include <QObject>                ///<for signalling slots

class Weapon:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Weapon();           ///< Spawns a tresure chest that will randomly generate a new weapon damage
public slots:
    void move();        ///< Moves the treasure chest down
};

#endif // WEAPON_H
