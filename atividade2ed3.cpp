#include <iostream>

 

using namespace std;

 

class celula
{
private:
    string nome;
    celula *proxima;
public:
    celula(){
    	proxima = NULL;
    }
    
     celula(string n){
     	nome = n;
    	proxima = NULL;
    }
    
    
    void setNome(string n){
        nome = n;
    }
    
    string getNome(){
        return nome;
    }
    
    void setProxima(celula *c){
        proxima = c;
    }
    
    celula * getProxima(){
        return proxima;
    }
};

 

class lista
{
private:
    celula * inicio;
public:
    lista(){
        inicio = NULL;
    }
    
     lista(string n){
     	celula * nova = new celula();
     	nova->setNome(n);
        inicio = nova;
    }
    
    celula * getInicio(){
        return inicio;
    }
    
    void inserirInicio(string nome){
        celula * nova = new celula();
        nova->setNome(nome);
        nova->setProxima(inicio);
        inicio = nova;
    }
    
    void imprimir(){
        if(inicio == NULL){
            cout << "Lista vazia" << endl;
        }
        else{
            celula *aux = inicio;
            while(aux != NULL){
                cout << aux->getNome() << " | ";
                aux = aux->getProxima();
            }
        }
    }
    
};

 

int main()
{
    string nome;
<<<<<<< HEAD
<<<<<<< Updated upstream
	lista alunos("Gabriel");    
=======
=======
>>>>>>> 3a617290684282ac17d2642a11319307c0080138
	lista alunos;
	lista gabriel;
		
	gabriel = new lista();
	
	gabriel.inserirInicio("marvin");    
<<<<<<< HEAD
>>>>>>> Stashed changes
=======
>>>>>>> 3a617290684282ac17d2642a11319307c0080138
    cout << "Digite o nome que você deseja inserir no inicio da lista" << endl;  
    while(cin >> nome != 0){     
    alunos.inserirInicio(nome);
    
    cout << "----------- Lista Atual ----------" << endl;
	alunos.imprimir();	
	cout << endl;
	cout << "Digite o nome que você deseja inserir no inicio da lista" << endl; 
	}
	
	
    // alunos.inserirInicio("Queiroz");
    // alunos.inserirInicio("Miguel");
    
    return 0;
    
    
    
    
    
    
    
}