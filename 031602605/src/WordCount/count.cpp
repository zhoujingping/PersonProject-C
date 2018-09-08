#include<iostream>
#include<fstream>	//实现文本输入输出流的头文件 
#include<string> 
#include<cstring>
#include<map>
using namespace std;


int main(int argc, char *argv[])//argc是命令行参数，*argv[]
{
	map<int,string> mapstr;
	long snum=0,i,num,rownum=0;
	int ans,ans2;
	string name,last;
	//读出文件
	ifstream rf;
	rf.open(argv[1]);
	while(!rf.eof())
	{
	getline(rf,name);
	ans=0,ans2=0;
	num=name.size();
	for(i=0;i<num;i++)
	{
		
		if(name[i]>=0&&name[i]<=127)
		{
			snum++;
		}
		if(!ans&&name[i]!=0x9&&name[i]!=0xd&&name[i]!=0xa&&name[i]!=0x20)
		{
			ans=1;//标记； 
		}
		if(name[i])
	}
	if(ans)rownum++;
	cout<<name<<endl;;	
	}
	cout<<snum<<"|"<<rownum;
	return 0;
}


