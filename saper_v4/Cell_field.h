#pragma once
#include"Header.h"
#include"Cell.h"
#include<vector>
#include"functions.h"
class Cell;

class Cell_field
{
public:
	Cell_field(Texture& t, int x_, int y_, int mine_);
	~Cell_field();
	void draw(RenderWindow& window);
	void key_respond(RenderWindow& window);
	bool get_is_end();
	void update();
	bool get_is_win();
	//void set_size(int x ,int y);
	//void set_size(Vector2i v);
	//void set_max_mines(int q);
	Vector2i get_size();
	int get_max_mines();
	void restart();
private:
	void open_free(int x, int y);
	bool is_elem(int x, int y);
	vector<vector<Cell>> field;
	bool is_end , is_win;
	int max_mines, x_len, y_len;
};

