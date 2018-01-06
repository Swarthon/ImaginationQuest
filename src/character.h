#ifndef _CHARACTER_H_
#define _CHARACTER_H_

extern struct character
{
        char name[32];
} _character;

extern void
select_name (const char* question, char* name);

extern void
set_up_character (struct character* c);

#endif /* _CHARACTER_H_ */
