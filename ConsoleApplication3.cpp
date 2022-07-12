// ConsoleApplication3.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

float f(double x) //���������� �������� ������� f(x) = x^2-2

{

       return x*x-2;

}

float df(float x) //���������� �������� �����������

{

       return 2*x;

}

float d2f(float x) // �������� ������ �����������

{

       return 2;

}

int _tmain(int argc, _TCHAR* argv[])

{

       int exit = 0, i=0;//���������� ��� ������ � �����

       double x0,xn;// ����������� ����������� ��� �����

       double a, b, eps;// ������� ������� � ����������� ��������

             do {

                    i=0;

                    cout<<"Please input [a;b]\n=>";

                    cin>>a>>b; // ������ ������� �������, �� ������� ����� ������ ������

                    cout<<"\nPlease input epsilon\n=>";

                    cin>>eps; // ������ ������ �������� ����������

                    if (a > b) // ���� ������������ ��������� ������� �������, ������ �� �������

                           {

                                  x0 = a;

                                  a = b;

                                  b = x0;

                           }

                    if (f(a)*f(b)>0) // ���� ����� ������� �� ����� ������� ����������, �� ����� ��� �����

                                  cout<<"\nError! No roots in this interval\n";

                           else

                           {

                           if (f(a)*d2f(a)>0) x0  = a; // ��� ������ ��������� ����� ��������� f(x0)*d2f(x0)>0 ?

                                  else x0 = b;

                           xn = x0-f(x0)/df(x0); // ������� ������ �����������

                           cout<<++i<<"-th iteration = "<<xn<<"\n";

                           while(fabs(x0-xn) > eps) // ���� �� ��������� ����������� ��������, ����� ���������� ���������

                           {

                                  x0 = xn;

                                  xn = x0-f(x0)/df(x0); // ��������������� ������� �������

                                  cout<<++i<<"-th iteration = "<<xn<<"\n";

                           }

                    cout<<"\nRoot = "<<xn; // ����� ������������ �����

                    }

                    cout<<"\nExit?=>";

                    cin>>exit;

             } while (exit!=1); // ���� ������������ �� ���� exit = 1

       return 0;

}
