#include <stdlib.h>
#include <stdio.h>


int main (){

char arrays[200] = {0}, arrayn[400] = {0}, alphabet[26]= {'a', 'b', 'c', 'd', 'e','f', 'g','h', 'i','j', 'k','l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int x = 1, c, alphaclock, clock, numclock = 0, size;

    //entrada
    fgets (arrays, 200, stdin);
    fgets (arrayn, 400, stdin);

    //discover size array

    for(size = 0; arrays[size]!='\0'; size++){
        
    //printf ("%d", size);
    }
    size = size -1;
    //printf ("%d", size);

    //execução

    for(clock =0; clock< size; clock++){

    // discovering letter in 1st array
        alphaclock = 0;
        while ((arrays[clock] != alphabet[alphaclock])){alphaclock++;}

       // printf("___> %d <___", alphaclock);
    


    // identifying if its either + or - in arrayn
    if (arrayn[numclock] == '-' || arrayn[numclock] == '+'){
        if (arrayn[numclock] == '-'){x = 0;}
        if (arrayn[numclock] == '+'){x = 1;}
        numclock++;
    }
        
    //    printf("identified");
    // fixing arrays   

    if (x=0){ 
        alphaclock = alphaclock - arrayn[numclock]; 
        if (alphaclock <0){ alphaclock = 26 - alphaclock;}
        numclock ++;
    }

    if (x=1){ 
        alphaclock = alphaclock + arrayn[numclock]; 
        if (alphaclock > 25){ alphaclock =  alphaclock - 26;}
        numclock ++;
    }

    // finalyzing array
    printf (" >>> %c <<<", alphabet[alphaclock]);

    arrays[clock] = alphabet[alphaclock];


    }

    printf("____> %s <-----", arrays);


    return 0;

}
