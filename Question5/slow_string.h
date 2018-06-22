/*
 */

/* 
 * File:   slow_string.h
 * Author: Jack L. Clements
 *
 * Created on 17 June 2018, 16:31
 */
#ifndef SLOW_STRING_H
#define SLOW_STRING_H

#include <cstddef>
#include <iostream>

static const size_t npos = -1; //no matches for search operations

class slow_string {
private:
    char *data;
public:
    
    //constructors
    slow_string();
    slow_string(char* data);
    slow_string(const slow_string &str);
    ~slow_string();
    
    size_t size() const;
    size_t copy(const char* str, size_t len, size_t pos = 0) const; 
    size_t find(const slow_string& str, size_t pos = 0); 
    size_t find(const char* str, size_t pos, size_t len);//pos is position, does not default here as length is given too
    size_t find(const char c, size_t pos = 0);
    slow_string substr(size_t pos, size_t len); 
    int compare(const slow_string& str);
    int compare(const char* str);
    char at(int i);
    char* c_str() const;

    //overloaded operators
    void operator += (slow_string& rhs);
    slow_string operator + (slow_string& rhs);
    char operator [] (int i); //access
    friend std::ostream & operator << (std::ostream& os, const slow_string& str);
};


#endif /* SLOW_STRING_H */

