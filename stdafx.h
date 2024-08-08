#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include "Monster.h"

template<class T>
class TreeNode {
public:
	TreeNode(T& Ele) {
		//初始化树
		memset(&this->element, 0, sizeof(Ele));
		//将数据存入element
		memcpy(&element, &Ele, sizeof(T));
		this->pLeft = this->pRight = NULL;
		
		
	}

	T element;
	TreeNode<T>* pLeft;
	TreeNode<T>* pRight;
};

template<class T>
class BSortTree {
public:
	BSortTree();
	~BSortTree();

public:
	//初始化
	VOID Init();
	VOID Traverse1(TreeNode<T>* TreeNode);
	VOID Traverse2(TreeNode<T>* TreeNode);
	VOID Traverse3(TreeNode<T>* TreeNode);
	VOID Clear(TreeNode<T>* TreeNode);
	DWORD GetDepth(TreeNode<T>* TreeNode);
	TreeNode<T>* GetRoot();
	


private:
	TreeNode<T>* m_pRoot;
	DWORD m_size;
};


template <class T>
BSortTree<T>::BSortTree() {
	this->Init();
}

template <class T>
BSortTree<T>::~BSortTree() {
	Clear(m_pRoot);
	m_pRoot = nullptr;
}


template<class T>
VOID BSortTree<T>::Init() {
	//在栈中创建对象
	Monster m1("LiZonghong", 0x10, 0x10, 18);
	Monster m2("LiHengzhen", 0x10, 0x10, 18);
	Monster m3("NiChenzhe", 0x10, 0x10, 18);
	Monster m4("XieZiyi", 0x10, 0x10, 18);
	Monster m5("XueJiacheng", 0x10, 0x10, 18);
	Monster m6("YinZuodong", 0x10, 0x10, 18);
	Monster m7("ChaoRenqiang", 0x10, 0x10, 18);
	Monster m8("FengChengzhi", 0x10, 0x10, 18);

	//分配与怪物等同的树节点，并将怪物存入节点
	TreeNode<Monster>* t1 = new TreeNode<Monster>(m1);
	TreeNode<Monster>* t2 = new TreeNode<Monster>(m2);
	TreeNode<Monster>* t3 = new TreeNode<Monster>(m3);
	TreeNode<Monster>* t4 = new TreeNode<Monster>(m4);
	TreeNode<Monster>* t5 = new TreeNode<Monster>(m5);
	TreeNode<Monster>* t6 = new TreeNode<Monster>(m6);
	TreeNode<Monster>* t7 = new TreeNode<Monster>(m7);
	TreeNode<Monster>* t8 = new TreeNode<Monster>(m8);

	//用成员变量指向分配的节点
	this->m_pRoot = t1;
	t1->pLeft = t2;
	t1->pRight = t3;
	t2->pLeft = t4;
	t4->pRight = t5;
	t3->pLeft = t6;
	t6->pRight = t7;
	t4->pLeft = t8;
	
	

}
template<class T>
TreeNode<T>* BSortTree<T>::GetRoot() {
	return m_pRoot;
}




template<class T>
DWORD BSortTree<T>::GetDepth(TreeNode<T>* TreeNode) {
	if (TreeNode == NULL) {
		return 0;
	}
	else{
		int m = GetDepth(TreeNode->pLeft);
		int n = GetDepth(TreeNode->pRight);
		return (m > n) ? (m + 1) : (n + 1);
	}
}


//左右根
template<class T>
void BSortTree<T>::Traverse1(TreeNode<T>* TreeNode) {
	if (!TreeNode) {
		return;
	}
	else{
		Traverse1(TreeNode->pLeft);
		Traverse1(TreeNode->pRight);
		char temp[20]{};
		memcpy(temp, &TreeNode->element, 20);
		std::cout << temp << std::endl;
	}
}

//左根右
template<class T>
void BSortTree<T>::Traverse2(TreeNode<T>* TreeNode) {
	if (!TreeNode) {
		return;
	}
	else {
		Traverse2(TreeNode->pLeft);
		char temp[20]{};
		memcpy(temp, &TreeNode->element, 20);
		std::cout << temp << std::endl;
		Traverse2(TreeNode->pRight);
	}
}

//根左右
template<class T>
void BSortTree<T>::Traverse3(TreeNode<T>* TreeNode) {
	if (!TreeNode) {
		return;
	}
	else {
		char temp[20]{};
		memcpy(temp, &TreeNode->element, 20);
		std::cout << temp << std::endl;
		Traverse3(TreeNode->pLeft);
		Traverse3(TreeNode->pRight);
	}
}

template<class T>
VOID BSortTree<T>::Clear(TreeNode<T>* TreeNode) {
	if (!TreeNode) {
		return;
	}
	else {
		Clear(TreeNode->pLeft);
		Clear(TreeNode->pRight);
		delete TreeNode;
	}
	

}





