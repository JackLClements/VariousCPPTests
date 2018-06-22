#include "slow_string.h"
#include <cstring>

slow_string::slow_string() {
    *data = '\0'; //should null terminate the str, not perfect but works
}

slow_string::slow_string(char* data) {
    this->data = data;
}

slow_string::slow_string(const slow_string& str) {
    str.copy(data, str.size());
}

slow_string::~slow_string() {
}

size_t slow_string::size() const {
    return strlen(data);
}

size_t slow_string::copy(const char* str, size_t len, size_t pos) const{
    strncpy(data, str, pos + len); //no need to assign return value as data should be overwritten
    data[pos + len] = '\0';
    return len;
}

size_t slow_string::find(const slow_string& str, size_t pos) {
    return find(str.c_str(), pos, str.size());
}

size_t slow_string::find(const char* str, size_t pos, size_t len) {
    char* strPointer;
    strncpy(strPointer, str, len);
    strPointer[len] = '\0';
    char* indexPointer = strstr(data + (sizeof (char)*pos), strPointer);
    if (indexPointer == NULL) {
        return npos;
    } else {
        return indexPointer - data;
    }
}

size_t slow_string::find(char c, size_t pos) {
    char* indexPointer = strchr(data + (sizeof (char)*pos), c);
    if (indexPointer == NULL) {
        return npos;
    } else {
        return indexPointer - data;
    }
}

slow_string slow_string::substr(size_t pos, size_t len) {
    char* substring;
    strncpy(substring, data + pos, len);
    substring[len] = '\0';
    return slow_string(substring);
}

int slow_string::compare(const slow_string& str) {
    return strcmp(data, str.c_str());
}

int slow_string::compare(const char* str) {
    return strcmp(data, str);
}

char slow_string::at(int i) {
    return data[i];
}

char* slow_string::c_str() const {
    return data;
}

void slow_string::operator+=(slow_string& rhs) {
    strcat(data, rhs.c_str());
}

slow_string slow_string::operator+(slow_string& rhs) {
    return slow_string(strcat(data, rhs.c_str()));
}

char slow_string::operator[](int i) {
    return data[i];
}

std::ostream& operator << (std::ostream& os, const slow_string& str){
    os << str.c_str();
    return os;
} 
