#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <map>

#include <termcolor/termcolor.hpp>

using namespace std;

void putShip(char ship, vector<vector<char>>& YourTable){
    map<char, vector<int>> tamanhos = {{'C', {3,1}} , {'F', {4,1}}, {'D', {5,1}}, {'M', {6,2}}, {'P',{8,2}}, {'S',{3,2}}};
    vector<int> tamanho = tamanhos[ship];
    int  coluna, linha, orientacao;
    char x;
    bool valido = false;

    while(!valido){

    cout << termcolor::white<< "\nEscolha a coluna, linha e orientacao de sua embarcacao:\nColuna: ";

    cin >> x;
    coluna = toupper(x) - 'A';

    cout << "\nLinha: ";
    cin >> linha;

    cout << "\nOrientacao \n|1 - Horizontal ||2 - Vertical|: ";
    cin >> orientacao;
    

    valido = true;

    if(coluna < 0 || coluna >= 20 || linha < 0 || linha >= 20 || orientacao < 1 || orientacao > 2){
        valido = false;
    }


    if(valido){
        int largura = (orientacao == 1) ? tamanho[0] : tamanho[1];
        int altura  = (orientacao == 1) ? tamanho[1] : tamanho[0];

        for(int i = 0; i < largura && valido; i++){
            for(int j = 0; j < altura && valido; j++){

                if(coluna + i >= 20 || linha + j >= 20){
                    valido = false;
                    break;
                }

                if(YourTable[linha + j][coluna + i] != '~'){
                    valido = false;
                    break;
                }
            }
        }
    }

    if(!valido){
        cout << termcolor::bright_red
             << "\nPOSICAO INVALIDA! Tente novamente.\n"
             << termcolor::white;
    }
    }

    
    int largura = (orientacao == 1) ? tamanho[0] : tamanho[1];
    int altura  = (orientacao == 1) ? tamanho[1] : tamanho[0];
    for(int i = 0; i < largura; i++){
        for(int j = 0; j < altura; j++){
            YourTable[linha + j][coluna + i] = ship;
        }
    }
    
}


void pickShip(int& pontos, vector<vector<char>>& YourTable, map< char, int>& YourShips,  map<char, int>& tamanhos){
    map<char, int> custos = {{'C', 3} , {'F', 5}, {'D', 7}, {'M', 10}, {'P',15}, {'S',15}};

    cout<<termcolor::cyan<<"ESCOLHA UMA EMBARCACAO DE NOSSA LISTA, VOCE TEM "<<pontos<<" PONTOS\n"
    <<termcolor::blue<<"EMBARCACAO          CODIGO    "<<termcolor::red<<"CUSTO\n"
    <<termcolor::blue<<"Corveta Stealth       C       "<<termcolor::red<<"3 Pts\n"
    <<termcolor::blue<<"Fragata               F       "<<termcolor::red<<"5 Pts\n"
    <<termcolor::blue<<"Destroyer             D       "<<termcolor::red<<"7 Pts\n"
    <<termcolor::blue<<"Cruzador de Misseis   M       "<<termcolor::red<<"10 Pts\n"
    <<termcolor::blue<<"Porta-Avioes          P       "<<termcolor::red<<"15 Pts\n"
    <<termcolor::blue<<"Submarino Nuclear     S       "<<termcolor::red<<"15 Pts\n";
    char escolha;

    cout<<termcolor::white<<"\nDigite sua escolha: ";
    cin>>escolha;
    escolha = toupper(escolha);

    while(true){
    
    while(!custos.count(escolha)){
        cout<<termcolor::bright_red<<"\nESCOLHA INVALIDA\n"<<termcolor::white<<"\nDigite sua nova escolha: ";
        cin>>escolha;
        escolha = toupper(escolha);
               
    }
    if(custos[escolha] > pontos){
        cout<<termcolor::bright_red<<"\nPONTOS INSUFICIENTES\n";
        escolha = '0';
    }else{
        putShip(escolha,YourTable);
        pontos -= custos[escolha];
        YourShips[escolha] += tamanhos[escolha];
        break;
    }
    }
}

