//Bruno Giordano Ono
//Rafael Costa Nascimento


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 20

typedef struct{
    char nome_alu[20];
    char materias[MAX][20];
    int RA, a_cadastrado, contador_materia;
}Alunos;
Alunos aluno[MAX];

typedef struct{
    char nome_prof[20];
    char materias[MAX][20];
    int p_cadastrado;
}Prof;
Prof prof[MAX];

typedef struct{
    char nome_mat[20];
    int m_cadastrado;
    char alunos_matriculados[MAX][20];
    char professor_vinculados[MAX][20];
}Mat;
Mat mat[MAX];

void cadastra_aluno()
{
    int qtd_alunos, i=0, j=0, RA, aux=0;
    char nome[10];

    system("cls");
    printf("Quantos alunos deseja cadastrar: ");
    scanf("%d",&qtd_alunos);

    for (j = 0; j < MAX; j++)
    {
        if (aluno[j].a_cadastrado==1)
        {
            aux++;
            qtd_alunos++;
        }
    }

    for (i = aux; i < qtd_alunos; i++)
    {
        if(aluno[i].a_cadastrado==0){
            printf("\nDigite o nome do aluno: ");
            fflush(stdin);
            gets(nome);
            printf("Informe seu RA: ");
            scanf("%d",&RA);

            strcpy(aluno[i].nome_alu , nome);
            aluno[i].RA=RA;
            aluno[i].contador_materia=0;
            aluno[i].a_cadastrado=1;
        }
    }
    system("pause");
}

void cadastra_professor()
{
    int qtd_prof, i=0, j, aux=0;
    char nome[10];

    system("cls");
    printf("Quantos professores deseja cadastrar: ");
    scanf("%d",&qtd_prof);

    for (j = 0; j < MAX; j++)
    {
        if (prof[j].p_cadastrado==1)
        {
            aux++;
        }
    }

    for (i = 0; i < qtd_prof; i++)
    {
        if(prof[i+aux].p_cadastrado==0){
            printf("Digite o nome do professor: ");
            fflush(stdin);
            gets(nome);

            strcpy(prof[i+aux].nome_prof , nome);
            prof[i+aux].p_cadastrado=1;
        }
    }
    system("pause");
}

void cadastra_materia()
{
    int qtd_materias, i=0, j, aux=0;
    char nome[10];

    system("cls");
    printf("Quantas materias deseja cadastrar: ");
    scanf("%d",&qtd_materias);

    for (j = 0; j < MAX; j++)
    {
        if (mat[j].m_cadastrado==1)
        {
            aux++;
        }
    }

    for (i = 0; i < qtd_materias; i++)
    {
        if(mat[i+aux].m_cadastrado==0)
        printf("Digite o nome da materia: ");
        fflush(stdin);
        gets(nome);

        strcpy(mat[i+aux].nome_mat, nome);
        mat[i+aux].m_cadastrado=1;
    }
    system("pause");
}

