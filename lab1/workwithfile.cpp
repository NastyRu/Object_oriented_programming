#include "workwithfile.h"

#define COR 0
#define INCOR 1

int open_file(File &f, const char *filename) {
    f.name = filename;
    f.file.open(f.name);
    if (!f.file) {
        return NO_FILE;
    }
    return OK;
}

void close_file(File &f) {
    f.file.close();
}

int readf(int &x, File &f) {
    if (!(f.file >> x)) {
        return INCOR;
    }
    return COR;
}

void writef(File &f, int x) {
    f.file << x;
}

void writef(File &f, char x) {
    f.file << x;
}

