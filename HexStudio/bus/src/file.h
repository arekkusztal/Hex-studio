#ifndef FILE_H
#define FILE_H

#include "../inc/types.h"

class File
{
public:
    int  flen;
    char *fname;
    char *fcontent;


    File();
    ~File();
};

#endif // FILE_H
