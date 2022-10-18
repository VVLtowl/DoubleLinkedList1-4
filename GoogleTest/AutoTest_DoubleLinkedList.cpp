/*********************************************************
* @brief		�o�������X�g�̒P�̃e�X�g
* @date			2022/10/11
********************************************************/
#include "gtest/gtest.h"
#include "../DoubleLinkedList/DoubleLinkedList.h"
#include "../DoubleLinkedList/ScoreData.h"
#include "TestTool.h"

//�o�������X�g�̒P�̃e�X�g
#define GT_AUTO_TEST_LIST

//�o�������X�g�̎蓮�e�X�g
//#define GT_MANUAL_TEST_LIST

namespace ex01_DoubleLinkedList
{
#if defined GT_AUTO_TEST_LIST

#pragma region ========== �f�[�^���̎擾 ==========

	using ListCountTest_F = ListFixture;

	/*********************************************************
	* @brief		���X�g����ł���ꍇ�̖߂�l
	* @details		ID:0-0
	* 				���X�g����ł���ꍇ�A
	*				�f�[�^���̎擾�֐��̖߂�l���m�F���܂��B
	*				�߂�l��0�̏ꍇ�����ł��B
	********************************************************/
	TEST(ListCountTest, WhenEmptyList)
	{
		DoubleLinkedList<ScoreData> list;
		EXPECT_EQ(0, list.Count());
	}

	/*********************************************************
	* @brief		���X�g�����ւ̑}�����s�����ۂ̖߂�l
	* @details		ID:0-1
	* 				���X�g�����ւ̑}�����s�����ۂɁA
	*				�f�[�^���̎擾�֐��̖߂�l���m�F���܂��B
	*				�߂�l��1�̏ꍇ�����ł��B
	********************************************************/
	TEST(ListCountTest, WhenInsertToEndSucceed)
	{
		DoubleLinkedList<ScoreData> list;

		//�����ւ̑}���𐬌�������
		auto iter = list.End();
		ScoreData data(10, "element0");
		EXPECT_TRUE(list.Insert(iter, data));

		EXPECT_EQ(1, list.Count());
	}

	/*********************************************************
	* @brief		���X�g�����ւ̑}�������s�����ۂ̖߂�l
	* @details		ID:0-2
	* 				���X�g�����ւ̑}�������s�����ۂɁA
	*				�f�[�^���̎擾�֐��̖߂�l���m�F���܂��B
	*				�߂�l��0�̏ꍇ�����ł��B
	********************************************************/
	TEST(ListCountTest, WhenInsertToEndFailed)
	{
		DoubleLinkedList<ScoreData> list;
		DoubleLinkedList<ScoreData> otherList;

		//�����ւ̑}�������s������
		auto iter = otherList.End();//�ʃ��X�g�̃C�e���[�^�Ŏ��s���N����
		ScoreData data;
		EXPECT_FALSE(list.Insert(iter, data));

		EXPECT_EQ(0, list.Count());
	}

	/*********************************************************
	* @brief		�f�[�^�̑}�����s�����ۂ̖߂�l
	* @details		ID:0-3
	* 				�f�[�^�̑}�����s�����ۂɁA
	*				�f�[�^���̎擾�֐��̖߂�l���m�F���܂��B
	*				�߂�l��1�̏ꍇ�����ł��B
	********************************************************/
	TEST(ListCountTest, WhenInsertSucceed)
	{
		DoubleLinkedList<ScoreData> list;

		//�}�����s����
		auto iter = list.Begin();
		ScoreData data(10, "element0");
		EXPECT_TRUE(list.Insert(iter, data));

		EXPECT_EQ(1, list.Count());
	}

	/*********************************************************
	* @brief		�f�[�^�̑}���Ɏ��s�����ۂ̖߂�l
	* @details		ID:0-4
	* 				�f�[�^�̑}���Ɏ��s�����ۂɁA
	*				�f�[�^���̎擾�֐��̖߂�l���m�F���܂��B
	*				�߂�l��0�̏ꍇ�����ł��B
	********************************************************/
	TEST(ListCountTest, WhenInsertFailed)
	{
		DoubleLinkedList<ScoreData> list;
		DoubleLinkedList<ScoreData> otherList;

		//�}�������s������
		auto iter = otherList.Begin();//�ʃ��X�g�̃C�e���[�^�Ŏ��s���N����
		ScoreData data;
		EXPECT_FALSE(list.Insert(iter, data));

		EXPECT_EQ(0, list.Count());
	}

