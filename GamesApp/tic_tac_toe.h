#pragma once

#include <QDialog>
#include "ui_tic_tac_toe.h"

class Tic_Tac_Toe : public QDialog, public Ui::Tic_Tac_Toe
{
	Q_OBJECT

public:
	Tic_Tac_Toe(QWidget *parent = Q_NULLPTR);

private slots:
	void on_XChoicepushbutton_clicked();
	void on_OChoicepushbutton_clicked();
};
