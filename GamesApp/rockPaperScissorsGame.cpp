#include <QtWidgets>
#include <QApplication>
#include <QPushButton>
#include "rockpaperscissors.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    rockPaperScissors GameApp;

    //assigning the buttons with labels
    QPushButton *scissorButton = new QPushButton("Scissor");
    QPushButton *rockButton = new QPushButton("Rock");
    QPushButton *paperButton = new QPushButton("Paper");
    QPushButton *exitButton = new QPushButton("Exit");

    //all the buttons
    QObject::connect(scissorButton, SIGNAL(clicked()), &app, SLOT(scissorsButtonClicked()));
    QObject::connect(rockButton, SIGNAL(clicked()), &app, SLOT(rockButtonClicked()));
    QObject::connect(paperButton, SIGNAL(clicked()), &app, SLOT(paperButtonClicked()));
    QObject::connect(exitButton, SIGNAL(clicked()), &app, SLOT(exitButtonClicked()));

    //everything will update as buttons are clicked
    GameApp.updateUI();
    GameApp.show();
    scissorButton->show();
    rockButton->show();
    paperButton->show();
    exitButton->show();
    return app.exec();
}
