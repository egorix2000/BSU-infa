#include <iostream>
#include <string>

#include "SinglyLinkedList/SinglyLinkedList.h"
#include "SinglyLinkedList/SinglyLinkedListIterator.h"
#include "Array/Array.h"

using namespace std;

int main()
{
    Array<int> list1;
    Array<int> list2 (5);

    list1.push_front(7);

    list1.push_front(3);
    SinglyLinkedListIterator<int> iterator1 = list1.begin();
    ++iterator1;
    list1.insert(iterator1, 2);
    list2.push_front(3);
    list2.push_front(1);

    SinglyLinkedListIterator<int> iterator2 = list2.begin();
    list1.insert(iterator1, 2);
    iterator1 = list1.begin();
    ++iterator1;
    list1.erase(iterator1);
    iterator1 = list1.begin();
    list1.erase(iterator1);

    cout << list1[0] << " " << list1[1] << endl;
    cout << list2[2];
    return 0;
}