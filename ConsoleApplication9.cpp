// ConsoleApplication9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// vector::begin/end
#include <iostream>
#include <vector>
class test {
public:
	void passvector(std::vector<int> *myvector) {
		for (std::vector<int>::iterator it = (myvector->end()-1); it != (myvector->begin()); --it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		for (auto it = myvector->rbegin(); it != myvector->rend(); ++it)
		{
			std::cout << ' ' << *it;
			
		}
		std::cout << '\n';
	}
	void pushstringinvector(std::vector<char> *myvector, char *string) {
		char *ptr;
		ptr = string;
		while (*ptr != '\0') {
			myvector->push_back(*ptr);
			ptr++;
		}
	}
	void displaystringvector(std::vector<char> *myvector) {
		for (auto it = myvector->begin(); it != myvector->end(); ++it)
		{
			std::cout  << *it;

		}
		std::cout << '\n';
		
	}
	void displayreversestringvector(std::vector<char> *myvector) {
		for (auto it = myvector->rbegin(); it != myvector->rend(); ++it)
		{
			std::cout << *it;

		}
		std::cout << '\n';
	}
};

class TwoSum
{
public:
	static std::pair<int, int> findTwoSum(const std::vector<int>& list, int sum)
	{
		for (auto it = list.begin(); it != list.end(); ++it)
		{
			for (auto jt = list.begin(); jt != list.end(); ++jt) {
				if ((*it + *jt) == sum) {
					std::pair <int, int> foo;
					//return foo.make_pair((int)*it, (int)*jt);
					int x = *it;
					int y = *jt;
					return std::make_pair(x, y);
				}
			}

		}
		throw std::logic_error("Waiting to be implemented");
	}
};
int main()
{
	std::vector<int> myvector;
	for (int i = 1; i <= 5; i++) myvector.push_back(i);

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	test testvec;
	testvec.passvector(&myvector);

	std::vector<char> mycharvector;
	testvec.pushstringinvector(&mycharvector, "this is a test");
	testvec.displaystringvector(&mycharvector);
	testvec.displayreversestringvector(&mycharvector);


	std::vector<int> list;
	list.push_back(1);
	list.push_back(3);
	list.push_back(5);
	list.push_back(7);
	list.push_back(9);

	std::pair<int, int> indices = TwoSum::findTwoSum(list, 12);
	std::cout << indices.first << '\n' << indices.second;
	std::cout << '\n';
	return 0;
}

