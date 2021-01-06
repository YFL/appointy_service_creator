#include "service_widget.h"
#include "ui_service_widget.h"

#include <iostream>

#include <QListWidget>
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
    auto *widget = new QuestionItemWidget(this);
    auto *item = new QListWidgetItem {ui->question_items};
    ui->question_items->addItem(item);
    ui->question_items->setItemWidget(item, widget);
    item->setSizeHint(QSize {378, 34});
    widget->show();
}
