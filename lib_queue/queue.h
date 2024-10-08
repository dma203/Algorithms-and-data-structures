// Copyright 2024 Matvey Demidovich

#ifndef LIB_QUEUE_H_
#define LIB_QUEUE_H_

template<class T>
class Queue {
	T* _data;
	size_t _size;
	size_t _top;
	size_t _front;
public:
	Queue(size_t size = 20);
	~Queue();

	bool isFull() const noexcept;
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
	_top = -1;
	_front = -1;
}

template<class T>
Queue<T>::~Queue() {
	delete[] _data;
	_data = nullptr;
}

template<class T>
inline bool Queue<T>::isFull() const noexcept
{
	if (_front == 0 && _top == _size - 1) {
		return true;
	}
	if (_front == _top + 1) {
		return true;
	}
	return false;
}

template<class T>
inline bool Queue<T>::isEmpty() const noexcept
{
	if (_front == -1) {
		return true;
	}
	return false;
}


template<class T>
void Queue<T>::push(T val)
{
	if (isFull()) {
		throw std::logic_error("Queue is full");
	}
	else if (isEmpty()) {
		_front = 0;
	}
		_top = (_top + 1) % _size;
		_data[_top] = val;

}

template<class T>
void Queue<T>::pop()
{
	if (isEmpty()) {
		throw std::logic_error("Queue is empty");
	}
	else {
		//val = _data[_front];
		if (_front == _top) {
			_front = -1;
			_top = -1;
		}
		else {
			_front = (_front + 1) % _size;
		}
	}
}

template<class T>
inline T Queue<T>::top()
{
	if (isEmpty()) {
		throw std::logic_error("Queue is empty");
	}
	return _data[_top - 1];
}

template<class T>
inline T Queue<T>::front()
{
	if (isEmpty()) {
		throw std::logic_error("Queue is empty");
	}
	return _data[_front];
}

#endif  // LIB_QUEUE_QUEUE_H_
