#include <iostream>
#include "CompareScoreData.h"


//========== 成績データの名前の比較キー ==========
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

//========== 成績データのスコアの比較キー ==========
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
