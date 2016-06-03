//
//  main.cpp
//  HeapSort
//
//  Created by 王青龙 on 6/3/16.
//  Copyright © 2016 王青龙. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;


void max_heapify(int arr[], int start, int end){

    int dad = start;
    int son = dad * 2 + 1;

    while (son < end) {
//        if (son + 1 < end && arr[son] < arr[son + 1]) {
//            ++son;
//        }

        if (son + 1 < end) {
            if (arr[son] < arr[son + 1]) {
                ++son;
            }
        }

        if (arr[dad] > arr[son]) {
            return;//也即是只要上面有序，那么下面也肯定有序，即可跳出
        }else{
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(int arr[], int len){

    for (int i = len / 2 - 1; i >= 0; --i) {
        max_heapify(arr, i, len);
    }

    for (int i = len - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i);
    }
}

int main(int argc, const char * argv[]) {

    int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    int len = (int) sizeof(arr) / sizeof(*arr);

    heap_sort(arr, len);

    for (int i=0; i<len; ++i) {
        cout<<arr[i]<<' ';
    }

    cout<<endl;

    return 0;
}
