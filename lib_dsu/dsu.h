// Copyright 2024 Matvey Demidovich

#include <stdexcept>
#ifndef LIB_DSU
#define LIB_DSU

class DSU {
	int _size;
	int* _p;
	int* _rk;


public:
	DSU(int size = 0);
	~DSU();
	int make_set(int elem);
	int find(int elem);
	void dsu_union(int first, int second);
	//void clear();
};

DSU::DSU(int size)
{
	_size = size;
	_p[_size];
	_rk[_size];
	for (int i = 0; i < _size; i++) {
		_p[i] = i;
		_rk[i] = 1;
	}
}

DSU::~DSU()
{
	delete _p;
	delete _rk;
}

int DSU::make_set(int elem)
{
	if (_p[elem] == elem) {
		return elem;
	}
	else {
		return _p[elem] = make_set(_p[elem]);
	}
}

int DSU::find(int elem)
{
	for (int i = 0; i < _size; i++) {
		if (_p[i] = elem) {
			return i;
		}
		else throw std::logic_error("Element not found");
	}
}
void DSU::dsu_union(int first, int second)
{
	int ra = make_set(first), rb = make_set(second);

	if (ra == rb) {
		return;
	}
	else {
		if (_rk[ra] < _rk[rb]) {
			_p[ra] = rb;
		}
		else if (_rk[rb] < _rk[ra]) {
			_p[rb] = ra;
		}
		else {
			_p[ra] = rb;
			_rk[rb]++;
		}
		return;
	}
}



#endif  // LIB_DSU