#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<algorithm>
using namespace std;
int main(){
	const vector<string>words={"BACON","COOL","NERD","FLAMBOYANT","JERK","PIG","CAT",
	"DOG","INTERESTING","SARCASTIC","CHICKEN","PIZZA","PROGRAM","GUITAR","VIOLIN",
	"ANTIDISESTABLISHMENTARIANISM,","COMPUTER","CANNON","GAME","URINE","FOOD"};
	vector<string>::size_type w;
	int tries_left=6;
	char current;
	srand(time(NULL));
	w=rand()%words.size();
	string chosen_word=words[w],showing,guessed;
	for(int size=chosen_word.size();size!=0;--size){
		showing+="_ ";
	}
	cout<<showing<<endl<<"You get "<<tries_left<<" fails."<<endl;
	while(cin>>current){
		bool is_correct=false,is_won=true,is_guessed=false;
		if(isalpha(current)){
			current=toupper(current);
			for(auto beg=guessed.begin();beg!=guessed.end();++beg){
				if(*beg==current){
					is_guessed=true;
				}
			}
			if(is_guessed==false){
				for(auto iter=chosen_word.begin();iter!=chosen_word.end();++iter){
					if(current==*iter){
						is_correct=true;
						auto index1=iter-chosen_word.begin();
						auto index2=2*index1;
						auto hold=showing.erase(showing.begin()+index2,showing.begin()+index2+1);
						showing.insert(hold,chosen_word[index1]);
						cout<<showing<<endl<<"Incorrect characters: "<<guessed<<endl;
					}
				}
				if(is_correct==false){
					--tries_left;
					guessed+=current;
					guessed+=' ';
					cout<<"Incorrect. Tries left: "<<tries_left<<endl
					<<"Incorrect characters: "<<guessed<<endl;
					if(tries_left==0){
						cout<<"You loose."<<endl<<"The word was: "<<chosen_word<<endl;
						break;
					}
				}
			}else{
				cerr<<"Error. "<<current<<" already guessed."<<endl;
			}
		}else{
			cerr<<"Error. Must be an alphabetical character."<<endl;
		}
		for(auto beg=showing.begin();beg!=showing.end();++beg){
			if(*beg=='_'){
				is_won=false;
			}
		}
		if(is_won==true){
			cout<<"Congratulations! You won!"<<endl;
			break;
		}
	}
	getch();
}
