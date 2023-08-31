#include <iostream>
#include <locale.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "Conditions.cpp"
#include "text.cpp"
#include "Colors.cpp"

#define RafaTAM 14 
#define RafaSZE 19 

using namespace std;

struct Player{
  string name, password;
  int moves;
};

struct Menu{
  int optionChoose, mapChoose, random, rank, menuSave;
  char tecla;
};

struct Conditions{
  bool win, exit;
};

struct Contadores{
  int winCounter, locationsBoxs, QuantityBoxsLocals, timesPlayed, sizeVetName, sizeVetMoves;
  int contador, mapMove, mapBring;
};

struct Field{
  int campo[RafaTAM][RafaSZE];
  int x, y;
};

struct fileVerificators{
  int search;
  string phrase;
};

struct matSize{
  int lines, columns;
};

struct Rank{
  string name2;
  int moves;
};

struct Cadastro{
  string username, password, confirmpassword;
  int menuChoose;
  bool cadastroConfirm;
};

struct Login{
  string username, password;
  bool userLog;
};

struct fileName{
  string file1, file2, file3;
  string relativePath;
};

int LinesCampo(Menu choose, matSize tamanho){ //Subortina para identificar o número de linhas de determinado mapa.
  if(choose.mapChoose == 1 || choose.random == 1){ //Campo do Gui.
    return tamanho.lines;
  }

  else if(choose.mapChoose == 2 || choose.random == 2){ //Campo do Mario.
    return tamanho.lines; 
  }

  else if(choose.mapChoose == 3 || choose.random == 3){
    return tamanho.lines;
  }

  return false;
}

int ColumnsCampo(Menu choose, matSize tamanho){ //Subrotina para identificar o número de colunas de determinado mapa.
  if(choose.mapChoose == 1 || choose.random == 1){ //Campo do Gui.
    return tamanho.columns;
  }

  else if(choose.mapChoose == 2 || choose.random == 2){ //Campo do Mario.
    return tamanho.columns; 
  }

  else if(choose.mapChoose == 3 || choose.random == 3){
    return tamanho.columns;
  }

  return false;
}

void PassMap(string path, matSize &tamanho, Field &camp){ //Subrotina para setar o número de linhas/colunas e a matriz.
  fileVerificators procura;
  ifstream file;

  file.open(path);

  if(file.is_open()){
    while(file.eof() == false){
      file >> procura.search;
      tamanho.lines = procura.search;

      file >> procura.search;
      tamanho.columns = procura.search;
        
      file >> procura.search;
      camp.x = procura.search;
      
      file >> procura.search;
      camp.y = procura.search;
    
      for(int lines = 0; lines < tamanho.lines; lines++){
        for(int columns = 0; columns < tamanho.columns; columns++){
          file >> procura.search;

          camp.campo[lines][columns] = procura.search;
        }
      }
    }

    file.close();
  }
  else{
    system("cls");

    cout << "Infelizmente não foi possível abrir o arquivo para leitura (PassMap)..."<< endl << endl;
    cout << "Tente novamente mais tarde..." << endl << endl;

    system("pause");
    system("cls");
  }
}

