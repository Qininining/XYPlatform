#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMessageBox>
#include "Stage.h" // Include Stage header file

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
    void updateUI(); // Slot function declaration

    void on_pushButton_clicked(bool checked);

    void on_Btu_Joint_Pos_2_clicked();

private:
    Ui::UI_MainWindow *ui;
    QTimer *timer; // QTimer member variable
    Stage *stage; // Stage member variable
    QThread *stageThread; // QThread member variable
};

#endif // UI_MAINWINDOW_H
