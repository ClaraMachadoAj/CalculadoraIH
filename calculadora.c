/*
22/08
Inciando: 21:23 
Decimal para Base 2: finalizado (não conferido) - 21:32
Decimal para Base 8: iniciando - 21:34
                     finalizado (não conferido) - 21:39
Decipal para base 16: iniciando - 21:40
                      finalizado (não conferido) - 21:41
Códig BCD: iniciando - 21:42
           finalizado (não conferido) - 22:05*/
#include <stdio.h>

void toBinary(int num){
  printf("Base 10 para Base 2:\n");
  int binary[32];
  int contDiv = 0;
  while(num > 0){
    binary[contDiv] = num % 2;
    printf("Passo %d: %d %% 2 = %d (resto)\n", contDiv+1, num, binary[contDiv]);
    num = num / 2;
    printf("Novo valor do número sendo convertido = %d\n", num);
    contDiv++;
  }

  printf("Resultado em Base 2: \n");
  for(int inversor = contDiv - 1; inversor >= 0; inversor--){
    printf("%d", binary[inversor]);
  }
   printf("\n");
}

void toOctal(num){
  printf("Base 10 para Base 8:\n");
  int octal[32];
  int contDiv = 0;

  while(num > 0){
    octal[contDiv] = num % 8;
    printf("Passo %d: %d %% 8 = %d (resto)\n", contDiv+1, num, octal[contDiv]);
    num = num / 8;
    printf("Novo valor do número sendo convertido = %d\n", num);
    contDiv++;
  }
  printf("Resultado em Base 8: \n");
  for (int inversor = contDiv - 1; inversor >= 0; inversor--){
    printf("%d", octal[inversor]);
  }
}

void toHex(num){
  printf("Base 10 para Base 16:\n");
  int hex[32];
  int contDiv = 0;

  while(num > 0){
    hex[contDiv] = num % 16;
    printf("Passo %d: %d %% 16 = %d (resto)\n", contDiv+1, num, hex[contDiv]);
    num = num / 16;
    printf("Novo valor do número sendo convertido = %d\n", num);
    contDiv++;
  }
  printf("Resultado em Base 16: \n");
  for (int inversor = contDiv - 1; inversor >= 0; inversor--){
    printf("%d", hex[inversor]);
  }
}

void toBCD(num){
  printf("Base 10 para BCD:\n");
  int byte[4];
  while(num > 0){
    int digit = num % 10;
    printf("Dígito %d em BCD: ", digit);
    for (int cont = 3; cont < 0; cont--){
      byte[cont] = digit % 2;
    }
    for (int cont = 3; cont < 0; cont--){
      printf("%d", byte[cont]);
    }
    printf("\n");
    num = num / 10;
    printf("Novo valor de n = %d\n", num);
  }
}

int main(void) {
  printf("Hello World\n");
  return 0;
}