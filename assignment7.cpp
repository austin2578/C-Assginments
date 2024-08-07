#include <bits/stdc++.h>
using namespace std;
  
// Class to implement node
class Node
{
public:
    int key;
    string name;
    Node **forward;
    Node(int, string, int);
};
  
Node::Node(int key, string name, int level)
{
    this->key = key;
    this->name = name;
    forward = new Node*[level+1];
  
    memset(forward, 0, sizeof(Node*)*(level+1));
};
  
// Class for Skip list
class SkipList
{
    // Maximum level for this skip list
    int MAXLVL;
  
    // P is the fraction of the nodes with level 
    // i pointers also having level i+1 pointers
    float P;
  
    // current level of skip list
    int level;
  
    // pointer to header node
    Node *header;
public:
    SkipList(int, float);
    int randomLevel();
    Node* createNode(int, int, string);
    void insertElement(int, string);
    void deleteElement(int);
    void searchElement(int);
    void displayList();
};
  
SkipList::SkipList(int MAXLVL, float P)
{
    this->MAXLVL = MAXLVL;
    this->P = P;
    level = 0;
  
    header = new Node(-1, "", MAXLVL);
};
  
// create random level for node
int SkipList::randomLevel()
{
    float r = (float)rand()/RAND_MAX;
    
    int lvl = 0;
    while(r < P && lvl < MAXLVL)
    {
        lvl++;
        r = (float)rand()/RAND_MAX;
        
    }
    return lvl;
};
  
// create new node
Node* SkipList::createNode(int key, int level, string name)
{
    Node *n = new Node(key, name, level);
    return n;
};
  
// Insert given key in skip list
void SkipList::insertElement(int key, string name)
{
    Node *current = header;
  

    Node *update[MAXLVL+1];
    memset(update, 0, sizeof(Node*)*(MAXLVL+1));
  
    /*    start from highest level of skip list
        move the current pointer forward while key 
        is greater than key of node next to current
        Otherwise inserted current in update and 
        move one level down and continue search
    */
    for(int i = level; i >= 0; i--)
    {
        while(current->forward[i] != NULL &&
              current->forward[i]->key < key)
            current = current->forward[i];
        update[i] = current;
    }
  
    /* reached level 0 and forward pointer to 
       right, which is desired position to 
       insert key. 
    */
    current = current->forward[0];
  
    /* if current is NULL that means we have reached
       to end of the level or current's key is not equal
       to key to insert that means we have to insert
       node between update[0] and current node */
    if (current == NULL || current->key != key)
    {
        // Generate a random level for node
        int rlevel = randomLevel();
  
        /* If random level is greater than list's current
           level (node with highest level inserted in 
           list so far), initialize update value with pointer
           to header for further use */
        if(rlevel > level)
        {
            for(int i=level+1;i<rlevel+1;i++){
                update[i] = header;
            }
            // Update the list current level
            level = rlevel;
        }
        for(int i=0;i<rlevel;i++){
        if(rlevel>1)
        cout<<"Key " << key <<" level Increase: True\n";
        else cout<<"Key " << key <<" level Increase: False\n";
        }
        // create new node with random level generated
        Node* n = createNode(key, rlevel, name);
  
        // insert node by rearranging pointers 
        for(int i=0;i<=rlevel;i++)
        {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }
        cout<<"Successfully Inserted key "<<key<<"\n";
    }
    
};
  
// Delete element from skip list
void SkipList::deleteElement(int key)
{
    Node *current = header;
  
    // create update array and initialize it
    Node *update[MAXLVL+1];
    memset(update, 0, sizeof(Node*)*(MAXLVL+1));
  
    /*    start from highest level of skip list
        move the current pointer forward while key 
        is greater than key of node next to current
        Otherwise inserted current in update and 
        move one level down and continue search
    */
    for(int i = level; i >= 0; i--)
    {
        while(current->forward[i] != NULL  &&
              current->forward[i]->key < key)
            current = current->forward[i];
        update[i] = current;
    }
  
    /* reached level 0 and forward pointer to 
       right, which is possibly our desired node.*/
    current = current->forward[0];
  
    // If current node is target node
    if(current != NULL and current->key == key)
    {
        /* start from lowest level and rearrange
           pointers just like we do in singly linked list
           to remove target node */
        for(int i=0;i<=level;i++)
        {
            /* If at level i, next node is not target 
               node, break the loop, no need to move 
              further level */
            if(update[i]->forward[i] != current)
                break;
  
            update[i]->forward[i] = current->forward[i];
        }
  
        // Remove levels having no elements 
        while(level>0 && header->forward[level] == 0)
            level--;
         cout<<"Successfully deleted key "<<key<<"\n";
    }
};
  
