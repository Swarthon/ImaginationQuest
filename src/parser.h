#ifndef _PARSER_H_
#define _PARSER_H_

#include "types.h"
#include "values.h"

#define TARGET_ID_MAX 10

extern struct action
{
        char action_string[WORD_LENGTH];
        char target_string[TARGET_ID_MAX][WORD_LENGTH];
        
        ID action_id;
        ID target_id[TARGET_ID_MAX];
} _group;

extern const char*
is_action_correct (const struct action* a);

extern struct action*
parse (const char* sentence);

#endif // _PARSER_H_
