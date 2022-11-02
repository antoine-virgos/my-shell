# compiler
CFLAGS=--std=c99 -Wall -I${INCLUDEDIR}

# directories
INCLUDEDIR=include
SRCDIR=src
OBJDIR=obj
BINDIR=bin

# create bin directory
$(shell mkdir -p $(BINDIR))

# executable
EXEC=my-shell

# objects files
OBJECTS=$(OBJDIR)/shell.o $(OBJDIR)/string-vector.o $(OBJDIR)/string-utils.o $(OBJDIR)/shell-utils.o $(OBJDIR)/action.o

# convenience variable for obj directory creation
DIR_GUARD=@mkdir -p $(@D)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BINDIR)/$(EXEC)

shell.o: $(INCLUDEDIR)/shell.h
string_vector.o: $(INCLUDEDIR)/string-vector.h
string_utils.o: $(INCLUDEDIR)/string-utils.h
shell_utils.o: $(INCLUDEDIR)/shell-utils.h
action.o: $(INCLUDEDIR)/action.h

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(DIR_GUARD)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJECTS) $(BINDIR)/$(EXEC) *~