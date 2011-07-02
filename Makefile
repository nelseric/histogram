CC=gcc
CFLAGS=-Wall -ggdb -std=c99
LDLIBS=-lreadline 
LDFLAGS=

SOURCES=main.c word_list.c freq_list.c histogram.c

OBJECTS=$(SOURCES:.c=.o)

TARGET=wordhist


.PHONY : clean run test

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(LDFLAGS) $(LDLIBS) $(OBJECTS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

run: all
	./$(TARGET)

test_freq_list: test_freq_list.c word_list.o freq_list.o
	$(CC) -o test_freq_list $(CFLAGS) $(LDLIBS) test_freq_list.c word_list.o freq_list.o

test: test_freq_list
	./test_freq_list

clean:
	rm $(OBJECTS) $(TARGET)

