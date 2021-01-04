#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <json.hpp>

#include <io_ops.h>
#include <json_parser.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    using nlohmann::json;

    auto services_str = appointy::load_services_from_json("/home/yofuckinlo/Programming/bachelor_proj/appointy/services_examples.json");
    json services_json = json::parse(services_str);
    std::vector<appointy::Service> services;

    for(auto &service : services_json)
    {
        services.push_back(appointy::JSON_Parser::parse_service(service));
    }

    std::string value;

    for(auto &service : services)
    {
        value += "-------------------------\n";
        value += service.to_string();
    }

    ui->service_view->setText(value.c_str());
}

MainWindow::~MainWindow()
{
    delete ui;
}

