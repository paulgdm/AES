CC=gcc

LDFLAGS=
EXEC=AES

SRC = ${wildcard *.c}
OBJ=${SRC:.c=.o}

all: $(EXEC)

AES: ${OBJ}
	$(CC) -o $@ $^ $(LDFLAGS)

AES.o: KeyExpander.h SubBytes.h AddRoundKey.h ShiftRow.h MixColumn.h

%.o: %.c
	$(CC) -o $@ -c $< 

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)