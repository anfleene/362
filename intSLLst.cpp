
#include "utility.h"
#include "intSLLst.h"

IntSLList::~IntSLList() {
    for (IntSLLNode *p; !isEmpty(); ) {
        p = head->next;
        delete head;
        head = p;
    }
}

void IntSLList::addToHead(int el) {
    head = new IntSLLNode(el,head);
    if (tail == 0)
       tail = head;
}

void IntSLList::addToTail(int el) {
    if (tail != 0) {      // if list not empty;
         tail->next = new IntSLLNode(el);
         tail = tail->next;
    }
    else head = tail = new IntSLLNode(el);
}

int IntSLList::deleteFromHead() {
    int el = head->info;
    IntSLLNode *tmp = head;
    if (head == tail)     // if only one node on the list;
         head = tail = 0;
    else head = head->next;
    delete tmp;
    return el;
}

int IntSLList::deleteFromTail() {
    int el = tail->info;
    if (head == tail) {   // if only one node on the list;
         delete head;
         head = tail = 0;
    }
    else {                // if more than one node in the list,
         IntSLLNode *tmp; // find the predecessor of tail;
         for (tmp = head; tmp->next != tail; tmp = tmp->next);
         delete tail;
         tail = tmp;      // the predecessor of tail becomes tail;
         tail->next = 0;
    }
    return el;
}
/*
This method sucks! what happens if you have the same value twice in more than one spot and you wanted to delete
the repeated element(you cant you can only delete the first one) I am commenting out this method and making my own delete method
*/
// void IntSLList::deleteNode(int el) {
//     if (head != 0)                     // if non-empty list;
//          if (head == tail && el == head->info) { // if only one
//               delete head;                       // node on the list;
//               head = tail = 0;
//          }
//          else if (el == head->info) {  // if more than one node on the list
//               IntSLLNode *tmp = head;
//               head = head->next;
//               delete tmp;              // and old head is deleted;
//          }
//          else {                        // if more than one node in the list
//               IntSLLNode *pred, *tmp;
//               for (pred = head, tmp = head->next; // and a non-head node
//                    tmp != 0 && !(tmp->info == el);// is deleted;
//                    pred = pred->next, tmp = tmp->next);
//               if (tmp != 0) {
//                    pred->next = tmp->next;
//                    if (tmp == tail)
//                       tail = pred;
//                    delete tmp;
//               }
//          }
// }
/*
This method deletes the node at the passed position and returns the value of that node
the node that is deleted is from postion not index to position 1 would be index 0
*/
int IntSLList::deleteNodeAt(int pos){
	//node to be deleted
	IntSLLNode *toBeDel = nodeAtPos(pos);
	//if the node is the head make the next node the head
	if(toBeDel == head){
		head = toBeDel->next;
	}
	//if the node is the tail make the pervious node the tail and set it's next to null
	else if(toBeDel == tail)
	{
		IntSLLNode *prev = 	nodeAtPos(pos-1);
		tail = prev;
		prev->next = NULL;		
	}
	//else make the previous node's next the node to be delted's next
	else{
		IntSLLNode *prev = 	nodeAtPos(pos-1);
		prev->next = toBeDel->next;
	}
	
	int el = toBeDel->info;
	//delete the node
	delete toBeDel;
	//return the value of the deleted node
	return el;
}

//this method returns a pointer to the node at the passed position
//this is very inefficent but it works
IntSLLNode* IntSLList::nodeAtPos(int pos)
{
	IntSLLNode *node = head;
	for(int i=1; i < pos; i++)
	{
		node = node->next;
	}
	return node;
}


bool IntSLList::isInList(int el) const {
    IntSLLNode *tmp;
    for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
    return tmp != 0;
}

void IntSLList::printAll() const {
	cout << "-----------<Linked List>-----------" << endl;
    for (IntSLLNode *tmp = head; tmp != 0; tmp = tmp->next)
	{
		cout << tmp->info;
		if(tmp != tail)
		{
			cout<< ", ";
		}
	}
        
	cout << endl << "-----------</Linked List>-----------" << endl;
}

IntSLLNode* IntSLList::getHead(){
	return head;
}

IntSLLNode* IntSLList::getTail(){
	return tail;
}