	/*********************************************************
	* @brief		�f�[�^�̍폜���s�����ۂ̖߂�l
	* @details		ID:0-5
	* 				�f�[�^�̍폜���s�����ۂɁA
	*				�f�[�^���̎擾�֐��̖߂�l���m�F���܂��B
	*				�߂�l��0�̏ꍇ�����ł��B
	********************************************************/
	TEST_F(ListCountTest_F, WhenRemoveSucceed)
	{
		InputOneData();

		//�폜���s����
		auto iter = list.Begin();
		EXPECT_TRUE(list.Remove(iter));

		EXPECT_EQ(0, list.Count());
	}

	/*********************************************************
	* @brief		�f�[�^�̍폜�����s�����ۂ̖߂�l
	* @details		ID:0-6
	* 				�f�[�^��}��������A�폜�����ꍇ�A�폜�����s�����ۂɁA
	*				�f�[�^���̎擾�擾�֐��̖߂�l���m�F���܂��B
	*				�߂�l��1�̏ꍇ�����ł��B
	********************************************************/
	TEST_F(ListCountTest_F, WhenRemoveFailed)
	{
		InputOneData();

		//�����ȃC�e���[�^����A�폜�����s������
		DoubleLinkedList<ScoreData>::Iterator iter;
		EXPECT_FALSE(list.Remove(iter));

		EXPECT_EQ(1, list.Count());
	}

	/*********************************************************
	* @brief		���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂ̖߂�l
	* @details		ID:0-7
	*				�}�C�i�X�ɂȂ�Ȃ������m�F���邽�߁A
	* 				���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂɁA
	*				�f�[�^���̎擾�֐��̖߂�l���m�F���܂��B
	*				�߂�l��0�̏ꍇ�����ł��B
	********************************************************/
	TEST(ListCountTest, WhenEmptyListAndRemove)
	{
		DoubleLinkedList<ScoreData> list;
		auto iter = list.Begin();
		EXPECT_FALSE(list.Remove(iter));

		EXPECT_EQ(0, list.Count());
	}

#pragma endregion

#pragma region ========== �f�[�^�̑}�� ==========

	using ListInsertTest_F = ListFixture;

	/*********************************************************
	* @brief		���X�g����ł���ꍇ�ɁA�}�������ۂ̋���
	* @details		ID:0-9
	* 				���X�g����ł���ꍇ�ɁA�V�v�f���C�e���[�^�̎w���ʒu�ɑ}�����܂��B
	*				�擪�C�e���[�^�A�����C�e���[�^�������œn�����ꍇ�ɂ��āA�ʂɋ������`�F�b�N���܂��B
	*				�f�[�^�̑}���֐��̖߂�l���m�F���܂��B
	*				�߂�l��true�̏ꍇ�����ł��B
	********************************************************/
	TEST(ListInsertTest, WhenEmptyList)
	{
		//�擪�C�e���[�^�̎w���ʒu�ɑ}��
		DoubleLinkedList<ScoreData> list1;
		auto head = list1.Begin();
		ScoreData data1(10, "element0");
		EXPECT_TRUE(list1.Insert(head, data1));

		//�����C�e���[�^�̎w���ʒu�ɑ}��
		DoubleLinkedList<ScoreData> list2;
		auto end = list2.End();
		ScoreData data2(11, "element1");
		EXPECT_TRUE(list2.Insert(end, data2));
	}

	/*********************************************************
	* @brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�}�������ۂ̋���
	* @details		ID:0-10
	* 				���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�}�����܂��B
	*				�擪�ɗv�f���}������A���X�擪�������v�f���Q�ԖڂɂȂ�܂��B
	*				�f�[�^�̑}���֐��̖߂�l���m�F���܂��B
	*				�߂�l��true�̏ꍇ�����ł��B
	********************************************************/
	TEST_F(ListInsertTest_F, WhenNotEmptyList_InsertToHead)
	{
		//�����v�f�̂��郊�X�g���쐬
		InputTwoData();

		//�擪�C�e���[�^��n���āA�V�v�f��}��
		auto head = list.Begin();
		auto headData(*head);//���X�擪�������v�f
		ScoreData newData(20, "newElement");
		EXPECT_TRUE(list.Insert(head, newData));

		//���X�擪�������v�f���Q�ԖڂɂȂ��Ă邩���`�F�b�N
		auto iter = list.Begin();
		++iter;
		EXPECT_EQ(headData.score, (*iter).score);
		EXPECT_EQ(headData.name, (*iter).name);
	}

