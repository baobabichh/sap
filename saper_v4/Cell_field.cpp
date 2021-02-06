#include"Cell_field.h"
Cell_field::Cell_field(Texture & t , int x_ , int y_ , int mine_)
{
	max_mines = mine_;
	x_len = x_;
	y_len = y_;
	is_win = 0;
	is_end = 0;
	
	// создание массива
	field.resize(x_len);
	for (int i = 0; i < x_len; i++)
	{
		field[i].resize(y_len);
	}
	// задаём текстуры
	for (int i = 0; i < x_len; i++)
	{
		for (int j = 0; j < y_len; j++)
		{
			field[i][j].set_texture(t);
			field[i][j].set_real_id(State::empty_open);
			field[i][j].set_show_id(State::empty_closed);
			field[i][j].set_pos(i * 32, j * 32);
		}
	}
	// создаём мины
	for (int i = 0; i < max_mines; i++)
	{
		while (1)
		{
			int x = random(0, x_len);
			int y = random(0, y_len);
			if (field[x][y].get_real_id() != State::mine)
			{
				field[x][y].set_real_id(State::mine);
				break;
			}
		}
	}
	// заполняем цифры
	for (int i = 0; i < x_len; i++)
	{
		for (int j = 0; j < y_len; j++)
		{
			if ( field[i][j].get_real_id() == State::mine)
			{
				if (is_elem(i - 1, j) && field[i - 1][j].get_real_id() != State::mine) { field[i - 1][j].set_real_id(field[i - 1][j].get_real_id() + 1); }//лево
				if (is_elem(i, j - 1) && field[i][j - 1].get_real_id() != State::mine) { field[i][j - 1].set_real_id(field[i][j - 1].get_real_id() + 1); }//верх
				if (is_elem(i - 1, j - 1) && field[i - 1][j - 1].get_real_id() != State::mine) { field[i - 1][j - 1].set_real_id(field[i - 1][j - 1].get_real_id() + 1); }//лево вверх
				if (is_elem(i + 1, j) && field[i + 1][j].get_real_id() != State::mine) { field[i + 1][j].set_real_id(field[i + 1][j].get_real_id() + 1); }//право
				if (is_elem(i, j + 1) && field[i][j + 1].get_real_id() != State::mine) { field[i][j + 1].set_real_id(field[i][j + 1].get_real_id() + 1); }//низ
				if (is_elem(i + 1, j + 1) && field[i + 1][j + 1].get_real_id() != State::mine) { field[i + 1][j + 1].set_real_id(field[i + 1][j + 1].get_real_id() + 1); }
				if (is_elem(i - 1, j + 1) && field[i - 1][j + 1].get_real_id() != State::mine) { field[i - 1][j + 1].set_real_id(field[i - 1][j + 1].get_real_id() + 1); }
				if (is_elem(i + 1, j - 1) && field[i + 1][j - 1].get_real_id() != State::mine) { field[i + 1][j - 1].set_real_id(field[i + 1][j - 1].get_real_id() + 1); }
			}
		}
	}
	
}
bool Cell_field::is_elem(int x, int y)
{
	if (x >= 0 && x < x_len && y >= 0 && y < y_len)
	{
		return 1;
	}
	return 0;
}
Cell_field::~Cell_field()
{
}
void Cell_field::draw(RenderWindow& window)
{
	if (is_end)
	{
		for (int i = 0; i < x_len; i++)
		{
			for (int j = 0; j < y_len; j++)
			{
				field[i][j].open();
				field[i][j].draw(window);
			}
		}
	}
	else
	{
		for (int i = 0; i < x_len; i++)
		{
			for (int j = 0; j < y_len; j++)
			{
				field[i][j].draw(window);
				//cout << field[i][j].get_real_id() << " ";
			}
			//cout << endl;
		}
	}
}
void Cell_field::key_respond(RenderWindow& window)
{
	for (int i = 0; i < x_len; i++)
	{
		for (int j = 0; j < y_len; j++)
		{
			if (field[i][j].is_hovered(window) && Mouse::isButtonPressed(Mouse::Left) && field[i][j].get_show_id()!=State::flag)
			{
				//field[i][j].open();
				open_free(i, j);
			}
			else if (field[i][j].is_hovered(window) && Mouse::isButtonPressed(Mouse::Right))
			{
				//field[i][j].open();
				if (field[i][j].get_show_id() == State::flag)
				{
					field[i][j].set_show_id(State::empty_closed);
				}
				else if (field[i][j].get_show_id() == State::empty_closed)
				{
					field[i][j].set_show_id(State::flag);
				}
			}
		}
	}
}
void Cell_field::open_free(int x, int y)
{
	if (field[x][y].get_real_id() == State::mine)
		is_end = 1;
	if (field[x][y].get_is_open()  )
		return;
	field[x][y].open();

	if (field[x][y].get_real_id() == State::empty_open) {
		if (is_elem(x - 1, y - 1)) { open_free(x - 1, y - 1); }
		if (is_elem(x, y - 1)) { open_free(x, y - 1); }
		if (is_elem(x + 1, y - 1)) { open_free(x + 1, y - 1); }
		if (is_elem(x - 1, y)) { open_free(x - 1, y); }
		if (is_elem(x + 1, y)) { open_free(x + 1, y); }
		if (is_elem(x - 1, y + 1)) { open_free(x - 1, y + 1); }
		if (is_elem(x, y + 1)) { open_free(x, y + 1); }
		if (is_elem(x + 1, y + 1)) { open_free(x + 1, y + 1); }
	}
}
bool Cell_field::get_is_end()
{
	return is_end;
}
void Cell_field::update()
{
	int cur = 0;
	for (int i = 0; i < x_len; i++)
	{
		for (int j = 0; j < y_len; j++)
		{
			if (field[i][j].get_real_id() == State::mine&& field[i][j].get_show_id() == State::flag)
			{
				cur++;
			}
		}
	}
	if (cur == max_mines)
	{
		is_end = 1;
		is_win = 1;
	}
}
bool Cell_field::get_is_win()
{
	return is_win;
}
//void Cell_field::set_size(Vector2i v)
//{
//	x_len = v.x;
//	y_len = v.y;
//}
//void Cell_field::set_size(int x ,int y)
//{
//	x_len = x;
//	y_len = y;
//}
//void Cell_field::set_max_mines(int q)
//{
//	max_mines = q;
//}
Vector2i Cell_field::get_size()
{
	return Vector2i(x_len, y_len);
}
int Cell_field::get_max_mines()
{
	return max_mines;
}
void Cell_field::restart()
{
	is_win = 0;
	is_end = 0;

	// создание массива
	field.resize(x_len);
	for (int i = 0; i < x_len; i++)
	{
		field[i].resize(y_len);
	}
	// задаём текстуры
	for (int i = 0; i < x_len; i++)
	{
		for (int j = 0; j < y_len; j++)
		{
			field[i][j].set_real_id(State::empty_open);
			field[i][j].set_show_id(State::empty_closed);
			field[i][j].close();
			field[i][j].set_pos(i * 32, j * 32);
		}
	}
	// создаём мины
	for (int i = 0; i < max_mines; i++)
	{
		while (1)
		{
			int x = random(0, x_len);
			int y = random(0, y_len);
			if (field[x][y].get_real_id() != State::mine)
			{
				field[x][y].set_real_id(State::mine);
				break;
			}
		}
	}
	// заполняем цифры
	for (int i = 0; i < x_len; i++)
	{
		for (int j = 0; j < y_len; j++)
		{
			if (field[i][j].get_real_id() == State::mine)
			{
				if (is_elem(i - 1, j) && field[i - 1][j].get_real_id() != State::mine) { field[i - 1][j].set_real_id(field[i - 1][j].get_real_id() + 1); }//лево
				if (is_elem(i, j - 1) && field[i][j - 1].get_real_id() != State::mine) { field[i][j - 1].set_real_id(field[i][j - 1].get_real_id() + 1); }//верх
				if (is_elem(i - 1, j - 1) && field[i - 1][j - 1].get_real_id() != State::mine) { field[i - 1][j - 1].set_real_id(field[i - 1][j - 1].get_real_id() + 1); }//лево вверх
				if (is_elem(i + 1, j) && field[i + 1][j].get_real_id() != State::mine) { field[i + 1][j].set_real_id(field[i + 1][j].get_real_id() + 1); }//право
				if (is_elem(i, j + 1) && field[i][j + 1].get_real_id() != State::mine) { field[i][j + 1].set_real_id(field[i][j + 1].get_real_id() + 1); }//низ
				if (is_elem(i + 1, j + 1) && field[i + 1][j + 1].get_real_id() != State::mine) { field[i + 1][j + 1].set_real_id(field[i + 1][j + 1].get_real_id() + 1); }
				if (is_elem(i - 1, j + 1) && field[i - 1][j + 1].get_real_id() != State::mine) { field[i - 1][j + 1].set_real_id(field[i - 1][j + 1].get_real_id() + 1); }
				if (is_elem(i + 1, j - 1) && field[i + 1][j - 1].get_real_id() != State::mine) { field[i + 1][j - 1].set_real_id(field[i + 1][j - 1].get_real_id() + 1); }
			}
		}
	}
}