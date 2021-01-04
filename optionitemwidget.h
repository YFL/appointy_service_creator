#ifndef OPTIONITEMWIDGET_H
#define OPTIONITEMWIDGET_H

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

#endif // OPTIONITEMWIDGET_H
