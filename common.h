/* common.h */

#ifndef COMMON_H
#define COMMON_H

extern char* last_token;

typedef enum exp_return {
    INT,
    FLOAT,
    BOOL,
    CHAR,
    STRING
};

#endif /* COMMON_H */