CC=gcc
CFLAGS=-Wall -ggdb -std=c99
LDLIBS=
LDFLAGS=

SOURCES=main.c count_list.c histogram.c

OBJECTS=$(SOURCES:.c=.o)

TARGET=hist


.PHONY : clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(LDFLAGS) $(LDLIBS) $(OBJECTS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

run: all
	./$(TARGET) < count_list.c
clean:
	rm $(OBJECTS) $(TARGET)

