#ifndef ALUNOSDAESCOLA_H
#define ALUNOSDAESCOLA_H

#include <stdio.h>
#include <stdlib.h>

//Definições

#define TAMANHO_DOS_NOMES 100

//structs

typedef struct Alunos {
    char *nomeAluno;
    int idadeAluno;
    int matriculaAluno;
    float notasAluno;
    struct Alunos *proxAluno; // Ponteiro para o próximo aluno na lista
} Alunos;

extern Alunos *prt_aluno;

enum {
    OP_NAO_SELECIONADA = 0,
    OP_ADICIONAR_ALUNO,
    OP_IMPRIMIR_ALUNO,
    OP_SAIR
};

void criarAlunos();
void imprimirAlunos ();
void freeMemory();
int menu();

#endif // ALUNOSDAESCOLA_H
