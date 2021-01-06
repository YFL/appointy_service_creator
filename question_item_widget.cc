#include "question_item_widget.h"
#include "ui_question_item_widget.h"

#include <QMainWindow>

#include <question_edit_window.h>

QuestionItemWidget::QuestionItemWidget(appointy::Question *question, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionItemWidget),
    _question {question}
{
    ui->setupUi(this);
    if(!question)
    {
        _question = std::unique_ptr<appointy::Question> {new appointy::Question {{""}, {""}, nullptr}};
    }
    ui->question_text->setText(QString {_question->text.c_str()});
    connect(ui->edit_btn, &QPushButton::clicked, this, &QuestionItemWidget::edit_click);
}

QuestionItemWidget::~QuestionItemWidget()
{
    delete ui;
}

auto QuestionItemWidget::question() const -> const appointy::Question
{
    return *_question;
}


auto QuestionItemWidget::edit_click() -> void
{
    auto question_edit_window = new QuestionEditWindow(_question.get(), this);
    connect(question_edit_window, &QuestionEditWindow::save_btn_clicked, this, &QuestionItemWidget::question_save);
    question_edit_window->show();
}

void QuestionItemWidget::question_save(const std::string &text, std::shared_ptr<appointy::AnswerSignature> &answer_signature)
{
    _question = std::unique_ptr<appointy::Question> { new appointy::Question {_question->id, text, answer_signature}};
}
