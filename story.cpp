#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <list>
#include <iostream>

#include "util.h"
#include "storylib.h"
#include "story.h"


#define SLEEP_TIME 1000
#define SLEEP_TIME2 50

using namespace std;

int totalscore = 100;
int bunnycatch = 0;

extern status M;      // ����   - �ܺ� �������� ����

/*
   ���丮 �Լ��� Ű�� �����Ͽ� �ʱ�ȭ
*/
void story_init()
{
    addStory(string("intro"), story_intro);
    addStory(string("begin"), story_begin);
    addStory(string("1"), story1);
    addStory(string("1_1"), story1_1);
    addStory(string("1_2"), story1_2);
    addStory(string("1_1_1"), story1_1_1);
    addStory(string("1_1_2"), story1_1_2);
    addStory(string("1_2_1"), story1_2_1);
    addStory(string("1_2_1_1"), story1_2_1_1);
    addStory(string("1_2_1_2"), story1_2_1_2);
    addStory(string("1_2_2"), story1_2_2);

    addStory(string("2"), story2);
    addStory(string("2_1"), story2_1);
    addStory(string("2_2"), story2_2);

    addStory(string("3"), story3);
    addStory(string("3_1"), story3_1);
    addStory(string("3_1_m"), story3_1_m);
    addStory(string("3_1_m_1"), story3_1_m_1);
    addStory(string("3_1_m_2"), story3_1_m_2);
    addStory(string("3_1_m_3"), story3_1_m_3);
    addStory(string("3_1_m_4"), story3_1_m_4);
    addStory(string("3_1_m_5"), story3_1_m_5);

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


}

void setcolor(int color, int bgcolor)

