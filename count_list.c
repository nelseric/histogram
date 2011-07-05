#include "count_list.h"
#include <stdlib.h>
#include <string.h>

void cl_init(count_list *list){
    list->size = 0;
    list->capacity = CL_INITIAL_CAP;
    list->list = malloc(sizeof(wcount) * capacity);
}

void cl_add_word(count_list *list, char *word){
  
    bool found = false;
    for(int i = 0; i < list->size; i++){
      wcount *c = list->list[i];
      if(strcmp(c->word, word) == 0){
        found = true;
        c->count++;
      }
    }
    if(!exists){
      if(size < capacity){
        list->list[size] =  malloc(sizeof(char) * strlen(word));
        strcpy(list->list[size], word);
        size++;
      } else {
        
      }
    } 

}

#ifdef NOT_DONE
void cl_add(word_list *list, char *word) {
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
#endif


void cl_free(word_list *list) {

}


#ifdef SORTING
int wcount_cmp(struct wcount *a, struct wcount *b){
  const wcount **ia = (const char **) a;
  const wcount **ib = (const char **) b;
  return strcmp(*ia, *ib);
}

void list_sort(count_list *list) {
    qsort(list->wordlist, list->size, sizeof(wcount), wcount_cmp);
}
#else
void list_sort(count_list *list) {
    //qsort(list->wordlist, list->size, sizeof(wcount), wcount_cmp);
}
#endif

