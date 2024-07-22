CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lm

SRCS = main.c io_handler.c dct.c math_utils.c complex.c dft.c signal_analyzer.c signal_filter.c fft.c signal_processing.c
OBJS = $(SRCS:.c=.o)
TARGET = main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)