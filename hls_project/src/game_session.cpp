#include <stdio.h>
//Variables Globales
int Board[3][3]={{1,1,0},{0,0,0},{0,0,0}};
bool jugador_out;
//Funcion para saber el turno del jugador
bool Check_jugador(){
  int jugadas=0;
  for ( int i = 0; i < 3; i = i + 1 ){
    for ( int j = 0; j < 3; j = j + 1 ){
      if(Board[i][j]!=0){
        jugadas=jugadas+1;
      }

    }
  }
  if(jugadas%2){
    jugador_out=true;
  }
  else{
    jugador_out=false;
  }
}




int main(int argc, char const *argv[]) {
  Check_jugador();
  printf("%d\n",jugador_out);
  return 0;
}
