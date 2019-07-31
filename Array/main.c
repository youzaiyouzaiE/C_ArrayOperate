//
//  main.c
//  Array
//
//  Created by jiahui on 2019/7/21.
//  Copyright © 2019 JH. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INCREMENT = 10

struct Array{
    int *data;///当前元素第一个元素的地址
    int length;//长度
    int content;//有效元素个数
    int increment;///增长因子
};

struct Array* init(void);
void initArray(struct Array *arr ,int len);
bool addpend(struct Array* array, int data);
int getValue(struct Array* array,int index);
bool instered(struct Array*, int data, int index);
bool delete(struct Array* ,int index);
bool empty(void);
bool inversionArray(struct Array* );
void showArray(struct Array *);

int main() {
//    struct Array *arr = init();  //struct Array arr分配的空间是Array,而struct Array *arr空间是个指针的空间
    struct Array arr;
    initArray(&arr, 6);
    showArray(&arr);
    addpend(&arr, 11);
    addpend(&arr, 22);
    addpend(&arr, 33);
    showArray(&arr);
    instered(&arr, 20, 2);
    showArray(&arr);
    delete(&arr, 2);
    showArray(&arr);
    inversionArray(&arr);
    showArray(&arr);

    return 0;
}

///只需给要存的数据分配内存即可，其他的变量只需一次的赋值
struct Array* init(void) {
    //struct Array*  arr = (struct Array *)malloc(sizeof(struct Array) * l0);///xx错 ！！不用给一个数组分配所有元素长度空间，只需给数组里要存的元素分配长度的空间即可
    struct Array*  arr = (struct Array *)malloc(sizeof(struct Array));///数组只需一个大小的空间，
    arr -> data = (int *) malloc(sizeof(int) *10);
    arr -> content = 0;
    arr -> increment = 10;
    (*arr).length = 10;
    return arr;
}

void initArray(struct Array *arr, int len) {
    arr ->data = malloc(sizeof(int) *len);
    if (arr ->data == NULL) {
        printf("内存分配失败！");
        exit(-1);
    } else {
        arr ->length = len;
        arr ->content = 0;
    }
}

bool addpend (struct Array* array, int data) {
    if (array -> length == array ->content) {
        return false;
    } else {
        int index = array->content;
        array->data[index] = data;
        array -> content += 1;
        return true;
    }
    return true;
}

int getValue(struct Array* array,int index) {
    if (index > array ->content || index < 0) {
        return -1;
    }
    return array->data[index -1];
}


bool instered(struct Array*arr, int data, int index){
    if (index > arr->content) {
        addpend(arr, data);
    } else {
        for (int i = arr->content -1; i >= index -1; i--) {
             arr->data[i+1] = arr ->data[i];
        }
        arr->data[index -1] = data;
        arr ->content ++;
        return true;
    }
    return false;
}

bool delete(struct Array* array,int index) {
    if (index > array ->content) {
        return false;
    } else {
        for (int i = index -1; i < array ->content; i++) {
            array->data[i] = array ->data[i+1];
        }
        array ->content --;
        return true;
    }
}

bool inversionArray(struct Array* array) {
    int start = 0;
    int end = array -> content -1;
    int temp;
    while (start < end) {
        temp = array -> data[start];
        array ->data[start] = array ->data[end];
        array ->data[end] = temp;
        start ++;
        end --;
    }
    return true;
}

bool sortArra(struct Array* array) {
    return true;
}

void showArray(struct Array *arr) {
    if (NULL == arr || arr -> content == 0) {
        printf("数组为空!");
    } else {
        printf("\n");
        for (int i =0; i < arr->content; i++) {
            printf("%d ->",arr->data[i]);
        }
        printf("\n");
    }
}
