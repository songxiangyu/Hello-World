#include <string>
#include <iostream>
#include "list.h"
#include <algorithm>
using namespace std;
int main(){
	int firstLength = 0;
	int secondLength = 0;
	int data = 0;
	int index = 0;
	cout << "Input the size of the first list(size > 0):";
	cin >> firstLength;
	int* firstBuf = new int[firstLength]();
	cout << "Input the data of the first list:";
	while(index < firstLength){
		cin >> data;
		firstBuf[index++] = data;
	}
	cout << "Input the size of the second list(size > 0):";
	cin >> secondLength;
	int* secondBuf = new int[secondLength]();
	cout << "Input the data of the second list:";
	index = 0;
	while(index < secondLength){
		cin >> data;
		secondBuf[index++] = data;
	}
	list first(firstBuf,firstLength);
	list second(secondBuf,secondLength);
	while(1){
		cout << "1--->show the first  list" << endl;
		cout << "2--->show the second list" << endl;
		cout << "3--->merge two lists and show result" << endl;
		cout << "4--->merge two lists and sort" << endl;
		cout << "5--->quit" << endl;
		int cmd = 0;
		cout << "Input cmd:";
		cin >> cmd;
		if(1 == cmd){
			cout << first << endl;
		}
		else if(2 == cmd){
			cout << second << endl;
		}
		else if(3 == cmd){
			list target = list::merge(first,second);
			cout << target << endl;
		}else if(4 == cmd){
			list target = list::merge(first,second);
			target.sort();
			cout << target << endl;
		}else if(5 == cmd){
			break;
		}
		else{
			cout << "unknown cmd" << endl;
		}
	}
	return 0;
}
