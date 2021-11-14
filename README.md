# Tik-Tac-Toe [C++]
This is a simple CLI implementation of Tik-Tack-Toe game in C++.
Depending on `numPlayers`, there are two modes in this game.
+ User Vs. User
+ User Vs. CPU

To keep the game competitive, the CPU randomly generates its moves instead of using any A.I.

---
### How To Build
This code have been tested on a Windows11 machine with cmake and GNU toolchain.
To replicate the setup, you will need to:
+ install cmake on your windows machine
 + set your windows environment `PATH` to include cmake
+ install `mingw32`
 + you can refer to this youtube video: https://www.youtube.com/watch?v=hCLIDph7-mU
 + set your windows environment `PATH` to include `mingw32\bin`  and `mingw32`

+ Now open `Windows PowerShell`


 ```
 set new-alias make mingw32-make
 git clone <this repository>
 mkdir build && cd build
 cmake .. -G"MinGW Makefiles"
 make
 ```

These steps should create an executable in build folder, named as `tic_tac_toe.exe`
You can run this file in same `Windows PowerShell`
```
  .\tic_tac_toe.exe
```

You can use same toolchain to build this code on Linux environment too.

---
### How To Use
+ When the program is executed, you're provided with two choices
 + Run a unit test - `1/2/3/4`
   + There are 4 unit test included.
   1. Test_tie - In this test the objective  is to end up in tie   
   2. Test_diagonal - In this test the objective  is for Player 1 (X) to make a diagonal pattern  
   3. Test_horizontal - In this test the objective  is for Player 1 (X) to make a horizontal pattern     
   4. Test_vertical - In this test the objective  is for Player 2 (O) to make a vertical pattern

  + Play the game - `0`
   + Once the game start you need to answer two questions to setup our game board
    1. `How big should the board be?( 2 < size < 10)` : choose any number between 3 to 10
    2. `How many players should be there?( 1 or 2)` : choose either 1 or 2
  + Next the game board will be generated and printed on your screen
  + use on screen instructions to play the game.

  ---
  ### Future Development
  + Currently the game is setup to accept board size upto 10*10 but there's a provision to make it more flexible.
  + Currently the game termination criterion termnates the game as soon as we have `countToWin = gameBoard_size` for more flexible, specifically for larger and asymmetric boards this parameter can be tuned.
  + Currently I have implemented  a random move generation function for CPU's move generation. I did not use any AI becase it will always result in a tie or User loosing the game.
