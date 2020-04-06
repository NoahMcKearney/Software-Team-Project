#pragma once

#include <QDialog>
#include "ui_Tic_Tac_Toe.h"

class Tic_Tac_Toe : public QDialog
{
	Q_OBJECT

public:
	Tic_Tac_Toe(QWidget *parent = Q_NULLPTR);

private slots:
	void on_XChoicepushbutton_clicked();
	void on_OChoicepushbutton_clicked();
private:
	Ui::Tic_Tac_Toe ui;
};
