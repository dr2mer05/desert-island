#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <list>
#include <iostream>
#include <cstdlib> // rand
#include <ctime> // srand 함수의 시드
#include <mmsystem.h> //멀티미디어시스템
#pragma comment(lib, "winmm.lib") //프로그램사용 윈도우미디어프로그램
//.wav 파일만 재생가능

#include "util.h"
#include "story.h"
#include "storylib.h"
#include "design.h"
#include "main.h"


#define SLEEP_TIME1 1000 // 1초
#define SLEEP_TIME2 50 // 0.05초

using namespace std;

extern inventory I;
int totalscore = 100;

void score_inform(int score)
{
    POS temp_pos = current_pos();
    gotoxy(UI_POS_X + 1, UI_POS_Y + 1);
    
    if(score > 0)
        printf("점수: +%d", score);
    else
        printf("점수: %d", score);
    totalscore += score;
    Sleep(SLEEP_TIME1);
    gotoxy(temp_pos.x, temp_pos.y);
}

// 스토리 키와 스토리 함수를 매핑하여 초기화한다
void story_init()
{
    addStory(string("begin"), story_begin);
    addStory(string("1"), story1);
    addStory(string("1_1"), story1_1);
    addStory(string("1_1_1"), story1_1_1);
    addStory(string("1_1_1_1"), story1_1_1_1);
    addStory(string("1_1_1_2"), story1_1_1_2);
    addStory(string("1_1_2"), story1_1_2);
    addStory(string("1_1_3"), story1_1_3);
    addStory(string("1_2"), story1_2);
    addStory(string("1_2_1"), story1_2_1);
    addStory(string("1_2_2"), story1_2_2);

    addStory(string("2"), story2);
    addStory(string("2_1"), story2_1);
    addStory(string("2_2"), story2_2);

    addStory(string("3"), story3);
    addStory(string("3_1"), story3_1);
    addStory(string("3_1_m"), story3_1_m);
    addStory(string("3_1_m_0"), story3_1_m_0);
    addStory(string("3_1_m_1"), story3_1_m_1);
    addStory(string("3_1_m_2"), story3_1_m_2);
    addStory(string("3_1_m_3"), story3_1_m_3);

    addStory(string("3_1_e"), story3_1_e);
    addStory(string("3_1_e_1"), story3_1_e_1);
    addStory(string("3_1_e_1_1"), story3_1_e_1_1);
    addStory(string("3_1_e_1_2"), story3_1_e_1_2);
    addStory(string("3_1_e_2"), story3_1_e_2);

    addStory(string("3_2"), story3_2);
    addStory(string("3_2_1"), story3_2_1);
    addStory(string("3_2_1_1"), story3_2_1_1);
    addStory(string("3_2_1_2"), story3_2_1_2);
    addStory(string("3_2_2"), story3_2_2);
    addStory(string("3_2_e_1"), story3_2_e_1);

    addStory(string("3_3"), story3_3);
    addStory(string("3_3_m"), story3_3_m);

    addStory(string("3_3_e_1"), story3_3_e_1);
    addStory(string("3_3_e_2"), story3_3_e_2);
    addStory(string("e"), story_e);

}

/*
스토리 중간에 인벤토리에 들어갔다가 나오면 기존의 스토리 함수를 다시 호출하게 된다
이때, 스크립트 출력 시간을 지연시키는 것은 불필요하기 때문에,
스토리 함수 호출 횟수를 변수로 세서
첫번째 호출 시에만 시간 지연 명령을 수행한다
*/
int cntbegin = 0;
int cnt1_1 = 0;
int cnt1_1_1 = 0;
int cnt1_1_1_1 = 0;
int cnt1_1_1_2 = 0;
int cnt1_1_2 = 0;
int cnt1_1_3 = 0;
int cnt1 = 0;
int cnt1_2 = 0;
int cnt1_2_1 = 0;
int cnt1_2_2 = 0;
int cnt2 = 0;
int cnt2_1 = 0;
int cnt2_2 = 0;
int cnt3 = 0;
int cnt3_1 = 0;
int cnt3_1_m = 0;
int cnt3_1_e = 0;
int cnt3_1_e_1 = 0;
int cnt3_1_e_1_1 = 0;
int cnt3_1_e_1_1_1 = 0;
int cnt3_1_e_1_2 = 0;
int cnt3_1_e_2 = 0;
int cnt3_2 = 0;
int cnt3_2_1 = 0;
int cnt3_2_1_1 = 0;
int cnt3_2_1_2 = 0;
int cnt3_2_2 = 0;
int cnt3_2_e_1 = 0;
int cnt3_3 = 0;
int cnt3_3_m = 0;
int cnt3_3_m_3_3_e_1 = 0;
int cnt3_3_m_3_3_e_2 = 0;

int cnt3_1_e_1_1_2 = 0;
int cnt3_3_2 = 0;
int cnt3_3_1 = 0;

