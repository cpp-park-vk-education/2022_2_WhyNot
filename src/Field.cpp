#include "field.h"

Field::Field(QWidget* parent) : QFrame(parent)
{
    setFixedSize(860, 500);
    fieldFrame = new QFrame(this);
    fieldFrame->setFrameStyle(QFrame::Box);

    updateDistFactor();

    inPaintingGraph = 0;
    idxPlayer = 0;
}

void Field::timerEvent(QTimerEvent *)
{
    this->repaint();
}

void Field::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    doDrawing();
}

void Field::resizeEvent(QResizeEvent* event)
{
    Q_UNUSED(event);
    fieldFrame->resize(size());
    updateDistFactor();
}

void Field::doDrawing()
{
    { // отрисовка координатных осей
        dekartSystemDrawing();
    }

    { // отрисовка игроков на поле
        playersDrawing();
    }

    { // отрисовка неразрушаемых препятствий на поле
        indestructibleObstracleDrawing();
    }

    { // отрисовка графика функции
        if(inPaintingGraph == 1){
            //qDebug() << idxPoint;
            attemptToKill(dekartDotsGraph[idxPoint]);
            tempScreenDotsGraph.push_back(screenDotsGraph[idxPoint++]);
            if(!endLength() && idxPoint >= 1 && !checkingOutside(dekartDotsGraph[idxPoint - 1]) &&
                    !checkingIntersectionGraphWithObstracles(dekartDotsGraph[idxPoint - 1])){
                graphDrawing();
            }
            else{
                if(idxPoint != 0) endDrawingGraph();
            }
        }
    }
}

void Field::graphDrawing()
{

    m_paint.begin(this);

    m_paint.setBrush(Qt::black);
    m_paint.setPen(Qt::black);

    for(const auto& i : tempScreenDotsGraph){
        m_paint.drawEllipse(i, 1, 1);
    }

    m_paint.end();
}

void Field::indestructibleObstracleDrawing()
{
    m_paint.begin(this);

//    m_paint.setBrush(Qt::black);
//    m_paint.setPen(Qt::black);

//    for(int i = 0; i < indestructibleObject.size(); i++){
//        for(int j = 1; j < indestructibleObject[i].getSizeScreenDots(); j++){
//            m_paint.drawLine(indestructibleObject[i].getScreenDotsObstacle(j - 1), indestructibleObject[i].getScreenDotsObstacle(j));
//        }
//    }

    m_paint.setBrush(Qt::black);
    m_paint.setPen(Qt::black);

    double r = 0;
    for(int i = 0; i < indestructibleObject.size(); i++){
        r = indestructibleObject[i].getRadius();
        r *= 100.0;
        r *= 1.0 / 3.0;
        m_paint.drawEllipse(indestructibleObject[i].getCenterPosScreenX() - (int)r / 2, indestructibleObject[i].getCenterPosScreenY() - (int)r / 2, r, r);
    }

    m_paint.end();
}

void Field::playersDrawing()
{
    m_paint.begin(this);

//    for(int i = 0; i < m_players.size(); i++){
//        for(int j = 1; j < m_players[i].getSizeScreenDots(); j++){
//            m_paint.drawLine(m_players[i].getScreenDotsPlayer(j - 1), m_players[i].getScreenDotsPlayer(j));
//        }
//    }

    m_paint.setPen(QPen(Qt::green,Qt::SolidLine));
    m_paint.setBrush(Qt::yellow);

    for(int i = 0; i < m_players.size(); i++){
        m_paint.drawEllipse(m_players[i].getCenterPosScreenX() - 13, m_players[i].getCenterPosScreenY() - 13, 25, 25);
    }

    m_paint.end();
}

void Field::dekartSystemDrawing()
{
    m_paint.begin(this);

    m_paint.setPen(Qt::black);

    m_paint.drawLine(0, this->height() / 2, this->width(), this->height() / 2);
    m_paint.drawLine(this->width() / 2, 0, this->width() / 2, this->height());

    m_paint.end();
}

