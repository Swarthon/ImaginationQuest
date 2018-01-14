#ifndef _SENTENCE_H_
#define _SENTENCE_H_

#include "types.h"
#include "error.h"

#define WORD_LENGTH 32
#define TARGET_ID_MAX 10

extern struct sentence
{
        char action_string[WORD_LENGTH];
        char target_string[TARGET_ID_MAX][WORD_LENGTH];

        ID action_id;
        vec2 target_id[TARGET_ID_MAX];
} _sentence;
typedef struct sentence sentence;


extern error*
is_sentence_correct (const sentence* s);

extern sentence*
parse (const char* sentence);

extern sentence*
get_sentence (char* question);


#endif /* _SENTENCE_H_ */
