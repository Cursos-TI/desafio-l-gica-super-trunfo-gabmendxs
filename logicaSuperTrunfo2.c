#include <stdio.h>

int main() {
    // Carta 1 - São Paulo
    char estado1 = 'A';
    char codigo1[4] = "A01";
    char nomeCidade1[50] = "São Paulo";
    unsigned long int populacao1 = 12325000;
    float area1 = 1521.11;
    float pib1 = 699.28; // em bilhões de reais
    int pontosTuristicos1 = 50;

    // Carta 2 - Rio de Janeiro
    char estado2 = 'B';
    char codigo2[4] = "B02";
    char nomeCidade2[50] = "Rio de Janeiro";
    unsigned long int populacao2 = 6748000;
    float area2 = 1200.25;
    float pib2 = 300.50; // em bilhões de reais
    int pontosTuristicos2 = 30;

    // Cálculos
    float densidade1 = (float)populacao1 / area1;
    float densidade2 = (float)populacao2 / area2;

    // Menu interativo
    int opcao;
    printf("\n===== SUPER TRUNFO =====\n");
    printf("Escolha um atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - Nome do Pais (apenas exibe)\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);

    printf("\nComparando %s (Carta 1) x %s (Carta 2)\n", nomeCidade1, nomeCidade2);

    switch (opcao) {
        case 1: // População
            printf("Atributo escolhido: Populacao\n");
            printf("%s: %lu habitantes\n", nomeCidade1, populacao1);
            printf("%s: %lu habitantes\n", nomeCidade2, populacao2);

            if (populacao1 > populacao2)
                printf("Resultado: %s venceu!\n", nomeCidade1);
            else if (populacao2 > populacao1)
                printf("Resultado: %s venceu!\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 2: // Área
            printf("Atributo escolhido: Area\n");
            printf("%s: %.2f km²\n", nomeCidade1, area1);
            printf("%s: %.2f km²\n", nomeCidade2, area2);

            if (area1 > area2)
                printf("Resultado: %s venceu!\n", nomeCidade1);
            else if (area2 > area1)
                printf("Resultado: %s venceu!\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 3: // PIB
            printf("Atributo escolhido: PIB\n");
            printf("%s: %.2f bilhões R$\n", nomeCidade1, pib1);
            printf("%s: %.2f bilhões R$\n", nomeCidade2, pib2);

            if (pib1 > pib2)
                printf("Resultado: %s venceu!\n", nomeCidade1);
            else if (pib2 > pib1)
                printf("Resultado: %s venceu!\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 4: // Pontos Turísticos
            printf("Atributo escolhido: Pontos Turisticos\n");
            printf("%s: %d pontos\n", nomeCidade1, pontosTuristicos1);
            printf("%s: %d pontos\n", nomeCidade2, pontosTuristicos2);

            if (pontosTuristicos1 > pontosTuristicos2)
                printf("Resultado: %s venceu!\n", nomeCidade1);
            else if (pontosTuristicos2 > pontosTuristicos1)
                printf("Resultado: %s venceu!\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 5: // Densidade Demográfica (menor vence)
            printf("Atributo escolhido: Densidade Populacional\n");
            printf("%s: %.2f hab/km²\n", nomeCidade1, densidade1);
            printf("%s: %.2f hab/km²\n", nomeCidade2, densidade2);

            if (densidade1 < densidade2)
                printf("Resultado: %s venceu!\n", nomeCidade1);
            else if (densidade2 < densidade1)
                printf("Resultado: %s venceu!\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 6: // Nome apenas exibe
            printf("Nomes dos paises:\n");
            printf("Carta 1: %s\n", nomeCidade1);
            printf("Carta 2: %s\n", nomeCidade2);
            printf("Nao ha comparacao neste atributo.\n");
            break;

        default:
            printf("Opcao invalida! Escolha um numero entre 1 e 6.\n");
    }

    return 0;
}