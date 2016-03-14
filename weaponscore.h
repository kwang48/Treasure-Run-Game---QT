#ifndef WEAPONSCORE_H
#define WEAPONSCORE_H

#include <QGraphicsTextItem>

class Weaponscore: public QGraphicsTextItem{
public:
    Weaponscore(QGraphicsItem * parent=0);
    void increase();
    int getDamage();

    friend class Weapon;

private:
    int damage_score;
};

#endif // WEAPONSCORE_H
