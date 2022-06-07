#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <map>
#include <list>
#include <string>

#include "main.h"
#include "story.h"
#include "storylib.h"
#include "util.h"
#include "design.h"

#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS

// 키보드 키의 아스키 코드 값
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27
#define SPACE 32

// 인벤토리 출력 위치
#define INVENTORY_POS_X 4
#define INVENTORY_POS_Y 1

using namespace std;

// 전역변수

extern inventory I; // 인벤토리

// 맵에서 커서(@)를 움직일 수 있는 범위
POS_BOUND map_bound = { 1, MAP_SIZE_X - 2, 1, MAP_SIZE_Y - 2 };
POS_BOUND* p_map_bound = &map_bound;
// 메뉴에서 커서(>)를 움직일 수 있는 범위
POS_BOUND menu_bound = { MENU_POS_X, MENU_POS_X, MENU_POS_Y, MENU_POS_Y+2 };
POS_BOUND* p_menu_bound = &menu_bound;
// 인벤토리에서 커서(>)를 움직일 수 있는 범위
POS_BOUND inventory_bound = { INVENTORY_POS_X, INVENTORY_POS_X, INVENTORY_POS_Y, INVENTORY_POS_Y-1 };
POS_BOUND* p_inventory_bound = &inventory_bound;

// 인벤토리 안내 함수
void inventory_inform()
{
    gotoxy(UI_POS_X + 1, UI_POS_Y + 1);
    printf("아이템을 사용하려면 [space]를 누르세요");

    gotoxy(UI_POS_X + 1, UI_POS_Y + 2);
    printf("종료하려면 [esc]를 누르세요");
}

// 아이템 출력함수
void print_item(ITEM item)
{
    if (item.cnt == 0) // 해당 아이템이 없다면,
        return; // 아무 일도 하지 않는다
    else // 해당 아이템이 있다면,
    {
        gotoxy(INVENTORY_POS_X+2, INVENTORY_POS_Y+item.index); // index에 맞는 y위치에서
        setColor(yellow, black);
        printf("[%s]", item.name.c_str()); // 아이템 이름을 출력하고,
        setColor(white, black);
        printf("%s", item.detail.c_str()); // 아아템 설명을 출력한다
    }
}

// 아이템을 사용할 수 없을 때 안내하는 함수
void inventory_exception()
{
    gotoxy(UI_POS_X + 1, UI_POS_Y + 1);
    printf("                                      ");
    gotoxy(UI_POS_X + 1, UI_POS_Y + 2);
    printf("                           ");
    gotoxy(UI_POS_X + 1, UI_POS_Y + 1);
    printf("지금은 아이템을 사용할 수 없습니다.");
    Sleep(500);
    gotoxy(UI_POS_X + 1, UI_POS_Y + 1);
    printf("                                   ");

    Sleep(500);
    inventory_inform();
}

