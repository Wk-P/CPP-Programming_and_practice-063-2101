#include "Reset.h"
#include <iostream>
#include "Brick.h"
#include "ball.h"
#include "Screen.h"

using namespace std;

bool Reset(Brick& bricks, Ball& ball, Bar& bar, bool& challenge_flag) {
    gotoxy(5, 5);
    cout << "���� �ٴ����� ���������ϴ�. \n";
    cout << "\t1.�絵��\n\t2.ó��ȭ������ ���ư���\n\t3.��������" << endl;
    int option;
    while (1)
    {
        cin >> option;
        if (option == 1 || option == 2)
        {
            if (option == 1) {									// play again
                bricks.reset_bricks();
                // ball direction reset
                ball.f_InitBALL();
                bar.InitBar();
                challenge_flag = true;
                return challenge_flag;
            }
            else if (option == 2) {
                bricks.reset_bricks();
                ball.f_InitBALL();				
                challenge_flag = false;
                return challenge_flag;                          // first screen print out
            }
        }
        else if (option == 3)
        {
            exit(0);
        }
        else
        {
            cout << "�ٽ� �������ּ���" << endl;
            continue;
        }
    }
}