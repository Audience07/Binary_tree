#include "stdafx.h"
#include "Monster.h"


int main() {
	
	BSortTree<Monster>* Tree1 = new BSortTree<Monster>();
	DWORD Depath = Tree1->GetDepth(Tree1->GetRoot());
	Tree1->Traverse1(Tree1->GetRoot());
	delete Tree1;

}