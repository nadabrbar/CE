// Writer name :Mohamed Okasha
// Course : 451

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

 #define r1 1
 #define r2 2
 #define r3 3
 #define r4 4
 #define r5 5
 #define r6 6


  #define num_proc 7


 int crs=0;

 struct proc{

	 long idp  ;
	 int state ;  // 0=block 1=ready 2=running
	 int priority ;
	 long pc;
	 void *mp;
	 char *context ;        // for example address of data segments
	 int ios;  // 0 not read not write , 1 Read , 2 write


	 struct proc* next;
 }  ;

 int dEvent[num_proc] ; // for example  [0,1] click ,  print char ,  type character

	  void exEvent(int id,char te)   ;

 char CriticalSection (int idp);
 int execute(int idp);
 struct proc* Generation(char sharedata[num_proc][20]) ;

 int Disspather(struct proc *head) ;


		int processor1(int idp);
		// int processor2(int idp);
 char shared_data[num_proc][1]={"","s","u","c","c","e","e"};    //  character word success


int main(){


struct proc *   process ;
struct proc *   tmp ;

			int i;

 process = Generation  (shared_data);

		 printf(	process[1].idp);


			 Disspather(process);

	  // for example






















return 0;
}

 int execute(int idp){
	 char ch;
	 if (dEvent[idp]) {

	 ch=CriticalSection(idp);

	  printf("\n	*%c",ch) ;
		dEvent[idp]=0;
	  return 1;
	 }
 return 0;
 }

void exEvent(int idp, char event){

	 switch(event){
	 case 'c':
	 dEvent[idp]=1;
	 break;
	 case 't':
	 dEvent[idp]=2;
	 break;
	 case 'p':
	 dEvent[idp]=3;
	 break;

	 default:
		dEvent[idp]=11;
		  }



	 }




	int  processor1(int idp){
	if (execute(idp))
	  crs--    ;
	return 0;
	}
	/*
	int  processor2(int idp){
	if (execute(idp))
	  crs--
	return 0;
	}
		 */

  int  Disspather(struct proc *head) {

			  struct proc * current = head;




			 while (current != NULL) {

				 processor1 (current->idp)    ;
			// do something with *current node
				 current = current->next;
			 }







  return 0;




  }














char CriticalSection (int idp){

	crs++;

	if (crs>1){
	printf("\n	Error %d nprocess in critical section ",crs);
	return '^';
	}
	printf("\nprocess %d in critical section",idp) ;


// printf("\nprocess %d leave critical section",idp)

return *shared_data[idp];
}


struct proc* Generation(char sharedata[num_proc][20])
{

struct proc *pcb[num_proc] ;
	int i=1;


// base
  pcb[0]->idp=1000;

//-------------------------/////////

for(i=1;i<=4;i++){

pcb[i] = malloc(sizeof(struct proc));

if (pcb[i]==NULL)
goto err;

}
  // setting up

for(i=1;i<=num_proc;i++){
			/*
randomize();
// pcb[i]->idp=  pcb[i-1]->idp++;                   //random (500+);
pcb[i]->state-> 1;
pcb[i]->priority= random (1);
pcb[i]->ios=0;
pcb[i]->next =pcb[i+1]           ;
 // pcb[n]->context= sharedata[n]; // remember context for thes example pointer only to data segment
			 */
}
 // pcb[num_proc] ->next=	NULL;


return pcb[1];


err:

printf("\n	Error! in parbegand process , not enough memory ");

return 	NULL;
}







