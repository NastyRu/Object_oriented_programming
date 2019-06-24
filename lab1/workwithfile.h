#ifndef WORKWITHFILE_H
#define WORKWITHFILE_H

#include "entry.h"
#include <fstream>
#include <QDebug>
using namespace std;

#define NO_FILE -1
#define OK 0
#define INCORRECT -2

struct File {
    fstream file;
    const char *name;
};

int open_file(File &, const char *);
void close_file(File &);
int readf(int &, File &);
void writef(File &, int );
void writef(File &, char );

#endif // WORKWITHFILE_H
