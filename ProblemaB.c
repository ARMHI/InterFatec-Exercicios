#include <stdlib.h>
#include <stdio.h>

// P = numero da populção,  E = numero de Eventos, cmd = comando, id = id dos dados;
int a, b, c, clock, checker, P, cmd, E,grupos, *pop, *group, *idg;
bool *safety;

void ArrayInit(int *pop, int *group, int *idg, bool *safety, int P, int clock){
    for(clock=0; clock < P; clock++){
    pop[clock]=clock+1;
    idg[clock]=clock+1;
    group[clock]=1;
    safety[clock]=1;
    //printf(" %d %d \n", pop[clock], ii[clock]);
    }
}

int main (){

    scanf (" %d %d", &P, &E);

    grupos = P;

    int *pop = (int*) malloc (sizeof(int)*P);
    if (pop==NULL){printf ("Memmory Allocation Error\n"); return 0;}

    int *group = (int*)malloc (sizeof (int)*P);
    if (group==NULL){printf ("Memmory Allocation Error\n"); return 0;}

    int *idg = (int*)malloc (sizeof (int)*P);
    if (idg==NULL){printf ("Memmory Allocation Error\n"); return 0;}

    bool *safety = (bool*) malloc (sizeof(bool)*P);
    if (safety==NULL){printf ("Memmory Allocation Error\n"); return 0;}

    ArrayInit(pop, group, idg, safety, P, 0);

    for (clock = 0; clock < E; clock++){
        switch(cmd){
        
            case 'c':
                scanf ("%d %d", &a, &b);
                grupos--;

                if (idg[a-1]>idg[b-1])
                    {c=a; a=b; b=c;}

                if(idg[a-1]==a && idg[b-1]==b)
                    checker = idg[b-1];
                        for(clock=idg[b-1];clock<(P+1);clock++){
                            if (idg[clock]==checker){
                                idg[clock]=idg[a-1]
                            }
                        }
                    }

                else{

                    //if (idg[a-1]=a) == transforma todos os id de grupo idg [b-1] em id do grupo de a( do grupo em que o maior numero AKA b estava contido)
                    if (idg[a-1]==a){
                        checker = idg[b-1];
                        for(clock=idg[b-1];clock<(P+1);clock++){
                            if (idg[clock]==checker){
                                idg[clock]=idg[a-1];
                            }
                        }
                    }
                }

                if(safety[a-1]==0 || safety[b-1]==0){
                    if(safety)
                }

                Grouping();

                break;
        
            case 'p':

                break;
        
            case 'n':

                break;

            case 'ns':

                break;

            case 'ni':

                break;

            case 'ii':

                break;

        }
    }

    free(pop);
    free(group);
    free(idg);
    free(safety);


    return 0;
}