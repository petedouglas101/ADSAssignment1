#define _CRT_SECURE_NO_WARNINGS //Allows me to use scanf instead of scanf_f
//Defining a boolean
#define bool int
#define false 0
#define true (!false);
#include <stdio.h>//Standard input/output


//Function Prototypes
void inputABook();
void takeOutABook();
void returnABook();
void deleteABookFromStock();
void viewAllBooks();
void viewASpecificBook();
void viewMostAndLeatPopular();

//Book Structure
struct book {
	char identifier[9];
	char name[25];
	char author[25];
	int yearOfPub;
	bool status;
	char custName[25];
	int count;
};



void main() {
		int option;//Variable to hold option for menu
	    printf("Welcome to the Library!\nPlease select from one of the following options: \n");//Welcome message of menu
	    printf("1. Add a new book\n2. Allow customer to take out book\n3. Allow customer to return a book\n4. Delete an old book from stock\n5. View all books\n6. View a specific book\n7. View details of most popular and least popular books\n8. Exit");//Displaying the menu and the options
	    scanf("%d", &option);
	switch (option) {
	case 1:
		inputABook();
		break;
	case 2:
		takeOutABook();
		break;
	case 3:
		returnABook();
		break;
	case 4:
		deleteABookFromStock();
		break;
	case 5:
		viewAllBooks();
		break;
	case 6:
		viewASpecificBook();
		break;
	case 7:
		viewMostAndLeastPopular();
		break;
	}


}