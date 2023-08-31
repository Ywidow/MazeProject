#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

void welcome(){ //Subrotina para dar boas vindas ao jogador.
  system("cls");

  cout << "Bem-Vindo ao trabalho de Algoritmos e Programa" << char(135) << char(198) << "o 2!!!" << endl;
  cout << endl << "         Tenha uma " << char(162)  << "tima experi" << char(136) <<"ncia!!!" << endl << endl << endl;
  cout << "     ";

  system("pause");
  system("cls");

}

void team(){ //Subrotina para o case 2 do switch.

  system("cls");

  cout << "Desenvolvedor: ";
  cout << "Guilherme Augusto Mafra Alves Thomy" << endl;
  cout << endl << "Professor: Thiago Felski Pereira" << endl;
  cout << endl << "Mat" << char(130) << "ria: Algoritmos e Programa" << char(135) << char(198) << "o II" << endl;
  cout << endl << "Data: Maio de 2023" << endl << endl;

  system("pause");
  system("cls");
}

void rules(){ //Subrotina para o case 3 do switch.
  system("cls");

  cout << "Regras: " << endl << endl;
  cout << "O jogo consiste no uso de l" << char(162) <<"gica e vis" << char(198) << "o do jogador..." << endl;
  cout << "O seu personagem '" << char(2) << "' ser" << char(160) << " movimentado por voc" << char(136) << "." << endl;
  cout << "O intuito do jogo " << char(130) <<" voc" << char(136) << " movimentar as caixas '" << char(254) << "' para seus locais alvo '" << char(177) << "'." << endl;
  cout << "A cada caixa colocada ser" << char(160) << " simbolizada com '" << char(158) << "' vence quando todas as caixas estiverem em locais alvo." << endl;
  cout << "Por" << char(130) << "m voc" << char(136) << " n" << char(198) << "o ser" << char(160) << " permitido atravessar paredes '" << char(219) << "'." << endl << endl;

  cout << "Controles:" << endl << endl;
  cout << "w ou ^: para cima" << endl;
  cout << "s ou v: para baixo" << endl;
  cout << "a ou <: para esquerda" << endl;
  cout << "d ou >: para direita" << endl; 
  cout << "4: sair do jogo ou retornar ao menu" << endl;

  cout << endl;

  system("pause");
  system("cls");

}

void bye(){ //Subrotina para o case 4 do switch.
  system("cls");
        
  cout << "Obrigado por utilizar nosso programa!!!" << endl;
  cout << endl << "\tVolte sempre!!! :)" << endl << endl;

  system("pause");
  system("cls");
}

void error404(){ //Subrotina para o default do switch.
  system("cls");

  cout << "Infelizmente esta op" << char(135) << char(198) << "o n" << char(198) << "o esta dispon" << char(161) << "vel no menu de intera" << char(135) << char(198) << "o...";
  cout << endl << endl << "Tente Novamente!!!" << endl << endl;

  system("pause");
  system("cls");
}

void winner(){ //Subrotina para aparecer uma mensagem caso o player ven�a.

  system("cls");

  cout << "PARAB" << char(144) << "NS VOC" << char(210) << " PREENCHEU TODOS OS LUGARES!!!" << endl;
  cout << endl << "       Obrigado por ter jogado!!!" << endl << endl;

  system("pause");
  system("cls");
}

void userAlreadyTaken(){ //Subrotina para aparecer uma mensagem caso ja tenha um user com este nome.
  system("cls");

  cout << "Este Username ja est" << char(160) << " sendo utilizado..." << endl << endl;

  system("pause");
  system("cls");
}

void noUserIdentified(){ //Subrotina para aparecer uma mensagem caso o user não seja encontrado no banco.
  system("cls");

  cout << "Username ou Password incorreta..." << endl << endl;
  cout << "Tente novamente ou cadastre-se no menu." << endl << endl;

  system("pause");
  system("cls");
}

