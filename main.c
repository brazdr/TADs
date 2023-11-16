#include "TAD.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 100
#define MAX_TAM 5

int main() {
    ConjuntoDeInteiros conjunto1, conjunto2, conjuntoResultado;

    criarConjuntoVazio(&conjunto1);
    criarConjuntoVazio(&conjunto2);

    printf("Adicione elementos ao Conjunto 1 (limite: %d):\n", MAX_TAM);
    while (conjunto1.tamanho < MAX_TAM) {
        int elemento;
        printf("Elemento %d: ", conjunto1.tamanho + 1);
        scanf("%d", &elemento);
        inserirElemento(&conjunto1, elemento);
    }
    
    printf("Adicione elementos ao Conjunto 2 (limite: %d):\n", MAX_TAM);
    while (conjunto2.tamanho < MAX_TAM) {
        int elemento;
        printf("Elemento %d: ", conjunto2.tamanho + 1);
        scanf("%d", &elemento);
        inserirElemento(&conjunto2, elemento);
    }

    conjuntoResultado = uniaoConjuntos(&conjunto1, &conjunto2);
    printf("Uniao: ");
    for (int i = 0; i < conjuntoResultado.tamanho; i++) {
        printf("%d ", conjuntoResultado.elementos[i]);
    }
    printf("\n");

    conjuntoResultado = intersecaoConjuntos(&conjunto1, &conjunto2);
    printf("Intersecao: ");
    for (int i = 0; i < conjuntoResultado.tamanho; i++) {
        printf("%d ", conjuntoResultado.elementos[i]);
    }
    printf("\n");

    printf("Conjunto 1 %s igual a Conjunto 2\n", saoIguais(&conjunto1, &conjunto2) ? "e" : "nao e");

    removerElemento(&conjunto1, 1);
    printf("Pertence ao Conjunto 1: %s\n", pertenceConjunto(&conjunto1, 1) ? "Sim" : "Nao");

    printf("Menor valor do Conjunto 1: %d\n", menorValor(&conjunto1));
    printf("Menor valor do Conjunto 2: %d\n", menorValor(&conjunto2));
    printf("Maior valor do Conjunto 1: %d\n", maiorValor(&conjunto1));
    printf("Maior valor do Conjunto 2: %d\n", maiorValor(&conjunto2));

    conjuntoResultado = diferencaConjuntos(&conjunto1, &conjunto2);
    printf("Diferenca (Conjunto 1 - Conjunto 2): ");
    for (int i = 0; i < conjuntoResultado.tamanho; i++) {
        printf("%d ", conjuntoResultado.elementos[i]);
    }
    printf("\n");

    printf("Tamanho do Conjunto 1: %d\n", tamanhoConjunto(&conjunto1));
    printf("Tamanho do Conjunto 2: %d\n", tamanhoConjunto(&conjunto2));
    printf("O Conjunto 2 %s vazio\n", conjuntoVazio(&conjunto2) ? "e" : "nao e");

    return 0;
}