	/*********************************************************
	* @brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�}�������ۂ̋���
	* @details		ID:0-11
	* 				���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�}�����܂��B
	*				�C�e���[�^�̎w���ʒu�ɗv�f���}������܂��B
	*				�f�[�^�̑}���֐��̖߂�l���m�F���܂��B
	*				�߂�l��true�̏ꍇ�����ł��B
	********************************************************/
	TEST_F(ListInsertTest_F, WhenNotEmptyList_InsertToTail)
	{
		//�����v�f�̂��郊�X�g���쐬
		InputTwoData();

		//�����C�e���[�^��n���āA�V�v�f��}��
		auto end = list.End();
		ScoreData data(20, "newElement");
		EXPECT_TRUE(list.Insert(end, data));
	}

	/*********************************************************
	* @brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�������ۂ̋���
	* @details		ID:0-12
	* 				���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���āA�}�����܂��B
	*				�C�e���[�^�̎w���ʒu�ɗv�f���}�����ꂻ�̈ʒu�ɂ������v�f�����ɂ���܂��B
	*				�f�[�^�̑}���֐��̖߂�l���m�F���܂��B
	*				�߂�l��true�̏ꍇ�����ł��B
	********************************************************/
	TEST_F(ListInsertTest_F, WhenNotEmptyList_InsertToMiddle)
	{
		//�����v�f�̂��郊�X�g���쐬
		InputTwoData();

		//�����C�e���[�^��n���āA�V�v�f��}��
		auto iter = list.Begin();
		++iter;//�����ֈړ�
		ScoreData data(20, "newElement");
		EXPECT_TRUE(list.Insert(iter, data));
	}

	/*********************************************************
	* @brief		ConstIterator���w�肵�đ}�����s�����ۂ̋���
	* @details		ID:0-13
	* 				ConstIterator���w�肵�āA�}�����܂��B
	*				�C�e���[�^�̎w���ʒu�ɗv�f���}�����ꂻ�̈ʒu�ɂ������v�f�����ɂ���܂��B
	*				�f�[�^�̑}���֐��̖߂�l���m�F���܂��B
	*				�߂�l��true�̏ꍇ�����ł��B
	*
	*				�i�[�ς݂̗v�f�ɉe�����Ȃ����A���҂����ʒu�ɗv�f���i�[����Ă��邩�B
	*				�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B
	********************************************************/
	TEST_F(ListInsertTest_F, WhenNotEmptyList_InsertByConstIterator)
	{
		//�����v�f�̂��郊�X�g���쐬
		InputTwoData();

		//�擪�C�e���[�^��n���āA�V�v�f��}��
		auto constHead = list.CBegin();
		ScoreData newData0(20, "newElement0");
		EXPECT_TRUE(list.Insert(constHead, newData0));

		//�����C�e���[�^��n���āA�V�v�f��}��
		auto constIter = list.CBegin();
		++constIter;//�����ֈړ�
		ScoreData newData1(21, "newElement1");
		EXPECT_TRUE(list.Insert(constIter, newData1));

		//�����C�e���[�^��n���āA�V�v�f��}��
		auto constEnd = list.CEnd();
		ScoreData newData2(22, "newElement2");
		EXPECT_TRUE(list.Insert(constEnd, newData2));

	}

	/*********************************************************
	* @brief		�s���ȃC�e���[�^��n���āA�}�������ꍇ�̋���
	* @details		ID:0-14
	* 				���X�g�̎Q�Ƃ��Ȃ��C�e���[�^�A�ʃ��X�g�̗v�f���w���C�e���[�^��n�����ۂ̋����Ȃǂ��m�F���܂��B
	*				���X�g�̎Q�Ƃ��Ȃ��C�e���[�^���w�肵����A
	*				�ʃ��X�g�̗v�f���w���C�e���[�^��n�����肵�āA�}�����܂��B
	*				�C�e���[�^�̎w���ʒu�ɗv�f���}�����ꂻ�̈ʒu�ɂ������v�f�����ɂ���܂��B
	*				�f�[�^�̑}���֐��̖߂�l���m�F���܂��B
	*				�߂�l��true�̏ꍇ�����ł��B
	*
	********************************************************/
	TEST(ListInsertTest, WhenNotEmptyList_InsertWrongIterator)
	{
		DoubleLinkedList<ScoreData> list;
		ScoreData data0(10, "element0");
		auto iter = list.Begin();
		list.Insert(iter, data0);


		//�ʃ��X�g���쐬
		DoubleLinkedList<ScoreData> otherList;
		ScoreData data1(11, "element1");
		iter = otherList.Begin();
		list.Insert(iter, data1);

		//���X�g�̎Q�Ƃ��Ȃ��C�e���[�^
		DoubleLinkedList<ScoreData>::Iterator noReference;
		ScoreData newData(20, "newElement");
		EXPECT_FALSE(list.Insert(noReference, newData));

		//�ʃ��X�g�̗v�f���w���C�e���[�^
		DoubleLinkedList<ScoreData>::Iterator wrongList = otherList.Begin();
		EXPECT_FALSE(list.Insert(wrongList, newData));
	}

#pragma endregion

#pragma region ========== �f�[�^�̍폜 ==========

