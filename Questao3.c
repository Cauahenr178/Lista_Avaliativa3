#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char placa[10];
    char dia[20];
    char dia_minusculo[20];
    int validar_placa = 0;
    int validar_dia = 0;
    char *dias_validos[7] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};
    
    scanf("%s", placa);
    scanf("%s", dia);
    placa[strcspn(placa, "\n")] = '\0';
    dia[strcspn(dia, "\n")] = '\0';

    for (int i = 0; i < 7; i++) {
        if(strcmp(dia, dias_validos[i]) == 0) {
            validar_dia = 1;
     }
   }

    int tam_placa = strlen(placa);
    char ultimo_caractere = placa[tam_placa - 1];

    if (((tam_placa == 8) && (placa[3] == '-'))) {
        validar_placa = 1;
    } else {
        if (((tam_placa == 7) && (isdigit(placa[3])))) {
            validar_placa = 1;
            for (int i = 0; i < tam_placa; i++) {
                if (placa[i] == '-') {
                    validar_placa = 0;
                    break;
            }
        }
      }
    }

    int index = 0;

    for (int o = 0; dia[o] != '\0'; o++) {
        dia_minusculo[o] = tolower(dia[o]);
        index++;
     }
    dia_minusculo[index + 1] = '\0';

    if ((validar_dia == 0) && (validar_placa == 0)) {
        printf("Placa invalida\n");
        printf("Dia da semana invalido\n");
    } else if ((validar_dia == 1) && (validar_placa == 0)) {
        printf("Placa invalida\n");
    } else if ((validar_dia == 0) && (validar_placa == 1)) {
        printf("Dia da semana invalido\n");
    } else if ((validar_dia == 1) && (validar_placa == 1)) {
        if (strcmp(dia, "SABADO") == 0 || strcmp(dia, "DOMINGO") == 0) {
            printf("Nao ha proibicao no fim de semana\n");
        } else if ((strcmp(dia, "SEGUNDA-FEIRA") == 0 && (ultimo_caractere == '0' || ultimo_caractere == '1')) ||
                   (strcmp(dia, "TERCA-FEIRA") == 0 && (ultimo_caractere == '2' || ultimo_caractere == '3')) ||
                   (strcmp(dia, "QUARTA-FEIRA") == 0 && (ultimo_caractere == '4' || ultimo_caractere == '5')) ||
                   (strcmp(dia, "QUINTA-FEIRA") == 0 && (ultimo_caractere == '6' || ultimo_caractere == '7')) ||
                   (strcmp(dia, "SEXTA-FEIRA") == 0 && (ultimo_caractere == '8' || ultimo_caractere == '9'))) {
             printf("%s nao pode circular %s\n", placa, dia_minusculo);
        } else {
              printf("%s pode circular %s\n", placa, dia_minusculo);
      }
  }
    return 0;
}
