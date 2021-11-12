/*
 * main.c
 * Oct 2020
 * Author: Mücahit KURTLAR
 * License: MIT
Copyright 2021 Mücahit KURTLAR

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>

int isnext2(int x1, int y1, int x2, int y2);
void insert(int a, int address, int arr[], int size);
void insert2group(int a, int b);
void insertalone2group(int a);
int isingroup(int address);
int howmanygroup();
void printgroups();
int search(int poinadress);
void deleteaddress(int address, int arr[], int size);
void deletesepbetween(int a, int b);
int seperatornumbetween(int a, int b);
void printgroupssize();
void sort(int list[], int n);

int tablesize[2];
int points[100][2];
int groups[100];
int groupssize = 0;
int pointsize;
int groupsvolumes[100];
int groupsvolumessize = 0;


int main() {
    scanf("%d %d", &tablesize[0], &tablesize[1]);
    for (pointsize = 0; pointsize < 100; pointsize++) {
        scanf("%d", &points[pointsize][0]);
        //scanf("%d %d", &points[pointsize][0], &points[pointsize][1]);
        if (points[pointsize][0] < 0) {
            break;
        } else {
            scanf("%d", &points[pointsize][1]);
        }
        
    }
    //printf("pointsize: %d\n", pointsize);
    //for (int j = 0; j < pointsize; j++) {
    //    printf("%d %d \n", points[j][0], points[j][1]);
    //}
    
    for (int i = 0; i < pointsize; i++) {
        int isalone = 1;
        for (int j = i + 1; j < pointsize; j++) {
            //printf("%d ile %d kiyaslaniyor\n", i, j);
            if (isnext2(points[i][0], points[i][1], points[j][0], points[j][1])) {
                insert2group(i, j);
                isalone = 0;
            }
            //printf("*-*-*-*-\n");
            //printgroups();
            //printf("*-*-*-*-\n");
        }
        if (isalone && !search(i)) {
            //printf("%d, %d is alone :(\n", points[i][0], points[i][1]);
            insertalone2group(i);
        }
    }
    //printf("group number: %d\n", howmanygroup());
    //printgroups();
    printf("%d", howmanygroup());
    printgroupssize();
    return 0;
}

int isnext2(int x1, int y1, int x2, int y2) {
    if (abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1) {
        //printf("dip dibe: %d %d, %d %d\n", x1, y1, x2, y2);
        return 1;
    }
    return 0;
}

void insert2group(int a, int b) {
    int a_address = isingroup(a);
    int b_address = isingroup(b);
    //printf("a_address: %d b_address: %d\n", a_address, b_address);
    if (groupssize == 0) {
        groups[0] = a;
        groups[1] = b;
        groups[2] = -1;
        groupssize = 1;
    } else if (a_address != -1 && b_address != -1) {
        if (seperatornumbetween(a_address, b_address) == 1) {
            deletesepbetween(a_address, b_address);
        }
        
    } else if (a_address != -1) {
        insert(b, a_address + 1, groups, groupssize);
    } else if (a_address != -1) {
        insert(b, a_address + 1, groups, groupssize);
    } else if (b_address != -1) {
        insert(a, b_address + 1, groups, groupssize);
    } else {
        groups[groupssize] = a;
        groups[groupssize + 1] = b;
        groups[groupssize + 2] = -1;
        groupssize += 3;
    }   
}

void insertalone2group(int a) {
    groups[groupssize] = a;
    groups[groupssize + 1] = -1;
    groupssize += 2;
}

void insert(int a, int address, int arr[], int size) {
    for (int i = size; i > address; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[address] = a;
    groupssize++;
}

void deleteaddress(int address, int arr[], int size) {
    for (int i = address; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    groupssize--;
}

int isingroup(int address) {
    for (int i = 0; i < groupssize; i++) {
        if (address == groups[i]) {
            return i;
        }
    }
    return -1;
}

int search(int poinadress) {
    for (int i = 0; i < groupssize; i++) {
        if (poinadress == groups[i]) {
            return 1;
        }
    }
    return 0;
}

int howmanygroup() {
    int selectornumber = 0;
    for (int i = 0; i < groupssize; i++) {
        if (groups[i] == -1) {
            selectornumber++;
        }
    }
    //printf("selectornumber: %d\n", selectornumber);
    return selectornumber;
}

void printgroups() {
    for (int i = 0; i < groupssize; i++)
    {
        printf("%d\n", groups[i]);
    }
    
}

int seperatornumbetween(int a, int b) {
    int seperatornum = 0;
    if (a < b) {
        for (int i = a + 1; i < b; i++) {
            if (groups[i] == -1) {
                seperatornum++;
            }
    }
    } else {
        for (int i = b + 1; i < a; i++) {
            if (groups[i] == -1) {
                seperatornum++;
            }
        }
    }
    return seperatornum;
}

void deletesepbetween(int a, int b) {
    if (a < b) {
        for (int i = a + 1; i < b; i++) {
            if (groups[i] == -1) {
                deleteaddress(i, groups, groupssize);
            }
    }
    } else {
        for (int i = b + 1; i < a; i++) {
            if (groups[i] == -1) {
                deleteaddress(i, groups, groupssize);
            }
        }
    }
}

void sort(int list[], int n) {
  long c, d, t;
  for (c = 0 ; c < n - 1; c++) {
    for (d = 0 ; d < n - c - 1; d++) {
      if (list[d] > list[d+1]) {
        t         = list[d];
        list[d]   = list[d+1];
        list[d+1] = t;
      }
    }
  }
}

void printgroupssize() {
    int groupsvolume = 0;
    for (int i = 0; i < groupssize; i++) {
        if (groups[i] != -1) {
            groupsvolume++;
        } else {
            groupsvolumes[groupsvolumessize] = groupsvolume;
            groupsvolumessize++;
            groupsvolume = 0;
        }
    }
    sort(groupsvolumes, groupsvolumessize);
    for (int j = 0; j < groupsvolumessize; j++) {
        printf(" %d", groupsvolumes[j]);
    }
    printf("\n");
    
}
