#pragma once
#include <vector>
#include <string>

class TextBox
{
public:
    TextBox(int textBoxWidth, int textBoxHeight, std::string value, int textBoxPositionX, int textBoxPositionY);
    void show();
    template <class T>
    void changeValue(T newValue)
    {
        std::stringstream s;
        s << newValue;
        std::string a = s.str();
        for (int i = 1; i < textBoxWidth - 1; i++)arr[textBoxHeight / 2][i] = ' ';
        for (int i = textBoxWidth - 2, j = a.size() - 1; i >= 1 && j >= 0; i--, j--)
        {
            arr[textBoxHeight / 2][i] = a[j];
        }
    }
private:
    std::vector<std::vector<char>> arr;
    int textBoxWidth;
    int textBoxHeight;
    int textBoxPositionX;
    int textBoxPositionY;
    std::string value;
    void textBoxFill();
};