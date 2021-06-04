#include "Brick.h"
#include <vector>
#include <iostream>
#include "gxy.h"

using namespace std;

int Coord::get_x()
{
	return x;
}

int Coord::get_y()
{
	return y;
}

void Coord::set_coord(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Coord::display_set()
{
	display_signal = 1;
}

void Coord::blank_set()
{
	display_signal = 0;
}

int Coord::get_display_signal() {
	return display_signal;
}

void Brick::set_bricks()				// n is the sum of bricks
{
	Coord temp;
	temp.set_coord(0, 0);
	for (int i = 0; i < sum_bricks; i++) {
		if (i < 20) {
			all_bricks.push_back(temp);
			temp.set_coord(temp.get_x() + 2, temp.get_y());
		}
		else if (20 <= i && i < 40){
			all_bricks.push_back(temp);
			temp.set_coord(temp.get_x() + 2, temp.get_y());
		}
		else {
			all_bricks.push_back(temp);
			temp.set_coord(temp.get_x() + 2, temp.get_y());
		}
		if (i == 19) {
			temp.set_coord(0, temp.get_y() + 1);
		}
		else if (i == 39){
			temp.set_coord(0, temp.get_y() + 2);
		}
	}
}

void Brick::delete_bricks(int n)
{
	all_bricks[n].blank_set();
}

void Brick::print() {
	for (auto&x : all_bricks) {
		if (x.get_display_signal()) {
			cout << "(" << x.get_x() << "," << x.get_y() << ")" << endl;
		}
		else {
			cout << "White Blank" << endl;
		}
	}
}

void Brick::clear_bricks() {
	vector<Coord>().swap(all_bricks);
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
	for (auto& x : all_bricks) {
		x.display_set();
	}
}

void Brick::Render()
{	
	for (int i = 0; i < sum_bricks; i++) {
		if (i % 20 == 0) {
			gotoxy(goto_x, goto_y + 2);
			goto_y = goto_y + 2;
		}
		if (all_bricks[i].get_display_signal()) {
			cout << "■";
		}
		else {
			cout << "  ";
		}
	}
}
Coord Brick::get_coord(int x, int y) {
	if (x == 0) {
		return all_bricks[x + y];
	}
	else if (x == 1) {
		return all_bricks[x + y + 19];
	}
	else if (x == 2) {
		return all_bricks[x + y + 39];
	}
}