/*
스토리 스크립트를 한 글자씩 출력한다.
스크립트 두 개 이상을 출력하는 스토리 함수는 두 번째 호출할 때부터는
시간 지연 명령을 수행하지 않는다.
스크립트 하나만을 출력하는 스토리 함수는 여러 번 호출하더라도
시간 지연 명령을 수행한다.
*/
void story_script(string script)
{
    printf("    ");
    for (int i = 0; i < script.length(); i++)
    {
        printf("%c", script[i]);
        Sleep(SLEEP_TIME2);
    }
    Sleep(SLEEP_TIME1);

}

// 오버로딩
void story_script(string script, int cnt)
{
    printf("    ");
    for (int i = 0; i < script.length(); i++)
    {
        printf("%c", script[i]);
        if (cnt == 0)
            Sleep(SLEEP_TIME2);
    }

    if (cnt == 0)
        Sleep(SLEEP_TIME1);
}

// UI에 스크립트를 출력하는 함수
void UI_script(string script)
{
    gotoxy(UI_POS_X+1, UI_POS_Y+1);
    printf("%s", script.c_str());
}

// 공백을 출력하는 함수
void print_space()
{
    for (int i = 0; i < MAP_POS_X; i++)
        printf(" ");
}

// 맵 출력 전 실행
void story_intro()
{
    string script1 = "이 게임은 플레이어의 선택에 따라 스토리가 좌우됩니다.\n\n";
    story_script(script1);
    string script2 = "신중하게 선택하여 플레이하시길 바랍니다.\n\n";
    story_script(script2);
    system("cls");
}

list<char> story_begin()
{   
    sndPlaySoundA("C:\\oceanwaves.wav", SND_ASYNC | SND_NODEFAULT); //파도소리, 해변가소리 재생
    string script3 = ".      .      .      .      .      .      .      .\n\n";
    story_script(script3, cntbegin);

    string script1 = "갈매기 소리와 함께 눈을 떴다.\n\n";
    story_script(script1, cntbegin);
    string script2 = "손가락을 꿈틀거리며 천천히 일어났는데, 이런... 옷이 다 젖었다.\n\n";
    story_script(script2, cntbegin);

    print_space();
    printf("1. 옷을 나무에 걸어 잠시 말려둔다.\n");
    print_space();
    printf("2. 옷을 말리지 않는다.\n\n");
    cntbegin++;

    return list<char>{'1', '2'};
}

// 옷을 말리는 경우
list <char> story1()
{
    string script1 = "원숭이가 내 옷을 가져갔다!\n\n";
    story_script(script1, cnt1);
    string script2 = "어서 서두르지 않으면 내 옷이 사라진다!\n\n";
    story_script(script2, cnt1);

    print_space();
    printf("1. 원숭이쯤이야! 덤비면 싸워서 가져오지 뭐!\n");
    print_space();
    printf("2. 그래도 싸우기에는... 망설여진다...원숭이를 달래보자.\n\n");
    cnt1++;

    return list<char>{'1', '2'};
}

// 싸우는 경우
list<char>story1_1() 
{
    string script1 = "막상 싸우려니 조금은 막막하다.\n\n";
    story_script(script1, cnt1_1);
    string script2 = "원숭이와 두 눈을 마주하고 몇 초가 흘렀다.\n\n";
    story_script(script2, cnt1_1);
    string script3 = "이게 뭐라고 식은땀이 흐를 일인가... 신중하게 행동해야겠다.\n\n\n";
    story_script(script3, cnt1_1);
    string script4 = "갑자기 원숭이가 도망간다! 이대로 도망가면 옷을 잃는다!\n\n";
    story_script(script4, cnt1_1);
    cnt1_1++;

    print_space();
    printf("1. 바닥에 있는 돌을 주워서 일단 던져보자.\n");
    print_space();
    printf("2. 아니다. 이건 잡아야 한다! 원숭이를 쫓아간다!\n");

    return list<char>{'1', '2'};
}

// 돌 던지는 경우
list<char> story1_1_1()
{
    string script1 = "몇 번 던져보았는데 하나도 맞지 않다니...\n\n";
    story_script(script1, cnt1_1_1);
    string script2 = "마지막 시도... 조금 더 신중히 던져보자...\n\n";
    story_script(script2, cnt1_1_1);
    cnt1_1_1++;

    print_space();
    printf("1. 돌을 왼쪽으로 던진다.\n");
    print_space();
    printf("2. 돌을 오른쪽으로 던진다.\n");

    return list<char>{'1', '2'};
}

// 인벤토리에서 부싯돌을 사용하는 경우
list<char> story1_1_3()
{
    string script1 = "부싯돌을 던졌다.\n\n";
    story_script(script1, cnt1_1_3);
    string script2 = "옷을 되찾았다!\n\n";
    story_script(script2, cnt1_1_3);
    string script3 = "다행히 옷은 멀쩡하다. 앞으로는 잘 간수하도록 하자.\n\n";
    story_script(script3, cnt1_1_3);
    cnt1_1_3++;

    rebuildStoryPath(list<char>{'3'});

    return callStoryFunc();
}

