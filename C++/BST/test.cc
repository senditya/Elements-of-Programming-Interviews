#include <iostream>
#include <vector>
#include "bst.h"

using namespace std;

int main()
{
	vector<int> array;
	array.push_back(5);
	array.push_back(6);
	array.push_back(1);
	array.push_back(3);
	array.push_back(-1);
	array.push_back(8);
	array.push_back(2);
	array.push_back(9);
	array.push_back(7);

	BST<int> bst;

	bst.construct(array);

	// bst.print("inorder");
	bst.print("preorder");
	// bst.print("postorder");
	// bst.print("BFT");
	// bst.print("DFT");

	cout << bst.remove(6) << endl;

	// bst.print("inorder");
	bst.print("preorder");
	// bst.print("postorder");
	// bst.print("BFT");
	// bst.print("DFT");
}