#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int Lose = 0;
int Win = 0;
int Draw = 0;

int GetComputer() { //난수를 생성 후 가위, 바위, 보 중 선택
    std::srand((unsigned int)time(NULL));
    int X = std::rand() % 3;
    return X;
}

int GetUser() { // 사용자로부터 입력받음
    std::string S;
    while (true) {
        std::cout << "가위, 바위, 보 중에서 입력하세요" << "\n";
        std::cin >> S;
        if (S == "가위" || S == "바위" || S == "보") {
            if (S == "가위") return 0;
            else if (S == "바위") return 1;
            else return 2;
        }
    }
}

void Match(int Computer, int User) { //가위바위보 진행
    if (User == Computer) {
        std::cout << "무승부" << "\n";
        Draw++;
    }
    else if (User < Computer) {
        if (User + 1 == Computer) {
            std::cout << "패배" << "\n";
            Lose++;
        }
        else {
            std::cout << "승리" << "\n";
            Win++;
        }
    }
    else {
        if (User - 1 == Computer) {
            std::cout << "승리" << "\n";
            Win++;
        }
        else {
            std::cout << "패배" << "\n";
            Lose++;
        }
    }
}
void Score() { //전적 표시
    std::cout << "승리 : " << Win << ", 패배 : " << Lose << ", 무승부 : " << Draw << "\n";
}
int IsEnd() { //게임을 계속 할지 결정
    std::string GetYesOrNo;
    while (true) {
        std::cout << "그만하시겠습니까?" << " " << "예/아니요" << "\n";
        std::cin >> GetYesOrNo;
        if (GetYesOrNo == "예") return 0;
        else if (GetYesOrNo == "아니요") return 1;
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