// 왼쪽으로 던진 경우
list<char> story1_1_1_1()
{
    string script1 = "오! 이걸 맞추다니!\n\n원숭이가 드디어 돌을 맞고 쓰러졌다!\n\n";
    story_script(script1, cnt1_1_1_1);
    Sleep(SLEEP_TIME1);
    string script2 = "뭔가 이상하다...어디선가 무리지어 달려오는 소리가 들린다.\n\n";
    story_script(script2, cnt1_1_1_1);
    cnt1_1_1_1++;

    print_space();
    printf(".\n");
    Sleep(SLEEP_TIME1);
    print_space();
    printf(".\n");
    Sleep(SLEEP_TIME1);
    print_space();
    printf(".\n\n\n");
    Sleep(SLEEP_TIME1);

    print_space();
    setColor(red, black); 
    printf("원숭이 군단에 의해 사망하였습니다.\n");
    setColor(white, black);
    score_inform(-100);
    Sleep(SLEEP_TIME1); 
    print_space();
    printf("리스폰 하려면 r을 누르시오.\n\n");

    // 키보드에서 r을 누를 때까지 기다린다
    while (keyCheckerIgnoreCase('r') == false)
    {
        Sleep(1);
    }

    // 스토리패스를 두 번 전의 스토리로 저장한다
    popStoryPath();
    popStoryPath();

    // 스토리 함수 호출 함수를 호출한다
    return callStoryFunc();
}

// 오른쪽으로 던진 경우
list <char> story1_1_1_2() 
{
    string script1 = "또 맞추지 못하였다.\n\n";
    story_script(script1, cnt1_1_1_2);
    string script2 = "옷을 되찾지 못했다. 너무 춥다...피곤하고 배고프다...\n\n";
    story_script(script2, cnt1_1_1_2);
    score_inform(-10);
    cnt1_1_1_2++;

    Sleep(SLEEP_TIME1);
    
   
    rebuildStoryPath(list<char>{'3'});  // 스토리패스를 3으로 다시 만든다

    return callStoryFunc();
}

// 쫓아가는 경우
list<char> story1_1_2() 
{
    string script1 = "헉..헉..헉...\n\n";
    story_script(script1, cnt1_1_2);
    string script2 = "원숭이를 잡지 못하였다. 체력 소모가 너무 컸나보다... 배가 고프다.\n\n";
    story_script(script2, cnt1_1_2);
    score_inform(-10);
    cnt1_1_2++;

    Sleep(SLEEP_TIME1);
    rebuildStoryPath(list<char>{'3'});
    return callStoryFunc();
}

// 아이템 획득 및 사용
list<char> story1_2()
{
    string script1 = "주변을 둘러보니 생각보다 먹을 것이 많다.\n\n";
    story_script(script1, cnt1_2);
    string script2 = "탐스럽게 열린 열매와 과일들이 보인다.\n\n";
    story_script(script2, cnt1_2);
    setColor(yellow, black);
    string script3 = "[아이템] 바나나와 자몽을 얻었다!\n\n";
    UI_script(script3);
    I.banana.cnt++; // 아이템 구조체에 바나나 개수 추가
    I.grapefruit.cnt++;
    setColor(white, black);
    string script4 = "i를 눌러 인벤토리를 확인해보자.\n";
    story_script(script4, cnt1_2);
    cnt1_1++;

    return list<char>{};
}

// 인벤토리에서 바나나 사용
list<char> story1_2_1()
{
    string script1 = "원숭이에게 조심스럽게 바나나를 건넸다.\n\n";
    story_script(script1, cnt1_2_1);
    Sleep(SLEEP_TIME1);
    string script2 = "아니 이걸 거부한다고? 혼종인가 보다.\n\n";
    story_script(script2, cnt1_2_1);
    setColor(yellow, black);
    string script3 = "원숭이가 가장 좋아하는 과일은 바나나가 아닌 자몽입니다.\n\n";
    story_script(script3, cnt1_2_1);
    setColor(white, black);
    string script4 = "옷을 얻지 못했고, 너무 춥다.\n\n";
    story_script(script4, cnt1_2_1);
    score_inform(-10);

    cnt1_2_1++;

    rebuildStoryPath(list<char>{'3'}); 
    return callStoryFunc(); 
}

// 인벤토리에서 자몽 사용
list<char> story1_2_2() 
{
    string script1 = "원숭이에게 조심스럽게 자몽을 건넸다.\n\n";
    story_script(script1, cnt1_2_2);
    Sleep(SLEEP_TIME1);
    string script2 = "원숭이가 옷을 돌려주었다!\n\n";
    story_script(script2, cnt1_2_2);
    string script3 = "다행히 옷은 멀쩡하다. 앞으로는 잘 간수하도록 하자.\n\n";
    story_script(script3, cnt1_2_2);
    cnt1_2_2++;

    rebuildStoryPath(list<char>{'3'});

    return callStoryFunc();
}

// 옷을 말리지 못하는 경우
list<char> story2() 
{
    string script1 = "옷을 말리지 못해 너무 춥다.\n\n";
    story_script(script1, cnt2);
    score_inform(-10);
    string script2 = "어두워지면 체온도 더 떨어질 것 같다.\n체온 유지를 위해 어서 불이라도 피워야 할 것 같다.\n\n";
    story_script(script2, cnt2);
    string script3 = "i를 눌러 인벤토리를 확인해보자..\n";
    story_script(script3, cnt2);
    cnt2++;

    return list<char>{};
}

