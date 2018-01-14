#ifndef _TYPES_H_
#define _TYPES_H_

#include <stdlib.h>

typedef unsigned int ID;


typedef int BOOL;
#define TRUE  1
#define FALSE 0


struct vec2
{
        int x;
        int y;
} _vector2;
typedef struct vec2 vec2;

extern vec2*
create_vec2 (const int x, const int y);

#endif // _TYPES_H_
