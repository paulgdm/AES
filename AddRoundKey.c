#include "AddRoundKey.h"


void AddRoundKey(byte *state,byte *key){
	for (int i=0;i<16;i++){
		state[i]=state[i] ^ key[i];
	}
}