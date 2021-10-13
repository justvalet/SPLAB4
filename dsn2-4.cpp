#include <iostream>
#include <sstream>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cmath>
using namespace std;
bool prime(long long n){
        long long req = sqrt(n);
        for(long long i=2;i<=req;i++)
                if(n%i==0)
                        return false;
        return true;
}
int main(int argc, char *argv[])
{
        setlocale(LC_ALL, "rus");
        int i=0, j=0;
        while(argv[++i]!=NULL)
        cout << i << ". "<< argv[i] << endl;
        cout << "Простые числа: ";
        for (int i=1; i<5; i++){
                int b = atoi(argv[i]);
                bool l = prime(b);
                if (l) {
                        cout << b << " ";
                        j++;
                }

        }
        return j;
}
