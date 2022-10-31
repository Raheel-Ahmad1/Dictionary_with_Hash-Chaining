#include <iostream>
#include <fstream>
#include<string>
#include <string.h>
#include "hashing.h"
using namespace std;


int main()
{
	string fileLine = "";
	
	int sizeofdisc = 0;
	ifstream infile;
	element *e = new element[36700];
	HashChain h(6997);
	
	cout << "Reading and loading data into hash table...." << endl;
	infile.open("dictionary.txt");
	if (!infile.is_open())
	{
		cout << "File not opened\n";
	}
	else
	{
		
		char x;
		while (!infile.eof())
		{
			infile.get(x);
			fileLine = fileLine + x;
			if (x == '\n')
			{
				if (fileLine.size() > 8){
					int ii = 0,chk=0;
					string temp = "";
					while (fileLine[ii] != ' '){
						temp = temp + fileLine[ii];
						ii++;
					}
					if (fileLine[ii+1] != ' '){
						
						ii++;
						temp=temp+" ";
						
						while (fileLine[ii] != ' '){
							temp = temp + fileLine[ii];
							ii++;
						}
						
						
					}
					
					e[sizeofdisc].word += temp;
					while (fileLine[ii] == ' ')ii++;

					while (fileLine[ii] != '\n'){

						e[sizeofdisc].details += fileLine[ii];
						ii++;
					}
					
					h.insertItem(e[sizeofdisc]);
					cout << "Inserted " << e[sizeofdisc].word << "  at " << h.myhashFunction(e[sizeofdisc].word)<<endl;
										
					sizeofdisc++;
				}
				fileLine = "";
			}
			
		
		}
		infile.close();
	}
	cout << sizeofdisc << " Records loaded into the hashtable:" << endl;
	cout << endl;
	
		
	
	cout << "Enter the word you want to search from Hash Table" << endl;
	char word[50];
	cin.getline(word,50);
	h.SearchItem(word);

	return 0;
}
