#include <algorithm>
#include <iostream>
#include <iterator>
#include <functional>

template <typename RandomAccessIterator>
void bubble_sort(RandomAccessIterator begin, RandomAccessIterator end);


template <typename RandomAccessIterator, typename Predicate>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end,
	Predicate p);

template <typename RandomAccessIterator>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end);

template<typename ForwardIterator> void selection_sort(ForwardIterator begin,
	ForwardIterator end);


template<typename RandomAccessIterator, typename Order>
void mergesort(RandomAccessIterator first, RandomAccessIterator last, Order order);

template<typename RandomAccessIterator>
void mergesort(RandomAccessIterator first, RandomAccessIterator last);


template<typename RandomAccessIterator,
	typename Order>
	void quicksort(RandomAccessIterator first, RandomAccessIterator last, Order order);

template<typename RandomAccessIterator>
void quicksort(RandomAccessIterator first, RandomAccessIterator last);