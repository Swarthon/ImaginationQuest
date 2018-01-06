#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "types.h"

extern void
get_answer(char* answer);

extern BOOL
affirmative_answer(const char* answer);

extern BOOL
confirm (const char* answer);

extern void
ask_question (const char* question);

#endif /* _INTERFACE_H_ */
