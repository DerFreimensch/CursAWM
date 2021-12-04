#include "pch.h"
#include "logic.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#define HIGH 75
#define MULT 1
using namespace sf;
logic::logic() {
	this->adr = FALSE;
	this->op = 0;
	this->l_trans = 0;
	this->c_time = 0;
	this->n_trans = 0;
	this->mas = new int[0];
	this -> clk = 30;
	this->whole_lenght = 0;
}
logic::logic(BOOL a, int o, int l, int c, int n) : 
	adr(a), op(o), l_trans(l), c_time(c), n_trans(n) {
	this->mas = new int[n];
	this->clk = 30;
	this->whole_lenght = 0;
}


void logic::create_mas() {
	if (c_time == 0) {
		for (int i = 0; i < this->n_trans; i++) {
			mas[i] = 120;
		}
	}
	else if (c_time == 1) {
		for (int i = 0; i < this->n_trans; i++) {
			mas[i] = 210;
		}
	}
	else if (c_time == 2) {
		for (int i = 0; i < this->n_trans; i++) {
			mas[i] = 30;
		}
	}
	else if (c_time == 3) {
		for (int i = 0; i < this->n_trans; i++) {
			if (i % 4 == 0) mas[i] = 60;
			else mas[i] = 30;
			
		}
	}
	else if (c_time == 4) {
		for (int i = 0; i < this->n_trans; i++) {
			if (i % 4 == 0) mas[i] = 90;
			else mas[i] = 30;

		}
	}
	else if (c_time == 5) {
		for (int i = 0; i < this->n_trans; i++) {
			if (i % 4 == 0) mas[i] = 60;
			else mas[i] = 30;

		}
	}
	else if (c_time == 6) {
		for (int i = 0; i < this->n_trans; i++) {
			if (i % 2 == 0) mas[i] = 90;
			else mas[i] = 30;

		}
	}
	else if (c_time == 7) {
		for (int i = 0; i < this->n_trans; i++) {
			if (i % 2 == 0) mas[i] = 120;
			else mas[i] = 60;

		}
	}
	else if (c_time == 8) {
		for (int i = 0; i < this->n_trans; i++) {
			mas[i] = 90;
		}
	}
	for (int i = 0; i < this->n_trans; i++) {
		this->whole_lenght += mas[i];
	}
}

int logic::check_lengh(int* pace, int op) {
	int num_of_lines;
	num_of_lines = whole_lenght / 15;
	if (whole_lenght % 15 >= 7) num_of_lines+=2;
	if (!adr) num_of_lines+=2;// для адреса
	else num_of_lines += 4;
	if (op == 2 || op == 3) num_of_lines += 2;
	num_of_lines += 4;
	*pace = 1610 / num_of_lines;
	return num_of_lines;
}

void logic::show() {

	sf::Font font;//шрифт 
	font.loadFromFile("arial.ttf");//передаем нашему шрифту файл шрифта
	Text names[7];
	Text text1("CLK", font, 40);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	Text text2("FRAME#", font, 40);
	Text text3("AD", font, 40);
	Text text4("C/BE#", font, 40);
	Text text5("IRDY#", font, 40);
	Text text6("TRDY#", font, 40);
	Text text7("DEVSEL#", font, 40);
	text1.setStyle(sf::Text::Bold);
	text1.move(50, 90);
	text2.setStyle(sf::Text::Bold);
	text2.move(50, 215);
	text3.setStyle(sf::Text::Bold);
	text3.move(50, 340);
	text4.setStyle(sf::Text::Bold);
	text4.move(50, 465);
	text5.setStyle(sf::Text::Bold);
	text5.move(50, 590);
	text6.setStyle(sf::Text::Bold);
	text6.move(50, 715);
	text7.setStyle(sf::Text::Bold);
	text7.move(50, 840);
	names[0] = text1;
	names[1] = text2;
	names[2] = text3;
	names[3] = text4;
	names[4] = text5;
	names[5] = text6;
	names[6] = text7;

	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(1910, 1070), "SFML works!", Style::Default, settings);
	RectangleShape line[7];
	int pace = 0;
	int num = check_lengh(&pace, this->op);
	RectangleShape* CLK = new RectangleShape[num];
	RectangleShape* vert = new RectangleShape[num];
	for (int i = 0; i < num; i++) {
		RectangleShape line_it(Vector2f(pace, 30.f));
		RectangleShape line_it1(Vector2f(800, 1.f));
		line_it1.setFillColor(Color(255, 255, 255));
		if(i%2 == 0) line_it.setFillColor(Color(255, 0, 0));
		else line_it.setFillColor(Color(0, 255, 0));
		//CLK[i].rotate(90.f);
		line_it1.rotate(90.f);
		if(i == 0) line_it1.move(250 + pace *(i + 1), 110);
		else line_it1.move(250 + pace *(2*i+1), 110);
		line_it.move(250+pace*(i), 110);
		vert[i] = line_it1;
		CLK[i] = line_it;
	}
	for (int i = 0; i < 7; i++) {
		RectangleShape line_it(Vector2f(1610, 5.f));
		line_it.setFillColor(Color(255, 255, 255));
		//line[i].rotate(90.f);
		line_it.move(250, 125*(i+1));
		line[i] = line_it;
	}
	int g = (mas[n_trans - 1] / 30)*2;
	RectangleShape frame[3];
	RectangleShape line_1(Vector2f(pace * 2, 30.f));
	RectangleShape line_2(Vector2f(pace * (num - 4-g), 30.f));
	RectangleShape line_3(Vector2f(pace * (2 +g), 30.f));
	line_1.setFillColor(Color(255, 0, 0));
	line_2.setFillColor(Color(0, 255, 0));
	line_3.setFillColor(Color(255, 0, 0));
	
	line_1.move(250,250);
	line_2.move(250 + pace * 2, 250);
	line_3.move(250 + pace * (num - 2-g), 250);
	frame[0] = line_1;
	frame[1] = line_2;
	frame[2] = line_3;
	while (window.isOpen())
	{
		Vector2i localPosition = Mouse::getPosition(window);
		
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear(Color(0, 0, 0, 0));
		for (int i = 0; i < 7; i++) {
			window.draw(names[i]);
			
			window.draw(line[i]);
		}
		for (int i = 0; i < num; i++) {
			window.draw(CLK[i]);
			window.draw(vert[i]);
		}
		for (int i = 0; i < 3; i++) {
			window.draw(frame[i]);
		}
		
		window.display();
	}
}


