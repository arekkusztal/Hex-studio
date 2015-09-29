#include <fstream>
#include <list>
#include "file.h"

#define     SECLEN 512

extern std::list<File *> filenames;

int readfile(char *filename)
{
    int error = 0;

    File *file = new File();
    file->fname = filename;

    std::ifstream is(filename,std::ifstream::binary);
    if (is)
    {
        is.seekg(0,is.end);
        file->flen = is.tellg();
        is.seekg(0,is.beg);

        file->fcontent = new char[file->flen];
        if (!file)
        {
            error = -1;
            goto END;
        }

        char *str = file->fcontent;

        while (is.read(str,SECLEN))
        {
            str += SECLEN;
        }

    }
    else
    {
        error = -2;
        goto END;
    }

    filenames.push_front(file);

END:
    return error;
}
