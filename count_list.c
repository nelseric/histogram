#include "count_list.h"
#include <stdlib.h>
#include <string.h>

/***
 * Initializes the count_list structure.
 */
void cl_init(count_list *list) {
	list->size = 0;
	list->capacity = CL_INIT_CAP;
	list->list = (wcount *) malloc(sizeof(wcount) * list->capacity);
}

/***
 * This function will either increment a word count, or create a new record in
 * the list.
 */
void cl_add_word(count_list *list, char *word) {

	char found = 0;
	for (int i = 0; i < list->size; i++) {
		wcount *c = &list->list[i];
		if (strcmp(c->word, word) == 0) {
			found = 1;
			c->count++;
		}
	}
	if (!found) {
		wcount new;
		new.word = malloc(sizeof(char) * strlen(word));
		strcpy(new.word, word);
		new.count = 1;
		cl_add(list, new);
	}

}

/***
 * Dynamically resize and add words to the list when a record.
 */
void cl_add(count_list *list, wcount new) {

	if (list->size >= list->capacity) {

		list->capacity = (list->capacity * 3) / 2 + 10;
		list->list = realloc(list->list, sizeof(wcount) * list->capacity);

	}

	list->list[list->size] = new;
	list->size++;
}

/***
 * Don't mess with Texas.
 * Clean up the structure.
 */
void cl_free(count_list *list) {
	for (int i = 0; i < list->size; i++) {
		free(list->list[i].word);
	}
	free(list->list);
}

/***
 * Comparison functions used for qsort()
 */
int wc_cmp_asc(const void *a, const void *b) {
	const wcount *ia = (const wcount *) a;
	const wcount *ib = (const wcount *) b;
	return ia->count - ib->count;
}
int wc_cmp_desc(const void *a, const void *b) {
	const wcount *ia = (const wcount *) a;
	const wcount *ib = (const wcount *) b;
	return ib->count - ia->count;
}
/***
 * Simple wrapper to make sorting the structure easier.
 * The only reason this is here is becaus I am too used to OO.
 */
void cl_sort(count_list *list, int cmp(const void *, const void *)) {
	qsort(list->list, list->size, sizeof(wcount), cmp);
}

