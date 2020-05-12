#pragma once

#include <QDialog>
#include "ui_rockpaperscissorsui.h"

class rockPaperScissorsUI : public QDialog, public Ui::rockPaperScissorsUI
{
	Q_OBJECT

public:
	rockPaperScissorsUI(QWidget *parent = Q_NULLPTR);
	~rockPaperScissorsUI();
private:
	Ui::rockPaperScissorsUI* ui;
	void updateUI();

//private slots:
	//action buttons
//	void printStringRep();
	void rockButtonClicked();
	void paperButtonClicked();
	void scissorsButtonCLicked();
	void exitButtonClicked(); //write the function for this one
};
