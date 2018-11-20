//Brandon Steege
//Lab7-Bsteege1.h
//Lab 7
//Description: A comparison of the different kind of sort functions
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <functional>

//Buble Sort Function from rosettacode.org
template <typename RandomAccessIterator>
void bubble_sort(RandomAccessIterator begin, RandomAccessIterator end);

//Insertion Sort Functions from rosettacode.org
template <typename RandomAccessIterator, typename Predicate>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end,
	Predicate p);

template <typename RandomAccessIterator>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end);

//Selection Sort Function from rosettacode.org
template<typename ForwardIterator> void selection_sort(ForwardIterator begin,
	ForwardIterator end);

//<erge Sort Function from rosettacode.org
template<typename RandomAccessIterator, typename Order>
void mergesort(RandomAccessIterator first, RandomAccessIterator last, Order order);

template<typename RandomAccessIterator>
void mergesort(RandomAccessIterator first, RandomAccessIterator last);

//Quick Sort Function from rosettacode.org
template<typename RandomAccessIterator,
	typename Order>
	void quicksort(RandomAccessIterator first, RandomAccessIterator last, Order order);

template<typename RandomAccessIterator>
void quicksort(RandomAccessIterator first, RandomAccessIterator last);