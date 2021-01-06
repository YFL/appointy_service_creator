#ifndef OPTION_ITEM_WIDGET_H
#define OPTION_ITEM_WIDGET_H

#include <QWidget>

#include <option.h>

namespace Ui {
class OptionItemWidget;
}

class OptionItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OptionItemWidget(const appointy::Option *option = nullptr, QWidget *parent = nullptr);
    ~OptionItemWidget();

public:
    auto option() const -> const appointy::Option;

private slots:
    void edit_btn_click();
    void option_save(const std::string &text, const appointy::Price &price, const appointy::Time &duration);

private:
    Ui::OptionItemWidget *ui;
    std::unique_ptr<appointy::Option> _option;
};

#endif // OPTION_ITEM_WIDGET_H
