#include <stdio.h>
#include <stdlib.h>
#include "word_list.h"
#include "freq_list.h"

int main(int argc, char **argv){
    word_list p;
    list_init(&p);
    list_add(&p, "Apple");
    list_add(&p, "Apple");
    list_add(&p, "Apple");
    list_add(&p, "Zebra");
    list_add(&p, "Apple");
    list_add(&p, "Apple");
    list_add(&p, "Orange");
    list_add(&p, "Orange");
    list_add(&p, "Orange");
    list_add(&p, "Banana");
    list_add(&p, "Banana");
    list_add(&p, "bus");
    for(int i = 0; i < p.size; i++){
        printf("%s\n",p.wordlist[i]);
    }
    list_sort(&p);
    for(int i = 0; i < p.size; i++){
        printf("%s\n",p.wordlist[i]);
    }
    //list_free(&p);
    
    return EXIT_SUCCESS;
}

