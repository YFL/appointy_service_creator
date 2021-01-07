#include "service_edit_window.h"
#include "ui_service_edit_window.h"

#include <QMessageBox>

#include <appointy_exception.h>

#include <question_item_widget.h>
#include <util.h>

ServiceEditWindow::ServiceEditWindow(const appointy::Service &service, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServiceEditWindow)
{
    ui->setupUi(this);

    connect(ui->save_btn, &QPushButton::clicked, this, &ServiceEditWindow::save_btn_click);
    connect(ui->cancel_btn, &QPushButton::clicked, this, &ServiceEditWindow::cancel_btn_click);
    connect(ui->add_question_btn, &QPushButton::clicked, this, &ServiceEditWindow::add_question_btn_click);
    connect(ui->remove_question_btn, &QPushButton::clicked, this, &ServiceEditWindow::remove_question_btn_click);

    ui->name_edit->setText(service.name.c_str());
    ui->price_edit->setText(service.price.to_string().c_str());
    ui->duration_edit->setText(service.duration.to_string().c_str());
    for(auto &question : service.questions)
    {
        auto *widget = new QuestionItemWidget {&question, this};
        add_widget_to_list_widget(widget, ui->question_items, QSize {378, 34});
        widget->show();
    }
}

ServiceEditWindow::~ServiceEditWindow()
{
    delete ui;
}

void ServiceEditWindow::save_btn_click()
{
    using namespace appointy;
    if(ui->name_edit->text().length() == 0)
    {
        show_error_with_ok("Name empty", "");
        return;
    }

    std::string name = ui->name_edit->text().toStdString();
    try
    {
        Price price = string_to_price(ui->price_edit->text().toStdString());
        try
        {
            Time duration = string_to_time(ui->duration_edit->text().toStdString());

            std::vector<Question> questions;
            for(int i = 0; i < ui->question_items->count(); i++)
            {
                questions.push_back(dynamic_cast<QuestionItemWidget *>(ui->question_items->itemWidget(ui->question_items->item(i)))->question());
            }

            emit service_saved({"0"}, name, price, duration, questions);
            close();
        }
        catch(const Exception &e)
        {
            show_error_with_ok("Couldn't parse duration", e.what());
            return;
        }
    }
    catch(const Exception &e)
    {
        show_error_with_ok("Couldn't parse price", e.what());
        return;
    }
}

void ServiceEditWindow::cancel_btn_click()
{
    close();
}

void ServiceEditWindow::add_question_btn_click()
{
    auto *widget = new QuestionItemWidget {nullptr, this};
    add_widget_to_list_widget(widget, ui->question_items, QSize {378, 34});
    widget->show();
}

void ServiceEditWindow::remove_question_btn_click()
{
    auto selected= ui->question_items->selectedItems();
    for(auto *item : selected)
    {
        remove_item_from_list_widget(item, ui->question_items);
        delete item;
    }
}
