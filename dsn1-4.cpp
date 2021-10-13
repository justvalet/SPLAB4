#include <iostream>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/mman.h>//для создания разделяемой памяти
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    pid_t f;
    int t, j=0;
    char str[20], str1[20], str2[20], str3[20];
    const char *c="";
    int a[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    for (int i = 0; i < 16; i++) {
        cout << a[i] << " ";
    }

    cout << endl;
    for (int i = 0; i < 16; i=i+4)
    {
        t = -1;
        sprintf(str, "%d", a[i]);
        sprintf(str1, "%d", a[i+1]);
        sprintf(str2, "%d", a[i+2]);
        sprintf(str3, "%d", a[i+3]);
        switch (fork()) // раздел процесс на 2 процесса
        {
            case -1:
                cout << "Не работает\n";
                break;
            case 0:
                cout << "Дочерний PID: " << getpid() << endl;//функция для получения id - процесса
                execl("./dsn2-4", "./dsn2-4", str, str1, str2, str3, NULL);// заменяет текущий процесс на дочерний
                break;
            default:// в случае если предыдущий не подходит
                cout << "Родительский PID: " << getpid() << endl;
                wait(&t);// ждет пока кончится процесс и сохр в t
                j += WEXITSTATUS(t);//берет старший байт - то значение которое вернул дочерний процесс
                break;
        }
    }
    cout << "Всего простых чисел: " << j << endl;
    return (0);
}
