#include "sentence.h"

#include <stdio.h>
#include <string.h>

#include "funcs.h"
#include "action.h"
#include "interface.h"

error*
is_sentence_correct (const sentence* s)
{
        if (s->action_id == -1)
                return create_error(ERR_UNKNOWN_WORD, s->action_string);
        action a = defined_actions[s->action_id];
        for (int i = 0; i < TARGET_ID_MAX; i++)
                {
                        if (s->target_id[i].x == -1)
                                return create_error(ERR_UNKNOWN_WORD,
                                                    s->target_string[i]);
                        vec2 vec = s->target_id[i];
                        unsigned int categorie = 1 << vec.x;
                        if (!(categorie & a.accepted_categories))
                                return create_error(ERR_NON_ACCEPTED_WORD,
                                                    s->target_string[i]);
                }
        return NULL;
}

sentence*
parse (const char* sen)
{
        sentence* sentence_parsed = malloc(sizeof(sentence));

        char buffer[strlen (sen)];
        strcpy (buffer, sen);

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

sentence*
get_sentence (char* question)
{
        if (question)
                ask_question(question);
        char answer[32];
        get_answer(answer);
        sentence* s = parse(answer);
        error* err  = is_sentence_correct(s);
        if(err) {
                switch (err->type) {
                case 1:
                        printf("Unknown word %s\n", err->message);
                        break;
                case 2:
                        printf("Word %s cannot be used with this verb\n",
                               err->message);
                        break;
                }
                return get_sentence (question);
        }
        return s;
}
