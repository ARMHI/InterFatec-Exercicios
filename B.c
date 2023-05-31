#include <stdlib.h>
#include <stdio.h>

void char_to_int(int a, int b, char cmd[20], int clock, int control[5], int counter, char zero)
{

  while (cmd[clock] != ' ')
  {
    control[counter] = cmd[clock] - zero;
    counter++;
    clock++;
  }

  switch (counter)
  {

  case 1:
    a = control[0];
    break;

  case 2:
    a = (control[1] + (control[0] * 10));
    break;
  case 3:
    a = (control[2] + (control[1] * 10) + (control[0] * 100));
    break;
  case 4:
    a = (control[3] + (control[2] * 10) + (control[1] * 100) + (control[0] * 1000));
    break;
  case 5:
    a = (control[4] + (control[3] * 10) + (control[2] * 100) + (control[1] * 1000) + (control[0] * 10000));
    break;
  }
  // printf(" %s --- \n ", cmd);

  clock = 3 + counter;
  counter = 0;
  b = 0;
  while (b == 0)
  {

    if (cmd[clock] == ' ')
    {
      b = 1;
    }
    if (cmd[clock] == '\n')
    {
      b = 1;
    }
    control[counter] = cmd[clock] - zero;
    counter++;
    clock++;
  }
  // printf("%d----- control \n", control[0]);

  counter--;
  // printf(" counter ----- %d\n", counter);
  switch (counter)
  {

  case 1:
    b = control[0];
    printf("%d----- control \n", control[0]);
    printf("%d----- b \n", b);
    break;

  case 2:
    b = (control[1] + (control[0] * 10));
    break;
  case 3:
    b = (control[2] + (control[1] * 10) + (control[0] * 100));
    break;
  case 4:
    b = (control[3] + (control[2] * 10) + (control[1] * 100) + (control[0] * 1000));
    break;
  case 5:
    b = (control[4] + (control[3] * 10) + (control[2] * 100) + (control[1] * 1000) + (control[0] * 10000));
    break;
  }
  // printf(" aaaaaa--- %d, bbbbbb-----%d\n", a, b);
}

void group_count(int *grupos, int variant, int input1, int clock, int counter, int carrier, int *covid)
{

  for (clock = 0; clock < input1; clock++)
  {

    if (grupos[clock] > carrier)
    {
      carrier = grupos[clock];
      // printf("%d ----- carrier\n ",carrier);
      // printf("%d ----- grupos clock\n ",grupos[clock]);
      counter++;
      if (variant == 1)
      {
        if (covid[grupos[clock]] == 0)
        {
          counter--;
        }
      }
      if (variant == 2)
      {
        if (covid[grupos[clock]] == 1)
        {
          counter--;
        }
      }
    }
  }
  printf("%d\n", counter);
}

int main()
{

  int input1, input2, *grupos, a, b, temp, *people, clock, clock2, *covid, variant, counter, regulator;
  int control[5], carrier;
  char cmd[20], zero = '0';

  scanf("%d %d", &input1, &input2);

  grupos = (int *)malloc(sizeof(int) * input1);
  covid = (int *)malloc(sizeof(int) * input1);
  people = (int *)malloc(sizeof(int) * input1);

  for (clock = 0; clock < input1; clock++)
  {
    grupos[clock] = clock + 1;
    people[clock] = clock + 1;
    covid[clock] = 0;
  }

  for (clock = 0; clock < input2; clock++)
  {

    fgets(cmd, 20, stdin);

    switch (cmd[0])
    {
    case 'c':

      char_to_int(a, b, cmd, 2, control, 0, zero);
      // printf(" aaaaaa--- %d, bbbbbb-----%d\n", a, b);

      if (grupos[a - 1] > grupos[b - 1])
      {
        temp = a;
        a = b;
        b = temp;
      }

      for (clock2 = 0; clock2 < input1; clock2++)
      {

        if (grupos[clock2] == grupos[b - 1])
        {
          grupos[clock2] = grupos[a - 1];
        }
      }

      break;

    case 'p':
      scanf(" %d", &a);
      covid[a - 1] = 1;
      break;

    case 'n':
      switch (cmd[1])
      {
      case 'i':
        variant = 1;
        group_count(grupos, variant, input1, clock2, counter, 0, covid);
        break;

      case 's':
        variant = 2;
        group_count(grupos, variant, input1, clock2, counter, 0, covid);
        break;

      default:
        variant = 0;
        group_count(grupos, variant, input1, clock2, counter, 0, covid);
        regulator = 1;
        break;
      }
      break;

    case 'i':
      scanf(" %c", &cmd);
      counter = 0;
      for (clock2 = 0; clock2 < input1; clock2++)
      {
        if (covid[grupos[clock2]] == 1)
        {
          printf("%d ", grupos[clock2] + 1);
          counter++;
        }
      }
      if (counter == 0)
      {
        printf("vazio\n");
      }

      break;
    }
  }

  free(grupos);
  free(covid);
  free(people);

  return 0;
}

