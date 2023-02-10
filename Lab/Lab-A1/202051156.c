#include <stdio.h>

/*
 * sbox function
 * input - plain text (16 bit int)
 * output - cipher text (16 bit int)
 */

__uint16_t sbox_function(__uint16_t text);

__uint8_t s_box[16] = {0x0E,0x04,0x0D,0x01,
                        0x02,0x0F,0x0B,0x08,
                        0x03,0x0A,0x06,0x0C,
                        0x05,0x09,0x00,0x07};

__uint16_t sbox_function(__uint16_t text){
    __uint8_t s[4];
    s[0] = text >> 12;
    s[1] = (text & 0x0F00) >> 8;
    s[2] = (text & 0x00F0) >> 4;
    s[3] = text & 0x000F;
    for(int i=0;i<4;i++){
        s[i] = s_box[s[i]];
    }
    return (s[0] << 12) | (s[1] << 8) | (s[2] << 4) | (s[3] << 0);
}

int main(){
    __uint32_t secret_key = 0x22485211;
    __uint16_t text = 0x2211;
    printf("C : %x\n", sbox_function(text));

    return 0;
}