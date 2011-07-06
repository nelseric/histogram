#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "histogram.h"
#include "count_list.h"

char *nchar(int n, char c) {
	char *stars = calloc(n + 1, sizeof(char));
	for (int i = 0; i < n; i++) {
		stars[i] = c;
	}
	return stars;
}

#define FORMATTING_OFFSET 7

void print_histogram(count_list *data, int columns) {
	int max_count = 0;
	int max_len = 0;
	for (int a = 0; a < data->size; a++) {
		if (data->list[a].count > max_count) {
			max_count = data->list[a].count;
		}
		if (strlen(data->list[a].word) > max_len) {
			max_len = strlen(data->list[a].word);
		}
	}

	for (int i = 0; i < data->size; i++) {
		char *stars = nchar((data->list[i].count * (columns - (max_len
				+ FORMATTING_OFFSET))) / max_count, '*');
		printf("%*s :%-4d %s\n", max_len, data->list[i].word,
				data->list[i].count, stars);
	}
}
