#pragma once

//========== ��r�L�[�̃C���^�t�F�[�X ==========
template <typename DataType>
class IComparator
{
public:
	/*********************************************************
	* @brief	DataType�^�̑Ώۂ���r����B
	* return	left��Ȃ�right�̏ꍇ1��Ԃ��A
	*			left���Ȃ�right�̏ꍇ-1��Ԃ��A
	*			left�C�R�[��right�̏ꍇ0��Ԃ��B
	********************************************************/
	virtual int Compare(DataType& left, DataType& right) = 0;
};

