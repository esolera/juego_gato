#include <stdio.h>
#include <iostream>
//Variables Globales
int Board[3][3]={{0,0,0},{0,0,0},{0,0,0}};
bool jugador_out;
int posicion;
bool valido;
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
  if(jugadas%2 == 0){
    jugador_out=true;
  }
  else{
    jugador_out=false;
  }
}

bool Valid_move(){
  if(posicion<=2){
    if(Board[0][posicion]!=0){
      valido=false;
    }
    else{
      valido=true;
    }
  }
  else if(posicion<=5){
    if(Board[1][posicion-3]!=0){
      valido=false;
    }
    else{
      valido=true;
    }
  }
  else if(posicion<=8){
    if(Board[2][posicion-6]!=0){
      valido=false;
    }
    else{
      valido=true;
    }
  }
  else {
    valido=false;
  }
}

int update_State(int posicion, bool jugador) {
	int jugador_value;
	if (jugador) {
		jugador_value = 1;
	}
	else {
		jugador_value = 2;
	}

	if(posicion <=2) {
		Board[0][posicion] = jugador_value;
	}
	else if(posicion <= 5){
		Board[1][posicion-3] = jugador_value;
	}
	else if(posicion <= 8){
		Board[2][posicion-6] = jugador_value;
	}
	return 0;
}

bool ganador(){
  for ( int i = 0; i < 3; i = i + 1 ){
    if(((Board[i][0] && Board[i][1] && Board[i][2])==1) || ((Board[i][0] && Board[i][1] && Board[i][2])==2) || ((Board[0][i] && Board[1][i] && Board[2][i])==1) || ((Board[0][i] && Board[1][i] && Board[2][i])==2)){
      return true;
    }
  }
  if(((Board[0][0]*Board[1][1]*Board[2][2])==1) || ((Board[0][0]*Board[1][1]*Board[2][2])==8) || ((Board[0][2]*Board[1][1]*Board[2][0])==8) || ((Board[0][2]*Board[1][1]*Board[2][0])==1)){
    return true;

  }
  else{
    return false;
  }

}

bool empate(){
	for (int i = 0; i < 3; i = i + 1) {
		for (int j = 0; i < 3; i = i + 1) {
			if(Board[i][j]) {
				return false;
			}
		}
	}
	return true;
}

/* Prueba Valid_move *//*
int main(int argc, char const *argv[]) {
  std::cin >> posicion;
  Valid_move();
  printf("%d\n",valido);
  return 0;
}
*/
int main(int argc, char const *argv[]) {
  for (int a = 0; a < 3; a = a + 1 ){
    for (int b = 0; b < 3; b = b + 1 ){
      Board[a][b]=1;
      std::cout << Board[0][0] << Board[0][1] << Board[0][2] << '\n';
      std::cout << Board[1][0] << Board[1][1] << Board[1][2] << '\n';
      std::cout << Board[2][0] << Board[2][1] << Board[2][2] << '\n';
      std::cout << ganador() << '\n';
      if(b==2){
        Board[a][0]=0;
        Board[a][1]=0;
        Board[a][2]=0;
      }

    }

  }

  for (int a = 0; a < 3; a = a + 1 ){
    for (int b = 0; b < 3; b = b + 1 ){
      Board[b][a]=1;
      std::cout << Board[0][0] << Board[0][1] << Board[0][2] << '\n';
      std::cout << Board[1][0] << Board[1][1] << Board[1][2] << '\n';
      std::cout << Board[2][0] << Board[2][1] << Board[2][2] << '\n';
      std::cout << ganador() << '\n';
      if(b==2){
        Board[0][a]=0;
        Board[1][a]=0;
        Board[2][a]=0;
      }

    }

  }
  Board[0][0]=1;
  Board[1][1]=1;
  Board[2][2]=1;
  std::cout << Board[0][0] << Board[0][1] << Board[0][2] << '\n';
  std::cout << Board[1][0] << Board[1][1] << Board[1][2] << '\n';
  std::cout << Board[2][0] << Board[2][1] << Board[2][2] << '\n';
  std::cout << ganador() << '\n';
  Board[0][0]=0;
  Board[1][1]=0;
  Board[2][2]=0;


  Board[0][2]=1;
  Board[1][1]=1;
  Board[2][0]=1;
  std::cout << Board[0][0] << Board[0][1] << Board[0][2] << '\n';
  std::cout << Board[1][0] << Board[1][1] << Board[1][2] << '\n';
  std::cout << Board[2][0] << Board[2][1] << Board[2][2] << '\n';
  std::cout << ganador() << '\n';
  Board[0][2]=0;
  Board[1][1]=0;
  Board[2][0]=0;

  return 0;
}
