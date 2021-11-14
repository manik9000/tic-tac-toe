#include <iostream>
#include <vector>
#include <assert.h>     /* assert */

void Test_tie()
{

    vector<int> moves_tie =
    {11,00,01,21,20,02,10,12,22};

    int shouldGameContinue = 0;
    int playerSwitch = 1;
    int BOARD_SIZE = 3;
    Game game(BOARD_SIZE);

    int i =0;
    while(shouldGameContinue == 0) {
        game.renderBoard();
        playerSwitch = game.makeMove(playerSwitch, moves_tie[i]);
        shouldGameContinue = game.endConditionMet(playerSwitch);
        i++;
    }

    if(game.gameEnded == true && game.winner == "tie"){
      cout<<"Test_tie: Passed!"<<endl;
    }
    else{
      cout<<"Test_tie: Failed!"<<endl;
    }
}

void Test_diagonal()
{

    vector<int> moves_diag_R_win =
    {
        // _|_|_
        // _|_|_
        //  | |
        11,
        // _|_|_
        // _|X|_
        //  | |
        01,
        // _|O|_
        // _|X|_
        //  | |
        00,
        // X|O|_
        // _|X|_
        //  | |
        22,
        // X|O|_
        // _|X|_
        //  | |O
        20,
        // X|O|_
        // _|X|_
        // X| |O
        10,
        // X|O|_
        // O|X|_
        // X| |O
        02,
        // X|O|X
        // O|X|_
        // X| |O
    };

    int shouldGameContinue = 0;
    int playerSwitch = 1;
    int BOARD_SIZE = 3;
    Game game(BOARD_SIZE);

    int i =0;
    while(shouldGameContinue == 0) {
        game.renderBoard();
        playerSwitch = game.makeMove(playerSwitch, moves_diag_R_win[i]);
        shouldGameContinue = game.endConditionMet(playerSwitch);
        i++;
    }

    if(game.gameEnded == true && game.winner == "P1"){
      cout<<"Test_diagonal: Passed!"<<endl;
    }
    else{
      cout<<"Test_diagonal: Failed!"<<endl;
    }
  }

void Test_horizontal()
{

    vector<int> moves_horiz_X_win =
    {
        // _|_|_
        // _|_|_
        //  | |
        00,
        // X|_|_
        // _|_|_
        //  | |
        10,
        // X|_|_
        // O|_|_
        //  | |
        01,
        // X|X|_
        // O|_|_
        //  | |
        11,
        // X|X|X
        // O|O|_
        // _|_|_
        02,
        // X|X|X
        // O|O|_
        // _| |_
        12,
        // X|X|X
        // O|O|O
        // _|_|_
    };

    int shouldGameContinue = 0;
    int playerSwitch = 1;
    int BOARD_SIZE = 3;
    Game game(BOARD_SIZE);

    int i =0;
    while(shouldGameContinue == 0) {
        game.renderBoard();
        playerSwitch = game.makeMove(playerSwitch, moves_horiz_X_win[i]);
        shouldGameContinue = game.endConditionMet(playerSwitch);
        i++;
    }

    if(game.gameEnded == true && game.winner == "P1"){
      cout<<"Test_horizontal: Passed!"<<endl;
    }
    else{
      cout<<"Test_horizontal: Failed!"<<endl;
    }
}


void Test_vertical()
{
      vector<int> moves_Vert_O_win = {
          // _|_|_
          // _|_|_
          // _|_|_
          00,
          // X|_|_
          // _|_|_
          // _|_|_
          11,
          // X|_|_
          // _|O|_
          // _|_|_
          20,
          // X|_|_
          // _|O|_
          // X| |
          01,
          // X|O|_
          // _|O|_
          // X|_|_
          22,
          // X|O|_
          // _|O|_
          // X|_|X
          21
          // X|O|_
          // _|O|_
          // X|O|X
      };

      int shouldGameContinue = 0;
      int playerSwitch = 1;
      int BOARD_SIZE = 3;
      Game game(BOARD_SIZE);

      int i =0;
      while(shouldGameContinue == 0) {
          game.renderBoard();
          playerSwitch = game.makeMove(playerSwitch, moves_Vert_O_win[i]);
          shouldGameContinue = game.endConditionMet(playerSwitch);
          i++;
      }

      if(game.gameEnded == true && game.winner == "P2"){
        cout<<"Test_vertical: Passed!"<<endl;
      }
      else{
        cout<<"Test_vertical: Failed!"<<endl;
      }
}
