#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "draw.h"
#include "commands.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    if (facade.get_scene_container().get_objects().size() > 0) {
        DrawQt drawer(p);
        Draw_command command(drawer, facade.get_scene_container().get_begin_object(), facade.get_scene_container().get_end_object());
        command.call(facade);
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString str = ui->lineEdit_2->text();
    if (str.toInt() == 0 && QString::compare(str, "0") != 0) {
        QMessageBox::critical(this,"ошибка","Неверно введены данные");
        return;
    }
    double dx = str.toInt();

    str = ui->lineEdit->text();
    if (str.toInt() == 0 && QString::compare(str, "0") != 0) {
        QMessageBox::critical(this,"ошибка","Неверно введены данные");
        return;
    }
    double dy = str.toInt();

    str = ui->lineEdit_10->text();
    if (str.toInt() == 0 && QString::compare(str, "0") != 0) {
        QMessageBox::critical(this,"ошибка","Неверно введены данные");
        return;
    }
    double dz = str.toInt();

    Offset_command command(dx, dy, dz, facade.get_scene_container().get_begin_object(), facade.get_scene_container().get_end_object(), facade.get_scene_container().get_begin_position());
    command.call(facade);
    repaint();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString str = ui->lineEdit_11->text();
    if (fabs(str.toDouble()) < 0.00001 && QString::compare(str, "0") != 0) {
        QMessageBox::critical(this,"ошибка","Неверно введены данные");
        return;
    }
    double k = str.toDouble();

    Scale_command command(k, facade.get_scene_container().get_begin_object(), facade.get_scene_container().get_end_object(), facade.get_scene_container().get_begin_position());
    command.call(facade);
    repaint();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString str = ui->lineEdit_7->text();
    if (str.toInt() == 0 && QString::compare(str, "0") != 0) {
        QMessageBox::critical(this,"ошибка","Неверно введены данные");
        return;
    }
    double anx = str.toInt();

    Rotate_x_command command_x(anx, facade.get_scene_container().get_begin_object(), facade.get_scene_container().get_end_object(), facade.get_scene_container().get_begin_position());
    command_x.call(facade);

    str = ui->lineEdit_8->text();
    if (str.toInt() == 0 && QString::compare(str, "0") != 0) {
        QMessageBox::critical(this,"ошибка","Неверно введены данные");
        return;
    }
    double any = str.toInt();

    Rotate_y_command command_y(any, facade.get_scene_container().get_begin_object(), facade.get_scene_container().get_end_object(), facade.get_scene_container().get_begin_position());
    command_y.call(facade);

    str = ui->lineEdit_9->text();
    if (str.toInt() == 0 && QString::compare(str, "0") != 0) {
        QMessageBox::critical(this,"ошибка","Неверно введены данные");
        return;
    }
    double anz = str.toInt();

    Rotate_z_command command_z(anz, facade.get_scene_container().get_begin_object(), facade.get_scene_container().get_end_object(), facade.get_scene_container().get_begin_position());
    command_z.call(facade);

    repaint();
}

void MainWindow::on_pushButton_4_clicked()
{
    QString filename = QFileDialog::getOpenFileName(nullptr, "Open Dialog", "", "*.txt");
    const char *f = filename.toStdString().c_str();

    File_loader file_loader(f);
    Model_builder builder;
    Load_command command(file_loader, builder);
    command.call(facade);

    repaint();
}

void MainWindow::on_pushButton_5_clicked()
{
    QString filename = QFileDialog::getSaveFileName(nullptr, "Open Dialog", "", "*.txt");
    const char *f = filename.toStdString().c_str();

    File_save file_save(f);
    Save_command command(file_save, facade.get_scene_container().get_begin_object(), facade.get_scene_container().get_end_object());
    command.call(facade);
}
