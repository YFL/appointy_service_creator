#include "questionitemwidget.h"
#include "ui_questionitemwidget.h"

QuestionItemWidget::QuestionItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionItemWidget)
{
    ui->setupUi(this);
}

QuestionItemWidget::~QuestionItemWidget()
{
    delete ui;
}
