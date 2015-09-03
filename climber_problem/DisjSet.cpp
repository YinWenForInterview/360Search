/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/8/15
description:���ཻ��
********************************************/

#include "DisjSet.h"
#include <cstdlib>
#include <iostream>


/*���߶��󲢣���ʼ��Ϊ�߶�1�ø�����ʾ*/
void initialize(DisjSet S)
{
	int i;
	for(i=0; i<NumSets; i++)
		S[i] = -1;
}


void SetUnion(DisjSet S, SetType root1, SetType root2)
{
	if(S[root1] < S[root2])
		S[root2] = root1;
	else
	{
		S[root1] = root2;
	}
}


/*·��ѹ��*/
SetType Find(ElementType X, DisjSet S)
{
	if(S[X] <= 0)
		return X;
	else
		return S[X] = Find(S[X], S);
}

