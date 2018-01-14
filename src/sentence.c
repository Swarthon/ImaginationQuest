#include "sentence.h"

#include <stdio.h>
#include <string.h>

#include "funcs.h"
#include "action.h"

struct error*
is_sentence_correct (const struct sentence* s)
{
        if (s->action_id == -1)
                return create_error(ERR_UNKNOWN_WORD, s->action_string);
        struct action a = defined_actions[s->action_id];
        for (int i = 0; i < TARGET_ID_MAX; i++)
                {
                        if (s->target_id[i].x == -1)
                                return create_error(ERR_UNKNOWN_WORD,
                                                    s->target_string[i]);
                        struct vector2 vec = s->target_id[i];
                        unsigned int categorie = 1 << vec.x;
                        if (!(categorie & a.accepted_categories))
                                return create_error(ERR_NON_ACCEPTED_WORD,
                                                    s->target_string[i]);
                }
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
