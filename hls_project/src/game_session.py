def Check_jugador(Board):
    jugadas = 0
    for i in range(3):
        for j in range(3):
            if(Board[i][j]!=0):
                jugadas=jugadas+1
    #Se cuentan el numero de jugadas, en caso de que sea par indica que inicia el jugador 1
    if((jugadas%2)==0):
        jugador_out=1
    else:
        jugador_out=2
    return jugador_out

def Valid_move(Board,posicion):
    if(posicion<=2):
        if(Board[0][posicion]!=0):
            valido=False
        else:
            valido=True
    elif(posicion <=5):
        if(Board[1][posicion-3]!=0):
            valido=False
        else:
            valido=True
    elif (posicion <=8):
        if(Board[2][posicion-6]!=0):
            valido=False
        else:
            valido=True
    else:
        valido=False
    return valido

def update_State(Board,posicion,jugador):
    if(posicion<=2):
        Board[0][posicion]=jugador
    elif(posicion <=5):
        Board[1][posicion-3]=jugador
    elif (posicion <=8):
        Board[2][posicion-6]=jugador
    return Board

def ganador(Board):
    for i in range(3):

        if(((Board[i][0]*Board[i][1]*Board[i][2])==1) or ((Board[i][0]*Board[i][1]*Board[i][2])==8) or ((Board[0][i]*Board[1][i]*Board[2][i])==1) or ((Board[0][i]*Board[1][i]*Board[2][i])==8)):
            return True
    if(((Board[0][0]*Board[1][1]*Board[2][2])==1) or ((Board[0][0]*Board[1][1]*Board[2][2])==8) or ((Board[0][2]*Board[1][1]*Board[2][0])==8) or ((Board[0][2]*Board[1][1]*Board[2][0])==1)):
        return True

    return False

def empate(Board):
    for i in range(3):
        for j in range(3):
            if(Board[i][j]==0):
                return False
    return True

Board = [[0,0,0],[0,0,0],[0,0,0]]

def play():
    jugador_en_turno=Check_jugador(Board)
    print("Es el turno del jugador %i" %jugador_en_turno)
    posicion = int(input("Coloque la posicion: "))
    while(not Valid_move(Board,posicion)):
        posicion = int(input("Posicion invalida, inserte otra posicion no ocupada"))
    Board=update_State(Board,posicion,jugador_en_turno)
    print(Board)
    if(ganador(Board) or empate(Board)):
        if(ganador(Board)):
            print("Ha ganado el jugador %i" %jugador_en_turno)
            return(True)
        else:
            return(True)
            print("El juego a quedado empatado")
    else:
        return(False)



if __name__ == "__main__":
    print("---------------------------------------------------------------------------------------------------------------------")
    print("--------------------------------------Inicio juego ------------------------------------------------------------------")
    Board = [
        [0,0,0],
        [0,0,0],
        [0,0,0]
    ]

    print(Board)
    while(True):



        jugador_en_turno=Check_jugador(Board)
        print("Es el turno del jugador %i" %jugador_en_turno)
        posicion = int(input("Enter a number: "))
        while(not Valid_move(Board,posicion)):
            posicion = int(input("Posicion invalida, inserte nuevamente un numero"))
        Board=update_State(Board,posicion,jugador_en_turno)
        print(Board)
        if(ganador(Board)):
            print("Ha ganado el jugador %i" %jugador_en_turno)
            break
        if(empate(Board)):
            print("El juego a quedado empatado")
            break
