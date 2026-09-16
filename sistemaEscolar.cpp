#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int inicioAula[5]={-1,-1,-1,-1,-1}, fimAula[5]={-1,-1,-1,-1,-1};
string aulas[5][4]; //primeiro o dia e depois a sequencia de turmas


//Estrutura de alunos 
struct Alunos{
string nome;
string matricula;
string telefone;
int idade;
string turma;
};
//Estrutura de turmas
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
//O codigo da turma sempre vai ser T mais um numero aleatorio
string gerarCodigoTurma(){
string codigo;
codigo = "T" + to_string(rand() % 9000 + 1000);
return codigo;
}

//FunÇão de cadastrar turmas so precisa gerar o Codigo da turma e saber qual é o nome da turma por exemplo turma A
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
    //como eu so quero que o email tenha o primeiro e segundo nome eu coloquei um contador pra poder controlar o limite te espaÇos indentificados
    //assim  se o contador ja tiver contado um espaço ele vai so ignorar e adicionar o final do email institucional
    if(contador<1){
    email+=".";
    contador++;
    } else {
        contador++;
        email+="@cefet-rj.br";
    }
}
    i++;

}while(contador<2);
return email;
} // fim gerar email-professor


//função de cadastrar o professor
//NÃO ESTA COMPLETO, esotu pensando em como eu posso guardar da maneira mais eficiente e rapida os professores dentro de uma variavel
void enfilaProfessor(Professor professor[], int fimProfessor){
    if(fimProfessor<3){
        fimProfessor++;
        cout<<"Qual o nome do professor: ";
        getline(cin, professor[fimProfessor].nome);
        cout<<"Qual o telefone do professor: ";
        getline(cin, professor[fimProfessor].telefone);
        professor[fimProfessor].codigo=gerarCodigoProfessor();
        professor[fimProfessor].emailInstitucional=gerarEmail(professor[fimProfessor].nome);
    } else {
        cout<<"Você ja alcançou o limite máximo de professores ";
    }
} // fim função de cadastrar o professor



//funÇão pra exibir os professores cadastrados caso isso seja solicitado
string exibirProfessor(Professor professor[], int fimProfessor){
    for(int i=0;i<fimProfessor;i++){
        cout<< i+1 << " - "<< professor[i].nome;
    }
}

//FunÇão que enfila as aulas dentro de uma fila com base no dia e qual a turma
void enfilaAula(int dia, string turma, int numProfessor){

if(fimAula[numProfessor-1]<3){
fimAula[numProfessor-1]++;
aulas[dia-1][fimAula[numProfessor-1]]=turma;
cout<<fimAula[numProfessor-1]<< "\n";
} else {
    cout<<"A quantidade de materias para esse dia ja está cheia";
}

if(inicioAula[numProfessor-1]==-1){
    inicioAula[numProfessor-1]=0;
}

} //Fim enfila 


//o Desenfila aula foi baseado para apenas mostrar qual é a sequencia da fila por isso ele nao volta para o -1 no finale sim para 0
string desenfilaAula(int dia, int numProfessor){
    string resposta;
    if(inicioAula[numProfessor-1]>=0){
        resposta=aulas[dia-1][inicioAula[numProfessor-1]];
        if(inicioAula[numProfessor-1]!=fimAula[numProfessor-1]){
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

    int dia, numProfessor, opcao, inicioProfessor=-1, fimProfessor=-1;
    string nomeTurma;
    Professor professores[4];


    do{
    cout<<"Escolha uma das opções a seguir: \n";
    cout<<"1 - Adicionar professor   2 - Adicionar Turmas\n";
    cout<<"3 - Adicionar turmas ao professor  4 - Exibir Professores";
    cin>>opcao;

    switch(opcao){
        case 1:
        enfilaProfessor(&professores[fimProfessor], fimProfessor);
        break;
        default:
        break;
    }


    } while(opcao!=0);

    do{ 
    cout<<"0 - parar \n 1 - Segunda\n 2 - Terça \n 3 - Quarta \n 4 - Quinta \n 5 - Sexta \n ";
    cout<<"Escolha o dia ";
    cin>>dia;
    cout<<"Escolha a turma (nome ou numero da turma)";
    cin>>nomeTurma;
    cout<<"Escolha o Professor ";
    cin>>numProfessor;
    enfilaAula(dia, nomeTurma, numProfessor);
    cout<<"2 para parar";
    cin>>opcao;
    system("cls");

    }while(opcao!=0);
    
    cout<<"Escolha o dia que quer saber a sequencia \n";
    cin>>dia;
    cout<<"sequencia de turma é \n";
    for(int i=0;i<4;i++){
        cout<<desenfilaAula(dia,numProfessor);
    }


}