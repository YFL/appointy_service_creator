#include "servicewidget.h"
#include "ui_servicewidget.h"

ServiceWidget::ServiceWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServiceWidget)
{
    ui->setupUi(this);
    connect(ui->name_edit, &QLineEdit::textChanged, this, &ServiceWidget::name_changed);
}

ServiceWidget::~ServiceWidget()
{
    delete ui;
}

void ServiceWidget::name_changed(const QString &text)
{
    _name = text.toStdString();
}

auto ServiceWidget::name() const -> std::string
{
    return _name;
}

auto ServiceWidget::duration() const -> appointy::Time
{
    return _duration;
}

auto ServiceWidget::price() const -> appointy::Price
{
    return _price;
}

auto ServiceWidget::questions() const -> const std::vector<appointy::Question> &
{
    return _questions;
}
