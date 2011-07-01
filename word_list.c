#include "word_list.h"
#include <stdlib.h>
#include <string.h>

void list_add(word_list *list, char *word) {
	if (list->size < list->capacity) {
		*(list->wordlist + list->size) =
                    malloc(sizeof(char) * strlen(word));
		strcpy(*(list->wordlist + list->size), (char*) word);
		list->size++;
	} else {
		list->capacity = (list->capacity * 3) / 2 + 10;
		list->wordlist
				= realloc(list->wordlist, sizeof(char*) * list->capacity);

		*(list->wordlist + list->size) = (char*) word;
		list->size++;
	}
}

void list_init(word_list *list) {
	list->size = 0;
	list->capacity = 10;
	list->wordlist = malloc(sizeof(char*) * list->capacity);
}
void list_free(word_list *list) {
	int ptr;
	for (ptr = list->size - 1; ptr >= 0; --ptr) {
		free(list->wordlist[ptr]);
	}
	free(list->wordlist);
	list->size = 0;
	list->capacity = 0;
}

int cstring_cmp_asc(const void *a, const void *b) {
	const char **ia = (const char **) a;
	const char **ib = (const char **) b;
	return strcmp(*ia, *ib);
}

void list_sort(word_list *list) {
    qsort(list->wordlist, list->size, sizeof(char *), cstring_cmp_asc);
}