void matricula_aluno()
{
    int qnt_materias, qnt_alunos, i, j, k, l, m, existe=0, verificar=0;
    char nome_mat[MAX][15], aux[15];

    system("cls");
    printf("\nQuantas materias esses alunos serão matriculados: ");
    scanf("%d",&qnt_materias);

    printf("\nQuais materias: ");
    for (i=0; i<qnt_materias; i++)
    {
        do
        {
            printf("\n[%d]: ", i+1);
            fflush(stdin);
            gets(aux);

            for (k = 0; k < MAX; k++)
            {
                existe = strcmp(aux, mat[k].nome_mat);
                if (existe==0)
                {
                    strcpy(nome_mat[i], mat[k].nome_mat);
                    break;
                }
            }
            if(existe!=0)
            {
                printf("\nMateria não cadastrada!\n");
            }

        } while (existe!=0);
    }

    printf("\nQuantos alunos serão matriculados a essa(s) matéria(s): ");
    scanf("%d",&qnt_alunos);

    printf("\nDigite o nome do(s) aluno(s) que será(ão) matriculado(s): ");

    for (j=0; j<qnt_alunos; j++)
    {
        do
        {
            printf("\nDigite o nome do aluno: ");
            fflush(stdin);
            gets(aux);

            for (k = 0; k < MAX; k++)
            {
                existe = strcmp(aux, aluno[k].nome_alu);
                if (existe==0)
                {
                    for (l = 0; l < qnt_materias; l++)
                    {
                        for (m = 0; m < MAX; m++)
                        {
                            if (strcmp(aluno[k].materias[m],"NULL")==0)
                            {
                                strcpy(aluno[k].materias[m], nome_mat[l]);
                                break;
                            }
                        }

                        for (i = 0; i < MAX; i++)
                        {
                            verificar = strcmp(mat[i].nome_mat, nome_mat[l]);
                            if (verificar==0)
                            {
                                strcpy(mat[i].alunos_matriculados[k], aux);
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            if (existe!=0)
            {
                printf("\nAluno não identificado!\n");
            }
        } while (existe!=0);
    }
    system("pause");
}

void vincula_prof()
{
    int qnt_materias, qnt_professor, i, j, k, l, m, existe=0, verificar=0;
    char nome_mat[MAX][20], aux[20];

    system("cls");
    printf("\nQuantas materias esse(s) professor(es) será(ão) vinculado(s): ");
    scanf("%d",&qnt_materias);

    printf("\nQuais materias: ");
    for (i=0; i<qnt_materias; i++)
    {
        do
        {
            printf("\n[%d]: ", i+1);
            fflush(stdin);
            gets(aux);

            for(k=0; k<MAX; k++)
            {
                existe = strcmp(aux, mat[k].nome_mat);
                if(existe==0)
                {
                    strcpy(nome_mat[i], mat[k].nome_mat);
                    break;
                }
            }
            if(existe!=0)
            {
                printf("\nMateria não cadastrada!\n");
            }

        } while (existe!=0);

    }

    printf("\nQuantos professores serão vinculados a essa(s) matéria(s): ");
    scanf("%d",&qnt_professor);

    printf("\nDigite o nome do(s) professor(es) que será(ão) vinculado(s): ");

    for (j=0; j<qnt_professor; j++)
    {
        do
        {
            printf("\nDigite o nome do professor: ");
            fflush(stdin);
            gets(aux);

            for (k = 0; k < MAX; k++)
            {
                existe = strcmp(aux, prof[k].nome_prof);
                if(existe==0)
                {
                    for (l = 0; l < qnt_materias; l++)
                    {
                        for (m = 0; m < MAX; m++)
                        {
                                if (strcmp(prof[k].materias[m], "NULL")==0)
                                {
                                    strcpy(prof[k].materias[m], nome_mat[l]);
                                    break;
                                }
                        }

                        for (i = 0; i < MAX; i++)
                        {
                            verificar = strcmp(mat[i].nome_mat, nome_mat[l]);
                            if (verificar==0)
                            {
                                strcpy(mat[i].professor_vinculados[k], aux);
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            if (existe!=0)
            {
                printf("\nProfessor não identificado!\n");
            }
        } while (existe!=0);
    }
    system("pause");
}

void cancela_aluno()
{
    int qnt_alu, qnt_mat, i, k, j, l, m, existe=0, verificar=0;
    char nome_mat[MAX][15], aux[15];

    system("cls");
    printf("Quantas materias serão canceladas: ");
    scanf("%d",&qnt_mat);

    printf("Quais materias serão canceladas: ");
    for (i=0; i<qnt_mat; i++)
    {
        do
        {
            printf("\n[%d]: ", i+1);
            fflush(stdin);
            gets(aux);

            for(k = 0; k < MAX; k++)
            {
                existe = strcmp(aux, mat[k].nome_mat);
                if(existe==0)
                {
                    strcpy(nome_mat[i], mat[k].nome_mat);
                    break;
                }
            }
            if(existe!=0)
            {
                printf("\nMateria não cadastrada!\n");
            }
        } while (existe!=0);
    }

    printf("\nQuanto(s) aluno(s) será(ão) cancelado(s) dessa(s) matéria(s): ");
    scanf("%d",&qnt_alu);

    printf("\nDigite o nome dos alunos que terão suas matriculas canceladas: ");

    for (j=0; j<qnt_alu; j++)
    {
        do
        {
            printf("\nDigite o nome do aluno: ");
            fflush(stdin);
            gets(aux);

            for (k = 0; k < MAX; k++)
            {
                existe = strcmp(aux, aluno[k].nome_alu);
                if (existe==0)
                {
                    for (l = 0; l < qnt_mat; l++)
                    {
                        for (m = 0; m < MAX; m++)
                        {
                            if (strcmp(aluno[k].materias[m], nome_mat[l])==0)
                            {
                                strcpy(aluno[k].materias[m], "NULL");
                                break;
                            }
                        }

                        for ( i = 0; i < MAX; i++)
                        {
                            verificar = strcmp(mat[i].nome_mat, nome_mat[l]);
                            if (verificar==0)
                            {
                                strcpy(mat[i].alunos_matriculados[k], "NULL");
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            if (existe!=0)
            {
                printf("\nAluno não identificado!\n");
            }
        } while (existe!=0);
    }
    system("pause");
}

void cancela_professor()
{
    int qnt_prof, qnt_mat, i, k, j, l, m, existe=0, verificar=0;
    char nome_mat[MAX][20], aux[20];

    system("cls");
    printf("Quantas materias serão canceladas: ");
    scanf("%d",&qnt_mat);

    printf("Quais materias serão canceladas: ");
    for (i=0; i<qnt_mat; i++)
    {
        do
        {
            printf("\n[%d]: ", i+1);
            fflush(stdin);
            gets(aux);

            for(k = 0; k < MAX; k++)
            {
                existe = strcmp(aux, mat[k].nome_mat);
                if(existe==0)
                {
                    strcpy(nome_mat[i], mat[k].nome_mat);
                    break;
                }
            }
            if(existe!=0)
            {
                printf("\nMateria não cadastrada!\n");
            }
        } while (existe!=0);
    }

    printf("Quanto(s) professor(es) será(ão) cancelado(s) dessa(s) matéria(s): ");
    scanf("%d",&qnt_prof);

    printf("Digite o nome dos professores que terão suas matriculas canceladas: ");

    for (j=0; j<qnt_prof; j++)
    {
        do
        {
            printf("\nDigite o nome do professor: ");
            fflush(stdin);
            gets(aux);

            for (k = 0; k < MAX; k++)
            {
                existe = strcmp(aux, prof[k].nome_prof);
                if (existe==0)
                {
                    for (l = 0; l < qnt_mat; l++)
                    {
                        for (m = 0; m < MAX; m++)
                        {
                            if (strcmp(prof[k].materias[m], nome_mat[l])==0)
                            {
                                strcpy(prof[k].materias[l], "NULL");
                                break;
                            }
                        }

                        for (i = 0; i < MAX; i++)
                        {
                            verificar = strcmp(mat[i].nome_mat, nome_mat[l]);
                            if (verificar==0)
                            {
                                strcpy(mat[i].professor_vinculados[k], "NULL");
                            }
                        }
                    }
                    break;
                }
            }
            if (existe!=0)
            {
                printf("\nProfessor não identificado!\n");
            }
        } while (existe!=0);
    }
    system("pause");
}

void imp_alunos()
{
    int i=0;

    system("cls");
    printf("\tLista de Alunos\n");
    for(i=0; i<MAX;i++)
    {
        if(aluno[i].a_cadastrado==1){
            printf("Nome: %s\n", aluno[i].nome_alu);
            printf("RA: %d\n", aluno[i].RA);
        }

    }
    system("pause");
}




void imp_disciplinas()
{
    int i=0;

    system("cls");
    printf("\tLista de Disciplina\n");

    for(i=0; i<MAX;i++)
    {

        if(mat[i].m_cadastrado==1)
        {
            printf("Nome: %s\n", mat[i].nome_mat);
        }

    }
    system("pause");
}

void imp_professores()
{
    int i=0;

    system("cls");
    printf("\tLista de Professores\n");

    for(i=0; i<MAX;i++)
    {

        if(prof[i].p_cadastrado==1){
            printf("Nome: %s\n", prof[i].nome_prof);
        }

    }
    system("pause");
}

void imp_disciplinas_aluno()
{
    int i=0, j=0, existe;
    char nome_alu[15];

    system("cls");

    do
    {
        printf("Informe o aluno o qual deseja ver a(s) disciplina(s): ");
        fflush(stdin);
        gets(nome_alu);

        for (i = 0; i < MAX; i++)
        {
            existe = strcmp(aluno[i].nome_alu, nome_alu);

            if (existe==0)
            {
                printf("\nA(As) disciplina(s) desse aluno é(são): ");
                for (j = 0; j < MAX; j++)
                {
                    if(strcmp(aluno[i].materias[j], "NULL")!=0)
                    {
                        printf("\n%s\n", aluno[i].materias[j]);
                    }
                }
                break;
            }
        }
        if (existe!=0)
            {
                printf("\nAluno não identificado!\n");
            }
    }while (existe!=0);
    system("pause");
}

void imp_alunos_disciplina()
{
    int i=0, j=0, existe;
    char nome_dici[15];

    system("cls");

    do
    {
        printf("Informe a disciplina da qual deseja ver o(os) aluno(s) matriculado(s): ");
        fflush(stdin);
        gets(nome_dici);

        for (i = 0; i < MAX; i++)
        {
            existe = strcmp(mat[i].nome_mat, nome_dici);
            if (existe==0)
            {
                printf("\nO(Os) aluno(s) dessa disciplina é(são): ");
                for (j = 0; j < MAX; j++)
                {
                    if(strcmp(mat[i].alunos_matriculados[j], "NULL")!=0)
                    {
                        printf("\n%s\n", mat[i].alunos_matriculados[j]);
                    }
                }
            break;
            }
        }

        if (existe!=0)
            {
                printf("\nDisciplina não identificada!\n");
            }
    }while (existe!=0);
    system("pause");
}

void imp_disciplinas_professor()
{
   int i, j, existe;
   char nome_prof[15];

    system("cls");

    do
    {
        printf("Informe o professor o qual deseja ver a(s) disciplina(s): ");
        fflush(stdin);
        gets(nome_prof);

        for (i = 0; i < MAX; i++)
        {
            existe = strcmp(nome_prof, prof[i].nome_prof);
            if (existe==0)
            {
                printf("\nA(As) disciplina(s) desse professor é(são): ");
                for (j = 0; j < MAX; j++)
                {
                    if(strcmp(prof[i].materias[j], "NULL")!=0)
                    {
                        printf("\n%s\n", prof[i].materias[j]);
                    }
                }
            break;
            }
        }
        if (existe!=0)
            {
                printf("\nProfessor não identificado!\n");
            }
    }while (existe!=0);
    system("pause");
}

void imp_professores_disciplina()
{
    int i=0, j=0, existe;
    char nome_dici[15];

    system("cls");


    do
    {
        printf("Informe a disciplina o qual deseja ver o(os) professor(es) vinculado(s): ");
        fflush(stdin);
        gets(nome_dici);

        for (i = 0; i < MAX; i++)
        {
            existe = strcmp(mat[i].nome_mat, nome_dici);
            if (existe==0)
            {
                printf("\nO(Os) professor(es) dessa disciplina é(são): ");
                for (j = 0; j < MAX; j++)
                {
                    if(strcmp(mat[i].professor_vinculados[j], "NULL")!=0)
                    {
                    printf("\n%s\n", mat[i].professor_vinculados[j]);
                    }
                }
            break;
            }
        }

        if (existe!=0)
            {
                printf("\nDisciplina não identificada!\n");
            }
    }while (existe!=0);
    system("pause");
}

void menu_impressao()
{

	int op2;
do
{
    system("cls");
    printf("Menu de Impressões");
    printf("\n0.Voltar");
    printf("\n1.Imprimir lista de alunos");
    printf("\n2.Imprimir lista de professores");
    printf("\n3.Imprimir lista de materia");
    printf("\n4.Imprimir lista de materias de um aluno");
    printf("\n5.Imprimir lista de alunos em uma materia");
    printf("\n6.Imprimir lista de todas as materias ministradas por um professor");
    printf("\n7.Imprimir lista de professores vinculados a uma materia");

    printf("\n\nSelecione uma ação: ");
    scanf("%d",&op2);
        fflush(stdin);

        switch (op2)
        {
            case 1:
                imp_alunos();
            break;

            case 2:
                imp_professores();
            break;

            case 3:
                imp_disciplinas();
            break;

            case 4:
                imp_disciplinas_aluno();
            break;

            case 5:
                imp_alunos_disciplina();
            break;

            case 6:
                imp_disciplinas_professor();
            break;

            case 7:
                imp_professores_disciplina();
            break;
        }
    } while (op2!=0);
}

void menu()
{

   int op;

   do
   {
       system("cls");
        printf("Menu de Matricula");
        printf("\n0.Sair");
        printf("\n1.Cadastrar alunos");
        printf("\n2.Cadastrar professores");
        printf("\n3.Cadastrar materias");
        printf("\n4.Matricular alunos à uma materia");
        printf("\n5.Vincular professores à uma materia");
        printf("\n6.Cancelar matricula do aluno");
        printf("\n7.Cancelar matricula do professor");
        printf("\n8.Impressões");

        printf("\n\nSelecione uma ação: ");
        scanf("%d",&op);
        fflush(stdin);

        switch (op)
        {
            case 1:
                cadastra_aluno();
            break;

            case 2:
                cadastra_professor();
            break;

            case 3:
                cadastra_materia();
            break;

            case 4:
                matricula_aluno();
            break;

            case 5:
                vincula_prof();
            break;

            case 6:
                cancela_aluno();
            break;

            case 7:
                cancela_professor();
            break;

            case 8:
                menu_impressao();
            break;

        }

   } while (op!=0);

}

void zerar(Alunos aluno[], Prof prof[], Mat mat[])
{
    for (int i = 0; i < MAX; i++)
    {
        strcpy(aluno[i].nome_alu, "NULL");
        strcpy(prof[i].nome_prof, "NULL");
        strcpy(mat[i].nome_mat, "NULL");

        for (int j = 0; j < MAX; j++)
        {
            strcpy(aluno[i].materias[j], "NULL");
            strcpy(prof[i].materias[j], "NULL");
            strcpy(mat[i].alunos_matriculados[j], "NULL");
            strcpy(mat[i].professor_vinculados[j], "NULL");
        }

    }

}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    zerar(aluno, prof ,mat);
    menu();

    return 0;
}
