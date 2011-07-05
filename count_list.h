#ifndef _COUNT_LIST_H_
#define _COUNT_LIST_H_
typedef struct {
    char * word;
    int count;
} wcount;

#define CL_INITI

typedef struct {
    int size;
    int capacity;
    wcount list;
} count_list;

void cl_init(count_list *list);
void cl_add_word(count_list *list, char *word);
void cl_add(count_list *list, wcount count);
void cl_free(count_list *list);
void cl_sort(count_list *list);
int wcount_cmp(struct wcount *a, struct wcount *b);

#endif
