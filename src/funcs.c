#include "funcs.h"

#include "stdio.h"
#include "ctype.h"

void
newline()
{
        putchar('\n');
}

void
to_lowercase(char* c)
{
        for ( ; *c; ++c) *c = tolower(*c);
}
