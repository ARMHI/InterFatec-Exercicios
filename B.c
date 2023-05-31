#include <stdlib.h>
#include <stdio.h>

void group_count (int *grupos,int variant, int input1, int clock,  int counter, int carrier){

    counter = 0;
    for (clock = 0; clock<input1; clock++){

            if (carrier<grupos[clock]){
                counter++;
                if (variant == 1){}
                if (variant == 2){}

            }


    }

}

int main (){

    int input1, input2, *grupos, a, b, temp, *people, clock, clock2, *covid, variant, counter;
    char cmd;

    scanf("%d %d", &input1, &input2);

    grupos = (int*) malloc (sizeof(int)*input1);
    covid = (int*) malloc (sizeof(int)*input1);
    people = (int*) malloc (sizeof(int)*input1);

    for(clock = 0; clock < input1; clock++){
        grupos[clock]= clock+1;
        people[clock]= clock+1;
        covid[clock]= 0;
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
        
        case 'p':
            scanf(" %d", &a);
            covid[a-1] = 1;
            break;

        case 'n':

            variant = 0;
            group_count(grupos, variant, input1, clock2, counter, 0);
            
            printf ("%d\n", counter);

            break;

        case 'n':

            variant = 0;
            group_count(grupos, variant, input1, clock2, counter, 0);
            
            printf ("%d\n", counter);
            break;

        }

    }




    free(grupos);
    free(covid);
    free(people);

}
