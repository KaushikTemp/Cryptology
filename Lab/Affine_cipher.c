#include<stdio.h>

int a = 2;
int b = 5;
int a_in=0;

void aInv(){
    int i=1;
    while ((a * i)%26 != 1 && i<26)
    {
        i++;
    }
    a_in = i;
}

char Enc(char text){
    text = ((text*a)+b)%26;
    printf("%d",text);
    return text;
}
char Dec(char text){
    text = ((text-b)*a_in)%26;
    return text;
}

void main(){
    char pText[] = "abcdefg";

    printf("plain text = %s \n",pText);
    int x=7;
    
    char out[x];

    void aInv();
    for(int i=0;i<x;i++){
        out[i] = Enc(pText[i]);
    }
    printf("\nEncrypted text : %s\n",out);
    
    for(int i=0;i<x;i++){
        out[i] = Dec(out[i]);
    }
    printf("Decrpted text : %s\n",out);
}
