#define _CRT_SECURE_NO_WARNINGS //Pre processor that allows me to use scanf instead of scanf_f
//Pre processor for defining a boolean
#define bool int
#define false 0
#define true (!false);
#define MAX 10//Definng a MAX constant
#include <stdio.h>//Standard input/output header file
#include <stdlib.h>//Standard library header file
#include <string.h>


//Function Prototypes
void inputABook();
void borrowABook();
void returnABook();
void deleteABookFromStock();
void viewAllBooks();
void viewASpecificBook();
void viewMostAndLeatPopular();
bool isEmpty();

//Book Structure
struct Book {
	char identifier[9];
	char name[25];
	char author[25];
	int yearOfPub;
	bool status;
	char custName[25];
	int count;
};

//Linear Node Structure
struct LinearNode {
	struct Book *element;
	struct LinearNode *next;
};

// Global Variables
struct LinearNode *first = NULL; //front of list
struct LinearNode *last = NULL; //pointer to last node in list
int bookCount = 0;





void main() {
	do {
		int option;//Variable to hold option for menu
		printf("Welcome to the Library!\nPlease select from one of the following options: \n");//Welcome message of menu
		printf("1. Add a new book\n2. Allow customer to take out book\n3. Allow customer to return a book\n4. Delete an old book from stock\n5. View all books\n6. View a specific book\n7. View details of most popular and least popular books\n8. Exit");//Displaying the menu and the options
		scanf("%d", &option);

		switch (option) {
		case 1:
			inputABook();
			break;

		case 2:
			borrowABook();
			break;

		case 5:
			viewAllBooks();
			break;
		}

	} while (option != 9);

}

//Function for inputting a book
void inputABook() {

	struct Book *aBook;
	struct LinearNode *aNode;//Creating a Linear Node for storing each book

	//Variables for storing data on each book
	char identifier[9];
	char name[25];
	char author[25];
	int yearOfPub;
	bool status = false;
	char custName[25];
	int count = 0;

	int i;//Index variable

	struct Book* aBook;
	struct LinearNode* aNode;//Creating a Linear Node for storing each book

	//Loop that goes around MAX times for entering new book details
	for (i = 0; i < MAX; i++) {

		printf("Please enter book identifier (8 digit number in the form xxxx-xxxx): \n");
		scanf("%s", identifier);

		printf("Please enter the name of the book: ");
		scanf("%s", name);

		printf("Please enter the name of the author: ");
		fflush(stdin);
		scanf("%s", author);

		do {
			printf("Please enter the year of publication: \n");
			scanf("%d", &yearOfPub);
			if (yearOfPub < 2008) {
				printf("Year of publicaion must be after 2008 - Please enter again!\n");
			}
		} while (yearOfPub < 2008);

		aBook = (struct Book *)malloc(sizeof(struct Book));//Allocate memory for new Book element
		aNode = (struct LinearNode *)malloc(sizeof(struct LinearNode));//Allocate memory for new Linear Node 

		aBook->identifier = identifier;
		aBook->name = name;
		aBook->author = author;
		aBook->yearOfPub = yearOfPub;
		aBook->status = status;
		aBook->custName = custName;
		aBook->count = count;

		if (aNode == NULL) {
			printf("Error - no space for new node!");
		}
		else {
			aNode->element = NULL;
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
void borrowABook()

//Function for viewing all books in the list
void viewAllNodes() {
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