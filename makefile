.PHONY: all clean

CC := gcc
LD := gcc

LIB := exc

SRCDIR := src
OBJDIR := obj
DEPDIR := dep
LIBDIR := lib
INCDIR := inc

CCFLAGS := -ansi -pedantic-errors -Wall -c -g
LDFLAGS := -g
LDLIBS := -L./$(LIBDIR)
INCLUDE := -I./$(INCDIR)

SRCS := $(foreach SRC, $(SRCDIR), $(wildcard $(SRCDIR)/*.c))
OBJS := $(subst $(SRCDIR), $(OBJDIR), $(SRCS:.c=.o))
DEPS := $(subst $(OBJDIR), $(DEPDIR), $(OBJS:.o=.d))

all: $(LIB)
-include $(DEPS)

clean:

	$(RM) -r -f $(DEPDIR)
	$(RM) -r -f $(OBJDIR)
	$(RM) -f $(LIBDIR)/$(addprefix lib, $(addsuffix .a, $(LIB)))
	
$(LIB): $(OBJS)

	mkdir -p $(LIBDIR)
	ar rc $(LIBDIR)/$(addprefix lib, $(addsuffix .a, $@)) $^
	ranlib $(LIBDIR)/$(addprefix lib, $(addsuffix .a, $@))

$(DEPDIR)/%.d: $(SRCDIR)/%.c

	mkdir -p $(@D)
	$(CC) $(INCLUDE) -MM -MT "$@ $(patsubst %.d, %.o, $@)" -MF $@ $<

$(OBJDIR)/%.o: $(SRCDIR)/%.c

	mkdir -p $(@D)
	$(CC) $(CCFLAGS) $(INCLUDE) $< -o $@
