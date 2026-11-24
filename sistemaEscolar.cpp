#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int inicioAula[5]= {-1,-1,-1,-1,-1}, fimAula[5]= {-1,-1,-1,-1,-1};
string aulas[5][4]; //primeiro o dia e depois a sequencia de turmas


//Estrutura de alunos
struct NoAluno {
string nome;
string matricula;
string telefone;
string idade;
string turma;
string email;
string cpf;
string nomeMateria[10];
string notaMateria[10];
NoAluno* prox;
};


//Estrutura de turmas
struct Turmas {
string codigo;
string nome;
string alunos[20];
int quantidadeAluno;
bool ativo;

};

//Inicio da Cadeia de alunos
NoAluno* inicioAlunos = NULL;

//estrutura de Professor
struct Professor {
string AulaDoDia[5][4];// 5 dias para um limite de 4 turmas por dia.
string turmas[4];
string nome;
string codigo;
string telefone;
string emailInstitucional;
bool ativo;
};


//funções relacionadas a TURMAS
//O codigo da turma sempre vai ser T mais um numero aleatorio
string gerarCodigoTurma() {
string codigo;
codigo = "T" + to_string(rand() % 9000 + 1000);
return codigo;
}

//FunÇão de cadastrar turmas so precisa gerar o Codigo da turma e saber qual é o nome da turma por exemplo turma A
void cadastrarTurmas(Turmas &turma) {
cout<<"Qual o nome da turma: ";
getline(cin, turma.nome);
turma.codigo=gerarCodigoTurma();
turma.ativo=true;
}

void excluirTurma(Turmas turma[], int num){
    num--;
    turma[num].ativo=false;
    cout<<"A turma foi excluida com sucesso";
}

void verTurma(Turmas turma[], int num) {
    num--;
    if(turma[num].ativo==true) {
        cout<< " - "<< turma[num].nome << "\n";
        for(int i=0; i<turma[num].quantidadeAluno; i++) {
            cout<< " - "<< turma[num].alunos[i] << "\n";
        }
    } else {
        cout<< " - Vazio \n";
    }
}


//Fuções relacionadas  a PROFESSOR

string gerarCodigoProfessor() {
string codigo;
codigo = "PROF" + to_string(rand() % 9000 + 1000);
return codigo;
}

//funÇão de gerar email-professor
string gerarEmail(string nome) {
string email;
int contador=0, i=0;
do {
// primeiro ele verifica se o caracter n é vazio, caso não seja ele adiciona o caracter ao email final
if(nome[i]!=' ') {
email+=nome[i];
} else {
//como eu so quero que o email tenha o primeiro e segundo nome eu coloquei um contador pra poder controlar o limite te espaÇos indentificados
//assim  se o contador ja tiver contado um espaço ele vai so ignorar e adicionar o final do email institucional
if(contador<1) {
email+=".";
contador++;
} else {
contador++;
email+="@cefet-rj.br";
}
}
i++;

} while(contador<2);
return email;
} // fim gerar email-professor


//função de cadastrar o professor
void cadastroProfessor(Professor &professor) {
getchar();
cout<<"Qual o nome do professor: ";
getline(cin, professor.nome);
cout<<"Qual o telefone do professor: ";
getline(cin, professor.telefone);
professor.codigo=gerarCodigoProfessor();
professor.emailInstitucional=gerarEmail(professor.nome);
professor.ativo=true;

} // fim função de cadastrar o professor


//Mostra quais são os dados do professore
void mostrarDadosProfessor(Professor &professor) {
cout<<"Nome - "<< professor.nome <<"\n";
cout<<"email - "<< professor.emailInstitucional <<"\n";
cout<<"Telefone- "<< professor.telefone <<"\n";
cout<<"Codigo - "<< professor.codigo <<"\n";
cout<<"Turmas que ele da aula";
for(int i=0; i<4; i++) {
cout<<" - " <<professor.turmas[i];
}

}

//funÇão pra exibir os professores cadastrados caso isso seja solicitado
void exibirProfessor(Professor professor[], int tamanho) {
for(int i=0; i<tamanho; i++) {
if(professor[i].ativo==true) {
cout<< i+1 << " - "<< professor[i].nome << "\n";
} else {
cout<< i+1 << " - Vazio \n";
}
}
}


//Função gera emuma unica linha a sequenia de turmas do professor, na teoria isso seia so para o adm usar, a fnção que o professor fosse usar para ver qual é a sequencia dele seria o desenfilaAula
string exibirTurmaProfessor(Professor professor) {
string resposta;
for(int i=0; i<4; i++) {
resposta+=" "+ professor.turmas[i] + " ";
}
return resposta;
}

// Exibe o PROFESSOR as Turmas em que ele da aula, pensando em fazer algo parecido mas com materias
void exibirProfessorETurma(Professor professor[], int tamanho) {
   for(int i=0; i<tamanho; i++) {
      if(professor[i].ativo==true) {
      cout<< i+1 << " - "<< professor[i].nome << exibirTurmaProfessor(professor[i]) <<"\n";

      } else {
         cout<< i+1 << " - Vazio \n";
      }
   }
}

