#include<bits/stdc++.h>
using namespace std;
map<string,int>ma;
int cnt=0,del=0;
struct info{
	string id;
	string name;
	int age;
	string sex;
	string others;
	bool f;
	info(){
		f=1;
	}
	void read(){
		cin>>name>>age>>sex>>others;
	}
	void input(){
		printf("请输入姓名 年龄 性别 籍贯\n");
		cin>>name>>age>>sex>>others;
	}
	void output(){
		if(f)cout<<id<<" "<<name<<" "<<age<<" "<<sex<<" "<<others<<endl;
	}
	void change(){
		int x;
		printf("若删除输入1\n否则输入2\n");
		cin>>x;
		if(x==1){
			f=0;del++;return ;
		} 
		printf("请输入姓名 年龄 性别 籍贯\n");
		cin>>name>>age>>sex>>others;
	}
}p[200010];
int main(){
	while(1){
	printf("输入1添加个人信息\n");
	printf("输入2查询个人信息\n");
	printf("输入3修改个人信息\n");
	printf("输入4保存\n");
	printf("输入5导入\n");
	printf("输入6退出\n");
	int op;
	string cardid;
	scanf("%d",&op);
	if(op==1){
		printf("请输入身份证号\n");
		cin>>cardid;
		if(ma.count(cardid)&&p[ma[cardid]].f!=0){
			printf("已存在\n");
			continue;
		}
		else {
			cnt++;
			ma[cardid]=cnt;
			p[cnt].id=cardid;
			p[cnt].input();
		}
	}
	else if(op==2){
		printf("请输入身份证号\n");
		cin>>cardid;
		if(!ma.count(cardid)||p[ma[cardid]].f==0){
			printf("不存在\n");
			continue;
		}
		else {
			p[ma[cardid]].output();
		}
	}
	else if(op==3){
		printf("请输入身份证号\n");
		cin>>cardid;
		if(!ma.count(cardid)||p[ma[cardid]].f==0){
			printf("不存在\n");
			continue;
		}
		else {
			p[ma[cardid]].change();
		}
	}
	else if(op==4){
		printf("请输入要保存的文件名\n");
		string s;
		cin>>s;
		freopen(s.c_str(),"w",stdout);
		cout<<cnt-del<<endl;
		for(int i=1;i<=cnt;i++){
			p[i].output();
		}
		freopen("CON","w",stdout);
		printf("success\n");
	}
	else if(op==5){
		if(cnt!=0){
			printf("请关闭程序后导入\n");
			continue;
		} 
		printf("请输入要读取的文件名\n");
		string s;
		cin>>s;
		freopen(s.c_str(),"r",stdin);
		cin>>cnt;
		for(int i=1;i<=cnt;i++){
			cin>>cardid;
			p[i].id=cardid;
			p[i].read();
			ma[cardid]=i;
			p[i].output();
			p[i].f=1;
		}
		freopen("CON","r",stdin);
		printf("success\n");
	}
	else if(op==6){
		break;
	}
	else {
		printf("请输入1到6数字\n");
		continue; 
	}
	}
	return 0;
}
