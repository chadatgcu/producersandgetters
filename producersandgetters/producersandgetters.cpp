// producersandgetters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <pthread.h>

using namespace std;
int theProduct;
vector<int> Consumer;

int main()
{
    std::cout << "Starting!\n"; 
}

void producer() {
	int i;
	while (1) {
		i = produce();
		put(i);
	}
}

void consumer() {
	int i;
	while (1) {
		i = get();
		consume(i);
	}
}

void put(int i) {
	Consumer.push_back(i);
}

int get() {
	return Consumer.pop_back();
}

int produce() {
	return theProduct++;
}

void consume(int i) {
	std::cout << i << "\n";
}

