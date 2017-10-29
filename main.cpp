#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <QTime>


using namespace std;

void Hoar(vector <int> &arr, int left, int right);
void Merge (vector <int> &arr, int left, int right, int n);
void Bubble (vector <int> &arr, int n);
void copy (vector <int> arr, vector <int> &arr_temp, int n);


int main()
{
    srand(time(0));
    vector <int> arr;
    int n=10000;                         //Количество элементов в массиве

    for (int i=0; i<n; i++)
    {
        int temp=rand()%100;
        arr.push_back(temp);
    }
    cout<<"Array is full. Choose a sorting method:"<<endl;
    vector <int> arr_temp;
    arr_temp.resize(n);
    int s=0;
    cout<<"1.Bubble sorting."<<endl<<"2.Hoar sorting"<<endl<<"3.Merge sorting."<<endl<<"4.Standart sorting"<<endl<<"5.Exit"<<endl;
    while (s<5 ){
    cin>>s;
    switch(s){


        case 1:{
    copy(arr, arr_temp, n);
    QTime time_bubble;
    time_bubble.start();                            //Запуск таймера
    Bubble(arr_temp, n);
    int t_bubble=time_bubble.elapsed();             //Время таймера
    cout<<"Bubble sorting time: "<<t_bubble<<"ms"<<endl;
    break;
    }


        case 2:{
    copy(arr, arr_temp, n);
    QTime time_hoar;
    time_hoar.start();
    Hoar(arr_temp, 0, n-1);
    int t_hoar=time_hoar.elapsed();
    cout<<"Hoar sorting time: "<<t_hoar<<"ms"<<endl;
    break;
    }


        case 3:{
    copy(arr, arr_temp, n);
    QTime time_merge;
    time_merge.start();
    Merge(arr_temp, 0, n-1, n);
    int t_merge=time_merge.elapsed();
    cout<<"Merge sorting time: "<<t_merge<<"ms"<<endl;
    break;
    }


        case 4:{
    copy(arr, arr_temp, n);
    QTime time_sort;
    time_sort.start();
    sort(arr_temp.begin(), arr_temp.begin()+n);   //Стандартная сортировка С++
    int t_sort=time_sort.elapsed();
    cout<<"Standart sorting time: "<<t_sort<<"ms"<<endl;
    break;
    }


    default: break;
        }
    }

    return 0;
}



void copy (vector <int> arr, vector <int> &arr_temp, int n)
{
    for (int i=0; i<n; i++)
        arr_temp[i]=arr[i];
}


void Bubble (vector <int> &arr, int n)        //Сортировка пузырем
{
    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-i-1; j++)
            if (arr[j]>arr[j+1])
                    swap(arr[j], arr[j+1]);
}


void Hoar(vector <int> &arr, int left, int right)       //Сортировка Хоар
{
    int i=left;
    int j=right;
    int middle=(left+right+1)/2;
    do
    {
        while(arr[i]<arr[middle]) i++;
        while(arr[j]>arr[middle]) j--;
        if (i<=j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i<=j);
    if (i<right) Hoar(arr, i, right);
    if (left<j) Hoar(arr, left, j);
}


void Merge (vector<int> &arr, int left, int right, int n)        //Сортировка слиянием
{
    if (left==right) return;
    if (right-left==1)
    {
        if (arr[left]>arr[right])
            swap(arr[left], arr[right]);
        return;
    }
    int mid=(left+right)/2;
    Merge(arr, left, mid, n);
    Merge(arr, mid+1, right, n);
    vector<int> arr_temp;
    arr_temp.resize(n);
    int _left=left;
    int _right=mid+1;
    int cur=0;
    while (right-left+1 != cur)
    {
        if (_left>mid)
            arr_temp[cur++]=arr[_right++];
        else if (_right>right)
            arr_temp[cur++]=arr[_left++];
        else if (arr[_left]>arr[_right])
            arr_temp[cur++]=arr[_right++];
        else arr_temp[cur++]=arr[_left++];
    }
    for (int i=0; i<cur; i++)
        arr[i+left]=arr_temp[i];
}


