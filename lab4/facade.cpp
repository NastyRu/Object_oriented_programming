#include "facade.h"

Work_with_file_manager Facade::get_work_with_file_manager() {
    return work_with_file_manager;
}

Draw_manager Facade::get_draw_manager() {
    return draw_manager;
}

Transfrom_manager Facade::get_transfrom_manager() {
    return transfrom_manager;
}

Delete_manager Facade::get_delete_manager() {
    return delete_manager;
}

Scene_container &Facade::get_scene_container() {
    return scene_container;
}
