/*********************************************************
* @brief		�e�X�g�⏕�̃N���X�Ɗ֐�
* @date			2022/10/12
********************************************************/
#pragma once

#include "gtest/gtest.h"
#include "../DoubleLinkedList/DoubleLinkedList.h"
#include "../DoubleLinkedList/ScoreData.h"
#include <string>


//========== �w��v�f���̃��X�g�̃t�B�N�X�`�� ==========
class ListFixture : public ::testing::Test
{
protected:
	/*********************************************************
	* @brief		�e�X�g�p���X�g
	********************************************************/
	DoubleLinkedList<ScoreData> list;

	/*********************************************************
	* @brief		�擪�v�f���w���C�e���[�^
	********************************************************/
	DoubleLinkedList<ScoreData>::Iterator headIter;

	/*********************************************************
	* @brief		���ԗv�f���w���C�e���[�^
	********************************************************/
	DoubleLinkedList<ScoreData>::Iterator middleIter;

	/*********************************************************
	* @brief		�Ō�̗v�f���w���C�e���[�^
	********************************************************/
	DoubleLinkedList<ScoreData>::Iterator tailIter;

	/*********************************************************
	* @brief		�����v�f���w���C�e���[�^
	********************************************************/
	DoubleLinkedList<ScoreData>::Iterator endIter;

protected:
	virtual void SetUp(void)
	{
		//list = new DoubleLinkedList();
	}

	virtual void TearDown(void)
	{
		//delete list;
	}

	/*********************************************************
	* @brief		�v�f��1���������
	********************************************************/
	void InputOneData()
	{
		ScoreData data;
		DoubleLinkedList<ScoreData>::Iterator end;

		data.score = 10;
		data.name = "head";
		end = list.End();
		list.Insert(end, data);

		//�e�X�g�p�C�e���[�^�̏���
		headIter = list.Begin();
		middleIter = list.Begin(); ++middleIter;
		tailIter = list.End();--tailIter;
		endIter = list.End();

		UpdateIterator();
	}

	/*********************************************************
	* @brief		�v�f��2�����
	********************************************************/
	void InputTwoData()
	{
		ScoreData data;
		DoubleLinkedList<ScoreData>::Iterator end;

		data.score = 10;
		data.name = "head";
		end = list.End();
		list.Insert(end, data);

		data.score = 11;
		data.name = "tail";
		end = list.End();
		list.Insert(end, data);

		UpdateIterator();
	}

	/*********************************************************
	* @brief		�v�f��3�����
	********************************************************/
	void InputThreeData()
	{
		ScoreData data;
		DoubleLinkedList<ScoreData>::Iterator end;

		data.score = 10;
		data.name = "head";
		end = list.End();
		list.Insert(end, data);

		data.score = 11;
		data.name = "middle";
		end = list.End();
		list.Insert(end, data);

		data.score = 12;
		data.name = "tail";
		end = list.End();
		list.Insert(end, data);

		UpdateIterator();
	}

	/*********************************************************
	* @brief		2�ȏ�A�w��v�f���œ����
	* @param		count: �v�f��[2,5]
	********************************************************/
	void InputDatas(int count)
	{
		ScoreData data;
		DoubleLinkedList<ScoreData>::Iterator end;
		int dataNum = count;

		//�쐬���𐧌�
		if (dataNum < 2)dataNum = 2;
		if (dataNum > 5)dataNum = 5;

		//�擪���쐬���A���X�g�ɓ����
		data.score = 10;
		data.name = "head";
		end = list.End();
		list.Insert(end, data);

		//���Ԃ��쐬���A���X�g�ɓ����
		for (int i = 1; i < dataNum-1; i++)
		{
			data.score = 10 + i;
			data.name = "middle" + std::to_string(i - 1);//���O�ŋ�ʂ�����
			end = list.End();
			list.Insert(end, data);
		}

		//�Ō�̗v�f���쐬���A���X�g�ɓ����
		data.score = 10 + dataNum - 1;
		data.name = "tail";
		end = list.End();
		list.Insert(end, data);

		UpdateIterator();
	}

	/*********************************************************
	* @brief		�e�X�g�p�̐擪�A���ԁA�Ō�̗v�f�A�����C�e���[�^�̏���
	********************************************************/
	void UpdateIterator()
	{
		//���X�g����ł���ꍇ�A�ݒu���Ȃ�
		if (list.Count() == 0)
			return;

		//�e�X�g�p�C�e���[�^�̏���
		headIter = list.Begin();
		middleIter = list.Begin(); ++middleIter;//���ԗv�f���擾
		tailIter = list.End(); --tailIter;//�Ō�̗v�f���擾
		endIter = list.End();
	}
};
