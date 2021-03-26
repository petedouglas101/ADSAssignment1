#define _CRT_SECURE_NO_WARNINGS //Pre processor that allows me to use scanf instead of scanf_f
//Pre processor for defining a boolean
#define bool int
#define false 0
#define true (!false);
#define MAX 10//Definng a MAX constant
#include <stdio.h>//Standard input/output header file
#include <stdlib.h>//Standard library header file
#include <string.h>//Standard string header file


//Function Prototypes
void inputABook();
void borrowABook();
void returnABook();
void deleteABookFromStock();
void viewAllBooks();
//void viewASpecificBook();
//void viewMostAndLeatPopular();
bool isEmpty();

//Book Structure
struct Book {
	char identifier[9];
	char name[25];
	char author[25];
	int yearOfPub;
	bool isAvailable;
	char custName[25];
	int count;
};

//Linear Node Structure
struct LinearNode {
	struct Book *element;
	struct LinearNode *next;
};

// Global Variables
struct LinearNode *first = NULL; //pointer to first element in the list
struct LinearNode *last = NULL; //pointer to last node in list
int bookCount = 0;





void main() {

	int option;//Variable to hold option for menu
	printf("Welcome to the Library!\nPlease select from one of the following options: \n");//Welcome message of menu
	do {
		printf("1. Add a new book\n2. Allow customer to take out book\n3. Allow customer to return a book\n4. Delete an old book from stock\n5. View all books\n6. View a specific book\n7. View details of most popular and least popular books\n8. Exit");//Displaying the menu and the options
		scanf("%d", &option);

		switch (option) {
		case 1:
			if (bookCount <= 10) {
				inputABook();
			}
			else {
				printf("ERROR - Too many books in the system!");
			}
			break;
		case 2:
			borrowABook();
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
		case 9:
			break;
		default:
			printf("Invalid selection - try again!");
			break;
		}
	} while (option != 9);

}

//Function for inputting a book
void inputABook() {

	struct Book *aBook;
	struct LinearNode *aNode;//Creating a Linear Node for storing each book

	//Variables for storing data on each book
	int yearOfPub;
	bool isAvailable = true;
	char custName[25];
	int count = 0;

	int i;//Index variable

	//Loop that goes around MAX times for entering new book details
	for (i = 0; i < MAX; i++) {

		aBook = (struct Book*)malloc(sizeof(struct Book));//Allocate memory for new Book element
		aNode = (struct LinearNode*)malloc(sizeof(struct LinearNode));//Allocate memory for new Linear Node 

		printf("Please enter book identifier (8 digit number in the form xxxx-xxxx): \n");
		scanf("%s", aBook->identifier);

		printf("Please enter the name of the book: \n");
		scanf("%s", aBook->name);

		printf("Please enter the name of the author: \n");
		scanf("%s", aBook->author);

		do {
			printf("Please enter the year of publication: \n");
			scanf("%d", &aBook->yearOfPub);
			fflush(stdin);
			if (yearOfPub < 2008) {
				printf("Year of publicaion must be after 2008 - Please enter again!\n");
			}
		} while (yearOfPub < 2008);

		aBook->isAvailable = isAvailable;
		strcpy(aBook->custName, custName);
		aBook->count = count; 

		if (aNode == NULL) {
			printf("Error - no space for new node!");
		}
		else {
			aNode->next = NULL;
			aNode->element = aBook;
		}

		
		//add node to front of the list
		if (isEmpty())
		{
			first = aNode;
			last = aNode;
		}
		else {
			aNode->next = first;
			first = aNode;
		}

		bookCount++;

	}

	
}

//Function for borrowing a book
void borrowABook() {
	char iden[9];
	char name[25];
	struct LinearNode *current = first;
	printf("Please enter the identifier of the book you wish to borrow: ");
	scanf("%s", iden);

	while (current != NULL && strcmp(current->element->identifier, iden) != 0) {
		current = current->next;
	}

	if (current == NULL) {
		printf("This book does not exist!");
	}
	else {
		printf("We have found the book you are looking for!\n");
		if (current->element->isAvailable != false){
			printf("Please enter your name: \n");
			scanf("%s", name);
			strcpy(current->element->custName, name);
			current->element->isAvailable = false;
			current->element->count++;

		}
		else {
			printf("But it is unavailable right now!\n");
		}
	}
}

//Function for returning a borrowed book
void returnABook() {
	char iden[9];
	char custName[25];
	printf("Please enter your name: \n");
	gets("%s", custName);
	printf("Please enter the identifier of the book you wish to return: \n");
	gets("%s", custName);
	struct LinearNode* current = first;
	while (current != NULL && strcmp(current->element->identifier, iden) != 0 && strcmp(current->element->custName, custName) != 0){
		current = current->next;
	}

	if (current == NULL) {
		printf("Book/Customer has not been found!");
	}

	if (strcmp(current->element->identifier, iden) == 0 && strcmp(current->element->custName, custName) == 0) {
		printf("Thank you for returning the book on time!");
		current->element->isAvailable = true;

	}

}

//Function for delesting a book from stock
void deleteABookFromStock() {
	char iden[9];
	struct LinearNode* current, * previous;
	bool found = false;
	printf("Please enter the identifier of the book you wish to delete: \n");
	gets("%s", iden);

	if (isEmpty()) {
		printf("ERROR - There are no books in the library!\n");
	}
	else {
		current = previous = first;
		while (!found && current != NULL) {
			if (strcmp(iden, current->element->identifier) == 0) {
				found = true;
			}
			else {
				current = current->next;
				previous = current;
			}
		}

		if (!found) {
			printf("ERROR - This book does not exist!\n");
		}
		else {
			if (current == first) {
				first = first->element;
				free(current);
			}
			else {
				previous->next = current->next;
				free(current);
			}

			printf("%s has been deleted!\n", iden);
		}
	}




	
}

//Function for viewing all books in the list
void viewAllBooks() {
	struct LinearNode* current;

	if (isEmpty())
		printf("Error - there are no books in the list\n");
	else {
		current = first;
		while (current != NULL) {
			printf("Book Identifier: %s\nBook Title: %s\nAuthor: %s\nPublished: %d", current->element->identifier, current->element->name, current->element->author, current->element->yearOfPub);
			current = current->next;
		}
	}
}

//Function that returns true if Linked List is empty and false if not
bool isEmpty() {
	if (first == NULL) {
		return true;
	}
	else {
		return false;
	}
}

