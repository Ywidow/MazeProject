#include <iostream>
#include <locale.h>
#include <windows.h>

bool emptyIdentifier(int check){ //Subrotina para identificar "vazio" na posi��o fornecida,
  if(check == 0){
    return true;
  }

  else{
    return false;
  }
}

bool wallIdentifier(int check){ //Subrotina para identificar "parede" na posi��o fornecida.

  if(check != 1){
    return true;
  }

  else{
    return false;
  }

}

bool boxIdentifier(int check){ //Subrotina para identificar "caixa" na posi��o fornecida.
  
  if(check == 2){
    return true;
  }

  else{
    return false;
  }
}

bool moveBoxEmpty(int check, int check2){ //Subrotina para condi��o de movimento da caixa para "vazio".

  if(boxIdentifier(check) && emptyIdentifier(check2)){
    return true;
  }

  else{
    return false;
  }
}

bool boxInLocal(int check, int check2){ //Subrotina para condi��o da altera��o do caracter do "local com caixa".

  if(boxIdentifier(check) && check2 == 3){
    return true;
  }

  else{
    return false;
  }
}

bool boxInLocal2Local(int check, int check2){ //Subrotina para condi��o de mover "local com caixa" para "local de caixa"

  if(check == 4 && check2 == 3){
    return true;
  }

  else{
    return false;
  }
}


bool boxInLocal2Empty(int check, int check2){ //Subrotina para condi��o para mover "local com caixa" para "vazio".

  if((check == 4 || check == 5) && emptyIdentifier(check2)){
    return true;
  }

  else{
    return false;
  }
}

bool dontMoveBox(int check, int check2){ //Subrotina para condi��o de n�o mover a "caixa" caso haja uma outra "caixa", "parede" ou "local com caixa".

  if(boxIdentifier(check) && boxIdentifier(check2) == false && check2 != 4 && wallIdentifier(check2)){
    return true;
  }

  else{
    return false;
  }
}

bool beFree(int check){ //Subrotina para condi��o de poder se mover em "vazio" ou "local de caixa".  
  if(emptyIdentifier(check) || check == 3 || check == 6){
    return true;
  }

  else{
    return false;
  }
}
