#ifndef OPTION_EDIT_WINDOW_H
#define OPTION_EDIT_WINDOW_H

#include <QMainWindow>

#include <option.h>

namespace Ui {
class OptionEditWindow;
}

class OptionEditWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OptionEditWindow(const appointy::Option &option, QWidget *parent = nullptr);
    ~OptionEditWindow();

signals:
    void option_saved(const std::string &text, const appointy::Price &price, const appointy::Time &time);

private slots:
    void save_btn_click();
    void cancel_btn_click();

private:
    Ui::OptionEditWindow *ui;
};

#endif // OPTION_EDIT_WINDOW_H
