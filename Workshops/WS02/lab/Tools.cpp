/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 24 Jan 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "Tools.h"
#include "Package.h"
//#define filename_r "Filtered_Dataset.csv"

FILE* fp;

namespace sdds {
    int openFile_r(const char filename[]) { // Fully provided
        fp = fopen(filename_r, "r");
        return fp != NULL;
    }
    int noOfTraces() {  // Fully provided
        int noOfTraces = 0;
        char ch;
        while (fscanf(fp, "%c", &ch) == 1) {
            noOfTraces += (ch == '\n');
        }
        rewind(fp);
        return noOfTraces;
    }

    //"%[ ^\t\n\r\v\f,]%*c,%d,%lf,%d,%d,%d,%60[^\n]\n" ??
    // To Do: read functions (4 overloaded read functions)
    int read(char* pkgName) {
        return fscanf(fp, "%60[^\n]\n", pkgName); //60???? read %s upto \n skip the \n (this is the last col)
    }

    int read(int& intType) {
        return fscanf(fp, "%d,", &intType); 
    }

    int read(double& timeInHours) {
        return fscanf(fp, "%lf,", &timeInHours);
    }

    int read(char& dayOfWeek) {
        return fscanf(fp, "%[^ \t\n\r\v\f,]%*c,", &dayOfWeek); //space!!!!!
    }
    // \t tab \n newline \r carrage return \v vertical tab \f newline+space

    

    void closefile() { // Fully provided
        if (fp) fclose(fp);
    }
    
    void strCpy(char* str1, const char* str2) { // Fully provided 
        while (*str2) {
            *str1++ = *str2++;
        }
        *str1 = 0;
    }
    int strLen(const char* str) {  // Fully provided
        int i = -1;
        while (str[++i]);
        return i;
    }
}