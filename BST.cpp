#include<bits/stdc++.h>
using namespace std;
class node{
	private:
		int num;
		node *right, *left;
	public:
		node(int key):num(key){
			right=left=nullptr;
		}
	friend class bst;
};
class bst{
	private:
		node *root;
		void add(int key,node *cur){
			if(root==nullptr){
				node *child=new node(key);
				root=child;
			}
			else{
				if(key>cur->num){
					if(static_cast<bool>(cur->right))
						add(key,cur->right);
					else{
						node *child=new node(key);
						cur->right=child;
					}
				}
				else{
					if(static_cast<bool>(cur->left))
						add(key,cur->left);
					else{
						node *child=new node(key);
						cur->left=child;
					}
				}
			}
		}
		void Print(node *cur){
			if(static_cast<bool>(cur->left))
				Print(cur->left);
			cout<<cur->num<<' ';
			if(static_cast<bool>(cur->right))
				Print(cur->right);
		}
		void destruct(node *cur){
			if(static_cast<bool>(cur->left))
				destruct(cur->left);
			if(static_cast<bool>(cur->right))
				destruct(cur->right);
			delete cur->left;
			delete cur->right;
			cur->left=nullptr;
			cur->right=nullptr;
		}
		bool check_null(void){
			if(root==nullptr)
				return true;
			else
				return false;
		}
	public:
		bst(){
			root=nullptr;
		}
		bst(vector<int> vec):root(nullptr){
			for(const auto& i:vec){
				add(i,root);
			}
		}
		~bst(){
			if(root!=nullptr)
				destruct(root);
			root=nullptr;
		}
		void push(int key){
			add(key,root);
		}
		void print(void){
			if(root!=nullptr)
				Print(root);
			else
				cout<<"Empty BST!!!";
			cout<<'\n';
		}
		void clean(void){
			if(root!=nullptr)
				destruct(root);
			root=nullptr;
		}
		bool empty(void){
			return check_null();
		}
};
int main(){
	int n,tmp;
	while(cin>>n){
		bst tree;
		while(n--){
			cin>>tmp;
			tree.push(tmp);
		}
		tree.print();
		tree.clean();
		tree.print();
	}
	return 0;
}