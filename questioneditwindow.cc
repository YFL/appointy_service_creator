#include "questioneditwindow.h"
#include "ui_questioneditwindow.h"

QuestionEditWindow::QuestionEditWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QuestionEditWindow)
{
    ui->setupUi(this);
}

QuestionEditWindow::~QuestionEditWindow()
{
    delete ui;
}
