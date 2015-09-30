#include <fstream>
#include <list>
#include <vector>
#include "file.h"

#define     SECLEN 512

extern std::vector<File *> filenames;

extern void showMessage(const char *message);

int readfile(const char *filename)
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
            showMessage("Error alocation memory for file\n");
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
        showMessage("Error reading the file\n");
        error = -2;
        goto END;
    }

    filenames.push_back(file);


END:
    return error;
}
