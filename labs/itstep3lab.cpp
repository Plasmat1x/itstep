#include <iostream>
#include <cstdlib>

void secPart();
void lab();

int main(int argc, char* argv[])
{
    system("chcp 1251");
    system("cls");

    //int A = 0;                                    // ���������� = �������
    //long A = 15L                                  // long
    //auto A = 15.f                                 // float
    //auto A = 15.                                  // double
    //auto A = 15                                   // int
    //bool C = true;                                // true - �������
    //bool c = 0;                                   // false
    //bool c = 1;                                   // true
    //double D = .256;                              // 0.256...
    //double F = 3.9e-2;                            // exp double
    //double F = 3.9e-2f;                           // exp float
    //char H = 'A';                                 // '' ���������� �������
    //const char[] = "Hello, World!"                // "" ��������� �������
    //arithmetic operators:       + - * / % 

    /*
    int A = 5, B = 3;
    A = (B + 1) / 5

    -3;
    -(-3);
    A + B;

    int A;
    A = A + 10; //A=5+10 //A=15
    cout << "���������� �: " << A << endl;
    A++;   //���������� A = A + 1; �������� ���������
    cout << "���������� �: " << A << endl;
    A--; //�������� ��������� ���������� A = A - 1;
    cout << "���������� �: " << A << endl;
    ++A;  //���������� ����� ��������� ���������
    cout << "���������� �: " << A << endl;
    A = 10; //�������� ������������, �������������� ������� ���������� ����������
    system("cls"); //������� ������ �������
    cout << "���������� �: " << A << endl;
    cout << "���������� �++: " << A++ << endl;
    cout << "���������� �: " << A << endl;
    cout << "���������� ++A: " << ++A << endl;
    cout << "���������� �: " << A << endl; //A=12
    B = A++; //B=A; A=A+1; //����������� ����� ��������� ��������� �������
    //���������� B ����� ��������� ������� �������� ���������� �
    //����� �������� ���������� � ����� ��������� �� 1
    cout << "���������� �: " << A << endl;
    cout << "���������� B: " << B << endl;
    //A=13     //A+B*C    //(A+B)*C
    B = ++A; //A=A+1; B=A; //���������� ����� ��������� ��������� �������
    //������� �������� ���������� � ����� ��������� �� 1
    //����� ���������� B ����� ��������� ����� �������� ���������� �
    cout << "���������� �: " << A << endl;
    cout << "���������� B: " << B << endl;
    A--; //����������� ����� ��������� ���������
    --A; //���������� ����� ��������� ���������
    cout << "A%5= " << A % 5 << endl;
    cout << B % 2 << endl; //������� �� ������� �������� ���������� B �� 2 ��������� ������ ��
    //�������� ��������� � ���������� � ��� ���
    //*/

    secPart();
    lab();

    return 0;
}

using namespace std;

void secPart()
{
    //�������� ����� ������
    //bool, char, short, unsigned short, int, unsigned int, long, unsigned long
    //long int, unsigned long int, long long, unsigned long long, float, double, long double

    //(double)D // ����� �������������� �������� ���������� D � ���� ������ double 
    //(��� ��������� �� ������), ������� ��� ��� �������������
    //double(D) // ������������ ������, ����������������

    //     2       3       1
    // int - float + short * bool
    //                     1. short * bool = short
    //     2. int - float = float
    //             3. float + short = float

    unsigned int A = 3000000000; //unsigned �������� ����������� ��������������
    cout << "A= " << A << endl;
    int B = 3.14; //������� �������� �������������� ��������(double) � ������ ���� ������ int, �������� ������� �����
    cout << "B= " << 3 << endl;
    float C = 3.14; //������� �������� �������������� �� ���� ������ double � ���� ������ float
    int D = 1;
    //�������������� ����� ������ � ����������
    cout << "D/B= " << (double)D / B << endl; //double/int=double
    //(double)D - ����� �������������� �������� ��������� D � ���� ������ double
    double E = (float)D / (double)B; //float/double=double
    //����� ��������������(����������) ����� ������, ��������� ����� �������� ���� ������ (double)
    //��������� ������ ���, ��� ������������,  ���������� D � B ��������� ���� ������ int
    cout << "E=" << E << endl; //int/int=int   double=int
    //    2       3       1
    //int - float + short * bool
    //1 short*bool=short
    //2 int-float=float
    //3 float+short=float
    float G = D / 2.0F; //(float)D/2;  int/float=float
    //������� �������������� ���������� � ������� ���� ������(float) 
    //�������������� �������� ������� ��� ������ (float)
    cout << "G= " << G << endl;
    double H = ((D / 10) + E) * G;
    cout << "H=" << H << endl;
    //     I    II     III
    //((int/int)+double)*float
    //I   int/int=int          1/10=0
    //II  int+double=double   0+0.33333=0.33333
    //III double*float=double 0.3333*0.5=0.166667
    H = (((double)D / 10) + E) * G;
    cout << "H=" << H << endl;
    //     I    II     III
    //((double/int)+double)*float
    //I   double/int=double          1/10=0.1
    //II  double+double=double   0.1+0.33333=0.43333
    //III double*float=double 0.4333*0.5=0.216667
    H = ((D / 10.0) + E) * G;
    cout << "H=" << H << endl;
    //     I    II     III
    //((int/double)+double)*float
    //I   int/double=double          1/10=0.1
    //II  double+double=double   0.1+0.33333=0.43333
    //III double*float=double 0.4333*0.5=0.216667

}

void lab()
{

}