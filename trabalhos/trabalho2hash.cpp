//NOME : EDSON MATEUS ALVES DE OLIVEIRA TURNO : NOITE CIENCIAS DA COMPUTACAO
#include <iostream>
#include<string>
using namespace std;


int menuProdutor();
int menuDeLotes();
int qtdLotes = 0;
int qtdProdutores = 0;
const int UMPRIMO = 37;
int funcaoHash(string s, int M);

class  NoProdutor
{	

	public:

		string nomeFantasia;
		string razaoSocial;
		string cidade;
		string uf;
		int cnpj = 0;
		string state = "INDEFINIDO NECESSARIO DEFINIR UM ESTADO";
		NoProdutor* prox;

		NoProdutor(int cnpj ,string nomeFantasia, string razaoSocial, string cidade, string uf) {

			this->cidade = cidade;
			this->uf = uf;
			this->razaoSocial = razaoSocial;
			this->nomeFantasia = nomeFantasia;
			this->cnpj = cnpj;
			this->prox = NULL;

		}
		void setProx(NoProdutor* ponteiroPara) {
			prox = ponteiroPara;
		}
};


class ListaProdutor
{
	private:
		NoProdutor* comecoLista;

	public:
		ListaProdutor() {
			 comecoLista = NULL;
		}

		ListaProdutor(int cnpj, string nomeFantasia, string razaoSocial, string cidade, string uf){

			//funcao de validar cnpj no cadastro
			comecoLista = new NoProdutor(cnpj, nomeFantasia,razaoSocial,cidade,uf);

		}

		bool getvazia() {
			return (comecoLista == NULL);
		}

		void inserirProdutor(int cnpj, string nomeFantasia, string razaoSocial, string cidade, string uf) {
			NoProdutor *novoNo = new NoProdutor(cnpj, nomeFantasia, razaoSocial, cidade, uf);

				if (novoNo)
				{
					if (getvazia()) {
						comecoLista = novoNo;

					}
					else
					{
						novoNo->setProx(comecoLista);
						comecoLista = novoNo;
					}
					qtdProdutores++;
				}
		}

		void remover()
		{
			if (!getvazia())
			{
				// se houver so 1 elemento
				if (comecoLista->prox == NULL)
					comecoLista = NULL;
				else if (comecoLista->prox->prox == NULL) // 2 elementos
					comecoLista->setProx(NULL);
				else // > 2 elementos
				{
					NoProdutor* ant_ant = comecoLista;
					NoProdutor* ant = comecoLista->prox;
					NoProdutor* corrente = comecoLista->prox->prox;

					while (corrente)
					{
						NoProdutor* aux = ant;
						ant = corrente;
						ant_ant = aux;
						corrente = corrente->prox;
					}
					delete ant_ant->prox; // libera memória
					ant_ant->setProx(NULL); // seta o prox como NULL

				}
				qtdProdutores--;
			}
		}

		void mostrarProdutores() // mostra todos os elementos da lista
		{
			cout << "Detalhes dos produtores... " << endl;
			NoProdutor* aux = comecoLista;

			if (getvazia())
				cout << "Nao possui produtores cadastrados !!" << endl;
			else
			{
				while (aux) // percorre a lista
				{
					cout << "!--------------------!" << endl;
					cout << "Razao Socical ... " << aux->razaoSocial << endl;
					cout << "Nome Fantazia ... " << aux->nomeFantasia << endl;
					cout << "Cidade... " << aux->cidade << endl;
					cout << "Estado (UF) ..." << aux->uf << endl;
					cout << "CNPJ... " << aux->cnpj << endl;
					cout << "ESTADO (ATIVO/INATIVO)... " << aux->state << endl;
					cout << "!--------------------!" << endl;
					aux = aux->prox;
				}

				cout << "TOTAL DE PRODUTORES DESATIVADOS: " << desativados() << endl;
				cout << "TOTAL DE PRODUTORES ATIVADOS : " << ativados() << endl;
				cout << "TOTAL DE PRODUTORES INDEFINIDOS : " << indefinidos() << endl;
				cout << "TOTAL DE PRODUTORES : " << qtdProdutores << endl;
				cout << endl;
			}
		}

		int quatidadeDeProdutores()
		{
			if (getvazia()) // se for vazia, entã retorna 0
				return 0;

			NoProdutor* c = comecoLista;
			int tam = 0;

			// percorre a lista
			do
			{
				c = c->prox;
				tam++;
			} while (c);

			cout << "Quantidade total de produtores " << tam << endl;
			return tam;
		}