//Função ordenarProfessor

void ordenarProfessor(Professor professor[], int tamanho) {
   bool trocou= false;
   string char1;
   string char2;
   int tamanhoLoop;
//if para ver qual é o tamanho da string menor, para não dar erro de estouro de memoria
   if(char1.length()>char2.length()) {
      tamanhoLoop=char2.length();
   } else {
      tamanhoLoop=char1.length();
   }
   while(!trocou) {
      for(int i=0; i<tamanhoLoop-1; i++) {
         char1=professor[i].nome;
         char2=professor[i+1].nome;
         if(char1[i]>char2[i]) {
            Professor aux= professor[i];
            professor[i]=professor[i+1];
            professor[i+1]=aux;
            trocou=true;
         }
      }
   }

}


void alterarProfessor(Professor professor[], int num){
    num--;
    string aux;
    mostrarDadosProfessor(professor[num]);
    cout<<"\nCaso não queria alterar o dado deixe em branco ( aperte Enter)\n";
    cout<<"O codigo não pode ser alterado e o email é alterado automaticamente caso o noem seja alterado";
    cout<<"Qual o nome do professor: ";
    getline(cin, aux);
    if(aux!=""){
        professor[num].nome=aux;
    }
    cout<<"Qual o telefone do professor: ";
    getline(cin, aux);
    if(aux!=""){
        professor[num].telefone=aux;
    }
    professor[num].emailInstitucional=gerarEmail(professor[num].nome);
    cout<<"Email - "<< professor[num].emailInstitucional <<"\n";
}


void excluirProfessor(Professor professor[], int num){
    num--;
    professor[num].ativo=false;
    cout<<"O professor foi excluido com sucesso";
}



//FunÇão que enfila as aulas dentro de uma fila com base no dia e qual a turma
//So para explicar professor, essa função aq esta fazndo duas funções, ela ta guardando turmas em duas variaveis diferentes
//Uma é algo mais estruturado a egunda eu ainda vou mexer e está mais simples
//sem contar que uma é para o Professor ver a outra é para o Admin ver ( na teoria)
void enfilaAula(int dia, string turma, int numProfessor, Professor &professor) {

if(fimAula[numProfessor]<3) {
fimAula[numProfessor]++;
aulas[dia][fimAula[numProfessor]]=turma;
professor.AulaDoDia[dia][fimAula[numProfessor]]=turma;
cout<<fimAula[numProfessor]<< "\n";
} else {
cout<<"A quantidade de materias para esse dia ja está cheia";
}

if(inicioAula[numProfessor-1]==-1) {
inicioAula[numProfessor-1]=0;
}

} //Fim enfila


//o Desenfila aula foi baseado para apenas mostrar qual é a sequencia da fila por isso ele nao volta para o -1 no finale sim para 0
string desenfilaAula(int dia, int numProfessor) {
string resposta;
if(inicioAula[numProfessor]>=0) {
resposta=aulas[dia][inicioAula[numProfessor]];
if(inicioAula[numProfessor]!=fimAula[numProfessor]) {
inicioAula[numProfessor]++;
} else {
inicioAula[numProfessor]=0;
fimAula[numProfessor]=0;
}

} else {
cout<<"\nEsse dia está vazio, adicione aulas para esse professor";
}
return resposta;
}


//Função de gerar matricula, gera um numero aleatorio e soma ele ocm a string SINF ( parecido com o que é no cefet)
string gerarMatricula() {
string matricula;
matricula= to_string(rand() % 9000 + 1000)+ "SINF";
return matricula;
}

//Inserir no Inicio
void cadastrarAlunoInicio(Turmas turmas[]) {

int cont=0;
    NoAluno* aluno= new NoAluno;
bool teste=false;

//Verifica se tem turmas cadastradas, caso não tenha ele não deixa cadastrar o aluno
for(int i=0; i<4; i++) {
   if(turmas[i].ativo==false){
       cont++;
       cout<<cont;
    }
}
    if(cont==4){
        cout<<"Não tem turmas cadastradas, não da para adicionar um aluno, primeiro adicione uma turma";
        return;
    }
cout<<"Qual o nome do aluno: ";
getline(cin, aluno->nome);
cout<<"Qual o telefone desse aluno (colocar apenas números e com DDD): ";
getline(cin,aluno->telefone);
cout<<"Qual a idade desse aluno: ";
getline(cin,aluno->idade);
if(inicioAlunos==NULL){
   inicioAlunos=aluno;
} else {
   aluno->prox=inicioAlunos;
   inicioAlunos=aluno;
}

do {
cout<<"Escreve o nome da turma que o aluno vai pertencer: ";
getline(cin, aluno->turma);

for(int i=0; i<4; i++) {
   if (aluno->turma==turmas[i].nome) {
      if(turmas[i].quantidadeAluno<=20) {
      turmas[i].quantidadeAluno++;
      teste=true;
      } else {
      cout<<"A turma escolhida já está cheia, escolha outra turma para atribuirao aluno.\n";
      }
      break;
      }
   }
} while(teste==false || cont==4);

aluno->matricula=gerarMatricula();

cout<<"A matricula desse aluno foi gerada, ela é: " << aluno->matricula<< "\n";

}

