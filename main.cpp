#include <iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

const int height = 10;
const int width = 10;
const int slen = 10;
int dirx;
int diry;
int fruitx;
int fruity;
int head;
int score;

struct snake{
	int x;
	int y;
};
struct snake s[slen];
//initialize the game board
void init(){
	score = 0;
	head = 0;
	dirx = diry = 0;
	s[head].x = 0;
	s[head].y = 0;
	fruitx = rand()%width;
	fruity = rand()%height;
}
//draw the game board
void draw(){
	int flag;
	for(int i=0;i<height;i++){
		cout<<"|";
		for(int j=0;j<width;j++){
			flag =0;
			for(int k=0;k<=head;k++)
			{
				if(i==s[k].y && j==s[k].x){
					cout<<"0";
					flag=1;
				}
			}
			if(i==fruity && j==fruitx){
				cout<<"*";
				flag=1;
			}
			if(flag==0){
				cout<<" ";
			}
		} 
		cout<<"|"<<endl;
	}	
	cout<<"\nScore : "<<score;
}
void update(){
	//key event handler
	if(_kbhit()){
		switch(_getch()){
			case 's':
				diry = 1;
				dirx = 0;
				break;
			case 'd':
				dirx = 1;
				diry=0; 
				break;
			case 'a':
				dirx = -1;
				diry=0;
				break;
			case 'w':
				diry = -1;
				dirx=0;
				break;
				
		}
	}
	//check if food and snake head are equal
	if(s[head].x==fruitx && s[head].y==fruity){
		head++;
		s[head].x = fruitx;
		s[head].y = fruity;
		fruitx = rand()%width;
		fruity = rand()%height;
		score++;
	}
	//snake body update
	for(int i = 0;i<head;i++){
		s[i].x= s[i+1].x;
		s[i].y=s[i+1].y;		
	}
		
	if(dirx==1){
		s[head].x +=1;
		s[head].y +=0;
	}
	else if(dirx==-1){
		s[head].x -=1;
		s[head].y +=0;
	}
	else if(diry==1){
		s[head].x +=0;
		s[head].y +=1;
	}
	else{
		s[head].x +=0;
		s[head].y -=1;
	}
	
}
bool gameOver(){
	if(s[head].x>=width || s[head].y>=height || s[head].x<0 || s[head].y<0)
	return 1;
	return 0;
}
int main(int argc, char** argv) {	
	init();
	dirx=1;
	draw();
	getch();
	system("cls");
	
	for(;;){
		
		draw();
		Sleep(300);
		update();
		if(gameOver()){
			cout<<"\nGameOver...!\n";
			exit(0);
		}
		system("cls");
	}
	
	getch();
	return 0;
}
