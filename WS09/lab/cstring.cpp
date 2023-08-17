/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 25-May-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "cstring.h"

namespace sdds {
	//This is a more powerful solution than my previous one
	//By passing strLen(src) + 1 instead of strLen(src), the call of 
	// strnCpy will now work as expected copying the whole content of
	// source includying '\0'
	void strCpy(char* des, const char* src) {
		strnCpy(des, src, strLen(src) + 1);
	}
	//Neither of these functions have to deal with the destination 
	// sources being populated with garbage values since the '\0' will 
	// be placed properly, all just by adding + 1 to strLen(src) when 
	// passed as the 3rd argument
	//Using *des and *src instead of the classic src[i] reduces the 
	// amount of keystrokes required to write the function, using the ++
	// operators keeps track of the next index to be used and reduces the
	// brain bloat, and the ++ operations are stacked in the same line 
	// for simplicity
	void strnCpy(char* des, const char* src, int len) {
		int i = 0;
		while (i < len) {
			*des = *src;
			++des; ++src; i++;
		}
		if (i < len)
			*des = '\0';
	}
	///////////////////////////////////////////////////////////////////
	int strCmp(const char* s1, const char* s2) {
		return strnCmp(s1, s2, strLen(s1));
	}
	int strnCmp(const char* s1, const char* s2, int len) {
		int check = 0, i = 0;

		while (i < len && check == 0) {
			if (s1[i] > s2[i])
				check = 1;
			else if (s1[i] < s2[i])
				check = -1;
			i++;
		}

		return check;
	}
	int strLen(const char* s) {
		int i = 0;
		while (s[i] != '\0') i++;
		return i;
	}
	const char* strStr(const char* str1, const char* str2) {
		int str1Sz = strLen(str1), str2Sz = strLen(str2), i = -1, check = 1;
		const char* foundCharAddress = nullptr;

		while (check != 0 && i < str1Sz) {
			i++;
			check = strnCmp(&str1[i], str2, str2Sz);
		}

		if (!check)
			foundCharAddress = &str1[i];

		return foundCharAddress;
	}
	void strCat(char* des, const char* src) {
		int i = strLen(des), j = 0;
		while (j < strLen(src)) {
			des[i] = src[j];
			i++; j++;
		}
	}
}
