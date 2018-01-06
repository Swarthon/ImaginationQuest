#include "character.h"

#include "interface.h"

#include <stdlib.h>
#include <stdio.h>

void
select_name (const char* question, char* name)
{
        if (question == NULL)
                return;
        
        ask_question(question);
        get_answer (name);

        char buffer [100];
        snprintf(buffer, 100, "Hello %s ! Are you okay with your name ?", name);
        if (!confirm (buffer))
                select_name (question, name);
}

void
set_up_character (struct character* c)
{
        select_name ("Please, choose your name.", c->name);
}
