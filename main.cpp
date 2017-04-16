#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<string> readFile(string filename)
{
	vector<string> data;
	string d;
	fstream file(filename, ios::in);
	//assert(file.is_open());
	while(file)
	{
		file>>d;
		data.push_back(d);
		//cout<<d<<endl;
	}
	file.close();
	return data;
}
bool isMatch(const string &word, string tiles, bool withWildcard)
{
	if(word.size() > tiles.size()) return false;
	if(word.size()==0 || tiles.size()==0) return false;
	bool found=false;
	for(auto& c : word)
	{
		found=false;
		for(string::iterator itr=tiles.begin(); itr!=tiles.end(); itr++)
		{
			if(c==*itr)
			{
				*itr=1;
				found=true;
			}
			if(withWildcard)
			{
				if(*itr==' ')
				{
					*itr=1;
					found=true;
				}
			}
			
		}
		if(!found) return false;
	}
	return true;
	
}
int main(int argc, char** argv)
{
	
	string withW=argv[1];
	string tiles=argv[2];
	
	bool withWildcard=false;
	if(withW=="-w") withWildcard=true;
	
	auto dictionary=readFile("dictionary.txt");
	cout<<dictionary.size()<<endl;
	// looping the dictionary
	for(auto word : dictionary)
	{
		// copy a new tile string
		if(isMatch(word, tiles, withWildcard))
		{
			// This is one way to output the result
			cout<<word<<endl;
		}
	}
	return 0;
}