#pragma once

#include <map>
#include <list>
#include <string>

using namespace std;

struct status //player ����: �����, �񸶸�, ü��
{
	int Hp;
	int totalscore;
};

struct inventory
{
	// ��� ������ ���丮�� �̸�
	list<string> firestone = {"2"};
	list<string> glasses = {"2"};
	list<string> coin = {};
	list<string> banana = {"1_1"};
	list<string> grapefruit = {"1_1"};
};

// ���丮 �Լ� ������
// ��ȯ�� : ���� ���丮�� ������ (�ɼǰ��� List) 
typedef list<char>(*STORY_FUNC)();

void addStory(string storyKey, STORY_FUNC storyFunc);
void pushStoryPath(char option);
char popStoryPath();
void clearStoryPath();
void rebuildStoryPath(list<char> list);
string buildStoryKey();
list<char> callStoryFunc();

void SleepEx(DWORD dwMilliseconds, int* count);