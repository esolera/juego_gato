from display_image import *
from game_session import *

if __name__ == "__main__":
	print("---------------------------------------------------------------------------------------------------------------------")
	print("--------------------------------------Inicio juego ------------------------------------------------------------------")
	Board = [
        [0,0,0],
        [0,0,0],
        [0,0,0]
    ]


	while(True):
		create_image(Board)
		jugador_en_turno=Check_jugador(Board)
		print("Es el turno del jugador %i" %jugador_en_turno)
		posicion = int(input("Enter a number: "))
		while(not Valid_move(Board,posicion)):
			posicion = int(input("Posicion invalida, inserte nuevamente un numero"))
		Board=update_State(Board,posicion,jugador_en_turno)
		if(ganador(Board)):
			print("Ha ganado el jugador %i" %jugador_en_turno)
			create_image(Board)
			break
		if(empate(Board)):
			print("El juego a quedado empatado")
			create_image(Board)
			break
