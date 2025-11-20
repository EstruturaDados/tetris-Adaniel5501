#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura da peca
typedef struct {
    char nome; // I, O, T, L
    int id;    // identificador unico
} Peca;

// Funcoes
void mostrarFila(Peca fila[], int tamanho, int inicio, int quantidade);
Peca gerarPeca(int id);
void enqueue(Peca fila[], int *fim, int *quantidade, int tamanho, int *idGlobal);
void dequeue(Peca fila[], int *inicio, int *quantidade, int tamanho);

int main() {

    int tamanho = 5;
    Peca fila[5];
    int inicio = 0;
    int fim = 0;
    int quantidade = 0;
    int idGlobal = 0;
    int opcao;

    srand(time(NULL)); // aleatoriedade

    // Inicializando a fila com 5 pecas
    for(int i = 0; i < tamanho; i++) {
        fila[fim] = gerarPeca(idGlobal);
        idGlobal++;
        quantidade++;
        fim = (fim + 1) % tamanho;
    }

    do {
        printf("\n=== Fila de Pecas ===\n");
        mostrarFila(fila, tamanho, inicio, quantidade);

        printf("\nOpcoes:\n");
        printf("1 - Jogar peca (dequeue)\n");
        printf("2 - Inserir nova peca (enqueue)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            dequeue(fila, &inicio, &quantidade, tamanho);
        }
        else if (opcao == 2) {
            enqueue(fila, &fim, &quantidade, tamanho, &idGlobal);
        }

    } while (opcao != 0);

    printf("\nPrograma encerrado.\n");

    return 0;
}

// ---------------------------------------------------------
// Mostrar a fila
// ---------------------------------------------------------
void mostrarFila(Peca fila[], int tamanho, int inicio, int quantidade) {

    // Se quantidade for zero, fila esta vazia
    if (quantidade == 0) {
        printf("[Fila vazia]\n");
        return;
    }

    int pos = inicio;

    for (int i = 0; i < quantidade; i++) {
        printf("[%c %d] ", fila[pos].nome, fila[pos].id);
        pos = (pos + 1) % tamanho;
    }

    printf("\n");
}

// ---------------------------------------------------------
// Gerar uma nova peca
// ---------------------------------------------------------
Peca gerarPeca(int id) {
    char tipos[4] = {'I', 'O', 'T', 'L'};
    Peca nova;

    nova.nome = tipos[rand() % 4];
    nova.id = id;

    return nova;
}

// ---------------------------------------------------------
// Inserir nova peca (enqueue)
// ---------------------------------------------------------
void enqueue(Peca fila[], int *fim, int *quantidade, int tamanho, int *idGlobal) {

    if (*quantidade == tamanho) {
        printf("Fila cheia. Nao e possivel inserir.\n");
        return;
    }

    fila[*fim] = gerarPeca(*idGlobal);
    (*idGlobal)++;

    *fim = (*fim + 1) % tamanho;
    (*quantidade)++;

    printf("Peca inserida com sucesso!\n");
}

// ---------------------------------------------------------
// Remover peca (dequeue)
// ---------------------------------------------------------
void dequeue(Peca fila[], int *inicio, int *quantidade, int tamanho) {

    if (*quantidade == 0) {
        printf("Fila vazia. Nao ha pecas para jogar.\n");
        return;
    }

    printf("Peca [%c %d] jogada!\n", fila[*inicio].nome, fila[*inicio].id);

    *inicio = (*inicio + 1) % tamanho;
    (*quantidade)--;
}
