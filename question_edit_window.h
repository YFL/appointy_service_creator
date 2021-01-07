#ifndef QUESTION_EDIT_WINDOW_H
#define QUESTION_EDIT_WINDOW_H

#include <QMainWindow>

#include <answer_signature.h>
#include <question.h>

namespace Ui {
class QuestionEditWindow;
}

class QuestionEditWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuestionEditWindow(const appointy::Question &question, QWidget *parent = nullptr);
    ~QuestionEditWindow();

signals:
    void question_saved(const std::string &text, std::shared_ptr<appointy::AnswerSignature> &answer_signature);

private slots:
    void free_value_radio_btn_state_change(bool checked);
    void single_option_radio_btn_state_change(bool checked);
    void multiple_options_radio_btn_state_change(bool checked);
    void int_radio_btn_state_change(bool checked);
    void double_radio_btn_state_change(bool checked);
    void min_check_box_state_change(bool checked);
    void max_check_box_state_change(bool checked);
    void default_val_check_box_state_change(bool checked);
    void save_btn_click();
    void cancel_btn_click();
    void add_option_btn_click();
    void remove_option_btn_click();

private:
    Ui::QuestionEditWindow *ui;
};

#endif // QUESTION_EDIT_WINDOW_H
