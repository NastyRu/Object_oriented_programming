#ifndef FILE_SAVE_H
#define FILE_SAVE_H

#include "model.h"
#include "exceptions.h"
#include <fstream>

using namespace std;

class File_save
{
public:
    File_save();
    File_save(const char *fnam);
    ~File_save();

    void save_model(shared_ptr<Model> model);

private:
    const char *fname;
    fstream file;
};

#endif // FILE_SAVE_H
