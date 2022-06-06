#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <map>
#include <list>
#include <string>

#include "storylib.h"

using namespace std;

const string DELIMETER = "_";			// ���丮 �Լ� ����/�ε� �� �� ����ϴ� Ű�� ���� ����

/////////////////////////////////////////////////
// �������� start

status M;								// ����
inventory I;							// �κ��丮
map<string, list<char>(*)()> storyMap;	// ���丮 ���� ��
list<char> storyPathList;				// ���丮 ���� ���� ����Ʈ

// �������� end
/////////////////////////////////////////////////


void addStory(string storyKey, STORY_FUNC storyFunc)
{
	storyMap.insert(make_pair(storyKey, storyFunc));
}

/*
	���丮 ���� ���� ����Ʈ(storyPathList)�� �̿��Ͽ�
	���丮 �Լ��� Ű�� ����
	storyPathList�� "1, 2, 1" �� �����Ͽ� �����Ͽ� �Դٸ� Ű�� "1_2_1" �� ����
*/
string buildStoryKey()
{
	string pathStr;
	// iterator(�ݺ���) ����
	for (list<char>::iterator iter = storyPathList.begin(); iter != storyPathList.end(); iter++)
	{
		// ó���̸� delimeter ����
		if (pathStr.empty())
		{
			pathStr += string(1, *iter);
		}
		// �� �������ʹ� delimeter �����Ͽ� ����
		else
		{
			pathStr += DELIMETER + string(1, *iter);
		}
	}

	return pathStr;
}

/*
	������ �ɼ��� ���丮 ���� ���� ����Ʈ�� �ִ´�.
*/
void pushStoryPath(char option)
{
	storyPathList.push_back(option);
}

/*
	���丮 ���� ���� ����Ʈ�� ������ �ɼ��� ����Ʈ�� ��ȯ�� �� �����Ѵ�.
*/
char popStoryPath()
{
	if (storyPathList.size() > 0) 
	{
		char option = storyPathList.back();
		storyPathList.pop_back();
		return option;
	}
	else
	{
		return -1;
	}
}

void clearStoryPath()
{
	storyPathList.clear();
} 

void rebuildStoryPath(list<char> list)
{
	storyPathList = list;
}

/*
	���丮 �Լ��� ȣ��
	buildStoryKey�� �̿��Ͽ� ���� ���� ���丮 Ű�� �����ϰ�
	storyMap���� �ش��ϴ� �Լ��� ȣ��
*/
list<char> callStoryFunc()
{

	auto iter = storyMap.find(storyPathList.size() == 0 ? "begin" : buildStoryKey());
	if (iter == storyMap.end())
	{
		printf("�ش� ���丮�� �����ϴ�.");
		return list<char>{};
	}

	system("cls");
	return (*iter->second)();
}

void SleepEx(DWORD dwMilliseconds, int* count)
{
	if (*count == 0)
	{
		Sleep(dwMilliseconds);
	}
}