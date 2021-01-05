#ifndef SERVICE_WIDGET_H
#define SERVICE_WIDGET_H

#include <QWidget>

#include <question.h>
#include <price.h>
#include <appointy_time.h>

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
    void on_add_question_btn_clicked();

private:
    Ui::ServiceWidget *ui;
};

#endif // SERVICE_WIDGET_H