		NoProdutor* BuscarProdutores(int key)
		{
			NoProdutor* aux = comecoLista;

			while (aux)
			{
				if (aux->cnpj == key) {
					cout << "Produtor encotrado... " << endl;
					return aux;
				}
				aux = aux->prox;

			}
			cout << "Produtor nao encotrado... " << endl;
				return aux;
		}

		bool verficarCPNJ(int key)
		{
			NoProdutor* aux = comecoLista;
			while (aux)
			{
				if (aux->cnpj == key) {
					
					return false;
				}
				aux = aux->prox;

			}
			return true;
		}

		bool setState(int key,int state) {
			NoProdutor *produtor = BuscarProdutores(key);
			if (produtor)
			{
				if (state == 1)
				{
					produtor->state = "ATIVADO";
					cout << "Alterado para ativado" << endl;
					return true;

				}
				else if (state == 2) {
					produtor->state = "DESATIVADO" ;
					cout << "Alterado para desativado" << endl;
						return true;
				}		
				else
				{
					produtor->state = "INDEFINIDO NECESSARIO DEFINIR UM ESTADO";
					cout << "Valor invalido estado indefinido" << endl;
						return true;
				}

			}
			else
			{
				cout << "Esse produtor nao esta na tabela" << endl;
					return false;
			}

		}

		bool alteraNome(int key,string novoNome) {
			NoProdutor* produtor = BuscarProdutores(key);
			if (produtor)
			{
				produtor->nomeFantasia = novoNome;
				cout << "Nome alterado" << endl;
				return true;
			}
			cout << "ERRO nao foi possivel alterar o nome" << endl;
			return false;
		}

		int ativados() {
			NoProdutor* aux = comecoLista;
			int c = 0;
			while (aux)
			{
				if (aux->state == "ATIVADO")
				{
					c++;
				}	
				aux = aux->prox;
			}
			return c;
		}

		int desativados() {
			NoProdutor* aux = comecoLista;
			int c = 0;
			while (aux)
			{
				if (aux->state == "DESATIVADO")
				{
					c++;
				}
				aux = aux->prox;
			}
			return c;
		}

		int indefinidos() {
			NoProdutor* aux = comecoLista;
			int c = 0;
			while (aux)
			{
				if (aux->state == "INDEFINIDO NECESSARIO DEFINIR UM ESTADO")
				{
					c++;
				}
				aux = aux->prox;
			}
			return c;
		}
		
};


class NoLoteDeProdutos
{

	friend class TabelaHashLote;
	private:
		int CNPJdoProdutor;
		int hashGerado;
		string numeroDoLote;
		string dataProducao;
		string nomeDoProduto;
		NoLoteDeProdutos* prox = NULL;
	public:
		NoLoteDeProdutos() {
			CNPJdoProdutor = 0;
			numeroDoLote = "";
			dataProducao = "";
			nomeDoProduto = "";
		}

};

class TabelaHashLote
{
	private:
		NoLoteDeProdutos** itemHash = NULL;
		int capacidade;

	public:
		TabelaHashLote(int cap = 199){
			itemHash = new NoLoteDeProdutos * [cap];
			capacidade = cap;
			for (size_t i = 0; i < cap; i++)
			{
				itemHash[i] = NULL;
			}
		}

		~TabelaHashLote() {
			for (size_t i = 0; i < capacidade; i++)
			{
				NoLoteDeProdutos* atual = itemHash[i];
				while (atual != NULL)
				{
					NoLoteDeProdutos* aux = atual;
					atual = atual->prox;
					delete aux;
					itemHash[i] = NULL;
				}
			}
			cout << "Tabela excluida com sucesso" << endl;
			qtdLotes = 0;
		}

		void insereLote (string numeroDoLote, string dataProducao, string nomeDoProduto ,int CNPJdoProdutor) {
			int hash = funcaoHash(numeroDoLote, capacidade);
			if (buscarLote(hash) == "NÂO ENCONTRADO" )
			{
				if (itemHash[hash] == NULL)
				{
					itemHash[hash] = new NoLoteDeProdutos;
					itemHash[hash]->numeroDoLote = numeroDoLote;
					itemHash[hash]->dataProducao = dataProducao;
					itemHash[hash]->nomeDoProduto = nomeDoProduto;
					itemHash[hash]->CNPJdoProdutor = CNPJdoProdutor;
					itemHash[hash]->hashGerado = hash;
					qtdLotes ++;
				}
				else
				{
					cout << "COLIDIU" << nomeDoProduto << endl;
					NoLoteDeProdutos* aux = itemHash[hash];

					while (aux->prox != NULL)
					{
						aux = aux->prox;
					}
					NoLoteDeProdutos* novo = new NoLoteDeProdutos;
					novo->numeroDoLote = numeroDoLote;
					novo->dataProducao = dataProducao;
					novo->nomeDoProduto = nomeDoProduto;
					novo->CNPJdoProdutor = CNPJdoProdutor;
					aux->prox = novo;
					qtdLotes++;
				}
			}
			else
			{
				cout << "O NUMERO DE LOTE JA FOI CADASTRADO" << endl;
			}
			
		}

