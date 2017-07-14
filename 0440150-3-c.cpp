#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <stdlib.h>

using namespace std;

void Reverse(int i, int j) ;

bool test[10][10];

int main() {

    bool lights[10][10];

    while (true) {
        char x[100];
        scanf("%s", x);
        if (strcmp(x, "end") == 0) {
            return 0;
        }
        char row[10];
        for (int i = 0; i < 10; i++) {
            scanf("%s", row);
            for (int j = 0; j < 10; ++j) {
                if (row[j] == '#') {
                    lights[i][j] = false;
                    test[i][j] = false;
                } else {
                    lights[i][j] = true;
                    test[i][j] = true;
                }
            }
        }

        int minx = 10000;
        for (int i = 0; i < pow(2, 10); i++) {
            int nums = 0;
            int markcount = 0;
            bool mark[10];
            for (int k = 9; k >= 0; k--) {
                if ((i & (1 << k)) != 0) {
                    mark[markcount] = true;
                    markcount++;
                } else {
                    mark[markcount] = false;
                    markcount++;
                }
            }
            for (int j = 0; j < 10; j++) {
                if (mark[j]) {
                    Reverse(0, j);
                    nums++;
                }
            }
            for (int i = 1; i < 10; i++) {
                for (int j = 0; j < 10; j++)
                {
                    if (test[i - 1][j])
                    {
                        Reverse(i, j);
                        nums++;
                    }
                }
            }
            bool flag = true;
            for (int j = 0; j < 10; j++) {
                if (test[9][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag && nums < minx) {
                minx = nums;
            } else {
                memcpy(test, lights, sizeof(bool) * 100);
            }
        }
        cout << x;
        if (minx > 100) {
            cout << " -1" << endl;
        } else {
            cout << " " << minx << endl;
        }
    }
    return 0;
}

void Reverse(int i, int j)
{
    int a, b;
    int rvs_1[5] = { 0, 0, 0, 1, -1 };
    int rvs_2[5] = { 0, 1, -1, 0, 0 };
    for (int k = 0; k < 5; k++) {
        a = i + rvs_1[k];
        b = j + rvs_2[k];
        if (a >= 0 && a < 10 && b >= 0 && b < 10) {
            test[a][b] = !test[a][b];
        }
    }
}
