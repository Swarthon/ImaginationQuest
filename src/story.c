#include "story.h"

#include <stdio.h>
#include <stdlib.h>

#include "sentence.h"
#include "error.h"

character* hero = NULL;

/* Begin Forest */
void begin_forest_func ()
{
        puts ("You are in a forest, on east, there is a mountain, "
              "on south, the see, on north a road, "
              "on west, the forest continues");
        get_sentence ("What do you want to do ?");
}

/* Start Adventure */
void start_adventure ()
{
        begin_forest_func ();
}