// 인벤토리에서 부싯돌 사용
list<char> story2_1()
{
    string script1 = "주변에 부싯돌로 쓸만한 돌이 조금 보인다.\n";
    story_script(script1, cnt2_1);
    string script2 = "생각보다 부싯돌로 불을 붙이는 건 쉬운 일이 아니다.\n\n";
    story_script(script2, cnt2_1);
    string script3 = "덜...덜...덜... 너무 춥다... 이대로...\n";
    story_script(script3, cnt2_1);
    cnt2_1++;

    print_space();
    printf(".\n");
    Sleep(SLEEP_TIME1);
    print_space();
    printf(".\n");
    Sleep(SLEEP_TIME1);
    print_space();
    printf(".\n\n\n");
    Sleep(SLEEP_TIME1);

    setColor(cyan, black); 
    print_space();
    printf("추위에 의해 저체온증으로 사망하였습니다.\n");
    setColor(white, black); 

    Sleep(SLEEP_TIME1);
    print_space();
    printf("리스폰 하려면 r을 누르시오.\n\n");

    score_inform(-100);

    while (keyCheckerIgnoreCase('r') == false)
    {
        Sleep(1);
    }

    popStoryPath();
    return callStoryFunc();
}

// 인벤토리에서 안경 사용
list<char> story2_2()
{
    string script1 = "안경의 볼록렌즈로 태양빛을 모아 불을 붙이는 데 성공하였다.\n\n";
    story_script(script1, cnt2_2);
    score_inform(10);
    string script2 = "몸이 따뜻해지니 배가 고파지기 시작한다.\n\n";
    story_script(script2, cnt2_2);

    rebuildStoryPath(list<char>{'3'});

    return callStoryFunc();
}


list<char> story3()
{
    string script1 = "체력이 더 떨어지기 전에 빨리 먹을 것을 구해야겠다.\n\n";
    story_script(script1, cnt3);
    string script2 = "이동할 수 있을만한 장소가 총 3개 정도 보인다.\n\n";
    story_script(script2, cnt3);
    cnt3++;

    loop_map(); // main.h
    return callStoryFunc();
}

// 바다를 선택한 경우
list<char> story3_1()
{
    string script1 = "어느새 바다로 왔다.\n드넓은 바다를 보니 과연 이 곳을 빠져나갈 수 있을지 막막하다.\n";
    story_script(script1, cnt3_1);
    string script2 = "바다에 검은 형체가 지나가는 것이 보인다.\n\n";
    story_script(script2, cnt3_1);
    string script3 = "모래사장 근처 떨어진 낡은 낚시대가 보인다.\n\n";
    story_script(script3, cnt3_1);
    setColor(yellow, black);
    string script4 = "[아이템] 낚시대를 얻었다!\n\n";
    UI_script(script4);
    I.fishing_rod.cnt++;
    setColor(white, black);
    string script5 = "i를 눌러 인벤토리를 확인해보자..\n\n";
    story_script(script5, cnt3_1);
    cnt3_1++;

    setColor(yellow, black);
    string scriptm1 = "----------------물고기를 잡아라! minigame 튜토리얼----------------\n\n";
    story_script(scriptm1, cnt3_1);
    string scriptm2 = "제시되는 다섯 개의 숫자 1, 2, 3, 4, 5 중 하나를 랜덤으로 선택한다.\n";
    story_script(scriptm2, cnt3_1);
    string scriptm3 = "    5개의 숫자 중 어떤 물고기, 혹은 어떤 결과가 나올지는 모른다.\n";
    story_script(scriptm3, cnt3_1);
    string scriptm4 = "                    그럼, 행운을 빈다.\n\n";
    story_script(scriptm4, cnt3_1);
    string scriptm5 = "-------------------------------------------------------------------\n\n";
    story_script(scriptm5, cnt3_1);

    setColor(white, black);
    print_space();
    printf("계속하려면 [Space바]를 누르시오.\n\n");

    while (keyCheckerIgnoreCase(' ') == false)
    {
        Sleep(1);
    }

    pushStoryPath('m');
    return callStoryFunc();
}

int cnt_fish[4]; // 스토리 반복 횟수-1 저장
int cnt_jellyfish = 0; // 해파리를 낚는 횟수

 // 물고기 미니게임
list<char> story3_1_m()
{   
    cnt_fish[0] = 0; 
    cnt_fish[1] = 0;
    cnt_fish[2] = 0;
    cnt_fish[3] = 0;

    string script1 = "1    2    3    4    5\n\n";
    story_script(script1, cnt3_1_m);
    cnt3_1_m++;


    int key = pressedKey();
    if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5') // key로 1~5의 값을 눌렀을 때,
    {
        char random = NULL;
        srand((unsigned int)time(NULL));  // seed값으로 현재 시간 부여
        random = rand() % 4 + '0'; // 난수 범위 '0'~'3'으로 한정
        while (random == '0' && cnt_jellyfish != 0) // 해파리를 낚을 때 이미 이전에 한 번 이상 낚았다면 난수를 다시 생성한다
            random = rand() % 4 + '0';
        pushStoryPath(random);

    }

    return callStoryFunc();

}

