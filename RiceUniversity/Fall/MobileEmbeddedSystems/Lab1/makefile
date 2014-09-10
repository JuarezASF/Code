CC = gcc

ORDER = DSC

all: sort

sort: sort.o read_data.a
	$(CC) -g -o $@ sort.o read_data.a

sort.o: sort.c sort.h read_data.h
	$(CC) -D$(ORDER) -g -c sort.c

clean:
	rm -rf *.o sort

