#include<stdio.h>

int a = 3;
int b = 5;
int a_in=0;

void aInv(){
    int i=0;
    while ((a * i)%26 != 1 && i<26)
    {
        i++;
    }
    a_in = i;
}

char Enc(char text){
    text = ((text*a)+b)%26;
    return text;
}
char Dec(char text){
    text = ((text-b)*a_in)%26;
    return text;
}

void main(){

    int key = 'K';
    char pText[] = "kaushik";

    printf("plain text = %s \n",pText);

    int x=7;
    
    char out[x];

    for(int i=0;i<x;i++){
        out[i] = Enc(pText[i]);
    }
    printf("Encrypted text : %s\n",out);
    
    for(int i=0;i<x;i++){
        out[i] = Dec(pText[i]);
    }

    printf("Decrpted text : %s\n",out);
}
