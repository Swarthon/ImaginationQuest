#include "story.h"

#include <stdio.h>
#include <stdlib.h>

#include "interface.h"
#include "sentence.h"

struct character* hero = NULL;

/* Begin Forest */
void begin_forest_func (struct character* c)
{
        puts("You are in a forest, on east, there is a mountain, "
             "on south, the see, on north a road, "
             "on west, the forest continues");
        ask_question("What do you want to do ?");
        char answer[32];
        get_answer(answer);
        struct sentence* a = parse(answer);
        struct error* err;
        if(err = is_sentence_correct(a)) {
                switch (err->type) {
                case 1:
                        printf("Unknown word %s\n", err->message);
                case 2:
                        printf("Word %s cannot be used with this verb\n",
                               err->message);
                }
        }
}

/* Start Adventure */
void start_adventure (struct character* c)
{
        begin_forest_func (c);
}
