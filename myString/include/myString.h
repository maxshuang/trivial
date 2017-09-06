/*
 * myString.h
 *
 *  Created on: 2017年9月5日
 *      Author: maxshuang
 */

#ifndef MYSTRING_H_
#define MYSTRING_H_

#include <stdio.h>
#include <string>
#include <exception>
#include <iostream>
#include <iomanip>

#define size_t int

//need to do some meaningful thing
void new_fail_func()
{
	std::cerr<<"new fail!! Not Enough Mem in Heap! Exit!"<<std::endl;
	exit(0);
}


std::set_new_handler(new_fail_func);

namespace myString_n
{

class outOfIndex_error:public std::exception
{
public:
	explicit outOfIndex_error(const std::string& e_what){this->e_what=e_what;};
	explicit outOfIndex_error(const char* e_what){this->e_what(e_what);};
public:
	const char* what()const{return e_what.c_str();};
private:
	std::string e_what;
};




class myString
{
	//input and output
	friend std::ostream& operator<< (std::ostream& out,const myString& str);
	friend std::istream& operator>> (std::istream& in,const myString& str);
public:
	//ctor and dtor
	explicit myString(const char* str=NULL);
	explicit myString(const myString&);   //copy ctor
	~myString(){
		if(m_var!=NULL&&capacity!=0)
		{
			delete[] m_var;
			m_var=NULL;
			capacity=0;
		}
	};

public:
	size_t size()const{ return strlen(m_var);};
	bool empty()const{return size()?true:false;};

public:
	//operator overload:=,+,==,[]
	myString& operator=(const myString& str); //assignment
	//char operator[](int)throw(outOfIndex_error);
	char operator[](int)const;
	myString operator+(const myString& str);
	myString operator+(const char* str);
	myString& operator+=(const char* str);
	myString& operator+=(const myString& str);
	bool operator==(const myString& str)const;
private:
	char* m_var;
	int capacity;
};

}

#endif /* MYSTRING_H_ */
