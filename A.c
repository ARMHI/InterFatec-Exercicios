#include <stdio.h>
#include <stdlib.h>


int main()
{
  int input[7], clock, type_of_plate;
  
  for (clock=0; clock < 7; clock++){
    
    scanf("%d", &input[clock]);
    
  }
  
  if ((64<input[0]<91)&&(64<input[1]<91)&&(64<input[2]<91)&&(47<input[3]<58)&&(47<input[5]<58)&&(47<input[6]<58)){
 
    if(64<input[4]<91||47<input[4]<58){
      if(64<input[4]<91){type_of_plate=0;}
      else{type_of_plate=1;}
    }
    else{type_of_plate=2;}
  }
  
  else{type_of_plate=2;}
  return 0;
}