/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 7-August-2023
I have done all the coding by myself and only copied the code that my 
professor provided to complete my workshops and assignments.
***********************************************************************/
#pragma once
#include <iostream>
#include "Collection.h"
using namespace std;
namespace sdds {
	/// <summary>
	/// search receives a collection of type Collection<T>, an array of type T*, an array length , and a key of type K. It searches the array for occurrences of the key and adds the found elements to the given collection.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// Must support comparison using the equality operator 
	/// The elements should be assignable to the collection using add method
	/// 
	/// <typeparam name="K"></typeparam>
	/// Must support comparison using the equality operator
	/// 
	/// <param name="collection"></param>
	/// class Collection should have a method add that takes an object of type T and adds it to the collection
	///  collection's type T should match the type of the array elements
	template <typename T, typename K>
	bool search(Collection<T>& collection, const T* templatedArr, size_t arrLength, const K& key){
		bool check{};
		for (size_t i = 0; i < arrLength; i++)
		{
			if (templatedArr[i] == key) {
				collection.add(templatedArr[i]);
				check++; // if check is false it should become true, if it is true it shouldn't change
			}
		}
		return check;
	}

	/// <summary>
	/// prints the elements of an array along with their indices and a title
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// Must support the insertion operator
	/// 
	/// <returns></returns>
	/// returns a reference to the ostream object
	template <typename T>
	ostream& listArrayElements(const char* title, const T* templatedArr, size_t arrLength) {
		cout << title << endl;

		for (size_t i = 0; i < arrLength; i++)
		{
			cout << i + 1 << ": " << templatedArr[i] << endl;
		}

		return cout;
	}
		
}
