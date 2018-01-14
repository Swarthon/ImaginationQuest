#include "types.h"

#include <string.h>

struct vec2*
create_vec2 (const int x, const int y)
{
        vec2* vec = malloc(sizeof(vec2));
        vec->x = x;
        vec->y = y;
        return vec;
}

