#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

template<typename T>
class BSTode
{
	public:
		T data;
		BSTode *left;
		BSTode *right;
		
		BSTode()
		{
			left = NULL;
			right = NULL;
		}

		BSTode(T &entry)
		{
			data = entry;
			left = NULL;
			right = NULL;
		}
};


template<typename T>
class BST
{
	public:
		BSTode<T> *root;
		
		BST()
		{
			root = NULL;
		}

		void deleteBST(BSTode<T> *subroot)
		{
			if(subroot != NULL)
			{
				deleteBST(subroot->left);
				deleteBST(subroot->right);

				subroot->~BSTode<T>();
			}
		}

		void clear()
		{
			deleteBST(root);
		}

		BSTode<T> *find_parent(T &entry)
		{
			BSTode<T> *subroot = root;

			while(1)
			{
				if(subroot->left == NULL & subroot->right == NULL)
					return subroot;

				if(entry > subroot->data)
				{
					if(subroot->right != NULL)
						subroot = subroot->right;
					else
						return subroot;
				}

				else
				{
					if(subroot->left != NULL)
						subroot = subroot->left;
					else
						return subroot;
				}
			}

			//return subroot;
		}
		
		void insert(T entry)
		{
			if(root == NULL)
			{
				root = new BSTode<T>();
				root->data = entry;
			}

			else
			{
				BSTode<T> *parent = find_parent(entry);

				if(entry > parent->data)
					parent->right = new BSTode<T>(entry);
				else
					parent->left = new BSTode<T>(entry);
			}
		}

		BSTode<T> **delete_ptr(T &entry)
		{
			if(root->data == entry)
				return &root;

			BSTode<T> *subroot = root;
			while(subroot->left != NULL || subroot->right != NULL)
			{
				if(subroot->data == entry)
				{
					BSTode<T> **temp = &(subroot);
					return temp;
				}

				else if(subroot->data > entry)
				{
					if(subroot->left == NULL)
						return NULL;

					if((subroot->left)->data == entry)
						return &(subroot->left);
					else
						subroot = subroot->left;
				}

				else
				{
					if(subroot->right == NULL)
						return NULL;

					if((subroot->right)->data == entry)
						return &(subroot->right);
					else
						subroot = subroot->right;
				}
			}

			return NULL;
		}

		bool remove(T entry)
		{
			BSTode<T> **del_ptr = delete_ptr(entry);

			if(del_ptr == NULL)
				return false;

			if((*del_ptr)->left == NULL && (*del_ptr)->right == NULL)
			{
				BSTode<T> *temp = *del_ptr;
				*del_ptr = NULL;
				delete temp;
			}

			else
			{
				if((*del_ptr)->left != NULL)
				{
					//find rightmost child of left subtree
					BSTode<T> **candidate_ptr = &((*del_ptr)->left);

					while((*candidate_ptr)->right != NULL)
						candidate_ptr = &((*candidate_ptr)->right);

					BSTode<T> *candidate = *(candidate_ptr);
					*candidate_ptr = candidate->left;

					candidate->left = (*del_ptr)->left;
					candidate->right = (*del_ptr)->right;

					BSTode<T> *temp = *del_ptr;
					*del_ptr = candidate;
					delete temp;
				}

				else	//means left subtree is NULL: right subtree must exist
				{
					//find leftmost child of right subtree
					BSTode<T> **candidate_ptr = &((*del_ptr)->right);

					while((*candidate_ptr)->left != NULL)
						candidate_ptr = &((*candidate_ptr)->left);

					BSTode<T> *candidate = *(candidate_ptr);
					*candidate_ptr = candidate->right;

					candidate->left = (*del_ptr)->left;
					candidate->right = (*del_ptr)->right;

					BSTode<T> *temp = *del_ptr;
					*del_ptr = candidate;
					delete temp;
				}
			}

			return true;
		}

		void construct(T *array, int &n)
		{
			clear();

			for(int i=0; i<n; i++)
				insert(array[i]);
		}

		void construct(vector<T> &array)
		{
			clear();

			int n = (int)array.size();
			for(int i=0; i<n; i++)
				insert(array[i]);
		}

		void print_inorder(BSTode<T> *subroot)
		{
			if(subroot != NULL)
			{
				print_inorder(subroot->left);
				cout << subroot->data << " ";
				print_inorder(subroot->right);
			}
		}

		void print_preorder(BSTode<T> *subroot)
		{
			if(subroot != NULL)
			{
				cout << subroot->data << " ";
				print_preorder(subroot->left);
				print_preorder(subroot->right);
			}
		}

		void print_postorder(BSTode<T> *subroot)
		{
			if(subroot != NULL)
			{
				print_postorder(subroot->left);
				print_postorder(subroot->right);
				cout << subroot->data << " ";
			}
		}

		void print_bft()
		{
			queue< BSTode<T>* > q;
			q.push(root);

			BSTode<T> *current;

			while(!q.empty())
			{
				current = q.front();
				q.pop();
				cout << current->data << " ";

				if(current->left != NULL)
					q.push(current->left);
				if(current->right != NULL)
					q.push(current->right);
			}
		}

		void print_dft()
		{
			stack< BSTode<T>* > s;
			s.push(root);

			BSTode<T> *current;

			while(!s.empty())
			{
				current = s.top();
				s.pop();
				cout << current->data << " ";

				if(current->right != NULL)
					s.push(current->right);
				if(current->left != NULL)
					s.push(current->left);
			}
		}

		void print(string order = "inorder")
		{
			if(order == "inorder")
				print_inorder(root);
			else if(order == "preorder")
				print_preorder(root);
			else if(order == "postorder")
				print_postorder(root);
			else if(order == "BFT")
				print_bft();
			else if(order == "DFT")
				print_dft();
			else
				cout << "SUCH A TRAVERSAL ORDER IS NOT SUPPORTED";

			cout << endl;
		}
};