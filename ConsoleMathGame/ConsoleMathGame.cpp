#include <iostream>
using namespace std;
int RandomNumbers(int from, int to)
{
    return rand() % (to - from + 1) + from;
}


int NumberOfQuestion() {
    cout << "Please write Number Of Questions" << endl;
    int f;
    cin >> f;
    return f;
}
int LevelQuestions(int Level) {
    if (Level == 1) {

        return RandomNumbers(1, 10);

    }
    else if (Level == 2) {
        return RandomNumbers(1, 30);

    }
    else if (Level == 3) {
        return RandomNumbers(1, 50);

    }
    else {
        return LevelQuestions(RandomNumbers(1, 3));
    }


}
char TypeOfNumber(int Type) {

    if (Type == 1) {
        return char(43);
    }
    else if (Type == 2) {
        return char(45);
    }
    else if (Type == 3) {
        return char(42);
    }
    else if (Type == 4) {
        return char(47);
    }
    else {

    }



}
void Hard(int& Counter) {

    Counter++;
    cout << "Your Answer Is True" << endl;
    system("color 20");

}
void Hard2(int& Counter2) {
    Counter2++;
    cout << "Your Answer Is False" << endl;
    system("color 40");
}


void LoopQuestion(int Level, int Type, int& Counter, int& Counter2) {
    int F = LevelQuestions(Level);
    int P = LevelQuestions(Level);
    char c;
    int k;
    int CorrectNumber;
    if (Type == 1) {
        cout << P << "+" << F << "?" << endl;
        cin >> k;
        if (P + F == k)
            Hard(Counter);
        else
            Hard2(Counter2);


    }
    else if (Type == 2) {
        cout << P << "-" << F << "?" << endl;
        cin >> k;
        if (P - F == k)
            Hard(Counter);
        else
            Hard2(Counter2);


    }
    else if (Type == 3) {
        cout << P << "*" << F << "?" << endl;
        cin >> k;
        if (P * F == k)
            Hard(Counter);
        else
            Hard2(Counter2);
    }

    else if (Type == 4) {
        cout << P << "/" << F << "?" << endl;
        cin >> k;
        if (P / F == k)
            Hard(Counter);
        else
            Hard2(Counter2);
    }
    else {

        c = TypeOfNumber(RandomNumbers(1, 4));
        cout << P << c << F << "?" << endl;
        cin >> k;
        if (c == '+')
            if (P + F == k)
                Hard(Counter);
            else
                Hard2(Counter2);
        else if (c == '-')
            if (P - F == k)
                Hard(Counter);
            else
                Hard2(Counter2);
        else if (c == '*')
            if (P * F == k)
                Hard(Counter);
            else

                Hard2(Counter2);
        else if (c == '/')
            if (P / F == k)
                Hard(Counter);
            else
                Hard2(Counter2);


    }



}


void AnswerQuestion(int& Level, int& Type, int& Question) {
    int f = NumberOfQuestion();
    int Counter = 0;
    int Counter2 = 0;
    cout << "Enter Questions Level [1]:Easy,  [2]:Med,  [3]:Hard,  [4]:Mix ?" << endl;
    cin >> Level;
    LevelQuestions(Level);
    cout << "Enter Operation Type [1]:Add,  [2]:Sub,  [3]:Mul,  [4]:Div,  [5]:Mix  ?" << endl;
    cin >> Type;
    TypeOfNumber(Type);
    for (int i = 1; i <= f; i++) {


        LoopQuestion(Level, Type, Counter, Counter2);

    }
    cout << "Number Of Questions:" << f << endl;
    if (Level == 1) {
        cout << "Qusetion Level is Easy" << endl;
    }
    else if (Level == 2) {
        cout << "Qusetion Level is Med" << endl;
    }
    else if (Level == 3) {
        cout << "Qusetion Level is Hard" << endl;
    }
    else {
        cout << "Qusetion Level is Mix" << endl;
    }
    if (Type == 1) {
        cout << "OpType        : Add" << endl;
    }
    else  if (Type == 2) {
        cout << "OpType        : Sub" << endl;
    }
    else  if (Type == 3) {
        cout << "OpType        : Mul" << endl;
    }
    else  if (Type == 4) {
        cout << "OpType        : Div" << endl;
    }
    else  if (Type == 5) {
        cout << "OpType        : Mix" << endl;
    }
    cout << "Number of Right Answers:" << Counter << endl;
    cout << "Nunber of Worng Answer: " << Counter2 << endl;


}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}


void PlayAgain(int& Level, int& Type, int& Question) {
    char PlayAgain = 'Y';
    do

    {
        ResetScreen();
        AnswerQuestion(Level, Type, Question);
        cout << "do want to play Again" << endl;
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');







}




int main()
{
    srand((unsigned)time(NULL));
    int Level;
    int Type;
    int Question;
    PlayAgain(Level, Type, Question);

}