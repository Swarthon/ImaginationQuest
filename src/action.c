#include "action.h"

#include <string.h>

const struct action defined_actions [] = {
        {"go",     0b0001},
        {"attack", 0b0010},
        {"eat",    0b1100},
};
const size_t defined_actions_number = 3;

const char* word_categories [][MAX_WORDS_PER_CATEGORIE] = {
        {"north", "east",   "south",  "west"},
        {"troll", "orc",    "gnome"},
        {"apple", "cherry", "orange"},
        {"bread", "cake",   "cookie"},
};
const size_t word_categories_number = 4;
        
extern const int
action_find (const char* obj)
{
        for(int i = 0; i < defined_actions_number; i++)
                if(strcmp(defined_actions[i].name, obj) == 0)
                        return i;
        return -1;
}

extern const int
word_find (const char* obj)
{
        for(int i = 0; i < word_categories_number; i++)
                for(int j = 0; j < MAX_WORDS_PER_CATEGORIE; j++)
                        if(strcmp(word_categories[j][i], obj) == 0)
                                return i;
        return -1;
}
