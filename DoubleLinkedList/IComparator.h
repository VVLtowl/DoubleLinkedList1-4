#pragma once

//========== 比較キーのインタフェース ==========
template <typename DataType>
class IComparator
{
public:
	/*********************************************************
	* @brief	DataType型の対象を二つ比較する。
	* return	left大なりrightの場合1を返す、
	*			left小なりrightの場合-1を返す、
	*			leftイコールrightの場合0を返す。
	********************************************************/
	virtual int Compare(DataType& left, DataType& right) = 0;
};

