#ifndef ROCKPAPERSCISSORS_H
#define ROCKPAPERSCISSORS_H

#include "ui_rockPaperScissors.h"
#include <QtWidgets>

namespace Ui {
   class rockPaperScissors;
}

class rockPaperScissors : public QWidget
{
    Q_OBJECT
public:
    explicit rockPaperScissors(QWidget *parent = Q_NULLPTR);
    ~rockPaperScissors();

private slots:
    //action buttons
    void printStringRep();
    void rockButtonClicked();
    void paperButtonClicked();
    void scissorsButtonCLicked();
    void exitButtonClicked(); //write the function for this one
    void updateUI();

private:
    Ui::rockPaperScissors *ui;

};

#endif // ROCKPAPERSCISSORS_H
