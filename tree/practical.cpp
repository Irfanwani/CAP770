#include <iostream>
using namespace std;

class TreeNode { // tree node is defined
public:
int val;
TreeNode* left;
TreeNode* right;
TreeNode(int data)
{
val = data;
left = nullptr;
right = nullptr;
}
};

void inorder(TreeNode* root)
{
//base case
if (root == nullptr)
return;
//traverse left sub tree
inorder(root->left);
//traverse current node secondly
printf("%d ", root->val);
//traverse right sub tree finally
inorder(root->right);
}
void postorder(TreeNode* root)
{
//base case
if (root == nullptr)
return;

postorder(root->left);
postorder(root->right);
printf("%d ", root->val);
}
void preorder(TreeNode* root)
{
//base case
if (root == nullptr)
return;

printf("%d ", root->val);
preorder(root->left);
preorder(root->right);

}
int main()
{
//building the tree
TreeNode* t = new TreeNode(7);
t->left = new TreeNode(1);
t->left->left = new TreeNode(0);
t->left->right = new TreeNode(3);
t->left->right->left = new TreeNode(2);
t->left->right->right = new TreeNode(5);
t->left->right->right->left = new TreeNode(4);
t->left->right->right->right = new TreeNode(6);
t->right = new TreeNode(9);
t->right->left = new TreeNode(8);
t->right->right = new TreeNode(10);

printf("Inorder traversal of the above tree is:\n");
inorder(t);
printf("\nPostorder traversal of the above tree is:\n");
postorder(t);
printf("\nPretorder traversal of the above tree is:\n");
preorder(t);
return 0;
}