#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#define HANDLE GetStdHandle(STD_OUTPUT_HANDLE)
#define red SetConsoleTextAttribute(HANDLE,FOREGROUND_RED|FOREGROUND_INTENSITY)
#define ri SetConsoleTextAttribute(HANDLE,FOREGROUND_GREEN|FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE)
#define green SetConsoleTextAttribute(HANDLE,FOREGROUND_GREEN|FOREGROUND_INTENSITY)
#define blue SetConsoleTextAttribute(HANDLE,FOREGROUND_BLUE|FOREGROUND_INTENSITY)
#include <vector>
using namespace std;
struct timex{
	int fen,miao,hm;
	timex(int fen,int miao,int hm): fen(fen),miao(miao),hm(hm){}
	timex(int hm): fen(hm/CLOCKS_PER_SEC/60),miao(hm/CLOCKS_PER_SEC),hm(hm){}
	bool operator<(timex x){
		if(this->fen!=x.fen){
			return this->fen<x.fen;
		}
		if(this->miao!=x.miao){
			return this->miao<x.miao;
		}
		if(this->hm!=x.hm){
			return this->hm<x.hm;
		}
		return false;
	}
	bool operator>(timex x){
		if(this->fen!=x.fen){
			return this->fen>x.fen;
		}
		if(this->miao!=x.miao){
			return this->miao>x.miao;
		}
		if(this->hm!=x.hm){
			return this->hm>x.hm;
		}
		return false;
	}
	bool operator==(timex x){
		return this->fen==x.fen&&this->miao==x.miao&&this->hm==x.hm;
	}
	bool operator<=(timex x){
		timex y=*this;
		return y<x||y==x;
	}
	bool operator>=(timex x){
		timex y=*this;
		return y>x||y==x;
	}
	int toint(){
		int hmx;
		hmx=this->miao;
		hmx+=this->fen*60;
		hmx*=CLOCKS_PER_SEC;
		hmx+=this->hm;
		return hmx;
	}
	int operator-(timex x){
		return this->toint()-x.toint();
	}
};//时间结构体
vector <timex> jc;//计次信息
int minti=1,maxti=1;
int now_number;//目前计次数
int main(){
	now_number=1;
	int start=clock();
	jc.push_back(timex(0));
	jc.push_back(timex(0));
	while(1){
		if(kbhit()){
			int how=getch()-'0';
			if(how==1){
				if((jc[now_number]-jc[now_number-1])<(jc[minti]-jc[minti-1])){
                    minti=now_number;
                }
                if(jc[now_number]>jc[maxti]){
                    maxti=now_number;
                }
				now_number++;
				jc.push_back(jc[now_number-1]);
			}
			else{
				int pause=clock();
				system("cls");
				for(int i=now_number;i>0;i--){
	                if(i==minti&&now_number!=1&&i!=maxti){
    	                green;
        	        }
            	    if(i==maxti&&now_number!=1&&i!=minti){
                	    red;
	                }
    	            if(i==minti&&i==maxti&&now_number!=1){
        	        	blue;
					}
					cout << "计次" << i << ":  " << jc[i].fen << ":" << jc[i].miao << ":" << jc[i].hm << "\n";
	                ri;
				}
				cout << "按1复位，按2继续";
				while(!kbhit());
				how=getch()-'0';
				if(how!=2){
					now_number=1;
					jc.clear();
					minti=maxti=1;
					start=clock();
				}
				else{
					start+=(clock()-pause);
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
                if(i==minti&&now_number!=1&&i!=maxti){
                    green;
                }
                if(i==maxti&&now_number!=1&&i!=minti){
                    red;
                }
                if(i==minti&&i==maxti&&now_number!=1){
                	blue;
				}
				cout << "计次" << i << ":  " << jc[i].fen << ":" << jc[i].miao << ":" << jc[i].hm << "\n";
                ri;
            }
			cout << "按1计次，按2暂停";
		}
	}
	return 0;
}
