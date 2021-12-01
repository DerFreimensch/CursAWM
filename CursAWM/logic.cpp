#include "pch.h"
#include "logic.h"

logic::logic() {
	this->adr = FALSE;
	this->op = 0;
	this->l_trans = 0;
	this->c_time = 0;
	this->n_trans = 0;
	this->mas = new int[0];
}
logic::logic(BOOL a, int o, int l, int c, int n) : 
	adr(a), op(o), l_trans(l), c_time(c), n_trans(n) {
	mas = new int[n];
}
void logic::create_mas() {
	if (c_time == 0) {
		for (int i = 0; i < this->n_trans; i++) {
			mas[i] = 100;
		}
	}
	else if (c_time == 1) {
		for (int i = 0; i < this->n_trans; i++) {
			mas[i] = 200;
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
			else mas[i] = 20;
			
		}
	}
	else if (c_time == 4) {
		for (int i = 0; i < this->n_trans; i++) {
			if (i % 4 == 0) mas[i] = 75;
			else mas[i] = 25;

		}
	}
	else if (c_time == 5) {
		for (int i = 0; i < this->n_trans; i++) {
			if (i % 4 == 0) mas[i] = 45;
			else mas[i] = 30;

		}
	}
	else if (c_time == 6) {
		for (int i = 0; i < this->n_trans; i++) {
			if (i % 2 == 0) mas[i] = 80;
			else mas[i] = 20;

		}
	}
	else if (c_time == 7) {
		for (int i = 0; i < this->n_trans; i++) {
			if (i % 2 == 0) mas[i] = 100;
			else mas[i] = 40;

		}
	}
	else if (c_time == 8) {
		for (int i = 0; i < this->n_trans; i++) {
			mas[i] = 70;
		}
	}
}