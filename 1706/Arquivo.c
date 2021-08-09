#include<string.h>
#include<math.h>
#include <locale.h>


typedef struct sAluno {
    char nome[50];   
    float notaFinal;
}ALUNO;

ALUNO* criarAluno(char *nome, float nota) {
    ALUNO* aluno = (ALUNO*) malloc(sizeof(ALUNO));
    if (aluno != NULL){
        strcpy(aluno->nome, nome);
        aluno->notaFinal = nota;
    }
    return aluno;
}


void deletarAluno(ALUNO* a) {
    free(a);
}


void acessarAluno(ALUNO* a, char *nome, float *n) {
    *n = a->notaFinal;
    strcpy(nome, a->nome);
}

void config(){
    setlocale(LC_ALL, "");
}

int main() {
    config();

    float n, notaTemp;
    ALUNO *a1, *a2;
    char nomeTemp[50];
    a1 = criarAluno("João", 10);
    a2 = criarAluno("Maria", 8);


    acessarAluno(a1, nomeTemp, &notaTemp);
    printf("Nome: %s\nNota: %f\n", nomeTemp, notaTemp);


    acessarAluno(a2, nomeTemp, &notaTemp);
    printf("Nome: %s\nNota: %f\n", a2->nome, a2->notaFinal);


    deletarAluno(a1);
    deletarAluno(a2);


    return 0;
}
