#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

template<class t>
class DynamicArray 
{
public:
  DynamicArray();
  ~DynamicArray();
  void addEntry(t newEntry);
  t getEntry(int index);
  int getSize();

private:
  t *dynamicArray;
  int size;
};

template<class t>
DynamicArray<t>::DynamicArray()
{
  dynamicArray = nullptr;
  size = 0;
}

template<class t>
DynamicArray<t>::~DynamicArray()
{
  if (dynamicArray != nullptr)
    delete[] dynamicArray;
}

template<class t>
int DynamicArray<t>::getSize()
{
  return size;
}

// Adds an entry to the dynamic array.
template<class t> 
void DynamicArray<t>::addEntry(t newEntry)
{
    // Create a new array, copy the contents of the old array, then delete it
    t *newArray = new t[size + 1];
    for (int i = 0; i < size; i++)
    {
    newArray[i] = dynamicArray[i];
    }
    
    delete[] dynamicArray;
    
    dynamicArray = newArray;
    
    // Add the new entry and increment the size
    newArray[size++] = newEntry;
}



// Retrieve the element at a given index
template<class t>
t DynamicArray<t>::getEntry(int index)
{
  if ((index < 0) || (index >= size)){
    cout << "Out of the index !" << endl;
    return 0;

  }
  return dynamicArray[index];
}


int main()
{
  /*
  DynamicArray<int> x;
  
  // Adding entries
  x.addEntry(1);
  x.addEntry(3);
  x.addEntry(5);
  x.addEntry(9);
  x.addEntry(2);

  // Output entries
  cout << "List:" << endl;
  
  for (int i = 0; i < x.getSize(); i++)
    cout << x.getEntry(i) << endl;
  */

  DynamicArray<string> x;

  // Adding entries
  x.addEntry("Frank");
  x.addEntry("Wiggum");
  x.addEntry("Nahasapeemapetilon");
  x.addEntry("Quimby");
  x.addEntry("Flanders");

  // Output entries
  cout << "List:" << endl;
  
  for (int i = 0; i < x.getSize(); i++)
    cout << x.getEntry(i) << endl;
  
  return 0;
}

