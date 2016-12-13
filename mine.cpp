/*
First game to program. Probably a few bugs still. Come back later to be able to add flags to mark the bombs.

*/



#include <iostream>
#include <stdlib.h>
using namespace std;

class mine{
private:
	int hidden[11][11];
	int play[9][9];

public:

void setBoard(){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			play[i][j] = 21;
		}
	}
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11; j++){
			hidden[i][j] = 0;
		}
	}
}

void setMines(){
	int bombX, bombY;
	for (int i = 0; i < 10; i++){
		bombX = (rand() % 9) + 1;
		bombY = (rand() % 9) + 1;
		hidden[bombX][bombY] = 9;
	}
}	

void setNum(){
	for (int i = 1; i < 10; i++){
		for (int j = 1; j <= 9; j++){
			if (hidden[i][j] != 9){
				int num = 0;
				for (int k = i - 1; k <= i + 1; k++){
					for (int m = j - 1; m <= j + 1; m++){
						if (hidden[k][m] == 9) num++;
					}
				}
				hidden[i][j] = num;
			}
		}
	}
}

void printBoard(){
	cout << "\033[2J\033[1;1H";
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			if (play[i][j] != 21){
				cout << "[" << play[i][j] << "]";
			}
			else cout << "[-]";
		}
	cout << endl;
	}
}

void turn(int a, int b){
	if (hidden[a][b] != 9) play[a][b] = hidden[a+1][b+1];
	else{
		cout << "You hit a mine. Game Over." << endl;
		exit(1);
	}
}


};

int main(){

	mine a;
	a.setBoard();
	a.setMines();
	a.setNum();
	int f,g;
	
	for (int i = 0; i < 71; i++){
		a.printBoard();
		cout << "Enter Y coordinate (0 - 8): ";
		cin >> f;
		cout << "Enter X coordinate (0 - 8): ";
		cin >> g;
		a.turn(f, g);
	}

	cout << "You won!!" << endl;

	return 0;
}
