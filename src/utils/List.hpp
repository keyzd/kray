/*
	Dynamic array class aka List
*/

#pragma once

template <class T>
class List {
public:
	List();
	List( T initValue );
	List( const List& list );
	~List();

	unsigned int Count() const;
	unsigned int Capacity() const;
	void Push(T item);
	void Clear();
	void ResetCount();

	T& operator[] ( unsigned int index );
	T operator[] ( unsigned int index ) const;

private:
	T *buf;
	unsigned int count;
	unsigned int capacity;
};

template <class T>
inline unsigned int List<T>::Count() const {
	return count;
}

template <class T>
unsigned int List<T>::Capacity() const {
	return capacity;
}

template <class T>
void List<T>::Clear() {
	delete [] buf;
	buf = new T[ 8 ];
	capacity = 8;
	count = 0;
}

template <class T>
void List<T>::ResetCount() {
	count = 0;
}

template <class T>
T& List<T>::operator[]( unsigned int index ) {
	return buf[ index ];
}

template <class T>
T List<T>::operator[]( unsigned int index ) const {
	return buf[ index ];
}

template <class T>
List<T>::List() {
	count = 0;
	capacity = 8;
	buf = new T[ 8 ];
}

template <class T>
List<T>::List( const List &list ) {
	capacity = list.capacity;
	count = list.count;
	buf = new T[ list.capacity ];
	for( unsigned int i = 0; i < list.capacity; i++ ) {
		buf[ i ] = list.buf[ i ];
	}
}

template <class T>
List<T>::List( T initValue ) {
	count = 0;
	capacity = 8;
	buf = new T[ 8 ];
	for( unsigned int i = 0; i < capacity; i++ ) {
		buf[ i ] = initValue;
	}
}

template <class T>
List<T>::~List() {
	delete [] buf;
}

template <class T>
void List<T>::Push( T item ) {
	if( count == capacity - 1 ) {
		capacity *= 2;
		T *buf_tmp = new T[ capacity ];
		for( unsigned int i = 0; i < count; i++ ) {
			buf_tmp[ i ] = buf[ i ];
		}
		delete [] buf;
		buf = buf_tmp;
	}
	buf[ count ] = item;
	count++;
}

