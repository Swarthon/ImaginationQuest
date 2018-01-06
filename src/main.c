#include <config.h>
#include <stdio.h>
#include <stdlib.h>

#include "character.h"
#include "values.h"
#include "interface.h"
#include "story.h"
#include "funcs.h"

int
main (void)
{
        printf("%s\n", welcome_message);

        hero = malloc(sizeof(struct character));
        set_up_character (hero);
        start_adventure ();
        
        return 0;
}