		string buscarLote (int numeroDeHash) {
			if (itemHash[numeroDeHash] != NULL and itemHash[numeroDeHash]->hashGerado == numeroDeHash) {
				
				return "ENCONTRADO" ;
			}
			else {
				NoLoteDeProdutos* aux = itemHash[numeroDeHash];

				while (aux != NULL and aux->hashGerado != numeroDeHash) {
					aux = aux->prox;
				}

				if (aux != NULL and aux->hashGerado == numeroDeHash) {
					
					return "ENCONTRADO" ;
				}
				else {
					
					return "NÂO ENCONTRADO" ;
				}
			}

		}

		void mostrarDetalhesLote() {
			NoLoteDeProdutos* aux;
			if (itemHash == NULL)
			{
				return;
			}

				cout << "!--------------------!" << endl;
				for (int i = 0; i < capacidade; ++i) {
					aux = itemHash[i];
					while (aux) {
						cout << endl << "........................" << endl;
						cout << "Numero do lote ... " << aux->numeroDoLote << endl;
						cout << "Numero de hash ... " << aux->hashGerado << endl;
						cout << "Nome do lote ... " << aux->nomeDoProduto << endl;
						cout << "Data de producao... " << aux->dataProducao << endl;
						cout << "CNPJ do produtor... " << aux->CNPJdoProdutor << endl;
						cout << endl << "........................" << endl;
						aux = aux->prox;
					}

				}
				cout << "TOTAL DE LOTES CADASTRADOS : " << qtdLotes << endl;
				cout << "!--------------------!" << endl;
			
		}

		void removeLote(int chave) {
			if (itemHash[chave] != NULL and itemHash[chave]->hashGerado == chave) {
				NoLoteDeProdutos* aux = itemHash[chave];
				itemHash[chave] = itemHash[chave]->prox;
				delete aux;
				qtdLotes--;
				cerr << "REMOVIDO" << endl;
			}
			else {
				NoLoteDeProdutos* atual = itemHash[chave];
				NoLoteDeProdutos* anterior = 0;
				while (atual != NULL and atual->hashGerado != chave) {
					anterior = atual;
					atual = atual->prox;
				}
				if (atual != NULL and atual->hashGerado == chave) {
					anterior->prox = atual->prox;
					delete atual;
					qtdLotes--;
					cerr << "REMOVIDO" << endl;
				}
				else {
					cerr << "ERRO NA REMOCAO" << endl;
				}
			}
		}
};

