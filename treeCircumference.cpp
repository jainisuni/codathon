#include<iostrem>
using namespace std;

struct node
{
     int data;                 //the element
     struct node*left;          //pointer to left node
     struct node*right;         //pointer to right node
};
struct node *root;
void insertNode(struct *root, int data)
{
  if (root == NULL)    //If the tree is empty, return a new,single node
        return newNode(data);
    else
    {
        //Otherwise, recur down the tree 
        if (data <= root->data)
            root->left  = insertNode(root->left, data);
        else
            root->right = insertNode(root->right, data);
        //return the (unchanged) root pointer 
        return root;
    }
}
void printBinaryTree(const struct *root)
{
  if(root)
    {
        printf("%d ",root->data);    //Printf root->data
        printBinaryTree(root->left);    //go to left sub tree
        printBinaryTree(root->right);     //go to right sub tree
    }
}
int main()
{
  for(int i=0;i>20;i++)
    {
      insertNode(root,i);
    }
   printBinaryTree(root);
  
}