	using ListRemoveTest_F = ListFixture;

	/*********************************************************
	* @brief		���X�g����ł���ꍇ�ɁA�폜�����ۂ̋���
	* @details		ID:0-16
	* 				���X�g����ł���ꍇ�ɁA�V�v�f���C�e���[�^�̎w���ʒu�ɑ}�����܂��B
	*				�C�e���[�^�̎w���ʒu�ɗv�f���}�����ꂻ�̈ʒu�ɂ������v�f�����ɂ����B
	*				�f�[�^�̍폜�֐��̖߂�l���m�F���܂��B
	*				�߂�l��false�̏ꍇ�����ł��B
	********************************************************/
	TEST(ListRemoveTest, WhenEmptyList)
	{
		//�擪�v�f���폜
		DoubleLinkedList<ScoreData> list1;
		auto head = list1.Begin();
		EXPECT_FALSE(list1.Remove(head));

		//�����v�f���폜
		DoubleLinkedList<ScoreData> list2;
		auto end = list2.End();
		EXPECT_FALSE(list2.Remove(end));
	}

	/*********************************************************
	* @brief		�擪�v�f�̍폜�̋���
	* @details		ID:0-17
	* 				���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�폜���܂��B
	*				�擪�v�f���폜���ꂽ�����m�F���܂��B
	*				�f�[�^�̍폜�֐��̖߂�l���m�F���܂��B
	*				�߂�l��true�̏ꍇ�����ł��B
	********************************************************/
	TEST_F(ListRemoveTest_F, WhenNotEmptyList_RemoveHead)
	{
		//�����̗v�f�����郊�X�g���쐬
		InputTwoData();

		auto head = list.Begin();
		EXPECT_TRUE(list.Remove(head));
	}

	/*********************************************************
	* @brief		�����v�f���폜�����ۂ̋���
	* @details		ID:0-18
	* 				���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�폜���܂��B
	*				�����̓_�~�[�m�[�h�Ȃ̂ŁA�폜�͎��s����͂��ł��B
	*				�f�[�^�̍폜�֐��̖߂�l���m�F���܂��B
	*				�߂�l��false�̏ꍇ�����ł��B
	********************************************************/
	TEST_F(ListRemoveTest_F, WhenNotEmptyList_RemoveEnd)
	{
		//�����̗v�f�����郊�X�g���쐬
		InputTwoData();

		auto end = list.End();
		EXPECT_FALSE(list.Remove(end));
	}

	/*********************************************************
	* @brief		���ԗv�f���폜�����ۂ̋���
	* @details		ID:0-19
	* 				���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���č폜�����ۂɁA
	*				�C�e���[�^�Ɏw���ꂽ�v�f���폜���ꂽ�����m�F���܂��B
	*				�f�[�^�̍폜�֐��̖߂�l���m�F���܂��B
	*				�߂�l��true�̏ꍇ�����ł��B
	********************************************************/
	TEST_F(ListRemoveTest_F, WhenNotEmptyList_RemoveMiddle)
	{
		//�����̗v�f�����郊�X�g���쐬
		InputTwoData();

		//�����v�f���w���C�e���[�^���쐬
		auto iter = list.Begin();
		++iter;
		auto middle = iter;

		EXPECT_TRUE(list.Remove(middle));
	}

	/*********************************************************
	* @brief		ConstIterator���w�肵�č폜���s�����ۂ̋���
	* @details		ID:0-20
	* 				���X�g�ɕ����̗v�f������ꍇ�ɁAConstIterator���w�肵�Ă����ۂɁA
	*				ConstIterator�Ɏw���ꂽ�v�f���폜���ꂽ�����m�F���܂��B
	*				�f�[�^�̍폜�֐��̖߂�l���m�F���܂��B
	*				�߂�l��true�̏ꍇ�����ł��B
	********************************************************/
	TEST_F(ListRemoveTest_F, WhenNotEmptyList_RemoveByConstIterator)
	{
		//�����̗v�f�����郊�X�g���쐬
		InputTwoData();

		auto constIter = list.CBegin();
		EXPECT_TRUE(list.Remove(constIter));
	}

