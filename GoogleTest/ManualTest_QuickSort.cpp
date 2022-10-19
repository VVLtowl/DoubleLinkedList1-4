/*********************************************************
* @brief		クイックソートのテスト(手動テスト)
* @date			2022/10/19
********************************************************/
#include "gtest/gtest.h"
#include "../DoubleLinkedList/DoubleLinkedList.h"
#include "../DoubleLinkedList/ScoreData.h"
#include "ManualTest_QuickSort.h"

//クイックソートの手動テスト実行
#define GT_MANUAL_TEST_SORT

namespace ex03_ListSort
{
#ifdef  GT_MANUAL_TEST_SORT
#pragma region ========== クイックソート ==========


#ifdef MANUAL_TEST_SORT_WITH_WRONG_COMPARATOR
	/*********************************************************
	* @brief		型などが不適切なキー指定が引数で渡された時の挙動
	* @details		ID:0-7
	*				型などが不適切なキー指定が引数で渡された時、
	*				コンパイルエラーをチェック。自動テスト化しない。
	********************************************************/
	TEST(QuickSortTest, WithoutComparator)
	{
		DoubleLinkedList<ScoreData> list;

		//キー指定をしなくて、ソートを行う
		list.Sort([]() {return true; });
	}
#endif // MANUAL_TEST_SORT_WITH_WRONG_COMPARATOR

#ifdef MANUAL_TEST_SORT_NOT_CONST
	/*********************************************************
	* @brief		非constのメソッドであるか
	* @details		ID:0-8
	*				非constのメソッドであるかを確認。
	*				constのリストから呼び出して、コンパイルエラーとなるかをチェック。自動テスト化しなくてよい。
	********************************************************/
	TEST(QuickSortTest, NotConst)
	{
		const DoubleLinkedList<ScoreData> list;
		list.Sort([]() {return true; });
	}
#endif // MANUAL_TEST_SORT_WITH_WRONG_COMPARATOR


#pragma endregion



#endif //  GT_MANUAL_TEST_SORT
}





