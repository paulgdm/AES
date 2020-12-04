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



byte cipher_key[16] = {0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,0x12,0x34,0x56,0x78,0x9a,0xbc,0xde,0xf0};


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
		afficher(state);
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