void menuGame(COORD &coord, int choose, int rand, int moves){
  switch(choose){
    case 1:
      coord.X = 15;
      coord.Y = 2;
                
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

      cout << "Moves: " << moves;

      coord.Y = 4;

      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

      cout << "[4] sair";

      coord.X = 0;
      coord.Y = 0; 

      break;

    case 2:
      coord.X = 15;
      coord.Y = 2;
                
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

      cout << "Moves: " << moves;

      coord.Y = 4;

      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

      cout << "[4] sair";

      coord.X = 0;
      coord.Y = 0; 

      break;

    case 3:
      coord.X = 25;
      coord.Y = 5;
                
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

      cout << "Moves: " << moves;

      coord.Y = 7;

      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

      cout << "[4] sair";

      coord.X = 0;
      coord.Y = 0; 

      break;
  }

  switch(rand){
    case 1:
      coord.X = 15;
      coord.Y = 2;
                
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

      cout << "Moves: " << moves;

      coord.Y = 4;

      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

      cout << "[4] sair";

      coord.X = 0;
      coord.Y = 0; 

      break;

    case 2:
      coord.X = 15;
      coord.Y = 2;
                
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

      cout << "Moves: " << moves;

      coord.Y = 4;

      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

      cout << "[4] sair";

      coord.X = 0;
      coord.Y = 0; 

      break;

    case 3:
      coord.X = 25;
      coord.Y = 5;
                
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

      cout << "Moves: " << moves;

      coord.Y = 7;

      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

      cout << "[4] sair";

      coord.X = 0;
      coord.Y = 0; 

      break;
  }
  
  
}

void ImperialMarch(){
  int 
  c = 261,
  f = 349,
  gS = 415,
  a = 440,
  aS = 455,
  b = 466,
  cH = 523,
  cSH = 554,
  dH = 587,
  dSH = 622,
  eH = 659,
  fH = 698,
  fSH = 740,
  gH = 784,
  gSH = 830,
  aH =  880;

  Beep(a, 500);
  Beep(a, 500);    
  Beep(a, 500);
  Beep(f, 350);
  Beep(cH, 150);
  Beep(a, 500);
  Beep(f, 350);
  Beep(cH, 150);
  Beep(a, 1000);
      
  Beep(eH, 500);
  Beep(eH, 500);
  Beep(eH, 500);    
  Beep(fH, 350);
  Beep(cH, 150);
  Beep(gS, 500);
  Beep(f, 350);
  Beep(cH, 150);
  Beep(a, 1000);
  
  Beep(aH, 500);
  Beep(a, 350);
  Beep(a, 150);
  Beep(aH, 500);
  Beep(gSH, 250);
  Beep(gH, 250);
  
  Beep(fSH, 125);
  Beep(fH, 125);    
  Beep(fSH, 250);
  Beep(0,350);
  Beep(aS, 250);    
  Beep(dSH, 500);  
  Beep(dH, 250);  
  Beep(cSH, 250);  
  
  Beep(cH, 125);  
  Beep(b, 125);  
  Beep(cH, 250);      
  Beep(0,350);
  Beep(f, 125);  
  Beep(gS, 500);  
  Beep(f, 375);  
  Beep(a, 125);
  Beep(cH, 500);
  Beep(a, 375);  
  Beep(cH, 125);
  Beep(eH, 1000);
      
  Beep(aH, 500);
  Beep(a, 350);
  Beep(a, 150);
  Beep(aH, 500);
  Beep(gSH, 250);
  Beep(gH, 250);
  
  Beep(fSH, 125);
  Beep(fH, 125);    
  Beep(fSH, 250);
  Beep(0,250);
  Beep(aS, 250);    
  Beep(dSH, 500);  
  Beep(dH, 250);  
  Beep(cSH, 250);  
  
  Beep(cH, 125);  
  Beep(b, 125);  
  Beep(cH, 250);      
  Beep(0,250);
  Beep(f, 250);  
  Beep(gS, 500);  
  Beep(f, 375);  
  Beep(cH, 125);
   
  Beep(a, 500);            
  Beep(f, 375);            
  Beep(c, 125);            
  Beep(a, 1000);
}