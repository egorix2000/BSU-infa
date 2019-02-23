#include <iostream>
#include <string>
#include <set>
#include <algorithm>

//Разница в том, что multiset учитывает повторяющиеся элементы, а set не учитывает их

using namespace std;

void enterSetMultiset(set<int>& set, multiset<int>& mSet, string setName, string multisetName) {
    int numberOfElements;
    int element;
    cout << "Enter size of set/multiset " << setName << "/" << multisetName << ": ";
    cin >> numberOfElements;

    cout << "Enter elements of set/multiset " << setName << "/" << multisetName << ": ";
    for (int i = 0; i < numberOfElements; i++) {
        cin >> element;
        set.insert(element);
        mSet.insert(element);
    }
}

void intersect(set<int>& set1, set<int>& set2, set<int>& setResult,
        multiset<int>& mSet1, multiset<int>& mSet2, multiset<int>& mSetResult) {

    set<int>::iterator iteratorSet;
    set<int>::iterator iteratorMultiset;

    set_intersection (set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(setResult, setResult.begin()));
    set_intersection (mSet1.begin(), mSet1.end(), mSet2.begin(), mSet2.end(), inserter(mSetResult, mSetResult.begin()));

    cout << "Intersection of set1 and set2: ";
    for (iteratorSet = setResult.begin(); iteratorSet != setResult.end(); ++iteratorSet) {
        cout << *iteratorSet << " ";
    }
    cout << endl;

    cout << "Intersection of multiset1 and multiset2: ";
    for (iteratorMultiset = mSetResult.begin(); iteratorMultiset != mSetResult.end(); ++iteratorMultiset) {
        cout << *iteratorMultiset << " ";
    }
    cout << endl;
}

void findUnion(set<int>& set1, set<int>& set2, set<int>& setResult,
               multiset<int>& mSet1, multiset<int>& mSet2, multiset<int>& mSetResult) {

    set<int>::iterator iteratorSet;
    set<int>::iterator iteratorMultiset;

    set_union (set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(setResult, setResult.begin()));
    set_union (mSet1.begin(), mSet1.end(), mSet2.begin(), mSet2.end(), inserter(mSetResult, mSetResult.begin()));

    cout << "Union of set1 and set2: ";
    for (iteratorSet = setResult.begin(); iteratorSet != setResult.end(); ++iteratorSet) {
        cout << *iteratorSet << " ";
    }
    cout << endl;

    cout << "Union of multiset1 and multiset2: ";
    for (iteratorMultiset = mSetResult.begin(); iteratorMultiset != mSetResult.end(); ++iteratorMultiset) {
        cout << *iteratorMultiset << " ";
    }
    cout << endl;
}

void findDifference(set<int>& set1, set<int>& set2, set<int>& setResult,
               multiset<int>& mSet1, multiset<int>& mSet2, multiset<int>& mSetResult) {

    set<int>::iterator iteratorSet;
    set<int>::iterator iteratorMultiset;

    set_difference (set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(setResult, setResult.begin()));
    set_difference (mSet1.begin(), mSet1.end(), mSet2.begin(), mSet2.end(), inserter(mSetResult, mSetResult.begin()));

    cout << "Difference of set1 and set2: ";
    for (iteratorSet = setResult.begin(); iteratorSet != setResult.end(); ++iteratorSet) {
        cout << *iteratorSet << " ";
    }
    cout << endl;

    cout << "Difference of multiset1 and multiset2: ";
    for (iteratorMultiset = mSetResult.begin(); iteratorMultiset != mSetResult.end(); ++iteratorMultiset) {
        cout << *iteratorMultiset << " ";
    }
    cout << endl;
}

void include(set<int> set1, set<int> set2, multiset<int> mSet1, multiset<int> mSet2) {
    if ( includes(set1.begin(), set1.end(), set2.begin(), set2.end()) ) {
        cout << "Set1 contains set2" << endl;
    } else {
        cout << "Set1 doesn't contain set2" << endl;
    }

    if ( includes(mSet1.begin(), mSet1.end(), mSet2.begin(), mSet2.end()) ) {
        cout << "mSet1 contains mSet2" << endl;
    } else {
        cout << "mSet1 doesn't contain mSet2" << endl;
    }
}

int main()
{
    set<int> set1;
    set<int> set2;
    set<int> setResult;
    multiset<int> mSet1;
    multiset<int> mSet2;
    multiset<int> mSetResult;

    enterSetMultiset(set1, mSet1, "set1", "mSet1");
    enterSetMultiset(set2, mSet2, "set2", "mSet2");

    //include
    include(set1, set2, mSet1, mSet2);

    //intersection
    intersect(set1, set2, setResult, mSet1, mSet2, mSetResult);
    setResult.clear();
    mSetResult.clear();

    //union
    findUnion(set1, set2, setResult, mSet1, mSet2, mSetResult);
    setResult.clear();
    mSetResult.clear();

    //difference
    findDifference(set1, set2, setResult, mSet1, mSet2, mSetResult);
    setResult.clear();
    mSetResult.clear();

    return 0;
}