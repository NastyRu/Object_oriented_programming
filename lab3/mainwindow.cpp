#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    my_lift.labels(ui->state_floor, ui->state_lift, ui->state_doors);
    my_lift.buttons(10, ui->click_lift_1, ui->click_lift_2, ui->click_lift_3, ui->click_lift_4,
                    ui->click_lift_5, ui->click_lift_6, ui->click_lift_7, ui->click_lift_8,
                    ui->click_lift_9, ui->click_lift_10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_click_lift_1_clicked()
{
    my_lift.get_floor(1);
}

void MainWindow::on_click_lift_2_clicked()
{
    my_lift.get_floor(2);
}

void MainWindow::on_click_lift_3_clicked()
{
    my_lift.get_floor(3);
}

void MainWindow::on_click_lift_4_clicked()
{
    my_lift.get_floor(4);
}

void MainWindow::on_click_lift_5_clicked()
{
    my_lift.get_floor(5);
}

void MainWindow::on_click_lift_6_clicked()
{
    my_lift.get_floor(6);
}

void MainWindow::on_click_lift_7_clicked()
{
    my_lift.get_floor(7);
}

void MainWindow::on_click_lift_8_clicked()
{
    my_lift.get_floor(8);
}

void MainWindow::on_click_lift_9_clicked()
{
    my_lift.get_floor(9);
}

void MainWindow::on_click_lift_10_clicked()
{
    my_lift.get_floor(10);
}

void MainWindow::on_lift_to_1_clicked()
{
    my_lift.get_floor(1);
}

void MainWindow::on_lift_to_2_clicked()
{
    my_lift.get_floor(2);
}

void MainWindow::on_lift_to_3_clicked()
{
    my_lift.get_floor(3);
}

void MainWindow::on_lift_to_4_clicked()
{
    my_lift.get_floor(4);
}

void MainWindow::on_lift_to_5_clicked()
{
    my_lift.get_floor(5);
}

void MainWindow::on_lift_to_6_clicked()
{
    my_lift.get_floor(6);
}

void MainWindow::on_lift_to_7_clicked()
{
    my_lift.get_floor(7);
}

void MainWindow::on_lift_to_8_clicked()
{
    my_lift.get_floor(8);
}

void MainWindow::on_lift_to_9_clicked()
{
    my_lift.get_floor(9);
}

void MainWindow::on_lift_to_10_clicked()
{
    my_lift.get_floor(10);
}
