#include "question_item_widget.h"
#include "ui_question_item_widget.h"

#include <QMainWindow>

#include <question_edit_window.h>

QuestionItemWidget::QuestionItemWidget(const appointy::Question * const question, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionItemWidget)
{
    ui->setupUi(this);
    if(!question)
    {
        _question = std::unique_ptr<appointy::Question> {new appointy::Question {{""}, nullptr}};
    }
    else
    {
        _question = std::unique_ptr<appointy::Question> {new appointy::Question {*question}};
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
    auto question_edit_window = new QuestionEditWindow(*_question, this);
    connect(question_edit_window, &QuestionEditWindow::question_saved, this, &QuestionItemWidget::question_save);
    question_edit_window->show();
}

void QuestionItemWidget::question_save(const std::string &text, std::shared_ptr<appointy::AnswerSignature> &answer_signature)
{
    _question = std::unique_ptr<appointy::Question> { new appointy::Question {text, answer_signature}};
    ui->question_text->setText(_question->text.c_str());
}
