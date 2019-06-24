#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QLabel>

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
