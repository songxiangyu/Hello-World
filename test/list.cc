#include <iostream>
#include <algorithm>
#include "list.h"

/*
 * 用数组构造一个list对象
 * */
list::list(int* buf,int length){
	if(buf == NULL||length <= 0){
		cout << "invalid paramsters" << endl;
		exit(-1);
	}
	int index = 0;
    listNode* pCurrent = NULL;
    listNode* pPre = NULL;
	for(;index < length;index++) {
        if (pCurrent == NULL) {
            pCurrent = new listNode;
            pCurrent->pPre = NULL;
            pCurrent->pNext = NULL;
            pHead = pCurrent;
        } else {
            pCurrent->pNext = new listNode;
            pPre = pCurrent;
            pCurrent = pCurrent->pNext;
            pCurrent->pPre = pPre;
        }
        pCurrent->value = buf[index];
    }
    listLength = length;
}
/*
 * 原生链表初始化链表对象
 * */
list::list(const listNode* pList,int length){
	if(pList == NULL||length <= 0){
		cout << "invaild paramsters" << endl;
		exit(-1);
	}
    int index = 0;
    listNode* pCurrent = NULL;
    listNode* pPre = NULL;
    for(;index < length;index++) {
        if (pCurrent == NULL) {
            pCurrent = new listNode;
            pCurrent->pPre = NULL;
            pCurrent->pNext = NULL;
            pHead = pCurrent;
        } else {
            pCurrent->pNext = new listNode;
            pPre = pCurrent;
            pCurrent = pCurrent->pNext;
            pCurrent->pPre = pPre;
        }
        pCurrent->value = pList->value;
        pList = pList->pNext;
    }
    listLength = length;
}
/*
 * copy构造函数
 * */
list::list(const list &other) {
    int length = other.listLength;
    int index = 0;
    listNode* otherHead = other.pHead;
    listNode* pCurrent = NULL;
    listNode* pPre = NULL;
    for(;index < length;index++) {
        if (pCurrent == NULL) {
            pCurrent = new listNode;
            pCurrent->pPre = NULL;
            pCurrent->pNext = NULL;
            pHead = pCurrent;
        } else {
            pCurrent->pNext = new listNode;
            pPre = pCurrent;
            pCurrent = pCurrent->pNext;
            pCurrent->pPre = pPre;
        }
        pCurrent->value = otherHead->value;
        otherHead = otherHead->pNext;
    }
    listLength = length;
}
/*
 * operator=
 * */
list list::operator=(const list &other) {
    if (this == &other){     //other和*this指向同一个对象
        return *this;
    }
   (*this).deleteList();  //释放原来的链表对象空间
    int length = other.listLength;
    int index = 0;
    listNode* otherHead = other.pHead;
    listNode* pCurrent = NULL;
    listNode* pPre = NULL;
    for(;index < length;index++) {
        if (pCurrent == NULL) {
            pCurrent = new listNode;
            pCurrent->pPre = NULL;
            pCurrent->pNext = NULL;
            pHead = pCurrent;
        } else {
            pCurrent->pNext = new listNode;
            pPre = pCurrent;
            pCurrent = pCurrent->pNext;
            pCurrent->pPre = pPre;
        }
        pCurrent->value = otherHead->value;
        pCurrent = otherHead->pNext;
    }
    listLength = length;
    return *this;
}

/*以一定规则合并两个链表
 * 非破坏性合并
 * */

list list::merge(const list& first,const list& second) {
    listNode *pShorter = NULL;
    listNode *pLonger = NULL;
    int firstLength = first.listLength;
    int secondLength = second.listLength;
    int shorter = 0;
    int longer = 0;
    int totalLength = firstLength + secondLength;
    if (firstLength >= secondLength){
        longer = firstLength;
        pLonger = first.pHead;
        shorter = secondLength;
        pShorter = second.pHead;
    }else{
        longer = secondLength;
        pLonger = second.pHead;
        shorter = firstLength;
        pShorter = first.pHead;
    }
    listNode *pTarget =  NULL;
    listNode *pCurrent = NULL;
    listNode *pPre = NULL;
    int index = 0;
    while (index++ < shorter && pShorter && pLonger) {
        if (pCurrent == NULL) {
            pCurrent = new listNode;
            pTarget = pCurrent;
            pCurrent->value = pLonger->value;
        } else {
            pCurrent->pNext = new listNode;
            pCurrent->pNext->value = pLonger->value;
            pCurrent = pCurrent->pNext;
        }
        pCurrent->pPre = pPre;
        pPre = pCurrent;
        pCurrent->pNext = new listNode;
        pCurrent->pNext->value = pShorter->value;
        pCurrent = pCurrent->pNext;
        pCurrent->pPre = pPre;
        pPre = pCurrent;
        pCurrent->pNext = NULL;
        pLonger = pLonger->pNext;
        pShorter = pShorter->pNext;
    }
    if (pCurrent != NULL) {    //第二段链表长度不为0
        if (pLonger != NULL){
            while (pLonger != NULL) {    //将第一段链表的剩余部分拷贝至新对象中
                pCurrent->pNext = new listNode;
                pCurrent->pNext->value = pLonger->value;
                pCurrent->pNext->pNext = NULL;
                pCurrent = pCurrent->pNext;
                pCurrent->pPre = pPre;
                pPre = pCurrent;
                pLonger = pLonger->pNext;
            }
        }
    } else {           //第二段链表长度为0,返回
        return first;
    }
    return list(pTarget,totalLength);
}
/*
 * 显式的删除链表对象
 * */
void list::deleteList() {
    listNode* pCurrent = NULL;
    while (pHead) {
        pCurrent = pHead->pNext;
        delete (pHead);
        pHead = pCurrent;
    }
}

/*
 * 直接插入排序
 * */
/*pPre设置有问题*/
void list::sort(){
	if (pHead) {
        listNode *pCurrent = pHead->pNext;
        while (pCurrent) {
            int value = pCurrent->value;
            listNode *pStart = pCurrent->pPre;
            if (pStart->value <= value) {   //如果当前节点值大于等于前面节点的值，则直接跳过
                pCurrent = pCurrent->pNext;
                continue;
            }
            while (pStart && pStart->value > value) {   //否则找到合适的插入点
                pStart = pStart->pPre;
            }
            if (pStart == NULL) {   //插入点在链表的头
                listNode *pTemp = pCurrent->pNext;
                pCurrent->pPre->pNext = pTemp;
                if (pTemp != NULL) {   //当前节点的后面不为空,调整后面节点的前向指针
                    pTemp->pPre = pCurrent->pPre;
                }
                pCurrent->pNext = pHead;    //将当前节点放在链表头
                pHead->pPre = pCurrent;
                pCurrent->pPre = NULL;
                pHead = pCurrent;        //调整HEAD指针
                pCurrent = pTemp;
            } else {
                listNode *pTemp = pCurrent->pNext;   //记录当前节点后面的节点指针
                pCurrent->pPre->pNext = pTemp;
                if (pTemp != NULL) {   //如果当前节点后面不为空，调整后面节点的前向指针
                    pTemp->pPre = pCurrent->pPre;
                }
                listNode *pNextStart = pStart->pNext;   //记录插入点后面节点指针
                pStart->pNext = pCurrent;    //将当前节点移动到pstart后面
                pCurrent->pPre = pStart;
                pCurrent->pNext = pNextStart;   //将pstart所指节点后面的节点调整至当前节点后面
                pNextStart->pPre = pCurrent;
                pCurrent = pTemp;          //调整Pcurrent指针
            }
        }
    }
}
