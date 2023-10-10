#include "LinkedList.h"



LinkedList::LinkedList(){
    head = nullptr;
}

LinkedList::~LinkedList(){
    while (head != nullptr)
    {
        pop_back();
    }
    
}

int LinkedList::size() const {
    int length = 0;

    Node* curNode = head;

    while (curNode != nullptr)
    {
        ++length;
        curNode = curNode->next;
    }
    
    return length;
}

Date* LinkedList::back(void) const {
    return head->date;
}

Date* LinkedList::get(int index) const{
    Date* retCoord = nullptr;
    index = size() - 1 - index;

    if(index >= 0 && index < size() ){
        int counter = 0;
        Node* curNode = head;

        while (counter < index)
        {
            ++counter;
            curNode = curNode->next;
        }
        
        retCoord = curNode->date;

    }

    return retCoord;

}

void LinkedList::pop_back(){
    Node* toDelete = head;
    head = head->next;
    delete toDelete->date;
    delete toDelete;
}

void LinkedList::push_back(Date* date){
    Node* node = new Node();
    node->date = date;
    node->next = head;
    head = node;
}