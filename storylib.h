#pragma once

#include <map>
#include <list>
#include <string>

using namespace std;

typedef struct item
{
	int index; // print_inventory 함수에서 아이템을 출력하는 순서 저장
	int cnt; // 아이템의 개수
	string name;  // 아이템의 이름
	string detail; // 아이템의 설명
	list<string> available_story; // 아이템을 사용할 수 있는 스토리패스의 리스트
}ITEM;

struct inventory
{
	// 아이템
	item firestone = { 0, 1, "부싯돌\0", "\0" , { "1_1","1_1_1","2" } };
	item glasses = { 0, 1, "안경\0", "\0"  ,{"2"}};
	item coin = { 0, 3, "동전\0", "\0", {"3_2_1_1"}};
	item banana = { 0, 0, "바나나\0", "\0", {"1_2"}};
	item grapefruit = { 0, 0, "자몽\0", "\0", {"1_2"}};
	item fishing_rod = { 0, 0, "낚시대\0", "\0" ,{"3_1"}};
};

// 스토리 함수 포인터
// 반환값 : 다음 스토리의 선택지 (옵션값의 List) 
typedef list<char>(*STORY_FUNC)();

void addStory(string storyKey, STORY_FUNC storyFunc);
void pushStoryPath(char option);
char popStoryPath();
void clearStoryPath();
void rebuildStoryPath(list<char> list);
string buildStoryKey();
list<char> callStoryFunc();
