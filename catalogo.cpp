//
//  catalogo.cpp
//  projeto_03
//
//  Created by Paulo Bessa on 21/10/20.
//  Copyright © 2020 Paulo Bessa. All rights reserved.
//

#include "catalogo.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Catalogo::Catalogo(){
    string nome, produtora;
    double nota;
    
    ifstream Read;
    Read.open("/Users/user/Desktop/Matematica/UFRJ_matematica/Computação/Swift/projeto_03/projeto_03/catalogo");
    while (Read >> nome >> produtora >> nota){
        Filme filme({nome,produtora,nota});
        filmes.push_back(filme);
    }
    Read.close();
}

void Catalogo::finish(){
    ofstream of;
    of.open("/Users/user/Desktop/Matematica/UFRJ_matematica/Computação/Swift/projeto_03/projeto_03/catalogo", ofstream::out | ofstream::trunc);
    for (Filme x:filmes){
        of << x.nome << " " << x.produtora << " " << x.nota << "\n";
    }
    of.close();
}

int Catalogo::higherGrade(){
    int index;
    int grade = 0;
    string nome;
    for (Filme x:filmes){
        if (x.nota >= grade){
            grade = x.nota;
            nome = x.nome;
            index = indexFilme(x.nome);
        }
    }
    return index;
}

void Catalogo::showThemAllFilme(){
    cout << " Seguemos filmes cadastrados!\n";
    for(Filme x : filmes){
        cout << " Nome: " << x.nome << "\n Produtora: " << x.produtora << "\n Nota: " << x.nota << "\n\n";
    }
}

void Catalogo::showNamesFilme(){
    cout << " Segue o nome dos filmes cadastrados!\n";
    for(Filme x : filmes){
        cout << " Nome: " << x.nome << "\n\n";
    }
}

int Catalogo::indexFilme(string nome_verifica){
    for (int i = 0; i < filmes.size(); i++){
        if(filmes[i].nome == nome_verifica){
            return i;
        }
    }
    return -1;
}

bool Catalogo::checkFilme(string nome_verifica){
    for (int i = 0; i < filmes.size(); i++){
        if(filmes[i] == nome_verifica){
            return true;
        }
    }
    return false;
}

//void Catalogo::showFilme(Filme filme){
//    cout << " Filme: " << filme.nome << "\n Produtora: " << filme.produtora << "\n Nota: " << filme.nota << "\n\n";
//}

// ------ OVERLOADED OPERATORS -------

bool operator==(const Filme & filme1,const Filme & filme2){
    bool result;
    result = filme1.nome == filme2.nome;
    return result;
}

bool operator==(const Filme & filme1,const string & palavra){
    bool result;
    result = filme1.nome == palavra;
    return result;
}

void Catalogo::operator+=(const Filme & filme){
    if (!checkFilme(filme.nome)){
        filmes.push_back(filme);
    }
    else{
        cout << " Filme ja esta cadastrado no sistema!\n\n";
    }
}

bool operator<(const Filme& filme1, const Filme& filme2){
    return filme1.nome.size() < filme2.nome.size();
};

bool operator>(const Filme& filme1, const Filme& filme2){
    return filme1.nome.size() > filme2.nome.size();
};

void Catalogo::operator-=(const Filme & filme){
    int index;
    index = indexFilme(filme.nome);
    if (index == -1){
        cout << " Este filme nao estava no catalogo";
    } else {
        filmes.erase(filmes.begin() + index);
    }
}

Filme * Catalogo::operator()(const Filme * filme){
    int index;
    Filme * ponteiro;
    index = indexFilme((*filme).nome);
    ponteiro = &filmes[index];
    return ponteiro;
}

Filme * Catalogo::operator()(const string nome1, const string nome2){
    string entrada;
    double entrada_nota;
    int index;
    Filme * variable;
    index = indexFilme(nome1);
    variable = &filmes[index];
    if ( nome2 == "novonome"){
        cout << " Foi escolhida a edicao do nome do filme.\n Insira o novo nome: \n";
        cin >> entrada;
        filmes[index].nome = entrada;
        cout << " Pronto! Editado!\n";
        return variable;
    } else if ( nome2 == "novaprodutora"){
        cout << " Foi escolhida a edicao da produtora do filme.\n";
        cin >> entrada;
        filmes[index].produtora = entrada;
        cout << " Pronto! Editado!\n";
        return variable;
    } else if ( nome2 == "novanota"){
        cout << " Foi escolhida a edicao da nota do filme.\n";
        cin >> entrada_nota;
        filmes[index].nota = entrada_nota;
        cout << " Pronto! Editado!\n";
        return variable;
    }
    return NULL;
}

ostream &operator<<(ostream & output,const Filme & filme){
    output << " Nome do filme: " << filme.nome << "\n Nome da produtora: " << filme.produtora << "\n Nota do filme: " << filme.nota << "\n\n";
    return output;
}

ostream &operator<<(ostream & output,const vector<Filme> & lista){
    for (Filme filme:lista){
    output << " Nome do filme: " << filme.nome << "\n Nome da produtora: " << filme.produtora << "\n Nota do filme: " << filme.nota << "\n\n";
    }
    return output;
}
