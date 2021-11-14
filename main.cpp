#include "tic-tac-toe.h"
#include "tests.h"
#include <random>
#include <algorithm>

int generateRandomMove(std::vector<int>& intList){

    // std::cout << "list size: " << intList.size() << '\n';

    int index = rand() % intList.size(); // pick a random index
    int value = intList[index]; // a random value taken from that list
    intList.erase(intList.begin() + index);
    return value;
}

int main() {

  cout << "Welcome to Tic Tac Toe!" << endl;
  cout << "Do you want to play the game (0) or run a test case (1,2,3,4)?" << endl;
  int play=true;
  std::cin >> play;


    //****** unit tests one by one ***//
    if(play == 1)
      Test_tie();
    if(play == 2)
      Test_diagonal();
    if(play == 3)
      Test_horizontal();
    if(play == 4)
      Test_vertical();


    //********** manule gamr play section ****//
    else{

    int BOARD_SIZE = 0;
    vector<vector<string>> board;
    int shouldGameContinue = 0;
    int playerSwitch = 1;
    int numPlayers=1; // can  be either 1 or 2

    cout << "How big should the board be?( 2 < size < 10): " << endl;
    cin >> BOARD_SIZE;
    cout << "How many players should be there?( 1 or 2): " << endl;
    cin >> numPlayers;

    if(BOARD_SIZE>10){
      cout << "Board size too large to handle ..." << endl;
      return 0;
    }
    cout << "Creating a size of board " << BOARD_SIZE << " ..." << endl;

    Game game(BOARD_SIZE,numPlayers);

    // if both players are users
    if(numPlayers == 2){
      while(shouldGameContinue == 0) {
          game.renderBoard();
          playerSwitch = game.makeMove(playerSwitch);
          shouldGameContinue = game.endConditionMet(playerSwitch);
      }
    }
    //if playing Vs. CPU
    else{
      vector<int> intList;
      for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++)
          intList.push_back(i*10+j);
        }

      while(shouldGameContinue == 0) {
          game.renderBoard();

          if(playerSwitch == 1){
            int move;
            cout << "Type in Coordinate to place an X on that spot!" << endl;
            cin >> move;
            intList.erase(remove(intList.begin(), intList.end(), move), intList.end());
            playerSwitch = game.makeMove(playerSwitch, move);
            shouldGameContinue = game.endConditionMet(playerSwitch);
          }
          else{
            //generate a random move
            int move = generateRandomMove(intList);
            cout<<"<---------- CPU's Turn ------> "<<endl;
            playerSwitch = game.makeMove(playerSwitch, move);
            shouldGameContinue = game.endConditionMet(playerSwitch);
          }
      }
    }
  }
}
