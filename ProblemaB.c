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

void Contamination(bool* safety, int* idg, int* a){
    for (clock=0; clock < E; clock++){  if (idg[clock]==idg[a-1]){ safety[clock]==0;}}
}

void Triage(bool* safety, int* idg, int* group, int* pop,int a, int b){

    if (b==0){
      Contamination(safety, idg, a);
    }

    else{
        if(safety[a-1]==0 || safety[b-1]==0){ Contamination(safety, idg, a);}
    }

}

void GroupCount(int a, int b, int* group, int* idg){
    


}


void Fusing(int a, int b, int c, int* idg, int* group, int* pop, bool* safety){

    if (idg[a-1]==idg[b-1]){return;}

    c=idg[b-1];

    for(clock=(idg[a-1]-1); clock<E; clock++){

        if (idg[clock]==c){
            idg[clock]=idg[a-1];
        }
        GroupCount();
    }
    
    Triage(safety, idg, group, pop, a, b);

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

        scanf("%c", cmd);

        switch(cmd){
        
            case 'c':

                scanf ("%d, %d", a, b);

                if( idg[a-1]<idg[b-1] ){ c=a; a=b; b=c;}

                Fusing(a, b, 0, idg, group, pop, safety);

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
