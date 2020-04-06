#pragma once

#include <QDialog>
#include "ui_hangman.h"

class Hangman : public QDialog, public Ui::hangman
{
	Q_OBJECT

public:
	Hangman(QWidget *parent = Q_NULLPTR);
	~Hangman();
private:
	Ui::hangman* ui;
private slots:
	void letterPressed();
};
