#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;


struct celula {
	int num;
	celula *prox;
};

int main(int argc, char** argv)
{
	celula *inicio = NULL;
	celula *fim = NULL;
	celula *aux;
	celula *anterior;
	
	int op, numero, achou;
	
	do {
		
		cout << "\nMENU DE OPCOES\n";
		cout << "\n1 - Inserir no Inicio da lista";
		cout << "\n2 - Inserir no Fim da lista";
		cout << "\n3 - Consultar toda a lista";
		cout << "\n4 - Remover da lista";
		cout << "\n5 - Esvaziar a lista";
		cout << "\n6 - Sair";
		cout << "\n - Digite sua opcao";
		cin>>op;
		
		if(op<1 || op >6)
			cout << "Opcao invalida!!";
		if(op == 1)
		{
			cout << "Digite o numero a ser inserido no inicio da lista:";
			celula *novo = new celula;
			cin>>novo->num;
			if(inicio==NULL)
			{
				inicio = novo;
				fim = novo;
				fim->prox = NULL;
			}
			else
			{
				 novo->prox = inicio;
				 inicio = novo;
			}
			cout << "Numero inserido no inicio da lista !";
		}
		if(op == 2)
		{
			cout<<"Digite o numero a ser inserido no fim da lista: ";
			celula *novo = new celula;
			cin>>novo->num;
			if(inicio == NULL)
			{
				inicio = novo;
				fim = novo;
				fim->prox = NULL;
			}
			else
			{
			{
				fim->prox = novo;
				fim = novo;
				fim->prox=NULL;
			}
			cout<<"Numero inserido no fim da lista!!";
			}
		}
		if(op==3){
			if(inicio == NULL)
			{
				//a lista esta vazia
				cout << "Lista vazia " << endl;
			}
			else
			{
				cout << "\nConsultando a lista\n";
				aux = inicio;
				while(aux !=NULL){
					cout<<aux->num<<" ";
					aux = aux->prox;
				}
			}
		}
		
		if(op == 4){
			if(inicio == NULL){
				cout << "Lista Vazia" << endl;
			}
			else{
				cout << "\n Digite o elemento a ser removido:"<<endl;
				cin >> numero;
				aux = inicio;
				anterior = NULL;
				achou = 0;
				while(aux!=NULL)
				{
					if(aux->num == numero)
					{
						achou += 1;
						if(aux == inicio){
							inicio = aux->prox;
							delete(aux);
							aux = inicio;
						}
						else if (aux == fim)
						{
							anterior->prox = NULL;
							fim = anterior;
							delete(aux);
							aux = NULL;
						}
						else{
							anterior->prox = aux->prox;
							delete(aux);
							aux = anterior->prox;
						}
					}
						else{
							anterior = aux;
							aux=aux->prox;
						}
					}
					if(achou==0)
						cout << "numero não encontrado"<<endl;
					else if( achou == 1)
						cout << "Numero removido 1 vez";
					else					
						cout << "numero removido "<<achou<<"vezes";
					
				}
			}
			
			if(op == 5){
				inicio = NULL;
			}
			
		
		Sleep(2000);
		system("cls");
	}while(op!=6);
	
	
	
	
	return 0;
}