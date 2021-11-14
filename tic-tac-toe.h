#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Game{
public:
	int BOARD_SIZE = 0;
	int countToWin;
	vector<vector<string>> board;
	int numPlayers=2; //set to 1 for Player Vs CPU

	string winner = "P1";
	bool gameEnded = false;

	Game(int bSize){
		BOARD_SIZE=bSize;
		countToWin = BOARD_SIZE;
		board = vector<vector<string>> (BOARD_SIZE,vector<string>(BOARD_SIZE));
		setupEmptyBoard();
	}

	Game(int bSize, int numPlayers_){
		BOARD_SIZE=bSize;
		numPlayers = numPlayers_;
		if(numPlayers_>2)
			numPlayers_ = 2;
		if(numPlayers_<1){
				cout<< "we need atleast one player";
				exit(-1);
		}
		countToWin = BOARD_SIZE;
		board = vector<vector<string>> (BOARD_SIZE,vector<string>(BOARD_SIZE));
		setupEmptyBoard();
	}

	void renderBoard();
	int endConditionMet(int playerSwitch);
	int makeMove(int playerSwitch);
	int makeMove(int playerSwitch, int move);


private:
	void setupEmptyBoard();
	void decideWinner(int playerSwitch, int countToWin_p1, int countToWin_p2);
};

// Builds our board, and gives us a pointer to it
void Game::setupEmptyBoard(){
	for(int i = 0; i < BOARD_SIZE; i++) {
		for(int j = 0; j < BOARD_SIZE; j++) {
			string temp = "["+ std::to_string(i)+ std::to_string(j) +"] ";
			board[i][j] = temp;
		}
	}

}

// Prints our updated board
void Game::renderBoard() {
		// std::system("cls");
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Check for end condition
int Game::endConditionMet(int playerSwitch) {

    // Check Horizontally
		int countToWin_p1;
		int countToWin_p2;
		for(int i = 0; i < BOARD_SIZE; i++) {
			countToWin_p1 = 0;
			countToWin_p2 = 0;
				for(int j = 0; j < BOARD_SIZE; j++) {
						if(board[i][j] == "[X ] ") {
								countToWin_p1++;
						}
						if(board[i][j] == "[O ] ") {
								countToWin_p2++;
						}
				}
				decideWinner(playerSwitch, countToWin_p1, countToWin_p2);
			}

    // Check Vertically
		for(int i = 0; i < BOARD_SIZE; i++) {
			countToWin_p1 = 0;
			countToWin_p2 = 0;
			for(int j = 0; j < BOARD_SIZE; j++) {
				if(board[j][i] == "[X ] ") {
					countToWin_p1++;
				}
				if(board[j][i] == "[O ] ") {
					countToWin_p2++;
				}
			}
			decideWinner(playerSwitch, countToWin_p1, countToWin_p2);
		}

    //Check Left Diagonal

		countToWin_p1 = 0;
		countToWin_p2 = 0;
		for(int i = 0,j = 0; i < BOARD_SIZE, j < BOARD_SIZE; i++, j++) {
			if(board[j][i] == "[X ] ") {
				countToWin_p1++;
			}
			if(board[j][i] == "[O ] ") {
				countToWin_p2++;
			}
		}
		decideWinner(playerSwitch, countToWin_p1, countToWin_p2);

    // Check Right Diagonal

		countToWin_p1 = 0;
		countToWin_p2 = 0;
		for(int i = 0, j = BOARD_SIZE - 1; i < BOARD_SIZE, j >= 0; i++, j--) {
			if(board[j][i] == "[X ] ") {
				countToWin_p1++;
			}
			if(board[j][i] == "[O ] ") {
				countToWin_p2++;
			}
		}
		decideWinner(playerSwitch, countToWin_p1, countToWin_p2);

    // Check if there is no winner

    int countAllGone = 0;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == "[X ] " || board[i][j] == "[O ] ") {
                countAllGone++;
            }
        }
    }
    if(countAllGone == BOARD_SIZE * BOARD_SIZE) {
        cout << "NO WINNER!" << endl;
				gameEnded=true;
				winner = "tie";
        exit(0);
    }

    return 0;
}


