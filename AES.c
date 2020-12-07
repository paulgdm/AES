#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdint.h>

typedef uint8_t byte;

extern void AddRoundKey(byte *state,byte *key);
extern void SubBytes(byte *state);
extern void ShiftRow(byte *state);
extern void MixColumn(byte *state);
extern void ComputeKey(byte *key,int round);



byte cipher_key[16] = {0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};


void afficher(byte *tab);

int main(int argc,char* argv[]){
	byte state[16];
	for (int i=0;i<16;i++){
		state[i]=strtol(argv[i+1],NULL,16);
	}
	int i=0;
	AddRoundKey(state,cipher_key);
	for (i=0;i<9;i++){
		SubBytes(state);
		ShiftRow(state);
		MixColumn(state);
		ComputeKey(cipher_key,i);
		AddRoundKey(state,cipher_key);
	}
	SubBytes(state);
	ShiftRow(state);
	ComputeKey(cipher_key,i);
	AddRoundKey(state,cipher_key);
	afficher(state);
	return 0;
}



void afficher(byte *tab){
	for (int i=0;i<16;i++){
		printf("%.2x ",tab[i]);
	}
	printf("\n");
}