//
//  main.c
//  useofarry
//
//  Created by 胡啸 on 2017/7/6.
//  Copyright © 2017年 胡啸. All rights reserved.
//

#include <stdio.h>

void delete(int a[],int number);   //删除函数
void insert(int a[],int number);   //插入函数
void select1(int a[],int number);  //选择函数
void menu();                       //菜单
int input(int a[],int number);     //数组的输入


int main(void) {
    int a[]={};
    int choose;
    int number = 0;
    while (1) {
        menu();
        printf("请输入你的选择:");
        scanf("%d",&choose);
        switch (choose) {
            case 1:
                printf("请输入数组元素个数:");
                scanf("%d",&number);
                input(a,number);
                break;
            case 2:
                delete(a, number);
                break;
            case 3:
                insert(a, number);
                break;
            case 4:
                select1(a, number);
                break;
                
            default:
                printf("输入有误，请重新输入\n");
                break;
        }
    }
    
    
    
    
    return  0;
}


int input(int a[],int number)
{
    
    for(int i=0;i<number;i++)
    {
        printf("请输入第%d个元素的值",i+1);
        scanf("%d",&a[i]);
    }
    return a[number];
}


void menu()
{
    printf("--------Welcome to huxiao's program!----------\n");
    printf("           1.数组数据的输入\n");
    printf("           2.数组数据的删除\n");
    printf("           3.数组数据的插入\n");
    printf("           4.数组数据的查找\n");
}


void delete(int a[],int number)
{
    int i,k,l;
    int j = 0;
    int wanted;
    
    printf("输入你想删除的数:");
    scanf("%d",&wanted);
    
    for(i=0;;i++)
    {
        if(a[i]==wanted)
        {j=i;break;}
        
        if(i==number-1)
        {
            printf("error");
            exit(-1);
        }
        else
            continue;
        
    }
    for(k=j;k<number;k++)
    {
        a[k]=a[k+1];
    }
    number--;
    printf("删除成功!\n");
    printf("现在的数组为:");
    for(l=0;l<number;l++)
        printf("%d",a[l]);
    printf("\n");
}


void insert(int a[],int number)
{
    int j,l;
    int wanted2;
    int weizhi;
    
    printf("输入你想插入的数:");
    scanf("%d",&wanted2);
    printf("输入你想插入的位置:");
    scanf("%d",&weizhi);
    
    if(weizhi<0 || weizhi>number)
        printf("位置输入错误:");
    else
    {
        for( j=number;j>=weizhi-1;j--)
        {
            a[j+1]=a[j];
        }
        number++;
        a[weizhi-1]=wanted2;
    }
    printf("现在的数组为:");
    for(l=0;l<number-1;l++)
    {
        printf("%d",a[l]);
    }
    printf("\n");
}


void select1(int a[],int number)
{
    int i,j = 0;
    int wanted3;
    
    printf("输入你要查询的数:");
    scanf("%d",&wanted3);
    
    for(i=0;;i++)
    {
        if(a[i]==wanted3)
        {j=i;
            printf("\t\t\t您查询的数在第%d位!\n",j+1);
            continue;}
        
        else if(i==number)
        {
            printf("数组内不存在此数!\n");
            exit(-1);
        }
    }
    
}

