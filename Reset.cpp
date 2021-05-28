#include "Reset.h"
#include "Brick.h"
void Reset(int& option, Brick& bricks) {
	if (option == 1) {				// play again
		bricks.reset_bricks();
	}
	else if (option == 2) {			// go to the first screen
		// first screen print out
	}
}