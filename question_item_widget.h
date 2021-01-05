#ifndef QUESTION_ITEM_WIDGET_H
#define QUESTION_ITEM_WIDGET_H

#include <QWidget>

#include <question.h>

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
    appointy::Question question;
};

#endif // QUESTION_ITEM_WIDGET_H
