#ifndef ORDERED_LIST_H
#define ORDERED_LIST_H

#include "list.h"

//header file ORDERED_LIST.H for class 
//Ordered_list.  This is a derived class
//from the array-based List class.
//Methods of insert and replace are redefined.

//Because this is a template class,
//both interface and implementation
//are in the header file


template <class List_entry>
class Ordered_list:public List<List_entry>
{

public: 
// methods of the Ordered_list ADT

   Ordered_list();
   //constructor
   //postcondition: empty list has been created

   Error_code insert(const List_entry &data);
   //Postcondition
   //If the Ordered_list is not full, the function succeeds:
   //The List_entry data is inserted into the list, following the
   //last entry of the list with a strictly lesser key (or in the
   //first list position if no list element has a lesser key).
   //Else: the function fails with the diagnostic Error_code overflow.
   
   
   Error_code insert(int position, const List_entry &data);
   //Postcondition:
	//If the Ordered_list is not full, 0 <= position <= n,
	//where n is the number of entries in the list,
	//and the List_entry data can be inserted at position in the list,
	//without disturbing the list order, then the function succeeds:
	//Any entry formerly in position and all later entries have their
	//position numbers increased by 1 and data is inserted at position
	//of the List.
	//Else: the function fails with a diagnostic Error_code.


   Error_code replace(int position, const List_entry &data);
   //Postcondition: if 0 <= position < n, where n is
   //number of entries in list, and the List_entry data can be 
   //placed at position in the list,
   //without disturbing the list order, then the function succeeds: 
   //Else: the function fails with a diagnostic Error_code.

	 Error_code short_sequential_search(const List_entry &target, int &position);
   //postcondition: if an entry in the list equals target, then return
   //success and the position in the list where target was found
   //else return not_present and position becomes invalid.

	 Error_code binary1(const List_entry &target, int &position);
   //postcondition: if an entry in the list equals target, then return
   //success and the position in the list where target was found
   //else return not_present and position becomes invalid.

	 Error_code binary2(const List_entry &target, int &position);
   //postcondition: if an entry in the list equals target, then return
   //success and the position in the list where target was found
   //else return not_present and position becomes invalid.

};
#endif //ORDERED_LIST_H

template <class List_entry>
Ordered_list<List_entry>::Ordered_list():List<List_entry>(){}
//constructor
//postcondition: empty list has been created


template <class List_entry>
Error_code Ordered_list<List_entry>::insert(const List_entry &data)
//Postcondition
//If the Ordered_list is not full, the function succeeds:
//The List_entry data is inserted into the list, following the
//last entry of the list with a strictly lesser key (or in the
//first list position if no list element has a lesser key).
//Else: the function fails with the diagnostic Error_code overflow.

{
   int s = this->count;
   int position;
   for (position = 0; position < s; position++) {
      List_entry list_data;
      retrieve(position, list_data);
      if (data <= list_data) break;
	  //above line of code is incorrectly written in text as
	  //if (data >= list_data)
   }
   return List<List_entry>::insert(position, data);
}

template <class List_entry>
Error_code Ordered_list<List_entry>::insert(int position, const List_entry &data)
//Postcondition:
//If the Ordered_list is not full, 0 <= position <= n,
//where n is the number of entries in the list,
//and the List_entry data can be inserted at position in the list,
//without disturbing the list order, then the function succeeds:
//Any entry formerly in position and all later entries have their
//position numbers increased by 1 and data is inserted at position
//of the List.
//Else: the function fails with a diagnostic Error_code.

{
   List_entry list_data;
   if (position > 0) {
      retrieve(position - 1, list_data);
      if (data < list_data)
         return fail;
   }
   if (position < this->count) {
      retrieve(position, list_data);
      if (data > list_data)
         return fail;
   }
   return List<List_entry>::insert(position, data);
}

template <class List_entry>
Error_code Ordered_list<List_entry>::replace(int position, const List_entry &data)
//Postcondition: if 0 <= position < n, where n is
//number of entries in list, and the List_entry data can be 
//placed at position in the list,
//without disturbing the list order, then the function succeeds: 
//Else: the function fails with a diagnostic Error_code.
{
   List_entry list_data;
   if (position > 0) {
      retrieve(position - 1, list_data);
      if (data < list_data)
         return fail;
   }
   if (position < (this->count - 1)) {
      retrieve(position + 1, list_data);
      if (data > list_data)
         return fail;
   }
   return List<List_entry>::replace(position, data);
}


template <class List_entry>
Error_code Ordered_list<List_entry>::binary1(const List_entry &target, int &position)
//postcondition: if an entry in the list equals target, then return
//success and the position in the list where target was found
//else return not_present and position becomes invalid.
{
	List_entry data;
	int bottom = 0, top = this->count - 1;
	while (bottom < top)
	{
		int mid = (bottom + top)/2;
		retrieve(mid, data);
		if (data < target)
				bottom = mid + 1;
		else
				top = mid;
	}

	if (top < bottom) return not_present;
	else 
	{
		position = bottom;
		retrieve(bottom, data);
		if (data == target) return success;
		else return not_present;
	}
}

template <class List_entry>
Error_code Ordered_list<List_entry>::binary2(const List_entry &target, int &position)
//postcondition: if an entry in the list equals target, then return
//success and the position in the list where target was found
//else return not_present and position becomes invalid.
{
	List_entry data;
	int bottom = 0, top = this->count - 1;
	while (bottom <= top)
	{
		position = (bottom + top)/2;
		retrieve(position, data);
		if (data == target) return success;
		if (data < target) bottom = position + 1;
		else top = position - 1;
	}
	return not_present;
	
}

template <class List_entry>
Error_code Ordered_list<List_entry>::short_sequential_search(const List_entry &target, int &position)
//postcondition: if an entry in the list equals target, then return
//success and the position in the list where target was found
//else return not_present and position becomes invalid.
{
	int s = this->count;
	for (position = 0; position < s; position ++)
	{
		List_entry data;
		retrieve(position, data);
		if (data == target) return success;
		if(data > target) return not_present;
	}
	return not_present;
}

