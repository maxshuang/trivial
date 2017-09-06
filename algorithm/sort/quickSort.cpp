/*
 * quickSort.cpp
 *
 *  Created on: 2017骞�9鏈�6鏃�
 *      Author: maxshuang
 */

#include<stdio.h>
#include <iostream>
using namespace std;
#include"quickSort.h"
#include"common.h"



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










