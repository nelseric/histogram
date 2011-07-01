#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include "histogram.h"
#include "word_list.h"


int main(int argc, char **argv){
    printf("Hello World\n");
    char* line = readline("str: ");
    int* a = {1, 2, 3};
    print_histogram(&line,
            &a);

    return EXIT_SUCCESS;
}
