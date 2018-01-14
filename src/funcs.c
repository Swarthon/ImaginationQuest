#include "funcs.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void
newline ()
{
        putchar('\n');
}

void
to_lowercase (char* c)
{
        for ( ; *c; ++c) *c = tolower(*c);
}

void
readline (char* line)
{
        int c = 0, i = 0;
        for(i = 0; ((c = getchar()) != '\n'); i++)
                line[i] = c;
        line[i] = '\0';
}

int
find (const char** array, const size_t array_size, const char* obj)
{
        for(int i = 0; i < array_size; i++)
                if(strcmp(array[i], obj) == 0)
                        return i;
        return -1;
}
