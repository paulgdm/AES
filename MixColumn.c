#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MixColumn.h"

void MixColumn(byte *state){
	byte a,b,c,d,e;
	for(int i = 0; i < 16; i+=4){
  		a = state[i];
  		b = state[i+1];
  		c = state[i+2];
  		d = state[i+3];
  		e = a ^ b ^ c ^ d; // a + b + c + d in GF(2^8)
    	// 2 * a + 3 * b + c + d in GF(2^8)
  		state[i]   ^= e ^ xtime(a^b); // a += a + b + c + d + 2 * (a + b) in GF(2^8)
    	// a + 2 * b + 3 * c + d in GF(2^8)
  		state[i+1] ^= e ^ xtime(b^c); // b += a + b + c + d + 2 * (b + c) in GF(2^8)
    	// a + b + 2 * c + 3 * d in GF(2^8)
  		state[i+2] ^= e ^ xtime(c^d); // c += a + b + c + d + 2 * (c + d) in GF(2^8)
    	// 3 * a + b + c + 2 * d in GF(2^8)
  		state[i+3] ^= e ^ xtime(d^a); // d += a + b + c + d + 2 * (d + a) in GF(2^8)
  	}

}


byte xtime(byte x){
	return (x & 0x80) ? ((x << 1) ^ 0x1b) : (x<<1);
}