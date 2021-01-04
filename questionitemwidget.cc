#include "questionitemwidget.h"
#include "ui_questionitemwidget.h"

#include <QMainWindow>

#include <questioneditwindow.h>

QuestionItemWidget::QuestionItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionItemWidget)
{
    ui->setupUi(this);
    connect(ui->edit_btn, &QPushButton::clicked, this, &QuestionItemWidget::edit_clicked);
}

QuestionItemWidget::~QuestionItemWidget()
{
    delete ui;
}


auto QuestionItemWidget::edit_clicked() -> void
{
    QMainWindow *question_edit_window = new QuestionEditWindow(this);
    //connect(question_edit_window, &QuestionEditWindow::)
    question_edit_window->show();
}
