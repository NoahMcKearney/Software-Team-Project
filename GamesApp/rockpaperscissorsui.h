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
private slots:
	//action buttons
//	void printStringRep();
	void on_rockButton_clicked();
	void on_paperButton_clicked();
	void on_scissorButton_clicked();
	void on_exitButton_clicked(); //write the function for this one
};
