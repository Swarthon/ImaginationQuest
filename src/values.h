#ifndef _VALUES_H_
#define _VALUES_H_

#include <stdlib.h>

#include "action.h"

/* Error defines */
#define ERR_UNKNOWN_WORD 1
#define ERR_NON_ACCEPTED_WORD 2

/* Other defines */
#define WORD_LENGTH 20

extern const char* welcome_message;
extern const char* question_suffix;

extern const char* affirmative_answers[];
extern const size_t affirmative_number;


#endif /* _VALUES_H_ */
