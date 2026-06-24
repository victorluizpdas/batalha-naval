#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <map>
#include <ctime>
#include <windows.h>

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

void putEnemyShip(vector<vector<char>>& EnemyTable, map<char, int>& EnemyShips){

    switch(rand() % 10){

    case 0:

        // 10 Corvetas
        for(int i=0;i<3;i++) EnemyTable[1][1+i]='C';
        EnemyShips['C']+=3;

        for(int i=0;i<3;i++) EnemyTable[3][6+i]='C';
        EnemyShips['C']+=3;

        for(int i=0;i<3;i++) EnemyTable[5][11+i]='C';
        EnemyShips['C']+=3;

        for(int i=0;i<3;i++) EnemyTable[7][16+i]='C';
        EnemyShips['C']+=3;

        for(int i=0;i<3;i++) EnemyTable[10][2+i]='C';
        EnemyShips['C']+=3;

        for(int i=0;i<3;i++) EnemyTable[12][7+i]='C';
        EnemyShips['C']+=3;

        for(int i=0;i<3;i++) EnemyTable[14][12+i]='C';
        EnemyShips['C']+=3;

        for(int i=0;i<3;i++) EnemyTable[16][1+i]='C';
        EnemyShips['C']+=3;

        for(int i=0;i<3;i++) EnemyTable[18][8+i]='C';
        EnemyShips['C']+=3;

        for(int i=0;i<3;i++) EnemyTable[18][15+i]='C';
        EnemyShips['C']+=3;

        break;

    case 1:

        for(int i=0;i<4;i++) EnemyTable[1+i][2]='F';
       EnemyShips['F']+=4;

        for(int i=0;i<4;i++) EnemyTable[1+i][6]='F';
       EnemyShips['F']+=4;

        for(int i=0;i<4;i++) EnemyTable[1+i][10]='F';
       EnemyShips['F']+=4;

        for(int i=0;i<4;i++) EnemyTable[10+i][4]='F';
       EnemyShips['F']+=4;

        for(int i=0;i<4;i++) EnemyTable[10+i][9]='F';
       EnemyShips['F']+=4;

        for(int i=0;i<4;i++) EnemyTable[10+i][14]='F';
       EnemyShips['F']+=4;

        break;

    case 2:

        for(int i=0;i<5;i++) EnemyTable[2][2+i]='D';
       EnemyShips['D']+=5;

        for(int i=0;i<5;i++) EnemyTable[8][8+i]='D';
       EnemyShips['D']+=5;

        for(int i=0;i<5;i++) EnemyTable[15][12+i]='D';
       EnemyShips['D']+=5;

        for(int i=0;i<3;i++) EnemyTable[4+i][15]='C';
        EnemyShips['C']+=3;

        for(int i=0;i<3;i++) EnemyTable[9+i][2]='C';
        EnemyShips['C']+=3;

        for(int i=0;i<3;i++) EnemyTable[12+i][5]='C';
        EnemyShips['C']+=3;

        for(int i=0;i<3;i++) EnemyTable[5][10+i]='C';
        EnemyShips['C']+=3;

        for(int i=0;i<3;i++) EnemyTable[18][6+i]='C';
        EnemyShips['C']+=3;

        break;

    case 3:

        for(int x=0;x<6;x++)
            for(int y=0;y<2;y++)
                EnemyTable[2+y][2+x]='M';
       EnemyShips['M']+=12;

        for(int x=0;x<6;x++)
            for(int y=0;y<2;y++)
                EnemyTable[12+y][10+x]='M';
       EnemyShips['M']+=12;

        for(int i=0;i<3;i++) EnemyTable[18][1+i]='C';
        EnemyShips['C']+=3;

        for(int i=0;i<3;i++) EnemyTable[18][16+i]='C';
        EnemyShips['C']+=3;

        break;

    case 4:

        for(int x=0;x<8;x++)
            for(int y=0;y<2;y++)
                EnemyTable[5+y][5+x]='P';
       EnemyShips['P']+=16;

        for(int i=0;i<4;i++) EnemyTable[15][2+i]='F';
       EnemyShips['F']+=4;

        for(int i=0;i<4;i++) EnemyTable[15][12+i]='F';
       EnemyShips['F']+=4;

        break;

    case 5:

        for(int x=0;x<3;x++)
            for(int y=0;y<2;y++)
                EnemyTable[1+y][1+x]='S';
       EnemyShips['S']+=12;

        for(int x=0;x<3;x++)
            for(int y=0;y<2;y++)
                EnemyTable[1+y][10+x]='S';
       EnemyShips['S']+=12;

        for(int x=0;x<3;x++)
            for(int y=0;y<2;y++)
                EnemyTable[8+y][5+x]='S';
       EnemyShips['S']+=12;

        for(int x=0;x<3;x++)
            for(int y=0;y<2;y++)
                EnemyTable[15+y][14+x]='S';
       EnemyShips['S']+=12;

        for(int x=0;x<3;x++)
            for(int y=0;y<2;y++)
                EnemyTable[12+y][1+x]='S';
       EnemyShips['S']+=12;

        break;

    case 6:

        for(int x=0;x<8;x++)
            for(int y=0;y<2;y++)
                EnemyTable[2+y][2+x]='P';
       EnemyShips['P']+=16;

        for(int x=0;x<6;x++)
            for(int y=0;y<2;y++)
                EnemyTable[12+y][12+x]='M';
       EnemyShips['M']+=12;

        break;

    case 7:

        for(int i=0;i<5;i++) EnemyTable[1][1+i]='D';
       EnemyShips['D']+=5;

        for(int i=0;i<5;i++) EnemyTable[18][10+i]='D';
       EnemyShips['D']+=5;

        for(int i=0;i<4;i++) EnemyTable[6+i][15]='F';
       EnemyShips['F']+=4;

        for(int i=0;i<4;i++) EnemyTable[8][3+i]='F';
       EnemyShips['F']+=4;

        for(int i=0;i<3;i++) EnemyTable[12][5+i]='C';
        EnemyShips['C']+=3;

        for(int i=0;i<3;i++) EnemyTable[4][10+i]='C';
        EnemyShips['C']+=3;

        break;

    case 8:

        for(int x=0;x<6;x++)
            for(int y=0;y<2;y++)
                EnemyTable[8+y][7+x]='M';
       EnemyShips['M']+=12;

        for(int i=0;i<4;i++) EnemyTable[5+i][5]='F';
       EnemyShips['F']+=4;

        for(int i=0;i<4;i++) EnemyTable[5+i][14]='F';
       EnemyShips['F']+=4;

        for(int i=0;i<3;i++) EnemyTable[13][9+i]='C';
        EnemyShips['C']+=3;

        break;

    case 9:

        for(int x=0;x<8;x++)
            for(int y=0;y<2;y++)
                EnemyTable[1+y][10+x]='P';
       EnemyShips['P']+=16;

        for(int i=0;i<5;i++) EnemyTable[10+i][2]='D';
       EnemyShips['D']+=5;

        for(int i=0;i<5;i++) EnemyTable[10+i][17]='D';
       EnemyShips['D']+=5;

        for(int i=0;i<3;i++) EnemyTable[18][7+i]='C';
        EnemyShips['C']+=3;

        break;
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

void jogada(vector<vector<char>>& EnemyTable, vector<vector<bool>>& EnemyTableHits, map< char, int>& EnemyShips){
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
    if(EnemyTable[linha][coluna] == '~'){
        cout<<termcolor::bright_red<<"\nERROU\n";
        EnemyTable[linha][coluna] = true;

    }else{
    if(municao == 1){
        if(EnemyTable[linha][coluna] != 'S'){
            EnemyTableHits[linha][coluna] = true;
            cout<<termcolor::green<<"\nACERTOU!\n";
            EnemyShips[EnemyTable[linha][coluna]] --;
        }else{
            cout<<termcolor::bright_red<<"\nMUNICAO INCAPAZ DE ATINGIR SUBMARINOS!\n";
        }
    }else{
        if(EnemyTable[linha][coluna] == 'S'){
            EnemyTableHits[linha][coluna] = true;
            cout<<termcolor::green<<"\nACERTOU!\n";
            EnemyShips[EnemyTable[linha][coluna]] --;
        }else{
            cout<<termcolor::bright_red<<"\nMUNICAO SEM EFEITO EM EMBARCACOES COMUNS!\n";
        }
    }
}

}

void jogadaEnemy(vector<vector<char>>& EnemyTable, vector<vector<bool>>& EnemyTableHits, map< char, int>& EnemyShips){

    int coluna, linha, municao;
    char x;
    bool valido = false;

     while(!valido){
        coluna = rand() % 20;
        linha = rand() % 20;
        municao = rand() % 2;
        municao ++;

        if(!EnemyTableHits[linha][coluna]){
            valido = true;
        }
    }
            
    if(EnemyTable[linha][coluna] == '~'){
        cout<<termcolor::green<<"\nINIMIGOP ERROU\n";
        EnemyTable[linha][coluna] = true;
    }else{
    if(municao == 1){
        if(EnemyTable[linha][coluna] != 'S'){
            EnemyTableHits[linha][coluna] = true;
            cout<<termcolor::red<<"\nINIMIGO ACERTOU!\n";
            EnemyShips[EnemyTable[linha][coluna]] --;
        }else{
            cout<<termcolor::green<<"\nMUNICAO INIMIGA INCAPAZ DE ATINGIR SUBMARINOS!\n";
        }
    }else{
        if(EnemyTable[linha][coluna] == 'S'){
            EnemyTableHits[linha][coluna] = true;
            cout<<termcolor::red<<"\nINIMIGO ACERTOU!\n";
            EnemyShips[EnemyTable[linha][coluna]] --;
        }else{
            cout<<termcolor::green<<"\nMUNICAO INIMIGA SEM EFEITO EM EMBARCACOES COMUNS!\n";
        }
    }}
}

int main(){
    srand(time(nullptr));
    vector<vector<char>> EnemyTable(20, vector<char>(20, '~')) , YourTable(20, vector<char>(20, '~'));
    vector<vector<bool>> EnemyTableHits(20, vector<bool>(20, 0)), YourTableHits(20, vector<bool>(20, 0));
    map<char, int> YourShips = {{'C', 0} , {'F', 0}, {'D', 0}, {'M', 0}, {'P',0}, {'S',0}} , EnemyShips = {{'C', 0} , {'F', 0}, {'D', 0}, {'M', 0}, {'P',0}, {'S', 0}},
    tamanhos = {{'C', 3} , {'F', 4}, {'D', 5}, {'M', 12}, {'P',16}, {'S',6}};
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
    putEnemyShip(EnemyTable, EnemyShips);
    cout<<termcolor::on_grey<<termcolor::white;


    while(sumships(YourShips) && sumships(EnemyShips)){

    jogada(EnemyTable, EnemyTableHits, EnemyShips);
    if(!sumships(EnemyShips)){
        break;
    }
    jogadaEnemy(YourTable, YourTableHits, YourShips);

    showTable( EnemyTable,   YourTable,   EnemyTableHits,  YourTableHits);
    }

    if(!sumships(EnemyShips)){
        cout<<endl<<termcolor::on_bright_green<<termcolor::bright_white<<"VOCE GANHOU UM PREMIO DE 10 MIL MILHOES";
    }else{
         cout<<endl<<termcolor::on_bright_red<<termcolor::bright_white<<"VOCE PERDEU UM PREMIO DE 10 MIL MILHOES";
    }


    
 

}

