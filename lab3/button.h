#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QPushButton>

class button : public QObject
{
    Q_OBJECT
    enum button_state {
        pressed,
        reseted,
    };

public:
    button();
    void set_floor(int f);
    void set_btn(QPushButton *btn);

public slots:
    void press();
    void reset();
    bool is_pressed();

signals:
    void press_btn();
    void reset_btn();

private:
    button_state bstate;
    int floor;
    QPushButton *btn;
};
#endif // BUTTON_H
