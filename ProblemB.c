#include <stdlib.h>
#include <stdio.h>
// pi = pessoas comprometidas, gs = grupos seguros, gi= grupos inseguros
    int clock, g, e, click, quant, gs, gi, pi, pop[1], *P;
    char  c;
    
    void testArrayP(int clock,int g){

        for (clock = 0; clock<g;clock++){
            printf ("%d ", pop[clock]);
            printf("%d\n", clock);
        }


    }

    void FL(int clock, int g){

    for ( clock = 0; clock < g; clock++){
        pop[clock]=clock+1;
        printf("%d\n", clock);
       // printf("%d\n", g);
        printf ("%d ", pop[clock]);
    }

    }
int main ( ){


    P=&pop[1];



    scanf ("%d %d", &g, &e);
    printf ("coroi");

    P = (int*) malloc (sizeof(int) * g);

    if (P==NULL){printf("o fuck");}
    
    FL(0, g);
    
    //testArrayP(0, g);


    for (clock=0; clock < e; clock++) {

        scanf ("%c", &c);

        switch (c)
        {
        case 'c':
            int a, b;
            scanf ("%d %d", &a, &b);

            break;
        
        case 'p':
            int c;
            scanf("%d", &c);

            break;

        case 'n':

            printf ("%d", quant);

            break;
        
        case 'ns':

            printf ("%d", gs);

            break;

        case 'ni':

            printf ("%d", gi);

            break;
        
        case 'ii':

            printf ("%d", pi);

            break;

        default:
        printf ("invalid input\n");
            break;
        }

    }

free(P);

return 0;


}
