//Brandon Steege
//Lab7-Bsteege1.cpp
//Lab 7
//Description: A comparison of the different kind of sort functions
//

#include "winTimer.h"
#include "ContainterPrinting.h" //Included from lab 6 to allow << of lists
#include "Lab7-Bsteege1.h"
#include <iostream>
#include <vector>


using namespace std;

///////////////////////////////////////////////////////// FROM LAB 6 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

double randUniform()
{
	double r = double(rand()) / (RAND_MAX + 1.0);
	r = (double(rand()) + r) / (RAND_MAX + 1.0);
	r = (double(rand()) + r) / (RAND_MAX + 1.0);
	r = (double(rand()) + r) / (RAND_MAX + 1.0);
	return  r;
};

double randReal(double minReal, double maxReal)
{
	return minReal
		+ (maxReal - minReal) * randUniform();
}

vector<double>
getNums(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}

	//sort(begin(theList), end(theList));

	return theList;
}
//////////////////////////////////////////// Declaring Lab7-Bsteege.h Functions \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//All functions from rosettacode.org
template <typename RandomAccessIterator>
void bubble_sort(RandomAccessIterator begin, RandomAccessIterator end)
{
	bool swapped = true;
	while (begin != end-- && swapped) {
		swapped = false;
		for (auto i = begin; i != end; ++i) {
			if (*(i + 1) < *i) {
				std::iter_swap(i, i + 1);
				swapped = true;
			}
		}
	}
}

template <typename RandomAccessIterator, typename Predicate>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end,
	Predicate p) {
	for (auto i = begin; i != end; ++i) {
		std::rotate(std::upper_bound(begin, i, *i, p), i, i + 1);
	}
}

template <typename RandomAccessIterator>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end) {
	insertion_sort(
		begin, end,
		std::less<
		typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

template<typename ForwardIterator> void selection_sort(ForwardIterator begin,
	ForwardIterator end) {
	for (auto i = begin; i != end; ++i) {
		std::iter_swap(i, std::min_element(i, end));
	}
}

template<typename RandomAccessIterator, typename Order>
void mergesort(RandomAccessIterator first, RandomAccessIterator last, Order order)
{
	if (last - first > 1)
	{
		RandomAccessIterator middle = first + (last - first) / 2;
		mergesort(first, middle, order);
		mergesort(middle, last, order);
		std::inplace_merge(first, middle, last, order);
	}
}

template<typename RandomAccessIterator>
void mergesort(RandomAccessIterator first, RandomAccessIterator last)
{
	mergesort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

template<typename RandomAccessIterator,
	typename Order>
	void quicksort(RandomAccessIterator first, RandomAccessIterator last, Order order)
{
	if (last - first > 1)
	{
		RandomAccessIterator split = std::partition(first + 1, last, std::bind2nd(order, *first));
		std::iter_swap(first, split - 1);
		quicksort(first, split - 1, order);
		quicksort(split, last, order);
	}
}

template<typename RandomAccessIterator>
void quicksort(RandomAccessIterator first, RandomAccessIterator last)
{
	quicksort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

int main()
{
	cout << "Find the most isolated number" << endl
		<< "-----------------------------" << endl << endl;
	while (true)
	{
		cout << "Enter size for numbers: ";
		int n = 0;
		cin >> n;
		if (n <= 0)
			break;
		cout << "Enter seed for rand: ";
		unsigned int seed;
		cin >> seed;
		srand(seed);

		// Construct a sorted list of numbers
		Timer get;
		get.start();
		vector<double> numbers = getNums(n, -n, n);
		get.stop();
		cout << "Constructed in " << get() << " seconds"
			<< endl;

		if (n < 10)
			cout << numbers << endl << endl;

		// Report a most isolated isolated number
		Timer time;
		time.start();
		//sort(begin(numbers), end(numbers));
		//bubble_sort(numbers.begin(), numbers.end());
		//insertion_sort(numbers.begin(), numbers.end());
		//selection_sort(numbers.begin(), numbers.end());
		//mergesort(numbers.begin(), numbers.end());
		quicksort(numbers.begin(), numbers.end());
		time.stop();
		cout << "The sorted List is: "
			//<< numbers 
			<< endl
			<< "calculated in " << time() << " seconds"
			<< endl << endl;
	}
	return 0;
}