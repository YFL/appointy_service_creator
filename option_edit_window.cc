#include "option_edit_window.h"
#include "ui_option_edit_window.h"

#include <QMessageBox>

#include <appointy_exception.h>

#include <util.h>

OptionEditWindow::OptionEditWindow(const appointy::Option &option, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OptionEditWindow)
{
    ui->setupUi(this);

    connect(ui->save_btn, &QPushButton::clicked, this, &OptionEditWindow::save_btn_click);
    connect(ui->cancel_btn, &QPushButton::clicked, this, &OptionEditWindow::cancel_btn_click);

    ui->option_text->setPlainText(option.text.c_str());
    ui->duration->setText(option.duration.to_string().c_str());
    ui->price->setText(option.price.to_string().c_str());
}

OptionEditWindow::~OptionEditWindow()
{
    delete ui;
}

void OptionEditWindow::save_btn_click()
{
    try
    {
        appointy::Price price {string_to_price(ui->price->text().toStdString())};
        try
        {
            appointy::Time duration {string_to_time(ui->duration->text().toStdString())};

            emit option_saved(ui->option_text->toPlainText().toStdString(), price, duration);
            close();
        }
        catch(const appointy::Exception &e)
        {
            show_error_with_ok("Couldn't parse duration", e.what());
            return;
        }
    }
    catch(const appointy::Exception &e)
    {
        show_error_with_ok("Couldn't parse price", e.what());
        return;
    }
}

void OptionEditWindow::cancel_btn_click()
{
    close();
}
