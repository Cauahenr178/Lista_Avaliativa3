#include <stdio.h>
#include <string.h>

int obterValor(char romano);

void decimalParaBinario(int numDecimal) {
    if (numDecimal > 1) {
        decimalParaBinario(numDecimal / 2);
 }
    printf("%d", numDecimal % 2);
}

int romanoParaDecimal(char numRomano[]) {
    int numDecimal = 0;
    int i;

    for (i = 0; i < strlen(numRomano); i++) {
        if (i < strlen(numRomano) - 1 && obterValor(numRomano[i]) < obterValor(numRomano[i + 1])) {
            numDecimal -= obterValor(numRomano[i]);
        } else {
            numDecimal += obterValor(numRomano[i]);
        }
 }

    return numDecimal;
}

int main() {
    char numRomano[13];
    scanf("%s", numRomano);

    int numDecimal = romanoParaDecimal(numRomano);

    printf("%s na base 2: ", numRomano);
    
    decimalParaBinario(numDecimal);
    if (numDecimal == 0) {
        printf("0");
    }
    printf("\n");

    printf("%s na base 10: %d\n", numRomano, numDecimal);
     printf("%s na base 16: %x\n", numRomano, numDecimal);

    return 0;
}

int obterValor(char romano) {
    switch (romano) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
 }

}