list<char> story3_1_m_0()
{
    string script1 = "해파리를 낚아버렸다! 으악!\n\n\n";
    story_script(script1);

    print_space();
    setColor(yellow, black);
    printf("해파리에 의해 감전당해 사망하였습니다.\n\n");
    setColor(white, black);

    score_inform(-100);
    cnt_jellyfish++;

    Sleep(SLEEP_TIME1);
    print_space();
    printf("리스폰 하려면 r을 누르시오.\n\n");

    while (keyCheckerIgnoreCase('r') == false)
    {
        Sleep(1);
    }

    // 스토리패스를 세 번 전의 스토리로 저장한다
    popStoryPath();
    popStoryPath();
    popStoryPath();
    return callStoryFunc();
}

list<char> story3_1_m_1()
{
    string script1 = "응? 왜 낚시줄에 돌멩이가 이끌려 나오지..? 내 실력이 부끄럽다.\n";
    story_script(script1);

    while (cnt_fish[1]--) // 물고기를 잡은 횟수가 2번 이하이면
    {
        // 물고기 미니게임을 다시 한다
        popStoryPath();
        return callStoryFunc();

    }


    rebuildStoryPath(list<char>{'3', '1', 'e'});
    return callStoryFunc();
}

list<char> story3_1_m_2()
{
    string script1 = "넙치를 낚았다! 이걸로 끼니 해결은 가능하겠군!\n";
    story_script(script1);

    score_inform(10);

    while (cnt_fish[1]--) 
    {
        
        popStoryPath();
        return callStoryFunc();

    }

    rebuildStoryPath(list<char>{'3', '1', 'e'});
    return callStoryFunc();
}

list<char> story3_1_m_3()
{
    string script1 = "송어를 낚았다! 이걸로 끼니 해결은 가능하겠군!\n\n\n";
    story_script(script1);

    score_inform(50);

    while (cnt_fish[1]--) 
    {
        
        popStoryPath();
        return callStoryFunc();

    }

    rebuildStoryPath(list<char>{'3', '1', 'e'});
    return callStoryFunc();
}

list<char> story3_1_e()
{
    string script1 = "바다 주변을 조금씩 걸으며 내가 필요한 것들을 주웠다.\n\n";
    story_script(script1, cnt3_1_e_1);
    string script2 = "빈 캔, 녹슨 철제, 다 헤진 그물망...\n\n";
    story_script(script2, cnt3_1_e_1);
    string script3 = "잠깐...\n";
    story_script(script3, cnt3_1_e_1);
    string script4 = "잠깐...\n\n";
    story_script(script4, cnt3_1_e_1);
    string script5 = "저기 모래사장 근처 뗏목이 희미하게 보였다.\n\n";
    story_script(script5, cnt3_1_e_1);
    string script6 = "가까이 다가가니 뗏목이 확실했다.\n 상태가 많이 좋지는 않았지만 그래도 쓸만해 보였다.\n\n";
    story_script(script6, cnt3_1_e_1);
    string script7 = "이런 뗏목이 섬에 그냥 널려있을리가 없다.\n\n";
    story_script(script7, cnt3_1_e_1);

    print_space();
    printf("1. 이 섬에 나와 같은 다른 누군가가 만든 것일 수 있다.\n 함부로 가져가서는 안된다.\n");
    print_space();
    printf("2. 누구 것이고 아닌게 어딨어? 지금 가져가는 사람이 임자다.\n 이 섬에 더 있다가는 내가 죽는다.\n");

    return list<char>{'1', '2'};
}

// 배 훔치지 않은 경우
list<char> story3_1_e_1()
{
    string script1 = "아쉬움을 한가득 남긴채 뗏목을 그냥 두었다.\n\n";
    story_script(script1, cnt3_1_e_1_1);
    string script2 = "주인이 올 때까지 기다려보는 것도 방법이다.\n\n";
    story_script(script2, cnt3_1_e_1_1);
    string script3 = "뗏목에 앉아 주인을 하염없이 계속 기다렸다.\n\n";
    story_script(script3, cnt3_1_e_1_1);

    print_space();
    printf(".\n");
    Sleep(SLEEP_TIME1);
    print_space();
    printf(".\n");
    Sleep(SLEEP_TIME1);
    print_space();
    printf(".\n");

    system("cls");
    setColor(lightgreen, black);
    string script4 = "[??] : 저기...저기...\n\n";
    story_script(script4, cnt3_1_e_1_1);
    setColor(white, black);
    string script5 = "누군가 나를 흔들어깨웠다. 눈을 깜빡거리면서 일어났다.\n\n";
    story_script(script5, cnt3_1_e_1_1);
    setColor(white, black);
    string script6 = "[??] : 이거 제 뗏목인데...\n\n";
    story_script(script6, cnt3_1_e_1_1);
    cnt3_1_e_1_1++;

    print_space();
    printf("1. 네, 저도 압니다! 혹시 같이 탈출하실 수...있을까요?\n");
    print_space();
    printf("2. 아닌데요? 이거 제가 만들었는데요?\n");

    return list<char>{'1', '2'};
}

