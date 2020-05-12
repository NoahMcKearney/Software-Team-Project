#include "rockpaperscissors.h"
#include "ui_rockPaperScissors.h"
#include "stdafx.h"
#include <QtWidgets/QApplication>
#include <cstdlib>
#include <QtCore>
#include <QtGui>
#include <QLabel>
#include <QDialog>
#include <QPushButton>

int winsCount = 0, lossesCount = 0, tieCount = 0;

rockPaperScissors :: rockPaperScissors(QWidget *parent)
    : QDialog(parent)
    ui(new Ui::rockPaperScissors)
{
    ui->setupUi(this);

}

/*
void rockPaperScissors :: printStringRep(){
    char buffer[25];
    printf("%s", buffer);
}
*/
void rockPaperScissors :: updateUI(){

    //will update the counts for each game
    ui->tieLabel->setText(tieCount);
    ui->winsLabel->setText(winsCount);
    ui->lossesLabel->setText(lossesCount);

}

void rockPaperScissors :: rockButtonClicked(){ //user clicked the rock button
    //printf("Rock button clicked\n");
    //srand((unsigned int)time(NULL));
    QLabel *rocklabel = new QLabel(this);

    int computerPlay = (qrand() % 3) + 1;
    //1 is for Rock; 2 is for Paper; 3 is for Scissors

    switch(computerPlay){
    case 1:
        //this is a tie
        rocklabel->setText("Computer chose rock. / It's a tie.");
        rocklabel->show();
        tieCount++;
        break;
    case 2:
        //user lost
        rocklabel->setText("Computer chose paper. / You lost. Paper beats rock.");
        rocklabel->show();
        lossesCount++;
        break;
    case 3:
        //user won
        rocklabel->setText("Computer chose scissors. / You win! Rock beats scissors.");
        rocklabel->show();
        winsCount++;
        break;

    }
}

void rockPaperScissors :: paperButtonClicked(){//user clicked the paper button
    //printf("Paper button clicked\n");
    QLabel *paperlabel = new QLabel(this);


    int computerPlay = (qrand() % 3) + 1;
    //1 is for Rock; 2 is for Paper; 3 is for Scissors

    switch(computerPlay){
    case 1:
        //printf("Rock\n");
        //printf("You win! Paper beats rock.\n");
        paperlabel->setText("Computer chose rock. / You win! Paper beats rock.");
        paperlabel->show();
        winsCount++;
        break;
    case 2:
        //printf("Paper\n");
        //printf("Tie!\n");
        paperlabel->setText("Computer chose paper. / It's a tie.");
        paperlabel->show();
        tieCount++;
        break;
    case 3:
        //printf("Scissors\n");
        //printf("You lose! Scissors beats paper.\n");
        paperlabel->setText("Computer chose scissors. / You lost. Scissors beats paper.");
        paperlabel->show();
        lossesCount++;
        break;

    }

}
void rockPaperScissors :: scissorsButtonCLicked(){ //user clicked the scissors button
    //printf("Paper button clicked\n");
    QLabel *scissorlabel = new QLabel(this);

    int computerPlay = (qrand() % 3) + 1;
    //1 is for Rock; 2 is for Paper; 3 is for Scissors

    switch(computerPlay){
    case 1:
        //printf("Rock\n");
        //printf("You lose. Rock beats scissors.\n");
        scissorlabel->setText("Computer chose rock. / You lost. Rock beats scissors.");
        scissorlabel->show();
        lossesCount++;
        break;
    case 2:
        //printf("Paper\n");
        //printf("You win! Scissors beats paper.\n");
        scissorlabel->setText("Computer chose paper. / You win! Scissors beats paper.");
        scissorlabel->show();
        winsCount++;
        break;
    case 3:
        scissorlabel->setText("Computer chose scissors. / It's a tie.");
        scissorlabel->show();
        tieCount++;
        break;

    }

}

void rockPaperScissors :: exitButtonClicked(){//user will exit this game and go play the others
    this->close();
}
