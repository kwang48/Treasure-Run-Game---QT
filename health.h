/*
 * Name Katherine Wang
 * Final Game Assignment
 * Description Health class that creates the health amount and also displays the health in the corner.
 * If the player collides with the enemy, the player's score will decrease in the void decrease();
 */

#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent=0);
    void decrease();                    ///< Decreases health when player collides with enemy
    int getHealth();                    ///< Returns the health score
private:
    int health;                         ///< Contains the health score
};

#endif // HEALTH_H
