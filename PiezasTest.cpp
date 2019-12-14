/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
//checks for placement 
TEST(PiezasTest, noPlacement)
{
  Piezas tBoard;
  ASSERT_EQ(tBoard.pieceAt(0,1), Blank);
}

//illegal plays
TEST(PiezasTest, illegalDrop)
{
  Piezas tBoard;
  ASSERT_EQ(tBoard.dropPiece(5), Invalid);
}

TEST(PiezasTest, anotherIllegalDrop)
{
  Piezas tBoard;
  ASSERT_EQ(tBoard.dropPiece(-5), Invalid);
}

//check turns 
TEST(PiezasTest, xTurn)
{
  Piezas tBoard;
  ASSERT_EQ(tBoard.dropPiece(2), X);
}

TEST(PiezasTest, oTurn)
{
  Piezas tBoard;
  ASSERT_EQ(tBoard.dropPiece(2), O);
}

//board checks
TEST(PiezasTest, columnsFull)
{
  Piezas tBoard;

  tBoard.dropPiece(0);
  tBoard.dropPiece(0);
  tBoard.dropPiece(0);

  ASSERT_EQ(tBoard.dropPiece(0), Blank);
}
/*
TEST(PiezasTest, rowsFull)
{
  Piezas tBoard;

  tBoard.dropPiece(0);
  tBoard.dropPiece(1);
  tBoard.dropPiece(2);
  
  ASSERT_EQ(tBoard.dropPiece(3), Blank);
}
*/

TEST(PiezasTest, reset)
{
  Piezas tBoard;
  tBoard.dropPiece(1);
  tBoard.reset();

  ASSERT_EQ(tBoard.pieceAt(0,1), Blank);
}

//check for winners, ties etc
TEST(PiezasTest, catsGame)
{
  Piezas tBoard;
  tBoard.dropPiece(1);

  ASSERT_EQ(tBoard.gameState(), Invalid);
}

TEST(PiezasTest, xWon)
{
  Piezas tBoard;

  tBoard.dropPiece(0);
  tBoard.dropPiece(0);
  tBoard.dropPiece(1);

  tBoard.dropPiece(0);
  tBoard.dropPiece(2);
  tBoard.dropPiece(1);

  tBoard.dropPiece(3);
  tBoard.dropPiece(1);
  tBoard.dropPiece(2);

  tBoard.dropPiece(3);
  tBoard.dropPiece(3);
  tBoard.dropPiece(2);

  ASSERT_EQ(tBoard.gameState(), X);
}

TEST(PiezasTest, oWon)
{
  Piezas tBoard;
  tBoard.dropPiece(0);
  tBoard.dropPiece(1);
  tBoard.dropPiece(0);
  tBoard.dropPiece(1);
  tBoard.dropPiece(1);
  tBoard.dropPiece(0);
  tBoard.dropPiece(2);
  tBoard.dropPiece(2);
  tBoard.dropPiece(3);
  tBoard.dropPiece(3);
  tBoard.dropPiece(2);
  tBoard.dropPiece(3);

}

