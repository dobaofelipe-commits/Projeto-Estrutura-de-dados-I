#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int inicioAula[5]={-1,-1,-1,-1,-1}, fimAula[5]={-1,-1,-1,-1,-1};
string aulas[5][4]; //primeiro o dia e depois a sequencia de turmas



struct Alunos{
string nome;
string matricula;
string telefone;
int idade;
string turma;
};

struct Turmas{
string codigo;
string nome;
Alunos alunos[20];

};

//estrutura que define quais são os parametros de Professor
struct Professor{
string turmas[4];
string nome;
string codigo;
string telefone;
string emailInstitucional;
};


//funÇões relacionadas a TURMAS


string gerarCodigoTurma(){
string codigo;
codigo = "T" + to_string(rand() % 9000 + 1000);
return codigo;
}


void cadastarTurmas(Turmas &turma){
    cout<<"Qual o nome da turma: ";
    getline(cin, turma.nome);
    turma.codigo=gerarCodigoTurma();   
}


//Fuções relacionadas  a PROFESSOR

string gerarCodigoProfessor(){
string codigo;
codigo = "PROF" + to_string(rand() % 9000 + 1000);
return codigo;
}

//funÇão de gerar email-professor
string gerarEmail(string nome){
string email;
int contador=0, i=0;

do{
    // primeiro ele verifica se o caracter n é vazio, caso não seja ele adiciona o caracter ao email final
    if(nome[i]!=' '){
    email+=nome[i];
} else {
    //como eu so quero que o email tenha o primeiro e segundo nome do professor eu coloquei um contador pra poder controlar o limite te espaÇos indentificados
    //assim  se o contador ja tiver contado um espaço ele vai so ignorar e adicionar o final do email institucional
    if(contador<1){
    email+=".";
    contador++;
    } else {
        contador++;
        email+="@instituicao.com";
    }
}
    i++;

}while(contador<2);
return email;
} // fim gerar email-professor


//função de cadastrar o professor
void cadastrarProfessor(Professor &professor){

    cout<<"Qual o nome do professor: ";
    getline(cin, professor.nome);
    cout<<"Qual o telefone do professor: ";
    getline(cin, professor.telefone);
    professor.codigo=gerarCodigoProfessor();
    professor.emailInstitucional=gerarEmail(professor.nome);

} // fim função de cadastrar o professor

void enfilaAula(int dia, string turma, int numProfessor){

if(fimAula[numProfessor]<4){
fimAula[numProfessor-1]++;
aulas[dia][fimAula[numProfessor-1]]=turma;
cout<<fimAula[numProfessor-1]<< "\n";
} else {
    cout<<"A quantidade de materias para esse dia ja está cheia";
}

if(inicioAula[numProfessor-1]==-1){
    inicioAula[numProfessor-1]=0;
}

} //Fim enfila 

string desenfilaAula(int dia, int numProfessor){
    string resposta;
    if(inicioAula[numProfessor-1]>=0){
        resposta=aulas[dia][inicioAula[numProfessor-1]];
        if(inicioAula[numProfessor-1]!=fimAula[numProfessor-1]){
            cout<<inicioAula[numProfessor-1]<< "\n";
            inicioAula[numProfessor-1]++;
        }else{
            inicioAula[numProfessor-1]=0;
            fimAula[numProfessor-1]=0;
        }

    } else{
        cout<<"Esse dia está vazio, adicione aulas para esse professor";
    }
    return resposta;
}


int main(){

    int dia, numProfessor, opcao;
    string nomeTurma;

    do{
    cout<<"Escolha o dia ";
    cin>>dia;
    cout<<"Escolha a turma ";
    cin>>nomeTurma;
    cout<<"Escolha o Professor ";
    cin>>numProfessor;
    enfilaAula(dia, nomeTurma, numProfessor);
    cout<<"2 para parar";
    cin>>opcao;

    }while(opcao!=2);
    
    cout<<"Escolha o dia que quer saber a sequencia \n";
    cin>>dia;
    cout<<"sequencia de turma é \n";
    for(int i=0;i<4;i++){
        cout<<desenfilaAula(dia,numProfessor);
        i++;
    }
    cout<<aulas[dia][2]<<"\n";
    cout<<aulas[dia][3];



}