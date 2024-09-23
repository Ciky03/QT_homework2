#include "aboutwindow.h"
#include "ui_aboutwindow.h"

aboutWindow::aboutWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::aboutWindow)
{
    ui->setupUi(this);
}

aboutWindow::~aboutWindow()
{
    delete ui;
}

void aboutWindow::on_pushButton_clicked()
{
    close();
}

