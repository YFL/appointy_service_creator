#ifndef QUESTIONEDITWINDOW_H
#define QUESTIONEDITWINDOW_H

#include <QMainWindow>

namespace Ui {
class QuestionEditWindow;
}

class QuestionEditWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuestionEditWindow(QWidget *parent = nullptr);
    ~QuestionEditWindow();

private:
    Ui::QuestionEditWindow *ui;
};

#endif // QUESTIONEDITWINDOW_H
