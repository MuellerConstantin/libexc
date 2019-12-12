.PHONY: all clean

CC := gcc
LD := gcc

BIN := example

LIBDIR := lib
INCDIR := inc

CFLAGS := -ansi -pedantic-errors -c -g -Wall
LDFLAGS := -g
LDLIBS := -L../$(LIBDIR) -lexc
INCLUDE := -I../$(INCDIR)

OBJS := $(patsubst %.c, %.o, $(wildcard *.c))
DEPS := $(OBJS:.o=.d)

all: $(BIN)
-include $(DEPS)

clean:

	$(RM) -f $(DEPS)
	$(RM) -f $(OBJS)
	$(RM) -f $(BIN)

$(BIN): $(OBJS)

	$(LD) $(LDFLAGS) $^ -o $@ $(LDLIBS)

%.d: %.c

	$(CC) $(INCLUDE) -MM -MT "$@ $(patsubst %.d, %.o, $@)" -MF $@ $<

%.o: %.c %.d

	$(CC) $(CFLAGS) $(INCLUDE) $< -o $@
