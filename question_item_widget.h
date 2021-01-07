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
    explicit QuestionItemWidget(const appointy::Question * const question = nullptr, QWidget *parent = nullptr);
    ~QuestionItemWidget();

public:
    auto question() const -> const appointy::Question;

private slots:
    void edit_click();
    void question_save(const std::string &text, std::shared_ptr<appointy::AnswerSignature> &answer_signature);

private:
    Ui::QuestionItemWidget *ui;
    std::unique_ptr<appointy::Question> _question;
};

#endif // QUESTION_ITEM_WIDGET_H
