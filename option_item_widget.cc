#include "option_item_widget.h"
#include "ui_option_item_widget.h"

#include <option_edit_window.h>

OptionItemWidget::OptionItemWidget(const appointy::Option *option, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionItemWidget)
{
    ui->setupUi(this);
    if(option)
    {
        _option = std::unique_ptr<appointy::Option>(new appointy::Option {*option});
    }
    else
    {
        _option = std::unique_ptr<appointy::Option>(new appointy::Option {0, {""}, {0, 0}, {0, 0, 0}});
    }
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
    auto option_edit_window = new OptionEditWindow();
    connect(option_edit_window, &OptionEditWindow::save_btn_clicked, this, &OptionItemWidget::option_save);
}

void OptionItemWidget::option_save(const std::string &text, const appointy::Price &price, const appointy::Time &duration)
{
    _option = std::unique_ptr<appointy::Option> {new appointy::Option {_option->id, text, price, duration}};
}

