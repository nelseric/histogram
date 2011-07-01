#ifndef _FREQ_LIST_H_
#define _FREQ_LIST_H_
#include "word_list.h"

typedef struct {
    int size;
    int *frq;
    char **wordlist;
} freq_list;

freq_list* list_frq(word_list *list);
word_list* list_uniq(word_list *list);


#endif
