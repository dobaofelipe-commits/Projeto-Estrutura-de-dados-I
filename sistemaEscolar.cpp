#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


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
string turmas[5][4]; //primeiro o dia e depois a sequencia de turmas
};


//funÇões relacionadas a TURMAS

void cadastarTurmas(Turmas &turma){
    cout<<"Qual o nome da turma: ";
    getline(cin, turma.nome);
    turma.codigo=gerarCodigoTurma();   
}

string gerarCodigoTurma(){
string codigo;
codigo = "T" + to_string(rand() % 9000 + 1000);
return codigo;
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
}

void cadastrarProfessor(Professor &professor){

    cout<<"Qual o nome do professor: ";
    getline(cin, professor.nome);
    cout<<"Qual o telefone do professor: ";
    getline(cin, professor.telefone);
    professor.codigo=gerarCodigoProfessor();
    professor.emailInstitucional=gerarEmail(professor.nome);

}


int main(){

}