{
    color &= 0xf;
    bgcolor &= 0xf;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

int cntintro = 0;
int cntbegin = 0;
int cnt1 = 0;
int cnt1_1 = 0;
int cnt1_1_1 = 0;
int cnt1_1_2 = 0;
int cnt1_2 = 0;
int cnt1_2_1 = 0;
int cnt1_2_1_1 = 0;
int cnt1_2_1_2 = 0;
int cnt1_2_2 = 0;
int cnt2 = 0;
int cnt2_1 = 0;
int cnt2_2 = 0;
int cnt3 = 0;
int cnt3_1 = 0;
int cnt3_1_m = 0;
int cnt3_1_m_1 = 0;
int cnt3_1_m_2 = 0;
int cnt3_1_m_3 = 0;
int cnt3_1_m_4 = 0;
int cnt3_1_m_5 = 0;
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


void scriptEx(string script, int cnt)
{
    for (int i = 0; i < script.length(); i++)
    {
        printf("%c", script[i]);
        if (cnt == 0)
            Sleep(SLEEP_TIME2);
    }

    if (cnt == 0)
        Sleep(SLEEP_TIME);
}

list<char> story_intro()
{
    string script1 = "�� ������ �÷��̾��� ���ÿ� ���� ���丮�� �¿�˴ϴ�. \n\n";
    scriptEx(script1, cntintro);
    string script2 = "�����ϰ� �����Ͽ� �÷����Ͻñ� �ٶ��ϴ�. \n\n";
    scriptEx(script2, cntintro);
    cntintro++;

    return list<char>{};
}

list<char> story_begin()
{
    string script1 = "���ű� �Ҹ��� �Բ� ���� ����.\n";
    scriptEx(script1, cntbegin);
    string script2 = "�հ����� ��Ʋ�Ÿ��� õõ�� �Ͼ�µ�, �̷�... ���� �� ������. \n\n";
    scriptEx(script2, cntbegin);

    printf("1. ���� ������ �ɾ� ��� �����д�. \n");
    printf("2. ���� ������ �ʴ´�. \n\n");
    cntbegin++;

    return list<char>{'1', '2'};
}

list <char> story1()
{
    string script1 = "�����̰� �� ���� ��������! \n\n";
    scriptEx(script1, cnt1);
    string script2 = "��ó�� ���� ���� �̸� ��������. \n\n";
    scriptEx(script2, cnt1);

    printf("1. �����̸� �޷�����. \n");
    printf("2. ���������̾�. �ο��� �������� ��! \n\n");
    cnt1++;

    return list<char>{'1', '2'};
}



list<char> story1_1()
{
    string script1 = "�ֺ��� �ѷ����� �������� ���� ���� ���� ���� ���̴�. \n\n";
    scriptEx(script1, cnt1_1);
    string script2 = "Ž������ ���� ���ſ� ���ϵ��� ���δ�. \n������ �ٰ����� �ٳ����� �ڸ��� ���δ�. \n\n";
    scriptEx(script2, cnt1_1);
    string script3 = "���� ���� �͵� �� �ϳ��� Ȱ���غ���. \n";
    scriptEx(script3, cnt1_1);
    cnt1_1++;

    return list<char>{};
}

list<char> story1_1_1() // �κ��丮���� �ٳ��� ���
{
    string script1 = "�����̿��� ���ɽ����� �ٳ����� �ǳ޴�. \n";
    scriptEx(script1, cnt1_1_1);
    string script2 = "�ƴ� �̰� �ź��Ѵٰ�? ȥ���ΰ� ����. \n\n";
    scriptEx(script2, cnt1_1_1);
    M.Hp -= 10; //Hp �ϰ�
    string script3 = "���� ���� ���߰�, �ʹ� ���. \n\n";
    scriptEx(script3, cnt1_1_1);
    cnt1_1_1++;

    rebuildStoryPath(list<char>{'3'});

    return callStoryFunc();
}

list<char> story1_1_2() // �κ��丮���� �ڸ� ���
{
    string script1 = "�����̿��� ���ɽ����� �ڸ��� �ǳ޴�. \n";
    scriptEx(script1, cnt1_1_2);
    string script2 = "�����̰� ���� �����־���!\n\n";
    scriptEx(script2, cnt1_1_2);
    string script3 = "������ �� �ȿ� �ִ� �ָӴ�Į�� �����ϴ�. �� �� �����ϵ��� ����. \n\n";
    cnt1_1_2++;

    rebuildStoryPath(list<char>{'3'});

    return callStoryFunc();
}

list<char>story1_2() //�ο�� ���
{
    M.Hp -= 10;
    string script1 = "���� �ο���� ������ �����ϴ�. \n�����̿� �� ���� �������� �� �� ���� �귶��. \n";
    scriptEx(script1, cnt1_2);
    string script2 = "�̰� ����� �������� �带 ���ΰ�. \n���� �ൿ�� �������ؾ߰ڴ�. \n";
    scriptEx(script2, cnt1_2);
    string script3 = "���ڱ� �����̰� ��������! \n�̴�� �������� ���� �Ҵ´�! \n\n";
    cnt1_2++;

    printf("1. �ٴڿ� �����ٴϴ� �� �ƹ��ų� �ֿ��� �ϴ� ��������. \n");
    printf("2. �ƴϴ� �̰� ��ƾ� �Ѵ�! \n�����̸� �Ѿư���! \n");

    return list<char>{'1', '2'};
}

list<char> story1_2_1() //�� ������ ���
{
    string script1 = "�� �� �������Ҵµ� �ϴٵ� ���� �ʴٴ�... \n";
    scriptEx(script1, cnt1_2_1);
    string script2 = "������ �õ�... ���� �� ������ ��������... \n\n";
    scriptEx(script2, cnt1_2_1);
    cnt1_2_1++;

    printf("1. ���� �������� ������. \n");
    printf("2. ���� ���������� ������. \n");

    return list<char>{'1', '2'};
}

list<char> story1_2_1_1() //�������� ���� ���
{
    string script1 = "��! �̰� ���ߴٴ�! \n�����̰� ���� ���� �°� ��������! \n";
    scriptEx(script1, cnt1_2_1_1);
    Sleep(SLEEP_TIME);
    string script2 = "���� �̻��ϴ�... \n��𼱰� �������� �޷����� �Ҹ��� �鸰��. \n\n";
    scriptEx(script2, cnt1_2_1_1);
    cnt1_2_1_1++;

    printf(".\n");
    Sleep(SLEEP_TIME);
    printf(".\n");
    Sleep(SLEEP_TIME);
    printf(".\n");
    Sleep(SLEEP_TIME);

    setcolor(12, 0); //������ ������
    printf("������ ���ܿ� ���� ����Ͽ����ϴ�.\n");
    setcolor(15, 0);
    Sleep(SLEEP_TIME); //��� ������
    printf("������ �Ϸ��� 1�� �����ÿ�. \n\n");

    /*
    int respawn;
    scanf("%d", &respawn);
    if (respawn == 1)
    {
        popStoryPath();
        return story1_2_1();
    }
    */
    //�ƴ� ���� ��� ����?

    totalscore += 100;

    while (keyCheckerIgnoreCase('1') == false)
    {
        Sleep(100);
    }

    popStoryPath();
    popStoryPath();

    return callStoryFunc();
}

list <char> story1_2_1_2() //���������� ���� ���
{
    string script1 = "�� ������ ���Ͽ���.\n";
    scriptEx(script1, cnt1_2_1_2);
    M.Hp -= 10;
    string script2 = "���� ���� ���߰�, �ʹ� ���. �ǰ��ϰ� �������...\n\n";
    scriptEx(script2, cnt1_2_1_2);
    cnt1_2_1_2++;

    Sleep(SLEEP_TIME);
    rebuildStoryPath(list<char>{'3'});

    return callStoryFunc();
}

list<char> story1_2_2() //�Ѿư��� ���
{
    string script1 = "��..��..��... \n\n";
    scriptEx(script1, cnt1_2_2);
    M.Hp -= 10;
    string script2 = "�����̸� ���� ���Ͽ���. ü�� �Ҹ� �ʹ� �ǳ�����... �谡 ������. \n\n";
    scriptEx(script2, cnt1_2_2);
    cnt1_2_2++;

    Sleep(SLEEP_TIME);
    rebuildStoryPath(list<char>{'3'});

    return callStoryFunc();
}

list<char> story2() //���� ������ ���ϴ� ���
{
    M.Hp -= 10;
    string script1 = "���� ������ ���� �ʹ� ���. \n";
    scriptEx(script1, cnt2);
    string script2 = "��ο����� ü�µ� �� ������ �� ����. \n���� ü�� ������ ���� � ���̶� �ǿ��� �� �� ����. \n\n";
    scriptEx(script2, cnt2);
    string script3 = "���� ���� �͵� �� �ϳ��� Ȱ���غ���. \n";
    scriptEx(script3, cnt2);
    cnt2++;

    return list<char>{};
}

list<char> story2_1() // �κ��丮���� �ν˵� ���
{
    string script1 = "�ֺ��� �ν˵��� ������ ���� ���� ���δ�. \n";
    scriptEx(script1, cnt2_1);
    string script2 = "�������� �ν˵��� ���� ���̴� �� ���� ���� �ƴϴ�.\n\n";
    scriptEx(script2, cnt2_1);
    string script3 = "��...��...��... �ʹ� ���... �̴��...\n";
    scriptEx(script3, cnt2_1);
    cnt2_1++;

    printf(".\n");
    Sleep(500);
    printf(".\n");
    Sleep(500);
    printf(".\n");
    Sleep(500);

    setcolor(11, 0); //��Ʈ�� ������
    printf("������ ���� ��ü�������� ����Ͽ����ϴ�.\n");
    setcolor(15, 0); //��� ������
    Sleep(SLEEP_TIME);
    printf("������ �Ϸ��� 1�� �����ÿ�. \n\n");
    /*
    int n;
    scanf("%d", &n);

    if (n == 1)
    {
        story1_2_1();
    }
    */
    //�ƴ� ���� ��� ����?

    totalscore += 100;

    while (keyCheckerIgnoreCase('1') == false)
    {
        Sleep(100);
    }

    popStoryPath();
    system("cls");
    return story2();
}

list<char> story2_2() // �κ��丮���� �Ȱ� ���
{
    string script1 = "���� ���̴� �� �����Ͽ���. \n\n";
    scriptEx(script1, cnt2_2);
    string script2 = "���� ���������� �谡 �������� �����ߴ�. \n\n";
    scriptEx(script2, cnt2_2);

    Sleep(SLEEP_TIME);
    rebuildStoryPath(list<char>{'3'});

    return callStoryFunc();
}


list<char> story3()
{
    string script1 = "ü���� �� �������� ���� ���� ���� ���� ���ؾ߰ڴ�. \n\n";
    scriptEx(script1, cnt3);
    string script2 = "�̵��� �� �������� ��Ұ� �� 3�� ���� ���δ�. \n\n";
    scriptEx(script2, cnt3);
    cnt3++;

    printf("1. ����Ⱑ �Ĵ��Ĵ� �ٴٷ� �̵��غ���. \n");
    printf("2. �� ���� ���̴� ���� �Ʒ� ���� ���� ������ �̵��غ���. \n");
    printf("3. ���µ��� �������� ���� ������ ������ �̵��غ���. \n");

    return list<char>{'1', '2', '3'};
}

list<char> story3_1()
{
    string script1 = "����� �ٴٷ� �Դ�. ����� �ٴٸ� ���� ���� �� ���� �������� �� ������ �����ϴ�. \n";
    scriptEx(script1, cnt3_1);
    string script2 = "�ٴ幰 �Ʒ� ������ �����Ǵ� �׸��ڵ��� �������� ���� ���δ�. \n\n";
    scriptEx(script2, cnt3_1);
    string script3 = "�𷡻��� ��ó ������ ���� ���ô밡 ���δ�. \n\n";
    scriptEx(script3, cnt3_1);
    string script4 = "� ����⸦ ��ƺ���!\n\n\n";
    scriptEx(script4, cnt3_1);
    cnt3_1++;

    setcolor(14, 0);
    printf("----------------����⸦ ��ƶ�! minigame Ʃ�丮��----------------\n\n");
    printf("���õǴ� �ټ� ���� ���� 1, 2, 3, 4, 5 �� �ϳ��� �������� �����Ѵ�. \n");
    Sleep(SLEEP_TIME);
    printf("    5���� ���� �� � �����, Ȥ�� � ����� �������� �𸥴�. \n");
    Sleep(SLEEP_TIME);
    printf("                    �׷�, ����� ���. \n\n");
    printf("-------------------------------------------------------------------\n\n");

    pushStoryPath('m');
    return callStoryFunc();
}

list<char> story3_1_m() //����� �̴ϰ���
{
    string script1 = "1    2    3    4    5 \n\n";
    scriptEx(script1, cnt3_1_m);
    cnt3_1_m++;

    return list<char>{'1', '2', '3', '4', '5'};
}

list<char> story3_1_m_1()
{
    string script1 = "���ĸ��� ���ƹ��ȴ�! ����! \n\n\n";
    scriptEx(script1, cnt3_1_m_1);
    cnt3_1_m_1++;

    setcolor(14, 0);
    printf("���ĸ��� ���� �������� ����Ͽ����ϴ�. \n\n");

    totalscore += 100;

    popStoryPath();
    return callStoryFunc();
}

list<char> story3_1_m_2()
{
    string script1 = "��ġ�� ���Ҵ�! �̰ɷ� ���� �ذ��� �����ϰڱ�! \n";
    scriptEx(script1, cnt3_1_m_2);
    M.Hp += 10;
    cnt3_1_m_2++;

    rebuildStoryPath(list<char>{'3', '1', 'e'});
    return callStoryFunc();
}

list<char> story3_1_m_3()
{
    string script1 = "��? �� �����ٿ� �����̰� �̲��� ������..? �� �Ƿ��� �β�����. \n";
    scriptEx(script1, cnt3_1_m_3);
    cnt3_1_m_3++;
    M.Hp -= 10;

    rebuildStoryPath(list<char>{'3', '1', 'e'});
    return callStoryFunc();
}

list<char> story3_1_m_4()
{
    string script1 = "���ĸ��� ���ƹ��ȴ�! ����! \n\n\n";
    scriptEx(script1, cnt3_1_m_1);
    cnt3_1_m_1++;

    setcolor(14, 0);
    printf("���ĸ��� ���� �������� ����Ͽ����ϴ�. \n\n");

    totalscore += 100;

    popStoryPath();
    return callStoryFunc();
}

list<char> story3_1_m_5()
{
    string script1 = "�۾ ���Ҵ�! �̰ɷ� ���� �ذ��� �����ϰڱ�! \n\n\n";
    scriptEx(script1, cnt3_1_m_5);
    M.Hp += 10;
    cnt3_1_m_5++;

    rebuildStoryPath(list<char>{'3', '1', 'e'});
    return callStoryFunc();
}

list<char> story3_1_e()
{
    string script1 = "�ٴ� �ֺ��� ���ݾ� ������ ���� �ʿ��� �͵��� �ֿ���. \n\n";
    scriptEx(script1, cnt3_1_e_1);
    string script2 = "�� ĵ, �콼 ö��, �� ���� �׹���... \n\n";
    scriptEx(script2, cnt3_1_e_1);
    string script3 = "���...\n";
    scriptEx(script3, cnt3_1_e_1);
    string script4 = "���...\n\n";
    scriptEx(script4, cnt3_1_e_1);
    string script5 = "���� �𷡻��� ��ó �¸��� ���ϰ� ������. \n\n";
    scriptEx(script5, cnt3_1_e_1);
    string script6 = "������ �ٰ����� �¸��� Ȯ���ߴ�. ���°� ���� ������ �ʾ����� �׷��� ������ ������. \n\n";
    scriptEx(script6, cnt3_1_e_1);
    string script7 = "�̷� �¸��� �׳� ���� �������ϰ� �η��������� ����. \n\n";
    scriptEx(script7, cnt3_1_e_1);

    printf("1. �� ���� ���� ���� �ٸ� �������� ���� ���� �� �ִ�. �Ժη� ���������� �ȵȴ�. \n");
    printf("2. ���� ���̰� �ƴѰ� �����? ���� �������� ����� ���ڴ�. �� ���� �� �ִٰ��� ���� �״´�. \n");

    return list<char>{'1', '2'};
}

list<char> story3_1_e_1() //�� ��ġ�� ���� ���
{
    string script1 = "�ƽ����� �� ���� ����ä �¸��� �׳� �ξ���. \n\n";
    scriptEx(script1, cnt3_1_e_1_1);
    string script2 = "������ �� ������ ��ٷ����� �͵� ����̴�. \n\n";
    scriptEx(script2, cnt3_1_e_1_1);
    string script3 = "�¸� �ɾ� ������ �Ͽ����� ��� ��ٷȴ�. \n\n";
    scriptEx(script3, cnt3_1_e_1_1);

    printf(".\n");
    Sleep(SLEEP_TIME);
    printf(".\n");
    Sleep(SLEEP_TIME);
    printf(".\n");

    setcolor(10, 0);
    string script4 = "[??] : ����...����...\n\n";
    scriptEx(script4, cnt3_1_e_1_1);
    setcolor(15, 0);
    string script5 = "������ ���� ���������. ���� �����Ÿ��鼭 �Ͼ��. \n\n";
    scriptEx(script5, cnt3_1_e_1_1);
    setcolor(15, 0);
    string script6 = "[??] : �̰� �� �¸��ε�... \n\n";
    scriptEx(script6, cnt3_1_e_1_1);
    cnt3_1_e_1_1++;

    printf("1. ��, ���� �дϴ�! Ȥ�� ���� Ż���Ͻ� ��...�������?\n");
    printf("2. �ƴѵ���? �̰� ���� ������µ���? \n");

    return list<char>{'1', '2'};
}

list<char>story3_1_e_1_1() //�Բ� Ÿ�� �����ϴ� ����
{
    setcolor(10, 0);
    string script1 = "[??] : �׷� ���� ������! ���� Ż���սô�! \n\n";
    scriptEx(script1, cnt3_1_e_1_1_1);
    setcolor(15, 0);
    string script2 = "�׷��� ���� �׿� �Բ� �¸��� Ÿ�� �ٴٸ� �ǳʱ� �����Ͽ���. \n\n";
    scriptEx(script2, cnt3_1_e_1_1_1);
    string script3 = "���� �ð� �̵��ϸ鼭 �װ� ���� �ķ��� �����Ծ���. \n\n";
    scriptEx(script3, cnt3_1_e_1_1_1);
    string script4 = "�¸��� Ÿ�� ���� ������ �ʴ� �ٴٸ� �����ϸ� �� �̰� ��¼�� �� ���� ���������� ��� �Ǿ���. \n\n";
    scriptEx(script4, cnt3_1_e_1_1_1);
    string script5 = "Ȯ���� ��. �� ���� ���� ���� ���̶�� �Ŵ�. \n\n";
    scriptEx(script5, cnt3_1_e_1_1_1);
    string script6 = "�װ� �¸���� ������ �ߴ� �ð��� ���ϸ� ���� ���� �� ���� Ż���ϰ� �Ǿ�����...\n\n";
    scriptEx(script6, cnt3_1_e_1_1_1);


    printf(".\n");
    Sleep(SLEEP_TIME);
    printf(".\n");
    Sleep(SLEEP_TIME);
    printf(".\n");

    string script7 = "�� �ð��� ������ �츮�� ���� ���� ���� ��⸦ �߰��ߴ�. \n\n";
    scriptEx(script7, cnt3_1_e_1_1_1);
    string script8 = "������ ������û�� �� ���� �ʹ��� ������ �츮�� ������ �����Ǿ��� \n";
    scriptEx(script8, cnt3_1_e_1_1_1);
    string script9 = "�츮�� �̾߱�� ���� ���� �Ǹ��⵵ �Ͽ���. \n\n";
    scriptEx(script9, cnt3_1_e_1_1_1);
    string script10 = "���� ���� �� �� �¸��� �߰����� �ʾҴ���� ���� � ���� �Ͼ����...\n\n\n";
    scriptEx(script1, cnt3_1_e_1_1_1);

    Sleep(SLEEP_TIME);

    string script11 = "���� ����ϰ� ������ �ʴ�. \n";
    scriptEx(script11, cnt3_1_e_1_1_1);
    cnt3_1_e_1_1_1++;

    setColor(14, 0);
    printf("�ٸ� ������ �ñ����� �����Ű���? \n\n");
    printf("������ �ٽ� �÷����Ͽ� ���� ������ �����غ�����. \n\n");

    return list<char>{};
}

list<char>story3_1_e_1_2() //��ġ�� ���� ���
{
    string script1 = "�װ� ���� ���� ���ٴµ��� �վ����� �Ĵٺô�. \n\n";
    scriptEx(script1, cnt3_1_e_1_1_2);
    string script2 = "� �����ؾ� Ż���� �� �ְڴٰ� ���� ���� ������ ����ϰ� ���ʹ޶�� ��Ź�Ͽ���. \n\n";
    scriptEx(script2, cnt3_1_e_1_1_2);
    cnt3_1_e_1_1_2++;

    //return <char>story3_1_e_1_1();
    return story3_1_e_1_1();
}

list<char> story3_1_e_2() //�� ���İ� ���
{
    string script1 = "������ �¸��� ��߽�Ű�� ���� �غ��ߴ�. \n\n";
    scriptEx(script1, cnt3_1_e_1_2);
    string script2 = "���� �ִ� �볪���� ������ ��� �¸��� ��� ����ؾ߰ڴ�. \n\n";
    scriptEx(script2, cnt3_1_e_1_2);
    string script3 = "����Ϸ� �ϴµ� �� �ָ��� ������ �پ�´�. ��û ������. \n\n";
    scriptEx(script3, cnt3_1_e_1_2);
    string script4 = "�¸� �����ΰ� ����! ū���̴� ���� �����ľ� �Ѵ�. \n";
    scriptEx(script4, cnt3_1_e_1_2);
    string script5 = "�븦 ���� ���� ������ ���� �ִ� ���� ���� ������ ���� ���� �� �ڸ� ��Ÿ�Ͽ���. \n\n";
    scriptEx(script5, cnt3_1_e_1_2);
    string script6 = "������ �þ߰� �������...\n";
    scriptEx(script6, cnt3_1_e_1_2);
    cnt3_1_e_1_2++;

    printf(".\n");
    Sleep(500);
    printf(".\n");
    Sleep(500);
    printf(".\n");
    Sleep(500);

    setcolor(12, 0); //������ ������
    printf("�� �� ���� ���� ȭ���� �°� ����Ͽ����ϴ�. \n");
    setcolor(15, 0); //��� ������
    Sleep(SLEEP_TIME);

    printf("������ �Ϸ��� 1�� �����ÿ�. \n\n");

    totalscore += 100;

    while (keyCheckerIgnoreCase('1') == false)
    {
        Sleep(100);
    }

    popStoryPath();

    return callStoryFunc();
}

list<char> story3_2() //������
{
    string script1 = "����� ���� �����ߴ�. \n";
    scriptEx(script1, cnt3_2);
    string script2 = "��� �̰��� �ͼ� �� ���� ���� ������ �ִٴ� ���� �˰� ���������� ���� ������ �����ߴ�. \n\n";
    scriptEx(script2, cnt3_2);
    string script3 = "���� �������� ��� �о ���� �Ϸ��� �ɾ� ���������� �Ѵ�. \n\n\n\n";
    scriptEx(script3, cnt3_2);

    string script4 = "��� �ȴٺ��� ������ �����Ǵ� ���� ���̱� �����Ѵ�! ���� �ӹ��� ���� ���� ���ΰ�?\n\n";
    scriptEx(script4, cnt3_2);
    string script5 = "���� �������� ���� ������� �����Ǵ� ����� ���� �ɾ���. \n\n";
    scriptEx(script5, cnt3_2);

    setcolor(10, 0);
    string script6 = "[������] : ���� �Ҿ��°�?\n\n";
    scriptEx(script6, cnt3_2);
    cnt3_2++;

    setcolor(15, 0);
    printf("1. ��. Ȥ�� ���� �ӹ��� ���̶� �ֳ���?\n");
    printf("2. �ƴϿ�. ���� �� �� �������Դϴ�. ^^ \n\n");

    return list<char>{'1', '2'};
}

list<char> story3_2_1()
{
    setcolor(10, 0);
    string script1 = "[������] : ���� �� �׷��� �ϴ� ������ �ֳ���? \n\n";
    scriptEx(script1, cnt3_2_1);
    cnt3_2_1++;

    setcolor(15, 0);
    printf("1. ���� ���� �͵��� �׷��� �� �־��! \n");
    printf("2. �۽�� �������? \n\n");

    return list<char>{'1', '2'};
}

list<char> story3_2_2()
{
    setcolor(10, 0);
    string script1 = "[������] : �׷��ٸ� �̸� ���ư�����. \n\n";
    scriptEx(script1, cnt3_3_2);
    cnt3_3_2++;

    setcolor(15, 0);
    printf("1. �ƴմϴ�! �׷��� ���� �ӹ��� ���� �������..? \n\n");

    popStoryPath();
    pushStoryPath('1');
    return callStoryFunc();
}

list<char> story3_2_1_1() //�κ��丮 Ȯ��, ������ȯ ���� -> ���� ���� �ƴϸ� �ٸ� ���
{
    setcolor(10, 0);
    string script1 = "";

    rebuildStoryPath(list<char>{'3', '2', 'e', '1'});
    return callStoryFunc();
}

list<char> story3_2_1_2()
{
    setcolor(10, 0);
    string script1 = "[������] : (���� �� �ΰ�����...?) �׷� �̸� ���ư�����. \n\n";
    scriptEx(script1, cnt3_2_1_2);
    cnt3_2_1_2++;

    setcolor(15, 0);
    printf("1. �ƴմϴ�! ���� ���� �͵��� �־��! (���� ����)\n\n");

    popStoryPath();
    pushStoryPath('1');
    return callStoryFunc();
}

list<char> story3_2_e_1() //story3_2_1_1 ���Ŀ� �ٷ�
{
    string script1 = "�׷��� ���� �׵�� �Բ� �������� �Ϻημ� ��ư���. \n\n";
    scriptEx(script1, cnt3_2_e_1);
    string script2 = "������ ���ؼ� �ʹݿ��� �������. ���� �׵��� ��ƿ� ��İ��� ���� �޶��⿡. \n\n";
    scriptEx(script2, cnt3_2_e_1);
    string script3 = "�׵��� ���ϴ´��, �׵��� �Դ´��, �׵��� �Դ´�� ��Ȱ�ߴ�. \n\n";
    scriptEx(script3, cnt3_2_e_1);
    string script4 = "����� ���� ���� �������� �׵�� �ϳ����ٰ� �����ϰ� ��ư��� �־���. \n\n";
    scriptEx(script4, cnt3_2_e_1);
    string script5 = "����� �� ���� �� ��......\n\n\n";
    scriptEx(script5, cnt3_2_e_1);
    string script6 = "453���� ������. \n";
    scriptEx(script6, cnt3_2_e_1);
    cnt3_2_e_1++;

    Sleep(SLEEP_TIME);
    printf("\n\n");

    setColor(14, 0);
    printf("�ٸ� ������ �ñ����� �����Ű���? \n\n");
    printf("������ �ٽ� �÷����Ͽ� ���� ������ �����غ�����. \n\n");

    return list<char>{};
}

list<char> story3_3() //������
{
    string script1 = "Ǫ���� Ǯ ������ ������ �������� �̷���� ��â�� �� �տ� �����Ͽ���. \n";
    scriptEx(script1, cnt3_3);
    string script2 = "���� ������ �ƴϴ��� ���̴� ���� ���� ������ ���� ������..? \n\n";
    scriptEx(script2, cnt3_3);
    string script3 = "��! ���� �䳢�� ��������! �� �־����� ���� ���� ��ƾ� �Ѵ�! \n\n";
    scriptEx(script3, cnt3_3);
    string script4 = "� �䳢�� ��ƺ���! \n\n\n";
    scriptEx(script4, cnt3_3);
    cnt3_3++;

    setcolor(14, 0);
    printf("------------------�䳢�� ��ƶ�! minigame Ʃ�丮��------------------\n\n");
    printf("         ���� �䳢�� ������ �ʴ� ��Ȳ���� �����濡 �����ϸ�\n");
    Sleep(SLEEP_TIME);
    printf("         ������ ���� (LEFT) �Ǵ� ������ (RIGHT) �� �����Ѵ�. \n");
    Sleep(SLEEP_TIME);
    printf("    �� ���� ������ �� �� ���� �䳢�� ���� ����, �� ���� ���� �ִ�.  \n");
    Sleep(SLEEP_TIME);
    printf(" �������� �� 3�� ������ �Ǹ� 2�� �̻� �����ٸ� �䳢�� ��µ� �����Ѵ�! \n\n");
    printf("-----------------------------------------------------------------------\n\n");

    pushStoryPath('m');
    return callStoryFunc();
}

list<char> story3_3_m()
{
    string script1 = "���Ⱑ ������ ������ ���δ�! �������� �ֱ�! \n\n";
    scriptEx(script1, cnt3_3_m);
    cnt3_3_m++;

    int cnt = 3;
    int answer[3] = { '1', '2', '1' };
    while (cnt--)
    {
        printf("1. ����\n");
        printf("2. ������");

        int key = pressedKey();
        if (answer[3 - cnt] == key)
        {
            system("cls");
            printf("��Ҵ�");
            bunnycatch++;
        }
        else
        {
            system("cls");
            printf("���ƴ�");
        }
        
        Sleep(SLEEP_TIME);
        system("cls");
    }

    if (bunnycatch >= 2)
    {
        M.Hp += 10;
        string script1 = "�䳢�� ��Ҵ�! �̰ɷ� ���� �ذ��� �����ϰڱ�! \n";
        scriptEx(script1, cnt3_3);
        cnt3_3++;
    }

    else if (bunnycatch < 2)
    {
        M.Hp -= 10;
        string script2 = "�䳢�� ���ƴ�...������ ����ߴ��� �ʹ� �������...\n";
        scriptEx(script2, cnt3_3);
        cnt3_3++;
    }
    
    popStoryPath();
    pushStoryPath('e');
    pushStoryPath('1');

    return callStoryFunc();
}



list<char> story3_3_e_1()
{
    string script1 = "��ο����� �� �� ���� ���µ�� ���� ������ �����ϴ�. \n";
    scriptEx(script1, cnt3_3_1);
    string script2 = "� ���� ��ȣ�� �� �ִ� ���� ����� �Ѵ�. \n\n";
    scriptEx(script2, cnt3_3_1);
    cnt3_3_1++;

    //�̷��� �ϸ� �ȵɰ� ������

    string script3 = "�κ��丮 �ӿ� ����Ҹ��� ������ �ִ��� Ȯ���غ���. \n"; //�κ��丮 Ȯ��
    scriptEx(script3, cnt3_3_1);

    //return list<char>story3_3_1();
    return story3_3_e_2();
}

list<char> story3_3_e_2()
{
    string script1 = "�� ������ ���� ���⿡ ����ϴ�. � ���� ���� �����. \n\n";
    scriptEx(script1, cnt3_3_2);

    printf(".\n\n");
    Sleep(SLEEP_TIME);
    printf(".\n\n");
    Sleep(SLEEP_TIME);
    printf(".\n\n\n");

    string script2 = "�׷��� ���� ������ ���� ���� ������ ���ݾ� �ķ��� ������ ��� ���� �����Ͽ���. \n\n";
    scriptEx(script2, cnt3_3_2);
    string script3 = "���� ������ �������� ���� ������ �������� �� �˰� �Ǿ���. \n\n";
    scriptEx(script3, cnt3_2_2);
    string script4 = "Ż�⿡ ���� ����� ������ ����...\n\n";
    scriptEx(script4, cnt3_2_2);
    string script5 = "����� �� ���� �� ��......\n\n\n";
    scriptEx(script5, cnt3_2_2);
    string script6 = "453���� ������. \n";
    scriptEx(script6, cnt3_2_2);
    cnt3_2_2++;

    Sleep(SLEEP_TIME);
    printf("\n\n");

    setColor(14, 0);
    printf("�ٸ� ������ �ñ����� �����Ű���? \n\n");
    printf("������ �ٽ� �÷����Ͽ� ���� ������ �����غ�����. \n\n");

    return list<char>{};
}