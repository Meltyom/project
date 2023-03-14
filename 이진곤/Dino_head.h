#pragma once

#include<stdio.h>
//����� ���� �Լ����� �����ϴ� ǥ�� ���̺귯��
#include<windows.h>
//Windows �ü������ �����ϴ� �Լ����� ����ϱ� ���� ��� ����
#include<conio.h>
//�Է��� �޴� �Լ����� ����
#include<time.h>
//�ð��� ���õ� �Լ����� ����
#include<stdbool.h>
//bool Ÿ���� ����ϱ� ���� �ʿ�
#define DINO_BOTTOM_Y 12
//Dino(����)�� �׷����� ��ġ�� ��Ÿ���� ����
#define TREE_BOTTOM_Y 20
//����(Tree)�� �׷����� ��ġ�� ��Ÿ���� ����
#define TREE_BOTTOM_X 45
//����(Tree)�� �׷����� ��ġ�� ��Ÿ���� ����


//1. �ܼ� â�� ũ��� ������ �����ϴ� �Լ�
void SetConsoleView(); 

//2. Ŀ���� ��ġ�� x, y�� �̵��ϴ� �Լ�
void GotoXY(int x, int y);

//3. Ű������ �Է��� �ް�, �Էµ� Ű�� ���� ��ȯ�ϴ� �Լ�
int GetKeyDown();

//4. ������ �׸��� �Լ�
void DrawDino(int dinoY);

//5. ������ �׸��� �Լ�
void DrawTree(int treeX);

//6. �浹 ������ ���ӿ���
void DrawGameOver(const int score);

//7. �浹������ true, �ƴϸ� false
bool isCollision(const int treeX, const int dinoY);

//8 ���� �Լ����� Ȱ���ؼ� ������ �÷��� �ϴ� �Լ�
void Dino_play();