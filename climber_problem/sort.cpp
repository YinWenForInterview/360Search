#include "sort.h"
#include <stdlib.h>

/*插入排序*/
void InsertionSort(ElementType A[], int N)
{
	int i,j;
	ElementType temp;

	for(i=1; i<N; i++)
	{
		temp = A[i];

		for(j=i; j>0; j--)
		{
			if(temp.left <A[j-1].left)
				A[j] = A[j-1];
			else
				break;
		}
		A[j] = temp;
	}
}




/*快速排序*/
void Swap(ElementType *A, ElementType *B)
{
	ElementType temp;
	temp = *A;
	*A = *B;
	*B = temp;
}

ElementType Median3(ElementType A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;

	/*从左到右，从小到大排列*/
	if(A[Left].left > A[Center].left)
		Swap(&A[Left], &A[Center]);
	if(A[Left].left > A[Right].left)
		Swap(&A[Left], &A[Right]);
	if(A[Center].left > A[Right].left)
		Swap(&A[Center], &A[Right]);

	Swap(&A[Center], &A[Right-1]);
	return A[Right-1];
}

#define Cutoff (3)

void Qsort(ElementType A[], int Left, int Right)
{
	int i,j;
	ElementType Pivot;
	
	Pivot = Median3(A, Left, Right);

	if(Left + Cutoff <Right)
	{
		i = Left;
		j = Right-1;
		while(1)
		{
			while(A[++i].left < Pivot.left);
			while(A[--j].left > Pivot.left);
			if(i < j)
				Swap(&A[i], &A[j]);
			else
				break;
		}
		/*将枢纽元放回中间,此时枢纽元左边的数据都比它小
		右边的数据都比它大，再对左右数据排序即可*/
		Swap(&A[i], &A[Right-1]);

		Qsort(A, Left, i-1);
		Qsort(A, i+1, Right);
	}
	else
		/*少于4个数据就直接使用插入排序更快*/
		InsertionSort(A+Left, Right-Left+1);
}

void QuickSort(ElementType A[], int N)
{
	if(N>4)
		Qsort(A, 0, N-1);
	else
		InsertionSort(A, N);
}