void Field::convertToScreenSystem()
{
    screenDotsGraph.clear();
    for(const auto& i : dekartDotsGraph){
        screenDotsGraph.push_back(QPoint(convertX_Axes(i.first), convertY_Axes(i.second)));
    }
}

int Field::convertX_Axes(double m_x)
{
    double m_x_screenAxes = width() / 2 + m_x * distFactorForX;
    return m_x_screenAxes;
}

int Field::convertY_Axes(double m_y)
{
    double m_y_screenAxes = height() / 2 - m_y * distFactorForY;
    return m_y_screenAxes;
}

void Field::updateDistFactor()
{
    distFactorForX = width() / X_LENGTH;
    distFactorForY = height() / Y_LENGTH;
}

bool Field::checkingOutside(QPair<double, double> point)
{
    if(abs(point.first) > X_LENGTH / 2 || abs(point.second) > Y_LENGTH / 2){
        return true;
    }
    return false;
}

bool Field::checkingIntersectionGraphWithPlayers(QPair<double, double> point, int idxPlayer)
{
    for(int j = 0; j < m_players[idxPlayer].getSizeDekartDots(); j++){
        if(fabs(point.first - m_players[idxPlayer].getDekardDotsPlayer(j).first) +
           fabs(point.second - m_players[idxPlayer].getDekardDotsPlayer(j).second) < KILL_EPS){
            return true;
        }
    }
    return false;
}

bool Field::checkingIntersectionGraphWithObstracles(QPair<double, double> point)
{
    for(int i = 0; i < indestructibleObject.size(); i++){
        for(int j = 0; j < indestructibleObject[i].getSizeDekartDots(); j++){
            if(fabs(point.first - indestructibleObject[i].getDekardDotsObstacle(j).first) +
                fabs(point.second - indestructibleObject[i].getDekardDotsObstacle(j).second) < INTERSECTION_EPS){
                return true;
            }
        }
    }
    return false;
}

bool Field::checkingIntersectionPlayersWithObstracle(double X0, double Y0, double R0)
{
    double dist = 0;
    for(int i = 0; i < m_players.size(); i++){
        dist = distanceBetweenTwoPoints(X0, Y0, m_players[i].getCenterPosDekartX(), m_players[i].getCenterPosDekartY());
        if(dist < Player::M_RADIUS + R0){
            return true;
        }
    }
    return false;
}

void Field::attemptToKill(QPair<double, double> point)
{
    for(int i = 0; i < m_players.size(); i++){
        if(i != idxPlayer && checkingIntersectionGraphWithPlayers(point, i)){
            auto it = m_players.begin() + i;
            m_players.erase(it);
        }
    }
}

bool Field::endLength()
{
    return idxPoint == screenDotsGraph.size();
}

void Field::endDrawingGraph()
{
    killTimer(timerId);
    inPaintingGraph = 0;
    tempScreenDotsGraph.clear();
}

void Field::initPlayers()
{
    initCenterPosForPlayers();
    initDotsForPlayers();
}

void Field::initCenterPosForPlayers()
{
    QTime zerno(0, 0, 0);
    QRandomGenerator generator(zerno.secsTo(QTime::currentTime()));

    int signX = -1;
    int signY = 1;

    for(int i = 0; i < m_players.size(); i++){

        int posDecartX = (generator.generate() % (int)(X_LENGTH / 2 - distanceBetweenPlayerAndAxisX) + distanceBetweenPlayerAndAxisX) * signX;
        int posDecartY = (generator.generate() % (int)(Y_LENGTH / 2 - distanceBetweenPlayerAndAxisY) + distanceBetweenPlayerAndAxisY) * signY;

        m_players[i].setCenterPosDekartX(posDecartX);
        m_players[i].setCenterPosDekartY(posDecartY);
        m_players[i].setCenterPosScreenX(convertX_Axes(posDecartX));
        m_players[i].setCenterPosScreenY(convertY_Axes(posDecartY));

        signX *= (-1);
        if((i + 1) % 2 == 0){ signY *= (-1); }
    }
}

