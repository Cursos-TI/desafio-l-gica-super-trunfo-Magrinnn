#include <stdio.h>
#include <string.h>

#define MAX 50  // Definir tamanho máximo para strings

// Estrutura para armazenar os dados da cidade
typedef struct {
    char cidade[MAX];
    char estado[MAX];
    char codigo[MAX];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *c) {
    printf("\n--- Cadastro de Carta ---\n");
    printf("Nome da cidade: ");
    scanf(" %[^\n]", c->cidade);
    printf("Estado: ");
    scanf(" %[^\n]", c->estado);
    printf("Código da carta: ");
    scanf(" %[^\n]", c->codigo);
    printf("População: ");
    scanf("%d", &c->populacao);
    printf("Área (km²): ");
    scanf("%f", &c->area);
    printf("PIB (milhões): ");
    scanf("%f", &c->pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &c->pontos_turisticos);
}

// Função para comparar atributos de duas cartas
Carta* compararCartas(Carta *c1, Carta *c2, char atributo[]) {
    printf("\nComparando '%s' entre %s e %s...\n", atributo, c1->cidade, c2->cidade);
    
    if (strcmp(atributo, "populacao") == 0) {
        return (c1->populacao > c2->populacao) ? c1 : (c1->populacao < c2->populacao ? c2 : NULL);
    }
    else if (strcmp(atributo, "area") == 0) {
        return (c1->area > c2->area) ? c1 : (c1->area < c2->area ? c2 : NULL);
    }
    else if (strcmp(atributo, "pib") == 0) {
        return (c1->pib > c2->pib) ? c1 : (c1->pib < c2->pib ? c2 : NULL);
    }
    else if (strcmp(atributo, "pontos_turisticos") == 0) {
        return (c1->pontos_turisticos > c2->pontos_turisticos) ? c1 : (c1->pontos_turisticos < c2->pontos_turisticos ? c2 : NULL);
    }
    else if (strcmp(atributo, "densidade_populacional") == 0) {
        float densidade1 = c1->populacao / c1->area;
        float densidade2 = c2->populacao / c2->area;
        return (densidade1 < densidade2) ? c1 : (densidade1 > densidade2 ? c2 : NULL);
    }
    return NULL;  // Atributo inválido
}

int main() {
    Carta carta1, carta2;
    char atributo[MAX];

    printf("🏙️ Bem-vindo ao Jogo de Cartas de Cidades!\n");

    // Cadastro das cartas
    cadastrarCarta(&carta1);
    cadastrarCarta(&carta2);

    // Exibe as cartas cadastradas
    printf("\n--- Cartas Cadastradas ---\n");
    printf("Cidade 1: %s (%s) | Código: %s | População: %d | Área: %.2f | PIB: %.2f | Pontos Turísticos: %d\n", 
           carta1.cidade, carta1.estado, carta1.codigo, carta1.populacao, carta1.area, carta1.pib, carta1.pontos_turisticos);
    printf("Cidade 2: %s (%s) | Código: %s | População: %d | Área: %.2f | PIB: %.2f | Pontos Turísticos: %d\n", 
           carta2.cidade, carta2.estado, carta2.codigo, carta2.populacao, carta2.area, carta2.pib, carta2.pontos_turisticos);

    // Escolha do atributo para comparação
    printf("\nEscolha um atributo para comparar (populacao, area, pib, pontos_turisticos, densidade_populacional): ");
    scanf(" %[^\n]", atributo);

    // Realiza a comparação
    Carta *vencedor = compararCartas(&carta1, &carta2, atributo);

    // Exibe o resultado
    if (vencedor) {
        printf("\n🏆 A cidade vencedora é: %s (%s)!\n", vencedor->cidade, vencedor->estado);
    } else {
        printf("\n⚖️ Empate! Nenhuma cidade venceu.\n");
    }

    return 0;
}
