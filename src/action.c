#include "action.h"
#include "values.h"

#include <string.h>

extern const size_t
action_find (const char* obj)
{
        for (size_t i = 0; i < defined_actions_number; i++)
                if (strcmp (defined_actions[i].name, obj) == 0)
                        return i;
        return -1;
}

extern const vec2
word_find (const char* obj)
{
        for (size_t i = 0; i < word_categories_number; i++)
                for (size_t j = 0;
                     j < MAX_WORDS_PER_CATEGORIE && word_categories[i][j];
                     j++)
                        if (strcmp (word_categories[i][j], obj) == 0)
                                return *create_vec2(i,j);
        return *create_vec2(-1,-1);
}


/*---------------------------- Extern variable ------------------------------*/
const action defined_actions [] = {
        {"go",     0b0001},
        {"attack", 0b0010},
        {"eat",    0b1100},
};
const size_t defined_actions_number = 3;

const char* word_categories [][MAX_WORDS_PER_CATEGORIE] = {
        {"north", "east",   "south",  "west", NULL},
        {"troll", "orc",    "gnome",  NULL},
        {"apple", "cherry", "orange", NULL},
        {"bread", "cake",   "cookie", NULL},
};
const size_t word_categories_number = 4;
/*---------------------------------------------------------------------------*/