void Field::initDotsForPlayers()
{
    for(int i = 0; i < m_players.size(); i++){
        double x0 = m_players[i].getCenterPosDekartX();
        double y0 = m_players[i].getCenterPosDekartY();
        double r = m_players[i].M_RADIUS;
        double w = r;
        double h = 0;
        double tmpX1 = 0;
        double tmpX2 = 0;
        double tmpX3 = 0;
        double tmpX4 = 0;
        double tmpY1 = 0;
        double tmpY2 = 0;
        double tmpY3 = 0;
        double tmpY4 = 0;

        while(w > 0){
            h = qSqrt(r * r - w * w);

            tmpX1 = x0 + w;
            tmpY1 = y0 + h;

            tmpX2 = x0 + w;
            tmpY2 = y0 - h;

            tmpX3 = x0 - w;
            tmpY3 = y0 - h;

            tmpX4 = x0 - w;
            tmpY4 = y0 + h;

            m_players[i].pushBackInDekartDotsPlayer(QPair<double, double>(tmpX1, tmpY1));
            m_players[i].pushBackInDekartDotsPlayer(QPair<double, double>(tmpX2, tmpY2));
            m_players[i].pushBackInDekartDotsPlayer(QPair<double, double>(tmpX3, tmpY3));
            m_players[i].pushBackInDekartDotsPlayer(QPair<double, double>(tmpX4, tmpY4));
            m_players[i].pushBackInScreenDotsPlayer(QPoint(convertX_Axes(tmpX1), convertY_Axes(tmpY1)));
            m_players[i].pushBackInScreenDotsPlayer(QPoint(convertX_Axes(tmpX2), convertY_Axes(tmpY2)));
            m_players[i].pushBackInScreenDotsPlayer(QPoint(convertX_Axes(tmpX3), convertY_Axes(tmpY3)));
            m_players[i].pushBackInScreenDotsPlayer(QPoint(convertX_Axes(tmpX4), convertY_Axes(tmpY4)));
            w -= Player::K_POLYGON;
        }
    }
}

void Field::initDotsForIndestructibleObstracle()
{
    for(int i = 0; i < indestructibleObject.size(); i++){
        double x0 = indestructibleObject[i].getCenterPosDekartX();
        double y0 = indestructibleObject[i].getCenterPosDekartY();
        double r = indestructibleObject[i].getRadius();
        double w = r;
        double h = 0;
        double tmpX1 = 0;
        double tmpX2 = 0;
        double tmpX3 = 0;
        double tmpX4 = 0;
        double tmpY1 = 0;
        double tmpY2 = 0;
        double tmpY3 = 0;
        double tmpY4 = 0;

        while(w > 0){
            h = qSqrt(r * r - w * w);

            tmpX1 = x0 + w;
            tmpY1 = y0 + h;

            tmpX2 = x0 + w;
            tmpY2 = y0 - h;

            tmpX3 = x0 - w;
            tmpY3 = y0 - h;

            tmpX4 = x0 - w;
            tmpY4 = y0 + h;

            indestructibleObject[i].pushBackInDekartDotsObstacle(QPair<double, double>(tmpX1, tmpY1));
            indestructibleObject[i].pushBackInDekartDotsObstacle(QPair<double, double>(tmpX2, tmpY2));
            indestructibleObject[i].pushBackInDekartDotsObstacle(QPair<double, double>(tmpX3, tmpY3));
            indestructibleObject[i].pushBackInDekartDotsObstacle(QPair<double, double>(tmpX4, tmpY4));
            indestructibleObject[i].pushBackInScreenDotsObstacle(QPoint(convertX_Axes(tmpX1), convertY_Axes(tmpY1)));
            indestructibleObject[i].pushBackInScreenDotsObstacle(QPoint(convertX_Axes(tmpX2), convertY_Axes(tmpY2)));
            indestructibleObject[i].pushBackInScreenDotsObstacle(QPoint(convertX_Axes(tmpX3), convertY_Axes(tmpY3)));
            indestructibleObject[i].pushBackInScreenDotsObstacle(QPoint(convertX_Axes(tmpX4), convertY_Axes(tmpY4)));
            w -= Obstacle::K_POLYGON;
        }
    }
}

