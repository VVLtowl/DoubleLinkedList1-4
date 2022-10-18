#pragma once
#include "IComparator.h"
#include "ScoreData.h"

//========== 成績データの名前の比較キー ==========
/*********************************************************
* @brief	成績データの名前の比較キー
********************************************************/
class CompareScoreData_Name :
    public IComparator<ScoreData>
{
public:
	/*********************************************************
	* @brief	二つのScoreDataの対象を、メンバー変数scoreにより比較する。
	* return	left大なりrightの場合1を返す、
	*			left小なりrightの場合-1を返す、
	*			leftイコールrightの場合0を返す。
	********************************************************/
    int Compare(ScoreData& left, ScoreData& right)override;
};

//========== 成績データのスコアの比較キー ==========
/*********************************************************
* @brief	成績データのスコアの比較キー
********************************************************/
class CompareScoreData_Score :
    public IComparator<ScoreData>
{
public:
	/*********************************************************
	* @brief	二つのScoreDataの対象を、メンバー変数nameにより比較する。
	*			左から、nameのアルファベットを比べる（大文字小文字関係なし）、
	*			アルファベット順で判断できない場合、nameの桁数で比較する。
	* return	left大なりrightの場合1を返す、
	*			left小なりrightの場合-1を返す、
	*			leftイコールrightの場合0を返す。
	********************************************************/
    int Compare(ScoreData& left, ScoreData& right)override;
};

