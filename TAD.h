#ifndef TAD_H
#define TAD_H

#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 100
#define MAX_TAM 5

typedef struct {
    int elementos[TAM_MAX];
    int tamanho;
} ConjuntoDeInteiros;

void criarConjuntoVazio(ConjuntoDeInteiros *conjunto) {
    conjunto->tamanho = 0;
}

void inserirElemento(ConjuntoDeInteiros *conjunto, int elemento) {
    if (conjunto->tamanho < TAM_MAX) {
        conjunto->elementos[conjunto->tamanho++] = elemento;
    }
}

void removerElemento(ConjuntoDeInteiros *conjunto, int elemento) {
    int i, j;
    for (i = 0; i < conjunto->tamanho; i++) {
        if (conjunto->elementos[i] == elemento) {
            for (j = i; j < conjunto->tamanho - 1; j++) {
                conjunto->elementos[j] = conjunto->elementos[j + 1];
            }
            conjunto->tamanho--;
            break;
        }
    }
}

int pertenceConjunto(ConjuntoDeInteiros *conjunto, int elemento) {
    int i;
    for (i = 0; i < conjunto->tamanho; i++) {
        if (conjunto->elementos[i] == elemento) {
            return 1;
        }
    }
    return 0;
}

ConjuntoDeInteiros uniaoConjuntos(ConjuntoDeInteiros *conjunto1, ConjuntoDeInteiros *conjunto2) {
    ConjuntoDeInteiros resultado;
    criarConjuntoVazio(&resultado);

    int i;
    for (i = 0; i < conjunto1->tamanho; i++) {
        inserirElemento(&resultado, conjunto1->elementos[i]);
    }

    for (i = 0; i < conjunto2->tamanho; i++) {
        inserirElemento(&resultado, conjunto2->elementos[i]);
    }

    return resultado;
}

ConjuntoDeInteiros intersecaoConjuntos(ConjuntoDeInteiros *conjunto1, ConjuntoDeInteiros *conjunto2) {
    ConjuntoDeInteiros resultado;
    criarConjuntoVazio(&resultado);

    int i;
    for (i = 0; i < conjunto1->tamanho; i++) {
        if (pertenceConjunto(conjunto2, conjunto1->elementos[i])) {
            inserirElemento(&resultado, conjunto1->elementos[i]);
        }
    }

    return resultado;
}

int saoIguais(ConjuntoDeInteiros *conjunto1, ConjuntoDeInteiros *conjunto2) {
    if (conjunto1->tamanho != conjunto2->tamanho) {
        return 0; 
    }

    int i;
    for (i = 0; i < conjunto1->tamanho; i++) {
        if (!pertenceConjunto(conjunto2, conjunto1->elementos[i])) {
            return 0; 
        }
    }

    return 1; 
}

int menorValor(ConjuntoDeInteiros *conjunto) {
    if (conjunto->tamanho == 0) {
        return -1;
    }

    int menor = conjunto->elementos[0];
    int i;
    for (i = 1; i < conjunto->tamanho; i++) {
        if (conjunto->elementos[i] < menor) {
            menor = conjunto->elementos[i];
        }
    }

    return menor;
}

int maiorValor(ConjuntoDeInteiros *conjunto) {
    if (conjunto->tamanho == 0) {
        return -1;
    }

    int maior = conjunto->elementos[0];
    int i;
    for (i = 1; i < conjunto->tamanho; i++) {
        if (conjunto->elementos[i] > maior) {
            maior = conjunto->elementos[i];
        }
    }

    return maior;
}

ConjuntoDeInteiros diferencaConjuntos(ConjuntoDeInteiros *conjunto1, ConjuntoDeInteiros *conjunto2) {
    ConjuntoDeInteiros resultado;
    criarConjuntoVazio(&resultado);

    int i;
    for (i = 0; i < conjunto1->tamanho; i++) {
        if (!pertenceConjunto(conjunto2, conjunto1->elementos[i])) {
            inserirElemento(&resultado, conjunto1->elementos[i]);
        }
    }

    return resultado;
}

int conjuntoVazio(ConjuntoDeInteiros *conjunto) {
    return (conjunto->tamanho == 0);
}

int tamanhoConjunto(ConjuntoDeInteiros *conjunto) {
    return conjunto->tamanho;
}

#endif