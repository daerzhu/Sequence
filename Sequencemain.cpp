#include"Sequence.h"
using namespace std;

int main()

{

	Sequence s("dna.txt");

	cout << s.length() << endl;

	cout << s.numberOf('A') << endl;

	cout << s.numberOf('G') << endl;

	cout << s.numberOf('C') << endl;

	cout << s.numberOf('T') << endl;

	cout << s.longestConsecutive() << endl;

	cout << s.longestRepeated() << endl;

}

