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
TEST(PiezasTest, constCheck) {
	Piezas b;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; j++) {
			ASSERT_EQ(b.pieceAt(i,j), Blank);
		}
	}
}

// Basic reset()
TEST(PiezasTest, rstBaseCheck) {
	Piezas b;

	// Drop pieces
	for(int i = 0; i < 2; b.dropPiece(0), i++);
	for(int i = 0; i < 2; b.dropPiece(1), i++);
	for(int i = 0; i < 2; b.dropPiece(2), i++);
	for(int i = 0; i < 2; b.dropPiece(3), i++);
	for(int i = 0; i < 2; b.dropPiece(4), i++);

	// Reset and check
	b.reset();
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; j++) {
			ASSERT_EQ(b.pieceAt(i,j), Blank);
		}
	}
}

// Basic dropPiece()
TEST(PiezasTest, dpBaseXCheck) {
	Piezas b;
	Piece position;
	position = b.dropPiece(0);
	ASSERT_EQ(position, X);
}

// Basic dropPiece()
TEST(PiezasTest, dpBaseOCheck) {
	Piezas b;
	b.dropPiece(0);
	Piece position;
	position = b.dropPiece(0);
	ASSERT_EQ(position, O);
}

// Invalid dropPiece()
TEST(PiezasTest, dpBaseInvalid) {
	Piezas b;
	Piece p;
	b.dropPiece(0);
	b.dropPiece(0);
	b.dropPiece(0);
	p = b.dropPiece(0);
	ASSERT_EQ(p, Blank);
}

// Invalid dropPiece() OOB
TEST(PiezasTest, dpOOB) {
	Piezas b;
	Piece p;
	p = b.dropPiece(92);
	ASSERT_EQ(p, Invalid);
}

// Tie in gameState()
TEST(PiezasTest, gsBaseCheck) {
	Piezas b;

	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(0);
	b.dropPiece(2);
	b.dropPiece(0);
	b.dropPiece(3);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(3);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(3);
	ASSERT_EQ(b.gameState(), Blank);
}

// X wins gameState()
TEST(PiezasTest, gsXBaseCheck) {
	Piezas b;
	Piece p;

	b.dropPiece(0);
	b.reset();
	
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(0);
	b.dropPiece(2);
	b.dropPiece(1);
	b.dropPiece(3);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(2);
	b.dropPiece(3);
	b.dropPiece(3);
	b.dropPiece(2);
	b.dropPiece(0);
	b.dropPiece(3);
	b.dropPiece(0);
	
	p = b.gameState();
	ASSERT_EQ(p, X);
}

// Y wins gameState()
TEST(PiezasTest, gsOBaseCheck) {
	Piezas b;
	Piece p;

	
	
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(0);
	b.dropPiece(2);
	b.dropPiece(1);
	b.dropPiece(3);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(2);
	b.dropPiece(3);
	b.dropPiece(3);
	b.dropPiece(2);
	b.dropPiece(0);
	b.dropPiece(3);
	b.dropPiece(0);
	
	p = b.gameState();
	ASSERT_EQ(p, O);
}

// Invalid gameState()
TEST(PiezasTest, gsInvBaseCheck) {
	Piezas b;
	Piece p;
	b.dropPiece(0);
	p = b.gameState();
	ASSERT_EQ(p, Invalid);
}