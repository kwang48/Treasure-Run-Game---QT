/**
    Name Katherine Wang
    Final Game Assignment
    Description: This class creates the player (the character) and also
    allows the player to control his character through the arrow keys.
    Also spawns enemies.
  */

#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT    ///< for public slots
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);          ///< When a specific key is pressed, the player will move
public slots:
    void spawnEnemies();                            ///< Function that spawns enemies
    void spawnTreasure();                           ///< Function that spawns treasure
};

#endif // PLAYER_H
