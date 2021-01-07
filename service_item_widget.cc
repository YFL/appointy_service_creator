#include "service_item_widget.h"
#include "ui_service_item_widget.h"

#include <service_edit_window.h>

ServiceItemWidget::ServiceItemWidget(appointy::Service *service, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServiceItemWidget)
{
    using namespace appointy;
    ui->setupUi(this);
    if(service)
    {
        _service = std::unique_ptr<Service> {new Service {*service}};
    }
    else
    {
        _service = std::unique_ptr<Service> {new Service {{"0"}, {""}, {0, 0}, {0, 0, 0}, {}}};
    }

    connect(ui->edit_btn, &QPushButton::clicked, this, &ServiceItemWidget::edit_btn_click);
}

ServiceItemWidget::~ServiceItemWidget()
{
    delete ui;
}

appointy::Service ServiceItemWidget::service() const
{
    return *_service;
}

void ServiceItemWidget::edit_btn_click()
{
    auto service_edit_window = new ServiceEditWindow(*_service, this);
    connect(service_edit_window, &ServiceEditWindow::service_saved, this, &ServiceItemWidget::service_save);
    service_edit_window->show();
}

void ServiceItemWidget::service_save(const std::string &id, const std::string &name, const appointy::Price &price, const appointy::Time &duration, const std::vector<appointy::Question> &questions)
{
    _service = std::unique_ptr<appointy::Service> {new appointy::Service {id, name, price, duration, questions}};
    ui->name->setText(_service->name.c_str());
}
