/*************************************************************************
	> File Name: list.h
	> Author: songxiangyu
	> Mail: songxiangyu@xiaomi.com 
	> Created Time: Tue 17 May 2016 07:02:35 PM CST
 ************************************************************************/
#ifndef LIST_H
#define LIST_H
#include<iostream>
#include<algorithm>
using namespace std;
/**
 *双向链表的节点数据结构
 */
struct listNode{
	 int value;
	 struct listNode* pNext;   //下一个元素
	 struct  listNode* pPre;   //上一个元素
};

class list{
	private:
		listNode* pHead;   //链表头指针
		int listLength;    //链表长度，即链表元素个数
	public:
        virtual ~list(){
            deleteList();
        }
		list(int* buf,int length);   //数组初始化链表对象
		list(const listNode* pList,int length);  //链表对象构造函数
		void sort();     //直接插入排序
		void deleteList();   //显式删除链表
		list(const list& other);   //拷贝构造函数
		list operator=(const list& other);   //赋值操作符
    /*
    * 输出一个链表对象
    * */
        friend inline ostream& operator<<(ostream& os,list& other) {
            listNode* head = other.getHead();
            if(head != NULL) {   //链表为空，返回
                while (head) {   //正向循环输出链表节点值
                    os << head->value << " ";
                    head = head->pNext;
                }
            }
            return os;
        }
		static list merge(const list& first,const list& second);  //合并两个链表
		/*获取头指针和链表长度*/
		listNode* getHead(){
			return pHead;
		}
		int size(){
			return listLength;
		}
};
#endif
