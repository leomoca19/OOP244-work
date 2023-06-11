/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 19-May-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

I did research and I found that #pragma once serves the serve purpose as
the safe guards, I am using this approach since it requires less coding

my sources are wikipedia and microsoft

https://en.wikipedia.org/wiki/Pragma_once: "...#pragma once serves the
same purpose as include guards, but with several advantages, including:
less code, avoidance of name clashes, and sometimes improvement in
compilation speed..."

https://learn.microsoft.com/en-us/cpp/preprocessor/once?view=msvc-170:
"...has an effect similar to the include guard idiom, which uses
preprocessor macro definitions to prevent multiple inclusions of the
contents of the file. It also helps to prevent violations of the one
definition rule"
***********************************************************************/
#pragma once
namespace sdds {
    // Copies the srouce character string into the destination
    void strCpy(char* des, const char* src);

    // Copies the source character string into the destination upto "len"
    // characters. The destination will be null terminated only if the number
    // of the characters copied is less than "len"
    void strnCpy(char* des, const char* src, int len);

    // Compares two C-strings 
    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strCmp(const char* s1, const char* s2);

    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strnCmp(const char* s1, const char* s2, int len);

    // returns the lenght of the C-string in characters
    int strLen(const char* s);

    // returns the address of first occurance of "str2" in "str1"
    // returns nullptr if no match is found
    const char* strStr(const char* str1, const char* str2);

    // Concantinates "src" C-string to the end of "des"
    void strCat(char* des, const char* src);

}