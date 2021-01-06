#include "question_edit_window.h"
#include "ui_question_edit_window.h"

#include <iostream>

#include <choice_answer_signature.h>
#include <numeric_answer_signature.h>

#include <option_item_widget.h>

#include <util.h>

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
        ui->duration->setText(as.duration.to_string().c_str());
        ui->price->setText(as.price.to_string().c_str());
    }
    else if(answer_signature->type == AnswerSignatureType::DOUBLE)
    {
        auto &as = dynamic_cast<NumericAnswerSignature<double> &>(*answer_signature);
        if(as.min)
        {
            ui->min_check_box->setChecked(true);
            ui->min_double_spin_box->setValue(as.min.value());
        }
        if(as.max)
        {
            ui->max_check_box->setChecked(true);
            ui->max_double_spin_box->setValue(as.max.value());
        }
        if(as.default_value)
        {
            ui->default_val_check_box->setChecked(true);
            ui->default_double_spin_box->setValue(as.default_value.value());
        }
        ui->duration->setText(as.duration.to_string().c_str());
        ui->price->setText(as.price.to_string().c_str());
    }
    else
    {
        auto as = dynamic_cast<ChoiceAnswerSignature &>(*answer_signature);
        for(auto &option : as.options)
        {
            auto item = new QListWidgetItem {ui->options};
            auto widget = new OptionItemWidget {&option, ui->options};
            ui->options->addItem(item);
            ui->options->setItemWidget(item, widget);
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
    connect(ui->save_btn, &QPushButton::clicked, this, &QuestionEditWindow::save_btn_click);
    connect(ui->add_option_btn, &QPushButton::clicked, this, &QuestionEditWindow::add_option_btn_click);

    if(question)
    {
        ui->question_text->setPlainText(QString {question->text.c_str()});
        if(question->answer_signature)
        {
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
    }
    else
    {
        ui->free_value_radio_btn->setChecked(true);
        ui->int_radio_btn->setChecked(true);
        ui->answer_signature_widget->setTabEnabled(0, true);
        ui->answer_signature_widget->setTabEnabled(1, false);
        ui->value_answer_signature_widget->setTabEnabled(0, true);
        ui->value_answer_signature_widget->setTabEnabled(1, false);
        ui->min_check_box->setChecked(false);
        ui->min_spin_box->setEnabled(false);
        ui->min_double_spin_box->setEnabled(false);
        ui->max_check_box->setChecked(false);
        ui->max_spin_box->setEnabled(false);
        ui->max_double_spin_box->setEnabled(false);
        ui->default_val_check_box->setChecked(false);
        ui->default_spin_box->setEnabled(false);
        ui->default_double_spin_box->setEnabled(false);
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

void QuestionEditWindow::save_btn_click()
{
    using namespace appointy;
    auto text = ui->question_text->toPlainText().toStdString();

    Time duration {string_to_time(ui->duration->text().toStdString())};
    Price price {string_to_price(ui->price->text().toStdString())};

    std::shared_ptr<appointy::AnswerSignature> answer_signature;

    if(ui->free_value_radio_btn->isChecked())
    {
        if(ui->int_radio_btn->isChecked())
        {
            answer_signature = std::shared_ptr<appointy::AnswerSignature>(new appointy::NumericAnswerSignature<int>
            {
                {"0"},
                ui->min_spin_box->value(),
                ui->max_spin_box->value(),
                ui->default_spin_box->value(),
                duration,
                price
            });
        }
        else if(ui->double_radio_btn->isChecked())
        {
            answer_signature = std::shared_ptr<appointy::AnswerSignature>(new appointy::NumericAnswerSignature<double>
            {
                text,
                ui->min_double_spin_box->value(),
                ui->max_double_spin_box->value(),
                ui->default_double_spin_box->value(),
                duration,
                price
            });
        }
    }
    else
    {
        ChoiceType type;
        if(ui->single_option_radio_btn->isChecked())
        {
            type = ChoiceType::SINGLE;
        }
        else if(ui->multiple_options_radio_btn->isChecked())
        {
            type = ChoiceType::MANY;
        }

        std::vector<Option> options;
        for(int i = 0; i < ui->options->count(); i++)
        {
            auto option_item_widget = dynamic_cast<OptionItemWidget *>(ui->options->itemWidget(ui->options->item(i)));
            if(option_item_widget)
            {
                options.push_back(option_item_widget->option());
            }
        }
        answer_signature = std::shared_ptr<ChoiceAnswerSignature> {new ChoiceAnswerSignature
        {
            {"0"},
            type,
            options
        }};
    }

    emit save_btn_clicked(text, answer_signature);
}

void QuestionEditWindow::add_option_btn_click()
{
    auto *widget = new OptionItemWidget {nullptr, this};
    auto *item = new QListWidgetItem {ui->options};
    ui->options->addItem(item);
    ui->options->setItemWidget(item, widget);
    item->setSizeHint(QSize {282, 36});
    widget->show();
}

void QuestionEditWindow::remove_option_btn_click()
{

}
