#include "file_save.h"
#include <QDebug>

File_save::File_save() {
    file.open(fname);
    if (!file) {
        throw Work_with_file_exceptions();
    }
}

File_save::File_save(const char *fnam) : fname(fnam) {
    file.open(fname);
    if (!file) {
        throw Work_with_file_exceptions();
    }
}

File_save::~File_save() {
    if (file) {
        file.close();
    }
}

void File_save::save_model(shared_ptr<Model> model) {
    int np = model->get_kol_points();
    vector<Point_3d> points = model->get_points();
    int ne = model->get_kol_edges();
    vector<Edge> edges = model->get_edges();

    file << np << endl;
    for (int i = 0; i < np; i++) {
        file << points[i].get_x() << " " << points[i].get_y() << " " << points[i].get_z() << endl;
    }

    file << ne << endl;
    for (int i = 0; i < ne; i++) {
        file << edges[i].get_begin() << " " << edges[i].get_end() << endl;
    }
}