int main() {
	ListaProdutor produtorores;
	TabelaHashLote lotes;
	string razaoSocial, nomeFantazia, cidade, uf, dataLote, NomeDoProdutoLote, numeroLote, novonome;
	int CNPJ = 0, CNPJlotes = 0 ,state = 0, numeroHash = 0;

	int opcao = 0;
	do
	{
		cout << endl;
		cout << "1_Acessar menu dos produtores : " << endl;
		cout << "2_Acessar menu de lotes de produtos : " << endl;
		cout << "3_Sair encerra programa : " << endl;
		cin >> opcao;
		if (opcao == 1)
		{
			do
			{
				opcao = menuProdutor();
				switch (opcao)
				{
				case 1:
				{


					
					cin.ignore();
					cout << "Qual e o CNPJ do produtor ";
					cin >> CNPJ;
					if (produtorores.verficarCPNJ(CNPJ))
					{
						cin.ignore();
						cout << "Qual e o nome fantazia do produtor " << endl;
						getline(cin, nomeFantazia);

						cout << "Qual e a razao social do produtor " << endl;
						getline(cin, razaoSocial);


						cout << "Qual e a cidade " << endl;
						getline(cin, cidade);

						cout << "Qual e o estado do produtor (UF) " << endl;
						getline(cin, uf);

						produtorores.inserirProdutor(CNPJ, nomeFantazia, razaoSocial, cidade, uf);
					}
					else
					{
						cout << "CNPJ JA CADASTRADO" << endl;
					}
					break;
				}

				case 2:
				{
					cin.ignore();
					cout << "informe o CNPJ do produtor que quer buscar ";
					cin >> CNPJ;
					produtorores.BuscarProdutores(CNPJ);
					break;
				}
				case 3:
				{
					produtorores.mostrarProdutores();
					break;
				}
				case 4:
				{	

					cout << "Informe o CNPJ do produtor que deseja alterar o estado" << endl;
					cin >> CNPJ;
					cin.ignore();
					if (produtorores.BuscarProdutores(CNPJ))
					{
						cout << "1_Para ativar produtor  " << endl << "2_Para desativar produtor  " << endl;
						cin >> state;
						produtorores.setState(CNPJ, state);
					}
					else {
						cout << "tente de novo e informe um CNPJ valido" << endl;
					}
					break;
				}
				case 5: {
						
						cout << "Informe o CNPJ do produtor que deseja alterar o nome" << endl;
						cin >> CNPJ;
						cin.ignore();
						if (produtorores.BuscarProdutores(CNPJ))
						{
						
							cout << "Informe o novo nome fantazia do produtor que deseja alterar " << endl;
							getline(cin, novonome);
							produtorores.alteraNome(CNPJ, novonome);
						}
						else
						{
							cout << "tente de novo e informe um CNPJ valido" << endl;
						}
					break;
				}
				}
				
			} while (opcao != 6);
		}
		if (opcao == 2)
		{
			do
			{
				opcao = menuDeLotes();
				switch (opcao)
				{
				case 1:
				{
					cout << "Qual e o CNPJ do produtor responsavel por esse lote ";
					cin >> CNPJlotes;
					cin.ignore();
					cout << "Qual e o numero do lote " << endl;
					getline(cin, numeroLote);
					cout << "Qual e a data de fabricacao do lote (EXEMPLO : 26-03-1870) " << endl;
					getline(cin, dataLote);
					cout << "Qual e o nome do produto referente ao lote " << endl;
					getline(cin, NomeDoProdutoLote);
				
					lotes.insereLote(numeroLote, dataLote, NomeDoProdutoLote, CNPJlotes);
					break;
				}

				case 2:
				{	
					cin.ignore();
					cout << "Qual e o numero do lote que deseja buscar " << endl;
					cin >> numeroHash;


					if (lotes.buscarLote(numeroHash) == "ENCONTRADO")
					{
						cout << "Lote encotrado" << endl;
					}
					else
					{
						cout << "Lote nao encotrado" << endl;
					}
					break;
				}
				case 3:
				{	
					cin.ignore();
					cout << "Qual e o numero do lote que deseja remover " << endl;
					cin >> numeroHash ;
					lotes.removeLote(numeroHash);
					break;
				}

				case 4:
				{
					lotes.mostrarDetalhesLote();
					break;
				}
				case 5:
				{
					lotes.~TabelaHashLote();
					break;
				}
				};

			} while (opcao != 6);
		}
	} while (opcao != 3);
		system("pause");
		return 0;
}

int menuProdutor()
{
	int opcao;
	do
	{
		cout << endl;
		cout << "Escolha uma das opcoes abaixo:" << endl;
		cout << "1 - Cadastrar Produtor" << endl;
		cout << "2 - Bucar produtor " << endl;
		cout << "3 - Gerar relatorio  da tabela de produtores" << endl;
		cout << "4 - Mudar estado de um produtor " << endl;
		cout << "5 - Mudar nome fantazia do produtor " << endl;
		cout << "6 - Sair " << endl;
		cout << "Sua opcao: " << endl;
		cin >> opcao;
		if (opcao < 1 || opcao > 6)
		{
			cout << "Opcao invalida  !!";
		}
	} while (opcao < 1 || opcao > 6);
	return opcao;
}

int menuDeLotes()
{
	int opcao;
	do
	{
		cout << endl;
		cout << "Escolha uma das opcoes abaixo:" << endl;
		cout << "1 - Cadastrar lote de producao" << endl;
		cout << "2 - Consultar um  lote na tabela lotes  " << endl;
		cout << "3 - Remove um lote " << endl;
		cout << "4 - Gerar relatorio  da tabela de lotes" << endl;
		cout << "5 - Zerar a tabela de lotes (ISSO EXCLUIRAR TODOS OS DADOS DA TABELA)" << endl;
		cout << "6 - Sair " << endl;
		cout << "Sua opcao: " << endl;
		cin >> opcao;
		if (opcao < 1 || opcao > 6)
		{
			cout << "Opcao invalida  !!";
		}
	} while (opcao < 1 || opcao > 6);
	return opcao;
}

int funcaoHash(string s, int M) {
	long h = 0;
	for (unsigned i = 0; i < s.length(); i++) {
		h = (UMPRIMO * h + s[i]) % M;
	}
	return h;
};
