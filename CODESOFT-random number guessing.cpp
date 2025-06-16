#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

// Function to generate a random number
int randomNoGen(){
	return rand() % 100 + 1;
}

string check(int Generated_no , int guess){
	if(guess==Generated_no){
		return "Congrats!, you guessed the right number";
	}
	else if(guess-Generated_no >= 30){
		return "Too High";
	}
	else if(guess-Generated_no <= -30){
		return "Too Low";
	}
	else if(guess-Generated_no >= 10  ){
		return "High";
	}
	else if(guess-Generated_no <= -10){
		return "Low";
	}
	else if(guess-Generated_no > 0 ){
		return "Almost Close but High";
	}
	else if(guess-Generated_no < 0 ){
		return "Almost Close but Low";
	}
	
	return "Invalid guess";
	
}

int main(){
	
	// seeded using current time
	srand(time(0));
	
	// Integer to store a generated number
	int Generated_no = randomNoGen();
	
	//User guessing number
	int guess;
	cout << "A random number between 1 and 100 has been generated. Try to guess it!" << endl;
	
	//The loop untill the user guesses the correct number
	while(true){
		cout << "Enter your guess:";
		cin>> guess;
		string feedback = check(Generated_no,guess);
		cout << feedback<< endl;
		if(feedback=="Congrats!, you guessed the right number"){
			break;
		}
	}
	return 0;
}

//1275. Find Winner on a Tic Tac Toe Game