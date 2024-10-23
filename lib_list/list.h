// Copyright 2024 Matvey Demidovich

#ifndef LIB_LIST_H_
#define LIB_LIST_H_

#include <stdexcept>
//Реализация узла
template<class T>
struct Node {
    T val;
    Node<T>* next;

    Node(T _val) : val(_val), next(nullptr) {}
};
//Реализация списка
template<class T>
class List {
    Node<T>* _first;
    Node<T>* _last;

public:
    List();
    ~List();
    bool is_empty() noexcept; /*Функция проверки наличия узлов в списке*/
    void push_back(const T& _val) noexcept; /*Функция добавления элемента в конец списка*/
    void push_front(const T& _val) noexcept; /*Функция добавления элемента в начало списка*/
    void insert(int pos, const T& _val) noexcept;
    Node<T>* find(const T& _val); /*Функция поиска узла в списке по заданному значению*/
    void remove_first() noexcept; /*Функция удаления первого узла*/
    void remove_last() noexcept; /*Функция удаления последнего узла*/
    void remove(T _val) noexcept; /*Функция удаления узла по заданному значению*/
    Node<T>* operator[](const int index);
};

template<class T>
List<T>::List() {
    _first = nullptr;
    _last = nullptr;
}

template<class T>
bool List<T>::is_empty() noexcept {
    return _first == nullptr;
}
template<class T>
List<T>::~List() {
    _first = nullptr;
    _last = nullptr;
}
template<class T>
void List<T>::push_back(const T& _val) noexcept {
    Node<T>* p = new Node<T>(_val);
    if (is_empty()) {
        _first = p;
        _last = p;
        return;
    }
    _last->next = p;
    _last = p;
}
template<class T>
void List<T>::push_front(const T& _val) noexcept{
    Node<T>* p = new Node<T>(_val);
    if (is_empty()) {
        _first = p;
        _last = p;
        return;
    }
    p->next = _first;
    _first = p;
}

template<class T>
void List<T>::insert(int pos, const T& _val) noexcept {
    Node<T>* p = new Node<T>(_val);
    if (is_empty()) {
        _first = p;
        _last = p;
        return;
    }
    Node<T>* nextnode = _first;
    for (int i = 0; i != pos;) {
       nextnode = nextnode->next;
       i++;
    }
    if (nextnode == nullptr) {
        _last->next = p;
        p = _last;
    }
    else {
        p->next = nextnode->next;
        nextnode->next = p;
    }
    
}
template<class T>
Node<T>* List<T>::find(const T& _val) {
    Node<T>* p = _first;
    while (p && p->val != _val) p = p->next;
    return (p && p->val == _val) ? p : nullptr;
}
template<class T>
void  List<T>::remove_first() noexcept {
    if (is_empty()) return;
    Node<T>* p = _first;
    _first = p->next;
    delete p;
}
template<class T>
void  List<T>::remove_last() noexcept {
    if (is_empty()) return;
    if (_first == _last) {
        remove_first();
        return;
    }
    Node<T>* p = _first;
    while (p->next != _last) p = p->next;
    p->next = nullptr;
    delete _last;
    _last = p;
}
template<class T>
void  List<T>::remove(T _val) noexcept {
    if (is_empty()) return;
    if (_first->val == _val) {
        remove_first();
        return;
    }
    else if (_last->val == _val) {
        remove_last();
        return;
    }
    Node<T>* slow = _first;
    Node<T>* fast = _first->next;
    while (fast && fast->val != _val) {
        fast = fast->next;
        slow = slow->next;
    }
    if (!fast) {
        throw std::logic_error("This element does not exist");
    }
    slow->next = fast->next;
    delete fast;
}

template<class T>
Node<T>* List<T>::operator[] (const int index) {
    if (is_empty()) return nullptr;
    Node<T>* p = _first;
    for (int i = 0; i < index; i++) {
        p = p->next;
        if (!p) return nullptr;
    }
    return p;
}

#endif LIB_LIST_LIST_H_
