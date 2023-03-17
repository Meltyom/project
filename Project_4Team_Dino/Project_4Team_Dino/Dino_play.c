#include"Dino_head.h"
//���� �Լ����� Ȱ���Ͽ� ������ �÷��� �ϴ� �Լ�

void Dino_play()
{
    SetConsoleView();

    while (true)        //���� ����
    {
        //���� ���۽� �ʱ�ȭ������ ����
        bool isJumping = false;
        bool isBottom = true; // �ٴڿ� ���� �� 
        const int gravity = 3; // �߷��� ��Ÿ���� 'gravity'�� �ʱ�� ������

        int dinoY = DINO_BOTTOM_Y;
        int treeX = TREE_BOTTOM_X;
        //�ʱ�ȭ�� ���� ����� ��ֹ��� ��ġ�� �ʱⰪ���� ������

        int score = 0;
        clock_t start, curr;    //���� ���� �ʱ�ȭ
        start = clock();        //���۽ð� �ʱ�ȭ

        while (true)    //�� �ǿ� ���� ����
        {
            //�浹 �˻�(isCollision)�� ���� 
            //���� �浹�� ���� ������ Ż��
            if (isCollision(treeX, dinoY))
                break;

            //zŰ�� ���Ȱ�, �ٴ��� �ƴҶ� ����
            if (GetKeyDown() == 'z' && isBottom)
            {
                isJumping = true;
                isBottom = false;
            }

            //�������̶�� Y�� ����, ������ �������� Y�� ����.
            if (isJumping)
            {
                dinoY -= gravity;
            }
            else
            {
                dinoY += gravity;
            }

            //������ ��ġ�� ���, ������ �߷¿� ���� �������� ������
            //Y�� ����ؼ� �����ϴ°� �������� �ٴ��� ����.
            if (dinoY >= DINO_BOTTOM_Y)
            {
                dinoY = DINO_BOTTOM_Y;
                isBottom = true;
            }

            //��ֹ��� �̵���Ŵ
            //treeX ������ �̿��Ͽ� �������� �̵�
            //������ ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ.
            treeX -= 2;//���� ���� �ӵ��� ������
            if (treeX <= 0)
            {
                treeX = TREE_BOTTOM_X;
            }

            //������ ������ ������ ������ ���� ��Ȳ.
            if (dinoY <= 3)
            {
                isJumping = false;
            }

            DrawDino(dinoY);        //draw dino
            DrawTree(treeX);        //draw Tree
            //'DrawDino'�� 'DrawTree'�Լ� ����Ͽ� ����ȭ���� �׸�(����� ��ֹ�)
            
            curr = clock();            //����ð� �޾ƿ���
            if (((curr - start) / CLOCKS_PER_SEC) >= 1)    // 1�ʰ� �Ѿ�����
            {
                score++;    //���ھ� UP
                start = clock();    //���۽ð� �ʱ�ȭ
            }
            Sleep(60);
            //������ ��� �ð��� ���� ������ ���
            //��� �ð��� clock() �Լ��� ����Ͽ� ����
            //�� ���� �������� ����� �ð��� 1�ʰ� ������ ������ ����
            system("cls"); 
            //'system("cls")'�Լ� ����Ͽ� ����ȭ���� �����, ���ο� �������� �׸�

            //(v2.0) ��������� 1�ʸ��� ���ִ°��� �ƴ϶� �׻� ������ָ鼭, 1�ʰ� �������� ++ ���ݴϴ�.
            GotoXY(22, 0);    //Ŀ���� ��� �������� �ű��. �ܼ�â�� cols=100�̴ϱ� 2*x�̹Ƿ� 22���� �־���
            printf("Score : %d ", score);    //���� �������.
        }

        //���� ���� �޴�
        DrawGameOver(score);
        //���� ������ Ż���� ��, 'DrawGameOver' �Լ��� ȣ���Ͽ� 'GameOver'�� ���
    }
    return 0;
}