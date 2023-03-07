#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

// �ܼ�â���� wav������ ����� ������ ����ҷ��� playsound�Լ��� �ʿ���.
// �̶� PlaySound �Լ��� wchar_t �������� �� ���ϰ�θ� �ν�
// charToWChar �Լ��� char������ ������ wchar_t�������� ��ȯ��Ű�� ���� ���� ��
// wchar_t�� �����ڵ� ���ڸ� �����ϱ� ���� ������ Ÿ����. 'char'Ÿ���� ���ڿ����� �ٸ� ���·� ���ڿ��� ǥ��

wchar_t* charToWChar(const char* str)  
// const char*Ÿ���� ���ڿ��� wchar_t* Ÿ���� ���ڿ��� ��ȯ�ϴ� �Լ� ,�Լ��� �Ű������δ� const char*Ÿ���� ���ڿ� ������ str�� ���޵�
{
    const size_t size = strlen(str) + 1; 
    // strlen �Լ��� ����Ͽ� ���ڿ� str�� ���̸� ����, �� ���̿� 1�� ���� ���ڿ��� ����� ����ũ�� ���
    wchar_t* wstr = (wchar_t*)calloc(size, sizeof(wchar_t));
    // calloc �Լ��� ����Ͽ� ���۸� �Ҵ�, �̶� �Ҵ�� �޸𸮸� 0���� �ʱ�ȭ
    mbstowcs_s(NULL, wstr, size, str, _TRUNCATE);
    // char ���ڿ��� wchar_t ���ڿ��� ��ȯ, ù��° �Ű����� NULL�� ��ȯ�� ���ڿ��� ���̸� ��ȯ,
    // �ι�° �Ű������� ��ȯ�� ���ڿ��� ������ ���ۿ� ���� ������(str�� wstr�� ����)
    // ����° �Ű����� size�� ������ ũ�⸦ ��Ÿ��
    // �׹�° �Ű����� str�� ��ȯ�� 'char'������ ���ڿ�
    // �ټ���° �Ű����� _TRUNCAT�� ��ȯ�� ���ڼ��� �ִ밪 = ���ڿ��� ���߸��� ��
    return wstr;
    // wchar_t�������� ��ȯ�� ���ڿ��� ��ȯ
}

// ���� �Լ��� ���� �Լ��� wav������ ��������� ��� �Լ�

void playMusic(const char* fileName) 
// const char* fileName Ÿ���� ���ڿ� ������ fileName �Է��� ����
{
    wchar_t* wfileName = charToWChar(fileName); 
    // �Է¹��� fileName ���ڿ��� wchar_t*Ÿ������ ��ȯ charToWChar�Լ����� mbstowcs�� �̿��Ͽ� ��ȯ
    PlaySound(wfileName, NULL, SND_FILENAME | SND_ASYNC); 
    /*��ȯ�� wfileName�� �̿��Ͽ� Playsound()�Լ��� ȣ���� ����ϸ�, 
    SND_FILENAME�� �̿��Ͽ� �����̸� �����ϰ� SND_ASYNC�� ����Ͽ� �񵿱������� ���*/
    free(wfileName);
    // ����� �Ǹ� free()�� �̿��Ͽ� ���ڿ��� �Ҵ�� �޸𸮸� ����
}

void printTxtFile(const char* fileName) {
    FILE* file;
    if (fopen_s(&file, fileName, "r") != 0) {
        printf("Failed to open file %s.\n", fileName);
        return;
    }

    char buffer[500];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
        fflush(stdout); // ��� ���۸� ����ݴϴ�.
    }
    printf("\n");
    printf("\n");
    printf("\n");
    fclose(file);
}

void menu()
{
    int choice = 0;
    printf("\t\t                              ȯ���մϴ�!!!");
    printf("\n");
    printf("\n");

    while (1) {

        printf("\n");
        printf("\t�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�\n");
        printf("\t 1. ���ھ߱�");
        printf("       2. ��ֹ� ���ϱ�");
        printf("       3. ����");
        printf("       4. ��ŷ");
        printf("       5. ����\n\n");
        printf("\t�����ϼ��� :");

        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            system("cls");  // ȭ�� �ʱ�ȭ
            // ���ھ߱� ���� �ڵ� ����

            break;
        case 2:
            system("cls");  // ȭ�� �ʱ�ȭ
            // ��ֹ��� �����ؼ� ���ϴ� ���� �ڵ� ����

            break;
        case 3:
            system("cls");  // ȭ�� �ʱ�ȭ
            printf("���� ���� �߱����� �����ϰڽ��ϴ�.\n\n ");
            printf("������ �����ϸ� ������ 3�ڸ��� ���� ������ �˴ϴ�.\n ");
            printf("�־��� ��ȸ�� 10ȸ�̸� �ߺ��� ���ڸ� ������ �ƹ� ���� 3�ڸ��� �Է��Ͻø� �˴ϴ�.\n\n ");
            printf("�̶� �Է��� ���ڰ� �ڸ����� �ٸ��鼭 ���� ������ ���̸�\n ���� �����鼭 �ڸ����� ������ ��Ʈ����ũ�� �˴ϴ�. \n ");// ����
            printf("\n");
            printf("���� ��� 815���� ������ �Ǿ��� �� 263���� �Է��� ���ô�.\n\n ");
            printf("������ ���ڿ� �Է��� ���ڿ��� ���� �ڸ��� ���� ���ڴ� �����Ƿ� 0���̸�\n ���� ���ڰ� �ϳ��� �����Ƿ� 0��Ʈ����ũ �Դϴ�.\n\n ");// ����
            printf("�ٽ� 215�� �Է��� �غ���, ���� �ڸ��� ���� ���ڴ� 2���� �ְ�\n ���� ���ڰ� �����Ƿ� 2��Ʈ����ũ 0���� �Ǵ°̴ϴ�.\n\n "); // ����
            printf("���� ���������� 815�� �Է��ϸ� ���� �ڸ��� ���� �ڸ��� ���ڴ� 3���� �����Ƿ�\n 3��Ʈ����ũ�� �Ǹ� �÷��̾ �̱�ϴ�.\n\n "); // ����
            printf("�־��� ��ȸ�� 10ȸ�̹Ƿ� �����ϰ� ���ڸ� ��󺸼���.\n ");
            printf("\n");
            printf("\n");
            printf("��ֹ� ������ z ��ư�� ������\n");
            printf("�÷��̾��� ĳ���ʹ� ������ �ϰ� �ǰ� ��ֹ��� ���� �� �ֽ��ϴ�.\n");
            printf("��ֹ��� ���ؼ� �ְ������� ����غ�����.\n");
            break;
        case 4:
            system("cls");  // ȭ�� �ʱ�ȭ
            // ��ŷ
            break;
        case 5:
            return 0; // ���α׷� ����
        default:
            printf("�߸��� �����Դϴ�.\n");
            break; // ���α׷� ����
        }
    }
}


int main() {
    system("COLOR 0F");
    system("mode con cols=100 lines=60");

    playMusic("C:\\Users\\KB\\Desktop\\music.wav");

    printTxtFile("text.txt");
   
    menu();
    system("cls");

    system("mode con cols=100 lines=60"); // �ܼ�â ũ�� ����
    printTxtFile("text.txt");
    printf("\n                                         ������ ����Ǿ����ϴ�.\n");

    return 0;
}
