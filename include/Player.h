#ifndef PLAYER_H
#define PLAYER_H

#include <QVector>
#include <QPair>
#include <QPoint>

class Player
{
public:
    Player();
    void setCenterPosDekartX(int);
    void setCenterPosDekartY(int);
    void setCenterPosScreenX(int);
    void setCenterPosScreenY(int);
    int getCenterPosDekartX();
    int getCenterPosDekartY();
    int getCenterPosScreenX();
    int getCenterPosScreenY();
    int getSizeDekartDots();
    int getSizeScreenDots();
    int getCoordinateQuarter();
    QPair<double, double> getDekardDotsPlayer(int);
    QPoint getScreenDotsPlayer(int);
    void pushBackInDekartDotsPlayer(QPair<double, double>);
    void pushBackInScreenDotsPlayer(QPoint);

    constexpr static const double M_RADIUS = 0.75;
    constexpr static const double K_POLYGON = 0.005;

private:
    int centerPosDekartX;
    int centerPosDekartY;
    int centerPosScreenX;
    int centerPosScreenY;
    QVector<QPair<double, double> > dekartDotsPlayer;
    QVector<QPoint> screenDotsPlayer;
};

#endif // PLAYER_H
