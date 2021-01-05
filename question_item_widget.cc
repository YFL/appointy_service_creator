#include "question_item_widget.h"
#include "ui_questionitemwidget.h"

#include <QMainWindow>

#include <question_edit_window.h>

QuestionItemWidget::QuestionItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionItemWidget),
    question {std::string {""}, std::string {""}, nullptr}
{
    ui->setupUi(this);
    ui->question_text->setText(QString {question.text.c_str()});
    connect(ui->edit_btn, &QPushButton::clicked, this, &QuestionItemWidget::edit_clicked);
}

QuestionItemWidget::~QuestionItemWidget()
{
    delete ui;
}


auto QuestionItemWidget::edit_clicked() -> void
{
    QMainWindow *question_edit_window = new QuestionEditWindow(&question, this);
    //connect(question_edit_window, &QuestionEditWindow::)
    question_edit_window->show();
}
