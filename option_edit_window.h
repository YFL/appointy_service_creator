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
    explicit OptionEditWindow(appointy::Option *option = nullptr, QWidget *parent = nullptr);
    ~OptionEditWindow();

signals:
    void save_btn_clicked(const std::string &text, const appointy::Price &price, const appointy::Time &time);

private slots:
    void save_btn_click();

private:
    Ui::OptionEditWindow *ui;
};

#endif // OPTION_EDIT_WINDOW_H
