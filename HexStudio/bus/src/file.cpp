#include "file.h"

File::File()
{
}

File::~File()
{
    delete fname;
    delete fcontent;
}