double Field::differenceBetweenY0andYi(const QVector<QPair<double, double>>& m_dots)
{
    for(int i = 0; i < m_dots.size(); i++){
        if(fabs(m_dots[i].first - m_players[idxPlayer].getCenterPosDekartX()) < DIFF_EPS){
            return m_players[idxPlayer].getCenterPosDekartY() - m_dots[i].second;
        }
    }
    return 0.0;
}

void Field::movePlayer()
{
    updateField();
}

void Field::setNextPlayer()
{
    idxPlayer++;
}

int Field::getNumberOfPlayers()
{
    return m_players.size();
}

void Field::updateCountPlayers(int countPlayers)
{
    m_players.resize(countPlayers);

    initPlayers();
    initIndestructibleObstracle();
}

void Field::updateCoordGraph(const QVector<QPair<double, double>>& m_dots)
{
    this->dekartDotsGraph.clear();
    double tmpDekartAxisX = 0;
    double tmpDekartAxisY = 0;
    double diff = differenceBetweenY0andYi(m_dots);
    for(const auto& i : m_dots){
        tmpDekartAxisX = i.first;
        tmpDekartAxisY = i.second + diff;
        if((m_players[idxPlayer].getCoordinateQuarter() == 2 || m_players[idxPlayer].getCoordinateQuarter() == 3)
                && tmpDekartAxisX < m_players[idxPlayer].getCenterPosDekartX() - Player::M_RADIUS){
            this->dekartDotsGraph.push_back(QPair<double, double>(tmpDekartAxisX, tmpDekartAxisY));
        }
        if((m_players[idxPlayer].getCoordinateQuarter() == 1 || m_players[idxPlayer].getCoordinateQuarter() == 4)
                && tmpDekartAxisX > m_players[idxPlayer].getCenterPosDekartX() + Player::M_RADIUS){
            this->dekartDotsGraph.push_back(QPair<double, double>(tmpDekartAxisX, tmpDekartAxisY));
        }
    }

    if(m_players[idxPlayer].getCoordinateQuarter() == 2 || m_players[idxPlayer].getCoordinateQuarter() == 3){
        for(int i = 0; i < this->dekartDotsGraph.size() / 2; i++){
            swap(this->dekartDotsGraph[i], this->dekartDotsGraph[this->dekartDotsGraph.size() - 1 - i]);
        }
    }
    convertToScreenSystem();
}

void Field::updateField()
{
    if(inPaintingGraph != 1){
        idxPoint = 0;
        inPaintingGraph = 1;
        timerId = startTimer(DELAY);
    }
}