//함께 타고 가는 엔딩
list<char>story3_1_e_1_1()
{
    setColor(lightgreen, black);
    string script1 = "[??] : 그럼 같이 가시죠! 빨리 탈출합시다!\n\n";
    story_script(script1, cnt3_1_e_1_1_1);
    setColor(white, black);
    string script2 = "그렇게 나는 그와 함께 뗏목을 타고 바다를 건너기 시작하였다.\n\n";
    story_script(script2, cnt3_1_e_1_1_1);
    string script3 = "오랜 시간 이동하면서 그가 가진 식량을 나눠먹었다.\n\n";
    story_script(script3, cnt3_1_e_1_1_1);
    string script4 = "뗏목을 타고 끝이 보이지 않는 바다를 항해하며 그 이가 어쩌다 이 섬에 갇혔는지도 듣게 되었다.\n\n";
    story_script(script4, cnt3_1_e_1_1_1);
    string script5 = "확실한 건. 난 정말 운이 좋은 것이라는 거다.\n\n";
    story_script(script5, cnt3_1_e_1_1_1);
    string script6 = "그가 뗏목까지 만들어야 했던 시간에 비하면 정말 빨리 이 섬을 탈출하게 되었으니...\n\n";
    story_script(script6, cnt3_1_e_1_1_1);

    print_space();
    printf(".\n");
    Sleep(SLEEP_TIME1);
    print_space();
    printf(".\n");
    Sleep(SLEEP_TIME1);
    print_space();
    printf(".\n");

    system("cls");
    string script7 = "긴 시간이 지났고 우리는 운이 좋게 구조 헬기를 발견했다.\n\n";
    story_script(script7, cnt3_1_e_1_1_1);
    string script8 = "열심히 구조요청을 한 끝에 너무나 다행히 우리는 안전히 구조되었고\n";
    story_script(script8, cnt3_1_e_1_1_1);
    string script9 = "우리의 이야기는 뉴스 기사로 실리기도 하였다.\n\n";
    story_script(script9, cnt3_1_e_1_1_1);
    string script10 = "만약 내가 그 날 뗏목을 발견하지 않았더라면 과연 어떤 일이 일어났을지...\n\n\n";
    story_script(script10, cnt3_1_e_1_1_1);

    Sleep(SLEEP_TIME1);

    string script11 = "별로 상상하고 싶지는 않다.\n";
    story_script(script11, cnt3_1_e_1_1_1);
    cnt3_1_e_1_1_1++;
    Sleep(SLEEP_TIME1);
    rebuildStoryPath(list<char>{'e'});
    return callStoryFunc();
}

// 시치미 떼는 경우
list<char>story3_1_e_1_2()
{
    string script1 = "그가 나를 어이 없다는듯이 뚫어져라 쳐다봤다.\n\n";
    story_script(script1, cnt3_1_e_1_1_2);
    string script2 = "어서 수습해야 탈출할 수 있겠다고 느낀 나는\n빠르게 사과하고 도와달라고 부탁하였다.\n\n";
    story_script(script2, cnt3_1_e_1_1_2);
    cnt3_1_e_1_1_2++;
    
    popStoryPath();
    pushStoryPath('1');

    return callStoryFunc();
}

list<char> story3_1_e_2() //배 훔쳐간 경우
{
    string script1 = "빠르게 뗏목을 출발시키기 위해 준비했다.\n\n";
    story_script(script1, cnt3_1_e_1_2);
    string script2 = "옆에 있는 통나무의 가지를 뜯어 뗏목의 노로 사용해야겠다.\n\n";
    story_script(script2, cnt3_1_e_1_2);
    string script3 = "출발하려 하는데 저 멀리서 누군가 뛰어온다. 엄청 빠르다.\n\n";
    story_script(script3, cnt3_1_e_1_2);
    string script4 = "뗏목 주인인가 보다! 큰일이다 빨리 도망쳐야 한다.\n";
    story_script(script4, cnt3_1_e_1_2);
    string script5 = "노를 젓기 위해 가지를 물에 넣는 순간,\n무언가 뾰족한 것이 나의 목 뒤를 강타하였다.\n\n";
    story_script(script5, cnt3_1_e_1_2);
    string script6 = "서서히 시야가 흐려진다...\n";
    story_script(script6, cnt3_1_e_1_2);
    cnt3_1_e_1_2++;

    print_space();
    printf(".\n");
    Sleep(SLEEP_TIME1);
    print_space();
    printf(".\n");
    Sleep(SLEEP_TIME1);
    print_space();
    printf(".\n");
    Sleep(SLEEP_TIME1);

    setColor(red, black); 
    print_space();
    printf("알 수 없는 이의 화살을 맞고 사망하였습니다.\n");
    setColor(white, black); 

    score_inform(-100);
    
    Sleep(SLEEP_TIME1);
    print_space();
    printf("리스폰 하려면 r을 누르시오.\n\n");

    while (keyCheckerIgnoreCase('r') == false)
    {
        Sleep(1);
    }

    popStoryPath();

    return callStoryFunc();
}