	/*********************************************************
	* @brief		�s���ȃC�e���[�^��n���āA�폜�����ꍇ�̋���
	* @details		ID:0-21
	* 				���X�g�̎Q�Ƃ��Ȃ��C�e���[�^�A�ʃ��X�g�̗v�f���w���C�e���[�^�Ȃ�
	*				�s���ȃC�e���[�^��n�����ۂɁA
	*				�f�[�^�̍폜�֐��̖߂�l���m�F���܂��B
	*				�߂�l��false�̏ꍇ�����ł��B
	********************************************************/
	TEST(ListRemoveTest, WhenNotEmptyList_RemoveByWrongIterator)
	{
		DoubleLinkedList<ScoreData> list;
		ScoreData data0(10, "element0");
		list.Insert(list.End(), data0);

		//�ʃ��X�g���쐬
		DoubleLinkedList<ScoreData> otherList;
		ScoreData data1(11, "element1");
		otherList.Insert(otherList.End(), data1);

		//���X�g�̎Q�Ƃ��Ȃ��C�e���[�^
		DoubleLinkedList<ScoreData>::Iterator noReference;
		EXPECT_FALSE(list.Remove(noReference));

		//�ʃ��X�g�̗v�f���w���C�e���[�^
		DoubleLinkedList<ScoreData>::Iterator wrongList = otherList.Begin();
		EXPECT_FALSE(list.Remove(wrongList));
	}

#pragma endregion

#pragma region ========== �擪�C�e���[�^�̎擾 ==========

	using ListBeginTest_F = ListFixture;

	/*********************************************************
	* @brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
	* @details		ID:0-23
	* 				���X�g����ł���ꍇ�ɁA�Ăяo�����ۂɁA
	*				�߂�l�̓_�~�[�m�[�h���w���C�e���[�^�̏ꍇ�����ł��B
	********************************************************/
	TEST(ListBeginTest, WhenEmptyList)
	{
#ifdef _DEBUG
		DoubleLinkedList<ScoreData> list;

		//�_�~�[�ł��邩
		EXPECT_DEATH((*list.Begin()), "iterator: is dummy");
#else
		SUCCEED();
#endif // _DEBUG
	}

	/*********************************************************
	* @brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
	* @details		ID:0-24
	* 				���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂɁA
	*				�擪�v�f���w���C�e���[�^���Ԃ�ꍇ�����ł��B
	********************************************************/
	TEST_F(ListBeginTest_F, WhenOneElementList)
	{
		//�v�f������郊�X�g���쐬
		InputOneData();

		//���X�g�ɗv�f����ł��邩���`�F�b�N
		EXPECT_EQ(1, list.Count());

		EXPECT_EQ("head", (*list.Begin()).name);
	}

	/*********************************************************
	* @brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
	* @details		ID:0-25
	* 				���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂɁA
	*				�擪�v�f���w���C�e���[�^���Ԃ�ꍇ�����ł��B
	********************************************************/
	TEST_F(ListBeginTest_F, WhenManyElementsList)
	{
		//�v�f����ȏ゠�郊�X�g���쐬
		InputThreeData();

		//���X�g�ɗv�f����ȏ゠�邩���`�F�b�N
		EXPECT_LE(2, list.Count());

		EXPECT_EQ("head", (*list.Begin()).name);
	}

	/*********************************************************
	* @brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
	* @details		ID:0-26
	* 				�f�[�^�̑}�����s������ɁA�Ăяo�����ۂɁA
	*				�擪�v�f���w���C�e���[�^���Ԃ�ꍇ�����ł��B
	*				�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B
	********************************************************/
	TEST_F(ListBeginTest_F, AfterInsert)
	{
		InputThreeData();
		ScoreData newData(20, "newData");

		//�擪�ɑ}��
		UpdateIterator();
		EXPECT_TRUE(list.Insert(headIter, newData));
		EXPECT_EQ("newData", (*list.Begin()).name);

		//�����ɑ}��
		UpdateIterator();
		EXPECT_TRUE(list.Insert(middleIter, newData));
		EXPECT_EQ("newData", (*list.Begin()).name);

		//�����ɑ}��
		UpdateIterator();
		EXPECT_TRUE(list.Insert(endIter, newData));
		EXPECT_EQ("newData", (*list.Begin()).name);
	}

