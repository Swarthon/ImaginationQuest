#include "sentence.h"

#include <stdio.h>
#include <string.h>

#include "funcs.h"
#include "action.h"

const char*
is_sentence_correct (const struct sentence* a)
{
        if (a->action_id == -1) return a->action_string;
        for (int i = 0; i < TARGET_ID_MAX; i++)
                if (a->target_id[i] == -1) return a->target_string[i];
        return NULL;
}

struct sentence*
parse (const char* sentence)
{
        struct sentence* sentence_parsed = malloc(sizeof(struct sentence));
        
        char buffer[strlen (sentence)];
        strcpy (buffer, sentence);

        strtok (buffer, " ");
        strcpy(sentence_parsed->action_string, buffer);
        sentence_parsed->action_id = action_find (buffer);

        char* token;
        for (int i = 0; (token = strtok (NULL, " ")) && i < TARGET_ID_MAX; i++)
                {
                        strcpy(sentence_parsed->target_string[i], token);
                        sentence_parsed->target_id[i]
                                = word_find (token);
                }
        return sentence_parsed;
}
