#include <stdlib.h>
#include <stdio.h>


int main (){

    int input1, input2, *grupos;

    scanf("%d %d", input1, input2);


    grupos = (int*) malloc (sizeof(int)*input1);



    for(clock = 0; clock < input1; clock++){
        input1[clock]= clock+1;
    }


}


