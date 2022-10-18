#include <iostream>
#include "CompareScoreData.h"


//========== ���уf�[�^�̖��O�̔�r�L�[ ==========
int CompareScoreData_Name::Compare(ScoreData& left, ScoreData& right)
{
	int cmp = 0;

	if (left.name > right.name)
	{
		cmp = 1;
	}
	else if (left.name < right.name)
	{
		cmp = -1;
	}
	else if (left.name == right.name)
	{
		cmp = 0;
	}

	return cmp;
}

//========== ���уf�[�^�̃X�R�A�̔�r�L�[ ==========
int CompareScoreData_Score::Compare(ScoreData& left, ScoreData& right)
{
	int cmp = 0;
	
	//test
	//std::cout << "compare score:  ";
	//std::cout << left.score << " to " << right.score << std::endl;

	if (left.score > right.score)
	{
		cmp = 1;
	}
	else if (left.score < right.score)
	{
		cmp = -1;
	}
	else if (left.score == right.score)
	{
		cmp = 0;
	}

	return cmp;
}
