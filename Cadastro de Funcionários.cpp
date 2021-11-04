#include <iostream>
#include <locale>

using namespace std;

struct date{
	int dia, ano;
	string mes;
};

struct funcionario{
	string nome, cpf, cargo;
	int idade, setor;
	float salario;
	char sexo;
	date Data_de_Nascimento;
};

int main(){
	setlocale(LC_ALL, "portuguese");
	int op, filtro_setor, quantidade_funcionarios = 0;
	char filtro_sexo;
	funcionario lista_de_funcionarios[50];
	cout << "Cadastro de Funcionários" << endl << endl;
	
	do{
		int cont_sexo = 0, cont_setor = 0;
		cout << endl;
		cout << "Menu de Opções" << endl << endl;
		cout << "1 - Cadastrar Funcionário" << endl;
		cout << "2 - Listar Todos os Funcionários Cadastrados" << endl;
		cout << "3 - Listar os funcionários por Sexo" << endl;
		cout << "4 - Listar os funcionários por Setor" << endl;
		cout << "5 - Sair" << endl << endl;
		cout << "Escolha uma Opção: ";
		cin >> op;
		cout << " " << endl;
		
		switch(op){
			case 1:
				cout << "Digite o nome completo do(a) funcionário(a): ";
				cin.ignore( 1024, '\n');
				getline(cin, lista_de_funcionarios[quantidade_funcionarios].nome);
				cout << "Digite a idade do(a) funcionário(a): ";
				cin >> lista_de_funcionarios[quantidade_funcionarios].idade;
				cout << "Digite o sexo do(a) funcionário(a) (M ou F): ";
				cin >> lista_de_funcionarios[quantidade_funcionarios].sexo;
				cout << "Digite o CPF do(a) funcionário(a): ";
				cin >> lista_de_funcionarios[quantidade_funcionarios].cpf;
				cout << "Digite o cargo do(a) funcionário(a): ";
				cin >> lista_de_funcionarios[quantidade_funcionarios].cargo;
				cout << "Digite o ano de nascimento do(a) funcionário(a): ";
				cin >> lista_de_funcionarios[quantidade_funcionarios].Data_de_Nascimento.ano;
				cout << "Digite o mês(nome) de nascimento do(a) funcionário(a): ";
				cin >> lista_de_funcionarios[quantidade_funcionarios].Data_de_Nascimento.mes;
				cout << "Digite o dia de nascimento do(a) funcionário(a): ";
				cin >> lista_de_funcionarios[quantidade_funcionarios].Data_de_Nascimento.dia;
				cout << "Digite o código do setor do(a) funcionário(a): ";
				cin >> lista_de_funcionarios[quantidade_funcionarios].setor;
				
				quantidade_funcionarios++;
			break;
		
			case 2:
				for(int i = 0; i < quantidade_funcionarios; i++){
					cout << "Nome: " << lista_de_funcionarios[i].nome << endl;
					cout << "Idade: " << lista_de_funcionarios[i].idade << endl;
					cout << "Sexo: " << lista_de_funcionarios[i].sexo << endl;
					cout << "CPF: " << lista_de_funcionarios[i].cpf << endl;
					cout << "Cargo: " << lista_de_funcionarios[i].cargo << endl;
					cout << "Data de Nascimento: " << lista_de_funcionarios[i].Data_de_Nascimento.dia << " de " 
					<< lista_de_funcionarios[i].Data_de_Nascimento.mes << " de " 
					<< lista_de_funcionarios[i].Data_de_Nascimento.ano << endl;
					cout << "Código do Setor: " << lista_de_funcionarios[i].setor << endl;
					cout << " " << endl;
				}
				if(quantidade_funcionarios == 0){
					cout << "Nenhum funcionário cadastrado ainda." << endl << endl;
				}
			break;
		
			case 3:
				cout << "Deseja exibir os funcionários de qual sexo? (M ou F): ";
				cin >> filtro_sexo;
				cout << " " << endl;
				for(int i = 0; i <= quantidade_funcionarios; i++){
					if(lista_de_funcionarios[i].sexo == filtro_sexo)
					{
						cout << "Nome: " << lista_de_funcionarios[i].nome << endl;
						cont_sexo++;
					}
				}
				if(cont_sexo == 0)
					cout << "Nenhum funcionário desse sexo está registrado na empresa." << endl;
			break;
		
			case 4:
				cout << "Deseja exibir os funcionários de qual setor? (0-99): ";
				cin >> filtro_setor;
				cout << " " << endl;
				for(int i = 0; i <= quantidade_funcionarios; i++){
					if(lista_de_funcionarios[i].setor == filtro_setor)
					{
						cout << "Nome : " << lista_de_funcionarios[i].nome << endl;
						cont_setor++;
					}	
				}
				if(cont_setor == 0){
					cout << "Nenhum funcionário registrado neste setor da empresa ou setor inexistente." << endl;
					cout << "Por favor, tente novamente." << endl;
  	  	  	   }
  	   	   break;
  	      
    	   case 5:
   				cout << "Programa Encerrado com Sucesso!" << endl << endl;
   	   	   break;
  	      
  	      default: {
				cout << "Opção indisponível. Por favor, tente novamente." << endl << endl;
			}		 	
		}
	}while(op != 5);
return 0;		
}