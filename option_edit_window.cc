#include "option_edit_window.h"
#include "ui_option_edit_window.h"

#include <util.h>

OptionEditWindow::OptionEditWindow(appointy::Option *option, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OptionEditWindow)
{
    ui->setupUi(this);

    connect(ui->save_btn, &QPushButton::clicked, this, &OptionEditWindow::save_btn_click);

    if(option)
    {
        ui->option_text->setPlainText(option->text.c_str());
        ui->duration->setText(option->duration.to_string().c_str());
        ui->price->setText(option->price.to_string().c_str());
    }
}

OptionEditWindow::~OptionEditWindow()
{
    delete ui;
}

void OptionEditWindow::save_btn_click()
{
    emit save_btn_clicked(ui->option_text->toPlainText().toStdString(), string_to_price(ui->price->text().toStdString()), string_to_time(ui->duration->text().toStdString()));
}
