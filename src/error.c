#include "error.h"

#include <stdlib.h>
#include <string.h>

error*
create_error (const int type, const char* message)
{
        error* err = malloc(sizeof(error));
        err->type = type;
        strcpy(err->message,message);
        return err;
}
