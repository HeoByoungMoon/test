// HW 3
// Name :
// Student ID :

#include "hw3.h"


template <class T>
void  QuickSort<T>::Swap(int i, int j)
{
	int temp;
	temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;


}


template <class T>
void  QuickSort<T>::QSort(int s, int e)
{	
	// sort arr[s:e] into nonincreasing order
	cout << "Sort in [" << s << "," << e << "]" << endl;
	Show(s, e);


	if(s >= e)
		return;

	if( (e-s)==1 )
	{
		if(arr[e]>arr[s])
		{
			Swap(s,e);

			
			QSort(s,s);
			QSort(e+1, e);
			return;
		}
		QSort(s,s-1);
		QSort(e, e);
		return;
	}

	// Implement at the following....

	int left,middle,right;
	int pivot;
	int mp,pp;

	//if( (s+e) %2==1)
	//{ mp=(s+e)/2  +1;
	//}
	
	 mp=(s+e)/2;
	
	
	left=arr[s];
	middle=arr[mp];
	right=arr[e];
	if(left>=middle)
	{
		if(middle>=right)
		{
			pivot=middle;
			pp=mp;
		}
		else
		{
			if(left>=right)
			{
				pivot=right;
				pp=e;
			}
			else
			{
				pivot=left;
				pp=s;
			}
		}
	}
	else
	{
		if(middle>=right)
		{
			if(left>=right)
			{
				pivot=left;
				pp=s;
			}
			else
			{
				pivot=right;
				pp=e;
			}
		}
		else
		{
			pivot=middle;
			pp=mp;
		}

	}
	
	
	int temp;
	int tp;

	temp=arr[s];
	arr[s]=pivot;
	arr[pp]=temp;

	int i=s+1;
	int j=e;

	while(i<j)
	{
		if(arr[i]<=pivot)
		{
			if(arr[j]>=pivot)
			{
				temp=arr[j];

				arr[j]=arr[i];
				arr[i]=temp;
				i++;
			}
			j--;
			continue;
		}
		i++;
	}

	while(i>s)
	{
		if(pivot<=arr[i])
		{
			Swap(i,s);
			temp=i;
			break;
		}
		i--;
	}
	QSort(s,temp-1);
	QSort(temp+1,e);


	return;

}


// DO NOT REMOVE THE FOLLOWING LINE
template class QuickSort<int>;


