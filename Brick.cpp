#include "Brick.h"
#include <vector>
#include <iostream>
#include "Screen.h"

using namespace std;

void Brick::set_bricks(int x, int y)				// x, y is start position
{
	for (int i = 1; i < sum_bricks + 1; i++) {
		*(all_bricks + i)[0] = x;
		*(all_bricks + i)[1] = y;
		*(all_bricks + i)[2] = 1;
		x += 2;
		if (i / 20 >= 1 && i % 20 == 0) {
			x = start_x;
			y = y + 2;
		}
	}
}

void Brick::delete_bricks(int n)
{
	*(all_bricks + n)[3] = 0;
}

void Brick::clear_bricks() {
	for (int i = 0; i < sum_bricks; i++) {
		*(all_bricks + i)[0] = 0;
		*(all_bricks + i)[1] = 0;
		*(all_bricks + i)[2] = 0;
	}
}

void Brick::score_print()
{
	cout << "YOUR SCORE : " << score << endl;
}

int Brick::score_add()
{
	return score++;
}

void Brick::reset_bricks()
{
	for (int i = 0; i < sum_bricks; i++) {
		*(all_bricks + i)[2] = 1;
	}
	reset_score();
}

void Brick::Render()
{
	int x = start_x;
	int y = start_y;
	for (int i = 0; i < sum_bricks; i++) {
		if (i % 20 == 0 && i / 20 >= 1) {
			y = y + 2;
			x = start_x;
		}
		gotoxy(x, y);
		if (*(all_bricks+i)[2]) {
			cout << "бс";
		}
		else {
			cout << "  ";
		}
		x += 2;
	}
}

int Brick::get_display_signal(int x, int y)
{
	int n;
	if (y == 0) {
		n = x + y;
	}
	else if (y == 1) {
		n = x + y + 20;
	}
	else {
		n = x + y + 40;
	}
	return *(all_bricks + n)[2];
}

int Brick::get_x(int x, int y) {
	int n;
	if (y == 0) {
		n = x + y;
	}
	else if (y == 1) {
		n = x + y + 20;
	}
	else {
		n = x + y + 40;
	}
	return *(all_bricks + n)[0];
}

int Brick::get_y(int x, int y){
	int n;
	if (y == 5) {
		n = x + y;
	}
	else if (y == 7) {
		n = x + y + 19;
	}
	else {
		n = x + y + 39;
	}
	return *(all_bricks + n)[1];
}

void Brick::reset_score()
{
	score = 0;
}
