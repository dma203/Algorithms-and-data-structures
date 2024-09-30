// Copyright 2024 Matvey Demidovich

#ifndef LIB_QUEUE_H_
#define LIB_QUEUE_H_

template<class T>
class Queue {
	T* _data;
	size_t _size;
	size_t _top;
	size_t _front;
	size_t _q_size;
public:
	Queue(size_t size = 20);
	~Queue();

	bool isFull() const noexcept;
	int q_size();
	void push(T val);
	bool isEmpty() const noexcept;
	void pop();
	T top();
	T front();
};

template<class T>
Queue<T>::Queue(size_t size = 20) {
	_size = size;
	_data = new T[size];
	_top = 0;
	_front = 0;
}

template<class T>
Queue<T>::~Queue() {
	delete[] _data;
	_data = nullptr;
}

template<class T>
inline bool Queue<T>::isFull() const noexcept
{
	if (_top == _size) {
		return true;
	}
	return false;
}

template<class T>
inline int Queue<T>::q_size() {
	if (_front > _top)
		return _q_size = _size - _front + _top;
	else
		return _q_size = _top - _front;
}

template<class T>
void Queue<T>::push(T val)
{
	if (isFull()) {
		throw std::logic_error("...");
	}
	if (isEmpty()) {
		_front += 1;
		_data[_front] = val;
	}
		_data[_top] = val;
		_top = (_top + 1) % _q_size;

}

template<class T>
inline bool Queue<T>::isEmpty() const noexcept
{
	if (_top == 0) {
		return true;
	}
	return false;
}

template<class T>
void Queue<T>::pop()
{
	if (isEmpty()) {
		throw std::logic_error("...");
	}
	_front = (_front + 1) % _q_size;
}

template<class T>
inline T Queue<T>::top()
{
	if (isEmpty()) {
		throw std::logic_error("...");
	}
	return _data[_top - 1];
}

template<class T>
inline T Queue<T>::front()
{
	if (isEmpty()) {
		throw std::logic_error("...");
	}
	return _data[_front];
}

#endif  // LIB_QUEUE_QUEUE_H_
