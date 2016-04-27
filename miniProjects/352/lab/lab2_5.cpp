#include<conio.h>
#include<iostream.h>
void fibonaci(int);
void main(){
int terms;
cout<<"enter how many term= "; //jomana and reham 
cin>>terms;
fibonaci(terms);
getch();

}
void fibonaci(int term){
	int sum=0;
	int num2=1;
	int fibo=0;
	
	for(int i=0;i<term;i++){
	cout<<fibo<<',';
	sum=fibo+num2;
	fibo=num2;
	num2=sum;
	}
	cout<<endl;


}
