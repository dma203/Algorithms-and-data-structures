// Copyright 2024 Matvey Demidovich

#ifndef LIB_STACK_H_
#define LIB_STACK_H_

template<class T>
class TStack {
	T* _data;
	size_t _size;
	size_t _top;
public:
	TStack(size_t size = 20);
	~TStack();

	bool isFull() const noexcept;
	void push(T val);
	bool isEmpty() const noexcept;
	void pop();
	T top();
};

template<class T>
TStack<T>::TStack(size_t size = 20) {
	_size = size;
	_data = new T[size];
	_top = -1;
}

template<class T>
TStack<T>::~TStack() {
	delete[] _data;
	_data = nullptr;
}

template<class T>
inline bool TStack<T>::isFull() const noexcept
{
	if (_top == _size - 1) {
		return true;
	}
	return false;
}

template<class T>
inline void TStack<T>::push(T val)
{
	if (isFull()) {
		throw;
	}
	_top += 1;
	_data[_top] = val;
}

template<class T>
inline bool TStack<T>::isEmpty() const noexcept
{
	if (_top == -1) {
		return true;
	}
	return false;
}

template<class T>
void TStack<T>::pop()
{
	if (isEmpty()) {
		throw;
	}
	_top = _top - 1;
}

template<class T>
inline T TStack<T>::top()
{
	if (isEmpty()) {
		throw std::logic_error("...");
	}
	return _data[_top];
}

#endif  // LIB_STACK_H_
