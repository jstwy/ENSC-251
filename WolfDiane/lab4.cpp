#include <iostream>
#include <string>
using namespace std;
/*
class Node
{
  public
  
  private
};
*/

struct Node
{
    string name;
    Node *link;
};
typedef Node* NodePtr;
int main()
{
    NodePtr listPtr, tempPtr;
    listPtr = new Node;
    listPtr->name = "Emily";
    tempPtr = new Node;
    tempPtr->name = "James";
    listPtr->link = tempPtr;
    tempPtr->link = new Node;
    tempPtr = tempPtr->link;
    tempPtr->name = "Joules";
    tempPtr->link = NULL;
    return 0;
}