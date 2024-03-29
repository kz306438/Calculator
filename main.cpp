#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>
#include "consoleGUI/GUI.h"
#include "textBox.h"

StandartButton one(6, 3, "1", 0, 15), two(6, 3, "2", 7, 15),
three(6, 3, "3", 14, 15), four(6, 3, "4", 0, 12),
five(6, 3, "5", 7, 12), six(6, 3, "6", 14, 12),
seven(6, 3, "7", 0, 9), eight(6, 3, "8", 7, 9),
nine(6, 3, "9", 14, 9), zero(6, 3, "0", 7, 18),
exactly(6, 3, "=", 21, 18), plus(6, 3, "+", 21, 15),
minus(6, 3, "-", 21, 12), mult(6, 3, "x", 21, 9),
del(6, 3, "DEL", 21, 3), percent(6, 3, "%", 0, 3),
CE(6, 3, "CE", 7, 3), C(6, 3, "C", 14, 3),
reversibility(6, 3, "1/x", 0, 6), square(6, 3, "x^2", 7, 6),
root(6, 3, " ", 14, 6), divide(6, 3, "/", 21, 6),
sign(6, 3, "+/-", 0, 18), comma(6, 3, ",", 14, 18);



void customizeButtons()
{
    one.setBackgroundColor(White);
    one.setForegroundColor(Black);
    two.setBackgroundColor(White);
    two.setForegroundColor(Black);
    three.setBackgroundColor(White);
    three.setForegroundColor(Black);
    four.setBackgroundColor(White);
    four.setForegroundColor(Black);
    five.setBackgroundColor(White);
    five.setForegroundColor(Black);
    six.setBackgroundColor(White);
    six.setForegroundColor(Black);
    six.setBackgroundColor(White);
    six.setForegroundColor(Black);
    seven.setBackgroundColor(White);
    seven.setForegroundColor(Black);
    eight.setBackgroundColor(White);
    eight.setForegroundColor(Black);
    nine.setBackgroundColor(White);
    nine.setForegroundColor(Black);
    zero.setBackgroundColor(White);
    zero.setForegroundColor(Black);
    exactly.setBackgroundColor(White);
    exactly.setForegroundColor(Black);
    plus.setBackgroundColor(White);
    plus.setForegroundColor(Black);
    minus.setBackgroundColor(White);
    minus.setForegroundColor(Black);
    mult.setBackgroundColor(White);
    mult.setForegroundColor(Black);
    del.setBackgroundColor(White);
    del.setForegroundColor(Black);
    percent.setBackgroundColor(White);
    percent.setForegroundColor(Black);
    CE.setBackgroundColor(White);
    CE.setForegroundColor(Black);
    C.setBackgroundColor(White);
    C.setForegroundColor(Black);
    reversibility.setBackgroundColor(White);
    reversibility.setForegroundColor(Black);
    square.setBackgroundColor(White);
    square.setForegroundColor(Black);
    root.setBackgroundColor(White);
    root.setForegroundColor(Black);
    divide.setBackgroundColor(White);
    divide.setForegroundColor(Black);
    sign.setBackgroundColor(White);
    sign.setForegroundColor(Black);
    comma.setBackgroundColor(White);
    comma.setForegroundColor(Black);
    char symRoot = char(251);
    std::string sR = "o";
    sR[0] = char(251); sR += "x";
    root.setName(sR);
}

