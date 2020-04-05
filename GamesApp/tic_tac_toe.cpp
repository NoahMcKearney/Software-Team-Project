#include "stdafx.h"
#include "tic_tac_toe.h"
#include "ui_tic_tac_toe.h"

Tic_Tac_Toe::Tic_Tac_Toe(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}

void Tic_Tac_Toe::on_XChoicepushbutton_clicked()
{
   /* ui.XChoicepushbutton->setObjectName(QString::fromUtf8("pushButton_3"));
    ui.XChoicepushbutton->setGeometry(QRect(500, 30, 211, 131));
    QIcon icon2;
    icon2.addFile(QString::fromUtf8("resource/image.jpg"), QSize(), QIcon::Normal, QIcon::Off);
    ui.XChoicepushbutton->setIcon(icon2);
    ui.XChoicepushbutton->setIconSize(QSize(100, 100));*/

}

void Tic_Tac_Toe::on_OChoicepushbutton_clicked()
{
    int x = 0;
    x++;
}
