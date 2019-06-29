#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QLabel>
#include <QTimer>

class doors : public QObject {
    Q_OBJECT
    enum doors_state {
        close,
        closing,
        open,
        opening,
    };

public:
    doors();
    bool is_open();
    void label(QLabel *state_doors);

private:
    doors_state dstate;
    QLabel *state_doors;
    QTimer door_open_timer;
    QTimer door_close_timer;
    int wait_time = 1000;

public slots:
    void open_doors();
    void close_doors();
    void opening_doors();
    void closing_doors();

signals:
    void openned();
    void closed();
};

#endif // DOORS_H
