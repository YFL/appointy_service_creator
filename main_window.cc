#include "main_window.h"
#include "ui_main_window.h"

#include <fstream>

#include <QFileDialog>

#include <json.hpp>

#include <io_ops.h>
#include <json_parser.h>


#include <service_item_widget.h>
#include <util.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->add_service_btn, &QPushButton::clicked, this, &MainWindow::add_service_btn_click);
    connect(ui->remove_service_btn, &QPushButton::clicked, this, &MainWindow::remove_service_btn_click);
    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::new_session);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::open_services);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::save_services);
    connect(ui->actionSave_as, &QAction::triggered, this, &MainWindow::save_services_as);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add_service_btn_click()
{
    auto *widget = new ServiceItemWidget {nullptr, this};
    add_widget_to_list_widget(widget, ui->services, QSize{340, 36});
    widget->show();
}

void MainWindow::remove_service_btn_click()
{
    auto selected = ui->services->selectedItems();
    for(auto *item : selected)
    {
        remove_item_from_list_widget(item, ui->services);
        delete item;
    }
}

void MainWindow::new_session()
{

}

void MainWindow::open_services()
{

}

void MainWindow::save_services()
{

}

void MainWindow::save_services_as()
{
    QFileDialog fsd {};
    fsd.setFileMode(QFileDialog::AnyFile);
    fsd.setAcceptMode(QFileDialog::AcceptSave);
    fsd.setNameFilter({"JSON Files (*.json)"});
    fsd.setDefaultSuffix({"json"});
    fsd.setViewMode(QFileDialog::Detail);

    if(fsd.exec())
    {
        auto file_names = fsd.selectedFiles();
        for(auto &fn : file_names)
        {
            std::ofstream file {fn.toStdString()};
            if(!file.is_open())
            {
                show_error_with_ok("Couldn't save to file " + fn.toStdString(), std::strerror(errno));
                continue;
            }
            using nlohmann::json;
            json j = "[]"_json;
            for(int i = 0; i < ui->services->count(); i++)
            {
                j.push_back(dynamic_cast<ServiceItemWidget *>(ui->services->itemWidget(ui->services->item(i)))->service().to_json());
            }
            file << j.dump() << "\n";
        }
    }
}