void chooseCampo(Menu &choose, Field &camp, Player &jogador, Conditions &conditions, matSize &tamanho){ //Subrotina para a escolha de campo.
  fileVerificators procura;
  ifstream file;
  string path;

  switch(choose.mapChoose){ //Switch da escolha do mapa.
    case 1: //Mapa do Guilherme.
      path = "Mapas/Boxxle1(4).txt";

      PassMap(path, tamanho, camp);

      jogador.moves = 0;
      conditions.win = false;
      choose.random = 0;
      break;

    case 2: //Mapa do Mario.
      path = "Mapas/Minicosmos1(1).txt";

      PassMap(path, tamanho, camp);

      jogador.moves = 0;
      conditions.win = false;
      choose.random = 0;
      break;

    case 3: //Mapa do Rafa.
      path = "Mapas/Original&extra 4.txt";

      PassMap(path, tamanho, camp);

      jogador.moves = 0;
      conditions.win = false;
      choose.random = 0;

      break;

    case 4: //Mapa Aleatório.
      srand(time(NULL));

      choose.random = 0;
      choose.random = rand() % 3 + 1; //Gerar número aleatório para escolher o mapa.

      switch(choose.random){
        case 1:
          path = "Mapas/Boxxle1(4).txt";
          
          PassMap(path, tamanho, camp);

          jogador.moves = 0;
          conditions.win = false;

          break;

        case 2:
          path = "Mapas/Minicosmos1(1).txt";

          PassMap(path, tamanho, camp);

          jogador.moves = 0;
          conditions.win = false;

          break;

        case 3:
          path = "Mapas/Original&extra 4.txt";

          PassMap(path, tamanho, camp);

          jogador.moves = 0;
          conditions.win = false;
          break;
      }

      break;

    case 5:
      system("cls");

      cout << "Retornando ao menu!!!" << endl << endl;

      system("pause");
      system("cls");

      break;
              
    default:
      system("cls");

      cout << "Infelizmente esta op" << char(135) << char(198) << "o n" << char(198) << "o est" << char(161) << " valida :(" << endl << endl;
                
      system("cls");

      break;
  }
}

void printMap(COORD coord, Menu choose, Field camp, Contadores &counter, matSize tamanho){ //Subortina para imprimir o mapa.

  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //Posiciona a escrita no inï¿½cio do console.

  //Imprime o jogo: mapa e personagem.
  for(int lines = 0; lines < LinesCampo(choose, tamanho); lines++){
    for(int columns = 0; columns < ColumnsCampo(choose, tamanho); columns++){
      if(counter.locationsBoxs == 0){ //Condição para caso a matriz esteja sendo impressa pela primeira vez.

        if(camp.campo[lines][columns] == 3){ //Condição para identificar os "locais de caixas" na matriz.
          counter.QuantityBoxsLocals++; //Contador para saber a quantidade de "locais de caixas".

        }
      }

      if(lines == camp.x && columns == camp.y){ //Condição para caso as coordenadas da matriz sejam iguais as coordenadas do personagem.
        colors(15,0);
        
        cout << char(2); //Impressão do personagem.

        colors(7,0);

      } 
                    
      else{ //Impressão do mapa.
        switch (camp.campo[lines][columns]){
          case 0: //Impressão dos "vazios".
            cout << " "; 

            break; 
                            
          case 1: 
            colors(15,0);

            cout << char(219); //Impressão das "paredes".

            colors(7,0);

            break;

          case 2:
            colors(6,0);

            cout << char(254); //Impressão das "caixas".

            colors(7,0);

            break; 

          case 3:
            cout << char(177); //Impressão dos "locais de caixas".

            break;

          case  4:
            colors(4,0);

            cout << char(158); //Impressão das "locais com caixas".

            colors(7,0);

            break;

          case 5:
            colors(2,0);

            cout << char(254);

            colors(7,0);

            break;

          case 6:
            colors(2,0);

            cout << char(177);

            colors(7,0);

            break;
          
          case 7:
            colors(2,0);

            cout << char(158);

            colors(7,0);

            break;
            //default: cout<<"-"; //erro
        } //fim switch
      }
    }

    cout<<"\n";
  } //fim for mapa
}

void PassRecord(Player jogador, string path){ //Subrotina  para escrever os recordes dos jogadores. 
  ofstream arquivo;

  arquivo.open(path, ios_base::app);

  if(arquivo.is_open()){ 
    arquivo << "<Name>" << endl;
    arquivo << "\t" << jogador.name << endl;
    arquivo << "<Moves>" << endl;
    arquivo << "\t" << jogador.moves << endl << endl;
  }
  else{
    system("cls");

    cout << "Deu ruim ao abrir pra escrever" << endl << endl;

    system("pause");
    system("cls");
  }

  arquivo.close();
}

void recordSet(Menu choose, Player jogador, Conditions conditions){ //Subrotina para chamar PassRecord
  ofstream arquivo;
  string path;

  if(choose.mapChoose == 1 || choose.random == 1){
    path = "Recordes/Boxxle1(4).txt";
  }

  if(choose.mapChoose == 2 || choose.random == 2){
    path = "Recordes/Minicosmos1(1).txt";
  }

  if(choose.mapChoose == 3 || choose.random == 3){
    path = "Recordes/Original&extra 4.txt";
  }

  PassRecord(jogador, path);
}

