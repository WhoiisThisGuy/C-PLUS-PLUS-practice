//Erastothenes sieve
#include <iostream>
#include <list>

using namespace std;

void erastothenesSieve(const int until) {

	list<int> lsieve(until-1); //until-1: 0 and 1 is not counting but the number "until" itself does
	{
		int temp = 2;
		for (auto it = lsieve.begin(); it != lsieve.end(); ++it, ++temp) {

			lsieve.insert(it,temp);
		}
	}

	for (auto it_tempExamine = lsieve.begin(); it_tempExamine != lsieve.end();++it_tempExamine) { //O(n)
		for (auto it_PossibMultiple = std::next(it_tempExamine); it_PossibMultiple != lsieve.end();) { //O(n)
			if ((*it_PossibMultiple) % (*it_tempExamine) == 0)
				it_PossibMultiple = lsieve.erase(it_PossibMultiple);
			else
				++it_PossibMultiple;
		}
	}
	cout << "The primes between 0 - " << until <<"are:\n";
	for (auto& e : lsieve) {
		cout << e << " ";
	}
}

int main()
{
	erastothenesSieve(200);
}