	/*********************************************************
	* @brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
	* @details		ID:0-27
	* 				�f�[�^�̍폜���s������ɁA�Ăяo�����ۂɁA
	*				�擪�v�f���w���C�e���[�^���Ԃ�ꍇ�����ł��B
	*				�v�f��̐擪�A�����A�����ɍ폜���s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B
	********************************************************/
	TEST_F(ListBeginTest_F, AfterRemove)
	{
		//3��폜���s�����߁A�f�[�^4��p��
		InputDatas(4);//list: head middle0 middle1 tail

		//�����v�f���폜
		UpdateIterator();
		EXPECT_TRUE(list.Remove(tailIter));
		EXPECT_EQ("head", (*list.Begin()).name);	//list: head middle0 middle1

		//�������폜
		UpdateIterator();
		EXPECT_TRUE(list.Remove(middleIter));
		EXPECT_EQ("head", (*list.Begin()).name);	//list: head middle1

		//�擪���폜
		UpdateIterator();
		EXPECT_TRUE(list.Remove(headIter));
		EXPECT_EQ("middle1", (*list.Begin()).name);	//list: middle1
	}

#pragma endregion

#pragma region ========== �擪�R���X�g�C�e���[�^�̎擾 ==========

	using ListCBeginTest_F = ListFixture;

	/*********************************************************
	* @brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
	* @details		ID:0-29
	* 				���X�g����ł���ꍇ�ɁA�Ăяo�����ۂɁA
	*				�߂�l�̓_�~�[�m�[�h���w���C�e���[�^�̏ꍇ�����ł��B
	********************************************************/
	TEST(ListCBeginTest, WhenEmptyList)
	{
#ifdef _DEBUG
		DoubleLinkedList<ScoreData> list;

		//�_�~�[�ł��邩
		EXPECT_DEATH((*list.CBegin()), "constIterator: is dummy");
#else
		SUCCEED();
#endif // _DEBUG
	}

	/*********************************************************
	* @brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
	* @details		ID:0-30
	* 				���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂɁA
	*				�擪�v�f���w���C�e���[�^���Ԃ�ꍇ�����ł��B
	********************************************************/
	TEST_F(ListCBeginTest_F, WhenOneElementList)
	{
		//�v�f������郊�X�g���쐬
		InputOneData();

		//���X�g�ɗv�f����ł��邩���`�F�b�N
		EXPECT_EQ(1, list.Count());

		EXPECT_EQ("head", (*list.CBegin()).name);
	}

	/*********************************************************
	* @brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
	* @details		ID:0-31
	* 				���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂɁA
	*				�擪�v�f���w���C�e���[�^���Ԃ�ꍇ�����ł��B
	********************************************************/
	TEST_F(ListCBeginTest_F, WhenManyElementsList)
	{
		//�v�f����ȏ゠�郊�X�g���쐬
		InputThreeData();

		//���X�g�ɗv�f����ȏ゠�邩���`�F�b�N
		EXPECT_LE(2, list.Count());

		EXPECT_EQ("head", (*list.CBegin()).name);
	}

	/*********************************************************
	* @brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
	* @details		ID:0-32
	* 				�f�[�^�̑}�����s������ɁA�Ăяo�����ۂɁA
	*				�擪�v�f���w���C�e���[�^���Ԃ�ꍇ�����ł��B
	*				�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B
	********************************************************/
	TEST_F(ListCBeginTest_F, AfterInsert)
	{
		InputThreeData();
		ScoreData newData(20, "newData");

		//�擪�ɑ}��
		UpdateIterator();
		EXPECT_TRUE(list.Insert(headIter, newData));
		EXPECT_EQ("newData", (*list.CBegin()).name);

		//�����ɑ}��
		UpdateIterator();
		EXPECT_TRUE(list.Insert(middleIter, newData));
		EXPECT_EQ("newData", (*list.CBegin()).name);

		//�����ɑ}��
		UpdateIterator();
		EXPECT_TRUE(list.Insert(endIter, newData));
		EXPECT_EQ("newData", (*list.CBegin()).name);
	}

	/*********************************************************
	* @brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
	* @details		ID:0-33
	* 				�f�[�^�̍폜���s������ɁA�Ăяo�����ۂɁA
	*				�擪�v�f���w���C�e���[�^���Ԃ�ꍇ�����ł��B
	*				�v�f��̐擪�A�����A�����ɍ폜���s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B
	********************************************************/
	TEST_F(ListCBeginTest_F, AfterRemove)
	{
		//3��폜���s�����߁A�f�[�^4��p��
		InputDatas(4);//list: head middle0 middle1 tail

		//�����v�f���폜
		UpdateIterator();
		EXPECT_TRUE(list.Remove(tailIter));
		EXPECT_EQ("head", (*list.CBegin()).name);//list: head middle0 middle1

		//�������폜
		UpdateIterator();
		EXPECT_TRUE(list.Remove(middleIter));
		EXPECT_EQ("head", (*list.CBegin()).name);//list: head middle1

		//�擪���폜
		UpdateIterator();
		EXPECT_TRUE(list.Remove(headIter));
		EXPECT_EQ("middle1", (*list.CBegin()).name);//list: middle1
	}

#pragma endregion

#pragma region ========== �����C�e���[�^�̎擾 ==========

