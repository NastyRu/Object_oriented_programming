#include "managers.h"

shared_ptr<Model> Work_with_file_manager::loader_from_file(File_loader &file_loader, Model_builder &builder) {
    return file_loader.load_model(builder);
}

void Work_with_file_manager::save_to_file(File_save &file_save, objects_iterator begin, objects_iterator end) {
    for (objects_iterator i = begin; i != end; i++) {
        if (!(*i)->is_compose() && (*i)->is_visible()) {
            Object *object = (*i).get();
            file_save.save_model(make_shared<Model>(*((Model*)object)));
        }
    }
}

void Draw_manager::draw_model(Base_draw &drawer, objects_iterator begin, objects_iterator end) {
    for (objects_iterator i = begin; i != end; i++) {
        if (!(*i)->is_compose() && (*i)->is_visible()) {
            Object *object = (*i).get();
            Model model = *((Model*)object);
            draw_iter_model(drawer, model);
        }
    }
}

void Draw_manager::draw_iter_model(Base_draw &drawer, Model model) {
    vector<Point_3d> points = model.get_points();
    vector<Edge> edges = model.get_edges();
    for (int i = 0; i < model.get_kol_edges(); i++) {
        drawer.drawline(points[edges[i].get_begin()], points[edges[i].get_end()]);
    }
}

void Transfrom_manager::offset_model(double dx, double dy, double dz, objects_iterator begin, objects_iterator end, positions_iterator pos) {
    for (objects_iterator i = begin; i != end; i++, pos++) {
        if (!(*i)->is_compose() && (*i)->is_visible()) {
            Object *object = (*i).get();
            Model* model = ((Model*)object);
            offset_iter_model(model, dx, dy, dz, *(*pos).get());
        }
    }
}

void Transfrom_manager::offset_iter_model(Model *model, double dx, double dy, double dz, Position &pos) {
    for (int i = 0; i < model->get_kol_points(); i++) {
        model->get_var_points()[i].offset(dx, dy, dz);
    }
    pos.get_center().offset(dx, dy, dz);
}

void Transfrom_manager::scale_model(double k, objects_iterator begin, objects_iterator end, positions_iterator pos) {
    for (objects_iterator i = begin; i != end; i++, pos++) {
        if (!(*i)->is_compose() && (*i)->is_visible()) {
            Object *object = (*i).get();
            Model* model = ((Model*)object);
            scale_iter_model(model, k, *(*pos).get());
        }
    }
}

void Transfrom_manager::scale_iter_model(Model *model, double k, Position &pos) {
    for (int i = 0; i < model->get_kol_points(); i++) {
        model->get_var_points()[i].scale(k, pos.get_center());
    }
}

void Transfrom_manager::rotate_x_model(double angle, objects_iterator begin, objects_iterator end, positions_iterator pos) {
    for (objects_iterator i = begin; i != end; i++, pos++) {
        if (!(*i)->is_compose() && (*i)->is_visible()) {
            Object *object = (*i).get();
            Model* model = ((Model*)object);
            rotate_x_iter_model(model, angle, *(*pos).get());
        }
    }
}

void Transfrom_manager::rotate_x_iter_model(Model *model, double angle, Position &pos) {
    for (int i = 0; i < model->get_kol_points(); i++) {
        model->get_var_points()[i].rotate_x(angle, pos.get_center());
    }
}

void Transfrom_manager::rotate_y_model(double angle, objects_iterator begin, objects_iterator end, positions_iterator pos) {
    for (objects_iterator i = begin; i != end; i++, pos++) {
        if (!(*i)->is_compose() && (*i)->is_visible()) {
            Object *object = (*i).get();
            Model* model = ((Model*)object);
            rotate_y_iter_model(model, angle, *(*pos).get());
        }
    }
}

void Transfrom_manager::rotate_y_iter_model(Model *model, double angle, Position &pos) {
    for (int i = 0; i < model->get_kol_points(); i++) {
        model->get_var_points()[i].rotate_y(angle, pos.get_center());
    }
}

void Transfrom_manager::rotate_z_model(double angle, objects_iterator begin, objects_iterator end, positions_iterator pos) {
    for (objects_iterator i = begin; i != end; i++, pos++) {
        if (!(*i)->is_compose() && (*i)->is_visible()) {
            Object *object = (*i).get();
            Model* model = ((Model*)object);
            rotate_z_iter_model(model, angle, *(*pos).get());
        }
    }
}

void Transfrom_manager::rotate_z_iter_model(Model *model, double angle, Position &pos) {
    for (int i = 0; i < model->get_kol_points(); i++) {
        model->get_var_points()[i].rotate_z(angle, pos.get_center());
    }
}
