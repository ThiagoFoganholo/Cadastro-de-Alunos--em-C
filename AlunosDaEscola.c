#include "AlunosDaEscola.h"

Alunos *prt_aluno = NULL;

void criarAlunos() {
    Alunos *novoAluno = (Alunos *)malloc(sizeof(Alunos));

    if (novoAluno == NULL) {
        printf("Erro de alocacao de memoria!");
        exit(EXIT_FAILURE);
    }

    printf("Nome do Aluno: ");
    novoAluno->nomeAluno = (char *)malloc(TAMANHO_DOS_NOMES * sizeof(char));
    scanf("%s", novoAluno->nomeAluno);

    printf("Idade do Aluno: ");
    scanf("%d", &novoAluno->idadeAluno);

    printf("Matricula do aluno: ");
    scanf("%d", &novoAluno->matriculaAluno);

    printf("Notas do aluno: ");
    scanf("%f", &novoAluno->notasAluno);

    novoAluno->proxAluno = prt_aluno; // Aponta para o primeiro aluno da lista
    prt_aluno = novoAluno; // Atualiza o ponteiro para o novo aluno criado
}

int menu() {
    int op = OP_NAO_SELECIONADA;

    printf("Menu\n");
    printf("%d - Adicionar Aluno\n", OP_ADICIONAR_ALUNO);
    printf("%d - Imprimir todos os alunos\n", OP_IMPRIMIR_ALUNO);
    printf("%d - Sair\n", OP_SAIR);
    printf("Digite sua opcao: ");
    scanf("%d", &op);
    scanf("%*c");

    return op;
}
void imprimirAlunos() {
    Alunos *alunoAtual = prt_aluno;

    if (alunoAtual == NULL) {
        printf("\nNenhum cadastro realizado.\n");
        return;
    }

    printf("\nLista de Alunos:\n");
    while (alunoAtual != NULL) {
        printf("Nome: %s\n", alunoAtual->nomeAluno);
        printf("Idade: %d\n", alunoAtual->idadeAluno);
        printf("Matricula: %d\n", alunoAtual->matriculaAluno);
        printf("Notas: %.2f\n", alunoAtual->notasAluno);
        printf("\n");

        alunoAtual = alunoAtual->proxAluno; // Avança para o próximo aluno na lista
    }
}


void freeMemory(){
    Alunos *alunoAtual = prt_aluno;
    Alunos *proximoAluno = NULL;

    while (alunoAtual != NULL) {
        proximoAluno = alunoAtual->proxAluno; // Salva o próximo aluno antes de liberar a memória
        free(alunoAtual->nomeAluno); // Libera a memória alocada para o nome do aluno
        free(alunoAtual); // Libera a memória alocada para a estrutura Alunos
        alunoAtual = proximoAluno; // Avança para o próximo aluno na lista
    }
    prt_aluno = NULL; // Define o ponteiro para o primeiro aluno como NULL
}