void Game::decideWinner(int playerSwitch, int countToWin_p1, int countToWin_p2){
	if(playerSwitch == 1) {
					if(countToWin_p1 == countToWin) {
							cout << "********* PLAYER 1 HAS WON! *********" << endl;
							renderBoard();
							gameEnded=true;
							winner = "P1";
							exit(0);
					}
			}
	else {
					if(countToWin_p2 == countToWin) {
							cout << "********* PLAYER 2 HAS WON! *********" << endl;
							renderBoard();
							gameEnded=true;
							winner = "P2";
							exit(0);
					}
			}
}

int Game::makeMove(int playerSwitch){

    int input;
    bool validInput = false;
    int xInput = 0;
    int yInput = 0;

    if(playerSwitch == 1) {
        cout << "PLAYER 1 TURN!" << endl;
        // Check to make sure player is not inserting in an already taken spot

        while(!validInput) {
            cout << "Type in Coordinate to place an X on that spot!" << endl;
            cin >> input;

            xInput = (int)input/10;
            yInput = (int)input%10;

            if(board[xInput][yInput] == "[O ] " ||
                    board[xInput][yInput] == "[X ] " ||
                    xInput > BOARD_SIZE - 1 ||
                    yInput > BOARD_SIZE - 1 ||
                    xInput < 0 ||
                    yInput < 0) {
                cout << "Not Valid Input. Spot is already taken!" << endl;
            } else {
                validInput = true;
            }
        }

        board[xInput][yInput] = "[X ] ";
        endConditionMet(playerSwitch);

        playerSwitch = 0;
        return playerSwitch;
    } else {
        cout << "PLAYER 2 TURN!" << endl;

        while(!validInput) {
            cout << "Type in Coordinate to place an O on that spot!" << endl;
            cin >> input;

						xInput = (int)input/10;
            yInput = (int)input%10;

            if(board[xInput][yInput] == "[O ] " ||
                    board[xInput][yInput] == "[X ] " ||
                    xInput > BOARD_SIZE - 1 ||
                    yInput > BOARD_SIZE - 1 ||
                    xInput < 0 ||
                    yInput < 0) {
                cout << "Not Valid Input. Choose Again!" << endl;
            } else {
                validInput = true;
            }

        }

        board[xInput][yInput] = "[O ] ";
        endConditionMet(playerSwitch);

        playerSwitch = 1;
        return playerSwitch;
    }
}

// this make move funtion is specifically designed for unit tests
int Game::makeMove(int playerSwitch, int move){

    int input = move;
    bool validInput = false;
    int xInput = 0;
    int yInput = 0;

    if(playerSwitch == 1) {
        cout << "PLAYER 1 TURN!" << endl;
        // Check to make sure player is not inserting in an already taken spot
        while(!validInput) {
						cout << "Type in Coordinate to place an X on that spot!" << endl;
            cout << input<<endl;

            xInput = (int)input/10;
            yInput = (int)input%10;

            if(board[xInput][yInput] == "[O ] " ||
                    board[xInput][yInput] == "[X ] " ||
                    xInput > BOARD_SIZE - 1 ||
                    yInput > BOARD_SIZE - 1 ||
                    xInput < 0 ||
                    yInput < 0) {
                cout << "Not Valid Input. Spot is already taken! Restart The game" << endl;
								return playerSwitch;
            } else {
                validInput = true;
            }
        }

        board[xInput][yInput] = "[X ] ";
        endConditionMet(playerSwitch);

        playerSwitch = 0;
        return playerSwitch;
    } else {
        cout << "PLAYER 2 TURN!" << endl;

        while(!validInput) {
            cout << "Type in Coordinate to place an O on that spot!" << endl;
						cout << input<<endl;

						xInput = (int)input/10;
            yInput = (int)input%10;

            if(board[xInput][yInput] == "[O ] " ||
                    board[xInput][yInput] == "[X ] " ||
                    xInput > BOARD_SIZE - 1 ||
                    yInput > BOARD_SIZE - 1 ||
                    xInput < 0 ||
                    yInput < 0) {
										cout << "Not Valid Input. Spot is already taken! Restart The game" << endl;
										return playerSwitch;
            } else {
                validInput = true;
            }

        }

        board[xInput][yInput] = "[O ] ";
        endConditionMet(playerSwitch);

        playerSwitch = 1;
        return playerSwitch;
    }
}
