#include <iostream>

using namespace std;

class celula
{
private:
	string nome;
	string sexo;
	int idade;
	string bebe;
	celula * proxima;
public:
	celula()
	{
		proxima = NULL;		
		cout <<"Passou aqui 1";
	}
	celula(string n, string s, int i, string bebe)
	{
		nome = n;
		sexo = s;
		idade = i;
		bebe = bebe;
		cout <<"Passou aqui 2";
	}
	celula(string n, string s, int i, string bebe, celula *p)
	{
		nome = n;
		sexo = s;
		idade = i;
		bebe = bebe;
		proxima = p;
		cout <<"Passou aqui 3";
	}
	celula(string n, celula *p){
		nome = n;		
		proxima = p;
	}
	string getNome()
	{
		return nome;
	}
	void setNome(string n)
	{
		nome = n;
	}

	celula * getProxima()
	{
		return proxima;
	}

	void setProxima(celula * l)
	{
		proxima = l;
	}
	
	string getSexo(){
		return sexo;
	}
	
	void setSexo(string s){
		sexo = s;
	}
	
	int getIdade(){
		return idade;
	}
	void setIdade(int i){
		idade = i;
	}
	
	string getBebe(string bebe){
		if(bebe == "bebe")
			return cout << "bebe";
		else 
		return cout <<"nao bebe";
			
	}
	void setBebe(string bebe){
		bebe = bebe;
	}
};


class lista
{
private:
	celula * inicio;

public:
	lista()
	{
		inicio = NULL;
		cout << "passou aqui 1";
	}
	~lista(){
		esvaziar();
	}
	lista(celula *i)
	{
		inicio = i;
		
	}
	celula * getInicio()
	{
		return inicio;
	}

	void inserirInicio(string n, string s, int i, string bebe)
	{
		celula *nova = new celula;
		nova->setNome(n);
		nova->setProxima(inicio);
		nova->setSexo(s);
		nova->setIdade(i);
		nova->setBebe(bebe);
		inicio = nova;
	}
	/*
	void inserirFim(string n, string s, int i, bool bebe)
	{
		if(inicio == NULL)
		{
			inserirInicio(n, s, i, bebe);
		}
		else
		{
			celula *aux = inicio;
			while(aux->getProxima() != NULL)
			{
				aux = aux->getProxima();
			}
			celula *nova = new celula(n, s, i, bebe, NULL);
			aux->setProxima(nova); 
		}
	}
	*/


	void imprimir()
	{
		if(inicio == NULL)
		{
			cout << "Lista vazia.\n";
		}
		else
		{
			celula *aux = inicio;
			while(aux != NULL)
			{
				cout << aux->getNome() << " - " << aux->getSexo() << " - " << aux->getIdade() << " - "
				<< aux->getBebe(bebe) << " - " << endl;
				aux = aux->getProxima();
			}
		}
	}
	
	void esvaziar(){
		celula *aux = inicio;
		while(aux != NULL){
			inicio = inicio->getProxima();
			delete aux;
			aux = inicio;
		}
		cout << "\n----Memoria liberada----\n";
	}
};

int main()
{
	lista listaAlunos;
	listaAlunos.inserirInicio("Miguel", "Masculino", 25, "bebe");
	listaAlunos.inserirInicio("Joao", "Masculino", 26, "nao bebe");
	//listaAlunos.inserirFim("Jorge", 10);
	//listaAlunos.inserirFim("Ana", 9.8);
	listaAlunos.imprimir();
	return 0;
}