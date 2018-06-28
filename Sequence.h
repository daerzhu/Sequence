

#ifndef SEQUENCE_H
#define SEQUENCE_H 

#include<iostream>

#include <string>

using namespace std;

class Sequence

{

public:

	Sequence(char*);

	int length();

	int numberOf(char);

	string longestConsecutive();

	string longestRepeated();

private:

	string s;

	long long a, g, c, t, count;



};
#endif



























































