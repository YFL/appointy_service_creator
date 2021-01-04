#ifndef QUESTIONEDITWINDOW_H
#define QUESTIONEDITWINDOW_H

#include <QMainWindow>

#include <answer_signature.h>

namespace Ui {
class QuestionEditWindow;
}

class QuestionEditWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuestionEditWindow(QWidget *parent = nullptr);
    ~QuestionEditWindow();

public:
    virtual void closeEvent(QCloseEvent *event) override;

signals:
    void text_changed(const std::string &text);
    void answer_signature_changed(std::shared_ptr<appointy::AnswerSignature> answer_signature);
    void question_changed(const std::string &text, std::shared_ptr<appointy::AnswerSignature> answer_signature);
    void closing(const std::string text, std::shared_ptr<appointy::AnswerSignature> answer_signature);

private slots:
    void free_value_radio_btn_state_change(bool checked);
    void single_option_radio_btn_state_change(bool checked);
    void multiple_options_radio_btn_state_change(bool checked);
    void text_edit_changed();
    void answer_signature_changed();

private:
    Ui::QuestionEditWindow *ui;

private:
    std::string _text;
    std::shared_ptr<appointy::AnswerSignature> _answer_signature;
};

#endif // QUESTIONEDITWINDOW_H
