#include <iostream>

using namespace std;


typedef struct _TreeNode {
    int val;
    struct _TreeNode *left;
    struct _TreeNode *right;
    _TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	_TreeNode(){
		val=0;
		left=NULL;
		right=NULL ;
	}
}TreeNode;


// TreeNode* flip_tree(TreeNode* root) 
// {
//         TreeNode *left, *right;
//         if(root==NULL)
//             return root;
//         left = root->left;
//         right = root->right;

//         root->left = flip_tree(right);
//         root->right = flip_tree(left);
//         return root;
// }



TreeNode* flip_tree(TreeNode* root) 
{
        //TreeNode *left, *right;
		TreeNode *tmp;
        if(root==NULL)
            return root;

		flip_tree(root->left);
		flip_tree(root->right);
	
		tmp = root->left;
		root->left = root->right;
		root->right = tmp;

        return root;
}



 
void insert_node(TreeNode **tree,int a){
	if(*tree == NULL){
		*tree = new TreeNode();
		(*tree)->val = a;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
		return;	
	}
		
	if(a == (*tree)->val)
		return;
	else if(a < (*tree)->val)
		insert_node(&(*tree)->left,a);
	else
		insert_node(&(*tree)->right,a);
}


void tree_print(TreeNode *root)
{
	if (!root)
		return;
	cout << root->val;
	tree_print(root->left);
	tree_print(root->left);
}


int main(int argc, char const *argv[])
{
/* 
	//     3
    //    /   \
    //   2     8
    //  / \   / \
    // 1   4 5   9  
    
    //      3
    //    /   \
    //   8     2
    //  / \   / \
    // 9   5 4   1  

	*/

	TreeNode *tree = new TreeNode;

	insert_node(&tree, 3);
	insert_node(&tree, 2);
	insert_node(&tree, 8);
	insert_node(&tree, 1);
	insert_node(&tree, 4);
	insert_node(&tree, 5);
	insert_node(&tree, 9);



	
	tree_print(tree);
	flip_tree(tree);
	tree_print(tree);
	
	return 0;
}


