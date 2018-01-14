#ifndef _ERROR_H_
#define _ERROR_H_

#define LINE_LENGTH 100

/* Error codes */
#define ERR_UNKNOWN_WORD 1
#define ERR_NON_ACCEPTED_WORD 2

struct error
{
        int type;
        char message[LINE_LENGTH];
};
typedef struct error error;

extern error*
create_error (const int type, const char* message);

#endif /* _ERROR_H_ */
