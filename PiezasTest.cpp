/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test {
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck) {
	ASSERT_TRUE(true);
}

// Constructor
TEST(PiezasTest, blankCheck) {
	Piezas b;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; ASSERT_EQ(board.pieceAt(i,j), Blank), j++);
	}
}

// Basic reset()
TEST(PiezasTest, blankCheck) {
	Piezas b;

	// Drop pieces
	for(int i = 0; i < 2; board.dropPiece(0), i++);
	for(int i = 0; i < 2; board.dropPiece(1), i++);
	for(int i = 0; i < 2; board.dropPiece(2), i++);
	for(int i = 0; i < 2; board.dropPiece(3), i++);
	for(int i = 0; i < 2; board.dropPiece(4), i++);

	// Reset and check
	b.reset();
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; ASSERT_EQ(board.pieceAt(i,j), Blank), j++);
	}
}

// Basic dropPiece()
TEST(PiezasTest, dpBaseXCheck) {
	Piezas b;
	Piece position = b.dropPiece(0);
	ASSERT_EQ(position, X);
}

// Basic dropPiece()
TEST(PiezasTest, dpBaseOCheck) {// We dropPiece() twice to get it to go to O's turn
	Piezas b;
	b.dropPiece(0)
	Piece position = b.dropPiece(0);
	ASSERT_EQ(position, O);
}
