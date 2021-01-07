#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include <service.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void add_service_btn_click();
    void remove_service_btn_click();

    void new_session();
    void open_services();
    void save_services();
    void save_services_as();

private:
    Ui::MainWindow *ui;

private:
    std::vector<appointy::Service> _services;
};
#endif // MAIN_WINDOW_H
