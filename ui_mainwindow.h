#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QMainWindow>
#include <QTimer> // 添加 QTimer 头文件

QT_BEGIN_NAMESPACE
namespace Ui {
class UI_MainWindow;
}
QT_END_NAMESPACE

class UI_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    UI_MainWindow(QWidget *parent = nullptr);
    ~UI_MainWindow();

private slots:
    void updateUI(); // 添加槽函数声明

private:
    Ui::UI_MainWindow *ui;
    QTimer *timer; // 添加 QTimer 成员变量
};
#endif // UI_MAINWINDOW_H
