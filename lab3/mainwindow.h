#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "lift.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_click_lift_1_clicked();
    void on_click_lift_2_clicked();
    void on_click_lift_3_clicked();
    void on_click_lift_4_clicked();
    void on_click_lift_5_clicked();
    void on_click_lift_6_clicked();
    void on_click_lift_7_clicked();
    void on_click_lift_8_clicked();
    void on_click_lift_9_clicked();
    void on_click_lift_10_clicked();

    void on_lift_to_1_clicked();
    void on_lift_to_2_clicked();
    void on_lift_to_3_clicked();
    void on_lift_to_4_clicked();
    void on_lift_to_5_clicked();
    void on_lift_to_6_clicked();
    void on_lift_to_7_clicked();
    void on_lift_to_8_clicked();
    void on_lift_to_9_clicked();
    void on_lift_to_10_clicked();

private:
    Ui::MainWindow *ui;
    lift my_lift;
};

#endif // MAINWINDOW_H