list<char> story3_2() //강으로
{
    string script1 = "어느새 강에 도착했다.\n";
    story_script(script1, cnt3_2);
    string script2 = "사실 이곳에 와서 저 높은 곳에 폭포가 있다는 것을 알고\n직감적으로 강이 있음을 인지했다.\n\n";
    story_script(script2, cnt3_2);
    string script3 = "강은 생각보다 길고 넓어서강의 하류로 걸어 내려가고자 한다.\n\n";
    story_script(script3, cnt3_2);

    string script4 = "계속 걷다보니 마을로 추정되는 것이 보이기 시작한다!\n드디어 머무를 곳이 생긴 것인가?\n\n";
    story_script(script4, cnt3_2);
    string script5 = "마을 정문으로 가니 문지기로 추정되는 사람이 말을 걸었다.\n\n";
    story_script(script5, cnt3_2);

    setColor(lightgreen, black);
    string script6 = "[문지기] : 길을 잃으셨나요?\n\n";
    story_script(script6, cnt3_2);
    cnt3_2++;

    setColor(white, black);
    print_space();
    printf("1. 예. 혹시 제가 머무를 곳이라도 있나요?\n");
    print_space();
    printf("2. 아니요. 저도 이 섬 주민입니다. ^^\n\n");

    return list<char>{'1', '2'};
}

list<char> story3_2_1()
{
    setColor(lightgreen, black);
    string script1 = "[문지기] : 저희가 꼭 그래야 하는 이유가 있나요?\n\n";
    story_script(script1, cnt3_2_1);
    cnt3_2_1++;

    setColor(white, black);
    print_space();
    printf("1. 제가 가진 것들이 좀 있어요!\n");
    print_space();
    printf("2. 글쎄요 있을까요?\n\n");

    return list<char>{'1', '2'};
}


list<char> story3_2_1_1() 
{
    string script1 = "i를 눌러 인벤토리를 확인해보자.";
    story_script(script1);

    return list<char> {};
}

list<char> story3_2_1_2()
{
    setColor(lightgreen, black);
    string script1 = "[문지기] : (뭐지 이 싸가지는...?) 그렇다면 이만 돌아가시죠.\n\n";
    story_script(script1);
    setColor(white, black);
    string script2 = "그렇게 나는 그곳에서 쫓겨나고 말았다.\n\n";
    story_script(script2);
    
    Sleep(SLEEP_TIME1);
    popStoryPath();
    popStoryPath();

    return callStoryFunc();

}

list<char> story3_2_2()
{
    setColor(lightgreen, black);
    string script1 = "[문지기] : 그렇다면 이만 돌아가시죠.\n\n";
    story_script(script1);
    setColor(white, black);
    string script2 = "그렇게 나는 그곳에서 쫓겨나고 말았다.\n\n";
    story_script(script2);

    Sleep(SLEEP_TIME1);
    popStoryPath();
    popStoryPath();

    return callStoryFunc();

}

list<char> story3_2_e_1()
{
    string script1 = "나는 문지기에게 동전을 건넸다.\n\n";
    story_script(script1, cnt3_2_e_1);
    string script2 = "그들은 반짝이는 동전을 귀하게 여겼고, 나를 극진히 대접했다.\n\n";
    story_script(script2, cnt3_2_e_1);
    string script3 = "그렇게 나는 그들과 함께 구성원의 일부로서 살아갔다.\n\n";
    story_script(script3, cnt3_2_e_1);
    string script4 = "솔직히 말해서 초반에는 힘들었다.\n내가 그동안 살아온 방식과는 많이 달랐기에.\n\n";
    story_script(script4, cnt3_2_e_1);
    string script5 = "그들이 말하는대로, 그들이 먹는대로, 그들이 입는대로 생활했다.\n\n";
    story_script(script5, cnt3_2_e_1);
    string script6 = "어느새 나는 내가 원래부터 그들과 하나였다고 생각하고 살아가고 있었다.\n\n";
    story_script(script6, cnt3_2_e_1);
    string script7 = "어느새 이 섬에 산 지...\n";
    story_script(script7, cnt3_2_e_1);
    string script8 = "453일이 지났다.\n";
    story_script(script8, cnt3_2_e_1);
    cnt3_2_e_1++;

    Sleep(SLEEP_TIME1);
    rebuildStoryPath(list<char>{'e'});

    return callStoryFunc();
}

