#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int Lose = 0;
int Win = 0;
int Draw = 0;

int GetComputer() { //������ ���� �� ����, ����, �� �� ����
    std::srand((unsigned int)time(NULL));
    int X = std::rand() % 3;
    return X;
}

int GetUser() { // ����ڷκ��� �Է¹���
    std::string S;
    while (true) {
        std::cout << "����, ����, �� �߿��� �Է��ϼ���" << "\n";
        std::cin >> S;
        if (S == "����" || S == "����" || S == "��") {
            if (S == "����") return 0;
            else if (S == "����") return 1;
            else return 2;
        }
    }
}

void Match(int Computer, int User) { //���������� ����
    if (User == Computer) {
        std::cout << "���º�" << "\n";
        Draw++;
    }
    else if (User < Computer) {
        if (User + 1 == Computer) {
            std::cout << "�й�" << "\n";
            Lose++;
        }
        else {
            std::cout << "�¸�" << "\n";
            Win++;
        }
    }
    else {
        if (User - 1 == Computer) {
            std::cout << "�¸�" << "\n";
            Win++;
        }
        else {
            std::cout << "�й�" << "\n";
            Lose++;
        }
    }
}
void Score() { //���� ǥ��
    std::cout << "�¸� : " << Win << ", �й� : " << Lose << ", ���º� : " << Draw << "\n";
}
int IsEnd() { //������ ��� ���� ����
    std::string GetYesOrNo;
    while (true) {
        std::cout << "�׸��Ͻðڽ��ϱ�?" << " " << "��/�ƴϿ�" << "\n";
        std::cin >> GetYesOrNo;
        if (GetYesOrNo == "��") return 0;
        else if (GetYesOrNo == "�ƴϿ�") return 1;
    }
}

int main() {
    int Computer, User;
    int X = 1;
    while (X) {
        Computer = GetComputer();
        User = GetUser();
        Match(Computer, User);
        Score();
        X = IsEnd();
    }
}