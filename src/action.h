#ifndef _ACTION_H_
#define _ACTION_H_

#include <stdlib.h>

#include "types.h"

#define MAX_WORDS_PER_CATEGORIE 100

/**
 * In order to determine the accepted_categories, use the word_categories
 * array. It is an int representing the categories to use. Using a binary
 * representation, you can include and exclude the categorie.
 * 1 is include and 0 is exclude.
 *
 * Exemples :
 *  - "go" uses only direction words, which are stocked in the second line of
 *         the array. Thus the accepted_categories will be an int, with a
 *         binary representation in which the second column (from the right)
 *         will be a one. 0b1
 *  - "eat" uses fruit words and cooked words, which are stocked in the third
 *         and the fourth line of the array. As we have two categories, we will
 *         fill two columns of the int in the binary representation. 0b1100
 */

extern struct action {
        char* name;
        unsigned int accepted_categories;
} _action;
typedef struct action action;


extern const size_t
action_find (const char* obj);

extern const vec2
word_find (const char* obj);


/*---------------------------- Extern variable ------------------------------*/
extern const action defined_actions [];
extern const size_t defined_actions_number;

extern const char* word_categories [][MAX_WORDS_PER_CATEGORIE];
extern const size_t word_categories_number;
/*---------------------------------------------------------------------------*/


#endif /* _ACTION_H_ */
