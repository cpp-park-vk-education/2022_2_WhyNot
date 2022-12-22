#include <QApplication>
#include <QHBoxLayout>
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game* m_game = new Game;
    m_game->initGame();
    m_game->show();

    return a.exec();
}