void Field::initCenterPosForIndestructibleObstracle()
{
    QTime zerno(0, 0, 0);
    QRandomGenerator generatorDist(zerno.secsTo(QTime::currentTime()));
    QRandomGenerator generatorRadius(zerno.secsTo(QTime::currentTime()));

    double x1 = 0;
    double y1 = 0;
    double x2 = 0;
    double y2 = 0;
    double dx = 0;
    double dy = 0;
    double angle = 0;
    double centerPosDecartObstracleX = 0;
    double centerPosDecartObstracleY = 0;
    double dist = 0;
    double randPositionInLine = 0;
    double randRadius = 0;
    Obstacle tmpIndestructibleObject(0, 0);
    double tmpX0 = 0;
    double tmpY0= 0 ;
    for(int i = 0; i < m_players.size(); i++){
        for(int j = i + 1; j < m_players.size(); j++){
            x1 = m_players[i].getCenterPosDekartX();
            x2 = m_players[j].getCenterPosDekartX();
            y1 = m_players[i].getCenterPosDekartY();
            y2 = m_players[j].getCenterPosDekartY();

            if(y2 < y1){
                std::swap(y1, y2);
                std::swap(x1, x2);
            }

            dx = x2 - x1;
            dy = y2 - y1;
            angle = fabs(angleTanBetweenDxDyObstracle(dx, dy));

            dist = distanceBetweenTwoPoints(x1, y1, x2, y2);

            randPositionInLine = generatorDist.generateDouble() * dist;
            randRadius = (generatorRadius.generate() % (Obstacle::MAX_RADIUS - Obstacle::MIN_RADIUS + 1)) + Obstacle::MIN_RADIUS;

            tmpX0 = findOffsetXForCenterPosObstracle(randPositionInLine, fabs(dx), angle);
            tmpY0 = tmpX0 * angle;

            if(dx > 0){
                tmpX0 = tmpX0 + x1;
            }
            else{
                tmpX0 = x1 - tmpX0;
            }
            tmpY0 += y1;

            while(checkingIntersectionPlayersWithObstracle(tmpX0, tmpY0, randRadius + Obstacle::EXTRA_EPS_RADIUS)){
                randPositionInLine = generatorDist.generateDouble() * dist;

                tmpX0 = findOffsetXForCenterPosObstracle(randPositionInLine, fabs(dx), angle);
                tmpY0 = tmpX0 * angle;

                if(dx > 0){
                    tmpX0 = tmpX0 + x1;
                }
                else{
                    tmpX0 = x1 - tmpX0;
                }
                tmpY0 += y1;

                randRadius = (generatorRadius.generate() % (Obstacle::MAX_RADIUS - Obstacle::MIN_RADIUS + 1)) + Obstacle::MIN_RADIUS;
            }

            centerPosDecartObstracleX = findOffsetXForCenterPosObstracle(randPositionInLine, fabs(dx), angle);
            centerPosDecartObstracleY = centerPosDecartObstracleX * angle;

            if(dx > 0){
                centerPosDecartObstracleX = centerPosDecartObstracleX + x1;
            }
            else{
                centerPosDecartObstracleX = x1 - centerPosDecartObstracleX;
            }
            centerPosDecartObstracleY += y1;

            tmpIndestructibleObject.setCenterPosDekartX(centerPosDecartObstracleX);
            tmpIndestructibleObject.setCenterPosDekartY(centerPosDecartObstracleY);
            tmpIndestructibleObject.setCenterPosScreenX(convertX_Axes(centerPosDecartObstracleX));
            tmpIndestructibleObject.setCenterPosScreenY(convertY_Axes(centerPosDecartObstracleY));
            tmpIndestructibleObject.setRadius(randRadius);
            indestructibleObject.push_back(tmpIndestructibleObject);
        }
    }
}

void Field::initIndestructibleObstracle()
{
    initCenterPosForIndestructibleObstracle();
    initDotsForIndestructibleObstracle();
}

double Field::distanceBetweenTwoPoints(double x1, double y1, double x2, double y2)
{
    double dx = (x2 - x1);
    double dy = (y2 - y1);
    return sqrt(dx * dx + dy * dy);
}

double Field::findOffsetXForCenterPosObstracle(double dist, double dx, double angle)
{
    double w = 0;
    while(w < dx){
        if(fabs(w * sqrt(1 + angle * angle) - dist) < 1e-1){
            return w;
        }
        w += 0.05;
    }
    return 0;
}

double Field::angleTanBetweenDxDyObstracle(double dx, double dy)
{
    return dy / dx;
}
