#ifndef FILE_LOADER_H
#define FILE_LOADER_H

#include "model.h"
#include "model_builder.h"
#include <fstream>
#include <QDebug>

class File_loader
{
public:
    File_loader();
    File_loader(const char *fnam);
    ~File_loader();

    shared_ptr<Model> load_model(Model_builder builder);

private:
    const char *fname;
    fstream file;
};

#endif // FILE_LOADER_H