void print_inventory()
{
    cursor_visible(false); // 커서를 보이게 한다
    setColor(white, black);
    print_UI_boundary();

    // 사용할 수 있는 아이템에 0~의 인덱스를 부여한다.
    I.glasses.index = 0;
    I.coin.index = 1;
    int index = 2;
    if (I.firestone.cnt != 0)
        I.firestone.index = index++;
    if (I.banana.cnt != 0)
        I.banana.index = index++;
    if (I.grapefruit.cnt != 0)
        I.grapefruit.index = index++;
    if (I.fishing_rod.cnt != 0)
        I.fishing_rod.index = index++;
    
    inventory_bound.y_max += index;

    // 위에서부터 순서대로 아이템 목록을 출력한다.
    gotoxy(INVENTORY_POS_X, INVENTORY_POS_Y);
    printf("> ");
    print_item(I.banana);
    print_item(I.coin);
    print_item(I.firestone);
    print_item(I.fishing_rod);
    print_item(I.glasses);
    print_item(I.grapefruit);

    // 하단 UI에 출력
    gotoxy(UI_POS_X+1, UI_POS_Y + 1);
    printf("아이템을 사용하려면 [space]를 누르세요");
    
    gotoxy(UI_POS_X + 1, UI_POS_Y + 2);
    printf("종료하려면 [esc]를 누르세요");
    
    POS pos = { INVENTORY_POS_X, INVENTORY_POS_Y };
    gotoxy(pos.x, pos.y); //  >가 출력되었던 위치로 커서 이동
    POS* p_inventory_pos = &pos;
    while (1)
    {
        if (kbhit()) // 키 입력이 있으면,
        {
            //getch() 함수를 이용해서 방향키 값을 읽어들이면 두 번 반환한다
            int key = getch(); // 입력받은 키의 아스키 코드 값을 저장한다
            if (key == 224) // 키가 방향키라면
            {
                int sub_key = getch(); // 입력받은 키의 아스키 코드
                if (sub_key == UP || sub_key == DOWN)
                    move_cursor(p_inventory_pos, p_inventory_bound, sub_key, '>');
            }

            else if (key == ESC)
                return;
            else if (key == SPACE)
            {
                string storyKey = buildStoryKey(); // 현재 스토리 이름을 저장한다
                if (pos.y == INVENTORY_POS_Y + I.firestone.index) // 부싯돌을 사용했을 때,
                {
                    if (find(I.firestone.available_story.begin(), I.firestone.available_story.end(), storyKey) != I.firestone.available_story.end()) // I.firestone 리스트에 현재 스토리가 있다면,
                    {
                        if (storyKey == "1_1") // 현재 스토리가 1_1이라면,
                        {
                            pushStoryPath('3'); // 스토리패스를 1_1_3으로 만든다
                            return;
                        }

                        if (storyKey == "1_1_1") // 현재 스토리가 1_1이라면,
                        {
                            popStoryPath();
                            pushStoryPath('3'); // 스토리패스를 1_1_3으로 만든다
                            return;
                        }

                        if (storyKey == "2") 
                        {
                            pushStoryPath('1');
                            return;
                        }
                    }
                    else
                    {
                        inventory_exception();
                    }
                }
                else if (pos.y == INVENTORY_POS_Y + I.glasses.index) // 안경을 사용했을 때,
                {
                    if (find(I.glasses.available_story.begin(), I.glasses.available_story.end(), storyKey) != I.glasses.available_story.end()) // I.glasses 리스트에 현재 스토리가 있다면,
                    {
                        if (storyKey == "2")
                        {
                            pushStoryPath('1');
                            return;
                        }
                        else
                        {
                            inventory_exception();
                        }
                    }
                }
                else if (pos.y == INVENTORY_POS_Y + I.coin.index) // 동전을 사용했을 때,
                {
                    if (find(I.coin.available_story.begin(), I.coin.available_story.end(), storyKey) != I.coin.available_story.end()) // I.coin 리스트에 현재 스토리가 있다면,
                    {
                        if (storyKey == "3_2_2_1")
                        {
                            rebuildStoryPath(list<char>{'3', '2', 'e', '1'});
                            return;
                        }
                    }
                    else
                    {
                        inventory_exception();
                    }
                }
                else if (pos.y == INVENTORY_POS_Y+I.banana.index) // 바나나를 사용했을 때,
                {
                    if (find(I.banana.available_story.begin(), I.banana.available_story.end(), storyKey) != I.banana.available_story.end()) // I.banana 리스트에 현재 스토리가 있다면,
                    {
                        if (storyKey == "1_2")
                        {
                            pushStoryPath('1');
                            return;
                        }
                    }
                    else
                    {
                        inventory_exception();
                    }
                }
                else if (pos.y == INVENTORY_POS_Y+I.grapefruit.index) // 자몽을 사용했을 때, 
                {
                    if (find(I.grapefruit.available_story.begin(), I.grapefruit.available_story.end(), storyKey) != I.grapefruit.available_story.end()) // I.grapefruit 리스트에 현재 스토리가 있다면,
                    {
                        if (storyKey == "1_2")
                        {
                            pushStoryPath('2');
                            return;
                        }
                    }
                    else
                    {
                        inventory_exception();
                    }
                }
            }


        }

    }
}

/*
    키를 입력받아 스토리를 진행
*/
void loop_story()
{
    system("cls");
    list<char> options = callStoryFunc();

    while (1)
    {
        if (kbhit())
        {
            int key = getch(); // 입력받은 키의 아스키 코드 값을 저장한다
            switch (key)
            {
            case 0:
                break;
            case ESC:
                options = callStoryFunc();
                break;
            case 'i':
            case 'I':
                system("cls");
                print_inventory();
                options = callStoryFunc();
                break;
            default:
                // 선택 옵션 i
                if (find(options.begin(), options.end(), (char)key) != options.end())
                {
                    pushStoryPath((char)key);
                    options = callStoryFunc(); // 스토리 함수를 호출하고 다음 스토리 선택지를 지정
                }
                break;
            }
            key = 0;
        }
    }
}

