#include "file_loader.h"

File_loader::File_loader() {
    file.open(fname);
    if (!file) {
        throw Work_with_file_exceptions();
    }
}

File_loader::File_loader(const char *fnam) : fname(fnam) {
    file.open(fname);
    if (!file) {
        throw Work_with_file_exceptions();
    }
}

File_loader::~File_loader() {
    if (file) {
        file.close();
    }
}

shared_ptr<Model> File_loader::load_model(Model_builder builder) {
    builder.build_model();

    double x, y, z;
    int begin, end;

    int n;

    file >> n;
    for (int i = 0; i < n; i++) {
        file >> x >> y >> z;
        builder.build_point(x, y, z);
    }

    file >> n;
    for (int i = 0; i < n; i++) {
        file >> begin >> end;
        builder.build_edge(begin, end);
    }

    return builder.get_result();
}
