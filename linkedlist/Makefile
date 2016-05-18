CC = gcc
CFLAGS += -Wall -O2
LDFLAGS +- = $(PWD)

ALL_FILES = main
MAIN_OBJ = main.o
CAR_LIB = libcar.so
LIB_CAR_OBJ = cars.o

ALL = $(CAR_LIB) $(ALL_FILES)

all: $(ALL)
	@true

$(CAR_LIB): $(LIB_CAR_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -shared -o $@ $^

main: $(MAIN_OBJ) $(LIB_CAR_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -s -o $@ $^

%.o: %.c
	$(CC) $< $(CFLAGS) $(LDFLAGS) -c -o $@

$(LIB_CAR_OBJ): CFLAGS += -fPIC
	
clean:
	rm -rf *.o *.out $(ALL_FILES) $(CAR_LIB)

.PHONY: all clean
