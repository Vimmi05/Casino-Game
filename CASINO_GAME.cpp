#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
void rules()
{
    system("cls");
    cout << "\t\t----------CASINO NUMBER GUESSING RULES!----------\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}
int main(){
	string playerName;
	int balance;
	int bettingAmount;
	int guess;
	int dice;       //stores the random number
	char choice;
	srand(time(0));      //ssed the random generator
	cout<<"\n\t\t----------WELCOME TO THE CASINO WORLD----------"<<endl<<endl;
	cout<<"What's your palyer name : ";
	getline(cin,playerName);
	cout<<"Enter the starting amount to play : $";
	cin>>balance;
	do{
		system("cls");
		rules();
		cout<<"Your current balance is $"<<balance<<endl;
		do{
			cout<<"Hey, "<<playerName<<" , Enter the amount to bet : $";
			cin>>bettingAmount;
			if(bettingAmount>balance)
			 cout<<"Betting balnce can't be more than the current balance !!"
			 <<"\nRe-enter balance "<<endl;
		}
		while(bettingAmount>balance);
	
	    do{
	    	cout<<"Guess any number between 1 to 10 : ";
	    	cin>>guess;
	    	if(guess<=0 || guess>10)
	    	cout<<"\nNumber should only be between 1 to 10 "
	    	<<"\nRe-enter number : ";
		}
		while(guess<=0 || guess>10);
		dice=rand()%10+1;
		if(dice==guess){
			cout<<"\nYou are lucky!!!You have won $ "<<bettingAmount*10;
			balance=balance+bettingAmount*10;
		}
		else
		{
		    cout<<"Oops,better luck next time !! You lost $"<<bettingAmount<<endl;
		    balance=balance-bettingAmount;
		}
		cout<<"\nThe winning number : "<<dice;
		cout<<"\n"<<playerName<<", You have balance of $"<<balance<<endl;
		if(balance==0){
			cout<<"You have no ammount left to play.";
			break;
		}
		cout << "\n\nDo you want to play again (y/n)? ";
        cin >> choice;
    }
	while(choice =='Y'|| choice=='y');
    cout <<endl<<endl;
    cout << "\n\nThanks for playing the game. Your balance is $ " << balance << "\n\n";
    return 0;
}

