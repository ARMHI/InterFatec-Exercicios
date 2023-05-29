#include <stdlib.h>
#include <stdio.h>


int main (){

    int input1, input2, *grupos, a, b, temp, *people, clock, clock2;
    char cmd;

    scanf("%d %d", &input1, &input2);

    grupos = (int*) malloc (sizeof(int)*input1);
    people = (int*) malloc (sizeof(int)*input1);

    for(clock = 0; clock < input1; clock++){
        input1[clock]= clock+1;
    }

    for (clock = 0; clock < input2; clock++){
        scanf("%c", &cmd);
        
        switch (cmd)
        {
        case 'c':
            scanf (" %d %d", &a, &b);

            if(grupos[a-1] > grupos[b-1]){temp=a; a=b; b=temp;}
            for (clock2 = grupos[b-1]; clock2 < input1; clock2++){
                if ( grupos[clock2]==grupos[b-1]){
                   grupos[clock2]=grupos[a-1];
                }
            }

            break;
        
        default:
            break;
        }

    }




    free(grupos);
    free(people);

}
