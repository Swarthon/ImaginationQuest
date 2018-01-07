#ifndef _FUNCS_H_
#define _FUNCS_H_

#include <stdlib.h>

extern void
newline ();

extern void
to_lowercase (char* c);

extern void
readline (char* line);

extern int
find (const char** array, const size_t array_size, const char* obj);

#endif /* _FUNCS_H_ */
