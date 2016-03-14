/*
 * Name Katherine Wang
 * Final Game Assignment
 * Description Score class that adds up the score when the player collides with a treasure chest.
 */

#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=0);
    void increase();                        ///< Increases score when player collides with treasure chest
    int getScore();                         ///< Returns the total score
private:
    int score;                              ///< Contains the score
};

#endif // SCORE_H
