#include <iostream>
using namespace std;

// definicao de tipo
struct NO
{
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
int posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7)
	{
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada Ordenada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}
		system("pause"); // somente no windows
	}
}

void inicializar()
{
	NO* aux = primeiro;
	while (aux != NULL)
	{
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}
	primeiro = NULL;
	cout << "Lista inicializada \n";
}

void exibirQuantidadeElementos()
{
	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL)
	{
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;
}

void exibirElementos()
{
	if (primeiro == NULL)
	{
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL)
		{
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	NO* atual = primeiro;
	NO* anterior = NULL;

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	int Procura = posicaoElemento(novo->valor);
	if (Procura != NULL)
	{
		cout << "O elemento ja existe" << endl;
		free(novo);
		return;
	};

	if (primeiro == NULL)
	{
		primeiro = novo;
		cout << "O elemento foi adicionado na primeira posicao" << endl;
	}
	else
	{
		while (atual != NULL)
		{
			if (primeiro->valor > novo->valor)
			{
				primeiro = novo;
				primeiro->prox = atual;
				cout << "O elemento foi adicionado na primeira posicao" << endl;
				return;
			}

			else if (atual->valor > novo->valor)
			{
				anterior->prox = novo;
				novo->prox = atual;
				int pos = posicaoElemento(novo->valor); 
				cout << "O elemento foi adicionado na posicao: " << pos << endl;
				return;
			}

			else if (atual->prox == NULL)
			{
				atual->prox = novo;
				cout << "O elemento foi adicionado no final." << endl;
				return;
			}

			anterior = atual;
			atual = atual->prox;
		}
	}
}

void excluirElemento()
{

	if (primeiro == NULL)
	{
		cout << "Lista vazia" << endl;
		return;
	}

	int nExcluir;
	cout << "Digite o elemento a ser deletado: " << endl;
	cin >> nExcluir;
	int Procura = posicaoElemento(nExcluir);

	if (Procura == NULL)
	{
		cout << "Elemento nao existe" << endl;
		return;
	}

	NO* atual = primeiro;
	NO* anterior = NULL;

	while (atual != NULL)
	{
		if (atual->valor == nExcluir)
		{
			if (nExcluir == primeiro->valor)
			{
				primeiro = atual->prox;
			}
			else
			{
				anterior->prox = atual->prox;
			}
			free(atual);
			cout << "O elemento foi deletado com sucesso!" << endl;
			break;
		}
		anterior = atual;
		atual = atual->prox;
	}
}

void buscarElemento()
{
	if (primeiro == NULL)
	{
		cout << "Lista vazia" << endl;
		return;
	}

	NO* aux = primeiro;
	int busca;

	cout << "Digite o elemento a ser encontrado: " << endl;
	cin >> busca;
	int pos = posicaoElemento(busca);

	if (pos == NULL)
	{
		cout << "Elemento nao encontrado" << endl;
		return;
	}
	else
	{
		cout << "Elemento encontrado na posicao " << pos << endl;
	}
}

int posicaoElemento(int numero)
{
	NO* aux = primeiro;
	int posicao = 1; 

	while (aux != NULL)
	{
		if (aux->valor == numero) 
		{
			return posicao;
		}
		else if (aux->valor > numero) 
		{
			return NULL;
		}
		posicao++;
		aux = aux->prox;
	}
	return NULL;
}