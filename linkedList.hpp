#ifndef __LINKED_LIST_HPP_
#define __LINKED_LIST_HPP_

#include <cstdint>
#include <string>

namespace bcTools {

  template<typename Type> struct node {
  public:
    node<Type>* next;
    node<Type>* prev;
    Type value;
  private:
  };

  template<typename Type> class linkedList {
  public:
    linkedList();
    ~linkedList();

    void remove_index(uint index);
    void remove_end();
    void clear();
    void swap(uint indexA, uint indexB);

    void insert(uint index, Type value);

    //Push and pop methods
    void push_end(Type value);
    node<Type>* pop_end();
    void push_begin(Type value);
    node<Type>* pop_begin();

    //Warning: Slow!
    node<Type>* lookup_index(uint index);

    uint size()   { return memberCount; }
    node<Type>* getRootPtr() { return rootNode; }
    node<Type>* getLastPtr() { return lastNode; }

  private:
    void insertRootNode(Type value);
    void insertNode(Type value);

    node<Type>* rootNode;
    node<Type>* lastNode;

    uint memberCount;
  };

template class linkedList<ushort>;
template class linkedList<short>;
template class linkedList<uint>;
template class linkedList<int>;
template class linkedList<ulong>;
template class linkedList<long>;
}
#endif /* __LINKED_LIST_HPP_ */
