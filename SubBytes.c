#include "SubBytes.h"

void SubBytes(byte *state){
	for (int i=0;i<16;i++){
		state[i]=S_BOX[state[i]];
	}
}