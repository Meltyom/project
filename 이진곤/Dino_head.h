#pragma once

#include<stdio.h>
//입출력 관련 함수들을 제공하는 표준 라이브러리
#include<windows.h>
//Windows 운영체제에서 제공하는 함수들을 사용하기 위한 헤더 파일
#include<conio.h>
//입력을 받는 함수들을 제공
#include<time.h>
//시간과 관련된 함수들을 제공
#include<stdbool.h>
//bool 타입을 사용하기 위해 필요
#define DINO_BOTTOM_Y 12
//Dino(공룡)이 그려지는 위치를 나타내는 변수
#define TREE_BOTTOM_Y 20
//나무(Tree)가 그려지는 위치를 나타내는 변수
#define TREE_BOTTOM_X 45
//나무(Tree)가 그려지는 위치를 나타내는 변수


//1. 콘솔 창의 크기와 제목을 지정하는 함수
void SetConsoleView(); 

//2. 커서의 위치를 x, y로 이동하는 함수
void GotoXY(int x, int y);

//3. 키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
int GetKeyDown();

//4. 공룡을 그리는 함수
void DrawDino(int dinoY);

//5. 나무를 그리는 함수
void DrawTree(int treeX);

//6. 충돌 했을때 게임오버
void DrawGameOver(const int score);

//7. 충돌했으면 true, 아니면 false
bool isCollision(const int treeX, const int dinoY);

//8 위의 함수들을 활용해서 게임을 플레이 하는 함수
void Dino_play();