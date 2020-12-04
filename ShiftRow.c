#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ShiftRow.h"

void ShiftRow(byte *state){
	byte temp[16];
	for (int i=0;i<16;i++){
		temp[i]=state[i];
	}
	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++){
			state[4*j+i]=temp[(5*i + 4*j)%16];
		}
	}
}