	using ListEndTest_F = ListFixture;

	/*********************************************************
	* @brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
	* @details		ID:0-35
	* 				���X�g����ł���ꍇ�ɁA�Ăяo�����ۂɁA
	*				�߂�l�̓_�~�[�m�[�h���w���C�e���[�^�̏ꍇ�����ł��B
	********************************************************/
	TEST(ListEndTest, WhenEmptyList)
	{
#ifdef _DEBUG
		DoubleLinkedList<ScoreData> list;

		//�_�~�[�ł��邩
		EXPECT_DEATH((*list.End()), "iterator: is dummy");
#else
		SUCCEED();
#endif // _DEBUG
	}

	/*********************************************************
	* @brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
	* @details		ID:0-36
	* 				���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂɁA
	*				�_�~�[�m�[�h���w���C�e���[�^���Ԃ�ꍇ�����ł��B
	********************************************************/
	TEST_F(ListEndTest_F, WhenOneElementList)
	{
#ifdef _DEBUG
		//�v�f������郊�X�g���쐬
		InputOneData();

		//���X�g�ɗv�f����ł��邩���`�F�b�N
		EXPECT_EQ(1, list.Count());

		EXPECT_DEATH((*list.End()), "iterator: is dummy");
#else
		SUCCEED();
#endif // _DEBUG
	}

	/*********************************************************
	* @brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
	* @details		ID:0-37
	* 				���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂɁA
	*				�_�~�[�m�[�h���w���C�e���[�^���Ԃ�ꍇ�����ł��B
	********************************************************/
	TEST_F(ListEndTest_F, WhenManyElementsList)
	{
#ifdef _DEBUG
		//�v�f����ȏ゠�郊�X�g���쐬
		InputThreeData();

		//���X�g�ɗv�f����ȏ゠�邩���`�F�b�N
		EXPECT_LE(2, list.Count());

		EXPECT_DEATH((*list.End()), "iterator: is dummy");
#else
		SUCCEED();
#endif // _DEBUG
	}

	/*********************************************************
	* @brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
	* @details		ID:0-38
	* 				�f�[�^�̑}�����s������ɁA�Ăяo�����ۂɁA
	*				�_�~�[�m�[�h���w���C�e���[�^���Ԃ�ꍇ�����ł��B
	*				�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B
	********************************************************/
	TEST_F(ListEndTest_F, AfterInsert)
	{
#ifdef _DEBUG
		InputThreeData();
		ScoreData newData(20, "newData");

		//�擪�ɑ}��
		UpdateIterator();
		EXPECT_TRUE(list.Insert(headIter, newData));
		EXPECT_DEATH((*list.End()), "iterator: is dummy");

		//�����ɑ}��
		UpdateIterator();
		EXPECT_TRUE(list.Insert(middleIter, newData));
		EXPECT_DEATH((*list.End()), "iterator: is dummy");

		//�����ɑ}��
		UpdateIterator();
		EXPECT_TRUE(list.Insert(endIter, newData));
		EXPECT_DEATH((*list.End()), "iterator: is dummy");
#else
		SUCCEED();
#endif // _DEBUG
	}

	/*********************************************************
	* @brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
	* @details		ID:0-39
	* 				�f�[�^�̍폜���s������ɁA�Ăяo�����ۂɁA
	*				�_�~�[�m�[�h���w���C�e���[�^���Ԃ�ꍇ�����ł��B
	*				�v�f��̐擪�A�����A�����ɍ폜���s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B
	********************************************************/
	TEST_F(ListEndTest_F, AfterRemove)
	{
#ifdef _DEBUG
		//3��폜���s�����߁A�f�[�^4��p��
		InputDatas(4);

		//�����v�f���폜
		UpdateIterator();
		EXPECT_TRUE(list.Remove(tailIter));
		EXPECT_DEATH((*list.End()), "iterator: is dummy");

		//�������폜
		UpdateIterator();
		EXPECT_TRUE(list.Remove(middleIter));
		EXPECT_DEATH((*list.End()), "iterator: is dummy");

		//�擪���폜
		UpdateIterator();
		EXPECT_TRUE(list.Remove(headIter));
		EXPECT_DEATH((*list.End()), "iterator: is dummy");
#else
		SUCCEED();
#endif // _DEBUG
	}

#pragma endregion

#pragma region ========== �����R���X�g�C�e���[�^�̎擾 ==========

