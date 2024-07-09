#include <iostream>
#include <queue>
using namespace std;

//Binary Search Tree
class BinarySearchTree{
    private:
        struct TreeNode{
            int value;    //integer value of node
            TreeNode *left; //left child
            TreeNode *right; //right child
            TreeNode *parent; //parent of node
            TreeNode(int value, TreeNode *left = NULL, TreeNode *right = NULL)
            {
                this->value = value;     //set integer value of node
                this->left = left;       //set left child
                this->right = right;     //set right child
            }
        };

        TreeNode *root;        //tree root
        //insert value in tree 
        void insert(TreeNode *&tree, int value)
        {
            //if tree is empty  (BASE CASE)
            if(tree == NULL){
            tree = new TreeNode(value); 
            return;
            }
            //insert left      (Recursive Case 1)
            if(value < tree->value){
                insert(tree->left,value);
            }
            else  //insert right (Recursive Case 2)
            {
                insert(tree->right,value);
            }
        }
        //perform in order tree traversal
        void displayInOrder(TreeNode *tree)
        {
            if(tree == NULL)
            {
                return;
            }
            else
            {
                displayInOrder(tree->left);
                cout << tree->value << " ";
                displayInOrder(tree->right);
            }
        }
        //perform pre-order tree traversal
        void displayPreOrder(TreeNode *tree)
        {
            if(tree == NULL)
            {
                return;
            }
            else
            {
                cout << tree->value << " ";
                displayPreOrder(tree->left);
                displayPreOrder(tree->right);
            }
        }
        //perform post order tree traversal
        void displayPostOrder(TreeNode *tree)
        {
            if(tree == NULL)
            {
                return;
            }
            else
            {  
                displayPreOrder(tree->left);
                displayPreOrder(tree->right);
                cout << tree->value << " ";
            }
        }
        //perform breadth first tree traversal
        void displayBreadthFirst(TreeNode* root) {
        if (!root) {
         return;
        }
    
       // Create a queue to store the nodes to be visited
       queue<TreeNode*> q;
       q.push(root);
    
       while (!q.empty()) {
           // Get the next node to visit from the front of the queue
           TreeNode* curr = q.front();
           q.pop();
        
           // Process the current node
           cout << curr->value << " ";
        
         // Add the left and right children to the queue
          if (curr->left) {
                q.push(curr->left);
           }
           if (curr->right) {
               q.push(curr->right);
            }
        }
        }
        void displayParentChildRelationship(TreeNode* root) 
        {
            if (!root) {
                return;
            }
            // Show the parent-child relationship for the current node
            cout << "Node - " << root->value << ",";
         if (root->parent) {
                cout << " Parent: " << root->parent->value;
            }
            if (root->left) {
                cout << " Left Child: " << root->left->value;
            }
            if (root->right) {
                cout << " Right Child: " << root->right->value;
            }
            cout << endl;
    
            // Set the parent pointer for the child nodes
            if (root->left) {
                root->left->parent = root;
            }
            if (root->right) {
                root->right->parent = root;
            }
            // Recursively show the parent-child relationship for the child nodes
            displayParentChildRelationship(root->left);
            displayParentChildRelationship(root->right);
        }
    public: 
        //public calls for the private memberfunctions
        BinarySearchTree()
        {
            root = NULL;
        }
        void insert(int value) //overloaded insert function 
        {
            insert(root,value);
        }
        void showInOrder()
        {
            displayInOrder(root);
        }
        void showPreOrder()
        {
            displayPreOrder(root);
        }
        void showPostOrder()
        {
            displayPostOrder(root);
        }
        void showBreadthFirst()
        {
            displayBreadthFirst(root);
        }
        void showParentChildRelationship()
        {
            displayParentChildRelationship(root);
        }
};

int main()
{
    BinarySearchTree tree;
    int array[] = {12, 24, 49, 9, 59, 288, 19, 13, 888, 77, 25, 109, 55, 118, 89, 33, 1001, 18, 44, 88};
    int size = sizeof(array)/sizeof(array[0]); //size of array
    //tree data insertion
    for(int i=0;i<size;i++)
    {
        tree.insert(array[i]);
    }
    cout << "In order tree traversal:\n";
    tree.showInOrder();
    cout << "\nPre-order tree traversal:\n";
    tree.showPreOrder();
    cout << "\nPost-order tree traversal:\n";
    tree.showPostOrder();
    cout << "\nBreadth-first tree traversal:\n";
    tree.showBreadthFirst();
    cout << "\nParent-child relationship:\n";
    tree.showParentChildRelationship();
}