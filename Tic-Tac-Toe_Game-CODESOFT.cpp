#include<iostream>

using namespace std;

char Board[3][3];
char currentPlayer;

bool isMoveValid(int pos){
	int row = (pos-1)/3;
	int col = (pos-1)%3;
	return ( Board[row][col] != 'X' && Board[row][col] != 'O');
	
}

void initializeGame() {
    char ch = '1';
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            Board[i][j] = ch++;
}


void makeMove(int pos){
	int row = (pos-1)/3;
	int col = (pos-1)%3;
	Board[row][col] = currentPlayer;
	
}

void displayBoard(){
	cout<<"\n";
	for(int i =0 ; i<3;i++){
		cout<<" ";
		for(int j =0;j<3;j++){
			cout<< Board[i][j];
			if(j<2){
				cout<< " | ";
			}
		}
		cout<< "\n---|---|---\n";
	}
	cout<<"\n";
}

bool checkWin(){
	for(int i =0;i<3;i++){
		if( (Board[i][0] == currentPlayer && Board[i][1] == currentPlayer && Board[i][2] == currentPlayer) || 
			(Board[0][i] == currentPlayer && Board[1][i] == currentPlayer && Board[2][i] == currentPlayer)	)
			return true;
	}
	
	if( (Board[0][0] == currentPlayer && Board[1][1] == currentPlayer && Board[2][2] == currentPlayer) ||
	    (Board[0][2] == currentPlayer && Board[1][1] == currentPlayer && Board[2][0] == currentPlayer)){
	    	return true;
		}
	
	return false;
}

bool checkDraw(){
	for(int i =0;i<3;i++){
		for(int j = 0; j<3;j++){
			if( Board[i][j] != 'X' && Board[i][j] != 'O'){
				return false;
			}
		}
	}
	return true;
}

void switchPlayer(){ 
	currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame(){
	currentPlayer = 'X';
	int move;
	initializeGame();
	bool isGameOver = false;
	
	
	while(!isGameOver){
		displayBoard();
		cout<< "Player " << currentPlayer << ", enter your move (1 to 9): ";
		cin>>move;
		
		if( move < 1 || move > 9 || !isMoveValid(move)){
			cout<<"Invalid move. Try again. \n";
			continue;
		}
		
		makeMove(move);
		
		if(checkWin()){
			displayBoard();
			cout<< "Player " << currentPlayer << " Won!\n";
			isGameOver = true;
		}
		else if(checkDraw()){
			displayBoard();
			cout<< "The game is draw!\n";
			isGameOver = true;
		}
		else{
			switchPlayer();
		}
	}
	
}

int main(){
	char choice;
	do{
		playGame();
		cout<< "Do you want to play? ('y' for Yes & 'n' for No) : ";
		cin >> choice;
	}while(choice == 'y' || choice == 'Y');
	
	cout<< "Thanks for Playing!\n";
	return 0;
	
}