#include "ui_mainwindow.h"
#include "ui_ui_mainwindow.h"

UI_MainWindow::UI_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UI_MainWindow)
    , stage(new Stage("stageID")) // Initialize Stage instance
{
    ui->setupUi(this);

    // Initialize and start the timer
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &UI_MainWindow::updateUI);

    // Initialize the Stage
    // stage->initialize();
}

UI_MainWindow::~UI_MainWindow()
{
    // Shutdown the Stage
    stage->shutdown();
    timer->stop();
    delete stage;
    delete timer;
    delete ui;
}

void UI_MainWindow::updateUI()
{
    // Update the UI with the latest Stage data
    StageData data = stage->getStageData();
    // Example: Update labels or other UI elements with the data
    ui->lineEdit_Pos_X->setText(QString::number(data.positionX));
    ui->lineEdit_Pos_Y->setText(QString::number(data.positionY));
    ui->lineEdit_Vel_X->setText(QString::number(data.speedX));
    ui->lineEdit_Vel_Y->setText(QString::number(data.speedY));
    ui->lineEdit_Sta_X->setText(QString::number(data.statusX));
    ui->lineEdit_Sta_X->setText(QString::number(data.statusY));
}

void UI_MainWindow::on_pushButton_clicked(bool checked)
{
    if (checked) {
        // Example: Move the stage to a specific position when the button is checked
        stage->initialize();
        timer->start(100); // Update every second
        ui->pushButton->setText("Shutdown");
    } else {
        // Example: Stop the stage when the button is unchecked
        timer->stop();
        stage->shutdown();
        ui->pushButton->setText("Initialize");
    }
}


void UI_MainWindow::on_Btu_Joint_Pos_2_clicked()
{
    bool ok;
    signed int M_X = ui->lineEdit_AM_X_2->text().toInt(&ok);
    signed int M_Y = ui->lineEdit_AM_Y_2->text().toInt(&ok);


    if (ok) {
        Eigen::Vector2d target_positions(M_X, M_Y);
        stage->moveJointPosition(target_positions);
        // qDebug() << "M_S:" << M_S;
        // attitudeMeasurement->startMeasurement(target_positions);
    } else {
        QMessageBox::warning(this, "Error", "Please enter a valid signed integer.");
    }
}

