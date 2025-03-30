#include<iostrdeam.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char pass1[100], pass2[100], user1[100], user2[100];
int option = 0, vowelc = 0, numc = 0, pass1Len = 0, invalidc = 0;

void registration(){
	cout<<"**************REGISTRATION**************"<<endl<<endl;
	    cout<<"Username: ";
	    gets(user1);
	    invalidpass:
	    cout<<"Password: ";
	    gets(pass1);
	    pass1Len = strlen(pass1);
	    pass1[pass1Len] = '\0';


	    for (int i = 0; pass1[i] != '\0'; i++){
			if (isdigit(pass1[i])){
				numc++;
			} else if ((pass1[i] == 'a') ||
			(pass1[i] == 'e') || (pass1[i] == 'i') ||
			(pass1[i] == 'o') || (pass1[i] == 'u')){
				vowelc++;
			}
	    }


	    if ((pass1Len < 8) || pass1Len > 12){
			cout<<"Invalid: Password must be 8 to 12 characters long\n"<<endl;
			vowelc = 0;
			numc = 0;
			goto invalidpass;
	    }

	    if (numc < 2){
			cout<<"Invalid: Password must have at least two numbers\n"<<endl;
			vowelc = 0;
			numc = 0;
			goto invalidpass;
	    }

	    if (vowelc < 2){
			cout<<"Invalid: Password must have at least two vowels\n"<<endl;
			numc = 0;
			vowelc = 0;
			goto invalidpass;
	    }

	    cout<<"\nAccount Successfully Registered!\n"<<endl;
}
void login(){
	cout<<"**************LOGIN**************"<<endl<<endl;
	    Invalid:


	    if (invalidc == 3){
			cout<<"Maximum number of attempts exceeded. Program terminated!";
			getch();
			exit(0);
	    }
	    cout<<"Username: ";
	    gets(user2);
	    cout<<"Password: ";
	    gets(pass2);

	    if (strcmp(user2, user1) != 0){
			cout<<"Invalid Username"<<endl;
			invalidc++;
			goto Invalid;
	    }
	    if (strcmp(pass2, pass1) != 0){
			cout<<"Invalid Password"<<endl;
			invalidc++;
			goto Invalid;
	    }



	    cout<<"Login Successfully!";
}
main(){
    clrscr();

    start:
    cout<<"**************MENU**************"<<endl<<endl;
    cout<<"  [1] - Register "<<endl;
    cout<<"  [2] - Login "<<endl<<endl;
    cout<<"********************************"<<endl;
    cout<<"Option: ";
    cin>>option;

    if (option == 1){
	   registration();
	   goto start;
    } else if(option == 2){
	  login();
    }
    getch();
}
