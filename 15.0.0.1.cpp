#include <iostream>

using namespace std;

short** pamyat_dlya_matritzi(short** matrix, unsigned int rows, unsigned int columns){
	unsigned int k=16;
	
	matrix = new short *[ rows ];
	for( unsigned int i = 0; i < rows; ++i ) {
    	matrix[ i ] = new short[ columns ];
   		for( unsigned int j = columns-1; j < columns; --j ) {
     		matrix[ i ][ j ] = k--;
   		}
	}
	
	matrix [0][columns-1]=0;

	return matrix;
}

void delete_pamyat (short** matrix, unsigned int rows) {
	for(unsigned int i=0; i<rows; i++){	
		delete []matrix[i];
	}			
	delete []matrix;
}

void show_game (short **matrix, unsigned int &m, unsigned int &n){
	cout << "+----+----+----+----+" << endl;
	for (unsigned int i=0; i<4; i++){
		for (unsigned int j=0; j<4; j++){
			
			if (matrix [ i ][ j ] == 0){
				m=i;
				n=j;
				cout << "|    ";
			}
			else {
				if (matrix[ i ][ j ] < 10){
					cout << "| 0" << matrix[ i ][ j ] << ' ';
				}
				else {
					cout << "| " << matrix[ i ][ j ] << ' ';
				}
			}
			if (j==3) {
				cout << '|';			
				cout << endl << "+----+----+----+----+" << endl;
			}
			
		}
	}
}

bool move (short** matrix, char op, unsigned int m, unsigned int n) {
	bool ok=false;
	
	switch (op) {
		case 'j': {
			if (m!=3){
				swap ( matrix [m][n] , matrix [m+1][n]);
				ok=!ok;
			}
			else {
				cout << endl << "You can`t make this move. Please, try again: ";
			}
			return ok;
		}
		
		case 'k': {
			if (m!=0){
				swap ( matrix [m][n] , matrix [m-1][n]);
				ok=!ok;
			}
			else {
				cout << endl << "You can`t make this move. Please, try again: ";
			}
			return ok;
		}
		
		case 'h': {
			if (n!=3){
				swap ( matrix [m][n] , matrix [m][n+1]);
				ok=!ok;
			}
			else {
				cout << endl << "You can`t make this move. Please, try again: ";
			}
			return ok;
		}
		
		case 'l': {
			if (n!=0){
				swap ( matrix [m][n] , matrix [m][n-1]);
				ok=!ok;
			}
			else {
				cout << endl << "You can`t make this move. Please, try again: ";
			}
			return ok;
		}
		
		case 'q': {
			return ok;
		}
	}
	
	cout << endl << "You can`t use this letter. Please, try again: ";
	return ok;
}

int main () {
	short** matrix;
	bool ok = true;
	unsigned int m, n;
	char op='t';
	
	matrix=pamyat_dlya_matritzi(matrix, 4, 4);
	
	while (ok) {
		ok=!ok;
		show_game (matrix, m, n);
		while (op!='q' && ok==false) {
			cin >> op;
			ok=move (matrix, op, m, n);
		}
	}
	
	cout << endl << "Thanks for the game!";
	delete_pamyat (matrix, 4);
	
	cin.get();
	return 0;
}
