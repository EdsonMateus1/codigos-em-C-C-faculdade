// EDSON MATEUS ALVES DE OLIVEIRA

#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef struct rom
{
    string title;
    string genre;
    int lacquerYear = 0;
    string developerName;
    int quantityplayers = 0;
    int pk = 0;
} ROM;

int PK = 0;

void registe(map<int, ROM> &ROMs);
void delet(map<int, ROM> &ROMs);
void searchList(map<int, ROM> &ROMs);
int search(map<int, ROM> &ROMs);
void listROMs(map<int, ROM> &ROMs);

int menu();

int main()
{
    map<int, ROM> ROMs;

    int opcao;
    do
    {
        opcao = menu();

        switch (opcao)
        {
        case 1:
        {
            registe(ROMs);
            break;
        }
        case 2:
        {
            delet(ROMs);
            break;
        }
        case 3:
        {
            searchList(ROMs);
            break;
        }
        case 4:
        {
            listROMs(ROMs);
            break;
        }
        }
    } while (opcao != 5);

    system("pause");
    return 0;
}

int menu()
{

    int opcao;

    cout << endl;
    cout << "1 - Cadastro de ROMs" << endl;
    cout << "2 - Excluir de ROMs" << endl;
    cout << "3 - Buscar informacoes de uma ROM" << endl;
    cout << "4 - Lista todas informacoes das ROMs" << endl;
    cout << "5 - Finalizar" << endl;
    cout << endl;
    cout << "Sua opcao: ";
    cin >> opcao;

    return opcao;
}

void registe(map<int, ROM> &ROMs)
{

    cin.ignore();

    ROM nova;

    cout << "\t\t *** CADASTRO NO ESTOQUE ***" << endl;

    cout << "Titulo.....: ";
    getline(cin, nova.title);

    cout << "Genero..: ";
    getline(cin, nova.genre);

    cout << "Nome da desenvolvedora......: ";
    getline(cin, nova.developerName);

    cout << "Ano de lancamento......: ";
    cin >> nova.lacquerYear;

    cout << "Quatidade de jogadores......: ";
    cin >> nova.quantityplayers;

    PK++;

    nova.pk = PK;

    ROMs.insert(pair<int, ROM>(PK, nova));

    cout << "Cadastro " << nova.pk << " realizado com sucesso!" << endl;

    return;
}

void delet(map<int, ROM> &ROMs)
{

    int pk = search(ROMs);

    if (pk)
    {
        ROMs.erase(pk);
        cout << "ROM excluir com sucesso" << endl;
    }
    else
    {
        cout << "ROM nao encotrado impossivel excluir" << endl;
    }
}

void searchList(map<int, ROM> &ROMs)
{
    int pk = 0;

    map<int, ROM>::iterator itROMs;

    cout << "Informe a chave (pk) que deseja buscar para exibir as informacoes......: " << endl;
    cin >> pk;

    itROMs = ROMs.find(pk);

    if (itROMs == ROMs.end())
    {
        cout << "ROM nao encotrado" << endl;
    }
    else
    {
        cout << "ROM encotrado" << endl;

        cout << "Titulo " << itROMs->second.title << endl;
        cout << "Nome da desenvolvedora " << itROMs->second.developerName << endl;
        cout << "Genero " << itROMs->second.genre << endl;
        cout << "Ano de publicacao " << itROMs->second.lacquerYear << endl;
        cout << "Quantidade de jogadores " << itROMs->second.quantityplayers << endl;
        cout << "Chave primaria " << itROMs->second.pk << endl;
    }
}

int search(map<int, ROM> &ROMs)
{
    int pk = 0;

    map<int, ROM>::iterator itROMs;

    cout << "Informe a chave (pk) que deseja ......: " << endl;
    cin >> pk;

    itROMs = ROMs.find(pk);

    if (itROMs == ROMs.end())
    {

        return 0;
    }
    else
    {
        return pk;
    }
}

void listROMs(map<int, ROM> &ROMs)
{

    for (auto itROMs = ROMs.begin(); itROMs != ROMs.end(); ++itROMs)
    {
        cout << "............. ROM .................." << endl;
        cout << "Titulo " << itROMs->second.title << endl;
        cout << "Nome da desenvolvedora " << itROMs->second.developerName << endl;
        cout << "Genero " << itROMs->second.genre << endl;
        cout << "Ano de publicacao " << itROMs->second.lacquerYear << endl;
        cout << "Quantidade de jogadores " << itROMs->second.quantityplayers << endl;
        cout << "Chave primaria " << itROMs->second.pk << endl;
    }
}