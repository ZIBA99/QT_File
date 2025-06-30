#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_textChanged(const QString &arg1)
{
    ui->spinBox->blockSignals(true);// 비 정상 작동 방지-이유 좀 더 공부
    ui->dial->setValue(arg1.toInt());
    ui->spinBox->blockSignals(false);
}

