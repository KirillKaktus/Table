#pragma once
#include "THashTable.h"
class TArrayHashTable:public THashTable //������� � ��������� ������������
{
protected:
	TRecord* pRecs;
	int MaxSize, Step, Curr, Free;
	TRecord Empty, Del;
public:
	TArrayHashTable(int _MaxSize,int _Step)	
	{
		Step = _Step;
		MaxSize = _MaxSize;
		pRecs = new TRecord[MaxSize];
		Empty.key = -1;
		Empty.val = '0';
		Del.key = -2;
		Del.val = '0';
		for (int i = 0; i < MaxSize; i++)
		{
			pRecs[i] = Empty;
		}
	}
	~TArrayHashTable()
	{
		delete pRecs;
	}
	void Reset()
	{
		for (Curr = 0; Curr < MaxSize; Curr++)
		{
			if (pRecs[Curr] != Empty && pRecs[Curr] != Del)
				break;
		}
	}
	bool IsEnd()
	{
		if (Curr == MaxSize) return true;
	}
	void GoNext()
	{
		for (; Curr < MaxSize; Curr++)
		{
			if (pRecs[Curr] != Empty && pRecs[Curr] != Del)
				break;
		}
	}
	bool Find(Tkey key)
	{
		Free = -1;
		Curr = HashFunc(Tkey key) % MaxSize;

	}
};
