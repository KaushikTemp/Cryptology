#include<stdio.h>

char Enc(char text,int key){
        text= ((text-'a'+key)%26) + 'a';
    return text;
}
char Dec(char text,int key){
        text= ((text-'a'-key+26)%26) + 'a';
    return text;
}

void main(){
    int key = 'k';
    char pText[] = "kaushik";
    printf("plain text = %s \n",pText);
    int x=7;
    
    char out[x];
    for(int i=0;i<x;i++){
        out[i] = Enc(pText[i],key);
    }
    printf("Encrypted text : %s\n",out);
    
    for(int i=0;i<x;i++){
        out[i] = Dec(pText[i],key);
    }

    printf("Decrpted text : %s\n",out);
}