//Exibir aluno 
void exibirAluno(string nome ) {
NoAluno* aux= inicioAlunos;   
do {
   if(aux->nome==nome) {
      cout<<"Nome: "<< aux->nome << "\n";
      cout<<"Telefone: "<< aux->telefone << "\n";
      cout<<"Idade: "<< aux->idade << "\n";
      cout<<"Matricula: "<< aux->matricula << "\n";
   } else{
      aux=aux->prox;
   }
} while(aux!=NULL && aux->nome!=nome);

 if(aux==NULL) {
    cout<<"Aluno não encontrado\n";
 }
}


void excluirAluno(NoAluno* aluno, int num){
    num--;
   NoAluno* aux= inicioAlunos;
   NoAluno* anterior= NULL;  
   for(int i=0; i<num; i++) {
      anterior=aux;
      aux=aux->prox;
   }
   if(anterior==NULL) {
      inicioAlunos=aux->prox;

   } else {
      anterior->prox=aux->prox;  
   }

    cout<<"O aluno foi excluido com sucesso";
}



int main() {

int dia, numProfessor, opcao, num;
string nomeTurma;
Professor professores[4]= {};
Turmas turmas[4]= {};


do {
cout<<"Escolha uma das opções a seguir: \n";
cout<<"1 - Adicionar professor   2 - Adicionar Turmas\n";
cout<<"3 - Adicionar turmas ao professor  4 - Exibir Professores\n ";
cout<<"5 - Exibir Professores e suas aulas 6 - Mostrar dados do professor\n";
cout<<"7 - Cadastrar Alunos 8 - Mostrar proxima aula do Professor\n";
cout<<"9 - Alterar Professor 10 - Ver Aluno\n";
cout<<"11 - Excluir Professor Turma 12 - Excluir Aluno\n";
cout<<"13 - Excluir Turma \n";
cin>>opcao;

switch(opcao) {
case 1:
for(int i=0; i<5; i++) {
if(i<4) {
if(professores[i].ativo==false) {
cadastroProfessor(professores[i]);
break;
}
} else
cout<<"O limite de professores ja foi atingido ";

}
break;
case 2:
//Como professores é algo pequeno eu fiz um for por enquanto apra achar a posição vazia com base no bool ativo
cin.ignore();
for(int i=0; i<4; i++) {
if(i<4) {
if(turmas[i].ativo==false) {
cadastrarTurmas(turmas[i]);
break;
}
} else
cout<<"O limite de turmas ja foi atingido ";
}
break;
case 3:
int opcao2;
cout<<"Seus professores são:\n";
cout<<"\nPrecione enter para continuar";
getchar();
getchar();
system("clear");
do {
cout<<"0 - parar \n 1 - Segunda\n 2 - Terça \n 3 - Quarta \n 4 - Quinta \n 5 - Sexta \n ";
cout<<"Escolha o dia ";
cin>>dia;
system("clear");
cout<<"Escolha a turma (nome ou numero da turma)";
cin>>nomeTurma;
exibirProfessor(professores, 4);
cout<<"Escolha o numero do Professor ";
cin>>numProfessor;
enfilaAula(dia-1, nomeTurma, numProfessor,professores[numProfessor-1]);
cout<<"0 para parar e voltar ao menu principal";
cin>>opcao2;
system("clear");

} while(opcao2!=0);

break;
case 4:
exibirProfessor(professores, 4);
cout<<"\nPrecione enter para sair ";
getchar();

break;
case 5:
exibirProfessorETurma(professores, 4);
break;
case 6:
int num;
exibirProfessor(professores, 4);
cout<<"\nEscolha qual professor você quer pegar os dados: ";
cin>>num;
if(num<=4 && num >=0) {
mostrarDadosProfessor(professores[num-1]);
} else {
cout<<" Numero inválido\n Você voltará ao menu principal";
cout<<"\nPressione ENTER";
getchar();
}

break;
case 7:
   cin.ignore();
cadastrarAlunoInicio(turmas);

break;
case 8:
exibirProfessor(professores, 4);
cout<<"\nEscolha qual professor: ";
cin>> num;
cout<<"\nEscolha qual dia ";
cin>>dia;
cout<<desenfilaAula(dia, num);
break;
case 9:
exibirProfessor(professores, 4);
cout<<"\nEscolha qual professor você quer alterar: ";
cin>>num;
alterarProfessor(professores, num);
break;
case 10:{
string name;
cin.ignore();
cout<<"Digite o nome do aluno que você quer ver: ";
cin>>name;
exibirAluno(name);
break;
}
case 11:{
exibirProfessor(professores, 4);
cout<<"\nEscolha qual professor você quer excluir: ";
cin>>num;
excluirProfessor(professores, num);
break;
}
case 12:
exibirAluno(" ");
cout<<"\nEscolha qual aluno você quer excluir: ";
cin>>num;
excluirAluno(inicioAlunos, num);
break;
case 13:
excluirTurma(turmas, num);
break;}


} while(opcao!=0);

cout<<"FIM DO SISTEMA";

return 0;


}