	using ListCEndTest_F = ListFixture;

	/*********************************************************
	* @brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
	* @details		ID:0-41
	* 				���X�g����ł���ꍇ�ɁA�Ăяo�����ۂɁA
	*				�߂�l�̓_�~�[�m�[�h���w���C�e���[�^�̏ꍇ�����ł��B
	********************************************************/
	TEST(ListCEndTest, WhenEmptyList)
	{
#ifdef _DEBUG
		DoubleLinkedList<ScoreData> list;

		//�_�~�[�ł��邩
		EXPECT_DEATH((*list.CEnd()), "constIterator: is dummy");
#else
		SUCCEED();
#endif // _DEBUG
	}

	/*********************************************************
	* @brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
	* @details		ID:0-42
	* 				���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂɁA
	*				�_�~�[�m�[�h���w���C�e���[�^���Ԃ�ꍇ�����ł��B
	********************************************************/
	TEST_F(ListCEndTest_F, WhenOneElementList)
	{
#ifdef _DEBUG
		//�v�f������郊�X�g���쐬
		InputOneData();

		//���X�g�ɗv�f����ł��邩���`�F�b�N
		EXPECT_EQ(1, list.Count());

		EXPECT_DEATH((*list.CEnd()), "constIterator: is dummy");
#else
		SUCCEED();
#endif // _DEBUG
	}

	/*********************************************************
	* @brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
	* @details		ID:0-43
	* 				���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂɁA
	*				�_�~�[�m�[�h���w���C�e���[�^���Ԃ�ꍇ�����ł��B
	********************************************************/
	TEST_F(ListCEndTest_F, WhenManyElementsList)
	{
#ifdef _DEBUG
		//�v�f����ȏ゠�郊�X�g���쐬
		InputThreeData();

		//���X�g�ɗv�f����ȏ゠�邩���`�F�b�N
		EXPECT_LE(2, list.Count());

		EXPECT_DEATH((*list.CEnd()), "constIterator: is dummy");
#else
		SUCCEED();
#endif // _DEBUG
	}

	/*********************************************************
	* @brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
	* @details		ID:0-44
	* 				�f�[�^�̑}�����s������ɁA�Ăяo�����ۂɁA
	*				�_�~�[�m�[�h���w���C�e���[�^���Ԃ�ꍇ�����ł��B
	*				�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B
	********************************************************/
	TEST_F(ListCEndTest_F, AfterInsert)
	{
#ifdef _DEBUG
		InputThreeData();
		ScoreData newData(20, "newData");

		//�擪�ɑ}��
		UpdateIterator();
		EXPECT_TRUE(list.Insert(headIter, newData));
		EXPECT_DEATH((*list.CEnd()), "constIterator: is dummy");

		//�����ɑ}��
		UpdateIterator();
		EXPECT_TRUE(list.Insert(middleIter, newData));
		EXPECT_DEATH((*list.CEnd()), "constIterator: is dummy");

		//�����ɑ}��
		UpdateIterator();
		EXPECT_TRUE(list.Insert(endIter, newData));
		EXPECT_DEATH((*list.CEnd()), "constIterator: is dummy");
#else
		SUCCEED();
#endif // _DEBUG
	}

	/*********************************************************
	* @brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
	* @details		ID:0-45
	* 				�f�[�^�̍폜���s������ɁA�Ăяo�����ۂɁA
	*				�_�~�[�m�[�h���w���C�e���[�^���Ԃ�ꍇ�����ł��B
	*				�v�f��̐擪�A�����A�����ɍ폜���s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B
	********************************************************/
	TEST_F(ListCEndTest_F, AfterRemove)
	{
#ifdef _DEBUG
		//3��폜���s�����߁A�f�[�^4��p��
		InputDatas(4);//list: head middle0 middle1 tail

		//�����v�f���폜
		UpdateIterator();
		EXPECT_TRUE(list.Remove(tailIter));
		EXPECT_DEATH((*list.CEnd()), "constIterator: is dummy");

		//�������폜
		UpdateIterator();
		EXPECT_TRUE(list.Remove(middleIter));
		EXPECT_DEATH((*list.CEnd()), "constIterator: is dummy");

		//�擪���폜
		UpdateIterator();
		EXPECT_TRUE(list.Remove(headIter));
		EXPECT_DEATH((*list.CEnd()), "constIterator: is dummy");
#else
		SUCCEED();
#endif // _DEBUG
	}

#pragma endregion

#endif
}