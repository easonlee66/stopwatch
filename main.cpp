#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
using namespace std;
struct timex{
	int fen,miao,hm;
};//记录时间
timex jc[11];//记录计次信息
timex min_time={2147483647,2147483647,2147483647},max_time={0,0,0};
int now_number;//记录现在计次到几了
int main(){
	now_number=1;
	int start=clock();
	while(1){
		if(kbhit()){
			int how=getch()-'0';
			if(how==1){
				now_number++;
				if(now_number>10){
					exit(3322577);
				}
				jc[now_number]=jc[now_number-1];
			}
			else{
				system("cls");
				for(int i=now_number;i>0;i--){
					cout << "计次" << i << ":  " << jc[i].fen << ":" << jc[i].miao << ":" << jc[i].hm << "\n";
				}
				cout << "复位请按1，继续请按2";
				while(!kbhit());//while循环里可以没有任何循环体
				how=getch()-'0';
				cout << how << endl;
				if(how!=2){
					now_number=1;
					jc[1].fen=jc[1].miao=jc[1].hm=0;
				}
			}
		}
		else{
			system("cls");
			long long now_hm=(clock()-start)/10;
			jc[now_number].fen=now_hm/100/60;
			jc[now_number].miao=now_hm/100%60;
			jc[now_number].hm=now_hm%100;
			for(int i=now_number;i>0;i--){
				cout << "计次" << i << ":  " << jc[i].fen << ":" << jc[i].miao << ":" << jc[i].hm << "\n";
			}
			cout << "计次请按1，暂停请按2";
		}
	}
	return 0;
}
//目前的bug：无法复位
//以后会有.exe，现在先自己编译吧^_^
