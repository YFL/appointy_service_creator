#include "service_widget.h"
#include "ui_servicewidget.h"

#include <iostream>

#include <QVBoxLayout>

#include <question_edit_window.h>
#include <question_item_widget.h>

ServiceWidget::ServiceWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServiceWidget)
{
    ui->setupUi(this);
}

ServiceWidget::~ServiceWidget()
{
    delete ui;
}

void ServiceWidget::on_add_question_btn_clicked()
{
    std::cout << "yes" << std::endl;
    auto *widget = new QuestionItemWidget(this);
    ((QLayout *)ui->question_items)->addWidget(widget);
    widget->show();
}
