#include "question_edit_window.h"
#include "ui_questioneditwindow.h"

#include <iostream>

#include <numeric_answer_signature.h>

auto set_enabled_and_current_index(QTabWidget *tab_widget, int index, bool enabled)
{
    tab_widget->setTabEnabled(index, enabled);
    if(enabled)
    {
        tab_widget->setCurrentIndex(index);
    }
}

auto fill_answer_signature_data(Ui::QuestionEditWindow *ui, const std::shared_ptr<appointy::AnswerSignature> &answer_signature) -> void
{
    using namespace appointy;
    if(answer_signature->type == AnswerSignatureType::INT)
    {
        auto &as = dynamic_cast<NumericAnswerSignature<int> &>(*answer_signature);
        if(as.min)
        {
            ui->min_check_box->setChecked(true);
            ui->min_spin_box->setValue(as.min.value());
        }
        if(as.max)
        {
            ui->max_check_box->setChecked(true);
            ui->max_spin_box->setValue(as.max.value());
        }
        if(as.default_value)
        {
            ui->default_val_check_box->setChecked(true);
            ui->default_spin_box->setValue(as.default_value.value());
        }
    }
}

QuestionEditWindow::QuestionEditWindow(appointy::Question *question, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QuestionEditWindow)
{
    using namespace appointy;
    ui->setupUi(this);

    connect(ui->free_value_radio_btn, &QRadioButton::toggled, this, &QuestionEditWindow::free_value_radio_btn_state_change);
    connect(ui->single_option_radio_btn, &QRadioButton::toggled, this, &QuestionEditWindow::single_option_radio_btn_state_change);
    connect(ui->multiple_options_radio_btn, &QRadioButton::toggled, this, &QuestionEditWindow::multiple_options_radio_btn_state_change);
    connect(ui->int_radio_btn, &QRadioButton::toggled, this, &QuestionEditWindow::int_radio_btn_state_change);
    connect(ui->double_radio_btn, &QRadioButton::toggled, this, &QuestionEditWindow::double_radio_btn_state_change);

    if(question)
    {
        ui->question_text->setPlainText(QString {question->text.c_str()});
        switch((AnswerSignatureType::Type)question->answer_signature->type)
        {
            case AnswerSignatureType::SINGLE:
                ui->single_option_radio_btn->toggle();
                break;
            case AnswerSignatureType::MANY:
                ui->multiple_options_radio_btn->toggle();
                break;
            case AnswerSignatureType::INT:
                ui->free_value_radio_btn->toggle();
                ui->int_radio_btn->toggle();
                break;
            case AnswerSignatureType::DOUBLE:
                ui->free_value_radio_btn->toggle();
                ui->double_radio_btn->toggle();
                break;
        }
        fill_answer_signature_data(ui, question->answer_signature);
    }
    else
    {

    }
}

QuestionEditWindow::~QuestionEditWindow()
{
    delete ui;
}

void QuestionEditWindow::free_value_radio_btn_state_change(bool checked)
{
    set_enabled_and_current_index(ui->answer_signature_widget, 0, checked);
}

void QuestionEditWindow::single_option_radio_btn_state_change(bool checked)
{
    set_enabled_and_current_index(ui->answer_signature_widget, 1, checked);
}

void QuestionEditWindow::multiple_options_radio_btn_state_change(bool checked)
{
    set_enabled_and_current_index(ui->answer_signature_widget, 1, checked);
}

void QuestionEditWindow::int_radio_btn_state_change(bool checked)
{
    set_enabled_and_current_index(ui->value_answer_signature_widget, 0, checked);
}

void QuestionEditWindow::double_radio_btn_state_change(bool checked)
{
    set_enabled_and_current_index(ui->value_answer_signature_widget, 1, checked);
}

void QuestionEditWindow::min_check_box_state_change(bool checked)
{
    ui->min_spin_box->setEnabled(checked);
    ui->min_double_spin_box->setEnabled(checked);
}

void QuestionEditWindow::max_check_box_state_change(bool checked)
{
    ui->max_spin_box->setEnabled(checked);
    ui->max_double_spin_box->setEnabled(checked);
}

void QuestionEditWindow::default_val_check_box_state_change(bool checked)
{
    ui->default_spin_box->setEnabled(checked);
    ui->default_double_spin_box->setEnabled(checked);
}
