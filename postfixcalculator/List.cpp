// Charles Brady, cjb5ct, List.cpp, 9-13-2020

#include <iostream>
#include <string>
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"
using namespace std;


List::List() {
   head=new ListNode();
   tail=new ListNode();
   head->next=tail;
   tail->previous=head;
   count=0;
  

}
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}


List::~List() {
  makeEmpty();
  delete head;
  delete tail;
}

bool List::isEmpty() const {
  if (head->next == tail && tail->previous == head) {
    return true;
  }
  return false; 
}


void List::makeEmpty() {

  ListItr first = this->first();
  while(!first.isPastEnd()){
    first.moveForward();
    delete first.current->previous;
   
    
  }
  head->next = tail;
  tail->previous = head;
  count = 0;
  
  
}


void List::insertAtTail(int x) {
  ListNode*temp = new ListNode();
  temp->value = x;
  temp->next = tail;
  temp->previous = tail->previous;

  tail->previous = temp;
  temp->previous->next = temp;
    // tail = temp;
  count++;
 
}

ListItr List::first() {
  ListItr temp = head->next;
  return temp;
}

ListItr List::last() {
  ListItr temp = tail->previous;
  return temp;
}

void List::insertAfter(int x, ListItr position) {
  ListNode*temp = new ListNode();
  temp->value = x;
  temp->next = position.current->next;
  temp->previous = position.current;
  position.current->next->previous = temp;
  position.current->next = temp;
  count++;

}

void List::insertBefore(int x, ListItr position) {
  ListNode*temp = new ListNode();
  temp->value = x;
  temp->next = position.current;
  temp->previous = position.current->previous;
  position.current->previous->next = temp;
  position.current->previous = temp;

  count++;

}

ListItr List::find(int x) {
  ListItr first = this->first();
  
  while(!first.isPastEnd()) {
    if (x == first.retrieve()) {     
      return first;
    }
    first.moveForward();
  }
  return first;
}

void List::remove(int x) {
   ListItr first = find(x);
   first.current->previous->next = first.current->next;
   first.current->next->previous = first.current->previous;
   delete first.current;
   count--;
   return;

}
int List::size() const {
  return count; 
}

void printList(List& source, bool forward) {
  ListItr first = source.first();
  ListItr last = source.last();
  if(forward) {
    while(!first.isPastEnd()){
      cout << first.retrieve() << " ";
      first.moveForward();
    }
  }
  if(!forward) {
    while(!last.isPastBeginning()){
      cout << last.retrieve() << " ";
      last.moveBackward();
    }
  }
}