list<char> story3_3() //숲으로
{
    string script1 = "푸르른 풀 냄새로 가득한 녹음으로 이루어진 울창한 숲 앞에 도착하였다.\n";
    story_script(script1, cnt3_3);
    string script2 = "굳이 짐승이 아니더라도 숲이다 보니 뭐라도 먹을게 있지 않을까..?\n\n";
    story_script(script2, cnt3_3);
    string script3 = "앗! 저기 토끼가 지나간다! 더 멀어지기 전에 빨리 잡아야 한다!\n\n";
    story_script(script3, cnt3_3);
    string script4 = "어서 토끼를 잡아보자!\n\n\n";
    story_script(script4, cnt3_3);
    cnt3_3++;

    setColor(yellow, black);
    string scriptm1 = "------------------토끼를 잡아라!minigame 튜토리얼------------------\n\n";
    story_script(scriptm1, cnt3_3);
    string scriptm2 = "         현재 토끼가 보이지 않는 상황에서 갈림길에 도착하면\n";
    story_script(scriptm2, cnt3_3);
    string scriptm3 = "         빠르게 왼쪽(방향키) 또는 오른쪽을(방향키) 선택한다.\n";
    story_script(scriptm3, cnt3_3);
    string scriptm4 = "    한 번의 선택을 할 때 마다 토끼를 만날 수도, 못 만날 수도 있다. \n";
    story_script(scriptm4, cnt3_3);
    
    string scriptm5 = " 갈림길을 총 5번 만나게 되며 3번 이상 만났다면 토끼를 잡는데 성공한다!\n\n";
    story_script(scriptm5, cnt3_3);
    string scriptm6 = "-----------------------------------------------------------------------\n\n";
    story_script(scriptm5, cnt3_3);

    printf("계속하려면 [Space바]를 누르시오.\n\n");
    setColor(white, black);

    while (keyCheckerIgnoreCase(' ') == false)
    {
        Sleep(1);
    }

    pushStoryPath('m');
    return callStoryFunc();
}

int bunnycatch = 0;
list<char> story3_3_m()
{
    string script1 = "저기 지나간 흔적이 보인다! 갈림길이 있군!\n\n";
    story_script(script1, cnt3_3_m);
    cnt3_3_m++;

    int cnt = 5;
    int answer[5] = { '1','2','1','2','2' };

    while (cnt--)
    {
        gotoxy(17, 15);
        printf("왼쪽\n\n");
        gotoxy(37, 15);
        printf("오른쪽");

        if (_kbhit())
        {
            int key1 = _getch();
            int key2 = _getch();
            if (answer[5 - cnt] == key2)
            {
                system("cls");
                gotoxy(28, 15);
                printf("잡았다");
                bunnycatch++;
            }
            else
            {
                system("cls");
                gotoxy(28, 15);
                printf("놓쳤다");
            }

            Sleep(SLEEP_TIME1);
            system("cls");
        }
    }

        
    if (bunnycatch != 0)
    {
        string script1 = "이걸로 끼니 해결은 가능하겠군!";
        story_script(script1, cnt3_3);
        int score = 10*bunnycatch;
        score_inform(10 * bunnycatch);
    }
    else
    {
        string script1 = "토끼를 잡지 못했다. 너무 배고프다\n";
        story_script(script1, cnt3_3);
        score_inform(-10);
    }

    popStoryPath();
    pushStoryPath('e');
    pushStoryPath('1');

    return callStoryFunc();
}



list<char> story3_3_e_1()
{
    string script1 = "어두워지면 알 수 없는 짐승들과 추위 때문에 위험하다.\n";
    story_script(script1, cnt3_3_1);
    string script2 = "어서 나를 보호할 수 있는 집을 지어야 한다.\n\n";
    story_script(script2, cnt3_3_1);
    cnt3_3_1++;

    string script3 = "인벤토리 속에 사용할만한 나무가 있는지 확인해보자.\n"; 
    story_script(script3, cnt3_3_1);

    Sleep(SLEEP_TIME1);
    popStoryPath();
    return callStoryFunc();
}

list<char> story3_3_e_2()
{
    string script1 = "이 정도면 집을 짓기에 충분하다. 어서 나무 집을 지어보자.\n\n";
    story_script(script1, cnt3_3_2);

    printf(".\n\n");
    Sleep(SLEEP_TIME1);
    printf(".\n\n");
    Sleep(SLEEP_TIME1);
    printf(".\n\n\n");

    string script2 = "그렇게 나는 무사히 나무 집을 지었고 조금씩 식량을 모으며 어느 정도 정착하였다.\n\n";
    story_script(script2, cnt3_3_2);
    string script3 = "집도 서서히 넓혀갔고 섬의 구조도 누구보다 잘 알게 되었다.\n\n";
    story_script(script3, cnt3_2_2);
    string script4 = "탈출에 대한 희망은 버린지 오래...\n\n";
    story_script(script4, cnt3_2_2);
    string script5 = "어느새 이 섬에 산 지......\n\n\n";
    story_script(script5, cnt3_2_2);
    string script6 = "453일이 지났다.\n";
    story_script(script6, cnt3_2_2);
    cnt3_2_2++;

    Sleep(SLEEP_TIME1);
    rebuildStoryPath(list<char>{'e'});

    return callStoryFunc();
}

list<char> story_e()
{
    setColor(yellow, black);
    string script1 = "다른 엔딩이 궁금하지 않으신가요?\n\n";
    story_script(script1);
    string script2 = "게임을 다시 플레이하여 여러 엔딩을 경험해보세요.\n\n";
    story_script(script2);

    gotoxy(UI_POS_X + 1, UI_POS_Y + 1);
    printf("플레이어의 점수는 %d점 입니다", totalscore);
}
