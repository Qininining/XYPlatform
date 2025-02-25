#include "ui_mainwindow.h"
#include "ui_ui_mainwindow.h"

UI_MainWindow::UI_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UI_MainWindow)
    , timer(new QTimer(this)) // 初始化定时器
{
    ui->setupUi(this);

    // 连接定时器的超时信号到槽函数
    connect(timer, &QTimer::timeout, this, &UI_MainWindow::updateUI);

    // 启动定时器，设置间隔为1000毫秒（1秒）
    timer->start(1000);
}

UI_MainWindow::~UI_MainWindow()
{
    delete ui;
}

void UI_MainWindow::updateUI()
{
    // 在这里添加更新UI信息的代码
}