int main()
{
    setColorBackground(White);
    setColorForeground(Black);
    HWND console = GetConsoleWindow();
    SetConsoleTitleA("Calculator");

    HANDLE hOut;
    SMALL_RECT windowSize = { 0, 0, 27, 20 }; 

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(hOut, TRUE, &windowSize);

    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_EXTENDED_FLAGS;
    SetConsoleMode(hOut, dwMode);

    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(hOut, &bufferInfo);
    COORD newSize = {
        bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1,
        bufferInfo.srWindow.Bottom - bufferInfo.srWindow.Top + 1
    };

    SetConsoleScreenBufferSize(hOut, newSize);

    customizeButtons();

    TextBox table(27, 3, "", 0, 0);
    std::string temp = "";
    std::string temp1 = "";
    std::string temp2 = "";
    del.connect([&]() {if (temp.size() != 0) { temp.pop_back(); table.changeValue(temp); }  });
    one.connect([&]() {temp += '1'; table.changeValue(temp); });
    two.connect([&]() {temp += '2'; table.changeValue(temp); });
    three.connect([&]() {temp += '3'; table.changeValue(temp); });
    four.connect([&]() {temp += '4'; table.changeValue(temp); });
    five.connect([&]() {temp += '5'; table.changeValue(temp); });
    six.connect([&]() {temp += '6'; table.changeValue(temp); });
    seven.connect([&]() {temp += '7'; table.changeValue(temp); });
    eight.connect([&]() {temp += '8'; table.changeValue(temp); });
    nine.connect([&]() {temp += '9'; table.changeValue(temp); });
    zero.connect([&]() {temp += '0'; table.changeValue(temp); });
    bool flag = true;
    sign.connect([&]() {
        if (flag == true)
        {
            temp = '-' + temp;
            table.changeValue(temp);
            flag = false;
        }
        else
        {
            std::string s = temp;
            temp = "";
            for (int i = 1; i < s.size(); i++)
            {
                temp += s[i];
            }
            table.changeValue(temp);
            flag = true;
            
        }
        });
    C.connect([&]() {temp = ""; table.changeValue(temp); });
    CE.connect([&]() {temp = ""; table.changeValue(temp); });
    comma.connect([&]() {
        bool isPoint = false;
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] == '.')isPoint = true;
        }
        if (!isPoint)
        {
            temp += '.'; table.changeValue(temp);
        }
        });
    int operation;
    plus.connect([&]() {operation = 1; temp += '+'; table.changeValue(temp); });
    minus.connect([&]() {operation = 2; temp += '-'; table.changeValue(temp); });
    mult.connect([&]() {operation = 3; temp += 'x'; table.changeValue(temp); });
    divide.connect([&]() {operation = 4; temp += '/'; table.changeValue(temp); });
    percent.connect([&]()
        {
            bool isCan = true;
            if (temp[0] == '+'|| temp[0] == 'x' || temp[0] == '/')isCan = false;
            bool q = false;
            for (int i = 0; i < temp.size() - 1; i++)
            {
                if ((temp[i] == '+' || temp[i] == '-' || temp[i] == 'x' || temp[i] == '/') &&
                    (temp[i + 1] == '+' || temp[i + 1] == '-' || temp[i + 1] == 'x' || temp[i + 1] == '/'))
                    isCan = false;
            }
            for (int i = 0; i < temp.size(); i++)
            {
                if (isCan == false)break;
                if (temp[i] == '+' || temp[i] == '-' || temp[i] == 'x' || temp[i] == '/')q = true;
                if (q == false && temp[i] != '+' && temp[i] != '-' && temp[i] != 'x' && temp[i] != '/')temp1 += temp[i];
                else if (q == true && temp[i] != '+' && temp[i] != '-' && temp[i] != 'x' && temp[i] != '/')temp2 += temp[i];
            }
            if(temp2 != "" && isCan)
            {
                double num2 = stod(temp2);
                num2 /= 100;
                std::stringstream s;
                s << num2;
                temp2 = s.str();
                temp = temp1 + temp[temp1.size()] + temp2;
                table.changeValue(temp);
            }
            else
            {
                temp = "syntax error";
                table.changeValue(temp);
            }
            temp1 = "";
            temp2 = "";
        });
    root.connect([&]() 
        {
            bool isCan = true;
            for (int i = 1; i < temp.size(); i++)
            {
                if (temp[i] == '+' || temp[i] == '-' || temp[i] == 'x' || temp[i] == '/')isCan = false;
            }
            if (isCan)
            {
                double num = stod(temp);
                num = sqrt(num);
                table.changeValue(num);
                std::stringstream s;
                s << num;
                temp = s.str();
            }
            else
            {
                temp = "syntax error";
                table.changeValue(temp);
            }
            temp1 = "";
            temp2 = "";
        });
    square.connect([&]()
        {
            bool isCan = true;
            for (int i = 1; i < temp.size(); i++)
            {
                if (temp[i] == '+' || temp[i] == '-' || temp[i] == 'x' || temp[i] == '/')isCan = false;
            }
            if (isCan)
            {
                double num = stod(temp);
                num = pow(num, 2);
                table.changeValue(abs(num));
                std::stringstream s;
                s << num;
                temp = s.str();
            }
            else
            {
                temp = "syntax error";
                table.changeValue(temp);
            }
            temp1 = "";
            temp2 = "";
        });
    reversibility.connect([&]()
        {
            bool isCan = true;
            for (int i = 1; i < temp.size(); i++)
            {
                if (temp[i] == '+' || temp[i] == '-' || temp[i] == 'x' || temp[i] == '/')isCan = false;
            }
            if (isCan)
            {
                double num = stod(temp);
                num = 1 / num;
                table.changeValue(num);
                std::stringstream s;
                s << num;
                temp = s.str();
            }
            else
            {
                temp = "syntax error";
                table.changeValue(temp);
            }
            temp1 = "";
            temp2 = "";
        });
    exactly.connect([&]()
        {
            bool isCan = true;
            if (temp[0] == '+' || temp[0] == 'x' || temp[0] == '/')isCan = false;
            bool q = false;
            for (int i = 0; i < temp.size() - 1; i++)
            {
                if ((temp[i] == '+' || temp[i] == '-' || temp[i] == 'x' || temp[i] == '/') && 
                    (temp[i + 1] == '+' || temp[i + 1] == '-' || temp[i + 1] == 'x' || temp[i + 1] == '/'))
                    isCan = false;
            }
            for (int i = 0; i < temp.size(); i++)
            {
                if (isCan == false)break;
                if (temp[i] == '+' || temp[i] == '-' || temp[i] == 'x' || temp[i] == '/')q = true;
                if (q == false && temp[i] != '+' && temp[i] != '-' && temp[i] != 'x' && temp[i] != '/')temp1 += temp[i];
                else if (q == true && temp[i] != '+' && temp[i] != '-' && temp[i] != 'x' && temp[i] != '/')temp2 += temp[i];
            }
            if (isCan)
            {
                double num1 = stod(temp1);
                double num2 = stod(temp2);
                double num = stod(temp);
                switch (operation)
                {
                case 1:
                    num = num1 + num2;
                    break;
                case 2:
                    num = num1 - num2;
                    break;
                case 3:
                    num = num1 * num2;
                    break;
                case 4:
                    num = num1 / num2;
                    break;
                }
                operation = 0;
                table.changeValue(num);
                std::stringstream s;
                s << num;
                temp = s.str();
            }
            else
            {
                temp = "syntax error";
                table.changeValue(temp);
            }
            temp1 = "";
            temp2 = "";
        });
    setupInputHandling();
    while (true)
    {
        invisibleCursor();
       mouseButtonInteraction(&percent,&CE, &C, &del,&reversibility, &square, &root, &divide,
            &seven, &eight, &nine,&mult, &four, &five, &six,&minus,
            &one, &two, &three, &plus,&sign, &zero, &comma, &exactly);
       table.show();
        Sleep(10);
    }
    return 0;
}

