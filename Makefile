buildP = build
includeP = include
srcP = src

executable = $(buildP)/final

source = $(shell find ./$(srcP) -path ./src/steps/utils/dontcompile -prune -o -name '*.c' -print)

#objects = $(addprefix $(buildP), $(basename $(addprefix  $(dir $(source)), $(addsuffix .o , $(basename $(notdir $(source)))))))
objects = $(subst $(srcP),$(buildP),$(addsuffix .o ,$(basename $(source))))


flagsF = -Wall -I./$(includeP)

flagsI = -Wall -I./$(includeP) -g -ggdb

CC = gcc

%.o :
	$(CC) $(flagsI) $(subst $(buildP),$(srcP),$(addsuffix .c ,$(basename $@))) -c -o $@ 

$(executable):	$(objects) 
	$(CC) $(flagsF) $^ -o $@

clean:
	rm $(shell find ./$(buildP) -name '*.o') ./$(buildP)/final

all: $(executable)
	@echo buildado

create:
	$(shell mkdir -p $(dir $(objects)))
	$(shell mkdir -p $(dir $(subst $(srcP),$(includeP), $(source))))

