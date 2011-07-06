#ifndef _COUNT_LIST_H_
#define _COUNT_LIST_H_
// This stores the word and the number of times it appears
typedef struct {
	char * word;
	int count;
} wcount;

#define CL_INIT_CAP 10
// A dynamically growing array wrapper, to make adding and viewing easy.
typedef struct {
	int size;
	int capacity;
	wcount *list;
} count_list;

void cl_init(count_list *list);
void cl_add_word(count_list *list, char *word);
void cl_add(count_list *list, wcount count);
void cl_free(count_list *list);
void cl_sort(count_list *list, int cmp(const void *, const void *));
int wc_cmp_asc(const void *a, const void *b);
int wc_cmp_desc(const void *a, const void *b);

#endif
