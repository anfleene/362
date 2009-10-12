#include "utility.h"

#ifndef LIST_H
#define LIST_H

//header file LIST.H for class List.
//An array-based implementation.
//Because this is a template class,
//both interface and implementation
//are in the header file

const int max_list = 1000;

template <class List_entry>
class List {
public:
// methods of the List ADT
   List();
   //constructor
   //postcondition: empty list has been created

   int size() const;
   //postcondition:  returns number of entries in list

   bool full() const;
   //postcondition: function returns true or false according
   //to whether list is full or not

   bool empty() const;
   //postcondition: function returns true or false according
   //to whether list is empty or not

   void clear();
   //postcondition: all list entries have been removed,
   //list is now empty

   void traverse(void (*visit)(List_entry &));
   //postcondition: the action specified by function
   //*visit has been performed on every entry of the
   //list from position 0 on.

   Error_code retrieve(int position, List_entry &x) const;
   //postcondition:  if 0 <= position < n, where n is
   //number of entries in list, then function succeeds,
   //entry at position is copied to x, 
   //else function fails with error code
   
   Error_code replace(int position, const List_entry &x);
   //postcondition: if 0 <= position < n, where n is
   //number of entries in list, then function succeeds,
   //entry at position is replaced by x,
   //else function fails with error code  

   Error_code remove(int position, List_entry &x);
   //postcondition: if 0 <= position < n, where n is
   //number of entries in list, then function succeeds,
   //entry at position is copied to x and then 
   //removed from list and all later
   //entries have their position number reduced by 1, 
   //else function fails with error code

   Error_code insert(int position, const List_entry &x);
   //postcondition: if the list is not full and 
   //0 <= position <= n, where n is
   //number of entries in list, then function succeeds, 
   //entries at position and later all have their
   //position numbers increased by 1 and x becomes
   //the entry at position,  
   //else function fails with error code

   Error_code sequential_search(const List_entry &target, int &position);
   //postcondition: if an entry in the list equals target, then return
   //success and the position in the list where target was found
   //else return not_present and position becomes invalid.

protected:
//  data members for a contiguous list implementation
   int count;
   List_entry entry[max_list];
};
#endif //LIST_H


//implementation for class List
//an array-based implementation

template <class List_entry>
List<List_entry>::List()
//constructor
//postcondition: empty list has been created
{
	this->count = 0;
}

template <class List_entry>
int List<List_entry>::size() const
//postcondition:  returns number of entries in list
{
   return count;
}

template <class List_entry>
bool List<List_entry>::full() const
//postcondition: function returns true or false according
//to whether list is full or not
{
	return (count == max_list);
}

template <class List_entry>
bool List<List_entry>::empty() const
//postcondition: function returns true or false according
//to whether list is empty or not
{
	return (count == 0);
}

template <class List_entry>
void List<List_entry>::clear()
//postcondition: all list entries have been removed,
//list is now empty
{
	count = 0;
}

template <class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry &))
//postcondition: the action specified by function
//*visit has been performed on every entry of the
//list from position 0 on.
{
   for (int i = 0; i < count; i++)
      (*visit)(entry[i]);
}

template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const
//postcondition:  if 0 <= position < n, where n is
//number of entries in list, then function succeeds,
//entry at position is copied to x, 
//else function fails with error code
{
	if (empty())
		return underflow;

	if (position < 0 || position >= count)
		return exceeds_range;

	x = entry[position];
	return success;
}

template <class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x)
//postcondition: if 0 <= position < n, where n is
//number of entries in list, then function succeeds,
//entry at position is replaced by x,
//else function fails with error code 
{
	if (empty())
		return underflow;

	if (position < 0 || position >= count)
		return exceeds_range;

	entry[position] = x;
	return success;
}


template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x)
//postcondition: if 0 <= position < n, where n is
//number of entries in list, then function succeeds,
//entry at position is copied to x and then 
//removed from list and all later
//entries have their position number reduced by 1, 
//else function fails with error code
{
	if (empty())
		return underflow;

	if (position < 0 || position >= count)
		return exceeds_range;

	x = entry[position];
	for (int i = position + 1; i < count; i++)
		entry[i - 1] = entry[i];
	count--;
	return success;
}

template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x)
//postcondition: if the list is not full and 
//0 <= position <= n, where n is
//number of entries in list, then function succeeds, 
//entries at position and later all have their
//position numbers increased by 1 and x becomes
//the entry at position,  
//else function fails with error code
{
   if (full())
      return overflow;

   if (position < 0 || position > count)
      return exceeds_range;

   for (int i = count - 1; i >= position; i--)
      entry[i + 1] = entry[i];

   entry[position] = x;
   count++;
   return success;
}

template <class List_entry>
Error_code List<List_entry>::sequential_search(const List_entry &target, int &position)
//postcondition: if an entry in the list equals target, then return
//success and the position in the list where target was found
//else return not_present and position becomes invalid.
{
	int s = size();
	for (position = 0; position < s; position ++)
	{
		List_entry data;
		retrieve(position, data);
		if (data == target) return success;
	}
	return not_present;
}
