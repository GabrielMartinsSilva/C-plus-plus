#include <iostream>
#include <list>

using namespace std;

class jogador{
	private:
		string nome, posicao;
		int numero;
	public:
		jogador(){
		}
		jogador(string n, string p, int nu){
			nome = n;
			posicao = p;
			numero = nu;
		}

		//sobrecarga operador ==
		bool operator == (const jogador& p) const {
			return nome == p.nome;
		}

		void imprimir(){
			cout << nome << " - " << posicao << " - " << numero << endl;
		}
};

class equipe{
	private:
		list<jogador> jogadores;
		string nome;
		string nacionalidade;
		int ano;
	public:
		equipe(){
			nome = "";
			nacionalidade = "";
			ano = 0;
		}
		equipe(string n, string na, int a){
			nome = n;
			nacionalidade = na;
			ano = a;
		}

		//sobrecarga operador ==
		bool operator == (const equipe& p) const {
			return nome == p.nome;
		}

		void insereJogador(){
			cout << "Time a ser adicionado o jogador: "<< nome << endl;
			string nomeJogador, posicaoJogador;
			int numeroJogador;
			cout << "Digite o nome do jogador: ";
			cin >> nomeJogador;
			cout << "Digite a posição do jogador: ";
			cin >> posicaoJogador;
			cout << "Digite o número do jogador: ";
			cin >> numeroJogador;
			jogador temp(nomeJogador, posicaoJogador, numeroJogador);
			jogadores.push_back(temp);
			cout << "\nJogador inserido com sucesso\n";
		}

		void imprimirEquipe(){
			cout << "Equipe: " << nome;
			cout << "\nJogadores da equipe:\n";
			for(auto item : jogadores){
				item.imprimir();
			}
		}
		void removeJogador(){
			string j;
			cout << "Digite o nome do jogador a ser removido:";
			cin >> j;
			jogador temp(j, "", 0);
			jogadores.remove(temp);
		}

    
};

 void excluiJogadorEquipe(list<equipe> &lista){
      cout << "Em qual time deseja retirar o jogador ";
      string e;
      cin >> e;
      equipe temp(e, "", 0);
      for(auto &item : lista){
        if(item == temp){
          item.removeJogador();
        }
      }
    }


void cadastroJogador(list<equipe> &lista){
	cout << "Em qual time deseja adicionar um jogador? ";
	string e;
	cin >> e;
	equipe temp(e, "", 0);
	for(auto &item : lista){
		if(item == temp){
			item.insereJogador();
		}
	}
}



class torneio : public equipe{
	private:
		list<equipe> equipes;    
    string nome;
				
	public:
		torneio(){			
			nome = "";
		}

    torneio(string n){			
			nome = n;
		}		    


   
    

		void insereEquipe(){
      

      string nomeEquipe, nacionalidadeEquipe;
      int anoEquipe;

			cout << "Digite o nome da equipe que sera adicionado ao " << nome << endl;
			cin >> nomeEquipe;
      cout << "Digite a nacionalidade da equipe ";
      cin >> nacionalidadeEquipe;
      cout << "Digite o ano que foi fundada a equipe ";
      cin >> anoEquipe;

      equipe temp(nomeEquipe, nacionalidadeEquipe, anoEquipe);

      equipes.push_back(temp);     

		
		}

    void cadastraJogador(){
      cadastroJogador(equipes);
    }

    void removeJogadorEquipe(){
      excluiJogadorEquipe(equipes);
    }

            
		void imprimirTorneio(){
      cout << "Torneio : " << nome << endl;
			for(auto item : equipes){
				item.imprimirEquipe();
			}
		}
		void removerEquipe(){
			string n;
			cout << "Digite o nome da equipe a ser removida:";
			cin >> n;
			equipe temp(n, "", 0);
			equipes.remove(temp);
		}

            
};

void pausar()
{
  string temp; 
  cout << "\n\n-----Aperte enter para sair-----";
  getline(cin, temp );
  cin.get(); 
}






int main() {
	
  torneio brasileirao("Brasileirao");
  int op;

  do{
    system("clear");
    cout << "Menu: \n";
    cout << "1 - Inserir equipe ao torneio\n";
    cout << "2 - Remover equipe do torneio\n";
    cout << "3 - Imprimir equipes\n";
    cout << "4 - Adicionar jogador da equipe\n";
    cout << "5 - Remover jogador da equipe\n";

    cout << "6 - Sair\n";
    cout << "Digite a opção: "; 
    cin >> op;
    switch(op){
      case 1:        
         brasileirao.insereEquipe();        
        break;
      case 2:
        brasileirao.removerEquipe();        
        break;
      case 3:
          brasileirao.imprimirTorneio();          
        break;
      case 4:
          brasileirao.cadastraJogador();
        break;
      case 5:
          brasileirao.removeJogadorEquipe();
        break;
      case 0:
        cout << "Saindo";
      
        break;
      default:
        cout << "Opção inválida.";      
    }
    pausar();
  }while(op != 0);



  /*
  list<equipe> torneio;
	equipe e1("Palmeiras", "Brasil", 1920);
	equipe e2("Flamengo", "Brasil", 1925);
	equipe e3("Cruzeiro", "Brasil", 1922);
	
	torneio.push_front(e1);
	torneio.push_back(e2);


	(torneio);

  

	for(auto item : torneio){	
		item.imprimirEquipe();
	}
  */
  
}