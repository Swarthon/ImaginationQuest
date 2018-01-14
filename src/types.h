#ifndef _TYPES_H_
#define _TYPES_H_

#include <stdlib.h>

#include "values.h"

typedef int BOOL;
#define TRUE  1
#define FALSE 0

struct vector2 {
        int x;
        int y;
};
extern struct vector2*
create_vector2 (const int x, const int y);

struct array {
        size_t size;
        void* data;
};

#define LINE_LENGTH 100
struct error {
        int type;
        char message[LINE_LENGTH];
};
extern struct error*
create_error (const int type, const char* message);

typedef unsigned int ID;

#endif // _TYPES_H_
