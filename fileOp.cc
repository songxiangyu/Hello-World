#include "fileOp.h"
using namespace std;
using namespace fileOp;

myFile::myFile(const string& fileName, const string& filePath){
	if(filePath.back() != '/')
		fileFullName = filePath + '/' + fileName;
	else
		fileFullName = filePath + fileName;
}
/*open file*/
myFile::openFile(const string& opType){
	bool stat = true;
	if(opType == "r"){
		fs.open(fileFullName.c_str(),fstream::in);
		fs.seekg(fstream::beg);
		if(!fs)
			stat = false;
	}
	else if(opType == "w"){
		fs.open(fileFullName.c_str(),fstream::out|fstream::app);
		if(!fs)
			stat = false;
	}
	else {
		fs.open(fileFullname.c_str(),fstream::in|fstream::out);
		fs.seekg(fstream::beg);
		if(!fs)
			stat = false;
	}
	if(stat == false){
		cout << "open file failed" << end;
		return -1;
	}
}
/*close file*/
void myFile::closeFile(){
	fs.close();
	isClose = true;
}
myFile::~myFile(){
	if(!isClose){
		fs.close();
	}
}
