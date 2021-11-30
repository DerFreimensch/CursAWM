#include "pch.h"
#include "logic.h"

logic::logic() {
	this->adr = FALSE;
	this->op = 0;
	this->l_trans = 0;
	this->c_time = 0;
	this->n_trans = 0;
}
logic::logic(BOOL a, int o, int l, int c, int n) : 
	adr(a), op(o), l_trans(l), c_time(c), n_trans(n) {

}