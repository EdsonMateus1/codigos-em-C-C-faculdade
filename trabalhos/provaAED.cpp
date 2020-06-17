//EDSON MATEUS ALVES DE OLIVEIRA TURNO : NOITE CIENCIAS DA COMPUTACAO

/*
1. Escreva um programa em C que simule o histórico de navegação de um browser. Seu programa deve
conter as seguintes funcionalidades:
a. Abre o navegador (100 pts)
i. O usuário abre o navegador, considerando que o histórico está limpo.
b. Acessa site (300 pts)
i. O usuário acessa um site que deseja.
c. Exclui acesso (200 pts)
i. O usuário exclui um site acessado.
d. Acessa histórico (300 pts)
i. Imprime o histórico de acessos até então.
e. Fecha o navegador (100 pts)
i. Finaliza o acesso, mas antes zera o histórico de acessos.
Observações:
a. Cada item acima deve ser implementado em uma ou mais funções.
b. O programa deve ter um menu inicial que contenha essas funções.
c. O programa deve ficar em loop, apenas permitindo a finalização caso o usuário escolha a opção de
encerrar.
d. A impressão do histórico deve conter, para cada item:
a. Código interno, como uma chave primária
b. Hora e minuto e acesso no formato HH:MM
c. Endereço do site acessado
d. Título do site acessado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct historicoBrowser
{
    int codigo;
    char address[50];
    char title_Site[30];
    int hora;
    int minuto;
    struct historicoBrowser *prox;
    struct historicoBrowser *ant;
} Historico;

int chavePrimaria = 0;

int imprimeMenu();
int browser_access();
void EntrarNosite(Historico **list);
void exibir_historico(Historico *list);
int removerSite(Historico **lista);
void remTotal(Historico **list);

int main()
{

    Historico *list = NULL;
    int opcao = 0;
    do
    {
        printf("1_Acessar navegador:\n");
        printf("2_Encerra programa:\n");
        scanf("%d", &opcao);
        if (opcao == 1)
        {
            do
            {
                opcao = browser_access();
                switch (opcao)
                {
                case 1:
                {
                    EntrarNosite(&list);
                    break;
                }

                case 2:
                {
                    exibir_historico(list);
                    removerSite(&list);
                    break;
                }
                case 3:
                {
                    exibir_historico(list);
                    break;
                }
                case 4:
                {
                    printf("fechando navegador....seu historico sera excluido\n");
                    if (list != NULL)
                    {
                        remTotal(&list);
                    }
                    break;
                }
                }
            } while (opcao != 4);
        }

    } while (opcao != 2);
    system("PAUSE");
    return 0;
}

void EntrarNosite(Historico **lista)
{
    Historico *novo = (Historico *)malloc(sizeof(Historico));

    if (novo != NULL)
    {
        struct tm *data_hora_atual;
        time_t segundos;
        time(&segundos);
        data_hora_atual = localtime(&segundos);

        novo->codigo = chavePrimaria;
        novo->hora = data_hora_atual->tm_hour;
        novo->minuto = data_hora_atual->tm_min;

        printf("Endereco do site.: ");
        scanf("%s", &novo->address);
        printf("Titulo do site..: ");
        scanf("%s", &novo->title_Site);

        if (*lista == NULL)
        {
            *lista = novo;
            novo->prox = NULL;
            novo->ant = NULL;
        }
        else
        {
            novo->prox = *lista;
            novo->ant = NULL;
            (*lista)->ant = novo;
            *lista = novo;
        }
        chavePrimaria++;
    }
    return;
};

void exibir_historico(Historico *list)
{
    printf("\n\n");
    if (list == NULL)
    {
        printf("Historico vazio..!\n");
    }
    while (list)

    {
        printf("\n");
        printf("codigo...: %d\n", list->codigo);
        printf("Horas de acesso...: %d:%d \n", list->hora, list->minuto);
        printf("Endereco do site...: %s\n", list->address);
        printf("Titulo do site...: %s\n", list->title_Site);
        list = list->prox;
    }
    printf("\n");
    return;
}

int removerSite(Historico **lista)
{
    int codigo;
    if (*lista == NULL)
    {
        printf("imposivel remover historico vazio\n");
    }

    else
    {
        printf("Informe o codigo do site a ser removido: ");
        scanf("%d", &codigo);

        if (((*lista)->codigo == codigo) && ((*lista)->prox == NULL))
        {
            free(*lista);
            *lista = NULL;
            return codigo;
        }

        Historico *temp = (*lista);

        if (temp->codigo == codigo)
        {
            (temp->prox)->ant = NULL;
            (*lista) = (*lista)->prox;
            free(temp);
            return codigo;
        }

        while (temp->prox)
        {
            if (temp->codigo == codigo)
            {
                (temp->prox)->ant = temp->ant;
                (temp->ant)->prox = temp->prox;
                free(temp);
                return codigo;
            }
            temp = temp->prox;
        }

        if (temp->codigo == codigo)
        {
            (temp->ant)->prox = NULL;
            free(temp);
            return codigo;
        }
    }
    return 0;
}

void remTotal(Historico **list)
{
    Historico *aux = *list;
    if (aux != NULL)
    {
        Historico *p = aux;
        Historico *q = p;
        p = q->prox;
        free(q);
    }
    free(aux);
    *list = NULL;
}

int browser_access()
{
    int opcao;
    do
    {
        printf("\n\n");
        printf("Escolha uma das opcoes abaixo:\n\n");
        printf("1 - Acessar um site\n");
        printf("2 - remover um site do  historico\n");
        printf("3 - Exibir historico de navegacao \n");
        printf("4 - Fechar navegador...seu historico sera excluido\n");
        printf("\nSua opcao: ");
        scanf("%d", &opcao);
        if (opcao < 1 || opcao > 4)
        {
            printf("Opcao invalida!\n");
        }
    } while (opcao < 1 || opcao > 4);
    return opcao;
}
