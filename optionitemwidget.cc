#include "optionitemwidget.h"
#include "ui_optionitemwidget.h"

OptionItemWidget::OptionItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionItemWidget)
{
    ui->setupUi(this);
}

OptionItemWidget::~OptionItemWidget()
{
    delete ui;
}
