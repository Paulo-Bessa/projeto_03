//
//  hub.cpp
//  projeto_03
//
//  Created by Paulo Bessa on 23/10/20.
//  Copyright © 2020 Paulo Bessa. All rights reserved.
//

#include "hub.hpp"
//#include "catalogo.hpp"

Hub::Hub(){
    Catalogo catalogo;
    hub(catalogo);
}

void Hub::hub(Catalogo catalogo){
    string entrada_usr1, entrada_usr2;
    int entrada, num, ind;
    double nova_nota;
    bool boole;
    
    
    cout << " Ola, seja bem vindo ao catalogo virtual de filmes do Paulo! Todas as informacoes nao numericas inseridas devem ser escritas sem espacos. Por exemplo, se eu quiser inserir o filme 'Star Wars', devo digitar 'starwars'.\n\n Para adicionar um novo filme ao catalogo, digite 0\n Para ver quais filmes estao no catalogo digite 1\n Para acessar todas as informacoes de todos os filmes digite 2\n Para acessar a nota de um filme digite 3\n Para saber se algum filme especifico esta no catalogo digite 4\n Para remover um filme do catalogo digite 5\n Para editar um filme do catalogo digite 6\n Para buscar o filme mais bem avaliado digite 7\n Para encerrar digite 8\n Para testar busca digite 9\n";
    cin >> entrada;
    if (entrada == 0){
        hub(addUsuarioFilme(catalogo));
    } else if (entrada == 1){
        catalogo.showNamesFilme();
        hub(catalogo);
    } else if (entrada == 2){
        catalogo.showThemAllFilme();
        hub(catalogo);
    }else if (entrada == 3){
        cout << " Insira, em letras minusculas, o nome do filme desejado\n";
        cin >> entrada_usr1;
        ind = catalogo.indexFilme(entrada_usr1);
        if ( ind != -1){
            cout << " A nota deste filme eh " << catalogo.filmes[ind].nota << "\n";
        } else if ( ind == -1){
            cout << " Erro. Filme inexistente no sistema.\n";
        }
    } else if (entrada == 4){
        cout << " Insira, em letras minusculas, o nome do filme desejado";
        cin >> entrada_usr1;
        boole = catalogo.checkFilme(entrada_usr1);
        if (boole){
            cout << " Sim! Filme cadastrado!\n";
            hub(catalogo);
        } else {
            cout << " Nao, este filme nao se encontra no sistema.\n";
            hub(catalogo);
        }
    } else if (entrada == 5){
        cout << " Digite, em letras minusculas e sem acentos, o nome do filme que deseja remover: ";
        cin >> entrada_usr1;;
        catalogo -= catalogo.filmes[catalogo.indexFilme(entrada_usr1)];
        cout << " Pronto! Titulo removido com sucesso!\n\n";
        hub(catalogo);
    } else if (entrada == 6){
        cout << " Digite, em letras minusculas e sem acentos, o nome do filme que deseja editar: ";
        cin >> entrada_usr1;
        ind = catalogo.indexFilme(entrada_usr1);
        cout << " Caso deseje editar o nome, digite 0\n Caso queira editar a produtora, digite 1\n Caso queira editar a nota, digite 2\n";
        cin >> num;
        if ( num == 0 ){
            cout << " Digite o nome correto que deseja armazenar: ";
            cin >> entrada_usr2;
            catalogo.filmes[ind].nome = entrada_usr2;
        } else if ( num == 1 ){
            cout << " Digite o nome correto que deseja armazenar: ";
            cin >> entrada_usr2;
            catalogo.filmes[ind].produtora = entrada_usr2;
        } else if ( num == 2 ){
            cout << " Digite a nota correta que deseja armazenar: ";
            cin >> nova_nota;
            catalogo.filmes[ind].nota = nova_nota;
        }
        hub(catalogo);
    } else if (entrada == 7){
        ind = catalogo.higherGrade();
        cout << " O filme com a maior nota eh: \n" << catalogo.filmes[ind].nome << " e a sua nota eh " << catalogo.filmes[ind].nota << "\n\n";
        hub(catalogo);
    } else if (entrada == 8){
        catalogo.finish();
    } else if (entrada == 9){
//        string name;
//        Filme * variable;
//        cout << " Digite um nome: ";
//        cin >> name;
//        variable = catalogo(name);
//        cout << " VEJAMOS " << variable;
    }
}

Catalogo Hub::addUsuarioFilme(Catalogo catalogo){
    string nome, produtora;
    double nota;
    
    cout << " Para seguirmos adiante entre o nome do filme que deseja armazenar: ";
    cin >> nome;
    cout << " Otimo, agora a produtora: ";
    cin >> produtora;
    cout << " Para terminar, a nota de 0 a 10 que voce da para este filme: ";
    cin >> nota;
    
    Filme filmis({nome,produtora,nota});
    catalogo += filmis;
    return catalogo;
}
