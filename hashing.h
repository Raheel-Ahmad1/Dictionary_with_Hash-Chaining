// CPP program to implement hashing with chaining 
//#include<iostream> 
#include <string>
#include <cmath>
#include <list> 

using namespace std;


struct element
{
	string word;
	string details;

};
class HashChain
{
private:
	int size;
	list<element> *table;
public:
	HashChain(int V) // Constructor 
	{
		this->size = V;
		table = new list<element>[size];
	}
	// inserts a key into hash table 
	void insertItem(element key)
	{
		int index = myhashFunction(key.word);
		table[index].push_back(key);
	}
	
	void SearchItem(string word)
	{
			
		int i = myhashFunction(word);
		list<element>::iterator it;
		int chk1=0;
		for ( it=table[i].begin(); it!=table[i].end();it++)
		{
				if (word == (*it).word){
						cout << (*it).word << endl << (*it).details << endl;
						chk1++;
				}
		}
		if (!chk1){
			cout<<"Word not found !!!";
		}
		
	}

	// hash function to map values to key 
	int myhashFunction(string word) {
		float hashind = 0.0, sum = 0.0;
		int j = 0;
		while (j < word.length()/2)
		{
			sum += (int) word[j];
			hashind += (float)((int)word[j])*pow(11,j);
			j++;
		}
		int indexofkey = (((int)fmodf(hashind, sum)*word.length()) % (int)size);
		return indexofkey;
	}

};

