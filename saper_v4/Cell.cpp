#include"Cell.h"
Cell::Cell()
{
	real_id = State::empty_open;
	show_id = State::empty_closed;
	is_open = 0;
}

Cell::~Cell()
{
}

void Cell::set_real_id(int value)
{
	real_id = value;
	switch (real_id)
	{
	case 0:
		real_entity.setTextureRect(IntRect(0, 0, 32, 32));
		break;
	case 1:
		real_entity.setTextureRect(IntRect(1 * 32, 0, 32, 32));
		break;
	case 2:
		real_entity.setTextureRect(IntRect(2 * 32, 0, 32, 32));
		break;
	case 3:
		real_entity.setTextureRect(IntRect(3 * 32, 0, 32, 32));
		break;
	case 4:
		real_entity.setTextureRect(IntRect(4 * 32, 0, 32, 32));
		break;
	case 5:
		real_entity.setTextureRect(IntRect(5 * 32, 0, 32, 32));
		break;
	case 6:
		real_entity.setTextureRect(IntRect(6 * 32, 0, 32, 32));
		break;
	case 7:
		real_entity.setTextureRect(IntRect(7 * 32, 0, 32, 32));
		break;
	case 8:
		real_entity.setTextureRect(IntRect(8 * 32, 0, 32, 32));
		break;
	case 9:
		real_entity.setTextureRect(IntRect(9 * 32, 0, 32, 32));
		break;
	case 10:
		real_entity.setTextureRect(IntRect(10 * 32, 0, 32, 32));
		break;
	case 11:
		real_entity.setTextureRect(IntRect(11 * 32, 0, 32, 32));
		break;
	default:
		break;
	}
}
void Cell::set_show_id(int value)
{
	show_id = value;
	switch (show_id)
	{
	case 0:
		show_entity.setTextureRect(IntRect(0, 0, 32, 32));
		break;
	case 1:
		show_entity.setTextureRect(IntRect(1 * 32, 0, 32, 32));
		break;
	case 2:
		show_entity.setTextureRect(IntRect(2 * 32, 0, 32, 32));
		break;
	case 3:
		show_entity.setTextureRect(IntRect(3 * 32, 0, 32, 32));
		break;
	case 4:
		show_entity.setTextureRect(IntRect(4 * 32, 0, 32, 32));
		break;
	case 5:
		show_entity.setTextureRect(IntRect(5 * 32, 0, 32, 32));
		break;
	case 6:
		show_entity.setTextureRect(IntRect(6 * 32, 0, 32, 32));
		break;
	case 7:
		show_entity.setTextureRect(IntRect(7 * 32, 0, 32, 32));
		break;
	case 8:
		show_entity.setTextureRect(IntRect(8 * 32, 0, 32, 32));
		break;
	case 9:
		show_entity.setTextureRect(IntRect(9 * 32, 0, 32, 32));
		break;
	case 10:
		show_entity.setTextureRect(IntRect(10 * 32, 0, 32, 32));
		break;
	case 11:
		show_entity.setTextureRect(IntRect(11 * 32, 0, 32, 32));
		break;
	default:
		break;
	}
}
void Cell::open()
{
	is_open = 1;
}
int Cell::get_real_id()
{
	return real_id;
}
int Cell::get_show_id()
{
	return show_id;
}
void Cell::set_pos(float x, float y)
{
	real_entity.setPosition(x, y);
	show_entity.setPosition(x, y);
}
Vector2f Cell::get_pos()
{
	return real_entity.getPosition();
}
void Cell::set_pos(Vector2f& pos)
{
	real_entity.setPosition(pos);
	show_entity.setPosition(pos);
}
bool Cell::is_hovered(RenderWindow&window)
{
	return real_entity.is_hovered(window);
}
void Cell::draw(RenderWindow& window)
{
	if (!is_open)
	{
		window.draw(show_entity);
	}
	else
	{
		window.draw(real_entity);
	}
	
}
void Cell::set_texture(Texture& t)
{
	real_entity.setTexture(t);
	show_entity.setTexture(t);
}
bool Cell::get_is_open()
{
	return is_open;
}
void Cell::update()
{
	set_real_id(real_id);
	set_show_id(show_id);
}
void Cell::close()
{
	is_open = 0;
}