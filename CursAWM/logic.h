#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
class logic
{
private: 
	BOOL adr;
	int clk;
	int op;
	int l_trans;
	int c_time;
	int n_trans;
	int *mas;
	int whole_lenght;
public:
	logic();
	logic(BOOL a, int o, int l, int c, int n);
	void create_mas();
	void show();
	int check_lengh(int* pace, int op);
};



