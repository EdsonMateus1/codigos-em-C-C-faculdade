// EDSON MATEUS ALVES DE OLIVEIRA  TURNO NOITE : CIENCIAS DA COMPUTACAO

/*
1. Escreva um programa em C que simule uma fila dinâmica para atendimento de pessoas em uma clínica.
Seu programa deve conter as seguintes funcionalidades:
a. Recebe paciente OK
i. O paciente que chega à clínica deve ser recebido e inserido na fila de espera.
b. Desistência 
                             ATECAO PROFESSOR
    nessa questao nao conseguir imprementar a funcao,por que se o paciente estiver no final da fila ou no meio nao tem como remove-lo,ja que na fila a remocao e feita no inicio.
i. **O paciente prefere voltar em outro dia ou horário e sai da fila de espera.**                                                                                    
c. Atendimento***
i. Chama o próximo cliente da fila para o atendimento. OK
d. Status da fila OK
i. Retorna o tamanho atual da fila, quantos pacientes são homens, quantos são mulheres,
quantos possuem plano de saúde e quantos não possuem e a média de idade. OK
e. Imprime a fila OK
i. Imprime a fila com as seguintes informações: posição na fila, nome e número da carteirinha. OK
f. Zera a fila  OK
i. Se por algum motivo, for necessário cancelar todos os atendimentos do dia, essa função deverá
ser chamada, liberando todos os pacientes que estão na fila.
Observações: OK
a. Cada item acima deve ser uma função.
b. O programa deve ter um menu inicial que contenha essas funções.
c. O programa deve ficar em loop, apenas permitindo a finalização caso o usuário escolha a opção de
encerrar.
d. Um paciente tem nome, número da carteirinha do plano de saúde (caso houver), sexo e idade.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct cadastro
{
    char nome[50];
    int idade;
    char sexo;
    int carteira_plano;
    char nome_Plano[50];
    struct cadastro *prox;
} Cadastro;

int tam = 0;
int QuantiPlano = 0;
int coutSexo_m = 0;
int coutSexo_f = 0;

void entrada(Cadastro **inicio, Cadastro **fim);
void imprime(Cadastro *inicio);
void statusDaFila(Cadastro *inicio, Cadastro *fim);
void chamada_De_Paciente(Cadastro **inicio, Cadastro **fim);
void apagar_toda_fila(Cadastro **inicio, Cadastro **fim);

int main()
{
    Cadastro *inicio = NULL;
    Cadastro *fim = NULL;
    int opcao;

    do
    {
        opcao = imprimeMenu();
        switch (opcao)
        {
        case 1:
        {

            entrada(&inicio, &fim);
            break;
        }
        case 2:
        {
            imprime(inicio);
            break;
        }
        case 3:
        {
            statusDaFila(inicio, fim);
            break;
        }
        case 4:
        {
            chamada_De_Paciente(&inicio, &fim);
            break;
        }
        case 5:
        {
            apagar_toda_fila(&inicio, &fim);
            break;
        }
        case 6:
        {
            printf("O programa sera encerrado...\n\n");
            break;
        }
        }
    } while (opcao != 6);
    system("PAUSE");
    return 0;
};
void entrada(Cadastro **inicio, Cadastro **fim)
{
    Cadastro *novo = (Cadastro *)malloc(sizeof(Cadastro));
    if (novo)
    {
        char s;
        printf("Voce pussui plano de saude S/N?\n");
        scanf("%s", &s);

        if ((s == 'S') || (s == 's'))
        {
            char c;
            printf("Qual o nome do seu plano de saude?\n");
            scanf("%s", &novo->nome_Plano);
            printf("Qual o numero da sua carteirinha do plano de saude?\n");
            scanf("%d", &novo->carteira_plano);

            printf("Qual e seu nome?\n");
            scanf("%s", &novo->nome);
            printf("Qual e a sua idade?\n");
            scanf("%d", &novo->idade);
            QuantiPlano++;

            printf("Qual e o seu sexo M/F\n");
            scanf("%s", &c);
            if (c == 'M' || c == 'm')
            {
                novo->sexo = "M";
                coutSexo_m++;
            }
            else if (c == 'F' || c == 'f')
            {
                novo->sexo = "F";
                coutSexo_f++;
            }

            novo->prox = NULL;
            if (!(*inicio) && !(*fim))
            {

                *inicio = novo;
                *fim = novo;
            }
            else
            {
                (*fim)->prox = novo;
                *fim = novo;
            }

            printf("Aguarde na fila voce foi inserido com sucesso\n");
            tam++;
        }

        else if ((s == 'N') || (s == 'n'))
        {
            char c;
            novo->carteira_plano = 000;
            char nome_Plano = novo->nome_Plano;
            nome_Plano = "nao possui plano";

            printf("Qual e seu nome?\n");
            scanf("%s", &novo->nome);
            printf("Qual e a sua idade?\n");
            scanf("%d", &novo->idade);

            printf("Qual e o seu sexo M/F\n");
            scanf("%s", &c);
            if (c == 'M' || c == 'm')
            {
                novo->sexo = "M";
                coutSexo_m++;
            }
            else if (c == 'F' || c == 'f')
            {
                novo->sexo = "F";
                coutSexo_f++;
            }

            novo->prox = NULL;
            if (!(*inicio) && !(*fim))
            {
                *inicio = novo;
                *fim = novo;
            }
            else
            {
                (*fim)->prox = novo;
                *fim = novo;
            }
            printf("Aguarde na fila voce foi inserido com sucesso\n");
            tam++;
        }
    }
    return;
};

int imprimeMenu()
{
    int opcao;
    do
    {
        printf("\n\n");
        printf("Escolha uma das opcoes abaixo:\n\n");
        printf("1 - Inserir paciente\n");
        printf("2 - Consultar fila (IMPRIMIR)\n");
        printf("3 - Detalhes da fila (STATUS) \n");
        printf("4 - Chamar um paciente do inicio da fila\n");
        printf("5 - Apagar toda fila ... isso poderar encerrar as operacoes do sistema \n");
        printf("6 - Sair\n");
        printf("\nSua opcao: ");
        scanf("%d", &opcao);
        if (opcao < 1 || opcao > 6)
            printf("Opcao invalida!\n");
    } while (opcao < 1 || opcao > 6);
    return opcao;
};

void statusDaFila(Cadastro *inicio, Cadastro *fim)
{
    if (inicio == NULL)
    {
        printf("Fila vazia todos os detalhes estao zerados..!\n");
    }
    else
    {
        int r = 0;
        printf("\n");
        printf("Tamanho da fila : %d\n", tam);
        printf("Quantidade de pessoas com plano de saude  : %d\n", QuantiPlano);
        printf("Quantidade de pessoas que nao possuem plano de saude  : %d\n", r = QuantiPlano - tam);
        printf("Quantidade de pessoas do sexo Masculino  :%d\n", coutSexo_m);
        printf("Quantidade de pessoas do sexo Feminino   :%d\n", coutSexo_f);
        Cadastro *aux = inicio;
        int idade_Total = 0;
    
        while (aux)
        {
            idade_Total += aux->idade;
            aux = aux->prox;
        }
        printf("A media de idades dos pacientes %d", idade_Total / tam);
    }
};

void imprime(Cadastro *inicio)
{
    if (inicio == NULL)
    {
        printf("Fila vazia!...impossivel realizar consulta..!\n");
    }
    else
    {
        printf("\n");
        int pos = 1;
        Cadastro *aux = inicio;
        while (aux)
        {
            printf("\n");
            printf("Posicao : %d\n", pos);
            printf("Nome :%s\n", aux->nome);
            printf("numero da carteirinha :%d\n", aux->carteira_plano);
            pos++;
            aux = aux->prox;
        }
    }
    return;
};

void chamada_De_Paciente(Cadastro **inicio, Cadastro **fim)
{
    printf("\n");
    if (!(*inicio) && !(*fim))
    {
        printf("Fila vazia. Impossivel chamar paciente!\n");
        return;
    }
    Cadastro *aux = *inicio;
    if (*inicio == *fim)
    {
        *inicio = NULL;
        *fim = NULL;
        free(aux);
        tam--;
        printf("..Primeiro paciente foi chamado,com isso foi removido da fila de espera..!\n");
        return;
    }
    else
    {
        *inicio = (*inicio)->prox;
        free(aux);
        tam--;
        printf("..Primeiro paciente foi chamado,com isso foi removido da fila de espera..!\n");
        return;
    }
};

void apagar_toda_fila(Cadastro **inicio, Cadastro **fim)
{
    if ((*inicio) == NULL)
    {
        printf("fila vazia impossivel apagar \n");
    }
    else
    {
        for (int i = 0; i <= tam; i++)
        {
            chamada_De_Paciente(&inicio, &fim);
            tam--;
        }
        printf("..Fila deletada do sistema..!\n");
    }
}
