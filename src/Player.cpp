#include "player.h"

Player::Player()
{

}

void Player::setCenterPosDekartX(int newPosCenterX)
{
    centerPosDekartX = newPosCenterX;
}

void Player::setCenterPosDekartY(int newPosCenterY)
{
    centerPosDekartY = newPosCenterY;
}

void Player::setCenterPosScreenX(int newPosCenterX)
{
    centerPosScreenX = newPosCenterX;
}

void Player::setCenterPosScreenY(int newPosCenterY)
{
    centerPosScreenY = newPosCenterY;
}

int Player::getCenterPosDekartX()
{
    return centerPosDekartX;
}

int Player::getCenterPosDekartY()
{
    return centerPosDekartY;
}

int Player::getCenterPosScreenX()
{
    return centerPosScreenX;
}

int Player::getCenterPosScreenY()
{
    return centerPosScreenY;
}

int Player::getSizeDekartDots()
{
    return dekartDotsPlayer.size();
}

int Player::getSizeScreenDots()
{
    return screenDotsPlayer.size();
}

int Player::getCoordinateQuarter()
{
    if(centerPosDekartX < 0 && centerPosDekartY >= 0){
        return 1;
    }
    else if(centerPosDekartX > 0 && centerPosDekartY >= 0){
        return 2;
    }
    else if(centerPosDekartX > 0 && centerPosDekartY < 0){
        return 3;
    }
    return 4;
}

QPair<double, double> Player::getDekardDotsPlayer(int idx)
{
    return dekartDotsPlayer[idx];
}

QPoint Player::getScreenDotsPlayer(int idx)
{
    return screenDotsPlayer[idx];
}

void Player::pushBackInDekartDotsPlayer(QPair<double, double> point)
{
    dekartDotsPlayer.push_back(point);
}

void Player::pushBackInScreenDotsPlayer(QPoint point)
{
    screenDotsPlayer.push_back(point);
}
