#### Overview:
This project is a console-based implementation of the classic Tic-Tac-Toe game, developed in C++. It supports both player vs. player and player vs. computer game modes. The game includes features such as a dynamic game board, user-friendly prompts, and robust input validation to ensure a seamless gaming experience.

#### Features:
1. Dynamic Game Board: 
   - The game board is a 3x3 grid that updates dynamically based on player inputs.
   - The initial board displays numbers 1-9 representing each cell, which get replaced by 'X' or 'O' as players make their moves.

2. Game Modes:
   - Player vs. Player: Two human players can play against each other.
   - Player vs. Computer: A single human player can play against a computer, which makes random moves.

3. User Prompts and Input Validation:
   - The game provides clear prompts for player actions.
   - It validates inputs to ensure they are within the acceptable range (1-9) and that chosen cells are not already occupied.

4. Win and Draw Conditions:
   - The game checks for win conditions after each move, identifying if a player has aligned three of their marks in a row, column, or diagonal.
   - It also checks for draw conditions when all cells are filled without a winner.

#### Classes and Methods:
- Class `TicTacToe`:
  - Private Members:
    - `char board[SIZE][SIZE]`: The 3x3 game board.
    - `char currentPlayer`: The current player ('X' or 'O').
  - Constructor:
    - Initializes the game board and sets the starting player.
  - Methods:
    - `void displayBoard() const`: Prints the current state of the game board.
    - `bool checkWin(char player) const`: Checks if the specified player has won the game.
    - `bool isDraw() const`: Checks if the game has ended in a draw.
    - `void makeMove()`: Handles moves for the current player, with input validation.
    - `void computerMove()`: Handles random moves for the computer player.
    - `void switchPlayer()`: Switches the current player.
    - `void playGame()`: Manages the game loop, mode selection, and overall game flow.

#### Usage:
1. Initialization: The game starts by creating an instance of the `TicTacToe` class.
2. Mode Selection: Players choose between player vs. player or player vs. computer mode.
3. Gameplay:
   - The current player makes a move by selecting a cell (1-9).
   - The game board updates, and the game checks for win or draw conditions.
   - The player is switched, and the process repeats until a win or draw is detected.
4. End Game: The game announces the winner or declares a draw, and then exits.

#### Example Gameplay Flow:
1. Start Game:
   - The user is prompted to choose a game mode.
2. Player Moves:
   - In player vs. player mode, players take turns entering their moves.
   - In player vs. computer mode, the human player and computer alternate moves.
3. Board Update:
   - After each move, the board is displayed with the latest updates.
4. Win/Draw Check:
   - The game checks for winning conditions and draw conditions after each move.
5. End of Game:
   - If a player wins, the game announces the winner.
   - If the board is full and no player has won, the game declares a draw.

This project demonstrates fundamental concepts of object-oriented programming (OOP) in C++, including class design, encapsulation, and method implementation. It also showcases basic game development principles and user interaction in a console application.
