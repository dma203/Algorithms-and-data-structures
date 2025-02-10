// Copyright 2024 Matvey Demidovich

#ifndef LIB_DSU
#define LIB_DSU

class DSU {
	int _size;
	int* _parent;
	int* _rank;

public:
	DSU(int size = 0);
	~DSU();
	void make_set(int elem);
	int find(int elem);
	void union(int first, int second);
	void clear();
};

#endif  // LIB_DSU