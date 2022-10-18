#pragma once
#include "IComparator.h"
#include "ScoreData.h"

//========== ���уf�[�^�̖��O�̔�r�L�[ ==========
/*********************************************************
* @brief	���уf�[�^�̖��O�̔�r�L�[
********************************************************/
class CompareScoreData_Name :
    public IComparator<ScoreData>
{
public:
	/*********************************************************
	* @brief	���ScoreData�̑Ώۂ��A�����o�[�ϐ�score�ɂ���r����B
	* return	left��Ȃ�right�̏ꍇ1��Ԃ��A
	*			left���Ȃ�right�̏ꍇ-1��Ԃ��A
	*			left�C�R�[��right�̏ꍇ0��Ԃ��B
	********************************************************/
    int Compare(ScoreData& left, ScoreData& right)override;
};

//========== ���уf�[�^�̃X�R�A�̔�r�L�[ ==========
/*********************************************************
* @brief	���уf�[�^�̃X�R�A�̔�r�L�[
********************************************************/
class CompareScoreData_Score :
    public IComparator<ScoreData>
{
public:
	/*********************************************************
	* @brief	���ScoreData�̑Ώۂ��A�����o�[�ϐ�name�ɂ���r����B
	*			������Aname�̃A���t�@�x�b�g���ׂ�i�啶���������֌W�Ȃ��j�A
	*			�A���t�@�x�b�g���Ŕ��f�ł��Ȃ��ꍇ�Aname�̌����Ŕ�r����B
	* return	left��Ȃ�right�̏ꍇ1��Ԃ��A
	*			left���Ȃ�right�̏ꍇ-1��Ԃ��A
	*			left�C�R�[��right�̏ꍇ0��Ԃ��B
	********************************************************/
    int Compare(ScoreData& left, ScoreData& right)override;
};

