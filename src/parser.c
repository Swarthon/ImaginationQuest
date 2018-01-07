#include "parser.h"

#include <stdio.h>
#include <string.h>

#include "funcs.h"

const char*
is_action_correct (const struct action* a)
{
        if (a->action_id == -1) return a->action_string;
        for (int i = 0; i < TARGET_ID_MAX; i++)
                if (a->target_id[i] == -1) return a->target_string[i];
        return NULL;
}

struct action*
parse (const char* sentence)
{
        struct action* action_parsed = malloc(sizeof(struct action));
        
        char buffer[strlen (sentence)];
        strcpy (buffer, sentence);

        strtok (buffer, " ");
        strcpy(action_parsed->action_string, buffer);
        action_parsed->action_id = find (actions, actions_number, buffer);

        char* token;
        for (int i = 0; (token = strtok (NULL, " ")) && i < TARGET_ID_MAX; i++)
                {
                        strcpy(action_parsed->target_string[i], token);
                        action_parsed->target_id[i]
                                = find (actions, actions_number, token);
                }
        return action_parsed;
}
