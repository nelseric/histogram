#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "histogram.h"
#include "count_list.h"

#define DEFAULT_WIDTH 80
#define WORD_BUFFER_SIZE 100

int main(int argc, char **argv) {

	count_list l;
	cl_init(&l);

	char *wordbuf = calloc(WORD_BUFFER_SIZE, sizeof(char));
	char c;
	char mode = 0;
	do {
		c = getchar();

		if (mode == 0) {
			if (c == '/') {
				if (getchar() == '*') {
					mode = 1;
					continue;
				}
			}
			if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
				wordbuf[strlen(wordbuf)] = c;
			} else if (strlen(wordbuf) != 0) {
				cl_add_word(&l, wordbuf);
				free(wordbuf);
				wordbuf = calloc(WORD_BUFFER_SIZE, sizeof(char));
			}
		} else {
			if (c == '*' && getchar() == '/') {
				mode = 0;
			}
		}
	} while (c != EOF);
	printf("%s", wordbuf);

        cl_sort(&l, wc_cmp_desc);

	print_histogram(&l, DEFAULT_WIDTH);

	cl_free(&l);

	return EXIT_SUCCESS;
}
