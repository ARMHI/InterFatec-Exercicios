#include <stdio.h>
#include <stdlib.h>

void sequence_to_number(int a[3], int treated_input[999][7], int counter, int line, int position){
    //printf (" \n a == %d ", a[0]);
    //printf (" \n position == %d ", position);
    //printf (" \n line == %d ", line);

     switch (counter){
         case 1:
             treated_input[line][position] =  a[0];
             break;
         case 2:
             treated_input[line][position] =  (10 *a[0]) + a[1];
             break;
         case 3:
             treated_input[line][position] =  (100 *a[0]) + (10*a[1]) + a[2];
             break;
    }
}

int main()
{
    int end= 0, a[3], clock, clock2, clock3,clock4,  line={0}, ender=0, space_counter, treated_input[999][7] = {0};
    int counter, if_control, clock_if1, result_holder;
    char  space, input[999][28]= {0}, zero = {'0'};
    

    line=-1;
    do{
    line++;
    fgets(input[line], 28, stdin);
    //printf(" %s \n", input[line]);
    if(input[line][0]=='\n'){ender = 1;}
    if(input[line][0]=='\0'){ender = 1;}
    }while(ender==0);


    for(clock=0; clock<line; clock++){
        clock2 = 0;
        clock3 = 0;
        clock4 = 0;

        while(clock2<7){
            counter = 0;
            if_control = 0;
            for(clock4 =0; clock4<3; clock4++){
                if(input[clock][clock3]=='\n'){if_control = 1;}
                if(input[clock][clock3]==' '){if_control = 1;}
                if (if_control==0){
                    a[clock4] = input[clock][clock3] - zero;
                    //printf (" \n zero == %d ", zero);
                    //printf (" \n a == %d ", a[0]);
                    //printf (" \n input == %d ", input[0][clock3]);
                    clock3++;
                    counter++;
                }
            }

                sequence_to_number( a, treated_input, counter, clock, clock2);
                clock2++;
                clock3++;
        }

                    
    }
    
    for(clock =0; clock <line; clock++){
        clock_if1=0;
        if((treated_input[clock][0]>64)&&(treated_input[clock][0]<91)){clock_if1++;}
        if((treated_input[clock][1]>64)&&(treated_input[clock][1]<91)){clock_if1++;}
        if((treated_input[clock][2]>64)&&(treated_input[clock][2]<91)){clock_if1++;}
        if((treated_input[clock][3]>47)&&(treated_input[clock][3]<58)){clock_if1++;}
        if((treated_input[clock][5]>47)&&(treated_input[clock][5]<58)){clock_if1++;}
        if((treated_input[clock][6]>47)&&(treated_input[clock][6]<58)){clock_if1++;}
        //printf(" \n clockif == %d\n", clock_if1);
        
        if(clock_if1 == 6){
            if((treated_input[clock][4]>47)&&(treated_input[clock][4]<58)){result_holder = 1;}
            else{
                if((treated_input[clock][4]>64)&&(treated_input[clock][4]<91)){result_holder =0;}
                else{result_holder = 2;}
            }
        }
        else{result_holder = 2;}

        switch(result_holder){
            case 0:
                printf("MERCOSUL\n");
                break;
            case 1:
                printf("ANTIGA\n");
                break;
            case 2:
                printf("ERRO\n");
                break;
        }
    }

       
 //   printf ("\n input == %s", input[0]);
  //  printf ("\n treated_input == ");
   // for(clock = 0; clock < 7; clock++){
    //    printf (" %d, ", treated_input[0][clock]);}




  return 0;
}
