/*
22/08
Inciando: 21:23 
Decimal para Base 2: finalizado (não conferido) - 21:32
Decimal para Base 8: iniciando - 21:34
                     finalizado (não conferido) - 21:39
Decipal para base 16: iniciando - 21:40
                      finalizado (não conferido) - 21:41
Códig BCD: iniciando - 21:42
           finalizado (não conferido) - 22:05
           
23/08
Complemento a 2: iniciando - 8:11
                 finalizado (não conferido) - 8:42
28/08
Terceira questão: iniciando - 10:44 

29/08 
                  finalizando e conferindo tudo - 21:00

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Declarações de funções auxiliares
void toBinaryFraction(double fraction, char *binaryStr, size_t maxLen);
void toBinaryExponent(int exponent, char *exponentBin, size_t maxLen);
void toNormalizedFloat(char *binaryStr, int *exponent, size_t maxLen);

// Função para conversão de inteiro para binário
void toBinary(int num) {
    printf("\nConvertendo número inteiro (%d) para base binária:\n", num);
    int binary[32];
    int contDiv = 0;

    // Loop para calcular o binário do número
    while (num > 0) {
        binary[contDiv] = num % 2;  // Armazena o resto da divisão por 2
        printf("Passo %d: %d %% 2 = %d (resto)\n", contDiv + 1, num, binary[contDiv]);
        num = num / 2;  // Atualiza o número para a próxima iteração
        printf("Novo valor do número sendo convertido = %d\n", num);
        contDiv++;
    }

    // Imprime o resultado final em binário
    printf("Resultado em Base 2: ");
    for (int inversor = contDiv - 1; inversor >= 0; inversor--) {
        printf("%d", binary[inversor]);
    }
    printf("\n");
}

// Função para conversão de inteiro para octal
void toOctal(int num) {
    printf("\nConvertendo número inteiro (%d) para base octal:\n", num);
    int octal[32];
    int contDiv = 0;

    // Loop para calcular o octal do número
    while (num > 0) {
        octal[contDiv] = num % 8;  // Armazena o resto da divisão por 8
        printf("Passo %d: %d %% 8 = %d (resto)\n", contDiv + 1, num, octal[contDiv]);
        num = num / 8;  // Atualiza o número para a próxima iteração
        printf("Novo valor do número sendo convertido = %d\n", num);
        contDiv++;
    }

    // Imprime o resultado final em octal
    printf("Resultado em Base 8: ");
    for (int inversor = contDiv - 1; inversor >= 0; inversor--) {
        printf("%d", octal[inversor]);
    }
    printf("\n");
}

// Função para conversão de inteiro para hexadecimal
void toHex(int num) {
    printf("\nConvertendo número inteiro (%d) para base hexadecimal:\n", num);
    int hex[32];
    int contDiv = 0;

    // Loop para calcular o hexadecimal do número
    while (num > 0) {
        hex[contDiv] = num % 16;  // Armazena o resto da divisão por 16
        printf("Passo %d: %d %% 16 = %d (resto)\n", contDiv + 1, num, hex[contDiv]);
        num = num / 16;  // Atualiza o número para a próxima iteração
        printf("Novo valor do número sendo convertido = %d\n", num);
        contDiv++;
    }

    // Imprime o resultado final em hexadecimal
    printf("Resultado em Base 16: ");
    for (int inversor = contDiv - 1; inversor >= 0; inversor--) {
        if (hex[inversor] < 10)
            printf("%d", hex[inversor]);
        else
            printf("%c", hex[inversor] + 55);  // Converte 10-15 para A-F
    }
    printf("\n");
}

// Função para conversão de inteiro para BCD (Decimal Codificado em Binário)
void toBCD(int num) {
    printf("\nConvertendo número inteiro (%d) para BCD (Decimal Codificado em Binário):\n", num);

    int bcd[40];  // Armazena o resultado BCD
    int index = 0;

    // Loop para converter cada dígito decimal em BCD
    while (num > 0) {
        int digit = num % 10;
        printf("Dígito decimal: %d\n", digit);

        // Converte cada dígito decimal para binário de 4 bits
        int binary[4] = {0, 0, 0, 0};
        for (int i = 3; i >= 0; i--) {
            binary[i] = digit % 2;
            digit = digit / 2;
        }

        printf("Representação binária do dígito: ");
        for (int i = 0; i < 4; i++) {
            printf("%d", binary[i]);
        }
        printf("\n");

        // Armazena o binário do dígito atual no array BCD
        for (int i = 0; i < 4; i++) {
            bcd[index++] = binary[i];
        }

        num = num / 10;  // Move para o próximo dígito decimal
    }

    // Imprime o resultado em BCD
    printf("Resultado em BCD: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", bcd[i]);
    }
    printf("\n");
}

// Função para conversão de inteiro para complemento a 2
void toComplement2(int num) {
    printf("\nConvertendo número inteiro (%d) para complemento a 2 (16 bits):\n", num);

    if (num >= 0) {
        // Número positivo, apenas converte para binário
        toBinary(num);
    } else {
        // Número negativo, precisa calcular o complemento a 2
        printf("Número negativo detectado: %d\n", num);
        num = abs(num);  // Converte para positivo
        int binary[16] = {0};  // Array para armazenar o binário
        int contDiv = 0;

        // Converte o valor positivo para binário
        while (num > 0) {
            binary[contDiv] = num % 2;
            printf("Passo %d: %d %% 2 = %d (resto)\n", contDiv + 1, num, binary[contDiv]);
            num = num / 2;
            printf("Novo valor do número sendo convertido = %d\n", num);
            contDiv++;
        }

        // Calcula o complemento a 1
        printf("Complemento a 1 (invertendo bits): ");
        for (int cont = 0; cont < 16; cont++) {
            binary[cont] = binary[cont] == 0 ? 1 : 0;  // Inverte os bits
            printf("%d", binary[cont]);
        }
        printf("\n");

        printf("Adicionando 1 ao complemento a 1 para formar complemento a 2:\n");
        int carry = 1;  // Inicializa o carry para o complemento a 2
        for (int cont = 0; cont < 16; cont++) {
            int sum = binary[cont] + carry;
            binary[cont] = sum % 2;  // Atualiza o bit atual
            carry = sum / 2;  // Calcula o carry para o próximo bit
        }

        // Imprime o resultado em complemento a 2
        printf("Resultado em complemento a 2: ");
        for (int cont = 15; cont >= 0; cont--) {
            printf("%d", binary[cont]);
        }
        printf("\n");
    }
}

// Função para converter float para binário
void realToBinary(float num) {
    printf("\nConvertendo número float (%f) para ponto flutuante binário:\n", num);
    char output[1024] = "";  // Buffer para armazenar a saída
    char temp[256];          // Buffer temporário
    char binaryStr[128] = "";  // Armazena a representação binária
    int isNegative = 0, exponent = 0;  // Indica se o número é negativo e o expoente
    double fractionPart, integerPart;

    // Determina o sinal do número
    if (num < 0) {
        isNegative = 1;
        num = -num;  // Converte para positivo
    }

    // Separa parte inteira e fracionária
    fractionPart = modf(num, &integerPart);
    printf("Parte inteira: %.0f, Parte fracionária: %f\n", integerPart, fractionPart);

    // Converte a parte inteira e fracionária para binário
    printf("Convertendo parte inteira para binário...\n");
    toBinary((int)integerPart);
    strncat(binaryStr, ".", sizeof(binaryStr) - strlen(binaryStr) - 1);
    printf("Convertendo parte fracionária para binário...\n");
    toBinaryFraction(fractionPart, binaryStr, sizeof(binaryStr));

    // Normaliza o número
    printf("Normalizando o número binário...\n");
    toNormalizedFloat(binaryStr, &exponent, sizeof(binaryStr));
    printf("Número normalizado (mantissa): %s\n", binaryStr);
    printf("Expoente calculado: %d\n", exponent);

    // Armazena a saída formatada
    snprintf(temp, sizeof(temp), "\nFloat Binário Normalizado: %s\nExpoente: 2^%d\n\n", binaryStr, exponent);
    strncat(output, temp, sizeof(output) - strlen(output) - 1);

    // Calcula o expoente com viés
    int floatExponent = 127 + exponent;
    char exponentBin[12] = "";
    toBinaryExponent(floatExponent, exponentBin, sizeof(exponentBin));

    // Adiciona a parte do expoente à saída
    snprintf(temp, sizeof(temp), "FLOAT (IEEE 754):\nSinal: %d\nExpoente (com viés 127): %d (Binário: %s)\nMantissa: %s\n",
             isNegative, floatExponent, exponentBin, binaryStr);
    strncat(output, temp, sizeof(output) - strlen(output) - 1);

    // Exibe toda a saída formatada
    printf("%s", output);
}

// Função para converter double para binário
void doubleToBinary(double num) {
    printf("\nConvertendo número double (%lf) para ponto flutuante binário:\n", num);
    char output[1024] = "";  // Buffer para armazenar a saída
    char temp[256];          // Buffer temporário
    char binaryStr[128] = "";  // Armazena a representação binária
    int isNegative = 0, exponent = 0;  // Indica se o número é negativo e o expoente
    double fractionPart, integerPart;

    // Determina o sinal do número
    if (num < 0) {
        isNegative = 1;
        num = -num;  // Converte para positivo
    }

    // Separa parte inteira e fracionária
    fractionPart = modf(num, &integerPart);
    printf("Parte inteira: %.0f, Parte fracionária: %f\n", integerPart, fractionPart);

    // Converte a parte inteira e fracionária para binário
    printf("Convertendo parte inteira para binário...\n");
    toBinary((int)integerPart);
    strncat(binaryStr, ".", sizeof(binaryStr) - strlen(binaryStr) - 1);
    printf("Convertendo parte fracionária para binário...\n");
    toBinaryFraction(fractionPart, binaryStr, sizeof(binaryStr));

    // Normaliza o número
    printf("Normalizando o número binário...\n");
    toNormalizedFloat(binaryStr, &exponent, sizeof(binaryStr));
    printf("Número normalizado (mantissa): %s\n", binaryStr);
    printf("Expoente calculado: %d\n", exponent);

    // Armazena a saída formatada
    snprintf(temp, sizeof(temp), "\nDouble Binário Normalizado: %s\nExpoente: 2^%d\n\n", binaryStr, exponent);
    strncat(output, temp, sizeof(output) - strlen(output) - 1);

    // Calcula o expoente com viés
    int doubleExponent = 1023 + exponent;
    char exponentBin[12] = "";
    toBinaryExponent(doubleExponent, exponentBin, sizeof(exponentBin));

    // Adiciona a parte do expoente à saída
    snprintf(temp, sizeof(temp), "DOUBLE (IEEE 754):\nSinal: %d\nExpoente (com viés 1023): %d (Binário: %s)\nMantissa: %s\n",
             isNegative, doubleExponent, exponentBin, binaryStr);
    strncat(output, temp, sizeof(output) - strlen(output) - 1);

    // Exibe toda a saída formatada
    printf("%s", output);
}

// Funções auxiliares para conversão de partes de números reais
void toBinaryFraction(double fraction, char *binaryStr, size_t maxLen) {
    char temp[2];
    while (fraction > 0.0 && strlen(binaryStr) < maxLen - 1) {
        fraction *= 2;
        snprintf(temp, sizeof(temp), "%d", (int)fraction);
        strncat(binaryStr, temp, maxLen - strlen(binaryStr) - 1);
        if (fraction >= 1.0) {
            fraction -= 1.0;
        }
    }
}

void toBinaryExponent(int exponent, char *exponentBin, size_t maxLen) {
    char temp[2];
    while (exponent > 0 && strlen(exponentBin) < maxLen - 1) {
        snprintf(temp, sizeof(temp), "%d", exponent % 2);
        strncat(exponentBin, temp, maxLen - strlen(exponentBin) - 1);
        exponent /= 2;
    }
}

void toNormalizedFloat(char *binaryStr, int *exponent, size_t maxLen) {
    int pointPosition = strchr(binaryStr, '.') - binaryStr;
    if (binaryStr[0] == '1') {
        *exponent = strlen(binaryStr) - pointPosition - 1;
        memmove(&binaryStr[pointPosition], &binaryStr[pointPosition + 1], strlen(&binaryStr[pointPosition + 1]) + 1);
    } else {
        *exponent = -1;
        while (binaryStr[++(*exponent)] != '1' && strlen(binaryStr) < maxLen - 1) {}
        memmove(&binaryStr[*exponent], &binaryStr[*exponent + 1], strlen(&binaryStr[*exponent + 1]) + 1);
        *exponent = -(*exponent);
    }
}

// Função principal
int main() {
    int num;
    float realNum;
    double doubleNum;

    printf("Digite um número inteiro para conversões (base 10): ");
    scanf("%d", &num);
    printf("Número: %d\n", num);
    toBinary(num);
    printf("\n");

    toOctal(num);
    printf("\n");

    toHex(num);
    printf("\n");

    toBCD(num);
    printf("\n");

    toComplement2(num);
    printf("\n");

    printf("Digite um número real (float): ");
    scanf("%f", &realNum);
    printf("Número Real (float): %f\n", realNum);
    realToBinary(realNum);
    printf("\n");

    printf("Digite um número real (double): ");
    scanf("%lf", &doubleNum);
    printf("Número Real (double): %lf\n", doubleNum);
    doubleToBinary(doubleNum);
    printf("\n");

    return 0;
}
