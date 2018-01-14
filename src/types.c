#include "types.h"

#include <string.h>

struct vector2*
create_vector2 (const int x, const int y)
{
        struct vector2* vec = malloc(sizeof(struct vector2));
        vec->x = x;
        vec->y = y;
        return vec;
}

struct error*
create_error (const int type, const char* message)
{
        struct error* err = malloc(sizeof(struct error));
        err->type = type;
        strcpy(err->message,message);
        return err;
}
