#include<stdio.h>
const int a='a'; //ascii value of a

char Enc(char text,int key){
        text-=a;
        text =(text+key)%26;
        text+=a;
    return text;
}
char Dec(char text,int key){
        text-=a;
        text = ((text - key) + 26) % 26 ;
        text+=a;
    return text;
}

void main(){
    int key = 5;
    char pText[] = "kaushik";
    printf("plain text = %s \n",pText);
    int x=7;
    
    char out[x],cipherText[x];
    for(int i=0;i<x;i++){
        cipherText[i] = Enc(pText[i],key);
    }
    printf("\nEncrypted text : %s\n",cipherText);
    
    for(int i=0;i<x;i++){
        out[i] = Dec(cipherText[i] ,key);
    }

    printf("Decrpted text : %s\n",out);
}
