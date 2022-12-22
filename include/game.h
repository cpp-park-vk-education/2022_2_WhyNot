#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QObject>
#include "field.h"

class Game : public QWidget
{
    Q_OBJECT

public:
    Game(QWidget* parent = 0);
    void initGame();
    void gettingCoord();
    void gettingCountPlayers();

signals:
    void coordUpdated();
    void countPlayersUpdated();

private:
    Field* m_field;
    QPushButton* fireBtn;
    QPushButton* quitBtn;
    QLineEdit* functionInput;
    QLabel* historyInput;
    QVector<QPair<double, double> > m_dots;
    int numberOfPlayers;
};

#endif // GAME_H
