//////////// N=2, M=3:
// 1 2 3
// 6 5 4
//////////// N=4, M=4:
// 1   2    3    4
//12  13   14    5
//11  16   15    6
//10   9    8    7

#include<iostream>
#include<iomanip>

using namespace std;

// 打印矩阵a中，以下标[x][y]元素开始的，长宽为col,row的矩形的外围一圈元素，从数字n开始
void PrintOne(int** a, int x, int y, int row, int col, int& n)
{
    if (row <=0 || col <= 0) return;
    else if (row == 1 && col == 1) {// 打印中心的唯一元素
        a[x][y] = n;
        n++;
        return;
    }
    else if (row == 1) { // 只有一行，打印这一行,行坐标为x
        for(int i=0; i<col; i++) {
            a[x][i+y] = n;
            n++;
        }
        return;
    }
    else if (col == 1) { // 只有一列，打印这一列，列坐标为y
        for(int i=0; i<row; i++) {
            a[i+x][y] = n;
            n++;
        }
        return;
    }
    else { // 不止一行一列，沿四个方向打印
        for(int i=0; i<col-1; i++) { // 打印x行，左->右
            a[x][i+y] = n;
            n++;
        }
        for(int i=0; i<row-1; i++) { // 打印最右列,上->下
            a[i+x][col-1+y] = n;
            n++;
        }
        for(int i=col-1; i>0; i--) { // 打印最下行，右->左
            a[row-1+x][i+y] = n;
            n++;
        }
        for(int i=row-1; i>0; i--) { // 打印y列，下->上
            a[i+x][y] = n;
            n++;
        }
    }
    
}

void Print(int** a, int row, int col)
{
    for(int i=0; i<row; ++i) {
        for (int j=0; j<col; ++j) 
        {
            cout<<setw(10)<<a[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    int N;  //row
    int M;  //coloum

    while(true) {
        cin>>N;
        cin>>M;
        if(N<=0 || M<=0) break;
        
        int *p[N]; // 指针数组
        for (int i=0; i<N; ++i) {
            p[i] = new int[M];
        }

        int n = 1; // 从1开始打印
        int x = 0; // 每一圈的开始坐标x, y
        int y = 0;
        int i = N; // 每一圈的长宽
        int j = M;

        for (; i>=1&&j>=1; i-=2, j-=2) // 每打印一圈，长宽分别减去2，开始元素下标分别加1，开始新一轮打印
        {
            PrintOne(p, x, y, i, j, n);
            x++;
            y++;
        }
        Print(p, N, M);

        for (int i=0; i<N; ++i) { delete p[i]; }
    }
    
    return 0;
}
