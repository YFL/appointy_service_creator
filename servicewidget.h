#ifndef SERVICEWIDGET_H
#define SERVICEWIDGET_H

#include <QWidget>

#include <question.h>
#include <price.h>
#include <appointy_time.h>

#include <questionitemwidget.h>

namespace Ui {
class ServiceWidget;
}

class ServiceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ServiceWidget(QWidget *parent = nullptr);
    ~ServiceWidget();

private slots:
    void name_changed(const QString &new_text);
    void price_changed(const QString &new_price);
    void duration_changed(const QString &new_duration);
    void questions_changed(const std::vector<appointy::Question> &new_questions);
    void new_question_imbound(const std::string text, std::shared_ptr<appointy::AnswerSignature> answer_signature);

    void on_add_question_btn_clicked();

private:
    Ui::ServiceWidget *ui;

public:
    auto name() const -> std::string;
    auto duration() const -> appointy::Time;
    auto price() const -> appointy::Price;
    auto questions() const -> const std::vector<appointy::Question> &;

private:
    std::string _name;
    appointy::Time _duration {static_cast<std::time_t>(0)};
    appointy::Price _price {0, 0};
    std::vector<appointy::Question> _questions;
};

#endif // SERVICEWIDGET_H
