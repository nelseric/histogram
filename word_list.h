#ifndef _WORDLIST_H_
#define _WORDLIST_H_
typedef struct {
	int size;
	int capacity;
	char **wordlist;
} word_list;

void list_init(word_list *list);
void list_add(word_list *list, char *word);
void list_free(word_list *list);
void list_sort(word_list *list);

#endif
