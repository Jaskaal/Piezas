#include "Piezas.h"
#include <vector>
/** CLASS Piezas
* Class for representing a Piezas vertical board, which is roughly based
* on the game "Connect Four" where pieces are placed in a column and 
* fall to the bottom of the column, or on top of other pieces already in
* that column. For an illustration of the board, see:
*  https://en.wikipedia.org/wiki/Connect_Four
*
* Board coordinates [row,col] should match with:
* [2,0][2,1][2,2][2,3]
* [1,0][1,1][1,2][1,3]
* [0,0][0,1][0,2][0,3]
* So that a piece dropped in column 2 should take [0,2] and the next one
* dropped in column 2 should take [1,2].
**/


/**
* Constructor sets an empty board (default 3 rows, 4 columns) and 
* specifies it is X's turn first
**/
Piezas::Piezas() {
	// Resize (Static) base of gameboard to have valid row amount
	board.resize(3);

	// For every row (non-static iteration limit), resize (Static) row to proper size
	for(int i = 0; i < (int)board.size(); i++) {
		board[i].resize(4);

		// For every [i][j] element (non-static iteration limit), reset
		for(int j = 0; j < (int)board[i].size(); j++) {
			board[i][j] = Blank;
		}
	}
	turn = X;
}

/**
* Resets each board location to the Blank Piece value, with a board of the
* same size as previously specified
**/
void Piezas::reset() {
	// For every row (non-static iteration limit), resize row to proper size
	for(int i = 0; i < (int)board.size(); board[i].resize(4), i++) {
		
		// For every [i][j] element (non-static iteration limit), reset
		for(int j = 0; j < (int)board[i].size(); j++) {
			board[i][j] = Blank;
		}
	}
}

/**
* Places a piece of the current turn on the board, returns what
* piece is placed, and toggles which Piece's turn it is. dropPiece does 
* NOT allow to place a piece in a location where a column is full.
* In that case, placePiece returns Piece Blank value 
* Out of bounds coordinates return the Piece Invalid value
* Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column) {
	// Keep track of turn
	Piece tmpTurn = turn;

	// Toggle turn
	if(turn == X) {
		turn = O;
	} else {
		turn = X;
	}

	// OOB checking on int column
	if(column >= (int)board[0].size()) {return Invalid;}

	// For every row (non-static iteration limit) in board
	for(int i = 0; i < (int)board.size(); i++) {
		
		// Check the position [i][argument]
		if(board[i][column] == Blank) {

			// Assign the board position and return value
			board[i][column] = tmpTurn;
			return tmpTurn;
		}
	}
	return Blank;//Hopefully this will fix it
}

/**
* Returns what piece is at the provided coordinates, or Blank if there
* are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column) {
	if(row >= (int)board.size() || row < 0) {
		return Invalid;
	}
	
	else if(column >= (int)board[0].size() || column < 0) {
		return Invalid;
	}

	/*if(board[row][column] != X && board[row][column] != O && board[row][column] != Blank) {
		return Invalid;
	}*/

	return board[row][column];
}

/**
* Returns which Piece has won, if there is a winner, Invalid if the game
* is not over, or Blank if the board is filled and no one has won ("tie").
* For a game to be over, all locations on the board must be filled with X's 
* and O's (i.e. no remaining Blank spaces). The winner is which player has
* the most adjacent pieces in a single line. Lines can go either vertically
* or horizontally. If both X's and O's have the same max number of pieces in a
* line, it is a tie.
**/
Piece Piezas::gameState() {
	// Keep track of maximums and continuous values
	int OMax = 0, XMax = 0;
	int contO, contX = 0;

	// For every row (non-static iteration limit) in board
	for(int i = 0; i < (int)board.size(); i++) {
		
		// For every [i][j] element (non-static iteration limit)
		for(int j = 0; j < (int)board[i].size(); j++) {
			// Blank tile (Fatal on non-valid position?)
			if(board[i][j] == Blank || (board[i][j] != X && board[i][j] != O)) {
				return Invalid;
			} 

			// X
			else if(board[i][j] == X) {
				contO = 0;
				XMax = std::max(XMax, ++contX);
			} 

			// O
			else if(board[i][j] == O) {
				contX = 0;
				OMax = std::max(OMax, ++contO);
			}
		}
	}

	// For every column (non-static iteration limit) in board
	for(int i = 0; i < (int)board[0].size(); i++) {

		// For every [j][i] element (non-static iteration limit)
		for(int j = 0; j < (int)board.size(); j++) {
			
			// Blank tile (Fatal on non-valid position?)
			if(board[j][i] == Blank || (board[j][i] != X && board[j][i] != O)) {
				return Invalid;
			} 

			// X
			else if(board[j][i] == X) {
				contO = 0;
				XMax = std::max(XMax, ++contX);
			} 

			// O
			else if(board[j][i] == O) {
				contX = 0;
				OMax = std::max(OMax, ++contO);
			}
		}
	}

	// Is X == O? ->
	// Is X > O ? ->
	// Return conditionally
	return (XMax == OMax ? Blank:(XMax > OMax ? X:O));
}