#include <iostream>
#include "linkedList.hpp"

using namespace bcTools;

template<typename Type>
linkedList<Type>::linkedList()
{
  this->memberCount = 0;
}

template<typename Type>
linkedList<Type>::~linkedList()
{
  this->clear();
}

template<typename Type>
void linkedList<Type>::push_end(Type value){
  if(memberCount == 0) {
    insertRootNode(value);
    return;
  }
  auto oldLastNode = this->lastNode;

  oldLastNode->next = new node<Type>;

  lastNode = oldLastNode->next;
  lastNode->prev = oldLastNode;
  lastNode->next = nullptr;
  lastNode->value = value;

  memberCount++;

}

template<typename Type>
node<Type>* linkedList<Type>::pop_end(){
  auto oldLastNode = lastNode;
  lastNode = oldLastNode->prev;
  lastNode->next = nullptr;
  
  oldLastNode->next = nullptr;
  oldLastNode->prev = nullptr;
  
  memberCount--;
  return oldLastNode;
}

template<typename Type>
void linkedList<Type>::push_begin(Type value){
  if(memberCount == 0) {
    insertRootNode(value);
    return;
  }
  auto oldRootNode = this->rootNode;

  auto newRoot = new node<Type>;

  newRoot->next = this->rootNode;
  newRoot->prev = newRoot;
  newRoot->value = value;

  this->rootNode = newRoot;
  oldRootNode->prev = newRoot;

  memberCount++;
}

template<typename Type>
node<Type>* linkedList<Type>::pop_begin(){
  if(memberCount == 0) {
    std::cout << "No root node when and tried to call pop_begin()\n";
    return nullptr;
  }
  auto popedRootNode = rootNode;
  auto newRootNode = rootNode->next;

  newRootNode->prev = newRootNode;

  popedRootNode->next = nullptr;
  popedRootNode->prev = nullptr;

  memberCount--;
  return popedRootNode;
}

template<typename Type>
void linkedList<Type>::remove_index(uint index) {
  if(index > memberCount || memberCount == 0) {
    std::cout << "tried to remove past list bounds or no elements in list to remove\n";
    return;
  }
    auto target = lookup_index(index);

    auto prevNode = target->prev;
    auto nextNode = target->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    target->next = nullptr;
    target->prev = nullptr;

    delete(target);
    memberCount--;
}

template<typename Type>
void linkedList<Type>::remove_end() {
  auto markedNode = lastNode;

  lastNode->prev->next = nullptr;
  lastNode = lastNode->prev;

  delete markedNode;
  memberCount--;

}

template<typename Type>
void linkedList<Type>::clear() {
  for(uint i = memberCount; i > 0;i--){
    remove_end();
  }
}

template<typename Type>
void linkedList<Type>::swap(uint indexA, uint indexB)
{
    auto nodeA = lookup_index(indexA);
    auto nodeA_next = nodeA->next;
    auto nodeA_prev = nodeA->prev;

    auto nodeB = lookup_index(indexB);
    auto nodeB_next = nodeB->next;
    auto nodeB_prev = nodeB->prev;

    nodeA->next = nodeB_next;
    nodeA->prev = nodeB_prev;

    nodeB->next = nodeA_next;
    nodeB->prev = nodeA_prev;

}

template<typename Type>
void linkedList<Type>::insert(uint index, Type value) {
    auto targetNode = lookup_index(index);
    auto targetNext = targetNode->next;

    node<Type>* newNode = new node<Type>;
    newNode->value = value;
    newNode->next = targetNext;
    newNode->prev = targetNode;

    targetNode->next = newNode;
    targetNext->prev = newNode;
}


template<typename Type>
void linkedList<Type>::insertRootNode(Type value) {
  rootNode = new node<Type>;
  lastNode = rootNode;

  rootNode->next = nullptr;
  rootNode->prev = rootNode;

  rootNode->value = value;
  memberCount++;
}

template<typename Type>
void linkedList<Type>::insertNode(Type value) {
  lastNode->next = new node<Type>;
  lastNode->next->prev = lastNode;
  lastNode->next->next = nullptr;

  lastNode = lastNode->next;
  lastNode->value = value;
  memberCount++;
}

template<typename Type>
node<Type>* linkedList<Type>::lookup_index(uint index) {
  node<Type>* target;

  if(index == memberCount - 1){
    return this->lastNode;
  }
  else if(index >= (this->memberCount/2)) {
    target = this->lastNode;

    for(uint i = memberCount; i != index;i--) {
      target = target->prev;
    }

    return target;
  }
  else {
    target = this->rootNode;
    for(uint i = 0; i != index;i++){
      target = target->next;
    }
  return target;
  }
}

void sort() {
  //TODO: Implement sorting 
}
