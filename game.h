/**
  Katherine Wang
  Final Game Assignment
  Description: This class creates the visual interface and also spawns the player and the enemies.
  */

#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "Enemy.h"

class Game: public QGraphicsView
{
public:
    Game(QWidget * parent=0);

    Player * player;            ///< Creating player object
    Score * score;              ///< Creating score object
    Health * health;            ///< Creating health object
    Enemy * enemy;              ///< Creating enemy object
    QGraphicsScene * scene;     ///< Creating the scene object

};

#endif // GAME_H
