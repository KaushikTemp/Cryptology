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
 * input2 - round no
 * output - 16 bit round key
 */
__uint16_t roundKeyGenerator(__uint32_t secert_key,int round_no);

/*
 * permutaion function
 * to change bit sequence of text
 * input - plain text (16 bit int)
 * output - cipher text (16 bit int)
 *
 */
__uint16_t permute(__uint16_t text);

/*
 * s_box array
 * s[i] is a mapping from i -> s[i]
 *
 */
__uint8_t s_box[16] = {0x0E,0x04,0x0D,0x01,
                        0x02,0x0F,0x0B,0x08,
                        0x03,0x0A,0x06,0x0C,
                        0x05,0x09,0x00,0x07};

/*
 * permutation table
 * to pemute bit sequence
 */
int permutation_table[16] = {1,5,9,13,
                             2,6,10,14,
                             3,7,11,15,
                             4,8,12,16};

/*Binary values to get nth bit*/
__uint16_t nth_bit[16] = {
    0b1000000000000000, //first bit
    0b0100000000000000, //second bit
    0b0010000000000000, //third bit
    0b0001000000000000, //fourth bit
    0b0000100000000000, //fifth bit
    0b0000010000000000, //sixth bit
    0b0000001000000000, //seventh bit
    0b0000000100000000, //eight bit
    0b0000000010000000, //ninth bit
    0b0000000001000000, //tenth bit
    0b0000000000100000, //eleventh bit
    0b0000000000010000, //twelfth bit
    0b0000000000001000, //thirteenth bit
    0b0000000000000100, //fourteenth bit
    0b0000000000000010, //fifteenth bit
    0b0000000000000001  //sixteenth bit
};

/*
 * SPN encryption
 * input - char input
 * input2 - length of input 
 * input3 - 32 bit secret key
 * output - encrypted text
 */
__uint16_t SPN(char text[],int len,__uint32_t secret_key);


int main(){
    __uint32_t secret_key = 0x22485211;
    __uint16_t text = "thisiskavi";

    SPN(text, secret_key);

    return 0;
    
}

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

__uint16_t roundKeyGenerator(__uint32_t secret_key,int round_no){
    
    /*last bit to remove after taking 16 bits for round key.*/
    int shift = 48 - ((4*round_no)-3);
    return secret_key>>shift;
}

__uint16_t permute(__uint16_t text){
    /*declare 16 bit int to store answer and initialize it with 0*/
    __uint16_t permuted_text=0;

    /*shifting 16 bits*/
    for(int i=0;i<16;i++){

        /* shift amount
         * shift = dest - source
         *       = value at element i in permutation table - i (1,2, .. 16 ) 
         *  here array is 0 based so we added 1 to i.
         */
        int shift = (permutation_table[i] - (i+1));

        /* if shift is nagative we have to shift left side
         * for example   15 -> 12  shift = -3
         *                 shift left 3 times.
         */
        if(shift<0){ 
            shift = 0 - shift; 
            permuted_text = permuted_text | ((text & nth_bit[i])<<shift);
        }
        /* else shift right
         * 12 -> 15 
         * shift = 3
         */
        else{
            permuted_text = permuted_text | ((text & nth_bit[i])>>shift);
        }
    }
    return permuted_text;
}

__uint16_t SPN(char text[],int len,__uint32_t secret_key){
    char cipher_text[len];
    for(int i=0;i< len/2 ;i++){
        
    }
    return cipher_text;
}