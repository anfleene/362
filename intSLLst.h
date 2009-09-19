#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

#include <iostream>

class IntSLLNode {
public:
    int info;
    class IntSLLNode *next;
    IntSLLNode(int el, IntSLLNode *ptr = 0) {
        info = el; next = ptr;
    }
};

class IntSLList {
public:
    IntSLList() {
       	head = tail = 0;
		size = 0;
    }
    ~IntSLList();
    int isEmpty() {
        return head == 0;
    }
    void addToHead(int);
    void addToTail(int);
    int  deleteFromHead(); // delete the head and return its info;
    int  deleteFromTail(); // delete the tail and return its info;
	//this is a method that i created to replace the existing delete because it was a very bad implementation
	int deleteNodeAt(int);
	//this method grabs a node at the passed position (this is position not index)
	IntSLLNode *nodeAtPos(int);
    bool isInList(int) const;
    void printAll() const;
	//added some getters for the member funtions
	IntSLLNode *getHead();
	IntSLLNode *getTail();
private:
    IntSLLNode *head, *tail;
	int size;
};

#endif
