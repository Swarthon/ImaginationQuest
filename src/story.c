#include "story.h"

#include <stdio.h>
#include <stdlib.h>

#include "interface.h"
#include "parser.h"

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
        struct action* a = parse(answer);
        printf("Unknown word %s\n", is_action_correct(a));
}

/* Start Adventure */
void start_adventure (struct character* c)
{
        begin_forest_func (c);
}
