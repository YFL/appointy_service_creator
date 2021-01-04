#include "servicewidget.h"
#include "ui_servicewidget.h"

#include <QVBoxLayout>

#include <questioneditwindow.h>

ServiceWidget::ServiceWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServiceWidget)
{
    ui->setupUi(this);
    connect(ui->name_edit, &QLineEdit::textChanged, this, &ServiceWidget::name_changed);
}

ServiceWidget::~ServiceWidget()
{
    delete ui;
}

void ServiceWidget::name_changed(const QString &text)
{
    _name = text.toStdString();
}

void ServiceWidget::price_changed(const QString &new_price)
{
    return;
}

void ServiceWidget::duration_changed(const QString &new_duration)
{

}

void ServiceWidget::questions_changed(const std::vector<appointy::Question> &new_questions)
{

}

auto ServiceWidget::name() const -> std::string
{
    return _name;
}

auto ServiceWidget::duration() const -> appointy::Time
{
    return _duration;
}

auto ServiceWidget::price() const -> appointy::Price
{
    return _price;
}

auto ServiceWidget::questions() const -> const std::vector<appointy::Question> &
{
    return _questions;
}

void ServiceWidget::new_question_imbound(const std::string text, std::shared_ptr<appointy::AnswerSignature> answer_signature)
{
    if(text != "" && answer_signature)
    {
        _questions.push_back(appointy::Question {std::string {"0"}, text, answer_signature});
        QLayout *layout = ui->question_items->layout();
        if(!layout)
        {
            layout = new QVBoxLayout(ui->question_items);
            ui->question_items->setLayout(layout);
        }
        layout->addWidget(new QuestionItemWidget(this));
    }
}

void ServiceWidget::on_add_question_btn_clicked()
{
    QuestionEditWindow *question_edit_window= new QuestionEditWindow(this);
    connect(question_edit_window, &QuestionEditWindow::closing, this, &ServiceWidget::new_question_imbound);
    question_edit_window->show();
}