void story3_inform()
{
    gotoxy(UI_POS_X + 1, UI_POS_Y);
    printf("1. 물고기가 파닥파닥 바다로 이동해본다.\n");
    gotoxy(UI_POS_X + 1, UI_POS_Y + 2);
    printf("2. 저 높이 보이는 폭포 아래 있을 법한 강으로 이동해본다.\n");
    gotoxy(UI_POS_X + 1, UI_POS_Y + 3);
    printf("3. 짐승들이 숨어있을 법한 밀집한 숲으로 이동해본다.\n");
}


void loop_map()
{
    system("cls");
    print_map_boundary();
    POS map_pos = { 30, map_bound.y_max };
    gotoxy(map_pos.x, map_pos.y);
    printf("@");
    story3_inform();
    while (1)
    {
           if (map_pos.y == map_bound.x_min)
          {
              pushStoryPath('1');
              return;
          }

          if (map_pos.x == map_bound.y_max)
          {
              pushStoryPath('2');
              return;
          }

          if (map_pos.x == map_bound.x_max)
          {
              pushStoryPath('3');
              return;
          }

      if (kbhit())
        {
            int key = getch(); // 입력받은 키의 아스키 코드 값을 저장한다
            if (key == 224)
            {
                int sub_key = getch();
                move_cursor(&map_pos, p_map_bound, sub_key, '@');
            }

            else
            {
                switch (key)
                {
                case 0:
                    break;
                case ESC:
                    system("cls");
                    print_map_boundary();
                    gotoxy(map_pos.x, map_pos.y);
                    printf("@");
                    break;
                case 'i':
                case 'I':
                    system("cls");
                    print_inventory();
                    break;
                }
                key = 0;
            }
        }
        }
    }



int main()
{
    init();
    print_menu();
    system("cls");
    gotoxy(0, 0);
    story_intro();

    print_map_boundary();
    gotoxy(34, 13);
    printf("@");
    print_UI_boundary();
    story_init();

    gotoxy(UI_POS_X + 1, UI_POS_Y + 1);
    printf("space를 눌러 잠에서 깨어나시오");
    while (keyCheckerIgnoreCase(' ') == false)
    {
        Sleep(100);
    }
    system("cls");
    loop_story();
}

void print_menu()
{
    cursor_visible(false);
    printf(" -----------------------------------------------\n");
    printf("|                                               |\n");
    printf("|");
    setColor(yellow, black);
    printf("              무인도 ");
    setColor(white, black);
    printf("에서 살아남기             |\n");
    printf("|                                               |\n");
    printf("|                                               |\n");
    printf(" -----------------------------------------------\n");

    POS menu_pos = { MENU_POS_X, MENU_POS_Y };
    gotoxy(menu_pos.x, menu_pos.y);
    printf("> 게임시작");
    gotoxy(menu_pos.x + 1, menu_pos.y + 1);
    printf(" 게임정보");
    gotoxy(menu_pos.x + 2, menu_pos.y + 2);
    printf("  종료  ");
    while (1) { // 무한반복  
        gotoxy(menu_pos.x, menu_pos.y); //  >가 출력되었던 위치로 커서 이동
        POS* p_menu_pos = &menu_pos;
        while (1)
        {
            if (kbhit()) // 키 입력이 있으면,
            {
                //getch() 함수를 이용해서 방향키 값을 읽어들이면 두 번 반환한다
                int key = getch(); // 입력받은 키의 아스키 코드 값을 저장한다
                if (key == 224) // 키가 방향키라면
                {
                    int sub_key = getch(); // 입력받은 키의 아스키 코드
                    if (sub_key == UP || sub_key == DOWN)
                        move_cursor(p_menu_pos, p_menu_bound, sub_key, '>');
                }

                else if (key == SPACE)
                {
                    if (menu_pos.y == 24)
                        return;
                    else if (menu_pos.y == 25)
                        return;
                }
            }
        }
    }
}
