/*
 * quickSort.cpp
 *
 *  Created on: 2017年9月6日
 *      Author: maxshuang
 */

#include<stdio.h>
#include <iostream>
using namespace std;

void QuickSort(int* a,int start,int end);
void QuickSort(int* a,int n);
void swap(int*a,int*b);
int partition(int* a,int start,int end);
void Print(int* a,int n);


void QuickSort(int* a,int start,int end)
{
	if(start>=end)
		return;
	int mid=partition(a,start,end);
	QuickSort(a,start,mid);
	QuickSort(a,mid+1,end);
}

void QuickSort(int* a,int n)
{
	QuickSort(a,0,n-1);
}


void swap(int*a,int*b)
{
	int tmp=*b;
	*b=*a;
	*a=tmp;
}

int partition(int* a,int start,int end)
{

		int st=start;
		int en=end;
		int tmp=a[start];
		while(st!=en)
		{
			while(st!=en&&a[en]>=tmp) --en;
			swap(a+st,a+en);
			while(st!=en&&a[st]<=tmp) ++st;
			swap(a+st,a+en);
		}
		Print(a,10);
		return st;
}





void Print(int* a,int n)
{
	for(int i=0;i<n;++i)
		cout<<a[i]<<"\t";
	cout<<endl;
}


int main()
{
	int a[10]={1,5,3,4,7,9,2,8,0,6};
	QuickSort(a,10);
	//Print(a,10);
	int b[10]={1,5,3,9,7,9,2,8,0,6};
	QuickSort(b,10);
	return 0;
}


