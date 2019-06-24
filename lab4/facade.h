#ifndef FACADE_H
#define FACADE_H

#include "managers.h"
#include "scene_container.h"

class Facade
{
public:
    Facade() {}
    ~Facade() {}

    Work_with_file_manager get_work_with_file_manager();
    Draw_manager get_draw_manager();
    Transfrom_manager get_transfrom_manager();
    Delete_manager get_delete_manager();
    Scene_container &get_scene_container();

private:
    Work_with_file_manager work_with_file_manager;
    Draw_manager draw_manager;
    Transfrom_manager transfrom_manager;
    Delete_manager delete_manager;
    Scene_container scene_container;
};

#endif // FACADE_H
