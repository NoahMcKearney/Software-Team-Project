#include <QtWidgets>
#include <QtCore>
#include <QtGui>

#include "stdafx.h"
#include "tic_tac_toe.h"
#include "ui_Tic_Tac_Toe.h"

Tic_Tac_Toe::Tic_Tac_Toe(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	std::string XImageName = ":/new/prefix1/X.jpg";
	ui.XChoicepushbutton->setStyleSheet("border-image:url(:/new/prefix1/X.jpg);");

}
std::string image;


void Tic_Tac_Toe::on_XChoicepushbutton_clicked()
{
	image = "X";

}

void Tic_Tac_Toe::on_OChoicepushbutton_clicked()
{

}
