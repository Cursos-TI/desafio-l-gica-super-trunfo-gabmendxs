#include <stdio.h>
#include <string.h>

// ==================== ESTRUTURA ====================
typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

// ==================== FUNÇÕES AUXILIARES ====================

// Densidade populacional
float calcularDensidade(Carta c) {
    return c.populacao / c.area;
}

// PIB per capita
float calcularPIBperCapita(Carta c) {
    return (c.pib * 1000000000.0) / c.populacao; 
}

// Função de comparação
// Retorna +1 se carta1 vence, -1 se carta2 vence, 0 se empate
int compara(float v1, float v2, int menorVence) {
    if (menorVence) {
        if (v1 < v2) return 1;
        else if (v2 < v1) return -1;
        else return 0;
    } else {
        if (v1 > v2) return 1;
        else if (v2 > v1) return -1;
        else return 0;
    }
}

// Mostrar atributos disponíveis
void mostrarMenu(int opcaoBloqueada) {
    printf("\nEscolha um atributo para comparar:\n");
    if (opcaoBloqueada != 1) printf("1 - População\n");
    if (opcaoBloqueada != 2) printf("2 - Área\n");
    if (opcaoBloqueada != 3) printf("3 - PIB\n");
    if (opcaoBloqueada != 4) printf("4 - Pontos Turísticos\n");
    if (opcaoBloqueada != 5) printf("5 - Densidade Populacional\n");
    if (opcaoBloqueada != 6) printf("6 - PIB per Capita\n");
    printf("Opção: ");
}

// Pegar valor do atributo
float getValor(Carta c, int opcao) {
    switch (opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return calcularDensidade(c);
        case 6: return calcularPIBperCapita(c);
        default: return 0;
    }
}

// Nome do atributo
const char* nomeAtributo(int opcao) {
    switch (opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per Capita";
        default: return "Desconhecido";
    }
}

// ==================== MAIN ====================
int main() {
    // Cartas pré-cadastradas (pode trocar os valores depois)
    Carta carta1 = {'A', "A01", "São Paulo", 12300000, 1521.0, 750.0, 20};
    Carta carta2 = {'B', "B02", "Rio de Janeiro", 6748000, 1200.0, 400.0, 15};

    int opcao1, opcao2;

    // Escolha do 1º atributo
    mostrarMenu(0);
    scanf("%d", &opcao1);

    // Escolha do 2º atributo (não pode repetir)
    mostrarMenu(opcao1);
    scanf("%d", &opcao2);

    // Pegando os valores para comparação
    float valor1_c1 = getValor(carta1, opcao1);
    float valor1_c2 = getValor(carta2, opcao1);

    float valor2_c1 = getValor(carta1, opcao2);
    float valor2_c2 = getValor(carta2, opcao2);

    // Comparando os dois atributos
    int resultado1 = compara(valor1_c1, valor1_c2, (opcao1 == 5));
    int resultado2 = compara(valor2_c1, valor2_c2, (opcao2 == 5));

    // Soma dos atributos
    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    // ==================== RESULTADO ====================
    printf("\n===== RESULTADO =====\n");
    printf("Carta 1: %s\n", carta1.nomeCidade);
    printf("Carta 2: %s\n", carta2.nomeCidade);

    printf("\nComparação do atributo %s:\n", nomeAtributo(opcao1));
    printf("%s: %.2f | %s: %.2f\n", carta1.nomeCidade, valor1_c1, carta2.nomeCidade, valor1_c2);

    printf("\nComparação do atributo %s:\n", nomeAtributo(opcao2));
    printf("%s: %.2f | %s: %.2f\n", carta1.nomeCidade, valor2_c1, carta2.nomeCidade, valor2_c2);

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f | %s: %.2f\n", carta1.nomeCidade, soma1, carta2.nomeCidade, soma2);

    if (soma1 > soma2) {
        printf("\n>>> %s venceu!\n", carta1.nomeCidade);
    } else if (soma2 > soma1) {
        printf("\n>>> %s venceu!\n", carta2.nomeCidade);
    } else {
        printf("\n>>> Empate!\n");
    }

    return 0;
}
