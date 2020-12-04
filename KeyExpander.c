
#include "KeyExpander.h"

void ComputeKey(byte *key,int round){

	byte buf0, buf1, buf2, buf3;
	buf0 = S_BOX[ key[13] ];
	buf1 = S_BOX[ key[14] ];
	buf2 = S_BOX[ key[15] ];
	buf3 = S_BOX[ key[12] ];

	key[0] ^= buf0 ^ R_CON[round];
	key[1] ^= buf1;
	key[2] ^= buf2;
	key[3] ^= buf3;

	key[4] ^= key[0];
	key[5] ^= key[1];
	key[6] ^= key[2];
	key[7] ^= key[3];

	key[8]  ^= key[4];
	key[9]  ^= key[5];
	key[10] ^= key[6];
	key[11] ^= key[7];

	key[12] ^= key[8];
	key[13] ^= key[9];
	key[14] ^= key[10];
	key[15] ^= key[11];
}
