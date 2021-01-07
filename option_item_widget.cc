#include "option_item_widget.h"
#include "ui_option_item_widget.h"

#include <option_edit_window.h>

OptionItemWidget::OptionItemWidget(const appointy::Option * const option, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionItemWidget)
{
    ui->setupUi(this);

    connect(ui->edit_btn, &QPushButton::clicked, this, &OptionItemWidget::edit_btn_click);

    if(option)
    {
        _option = std::unique_ptr<appointy::Option>(new appointy::Option {*option});
    }
    else
    {
        _option = std::unique_ptr<appointy::Option>(new appointy::Option {0, {""}, {0, 0}, {0, 0, 0}});
    }

    ui->text->setText(_option->text.c_str());
}

OptionItemWidget::~OptionItemWidget()
{
    delete ui;
}

auto OptionItemWidget::option() const -> const appointy::Option
{
    return *_option;
}

void OptionItemWidget::edit_btn_click()
{
    auto option_edit_window = new OptionEditWindow(*_option, this);
    connect(option_edit_window, &OptionEditWindow::option_saved, this, &OptionItemWidget::option_save);
    option_edit_window->show();
}

void OptionItemWidget::option_save(const std::string &text, const appointy::Price &price, const appointy::Time &duration)
{
    _option = std::unique_ptr<appointy::Option> {new appointy::Option {_option->id, text, price, duration}};
    ui->text->setText(_option->text.c_str());
}

