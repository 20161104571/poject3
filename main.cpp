//
//  main.cpp
//  poject3
//
//  Created by 20161104571 on 18/7/7.
//  Copyright © 2018年 20161104571. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

struct player
{
    string name;  //姓名
    string sex;   //性别
    string clas;  //班级
    string pro;   //节目名称
    string type;  //节目类型
    string tel;   //电话
    string ach;   //成绩
}player;

typedef struct player ElemType;

typedef struct
{
    ElemType elem[50];
    int      last;
}SeqList;

string Trim(string& str)
{
    str.erase(0,str.find_first_not_of(" \t\r\n"));
    str.erase(str.find_last_not_of(" \t\r\n")+1);
    return str;
}

void CountScore(SeqList* L) //计算成绩
{
    int j,max=0,min=100,m,i;
    double sf;
    int f[10];
    
    ifstream fin("//Users//a20161104570//Desktop//表演名单.csv"); //打开文件流操作
    ofstream outfile("//Users//a20161104570//Desktop//成绩 2.csv",ios::app);  //写入文件
    string line;
    while (getline(fin, line))
    {
        //cout << line << endl;
        
        istringstream sin(line);
        vector<string> fields;
        string field;
        while (getline(sin, field, ','))
        {
            fields.push_back(field);
        }
        cout <<"姓名,性别,班级,节目名称,节目类型,电话："<<endl; //整行输出
        i=0;
        L->elem[i].name = Trim(fields[0]);
        L->elem[i].sex = Trim(fields[1]);
        L->elem[i].clas = Trim(fields[2]);
        L->elem[i].pro = Trim(fields[3]);
        L->elem[i].type = Trim(fields[4]);
        L->elem[i].tel = Trim(fields[5]);
        L->elem[i].ach = Trim(fields[6]);
        cout <<L->elem[i].name << "\t" << L->elem[i].sex<< "\t" << L->elem[i].clas <<"\t"<< L->elem[i].pro<<"\t"<< L->elem[i].type<<"\t"<< L->elem[i].tel<<"\t"<< L->elem[i].ach<<endl;
        
        max=0;
        min=100;
        sf=0;
        for(j=1;j<=5;j++)//评分
        {
            cout<<"评委 "<<j<<" 给分:";
            cin>>f[j];
            sf=sf+f[j];
            if(max<f[j])
            {
                max=f[j];
            }
            if(min>f[j])
            {
                min=f[j];
            }
        }
        cout<<"去一个max:"<<max<<endl;
        cout<<"去一个min:"<<min<<endl;
        sf=(sf-max-min)/3;
        cout<<"选手最终得分:"<<sf<<endl;
        L->elem[i].ach=sf;
        
        outfile<<L->elem[i].name << "," << L->elem[i].sex<< "," << L->elem[i].clas <<","<< L->elem[i].pro<<","<< L->elem[i].type<<","<< L->elem[i].tel<<","<< sf<<endl;
        cout<<"ok,press a key!"<<endl;

        
        cout<<"是否继续「是（1）否（0）」"<<endl;//中途结束评分
        cin>>m;
        if(m==0)
        {
            break;
        }
        i++;
    }
    cout<<"完成"<<endl;
}


void show()  //显示选手信息
{
    int i=0;
    ifstream fin("/Users/a20161104571/Desktop/选手信息.csv"); //打开文件流操作
    string line;
    while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
    {
        i++;
        cout<<"第 "<< i <<" 位选手:"<<endl;
        cout <<"姓名,性别,班级,节目名称,节目类型,电话："<< endl << line << endl;
    }
}

void add_player(SeqList* L)
{
    int i,j,m=0;
    double max=0,min=100;
    double sf;
    int f[10];
    cout<<"输入要添加的选手人数：";
    cin>>i;
    for(j=0;j<i;j++)
    {
        ofstream outfile("/Users/a20161104571/Desktop/选手信息.csv",ios::app);  //写入文件
        cout<<"选手姓名：";
        cin>>L->elem[j].name;
        outfile<<L->elem[j].name<<",";
        
        cout<<"选手性别：";
        cin>>L->elem[j].sex;
        outfile<<L->elem[j].sex<<",";
        
        cout<<"选手班级：";
        cin>>L->elem[j].clas;
        outfile<<L->elem[j].clas<<",";
        
        cout<<"选手节目名称：";
        cin>>L->elem[j].pro;
        outfile<<L->elem[j].pro<<",";
        
        cout<<"选手节目类型：";
        cin>>L->elem[j].type;
        outfile<<L->elem[j].type<<",";
        
        cout<<"选手电话：";
        cin>>L->elem[j].ach;
        outfile<<L->elem[j].ach<<",";
        
        cout<<"是否对选手进行打分「是（1）否（0）」"<<endl;
        cin>>m;
        if(m==1)
        {
            for(j=1;j<=5;j++)//评分
            {
                max=0;
                min=100;
                sf=0;
                cout<<"评委 "<<j<<" 给分:";
                cin>>f[j];
                sf=sf+f[j];
                if(max<f[j])
                {
                    max=f[j];
                }
                if(min>f[j])
                {
                    min=f[j];
                }
            }
            cout<<"去一个max:"<<max<<endl;
            cout<<"去一个min:"<<min<<endl;
            sf=(sf-max-min)/3;
            cout<<"选手最终得分:"<<sf<<endl;
            outfile<<sf<<endl;
        }
        else
        {
            outfile<<endl;
        }
    }

}

