#include "interface.h"

#include <string.h>
#include <stdio.h>
 
#include "funcs.h"
#include "values.h"

void
get_answer(char* answer)
{
        scanf ("%s", answer);
}

BOOL
affirmative_answer(const char* answer)
{
        for (int i = 0; i < affirmative_numbers; i++)
                {
                        char* c = malloc (strlen(answer) *
                                          sizeof (char));
                        strcpy (c, answer);
                        to_lowercase (c);
                        if (strcmp(c, affirmative_answers[i]) == 0)
                                return TRUE;
                }
        return FALSE;
}

BOOL
confirm (const char* question)
{
        ask_question(question);
        char answer [32];
        get_answer (answer);
        if (affirmative_answer (answer))
                return TRUE;
        return FALSE;
}

void
ask_question(const char* question)
{
        printf ("%s\n%s", question, question_suffix);
}