// Search for element in skip list
void SkipList::searchElement(int key)
{
    Node *current = header;
  
    /*    start from highest level of skip list
        move the current pointer forward while key 
        is greater than key of node next to current
        Otherwise inserted current in update and 
        move one level down and continue search
    */
    for(int i = level; i >= 0; i--)
    {
        while(current->forward[i] &&
               current->forward[i]->key < key)
            current = current->forward[i];
  
    }
  
    /* reached level 0 and advance pointer to 
       right, which is possibly our desired node*/
    current = current->forward[0];
  
    // If current node have key equal to
    // search key, we have found our target node
    if(current and current->key == key) 
        cout<<"Found key: "<<key<<"\n";
};
  
// Display skip list level wise
void SkipList::displayList()
{
    cout<<"\n*****Skip List*****"<<"\n";
    for(int i=0;i<=level;i++)
    {
        Node *node = header->forward[i];
        cout<<"\nLevel "<<i<<": \n-------------\nKey | Value";
        while(node != NULL)
        {
            cout<<endl<<" " << node->key<<" , "<<node->name;
            node = node->forward[i];
        }
        cout<<"\n";
    }
};
  
// Driver to test above code
int main()
{
    // Seed random number generator
    srand((unsigned)time(0));
  
    // create SkipList object with MAXLVL and P 
    SkipList lst(3, 0.5);

    cout<<"/********************************************************************\n";
    cout<<"* This program will enter the given data into a skip list using the\n";
    cout<<"* given key and corresponding values and the outputting the results\n* to the console.\n";
    cout<<"*********************************************************************/\n";
    lst.insertElement(18,"Laguna Niguel");
    lst.insertElement(41,"Mission Viejo");
    lst.insertElement(22,"San Clemente");
    lst.insertElement(44,"Irvine");
    lst.deleteElement(41);
    lst.insertElement(58,"Lake Forest");
    lst.insertElement(32,"San Diego");
    lst.insertElement(49,"Anaheim");
    lst.deleteElement(58);
    lst.insertElement(31,"Los Angeles");
    lst.insertElement(17,"Orange");
    lst.insertElement(72,"Palm Springs");
    lst.insertElement(41,"Riverside");
    lst.deleteElement(72);
    lst.insertElement(19,"Brea");
    lst.insertElement(60,"Santa Ana");
    lst.insertElement(35,"Tustin");
    lst.insertElement(103,"Oceanside");
    lst.insertElement(11,"La Jolla");
    lst.insertElement(18,"Del Mar");
    lst.insertElement(22,"Aliso  Viejo");
    lst.insertElement(49,"Laguna Beach");
    lst.deleteElement(41);
    lst.insertElement(42,"Vista");
    lst.insertElement(49,"San Diego");
    lst.insertElement(99,"San Juan");
    lst.insertElement(29,"Dana Point");
    lst.insertElement(88,"El Segundo");
    lst.insertElement(41,"San Clemente");
    lst.insertElement(62,"Laguna Hills");
    lst.insertElement(44,"Irvine");
    lst.deleteElement(41);
    lst.deleteElement(42);
    lst.insertElement(58,"Lake Forest");
    lst.insertElement(32,"Sand Diego");
    lst.insertElement(49,"Anaheim");
    lst.deleteElement(58);
    lst.insertElement(31,"Los Angeles");
    lst.insertElement(17,"Orange");
    lst.insertElement(72,"Palm Springs");
    lst.insertElement(41,"Riverside");
    lst.deleteElement(72);
    lst.insertElement(19,"Brea");
    lst.insertElement(60,"Santa Ana");
    lst.insertElement(35,"Tustin");
    lst.insertElement(103,"Oceanside");
    lst.insertElement(11,"La Jolla");
    lst.insertElement(18,"Del Mar");
    lst.insertElement(22,"Aliso Viejo");
    lst.insertElement(49,"Laguna Beach");
    lst.deleteElement(41);
    lst.insertElement(42,"Vist");
    lst.insertElement(49,"San Diego");
    lst.insertElement(99,"San Juan");
    lst.insertElement(29,"Dana Point");
    lst.insertElement(88,"El Segundo");
    lst.insertElement(41,"San Clemente");
    lst.insertElement(62,"Laguna Hills");

    lst.displayList();
}