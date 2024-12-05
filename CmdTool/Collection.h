#ifndef Collection_h
#define Collection_h

#include <iostream>

class Command;

template<typename T>
class Collection
{
	//forward declaration
	struct CollectionElement;
public:
	Collection() : head(nullptr), tail(nullptr), size(0) { };
		
	~Collection();

	//adds an element at the end
	void add(T val);

	void print();

	size_t getSize() { return size; }

	//alows a consumer to process each element of a collection while isolating the internal collection structure
	class Iterator {
	private:
		CollectionElement* current;
	public:
		Iterator(CollectionElement* start) : current(start) {};
		bool hasNext() { return current != nullptr; }
		T& next();
	};

	Iterator getIterator() { return Iterator(head); }
private:
	struct CollectionElement {
		T value;
		CollectionElement* next;
		
		CollectionElement(T& val) : value(val), next(nullptr) {};
	};

	CollectionElement* head;
	CollectionElement* tail;
	size_t size;


};

template<typename T>
Collection<T>::~Collection() {
	while (head) {
		CollectionElement* temp = head;
		head = head->next;
		delete temp;
	}
}

template<typename T>
void Collection<T>::add(T val) {
	CollectionElement* newElement = new CollectionElement(val);
	if (!head) {
		head = newElement;
	}
	else {
		tail->next = newElement;
	}
	tail = newElement;
	++size;
}

template<typename T>
void Collection<T>::print()
{
	CollectionElement* current = head;
	while (current) {
		std::cout << current->value << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

template<typename T>
T& Collection<T>::Iterator::next() {
	T& data = current->value;
	current = current->next;
	return data;
}
#endif

