#include <stdlib.h>
#include <stdio.h>

void entrada(char string[200], char num[400], int size, int clock){
    fgets(string, size, stdin);
    size = 400;
    fgets(num, size, stdin);

}

void decode(char num[400], char alphabet[26], int alphaclock, int cleck, int sinal, int val){ 
    if(sinal==1){
        val = num[cleck];
        //scanf(num[cleck], "%d", &val);
        cleck++;
        alphaclock = alphaclock + val;
        if (alphaclock > 25){alphaclock=alphaclock-26;}
    }
    else{
        val = num[cleck];
        cleck++;
        alphaclock = alphaclock - val;
        if (alphaclock < 0){alphaclock=alphaclock+26;}
    }

}

void final_touches(char string[200], char *alphabet, int clock, int alphaclock){
    string[clock]=alphabet[alphaclock];
    printf("%s", string[clock]);
    printf("%s", alphabet[alphaclock]);
}

void verification(char num[400], int sinal, int cleck){
    if (num[cleck] == '-'){sinal = 0;cleck++;}
    if (num[cleck] == '+'){sinal =1;cleck++;}
    
}

void triage(char string[200], char num[400], char alphabet[26], int clock, int lengths, int alphaclock, int click, int cleck, int sinal){

    for (clock= 0; clock < lengths; clock++){

        alphaclock = 0;
        while (string[clock]!=alphabet[alphaclock]&&string[clock]!='w')  {alphaclock++;}

        verification( string, sinal, cleck);

       
        if (string[clock]!='w'){decode(num, alphabet, alphaclock, cleck, sinal, 0); final_touches(string, alphabet, clock, alphaclock);}
        
        else{string[clock]=' ';}
        

    }

}








int main(){
    
    int sinal = 1;
    int clock, size, lengths, lengthn;
    char string[200], num[400], alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j','k', 'l', 'm', 'n', 'o','p', 'q', 'r', 's', 't','u', 'v', 'w', 'x', 'y','z'};

    entrada (string, num, 200, 0);

    for (lengths=0; string[lengths]!='\0'; lengths++){}
    lengths= lengths-1;
    triage (string, num, alphabet, clock, lengths, 0, 0, 0, sinal);


    free(num); return 0;

}
