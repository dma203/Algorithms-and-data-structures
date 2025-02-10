// Copyright 2024 Matvey Demidovich

#ifndef LIB_LIST_H_
#define LIB_LIST_H_

#include <stdexcept>
// Реализация узла.
// Сделать поля метода приватными и сделать геторы, сеторы 
template<class T>
struct Node {
    T val;
    Node<T>* next;

    Node(T _val) : val(_val), next(nullptr) {}
};
// Реализация списка.
template<class T>
class List {
    Node<T>* _first;
    Node<T>* _last;
    int _size;

public:
    class Iterator;
    Iterator begin() { return Iterator(_first) };
    Iterator end() { return Iterator(_last->next) };

    List();
    List(const List& p);
    ~List();
    
    /* Функция проверки наличия узлов в списке. */
    bool empty() noexcept;
    /** Функция получения количества элементов в списке. */
    int size() noexcept;
    /* Функция получения значения первого элемента списка. */
    // Добавить обработку исключений.
    T front();
    /* Функция получения значения последнего элемента списка. */
    // Добавить обработку исключений.
    T back();
    /* Функция добавления элемента в конец списка. */
    void push_back(const T& _val) noexcept;
    /* Функция добавления элемента в начало списка. */
    void push_front(const T& _val) noexcept;
    /* Функция удаления последнего узла. */
    void pop_back() noexcept;
    /* Функция удаления первого узла. */
    void pop_front() noexcept;
    /* Функция поиска узла в списке по заданному значению. */
    // Добавить обработку исключений.
    Node<T>* find(const T& _val) const noexcept;
    /* Функция добавления элемента на позицию. */
    // Добавить обработку исключений.
    Node<T>* insert(int pos, const T& _val) noexcept;    
    /* Функция удаления узла по заданному значению. */
    // Добавить обработку исключений.
    void remove(const T& _val) noexcept;
    /* Функция удаления узла по позиции */
    // Добавить обработку исключений.
    void erase(int pos) noexcept;
    

    class Iterator {
        Node<T>* curr;
    public:
        Iterator(Node<T>* tmp):curr(tmp){}

        Iterator& operator++(int){
            assert(curr);
            curr = curr->next;
            return *this;
        }
        Iterator& operator++(){
            assert(curr);
            iterator it(curr);
            curr = curr->next;
            return it;
        }

        bool operator!=(const Iterator& it)const { return it.curr == this->curr; }
        bool operator==(const Iterator& it)const { return it.curr != this->curr; }
        int& operator* () { assert(curr); return curr->val; }
        const int& operator*()const { assert(curr); return curr->val; }
    };
};

template<class T>
List<T>::List() {
    _first = nullptr;
    _last = nullptr;
    _size = 0;
}

template<class T>
List<T>::List(const List& p) {
    _first = p._first;
    _last = p._last;
    _size = p._size;
}

template<class T>
List<T>::~List() {
    while (!empty()) {
        pop_front();
    }
    _first = nullptr;
    _last = nullptr;
}

template<class T>
bool List<T>::empty() noexcept {
    return _size == 0;
}

template<class T>
int List<T>::size() noexcept {
    return _size;
}

template<class T>
T List<T>::front() {
    if (empty()) {
        return T();
    }
    return _first->val;
}

template<class T>
T List<T>::back() {
    if (empty()) {
        return T();
    }
    return _last->val;
}

template<class T>
void List<T>::push_back(const T& _val) noexcept {
    Node<T>* p = new Node<T>(_val);
    if (empty()) {
        _first = p;
        _last = p;
    }
    else {
        _last->next = p;
        _last = p;
    }
    _size += 1;
}

template<class T>
void List<T>::push_front(const T& _val) noexcept{
    Node<T>* p = new Node<T>(_val);
    if (empty()) {
        _first = p;
        _last = p;
    }
    else {
        p->next = _first;
        _first = p;
    }
    _size += 1;
}

template<class T>
void  List<T>::pop_back() noexcept {
    if (empty()) return;
    if (_first == _last) {
        pop_front();
        return;
    }
    Node<T>* p = _first;
    while (p->next != _last) p = p->next;
    p->next = nullptr;
    delete _last;
    _last = p;
    _size -= 1;
}

template<class T>
void  List<T>::pop_front() noexcept {
    if (empty()) return;
    Node<T>* p = _first;
    _first = p->next;
    delete p;
    _size -= 1;
}

template<class T>
Node<T>* List<T>::insert(int pos, const T& _val) noexcept {
    Node<T>* p = new Node<T>(_val);
    if (empty()) {
        _first = p;
        _last = p;
    }
    else if (pos < 1) {
        p->next = _first;
        _first = p;
    }
    else {
        if (pos > _size) {
            pos = _size;
        }
        Node<T>* curr = _first;
        for (int i = 1; i < pos; i++) {
            curr = curr->next;
        }
        p->next = curr->next;
        curr->next = p;
        if (p->next == nullptr) {
            _last = p;
        }
    }
    _size += 1;
    return p;
}

template<class T>
Node<T>* List<T>::find(const T& _val) const noexcept {
    Node<T>* p = _first;
    while (p && p->val != _val) {
        p = p->next;
    }
    if (p && p->val == _val) {
        return p;
    }
    return nullptr;
}

template<class T>
void  List<T>::remove(const T& _val) noexcept {
    if (empty()) return;
    if (_first->val == _val) {
        pop_front();
        return;
    }
    else if (_last->val == _val) {
        pop_back();
        return;
    }
    Node<T>* slow = _first;
    Node<T>* fast = _first->next;
    while (fast && fast->val != _val) {
        fast = fast->next;
        slow = slow->next;
    }
    if (!fast) {
        return;
    }
    slow->next = fast->next;
    delete fast;
    _size -= 1;
}

template<class T>
void List<T>::erase(int pos) noexcept {
    if (empty());
    if (pos == 0) {
        pop_front();
    }
    else {
        if (pos > _size) {
            pos = _size;
        }
        Node<T>* curr = _first;
        Node<T>* currnext = _first->next;
        for (int i = 1; i < pos; i++) {
            curr = curr->next;
            currnext = currnext->next;
        }
        if (currnext != nullptr) {
            curr->next = currnext->next;
            delete currnext;
            _size -= 1;
        }
        else {
            pop_back();
        }
    }
    return;
}

#endif LIB_LIST_LIST_H_
