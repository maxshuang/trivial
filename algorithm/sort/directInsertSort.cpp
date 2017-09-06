/*
 * directInsertSort.cpp
 *
 *  Created on: 2017��9��6��
 *      Author: hgh
 */

#include"common.h"
#include"directInsertSort.h"

void directInsert(int* a,int n)
{
	//o(n^3),very low
	/*for(int i=1;i<n;i++)
	{
		int tmp=a[i];
		for(int j=0;j<i;j++)
		{
			if(tmp<a[j]) //move backward
			{
				for(int k=i;k>j;k--)
					a[k]=a[k-1];
				a[j]=tmp;
				break;
			}
		}
	}*/
	//merge move and find
	for(int i=1;i<n;i++)
	{
		if(a[i]<a[i-1])  //disorder
		{
			int tmp=a[i];
			int j=i-1;
			while(a[j]>tmp&&j>=0)   //a[0]
			{
				a[j+1]=a[j];
				--j;
			}
			a[j+1]=tmp;
		}
	}
	Print(a,n);
}