void referee()  //显示裁判信息
{
    int i=0;
    ifstream fin("/Users/a20161104571/Desktop/裁判信息.csv"); //打开文件流操作
    string line;
    while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
    {
        i++;
        cout <<"姓名,性别,电话："<< endl << line << endl;
    }

}

void sort()//排序
{
    float a[20];
    int m;
    int j;
    int r;
    float t;
    for(r=0;r<m-1;r++)     //对平均成绩进行排序;
    {
        for(j=0;j<m-1-r;j++)
            if(a[j]<a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
    }
    cout<<"由高到低排序后的成绩为："<<endl;
    for(r=0;r<m;r++)
        cout<<a[r]<<"  ";
    cout<<endl;
    cout<<"************************"<<endl;
    cout<<"************************"<<endl;
}

void ranking()  //显示排名
{
    float a[20];
    int m;
    int bh[20];
    int b[20];
    int i;
    if((a[0]!=a[1])&&a[1]!=a[2])
        
    {
        if(m>2){
            cout<<setw(18)<<"编号"<<setw(15)<<"成绩"<<endl;
            cout<<"冠军:   ";
            
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    break;
            }
            cout<<setw(7)<<bh[i];
            cout<<setw(14)<<a[0]<<endl;
            cout<<"亚军：  ";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[1])
                    break;
            }
            cout<<setw(7)<<bh[i];
            cout<<setw(14)<<a[1]<<endl;
            cout<<"季军：  ";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[2])
                    break;
            }
            cout<<setw(7)<<bh[i];
            cout<<setw(14)<<a[2]<<endl;
        }
        else{
            
            cout<<setw(18)<<"编号"<<setw(15)<<"成绩"<<endl;
            cout<<"冠军：   ";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    break;
            }
            cout<<setw(7)<<bh[i];
            cout<<setw(13)<<a[0]<<endl;
            cout<<"亚军：   ";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[1])
                    break;
            }
            cout<<setw(7)<<bh[i];
            cout<<setw(13)<<a[1]<<endl;
        }
    }
    
    else if((a[0]==a[1])&&(a[1]!=a[2]))
    {
        cout<<"**两位选手并列第一"<<endl;
        if(m>2)
        {
            cout<<"冠军   编号为:";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    cout<<bh[i]<<"  ";
            }
            cout<<"成绩为："<<a[1]<<endl;
            cout<<"亚军   编号为:";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[2])
                    break;
            }
            cout<<bh[i];
            cout<<"成绩为："<<a[2]<<endl;
            
        }
        else
        {
            cout<<"冠军   编号为:";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    break;
            }
            cout<<bh[i];cout<<"   ";
            cout<<"成绩为："<<a[1]<<endl;
        }
    }
    else if((a[0]!=a[1])&&(a[1]==a[2]))
    {
        if(m>2)
        {
            cout<<"**几位选手并列第二"<<endl;
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    break;
            }
            cout<<"冠军   编号为："<<bh[i];
            cout<<"成绩为："<<a[0]<<endl;
            
            cout<<"亚军   编号为：";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[1])
                    cout<<bh[i]<<"   ";
            }
            
            cout<<"成绩为："<<a[2]<<endl;
        }
        else
        {
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    cout<<"冠军   编号为："<<bh[i]<<"   ";}
            cout<<"成绩为："<<a[0]<<endl;
            for(i=0;i<m;i++)
            {
                if(b[i]==a[1])
                    cout<<"亚军   编号为："<<bh[i]<<"   ";
            }
            cout<<"成绩为："<<a[1]<<endl;
        }
    }
    else if((a[0]==a[1])&&(a[1]==a[2]))
    {
        if(m>2)
        {
            cout<<"**几位选手并列第一"<<endl;
            cout<<"冠军   编号为:";
            
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    cout<<bh[i]<<"   ";
            }
            cout<<"成绩为："<<a[0]<<endl;
            
        }
        else
        {
            cout<<"**两位选手并列第一"<<endl;
            cout<<"冠军   编号为:";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    cout<<bh[i]<<"   ";
            }
            
        }
    }
}

int main()
{
    int i;
    SeqList L;
    L.last=0;
    while(1)
    {
        cout<<"|-------------------------------|\n";
        cout<<"|---------1.裁判打分-------------|\n";
        cout<<"|---------2.显示选手名单----------|\n";
        cout<<"|---------3.添加选手信息----------|\n";
        cout<<"|---------4.显示裁判名单----------|\n";
        cout<<"|---------5.成绩排序-------------|\n";
        cout<<"|---------6.显示排名-------------|\n";
        cout<<"|---------0.退出系统-------------|\n";
        
        cout<<"\n 请选择：";
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                CountScore(&L);
                break;
            case 2:
                show();
                break;
            case 3:
                add_player(&L);
                break;
            case 4:
                referee();
                break;
            case 5:
                sort();
                break;
            case 6:
                ranking();
                break;
            case 0:
                return 0;
        }
    }
    return 0;
}
