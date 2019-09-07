#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    if (AllocConsole()) {
        constexpr wchar_t message[]{ L"Hello world! but without CRT :)\nPress enter to exit..." };
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), message, sizeof(message) / sizeof(wchar_t) - 1, nullptr, nullptr);

        auto input{ L'\0' };

        do {
            DWORD charsRead;
            ReadConsoleW(GetStdHandle(STD_INPUT_HANDLE), &input, 1, &charsRead, nullptr);
        } while (!input);

        FreeConsole();
    }
}
