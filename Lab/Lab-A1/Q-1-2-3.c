#include <stdio.h>
#include <stdbool.h>

char plainText[]="rathvakaushik";
int text_length = sizeof(plainText)/sizeof(char)-1;
int p=0;
char playfair[5][5];

bool existIn_Playfair(char c);
void make_Playfair(char *str);
void init_playFair();
void print_playfair();

int main(){
    init_playFair();

    makePlayfair(plainText);


    printf("Q3 : %s\n\n",playfair);

    //for(int i=0;i<=26;i++){
     //   if(i=='j'-'a'){i++;}
       // char t = 'a'+i;
       // makePlayfair(t);
    //}


    printf("Q5 :\n");
    print_playfair();

    return 0;
}

bool existInPlayfair(char c){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(playfair[i][j]==c){return true;}
        }
    }
    return false;
}

void make_Playfair(char *str){
    for(int i=0;i<=text_length;i++){
        if(!existInPlayfair(str[i])){
            playfair[p/5][p%5]=str[i];
            if(p<25){p++;}
            else{break;}
        }
    }
}

void init_playFair(){
    for(int i=0;i<25;i++){
        playfair[i/5][i%5]=0;
    }
}

void print_playfair(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%c ",playfair[i][j]);
        }
        printf("\n");
    }
}
