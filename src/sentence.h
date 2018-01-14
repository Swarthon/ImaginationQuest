#ifndef _SENTENCE_H_
#define _SENTENCE_H_

#include "types.h"
#include "values.h"

#define TARGET_ID_MAX 10

extern struct sentence
{
        char action_string[WORD_LENGTH];
        char target_string[TARGET_ID_MAX][WORD_LENGTH];

        ID action_id;
        struct vector2 target_id[TARGET_ID_MAX];
} _sentence;

extern struct error*
is_sentence_correct (const struct sentence* s);

extern struct sentence*
parse (const char* sentence);

#endif /* _SENTENCE_H_ */
