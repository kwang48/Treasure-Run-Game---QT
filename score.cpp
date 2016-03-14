#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    /// initialize the score to 0
    score = 0;

    /// draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

///Increases the score when the player collides with a treasure chest
void Score::increase(){
    score++;            ///< increasing score
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1

    ///If the player wins, display the win prompt
    if (score > 5){
        setPlainText(QString("Congratulations, YOU WON!"));
        setPos(x()+200, y()+300);
        setFont(QFont("times",30));
    }
}

///Returns score publically
int Score::getScore(){
    return score;
}
