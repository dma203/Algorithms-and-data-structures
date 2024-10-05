// Copyright 2024 Matvey Demidovich

#ifndef LIB_STACK_H_
#define LIB_STACK_H_

template<class T>
class Stack {
	T* _data;
	size_t _size;
	size_t _top;
public:
	Stack(size_t size = 20);
	~Stack();

	bool isFull() const noexcept;
	void push(T val);
	bool isEmpty() const noexcept;
	void pop();
	T top();
};

template<class T>
Stack<T>::Stack(size_t size = 20) {
	_size = size;
	_data = new T[size];
	_top = -1;
}

template<class T>
Stack<T>::~Stack() {
	delete[] _data;
	_data = nullptr;
}

template<class T>
inline bool Stack<T>::isFull() const noexcept
{
	if (_top == _size - 1) 
	{
        return true;
	}
	return false;
}

template<class T>
inline void Stack<T>::push(T val)
{
	if (isFull()) 
	{
		throw std::logic_error("...");
	}
	_top += 1;
	_data[_top] = val;
}

template<class T>
inline bool Stack<T>::isEmpty() const noexcept
{
	if (_top == -1) 
	{
		return true;
	}
	return false;
}

template<class T>
void Stack<T>::pop()
{
	if (isEmpty()) 
	{
		throw std::logic_error("Stack is empty can not use pop");
	}
	_top = _top - 1;
}

template<class T>
inline T Stack<T>::top()
{
	if (isEmpty()) 
	{
		throw std::logic_error("Stack is empty can not use top");
	}
	return _data[_top];
}

#endif  // LIB_STACK_STACK_H_
