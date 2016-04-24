#include<iostream>
#include"fileOp.h"
#include <vector>
#include <sstream>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace fileOp;
int main(int argc,char** argv){
	if(argc != 4){
		cout << "usage:./updateKeywords {sourcefile} {keywordsfile} {result.txt}" << endl;
		return -1;
	}
	myFile sourceFile(argv[1]);
	myFile keywordsFile(argv[2]);
	myFile resultFile(argv[3]);
	sourceFile.open("r");
	keywordsFile.open("r");
	resultFile.open("w");
	result
	map<string,string> kmap;
	string line;
	string word;
	string replaceWord;
	while(getline(keywordsFile(keywordsFile.fs,line),keywordsFile.fs)){
		istringstream readline(line);
		line >> word >> replaceWord; 
		kmap.insert(make_pair<string,string>(word,replaceWord));
	}
	while(getline(sourceFile.fs,line),sourceFile.fs){
		istringstream readline(line);
		while(readline >> word){
			map<string,string>::iterator it = kmap.find(word);
			if(it != kmap.end()){
				resultFile.fs << kmap[word];
			}else{
				resultFile.fs << word;
			}
		}
		resultFile.fs << "\n" << endl;
	}
	return 0;
}