void PassSaveRecord(Rank *rank, string path){ //Subrotina para criar um vetor dinamico de ranking.
  ifstream file;
  fileVerificators procura;

  Contadores counter;
  counter.contador = 0;

  file.open(path);

  if(file.is_open()){
    while(file.eof() == false){
      file >> procura.phrase;

      if(procura.phrase == "<Name>"){
        file >> procura.phrase;
        rank[counter.contador].name2 = procura.phrase;
        file >> procura.phrase;

        if(procura.phrase == "<Moves>"){
          file >> procura.search;
          rank[counter.contador].moves = procura.search;
          counter.contador++;
        }
      }
    }
  }
  else{
    system("cls");

    cout << "Infelizmente o file do Rank não abriu(PassSaveRecord)..." << endl << endl;

    system("pause");
    system("cls");
  }

    file.close();
}

int PassSaveRecordCounter(string path){ //Subrotina para setar o contador do tamanho do vetor dinamico ranking. 
  ifstream file;
  fileVerificators procura;
  int contador;
  contador = 0;
  
  file.open(path);

    if(file.is_open()){
      while(file.eof() == false){
        file >> procura.phrase;

        if(procura.phrase == "<Name>"){
          contador++;
        }
      }
    }
    else{
      system("cls");

      cout << "Infelizmente o file do Rank1 não abriu..." << endl << endl;

      system("pause");
      system("cls");
    }

    file.close();

    return contador;
}

void recordSave(Menu choose, Player jogador){ //Subrotina para criar o vetor dinamico e organiza-lo.
  ifstream file;
  Contadores counter;
  counter.sizeVetMoves = 0;
  fileVerificators procura;
  Rank *rank;
  int varAux;
  string varAuxString, path;

  if(choose.rank == 1){
    path = "Recordes/Boxxle1(4).txt";
  }

  if(choose.rank == 2){
    path = "Recordes/Minicosmos1(1).txt";
  }

  if(choose.rank == 3){
    path = "Recordes/Original&extra 4.txt";
  }

  counter.sizeVetMoves = PassSaveRecordCounter(path);

  rank = new Rank[counter.sizeVetMoves + 1];

  PassSaveRecord(rank, path);

  for(int i = 0; i < counter.sizeVetMoves; i++){
    for(int j = i + 1; j < counter.sizeVetMoves; j++){
      
      if(rank[j].moves < rank[i].moves){
        varAux = rank[i].moves;
        rank[i].moves = rank[j].moves;
        rank[j].moves = varAux;

        varAuxString = rank[i].name2;
        rank[i].name2 = rank[j].name2;
        rank[j].name2 = varAuxString;
      }
    }
  }

  for(int i = 0; i < counter.sizeVetMoves; i++){
    cout << rank[i].name2;
    cout << "..............." << rank[i].moves << endl << endl;
  }

  delete []rank;
}

void PassSaveGame(Contadores &counter, Field camp, Player jogador, matSize tamanho, Menu choose, string path){ //Escrever em arquivo para voltar posição
  ofstream arquivo;

  arquivo.open(path, ios_base::app);

  if(arquivo.is_open()){
    arquivo << "<Move>: " << counter.mapMove << endl;
    arquivo << "<Mat>" << endl;

    for(int lines = 0; lines < LinesCampo(choose, tamanho); lines++){
      for(int columns = 0; columns < ColumnsCampo(choose, tamanho); columns++){
        arquivo << camp.campo[lines][columns] << " ";
      }
      arquivo << endl;
    }

    arquivo << endl;

    arquivo << "<Moves>" << endl;
    arquivo << jogador.moves << endl << endl;

    arquivo << "<winCounter>" << endl;
    arquivo << counter.winCounter << endl << endl;

    arquivo << "<Position>" << endl;
    arquivo << "\t<X>" << endl;
    arquivo << "\t\t" << camp.x << endl;
    arquivo << "\t<Y>" << endl;
    arquivo << "\t\t" << camp.y << endl << endl;
  }
  else{
    system("cls");

    cout << "Não foi possível abrir o arquivo 1 para salvar..." << endl << endl;

    system("pause");
    system("cls");
  }

  arquivo.close();
}

