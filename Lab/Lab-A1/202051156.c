#include <stdio.h>

/*
 * sbox function
 * input - plain text (16 bit int)
 * output - cipher text (16 bit int)
 */
__uint16_t sbox_function(__uint16_t text);

/*
 * round key generator function
 * input - 32 bit seceret key
 * output - 16 bit round key
 */
__uint16_t roundKeyGenerator(uint32_t secert_key);

/* 
 * s_box array
 * s[i] is a mapping from i -> s[i]
 */
__uint8_t s_box[16] = {0x0E,0x04,0x0D,0x01,
                        0x02,0x0F,0x0B,0x08,
                        0x03,0x0A,0x06,0x0C,
                        0x05,0x09,0x00,0x07};

__uint16_t sbox_function(__uint16_t text){
    /*array 0f size 4 for sbox*/
    __uint8_t s[4];

    /*s[0] - sbox 1 - first 4 bits of text 
     *s[1] - sbox 2 - second 4 bits of text
     *s[2] - sbox 3 - third 4 bits of text
     *s[3] - sbox 4 - last 4 bits of text
     */
    s[0] = text >> 12;
    s[1] = (text & 0x0F00) >> 8;
    s[2] = (text & 0x00F0) >> 4;
    s[3] = text & 0x000F;

    /*substituting value of this 4 sboxes*/
    for(int i=0;i<4;i++){
        s[i] = s_box[s[i]];
    }

    /*returning int concatinating 4 sboxes*/
    return (s[0] << 12) | (s[1] << 8) | (s[2] << 4) | (s[3] << 0);
}

__uint16_t roundKeyGenerator(uint32_t secert_key){
    
}
int main(){
    __uint32_t secret_key = 0x22485211;
    __uint16_t text = 0x2211;
    printf("C : %x\n", sbox_function(text));

    return 0;
}