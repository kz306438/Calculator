#include "textBox.h"
#include "consoleGUI/GUI.h"

TextBox::TextBox(int textBoxWidth, int textBoxHeight, std::string value, int textBoxPositionX, int textBoxPositionY) :
    textBoxWidth(textBoxWidth), textBoxHeight(textBoxHeight), value(value),
    textBoxPositionX(textBoxPositionX), textBoxPositionY(textBoxPositionY)
{
    textBoxFill();
}

void TextBox::textBoxFill()
{
    arr.resize(textBoxHeight);
    for (int i = 0; i < textBoxHeight; i++)
    {
        arr[i].resize(textBoxWidth, ' ');
    }
    for (int i = 0; i < textBoxHeight; i++)
    {
        arr[i][0] = char(186);
        arr[i][textBoxWidth - 1] = char(186);
    }
    for (int j = 0; j < textBoxWidth; j++)
    {
        arr[0][j] = char(205);
        arr[textBoxHeight - 1][j] = char(205);
    }
    arr[0][0] = char(201);
    arr[textBoxHeight - 1][0] = char(200);
    arr[0][textBoxWidth - 1] = char(187);
    arr[textBoxHeight - 1][textBoxWidth - 1] = char(188);

    for (int i = textBoxWidth - 2, j = value.size() - 1; i >= 1 && j >= 0; i--, j--)
    {
        arr[textBoxHeight / 2][i] = value[j];
    }
}

void TextBox::show()
{
    for (int i = 0; i < textBoxHeight; i++)
    {
        for (int j = 0; j < textBoxWidth; j++)
        {
            setcur(textBoxPositionX + j, textBoxPositionY + i);
            std::cout << arr[i][j];
        }
    }
}

