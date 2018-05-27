//
// Created by Jeffery on 2018/5/25.
//
#include <iostream>

using namespace std;
struct my_year {
    int year;
};

void int__array_pointer_test() {
    int array[] = {1, 2, 3, 4, 5};
    int *p = array;
    int **pr = &p;
    for (int i = 0; i < 5; ++i) {
        cout << "array[" << i << "] address in memory is " << &array[i] << endl;
    }
    //输出数组名，输出的是第一个元素的地址
    cout << "array = " << array << endl;
    //输出指向整形数组的指针，输出的还是第一个元素的地址
    cout << "p = " << p << endl;
    //对指向整形数组的指针做解引用操作，输出的是第一个元素的值
    cout << "*p = " << *p << endl;
    //输出指向整形数组的指针的指针，输出的是存储着数组第一个元素地址的内存地址
    cout << "pr = " << pr << endl;
    //输出对pr做一次解引用操作的结果，也就是第一个元素的地址
    cout << "*pr = " << *pr << endl;
    //输出对pr做两次解引用操作的结果，也就是第一个元素的值
    cout << "**pr = " << **pr << endl;
    /**
     * 总结如下：
     * array[0] = *p = **pr
     * array = p = *pr
     */
}

void char_array_pointer_test() {
    char array[] = {"Digist"};
    char *p = array;
    char **pr = &p;
    for (int i = 0; i < 5; ++i) {
        cout << "array[" << i << "] address in memory is " << array[i] << endl;
    }
    //输出数组名，输出的是整个数组的值
    cout << "array = " << array << endl;
    //输出指向字符数组的指针，输出的也是整个数组的值
    cout << "p = " << p << endl;
    //对字符数组的指针做解引用操作，输出的是第一个元素的值
    cout << "*p = " << *p << endl;
    //输出指向字符数组指针的指针，输出的是存储第一个元素地址的内存地址
    cout << "pr = " << pr << endl;
    //输出对指向字符数组的指针做一次解引用操作的结果，输出的是整个数组的值
    cout << "*pr = " << *pr << endl;
    //输出对指向字符数组的指针做两次解引用操作的结果，输出的是第一个元素的值
    cout << "**pr = " << **pr << endl;
}

void char_array_pointer_test2() {
    char array[] = {"Digist"};
    char *p = array;
    char **pr = &p;
    for (int i = 0; i < 5; ++i) {
        cout << "array[" << i << "] address in memory is " << (int *) &array[i] << endl;
    }
    cout << "array = " << (void *) array << endl;
    cout << "p = " << (int *) p << endl;
    cout << "*p = " << *p << endl;
    cout << "&p = " << &p << endl;
    cout << "pr = " << pr << endl;
    cout << "*pr = " << *pr << endl;
    cout << "**pr = " << **pr << endl;
}

void test_point_to_struct_pointer() {
    my_year s1, s2, s3;
    s1.year = 1998;
    s2.year = 2002;
    s3.year = 2004;
    my_year *pa = &s2;
    pa->year = 1999;
    my_year trio[3]{{1000},
                    {2000},
                    {3000}};
    my_year *pr = trio;
    my_year **ptr = &pr;
    for (int i = 0; i < 3; ++i) {
        cout << "trio[" << i << "] address in memory is " << &trio[i] << endl;
    }
    cout << "trio = " << trio << endl;
    cout << "pr = " << pr << endl;
    //此处会崩溃
    //cout << "*pr = " << *pr << endl;
    cout << "ptr = " << ptr << endl;
    cout << "*ptr = " << *ptr << endl;
    //cout << "**ptr = " << **ptr << endl;

    for (int i = 0; i < 3; ++i) {
        cout << (pr + i)->year << endl;
    }
    const my_year *arp[3] = {&s1, &s2, &s3};
    cout << "&s1 = " << &s1 << endl;
    cout << "&s2 = " << &s2 << endl;
    cout << "&s3 = " << &s3 << endl;

    const my_year **ppb = arp;
    cout << "ppb = " << ppb << endl;
    cout << "arp = " << arp << endl;
    cout << "arp[0] = " << arp[0] << endl;
    cout << "&arp[0] = " << &arp[0] << endl;
    cout << "*ppb = " << *ppb << endl;
    cout << "&ppb = " << &ppb << endl;
//    cout << (void *)arp << end;
}

void prtstr() {
    char animal[20]{"bear"};
    const char *bird = "wren";
    char *p = NULL;
    cout << animal << " and " << bird << "\n ";
    cout << "Enter a kind of animal";
    cin >> animal;
    p = animal;
    cout << p << "!\n";
    cout << "Before using strcpy():\n";
    cout << animal << " at " << (int *) animal << endl;
}

void new_double_array() {
    auto *p = new double[3];
    p[0] = 0.2;
    p[1] = 0.5;
    p[2] = 0.8;
    cout << "p[1] is " << p[1] << endl;
    // p指向数组中第二个元素
    p++;
    //这时候连续内存多了一块，这块内存存放的值是double的默认值0.000000
    for (int i = 0; i < 3; ++i) {
        printf("%f ", *(p + i));
    }
    cout << endl;
    cout << "Now p[1] is " << p[1] << endl;
    p--;
    delete[] p;
}

void test() {
    char array[4];
    char *p = array;
}

int main() {
//    prtstr();
//    int__array_pointer_test();
//    char_array_pointer_test();
//    char_array_pointer_test2();
    test_point_to_struct_pointer();
    return 0;
}
