#include "pch.h"
#include "logic.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <string>
#include <cmath>
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
	this->size_it = 35;
}
logic::logic(BOOL a, int o, int l, int c, int n) : 
	adr(a), op(o), l_trans(l), c_time(c), n_trans(n) {
	this->mas = new int[n];
	this->clk = 30;
	this->whole_lenght = 0;
	this->size_it = 35;
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
	RectangleShape fline_1(Vector2f(pace * 2, 30.f));
	RectangleShape fline_2(Vector2f(pace * (num - 4-g), 30.f));
	RectangleShape fline_3(Vector2f(pace * (2 +g), 30.f));
	fline_1.setFillColor(Color(255, 0, 0));
	fline_2.setFillColor(Color(0, 255, 0));
	fline_3.setFillColor(Color(255, 0, 0));
	fline_1.move(250,225);
	fline_2.move(250 + pace * 2, 225);
	fline_3.move(250 + pace * (num - 2-g), 225);
	frame[0] = fline_1;
	frame[1] = fline_2;
	frame[2] = fline_3;
	RectangleShape irdy[3];
	RectangleShape iline_1(Vector2f(pace * 2, 30.f));
	RectangleShape iline_2(Vector2f(pace * (num - 4), 30.f));
	RectangleShape iline_3(Vector2f(pace * 2, 30.f));
	iline_1.setFillColor(Color(255, 0, 0));
	iline_2.setFillColor(Color(0, 255, 0));
	iline_3.setFillColor(Color(255, 0, 0));
	iline_1.move(250, 600);
	iline_2.move(250 + pace * 2, 600);
	iline_3.move(250 + pace * (num - 2), 600);
	irdy[0] = iline_1;
	irdy[1] = iline_2;
	irdy[2] = iline_3;
	RectangleShape trdy[3];
	RectangleShape tline_1(Vector2f(pace * 2, 30.f));
	RectangleShape tline_2(Vector2f(pace * (num - 4), 30.f));
	RectangleShape tline_3(Vector2f(pace * 2, 30.f));
	tline_1.setFillColor(Color(255, 0, 0));
	tline_2.setFillColor(Color(0, 255, 0));
	tline_3.setFillColor(Color(255, 0, 0));
	tline_1.move(250, 725);
	tline_2.move(250 + pace * 2, 725);
	tline_3.move(250 + pace * (num - 2), 725);
	trdy[0] = tline_1;
	trdy[1] = tline_2;
	trdy[2] = tline_3;
	RectangleShape devsel[3];
	RectangleShape dline_1(Vector2f(pace * 2, 30.f));
	RectangleShape dline_2(Vector2f(pace * (num - 4), 30.f));
	RectangleShape dline_3(Vector2f(pace * 2, 30.f));
	dline_1.setFillColor(Color(255, 0, 0));
	dline_2.setFillColor(Color(0, 255, 0));
	dline_3.setFillColor(Color(255, 0, 0));
	dline_1.move(250, 850);
	dline_2.move(250 + pace * 2, 850);
	dline_3.move(250 + pace * (num - 2), 850);
	devsel[0] = dline_1;
	devsel[1] = dline_2;
	devsel[2] = dline_3;
	RectangleShape adress(Vector2f(pace * 2, 30.f));
	RectangleShape adress2(Vector2f(pace * 2, 30.f));
	std::string l;
	if (op == 0) {
		l = "Using codes: adr:0111";
	}
	else if (op == 1) {
		l = "Using codes: adr:0011";
	}
	else if (op == 2) {
		l = "Using codes: adr:0110";
	}
	else {
		l = "Using codes: adr:0010";
	}
	if (adr) {
		l = l + " adrEx: 1101";
	}
	if (l_trans == 0) {
		l = l+ " data:1100";
	}
	else if (l_trans == 1) {
		l = l + " data:0000";
	}
	else if (l_trans == 2) {
		l = l + " data:0000";
	}
	else {
		l = l + " data:1110";
	}
	
	size_it = size_it - int(std::log2(num));
	Text adr1(l,font, size_it);
	adr1.move(250, 950);
	
	adress.setFillColor(Color(0, 0, 255));
	adress.move(250 + pace * 2, 350);
	adress2.setFillColor(Color(0, 0, 255));
	adress2.move(250 + pace * 4, 350);
	adress.setOutlineThickness(2.f);
	adress2.setOutlineThickness(2.f);
	RectangleShape* mas1 = new RectangleShape[n_trans];
	int acm = 0;
	for (int i = 0; i < n_trans; i++) {
		if (op == 0 || op == 1) {
			
			RectangleShape tr(Vector2f(pace * 2 * mas[i] / 30, 30.f));
			tr.move(250 + pace*4 +acm, 350);
			tr.setOutlineThickness(2.f);
			tr.setFillColor(Color(0, 0, 255));
			mas1[i] = tr;
			acm += pace * 2 * mas[i] / 30;
		}
		else {
			RectangleShape tr(Vector2f(pace * 2 * mas[i] / 30, 30.f));
			tr.move(250 + pace*6 + acm, 350);
			tr.setOutlineThickness(2.f);
			tr.setFillColor(Color(0, 0, 255));
			mas1[i] = tr;
			acm += pace * 2 * mas[i] / 30;
		}
	}

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
			window.draw(irdy[i]);
			window.draw(trdy[i]);
			window.draw(devsel[i]);
		}
		window.draw(adress);
		if (adr) window.draw(adress2);
		window.draw(adr1);
		for (int i = 0; i < n_trans; i++) {
			window.draw(mas1[i]);
		}
		window.display();
		
	}
}


