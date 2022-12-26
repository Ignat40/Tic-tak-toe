#include <iostream>
#include <ctime>
#include <random>
using namespace std;

//variables 

char board[9] = {' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
void show_board();
void get_x_player_choice();
void get_0_player_choice();
void get_computer_choice();
int coutn_board(char symbol);
char check_winner();
void computer_vs_player();
void player_vs_player();

//main funciton

int main() {


	computer_vs_player();
	return 0;
}

//functions

void computer_vs_player() {

	string player_name;
	cout << "Enter player name: ";
	cin >> player_name;
	while (true) {
		system("cls");
		show_board();
		if (coutn_board('X') == coutn_board('O')) {
			cout << player_name << "'s Turn" << endl;
		}
		else {
			get_computer_choice();
		}
		char winner = check_winner();
		if (winner = 'X') {
			system("cls");
			show_board();
			cout << player_name << " Won the game" << endl;
			break;
		}
		else if (winner == 'O') {
			system("cls");
			show_board();
			cout << "Computer won the game " << endl;
			break;
		}
		else if (winner = 'D') {
			cout << "Game is draw" << endl;
			break;
		}
	}
}



void get_computer_choice() {

	srand(time(0));
	int choice;
	do {

		choice = rand() % 10;
	} while (board[choice] != ' ');
	board[choice] = 'O';
}

void get_x_player_choice() {

	while (true) {

		cout << "Select your position (1 - 9): ";
		int choice;
		cin >> choice;
		choice--;
		if (choice < 0 || choice > 8) {
			cout << "Please select another position which is (1 - 9): " << endl;

		}
		else if (board [choice] != ' ') {
			cout << "Please select and empty position: " << endl;
		}
		else {
			board[choice] = 'X';
			break;
		}
	}

}

void get_0_player_choice() {

	while (true) {

		cout << "Select your position (1 - 9): ";
		int choice;
		cin >> choice;
		choice--;
		if (choice < 0 || choice > 8) {
			cout << "Please select another position which is (1 - 9): " << endl;

		}
		else if (board[choice] != ' ') {
			cout << "Please select and empty position: " << endl;
		}
		else {
			board[choice] = 'O';
			break;
		}
	}

}

int coutn_board(char symbol) {

	int total = 0;
	for (int i = 0; i < 9; i++) {
		if (board[i] == symbol)
			total += 1;
	}
	return total;
}

char check_winner() {
	//horizontal
	if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
		return board[0];
	if (board[3] == board[4] && board[4] == board[5] && board[2] != ' ')
		return board[0];
	if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
		return board[0];

	//vertical
	if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
		return board[0];
	if (board[1] == board[4] && board[4] == board[6] && board[1] != ' ')
		return board[1];
	if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
		return board[2];

	//diagonal
	if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
		return board[0];
	if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
		return board[2];

	if (coutn_board('X') + coutn_board('O') < 9)
		return 'C';
	else
		return 'D';

}



void show_board() {

	cout << "   " << "    |   " << "    |   " << endl;
	cout << "   " << board[0] << "   |   " << board[1] << "   |   " << board[2] << endl;
	cout << "-----------------------" << endl;
	cout << "   " << "    |   " << "    |   " << endl;
	cout << "   " << board[3] << "   |   " << board[4] << "   |   " << board[5] << endl;
	cout << "-----------------------" << endl;
	cout << "   " << "    |   " << "    |   " << endl;
	cout << "   " << board[6] << "   |   " << board[7] << "   |   " << board[8] << endl;

}