void saveGame(Field camp, Player jogador, Contadores &counter, Menu choose, matSize tamanho){ //Subrotina para chamar subrotina PassSaveGame.
  ofstream arquivo;
  string path;
  counter.mapMove++;

  if(choose.mapChoose == 1 || choose.random == 1){
    path = "Saves/Boxxle1(4).txt";
  }

  if(choose.mapChoose == 2 || choose.random == 2){
    path = "Saves/Minicosmso1(1).txt";
  }

  if(choose.mapChoose == 3 || choose.random == 3){
    path = "Saves/Original&extra 4.txt";
  }

  PassSaveGame(counter, camp, jogador, tamanho, choose, path);
}

void PassReturnMove(Field &camp, Player &jogador, Contadores &counter, matSize tamanho, string path, Menu choose){ //Subrotina para passar os valores da pasta de voltar movimento.
  ifstream file;
  fileVerificators procura;

  file.open(path);
  
    if(file.is_open()){
      while(file.eof() == false){
        file >> procura.phrase;
        
        if(procura.phrase == "<Move>:"){
          file >> procura.search;

          if(procura.search == counter.mapMove){
            file >> procura.phrase;

            if(procura.phrase == "<Mat>"){
              for(int lines = 0; lines < LinesCampo(choose, tamanho); lines++){
                for(int columns = 0; columns < ColumnsCampo(choose, tamanho); columns++){
                  file >> procura.search;
                  camp.campo[lines][columns] = procura.search;
                }
              }

              file >> procura.phrase;

              if(procura.phrase == "<Moves>"){
                file >> procura.search;

                jogador.moves = procura.search;

                file >> procura.phrase;

                if(procura.phrase == "<winCounter>"){
                  file >> procura.search;

                  counter.winCounter = procura.search;

                  file >> procura.phrase;

                  if(procura.phrase == "<Position>"){
                    file >> procura.phrase;

                    if(procura.phrase == "<X>"){
                      file >> procura.search;

                      camp.x = procura.search; 

                      file >> procura.phrase;

                      if(procura.phrase == "<Y>"){
                        file >> procura.search;

                        camp.y = procura.search;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else{
      system("cls");

      cout << "Infelizmente não foi possível abrir o arquivo para return(PassReturnMove)..." << endl;
      
      system("pause");
      system("cls");
    }

    file.close();
}

void returnMove(Field &camp, Player &jogador, Contadores &counter, Menu choose, matSize tamanho){ //Subrotina para chamar a Subrotina PassReturnMove.
  string path;

  counter.mapMove--;
  if(choose.mapChoose == 1 || choose.random == 1){
    path = "Saves/Boxxle1(4).txt";
  }

  if(choose.mapChoose == 2 || choose.random == 2){
    path = "Saves/Minicosmso1(1).txt";
  }

  if(choose.mapChoose == 3 || choose.random == 3){
    path = "Saves/Original&extra 4.txt";
  }

  PassReturnMove(camp, jogador, counter, tamanho, path, choose);
}

void coordAlteration(Field &camp, int getchIdentificationX, int getchIdentificationY, Player &jogador){ //Subrotina para o deslocamento da posição do personagem em relação a aï¿½ï¿½o desejada.

  if(getchIdentificationX == -1){
    camp.x--;
    jogador.moves++;
  }

  else if(getchIdentificationX == 1){
    camp.x++;
    jogador.moves++;
  }

  if(getchIdentificationY == -1){
    camp.y--;
    jogador.moves++;
  }

  else if(getchIdentificationY == 1){
    camp.y++;
    jogador.moves++;
  }

}

void doMoves(Field &camp, Player &jogador, Contadores &counter, Menu choose, matSize tamanho, int getchIdentificationX, int getchIdentificationY){ //Subrotina para as condições de aï¿½ï¿½o do jogo.

  if(wallIdentifier(camp.campo[camp.x + getchIdentificationX][camp.y + getchIdentificationY])){ //Condiï¿½ï¿½o para nï¿½o entrar em "parede".
                    
    if(moveBoxEmpty(camp.campo[camp.x + getchIdentificationX][camp.y + getchIdentificationY], camp.campo[camp.x + 2 * getchIdentificationX][camp.y + 2 * getchIdentificationY])){ //Condiï¿½ï¿½o para movimentar a caixa com lugar vazio a cima || baixo || esquerda || direita.
      camp.campo[camp.x + getchIdentificationX][camp.y + getchIdentificationY] = 0;
      camp.campo[camp.x + 2 * getchIdentificationX][camp.y + 2 * getchIdentificationY] = 2;

      coordAlteration(camp, getchIdentificationX, getchIdentificationY, jogador);

      saveGame(camp, jogador, counter, choose, tamanho);
      Beep(750, 100);
    }

    else if(boxInLocal(camp.campo[camp.x + getchIdentificationX][camp.y + getchIdentificationY], camp.campo[camp.x + 2 * getchIdentificationX][camp.y + 2 * getchIdentificationY])){ //Condiï¿½ï¿½o para alterar caracter da caixa no local.
      camp.campo[camp.x + getchIdentificationX][camp.y + getchIdentificationY] = 0;
      camp.campo[camp.x + 2 * getchIdentificationX][camp.y + 2 * getchIdentificationY] = 4;
                      
      counter.winCounter++; //Condiï¿½ï¿½o para ganhar um winCounter caso a "caixa" saia do "lugar de caixa".
      coordAlteration(camp, getchIdentificationX, getchIdentificationY, jogador);

      saveGame(camp, jogador, counter, choose, tamanho);
    }

    else if(boxInLocal2Local(camp.campo[camp.x + getchIdentificationX][camp.y  + getchIdentificationY], camp.campo[camp.x + 2 * getchIdentificationX][camp.y + 2 * getchIdentificationY])){ //Condiï¿½ï¿½o para poder alterar a "caixa" dentro de um "local" para outro "local" vazio acima || abaixo || direita || esquerda.
      camp.campo[camp.x + getchIdentificationX][camp.y + getchIdentificationY] = 3;
      camp.campo[camp.x + 2 * getchIdentificationX][camp.y + 2 * getchIdentificationY] = 4;

      coordAlteration(camp, getchIdentificationX, getchIdentificationY, jogador);

      saveGame(camp, jogador, counter, choose, tamanho);
    }

    else if(boxInLocal2Empty(camp.campo[camp.x + getchIdentificationX][camp.y + getchIdentificationY], camp.campo[camp.x + 2 * getchIdentificationX][camp.y + 2 * getchIdentificationY])){ //Condiï¿½ï¿½o para mover a caixa de "local com caixa" para "livre"
      camp.campo[camp.x + getchIdentificationX][camp.y + getchIdentificationY] = 3;
      camp.campo[camp.x + 2 * getchIdentificationX][camp.y + 2 * getchIdentificationY] = 2;

      counter.winCounter--; //Condição para perder um winCounter caso a "caixa" saia do "lugar de caixa".
      coordAlteration(camp, getchIdentificationX, getchIdentificationY, jogador);

      saveGame(camp, jogador, counter, choose, tamanho);
      Beep(750, 100);
    }

    else if(dontMoveBox(camp.campo[camp.x + getchIdentificationX][camp.y + getchIdentificationY], camp.campo[camp.x + 2 * getchIdentificationX][camp.y + 2 * getchIdentificationY])){ //Condiï¿½ï¿½o para nï¿½o movimentar a caixa caso haja uma "caixa2", "local com caixa" ou "parede". 
      coordAlteration(camp, getchIdentificationX, getchIdentificationY, jogador);

      saveGame(camp, jogador, counter, choose, tamanho);
    }

    if(beFree(camp.campo[camp.x + getchIdentificationX][camp.y + getchIdentificationY])){ //Condiï¿½ï¿½o para se movimentar caso cima || baixo || direita || esquerda for "livre" ou "local de caixa".
      coordAlteration(camp, getchIdentificationX, getchIdentificationY, jogador);

      saveGame(camp, jogador, counter, choose, tamanho);
    }
  }
}

void startMoves(Menu choose, Field &camp, Player &jogador, Contadores &counter, Conditions &conditions, matSize tamanho){ //Subortina para o começo dos identificadores de aï¿½ï¿½o.
  int getchIdentificationX = 0, getchIdetificationY = 0; //Identificadores de movimentação em relação a tecla pressionada

  switch(choose.tecla){
    case 72: case 'w': //Cima.
      getchIdentificationX = -1;
      getchIdetificationY = 0;

      doMoves(camp, jogador, counter, choose, tamanho, getchIdentificationX, getchIdetificationY); 
      
      break;
                    
    case 80: case 's': //Baixo.
      getchIdentificationX = 1;
      getchIdetificationY = 0;

      doMoves(camp, jogador, counter, choose, tamanho, getchIdentificationX, getchIdetificationY); 

      break;
                    
    case 75:case 'a': //Esquerda.
      getchIdentificationX = 0;
      getchIdetificationY = -1;

      doMoves(camp, jogador, counter, choose, tamanho, getchIdentificationX, getchIdetificationY); 
                  
      break;
                    
    case 77: case 'd': //Direita.
      getchIdentificationX = 0;
      getchIdetificationY = 1;

      doMoves(camp, jogador, counter, choose, tamanho, getchIdentificationX, getchIdetificationY); 

      break;

    case '4': //Condição para o player poder sair quando quiser do jogo ao pressionar a tecla "4".
      conditions.exit = true;

      system("cls");

      break;

    case 'p':
      returnMove(camp, jogador, counter, choose, tamanho);

      break;

    case 'i':
      ImperialMarch();

      break;
  }         
}

bool WIN(Contadores counter, Menu choose, Player jogador, Conditions conditions){ //Subrotina para que ocorra o encerramento do mapa.

  if(counter.winCounter == counter.QuantityBoxsLocals){ //Condição para quando o contador da vitï¿½ria for igual a quantidade de caixas no local o jogo encerrar.
    winner();
    recordSet(choose, jogador, conditions);

    return true;
  }

  else{
    return false;
  }
}

void reset(Conditions &conditions, Contadores &counter){ //Subrotina para resetar os elementos de "New Game".
  conditions.exit = false;
  counter.winCounter = 0;
  counter.locationsBoxs = 0;
  counter.QuantityBoxsLocals = 0;
  counter.mapMove = 0;
}

void resetSave(Menu choose){ //Subrotina para resetar o save de continuar.
  ofstream arquivo;

  if(choose.mapChoose == 1 || choose.random == 1){
    arquivo.open("Saves/Boxxle1(4).txt", ios_base::out|ios_base::trunc);

    arquivo.close();
  }

  if(choose.mapChoose == 2 || choose.random == 2){
    arquivo.open("Saves/Minicosmso1(1).txt", ios_base::out|ios_base::trunc);

    arquivo.close();
  }
  
  if(choose.mapChoose == 3 || choose.random == 3){
    arquivo.open("Saves/Original&extra 4.txt", ios_base::out|ios_base::trunc);

    arquivo.close();
  }
}

void menuGame(COORD &coord, Player jogador, matSize tamanho){ //Subrotina para escrever no front da gameplay.
  coord.X = tamanho.lines * 2 - 1;
  coord.Y = tamanho.columns / 4;
                
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

  cout << "Moves: " << jogador.moves << "    ";

  coord.Y = tamanho.columns / 4 + 2;

  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

  cout << "[4] sair";

  coord.Y = tamanho.columns / 4 + 4;

  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

  coord.X = 0;
  coord.Y = 0; 
}

int main(){

  ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, A SEGUIR.
        //INÍCIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO     cursorInfo;
        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = false; // set the cursor visibility
        SetConsoleCursorInfo(out, &cursorInfo);
        //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
        //INÍCIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
        short int CX=0, CY=0;
        COORD coord;

        coord.X = CX;
        coord.Y = CY;
        //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, ACIMA.

  Player jogador;
  Menu choose;
  Contadores counter;
  Field camp;
  matSize tamanho;
  Cadastro cadastro;
  Login login;
  ifstream file;
  ofstream arquivo;
  fileVerificators procura;
  
  counter.locationsBoxs = 0;
  counter.QuantityBoxsLocals = 0;
  counter.timesPlayed = 0;
  counter.winCounter = 0;
  counter.mapMove = 0;

  Conditions conditions; //Condições de encerramento.

  conditions.exit = false;
  conditions.win = false;

  welcome(); //Chama a subrotina welcome.

  do{
    system("cls");

    cout << "[1] Login" << endl;
    cout << "[2] Cadastro" << endl;
    cout << "[3] Sair" << endl;
    cout << "Escolha: ";
    cin >> cadastro.menuChoose;

    switch(cadastro.menuChoose){
      case 1:
        system("cls");

        cout << "\t\tBem-Vindo ao Login" << endl << endl;

        cout << "Username: ";
        cin >> login.username;

        cout << endl << "Password: ";
        cin >> login.password;

        file.open("Cadastro/Cadastro.txt");

        if(file.is_open()){
          login.userLog = false;

          while(file.eof() == false){
            file >> procura.phrase;

            if(procura.phrase == "<Name>"){
              file >> procura.phrase;

              if(login.username == procura.phrase){
                file >> procura.phrase;

                if(procura.phrase == "<Password>"){
                  file >> procura.phrase;

                  if(login.password == procura.phrase){
                    login.userLog = true;
                  }
                }
              }
            }
          }
        }
        else{
          system("cls");

          cout << "Não foi possível abrir o file de leitura de login..." << endl << endl;

          system("pause");
          system("cls");
        }

        file.close();

        if(login.userLog == false){
          system("cls");

          cout << "Username ou Password incorreta..." << endl << endl;
          cout << "Tente novamente ou cadastre-se no menu." << endl << endl;

          system("pause");
          system("cls");
        }

        else{
          jogador.name = login.username;

          system("cls");

          cout << "Bem-vindo " << jogador.name << "!!!" << endl << endl;

          system("pause");
          system("cls");

          do{ //Laço de repetição para o menu de interação.
            system("cls");

            cout << "[1] Novo Jogo" << endl;
            cout << "[2] Continuar" << endl;
            cout << "[3] Sobre" << endl;
            cout << "[4] Recordes" << endl;
            cout << "[5] Sair" << endl;
            cout << "Escolha: ";
            cin >> choose.optionChoose; 

            switch(choose.optionChoose){ //Switch para as escolhas do jogador.
              case 1: case 2: //Escolha para iniciar o jogo.

              reset(conditions, counter); //Chama a subrotina reset
          
              if(choose.optionChoose == 1){ //Condição para caso a pessoa tenha começado o jogo.

                do{ //Laço para a escolha do mapa.
                  system("cls");
              
                  cout << "Escolha seu mapa: " << endl << endl;
                  cout << "[1] Boxxle1(4)" << endl;
                  cout << "[2] Minicosmos1(1)" << endl;
                  cout << "[3] Original&extra 4" << endl;
                  cout << "[4] Aleat" << char(162) << "rio" << endl;
                  cout << "[5] Menu" << endl << endl;
                  cout << "Escolha: ";
                  cin >> choose.mapChoose; //Entrada da escolha do mapa.

                  system("cls");

                  chooseCampo(choose, camp, jogador, conditions, tamanho);

                  resetSave(choose);
                }
                while(choose.mapChoose != 1 && choose.mapChoose != 2 && choose.mapChoose != 3 && choose.mapChoose != 4 && choose.mapChoose != 5); //Condição para ele escolher o mapa.
              }

              if((choose.optionChoose == 1 || counter.timesPlayed > 0) && conditions.win == false && choose.mapChoose != 5){ //Condição para que o jogo não comece caso tenham escolhido continuar.
                system("cls");

                cout << "!#%$ï¿½@&! QUE COMECEM OS JOGOS !#%$ï¿½@&!" << endl << endl; //Referência a jogos vorazes.

                system("pause");
                system ("cls");

                while(conditions.win != true && conditions.exit != true){ //Condições para o jogo rodar.
              
                  printMap(coord, choose, camp, counter, tamanho);

                  counter.locationsBoxs++; //Contador para poder saber quantas vezes o campo foi impresso.

                  menuGame(coord, jogador, tamanho);

                  if(_kbhit()){ //Executa os movimentos.
                    choose.tecla = getch();

                    startMoves(choose, camp, jogador, counter, conditions, tamanho);
                  }

                  conditions.win = WIN(counter, choose, jogador, conditions);
                } //fim do laço do jogo

                counter.timesPlayed++;
              } //fim if new game

              else{
                system("cls");

                cout << "Infelizmente n" << char(198) << "o possu" << char(161) << "mos um jogo seu em nossa mem" << char(162) << "ria :(" << endl;
                cout << endl;
                system("pause");
                system("cls"); 
              } 

              break;

            case 3: //Escolha para mostrar as regras do jogo.
            
              team();
            
              rules(); //Chama a subrotina rules.

              break;

            case 4:
              system("cls");

              cout << "Escolha o Mapa: " << endl << endl;
              cout << "[1] Boxxle1(4)" << endl;
              cout << "[2] Minicosmos1(1)" << endl;
              cout << "[3] Original&extra 4" << endl;
              cout << "Escolha: ";
              cin >> choose.rank;

              switch(choose.rank){
                case 1:
                  system("cls");

                  cout << "\t Recordes do Mapa: Boxxle1(4): " << endl << endl;

                  recordSave(choose, jogador);

                  system("pause");
                  system("cls");

                  break;

                case 2:
                  system("cls");

                  cout << "\t Recordes do Mapa: Minicosmos1(1): " << endl << endl;

                  recordSave(choose, jogador);

                  system("pause");
                  system("cls");
                
                  break;

                case 3:
                  system("cls");

                  cout << "\t Recordes do Mapa: Original&extra 4: " << endl << endl;
                  recordSave(choose, jogador);

                  system("pause");
                  system("cls");

                  break;

                default:
                  error404();

                  break;
              }

              break;

            case 5: //Escolha para mostrar mensagem quando o jogador sair.
              system("cls");

              cout << "Retornando ao menu..." << endl << endl;

              system("pause");
              system("cls");

              break;

            default: //Opção para caso não seja um dos cases.
              error404(); //Chama a subrotina error404.

              break;
            }

          }
          while(choose.optionChoose != 5); //Condição para que encerre o menu de interação.
        }

        break;

      case 2:
        system("cls");
        
        cout << "\t\tBem Vindo ao Cadastro" << endl << endl;

        cout << "Username: ";
        cin >> cadastro.username;

        cout << endl << "Password: ";
        cin >> cadastro.password;
        
        cout << endl << "Confirm Password: ";
        cin >> cadastro.confirmpassword;

        file.open("Cadastro/Cadastro.txt");

        if(file.is_open()){
          cadastro.cadastroConfirm = true;

          while(file.eof() == false){
            file >> procura.phrase;

            if(procura.phrase == "<Name>"){
              file >> procura.phrase;

              if(procura.phrase == cadastro.username){
                cadastro.cadastroConfirm = false;
              }
            }
          }
        }
        else{
          system("cls");

          cout << "Nï¿½o foi possï¿½vel abrir o file de leitura de cadastro..." << endl << endl;

          system("pause");
          system("cls");
        }

        file.close();

        if(cadastro.cadastroConfirm && cadastro.password == cadastro.confirmpassword){
          system("cls");

          cout << "Cadastro feito com sucesso!!!" << endl << endl;

          system("pause");
          system("cls");

          arquivo.open("Cadastro/Cadastro.txt", ios_base::app);

          arquivo << "<Name>" << endl;
          arquivo << "\t" << cadastro.username << endl;
          arquivo << "<Password>" << endl;
          arquivo << "\t" << cadastro.password << endl << endl;

          arquivo.close();
        }
        else if(cadastro.password != cadastro.confirmpassword){
          system("cls");

          cout << "As senhas n" << char(198) << "o batem..." << endl << endl;

          system("pause");
          system("cls");

        }
        else{
          userAlreadyTaken();
        }

        break;

      case 3:
        bye();

        break;

      default:
        error404();
        break;
    }
  }
  while(cadastro.menuChoose != 3); 

  return 0;
}
