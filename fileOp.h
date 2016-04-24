/*************************************************************************
	> File Name: fileOp.h
	> Author: songxiangyu
	> Mail: songxiangyu131@163.com
	> Created Time: Sun 24 Apr 2016 09:37:36 AM PDT
 ************************************************************************/
#ifndef FILE_OP_H
#define FILE_OP_H
#include<iostream>
#include<vector>
#include <string>
using namespace std;
namespace fileOp{
	class myFile{
		public:
			myFile(const string& fileName,const string& filePath=".\");
			virtual ~myFile();
			void openFile();
			void closeFile();
		private:
			fstream fs;
			string fileFullName;
			bool isClose;
	};
}
#endif 
