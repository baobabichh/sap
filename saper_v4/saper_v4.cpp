#include"Header.h"
#include"Entity.h"
#include"Cell.h"
#include "Cell_field.h"
int main()
{	//srand
	srand(time(NULL));
	//text
	sf::Text text;
	Font f;
	f.loadFromFile("STAY HOME.otf");
	text.setFont(f); 
	text.setString("Hello world");
	text.setCharacterSize(40); // in pixels, not points!
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	//window setup
	int x = 0;
	int mine = 0;
	string str;
	while (1)
	{
		cout << "Enter saper size : ";
		cin >> str;
		if (is_digit(str))
		{
			break;
		}
	}
	x = atoi(str.c_str());
	while (1)
	{
		cout << "Enter mine size : ";
		cin >> str;
		if (is_digit(str))
		{
			break;
		}
		
	}
	mine = atoi(str.c_str());
	//texture
	Texture t;
	t.loadFromFile(SAPER_IMAGE);
	//cell
	Cell_field field(t,x,x,mine);

	RenderWindow window(VideoMode(x*32, x*32), "Minesweeper!");
	

	Cell c;
	c.set_texture(t);
	c.set_real_id(State::flag);
	
	
	while (window.isOpen())
	{
		Event e;

		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
			field.key_respond(window);
			if (Keyboard::isKeyPressed(Keyboard::R))
			{
				field.restart();
			}
		}

		window.clear();

		field.update();
		field.draw(window);
		if (field.get_is_end())
		{
			if (field.get_is_win())
			{
				text.setString("You win!");
				text.setPosition(x * 32 / 2 - text.getGlobalBounds().width / 2, x * 32 / 2 - text.getGlobalBounds().height / 2);
				window.draw(text);

			}
			else
			{
				text.setString("You lose!");
				text.setPosition(x * 32 / 2 - text.getGlobalBounds().width / 2, x * 32 / 2 - text.getGlobalBounds().height / 2);
				window.draw(text);
			}
		}
		
		//c.draw(window);
		window.display();

	}
	return 0;
}