#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::UI_MainWindow *ui;
};
#endif // UI_MAINWINDOW_H
