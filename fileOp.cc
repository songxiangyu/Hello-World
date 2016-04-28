#include "fileOp.h"
using namespace std;
using namespace fileOp;

myFile::myFile(const string& fileName,const string& filePath){   
	if(filePath[filePath.size()-1] != '/') 
		fileFullName = filePath + '/' + fileName;
	else
		fileFullName = filePath + fileName;
}
/*open file*/
fstream& myFile::openFile(const string& opType){
	if(opType == "r"){
		fs.open(fileFullName.c_str(),fstream::in);
		fs.seekg(fstream::beg);   // 
	}
	else if(opType == "w"){
		fs.open(fileFullName.c_str(),fstream::out|fstream::app);
	}
	else {
		fs.open(fileFullName.c_str(),fstream::in|fstream::out|fstream::app);
		fs.seekg(fstream::beg);
	}
	return fs;
}
/*close file*/
void myFile::closeFile(){
	fs.close();
	isClose = true;
}
