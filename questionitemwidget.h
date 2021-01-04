#ifndef QUESTIONITEMWIDGET_H
#define QUESTIONITEMWIDGET_H

#include <QWidget>

namespace Ui {
class QuestionItemWidget;
}

class QuestionItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QuestionItemWidget(QWidget *parent = nullptr);
    ~QuestionItemWidget();

private slots:
    void edit_clicked();

private:
    Ui::QuestionItemWidget *ui;
};

#endif // QUESTIONITEMWIDGET_H
