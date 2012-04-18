
/* Please keep all functions alphabetical! */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>
#include "coniocouleur.h"






void clrscr() {
  COORD coord;
  DWORD written;
  CONSOLE_SCREEN_BUFFER_INFO info;

  coord.X = 0;
  coord.Y = 0;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
  FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
    info.dwSize.X * info.dwSize.Y, coord, &written);
  gotoxy (1, 1);
}

int cputs(const char *_str) {
  printf ("%s\n", _str);
  return 0;
}


void gotoxy(int x, int y) {
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void textattr(int _attr) {
  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), _attr);
//  printf ("%d\n", text_info.screenheight);
}

void textcolor(int _color) {
  textattr(_color );
}



