#include <stdio.h>
#include "AlunosDaEscola.h"

int main(void) {
    int opcao = OP_NAO_SELECIONADA;

    while (opcao != OP_SAIR) {
        opcao = menu();
        switch (opcao) {
            case OP_ADICIONAR_ALUNO:
                criarAlunos();
                break;
            case OP_IMPRIMIR_ALUNO:
                // Implemente a função para imprimir todos os alunos
                imprimirAlunos();
                break;
            case OP_SAIR:
                freeMemory();
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}
