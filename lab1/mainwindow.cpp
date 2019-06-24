#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    Actions actions;
    entry_func(ex, actions);
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    Actions actions;
    actions.p = &p;
    entry_func(draw, actions);
}

void MainWindow::on_pushButton_clicked()
{
    Actions actions;

    QString str = ui->lineEdit_2->text();
    if (str.toInt() == 0 && QString::compare(str, "0") != 0) {
        QMessageBox::critical(this,"ошибка","Неверно введены данные");
        return;
    }
    actions.dx = str.toInt();

    str = ui->lineEdit->text();
    if (str.toInt() == 0 && QString::compare(str, "0") != 0) {
        QMessageBox::critical(this,"ошибка","Неверно введены данные");
        return;
    }
    actions.dy = str.toInt();

    str = ui->lineEdit_10->text();
    if (str.toInt() == 0 && QString::compare(str, "0") != 0) {
        QMessageBox::critical(this,"ошибка","Неверно введены данные");
        return;
    }
    actions.dz = str.toInt();
    entry_func(off, actions);

    repaint();
}

void MainWindow::on_pushButton_2_clicked()
{
    Actions actions;

    QString str = ui->lineEdit_11->text();
    if (fabs(str.toDouble()) < 0.00001 && QString::compare(str, "0") != 0) {
        QMessageBox::critical(this,"ошибка","Неверно введены данные");
        return;
    }
    actions.k = str.toDouble();
    entry_func(sc, actions);

    repaint();
}

void MainWindow::on_pushButton_3_clicked()
{
    Actions actions;

    QString str = ui->lineEdit_7->text();
    if (str.toInt() == 0 && QString::compare(str, "0") != 0) {
        QMessageBox::critical(this,"ошибка","Неверно введены данные");
        return;
    }
    actions.anx = str.toInt();

    str = ui->lineEdit_8->text();
    if (str.toInt() == 0 && QString::compare(str, "0") != 0) {
        QMessageBox::critical(this,"ошибка","Неверно введены данные");
        return;
    }
    actions.any = str.toInt();

    str = ui->lineEdit_9->text();
    if (str.toInt() == 0 && QString::compare(str, "0") != 0) {
        QMessageBox::critical(this,"ошибка","Неверно введены данные");
        return;
    }
    actions.anz = str.toInt();
    entry_func(rot, actions);

    repaint();
}

void MainWindow::on_pushButton_4_clicked()
{
    Actions actions;
    QString filename = QFileDialog::getOpenFileName(nullptr, "Open Dialog", "", "*.txt");
    actions.filename = filename.toStdString().c_str();
    entry_func(load, actions);

    repaint();
}

void MainWindow::on_pushButton_5_clicked()
{
    Actions actions;
    QString filename = QFileDialog::getSaveFileName(nullptr, "Open Dialog", "", "*.txt");
    actions.filename = filename.toStdString().c_str();
    entry_func(save, actions);
}
