/*
 * myString.cpp
 *
 *  Created on: 2017年9月5日
 *      Author: maxshuang
 */

#include "myString.h"


#include <string.h>
#ifdef WIN32
#include<stdlib.h>

#else
#include<stddef.h>
#endif

#define NEED_LEN(X) (strlen(X)+1)

namespace myString_n
{

myString::myString(const char* str)
{
	if(str==NULL)
	{
		capacity=1;
		m_var=new char[capacity](0);
		return;
	}
	else
	{
		capacity=2*NEED_LEN(str);
		m_var=new char[capacity](0);
		strncpy(m_var,str,capacity);
	}
}

myString::myString(const myString& other)
{
	capacity=other.capacity;
	m_var=new char[capacity](0);
	strncpy(m_var,other.m_var,capacity);
}

myString& myString::operator=(const myString& other)
{
	if(this==&other)   //self assignment
		return *this;
	if(capacity<NEED_LEN(other.m_var))
	{
			capacity=other.capacity;
			delete[] m_var;
			m_var=new char[capacity](0);
			strncpy(m_var,other.m_var,capacity);
	}
	else
		strncpy(m_var,other.m_var,capacity);
	return *this;
}

/*char myString::operator[](int index) throw(outOfIndex_error)
{
	if(index<0||index>strlen(m_var))
		throw outOfIndex_error("out of index!!");
	else
		return m_var[index];
}*/

char myString::operator[](int index)const
{
	if(index<0)
		return m_var[0];
	else if(index>strlen(m_var))
		return m_var[strlen(m_var)-1];
	else
		return m_var[index];
}

myString myString::operator+(const char* other)
{
	myString newStr;
	newStr.capacity=(NEED_LEN(m_var)+NEED_LEN(other))*2;
	newStr.m_var=new char[newStr.capacity](0);
	strncpy(newStr.m_var,m_var,capacity);
	strncat(newStr.m_var,other,capacity);
	return newStr;
}


myString myString::operator+(const myString& other)
{
	myString tmp=*this+other.m_var;
	return tmp;
}

bool myString::operator==(const myString& other)const
{
	if(strlen(m_var)!=strlen(other.m_var))
		return false;
	return strcmp(m_var,other.m_var)==0?true:false;
}

myString& myString::operator+=(const char* str)
{
	int need=NEED_LEN(m_var)+NEED_LEN(str);
	if(need>capacity)
	{
		capacity=2*need;
		char* tmp=new char[capacity](0);
		strncpy(tmp,m_var,capacity);
		strncat(tmp,str,capacity);
		delete[] m_var;
		m_var=tmp;
	}
	else
		strncat(m_var,str,capacity);
	return *this;
}


myString& myString::operator+=(const myString& str)
{
	*this+=str.m_var;
	return *this;
}



friend std::ostream& operator<< (std::ostream& out,const myString& str)
{
	out<<str.m_var;
	return out;
}

friend std::istream& operator>> (std::istream& in,const myString& str)
{
	char inner[1024]={0};
	in>>std::setw(1024)>>inner;
	str(inner);
	return in;
}

}


