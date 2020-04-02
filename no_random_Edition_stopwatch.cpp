//Because the Chinese version will be garbled, I will provide another English version. If you don't understand, please go to Baidu translation (https://fanyi.baidu/com) to translate the content.
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
using namespace std;
struct timex{
	int fen,miao,hm;
};//Structure representing time
timex jc[11];//Record count information
int now_number;//How many times is the record now
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
					cout << "record" << i << ":  " << jc[i].fen << ":" << jc[i].miao << ":" << jc[i].hm << "\n";
				}
				cout << "Press 2 to continue, press 1 to reset";
				while(!kbhit());//There can be no loop bodies in a while loop
				how=getch()-'0';
				if(how!=2){
					now_number=1;
					start=clock();
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
				cout << "record" << i << ":  " << jc[i].fen << ":" << jc[i].miao << ":" << jc[i].hm << "\n";
			}
			cout << "Press 1 to recoud,press 2 to pause";
		}
	}
	return 0;
}
