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
Piezas::Piezas()
{

  board.resize(BOARD_ROWS);
  for(int x = 0; x < BOARD_ROWS; x++)
  {
    board[x].resize(BOARD_COLS);
  }
    turn = X;

    for(int x = 0; x < BOARD_ROWS; x++)
    {
      for(int y = 0; y < BOARD_COLS; y++)
      {

         board[x][y] = Blank;
      }
    }
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
  for(int x = 0; x < 3; x++)
  {
    for(int y = 0; y < 4; y++)
    {
      board[x][y] = Blank;
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
Piece Piezas::dropPiece(int column)
{
  if(column > BOARD_ROWS || column < 0)
  {
    if(turn == X)
    {
      turn = O;
    }

    else
    {
      turn = X;
    }

    return Invalid;
  }

  for(int x = 0; x < 3; x++)
  {
    if(board[x][column] == Blank)
    {
      Piece temp = turn;
      board[x][column] = turn;

      if(turn == X)
      {
        turn = O;
      }

      else
      {
        turn = X;
      }

      return temp;
    }

  }

  if(turn == X)
  {
    turn = O;
  }

  else
  {
    turn = X;
  }

  return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
 if((row < 0 || row > 2) && (column < 0 || column > 3)) 
 {
   return Blank;
 }

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
Piece Piezas::gameState()
{

  int xPiece = 0;
  int oPiece = 0;
  int score = 0;

  for(int x = 0; x < 3; x++)
  {
    for(int y = 0; y < 4; y++)
    {
      if(board[x][y] == Blank) 
      {
        return Invalid;
      }
    }
  }

  for(int x = 0; x < 3; x++)
  {
    for(int y = 0; y < 3; y++)
    {
      if(board[x][y] == board[x][y + 1])
      {
        score++;

        if(board[x][y] == x && score > xPiece) 
        {
          xPiece = score;
        }

        else if(board[x][y] == 0 && score > oPiece)
        {
          oPiece = score;
        }
      }

        else
        {
          score = 0;
        }  
     }
  }

  for(int y = 0; y < 4; y++)
  {
    for(int x = 0; x < 2; x++)
    {
      if(board[x][y] == board[x+1][y])
      {
         score++;

      if(board[x][y] == X && score > xPiece) 
      {
        xPiece = score;
      }

      else if(board[x][y] == 0 && score > oPiece)
      {
        oPiece = score;
      }
      
      }

      else
      {
        score = 0;
      }
    }
  }

  if(xPiece == oPiece)
  {
    return Blank;
  }

  else if(xPiece > oPiece)
  {
    return X;
  }


}
