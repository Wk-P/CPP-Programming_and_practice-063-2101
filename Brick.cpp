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
		if (i < 10) {
			all_bricks.push_back(temp);
			temp.set_coord(temp.get_x()+1, temp.get_y());
		}
		else if (10 <= i && i < 20){
			all_bricks.push_back(temp);
			temp.set_coord(temp.get_x() + 1, temp.get_y());
		}
		else {
			all_bricks.push_back(temp);
			temp.set_coord(temp.get_x() + 1, temp.get_y());
		}
		if (i == 9) {
			temp.set_coord(0, temp.get_y() + 1);
		}
		else if (i == 19){
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

void Brick::print_bricks()
{	
	for (int i = 0; i < sum_bricks; i++) {
		if (all_bricks[i].get_display_signal()) {
			cout << "¡ö";
		}
		else {
			cout << " ";
		}
		if (i % 20 == 0) {
			gotoxy(goto_x, goto_y+2);
			goto_y = goto_y + 2;
		}
	}
}