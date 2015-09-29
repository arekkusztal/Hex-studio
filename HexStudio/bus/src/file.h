#ifndef FILE_H
#define FILE_H

#include "../inc/types.h"

class File
{
public:
    int  *flen;
    char *fname;
    byte *fcontent;


    File();
    ~File();
};

#endif // FILE_H
