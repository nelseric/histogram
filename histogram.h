#ifndef _HISTOGRAM_H_
#define _HISTOGRAM_H_
#include "count_list.h"

/***
 * Prints out a count_list in a histogram type view
 * columns represents how many columns wide the horizontal histogram is.
 */
void print_histogram(count_list *data, int columns);

#endif
