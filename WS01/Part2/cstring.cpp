/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 19-May-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "cstring.h"

namespace sdds{
	void strCpy(char* des, const char* src) {
		for (int i = 0; i < 80; i++)
			des[i] = '\0';
		strnCpy(des, src, strLen(src));
	}
	void strnCpy(char* des, const char* src, int len) {
		int i = 0;

		if(des[0] == -52)
			for (i = 0; i < 80 + 1; i++) des[i] = '\0';
		
		for (i = 0; i < len && src[i] != '\0'; i++)
			des[i] = src[i];

		if (i < len)
			des[i] = '\0';
	}
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

		while(check != 0 && i < str1Sz){
			i++;
			check = strnCmp(&str1[i], str2, str2Sz);
		}

		if (!check)
			foundCharAddress = &str1[i];

		return foundCharAddress;
	}
	void strCat(char* des, const char* src) {
		int i = strLen(des), j = 0;
		while (j < strLen(src)){
			des[i] = src[j];
			i++; j++;
		}
	}
}
