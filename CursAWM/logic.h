#pragma once
class logic
{
private: 
	BOOL adr;
	int op;
	int l_trans;
	int c_time;
	int n_trans;
	int *mas;
public:
	logic();
	logic(BOOL a, int o, int l, int c, int n);
	void create_mas();
};


