#include "story.h"

#include <stdio.h>
#include <stdlib.h>

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
}

/* Start Adventure */
void start_adventure (struct character* c)
{
        begin_forest_func (c);
}
