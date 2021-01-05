#ifndef OPTION_ITEM_WIDGET_H
#define OPTION_ITEM_WIDGET_H

#include <QWidget>

namespace Ui {
class OptionItemWidget;
}

class OptionItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OptionItemWidget(QWidget *parent = nullptr);
    ~OptionItemWidget();

private:
    Ui::OptionItemWidget *ui;
};

#endif // OPTION_ITEM_WIDGET_H
