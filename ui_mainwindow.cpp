#include "ui_mainwindow.h"
#include "ui_ui_mainwindow.h"

UI_MainWindow::UI_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UI_MainWindow)
{
    ui->setupUi(this);
}

UI_MainWindow::~UI_MainWindow()
{
    delete ui;
}
