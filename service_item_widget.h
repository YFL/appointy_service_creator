#ifndef SERVICE_ITEM_WIDGET_H
#define SERVICE_ITEM_WIDGET_H

#include <QWidget>

#include <service.h>

namespace Ui {
class ServiceItemWidget;
}

class ServiceItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ServiceItemWidget(appointy::Service *service = nullptr, QWidget *parent = nullptr);
    ~ServiceItemWidget();

public:
    auto service() const -> appointy::Service;

private slots:
    void edit_btn_click();
    void service_save(const std::string &id, const std::string &name, const appointy::Price &price, const appointy::Time &duration, const std::vector<appointy::Question> &questions);

private:
    Ui::ServiceItemWidget *ui;
    std::unique_ptr<appointy::Service > _service;
};

#endif // SERVICE_ITEM_WIDGET_H
