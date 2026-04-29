#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* topo = NULL;

// headers
void menu();
void inicializar();
void pop();
void push();
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 4) {
		system("cls"); // somente no windows
		cout << "Menu Pilha";
		cout << endl << endl;
		cout << "1 - Inicializar Pilha \n";
		cout << "2 - Inserir elemento (Push) \n";
		cout << "3 - Remover elementos (Pop) \n";
		cout << "4 - Sair \n";


		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:push();
			break;
		case 3: pop();
			break;
		case 4:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista j� possuir elementos
	// libera a memoria ocupada
	NO* aux = topo;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	topo = NULL;
	cout << "Pilha inicializada \n";

}

/*pilha 1 ponteiro, fila 2 ponteiros*/
void push()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	NO* aux = novo;
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = topo;
	topo = novo;

	/*Fazer o novo nó apontar para o antigo topo (novo->prox = topo);*/
	if (topo != NULL) {
		novo->prox = topo;
	}
	topo = novo;
	
	/*Atualizar o ponteiro topo para apontar para o novo nó;*/
	if(aux == novo){
		topo = topo->prox;
	}
	cout << "Confirmando inserção: " << novo->valor << endl;

}

void pop()
{
	/*Verificar se a pilha está vazia*/
	if (topo == NULL) {
		cout << "Pilha vazia \n";
		return;
	}

	/*Criar um ponteiro auxiliar (NO* aux = topo);*/
	NO* excluir = topo;

	/*Atualizar topo para o próximo elemento */
	topo = topo->prox;

	/*Liberar a memória do nó removido */
	free(excluir);
	cout << "Elemento removido \n";
}

	



