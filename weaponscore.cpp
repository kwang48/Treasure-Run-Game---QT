#include "weaponscore.h"

#include <QFont>
#include "Game.h"

Weaponscore::Weaponscore(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the damage to 2
    damage_score = 2;

    // draw the text
    setPlainText(QString("Damage: ") + QString::number(damage_score)); // Score: 2
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Weaponscore::increase(){
    ++damage_score;
    setPlainText(QString("Damage: ") + QString::number(damage_score)); // Score: 3
}

int Weaponscore::getDamage(){
    return damage_score;
}
