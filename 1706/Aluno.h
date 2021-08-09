typedef struct sAluno ALUNO;

ALUNO* criarAluno(char* nome, float n);

void deletarAluno(ALUNO* aluno);
void acessarAluno(ALUNO* aluno, char* nome, float *n);

 