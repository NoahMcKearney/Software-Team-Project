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

	// board button
	void on_FirstpushButton_clicked();
	void on_SecondpushButton_clicked();
	void on_ThirdpushButton_clicked();
	void on_FourthpushButton_clicked();
	void on_FifthpushButton_clicked();
	void on_SixthpushButton_clicked();
	void on_SeventhpushButton_clicked();
	void on_EighthpushButton_clicked();
	void on_NinthpushButton_clicked();
private:
	Ui::Tic_Tac_Toe ui;
};
