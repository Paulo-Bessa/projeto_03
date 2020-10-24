//
//  catalogo.hpp
//  projeto_03
//
//  Created by Paulo Bessa on 21/10/20.
//  Copyright © 2020 Paulo Bessa. All rights reserved.
//

#ifndef catalogo_hpp
#define catalogo_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Filme {
    string nome;
    string produtora;
    double nota;
};

bool operator<(const Filme&, const Filme&);
bool operator>(const Filme&, const Filme&);

class Catalogo{
    int quantidade = 0;
    
    friend ostream &operator<<(ostream &,const Filme&);
    friend ostream &operator<<(ostream &,const vector<Filme>&);
    
public:
    Catalogo();
    
    vector<Filme> filmes;
    
    void addFilme(Filme filme);
    void removeFilme(string nome);
    void showFilme(Filme filme);
    int higherGrade();
    void operator+=(const Filme&);
    void operator-=(const Filme&);
    Filme* operator()(const Filme*);
    Filme* operator()(const string, const string);
    void finish();
//private:
    bool checkFilme(string nome);
    int indexFilme(string nome);
    void showThemAllFilme();
    void showNamesFilme();
};

bool operator==(const Filme&,const Filme&);
bool operator==(const Filme&,const string&);

#endif /* catalogo_hpp */
