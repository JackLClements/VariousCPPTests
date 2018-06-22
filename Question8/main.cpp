/*
 */

/* 
 * File:   main.cpp
 * Author: Jack L. Clements
 *
 * Created on 21 June 2018, 12:24
 */

#include <cstdlib>
#include <iostream>

using namespace std;

template <class T, class U>
struct Typelist {
    typedef T Head;
    typedef U Tail;
};

class NullType {
};

typedef Typelist<int, Typelist<float, Typelist<char*, NullType> > > UsableTypes1;
typedef Typelist<short, Typelist<string, NullType> > UsableTypes2;

template <typename T> class MyClass {
public:
    void print(T);
};

template <> class MyClass <UsableTypes1> {
private:
    int int_val;
    float float_val;
    const char* char_val;
public:
    
    template<typename T> void print(T) = delete; //force compiler error so no short->int conversion can implicitly take place

    void print(int value) {
        int_val = value;
        cout << "int - " << value << endl;
    }

    void print(float value) {
        float_val = value;
        cout << "float - " << value << endl;
    }

    void print(const char* value) {
        char_val = value;
        cout << "char* - " << value << endl;
    }
};

template <> class MyClass <UsableTypes2> {
private:
    short short_val;
    string string_val;
public:
    
    template<typename T> void print(T) = delete; //force compiler error so no int->short conversion can implicitly take place
    
    void print(short value) {
        short_val = value;
        cout << "short - " << value << endl;
    }

    void print(string value) {
        string_val = value;
        cout << "string - " << value << endl;
    }
};



MyClass<UsableTypes1> hogehoge;
MyClass<UsableTypes2> blhablha;

void TestMyClass() {
    int int_val = 0;
    float flt_val = 0.1f;
    const char* char_val = "Hi";
    short short_val = 10;
    string str_val = "Hello";

    hogehoge.print(int_val); // OK
    hogehoge.print(flt_val); // OK
    hogehoge.print(char_val); // OK
    //hogehoge.print( short_val); // compile error
    //hogehoge.print( str_val ); // compile error

    //blhablha.print( int_val ); // compile error
    //blhablha.print( flt_val ); // compile error
    //blhablha.print( char_val ); // compile error
    blhablha.print(short_val); // OK
    blhablha.print(str_val); // OK
}

int main(int argc, char** argv) {
    TestMyClass();
    return 0;
}

