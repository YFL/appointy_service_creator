#ifndef SERVICE_EDIT_WINDOW_H
#define SERVICE_EDIT_WINDOW_H

#include <QMainWindow>

#include <service.h>

namespace Ui {
class ServiceEditWindow;
}

class ServiceEditWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServiceEditWindow(const appointy::Service &service, QWidget *parent = nullptr);
    ~ServiceEditWindow();

signals:
    void service_saved(const std::string &id, const std::string &name, const appointy::Price &price, const appointy::Time &duration, const std::vector<appointy::Question> &questions);

private slots:
    void save_btn_click();
    void cancel_btn_click();
    void add_question_btn_click();
    void remove_question_btn_click();

private:
    Ui::ServiceEditWindow *ui;
};

#endif // SERVICE_EDIT_WINDOW_H
