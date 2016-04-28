#include<iostream>
#include"fileOp.h"
#include <vector>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <string>
using namespace std;
using namespace fileOp;
int main(int argc,char** argv){
	if(argc != 4){
		cout << "usage:./updateKeywords {sourcefile} {keywordsfile} {result.txt}" << endl;
		return -1;
	}
	myFile sourceFile(argv[1],"./");
	myFile keywordsFile(argv[2],"./");
	myFile resultFile(argv[3],"./");
	fstream &sf = sourceFile.openFile(string("r"));
	fstream &kf = keywordsFile.openFile(string("r"));
	fstream &rf = resultFile.openFile(string("w"));
	map<string,string>  kmap; //read keywordsfile to the map 
	string line;
	string word;
	string replaceWord;
	/*read from keywordsfile and insert into map*/
	while(getline(kf,line)){ 
		istringstream readline(line);
		readline >> word >> replaceWord; 
		kmap.insert(make_pair<string,string>(word,replaceWord));
	}
	while(getline(sf,line),sf){
		istringstream readline(line);
		//for every word from sourcefile, compare with the map.key
		while(readline >> word){  
			map<string,string>::iterator it = kmap.find(word);//if found, replece it 
			if(it != kmap.end()){
				rf << kmap[word];
			}else{
				rf << word;  //else, write it to the resultFile
			}
		}
		rf << "\n" << endl;
	}
	return 0;
}
