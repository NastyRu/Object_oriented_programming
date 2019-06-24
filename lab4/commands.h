#ifndef COMMANDS_H
#define COMMANDS_H

#include "facade.h"

class Command
{
public:
    Command() {}
    Command(objects_iterator begin);
    Command(objects_iterator begin, objects_iterator end);
    ~Command() {}

    virtual void call(Facade &facade) = 0;

protected:
    objects_iterator begin;
    objects_iterator end;
};

class Load_command : Command
{
public:
    Load_command(File_loader &file_loade, Model_builder &builde);
    ~Load_command() {}

    void call(Facade &facade) override;

private:
    File_loader &file_loader;
    Model_builder &builder;
};

class Save_command : Command
{
public:
    Save_command(File_save &file_sav, objects_iterator begin);
    Save_command(File_save &file_sav, objects_iterator begin, objects_iterator end);
    ~Save_command() {}

    void call(Facade &facade) override;

private:
    File_save &file_save;
};

class Draw_command : Command
{
public:
    Draw_command(Base_draw &drawe, objects_iterator begin);
    Draw_command(Base_draw &drawe, objects_iterator begin, objects_iterator end);
    ~Draw_command() {}

    void call(Facade &facade) override;

private:
    Base_draw &drawer;
};

class Offset_command : Command
{
public:
    Offset_command(double dx, double dy, double dz, objects_iterator begin, positions_iterator pos);
    Offset_command(double dx, double dy, double dz, objects_iterator begin, objects_iterator end, positions_iterator pos);
    ~Offset_command() {}

    void call(Facade &facade) override;

private:
    positions_iterator pos;
    double dx, dy, dz;
};

class Scale_command : Command
{
public:
    Scale_command(double k, objects_iterator begin, positions_iterator pos);
    Scale_command(double k, objects_iterator begin, objects_iterator end, positions_iterator pos);
    ~Scale_command() {}

    void call(Facade &facade) override;

private:
    positions_iterator pos;
    double k;
};

class Rotate_x_command : Command
{
public:
    Rotate_x_command(double angle, objects_iterator begin, positions_iterator pos);
    Rotate_x_command(double angle, objects_iterator begin, objects_iterator end, positions_iterator pos);
    ~Rotate_x_command() {}

    void call(Facade &facade) override;

private:
    positions_iterator pos;
    double angle;
};

class Rotate_y_command : Command
{
public:
    Rotate_y_command(double angle, objects_iterator begin, positions_iterator pos);
    Rotate_y_command(double angle, objects_iterator begin, objects_iterator end, positions_iterator pos);
    ~Rotate_y_command() {}

    void call(Facade &facade) override;

private:
    positions_iterator pos;
    double angle;
};

class Rotate_z_command : Command
{
public:
    Rotate_z_command(double angle, objects_iterator begin, positions_iterator pos);
    Rotate_z_command(double angle, objects_iterator begin, objects_iterator end, positions_iterator pos);
    ~Rotate_z_command() {}

    void call(Facade &facade) override;

private:
    positions_iterator pos;
    double angle;
};

class Delete_command : Command
{
public:
    Delete_command() {}
    ~Delete_command() {}

    void call(Facade &facade) override;
};

#endif // COMMANDS_H