void showTable(vector<vector<char>>& EnemyTable,  vector<vector<char>>& YourTable,
    vector<vector<bool>>& EnemyTableHits, vector<vector<bool>>& YourTableHits){

    cout<<termcolor::on_grey<<termcolor::bright_red<<endl<<endl<<"                   TABULEIRO INIMIGO"<<endl<<endl;

    cout<<termcolor::on_grey<<termcolor::bright_red <<"   A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T"<<endl;   

    for(int i = 0; i < EnemyTable.size(); i++){

        string x = (i <10)? "  ":" ";

        cout<<termcolor::bright_red<<i<<x;

        for(int j = 0; j <EnemyTable[i].size(); j++){

            if(EnemyTableHits[i][j]){

                cout<< termcolor::on_blue << termcolor::red << EnemyTable[i][j];

            }else{

                cout<< termcolor::on_blue << termcolor::bright_blue << "~";

            }

            cout<< "  ";
        }

        cout<<termcolor::on_grey<< termcolor::white<<endl;
    }

     cout<<termcolor::on_grey<<termcolor::bright_green <<endl<<endl<<"                   SEU TABULEIRO"<<endl<<endl;

    cout<<termcolor::on_grey<<termcolor::bright_green <<"   A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T"<<endl;   

    for(int i = 0; i < YourTable.size(); i++){

        string x = (i < 10)? "  ":" ";

        cout<<termcolor::bright_green<<i<<x;

        for(int j = 0; j <YourTable[i].size(); j++){

            if(YourTableHits[i][j]){               
                    cout<< termcolor::on_blue << termcolor::red << YourTable[i][j];
            }else{
                if(YourTable[i][j] == '~'){
                    cout<< termcolor::on_blue << termcolor::bright_blue << YourTable[i][j];
                }else{
                    cout<< termcolor::on_blue << termcolor::bright_yellow << YourTable[i][j];
                }
            }

            cout<< "  ";
        }

        cout<<termcolor::on_grey<< termcolor::white<<endl;
    }

}

int sumships(map< char, int>& Ships){
    int sum = 0;
    for(auto x : Ships){
        sum += x.second;
    }

    return sum;
}

void jogada(vector<vector<char>>& EnemyTable, vector<vector<bool>>& EnemyTableHits, map< char, int>& EnemyShips, map<char, int>& tamanhos ){
    int coluna, linha, municao;
    char x;
    bool valido = false;

    while(!valido){
        cout<<termcolor::white<<termcolor::on_grey<<"\nDIGITE SUA JOGADA:\nColuna: ";
        cin>>x;
        x = toupper(x);
        coluna = x -'A';
        cout<<termcolor::white<<termcolor::on_grey<<"\nLinha: ";
        cin>>linha;

        cout<<"\nESCOLHA A MUNICAO\n|1 - NORMAL ||2 - ESPECIALIZADA EM SUBMARINOS|\n";
        cin>>municao;


        if(coluna < 0 || coluna >= 20 || linha < 0 ||linha >= 20 || municao<1 || municao > 2){
            cout<<termcolor::bright_red<<"\nJOGADA INVALIDA";
        }else{
            if(!EnemyTableHits[linha][coluna]){
                valido = true;
            }else{
                cout<<termcolor::bright_red<<"\nJOGADA INVALIDA";
            }
        }
    }

    if(municao == 1){
        if(EnemyTable[linha][coluna] != 'S'){
            EnemyTableHits[linha][coluna] = true;
            cout<<termcolor::green<<"\nACERTOU!\n";
            EnemyShips[EnemyTable[linha][coluna]] -= tamanhos[EnemyTable[linha][coluna]];
        }else{
            cout<<termcolor::bright_red<<"\nMUNICAO INCAPAZ DE ATINGIR SUBMARINOS!\n";
        }
    }else{
        if(EnemyTable[linha][coluna] == 'S'){
            EnemyTableHits[linha][coluna] = true;
            cout<<termcolor::green<<"\nACERTOU!\n";
            EnemyShips[EnemyTable[linha][coluna]] -= tamanhos[EnemyTable[linha][coluna]];
        }else{
            cout<<termcolor::bright_red<<"\nMUNICAO SEM EFEITO EM EMBARCACOES COMUNS!\n";
        }
    }

}

int main(){
    vector<vector<char>> EnemyTable(20, vector<char>(20, '~')) , YourTable(20, vector<char>(20, '~'));
    vector<vector<bool>> EnemyTableHits(20, vector<bool>(20, 0)), YourTableHits(20, vector<bool>(20, 0));
    map<char, int> YourShips = {{'C', 0} , {'F', 0}, {'D', 0}, {'M', 0}, {'P',0}, {'S',0}} , EnemyShips = {{'C', 0} , {'F', 0}, {'D', 0}, {'M', 0}, {'P',0}, {'S', 0}},
    tamanhos = {{'C', 3} , {'F', 4}, {'D', 5}, {'M', 12}, {'P',16}, {'S',12}};
    int pontos = 30;


    cout << termcolor::on_grey<<endl;

    cout<< termcolor::cyan<< "Seja bem vindo a Batalha Naval"<<termcolor::white<<"\nIniciaremos nosso jogo com a escolha das embarcacoes\n"<<termcolor::white;

    while(pontos >= 3){
    pickShip(pontos, YourTable, YourShips, tamanhos);
    showTable( EnemyTable,   YourTable,   EnemyTableHits,  YourTableHits);
    }

    cout<<endl<<termcolor::bright_red<<termcolor::on_white<<"Embarcacoes Inimigas a caminho!"<<endl<<"Progresso:\n1%               100%"<<endl;

    for(int i = 0;i< 21; i++ ){
        Sleep(500);
        cout<<"-";
    }
    cout<<termcolor::on_grey<<termcolor::white;

   while(sumships(YourShips) && sumships(EnemyShips)){

    jogada(EnemyTable, EnemyTableHits, EnemyShips, tamanhos);



    }


    
 

}

