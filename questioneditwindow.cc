#include "questioneditwindow.h"
#include "ui_questioneditwindow.h"

QuestionEditWindow::QuestionEditWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QuestionEditWindow)
{
    ui->setupUi(this);
    _text = ui->question_text->toPlainText().toStdString();
    _answer_signature = nullptr;
}

QuestionEditWindow::~QuestionEditWindow()
{
    delete ui;
}

void QuestionEditWindow::closeEvent(QCloseEvent *event)
{
    emit closing(_text, _answer_signature);
}

void QuestionEditWindow::free_value_radio_btn_state_change(bool checked)
{
    ui->free_value->setEnabled(checked);
}

void QuestionEditWindow::single_option_radio_btn_state_change(bool checked)
{
    ui->single_option->setEnabled(checked);
}

void QuestionEditWindow::multiple_options_radio_btn_state_change(bool checked)
{
    ui->multiple_options->setEnabled(checked);
}

void QuestionEditWindow::text_edit_changed()
{
    _text = ui->question_text->toPlainText().toStdString();
    emit text_changed(_text);
    emit question_changed(_text, _answer_signature);
}

void QuestionEditWindow::answer_signature_changed()
{

}
