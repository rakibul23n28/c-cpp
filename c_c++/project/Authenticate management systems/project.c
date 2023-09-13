#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_BOOK 100
#define MAX_MEMBERS 100

struct Library
{
    char books_name[100];
    char author_name[100];
    int unique_token;
    
};
struct Library books[MAX_BOOK];
int total_books = 0;

struct Members
{
   char username[100];
   long long unique_id;
   int borrow_books;
   int total_book_borrowed;
   bool admin_or_not;
};
struct Members members[MAX_MEMBERS];
int member_no=0;

//landing page
void registerMember();
void login();
bool is_unique(long long id);
void loadMembersFromFile();

//admin page
void admin_page();
void show_student_details();
void show_admin_details();
void saveRegisterMemberinFILE();
void remove_student();
void saveBooksToFile();
void loadBooksDetailsFromFile();
void add_new_book();
//student page
void student_page(struct Members *student);
void view_profile(struct Members student);
void available_books();
void borrow_book(struct Members *student);
void return_book(struct Members *student);

//main funnction
int main(){
    loadMembersFromFile();
    loadBooksDetailsFromFile();
    int choice;
    do
    {
        choice=3;
        printf("Menu:\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                registerMember();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }while(choice!=3);
}
//admin page after authentication

void admin_page() {
    int admin_choice;
    do {
        admin_choice=8;
        printf("Admin Page:\n");
        printf("1. Show Student Details\n");
        printf("2. Show Admin Details\n");
        printf("3. Remove Student\n");
        printf("4. Save register members and Added books in file\n");
        printf("5. Total members\n");
        printf("6. Add new book\n");
        printf("7. Available books\n");
        printf("8. LOGOUT\n");
        printf("Enter your choice: ");
        scanf("%d", &admin_choice);

        switch(admin_choice){
            case 1:
                show_student_details();
                printf("\n");
                break;
            case 2:
                show_admin_details();
                printf("\n");
                break;
            case 3:
                remove_student();
                printf("\n");
                break;
            case 4:
                saveRegisterMemberinFILE();
                saveBooksToFile();
                printf("Member information saved to members.txt\n");
                printf("Book information saved to books.txt\n");
                printf("\n");
                break;
            case 5:
                printf("Total member: %d\n", member_no);
                printf("\n");
                break;
            case 6:
                add_new_book();
                printf("\n");
                break;
            case 7:
                available_books();
                printf("\n");
                break;
            case 8:
                system("cls");
                printf("Logging out from admin page.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while(admin_choice!=8);
}

//student page after authentication

void student_page(struct Members *student){
    int student_choice;
    do {
        student_choice=5;
        printf("\nStudent Page:\n");
        printf("1. View Profile\n");
        printf("2. Borrow a book\n");
        printf("3. Return Book\n");
        printf("4. Available books\n");
        printf("5. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &student_choice);

        switch(student_choice) {
            case 1:
                system("cls");
                view_profile(*student);
                printf("\n");
                break;
            case 2:
                borrow_book(student);
                printf("\n");
                break;
            case 3:
                return_book(student);
                printf("\n");
                break;
            case 4:
                available_books();
                printf("\n");
                break;
            case 5:
                system("cls");
                printf("Logging out from student page.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while(student_choice!=5);
}

//register method
void registerMember(){
    if(member_no<100){
        char name[100];
        printf("Enter Username: ");
        scanf(" %[^\n]", name);
        long long id;
        printf("Enter Unique id: ");
        scanf(" %lld", &id);
        if(is_unique(id)){
            members[member_no].unique_id=id;
            strcpy(members[member_no].username,name);
            members[member_no].admin_or_not=false;
            //
            FILE *file=fopen("members.txt","a");
                fprintf(file, "%s,%lld,%hhd,%d,%d\n",members[member_no].username,members[member_no].unique_id,members[member_no].admin_or_not ? 1 : 0,members[member_no].borrow_books,members[member_no].total_book_borrowed);
            fclose(file);
            //
            (member_no)++;
            return;
        }
        else {
            printf("This ID already Exist, Please TRY AGINE\n");
            return;
        }
    }
}
//login method


void login() {
    long long id;
    printf("Enter your Unique ID: ");
    scanf("%lld", &id);
    bool found=false;
    for(int i=0;i<member_no;i++){
        if(members[i].unique_id==id){
             found=true;
            if(members[i].admin_or_not){
                
                int choise;
                do
                {
                    choise=3;
                    printf("1. Login as a Admin\n");
                    printf("2. Login as a Student\n");
                    printf("3. Back in landing page\n");
                    scanf(" %d", &choise);
                    switch (choise)
                    {
                    case 1:
                        system("cls");
                        printf("Admin login successful\n");
                        admin_page(members,member_no);
                        choise=3;
                        break;
                    case 2:
                        system("cls");
                        printf("Student login successful\n");
                        student_page(&members[i]);
                        choise=3;
                        break;
                    case 3:
                        system("cls");
                        printf("3. Back in landing page\n");
                        break;
                    default:
                        printf("Invalid choice. Please select a valid option.\n");
                    }

                    
                } while(choise!=3);
                break;
            }
            else{
                system("cls");
                printf("Student login successful\n");
                student_page(&members[i]);
            }
            break;
        }
    }
    if(!found){
        printf("Member not found. Please register or provide a valid Unique ID.\n");
    }
}

void saveRegisterMemberinFILE(){
    FILE *file=fopen("members.txt","w");
    if(file==NULL){
        printf("ERROR opening file.\n");
        return;
    }
    for(int i=0;i<member_no;i++){
        fprintf(file, "%s,%lld,%hhd,%d,%d\n",members[i].username,members[i].unique_id,members[i].admin_or_not ? 1 : 0,members[i].borrow_books,members[i].total_book_borrowed);
    }
    fclose(file);
}
void saveBooksToFile(){
    FILE *file=fopen("books.txt","w");
    if(file==NULL){
        printf("ERROR opening book file for writing.\n");
        return;
    }
    for(int i=1;i<total_books;i++){
        fprintf(file, "%s,%s,%d\n",books[i].books_name,books[i].author_name,books[i].unique_token);
    }

    fclose(file);
}

//load informetion from file
void loadMembersFromFile(){
    FILE *file=fopen("members.txt", "r");
    if (file==NULL){
        printf("ERROR opening file for reading.\n");
        return;
    }
    while(member_no<MAX_MEMBERS && fscanf(file, " %[^,],%lld,%hhd,%d,%d\n",members[member_no].username,&members[member_no].unique_id,&members[member_no].admin_or_not,&members[member_no].borrow_books,&members[member_no].total_book_borrowed) == 5){
        if (is_unique(members[member_no].unique_id)&& (members[member_no].borrow_books==1 || members[member_no].borrow_books==0)){
            (member_no)++;
        }
        else{
            printf("Non-unique ID found in file. Skipping entry.\n");
        }
    }
    fclose(file);
}
void loadBooksDetailsFromFile(){
    FILE *file=fopen("books.txt","r");
    if (file==NULL){
        printf("ERROR opening book file for reading.\n");
        return;
    }
    total_books=1;

    while (total_books<MAX_BOOK && fscanf(file, " %[^,],%[^,],%d\n",books[total_books].books_name,books[total_books].author_name,&books[total_books].unique_token)==3){
        total_books++;
    }

    fclose(file);
}

bool is_unique(long long id){
    for (int i = 0; i < member_no; i++)
    {
        if(members[i].unique_id==id) return false;
    }
    return true;
    
}

//login page 

void show_student_details(){
    FILE *file=fopen("student_details.txt", "w");
    if(file==NULL){
        printf("ERROR opening file.\n");
        return;
    }
    for(int i=0;i<member_no;i++){
        if (!members[i].admin_or_not){
            fprintf(file, "Username: %s\nID: %lld\nStatus: Student\nBorrowed Books: %d\nTotal book borrowed: %d\n\n\n",members[i].username,members[i].unique_id,members[i].borrow_books,members[i].total_book_borrowed);
            printf("Username: %s\nID: %lld\nStatus: Student\nBorrowed Books: %d\nTotal book borrowed: %d\n",members[i].username,members[i].unique_id,members[i].borrow_books,members[i].total_book_borrowed);
            printf("____________________________________________________________________________\n\n");
        }
    }
    fclose(file);
    printf("Student information saved to student_details.txt\n");
}
void show_admin_details() {
    FILE *file=fopen("admin_details.txt", "w");
    if(file==NULL){
        printf("ERROR opening file.\n");
        return;
    }
    for (int i=0;i<member_no;i++) {
        if (members[i].admin_or_not) {
            fprintf(file, "Username: %s\nID: %lld\nStatus: Admin\nBorrowed Books: %d\nTotal book borrowed: %d\n\n\n",members[i].username,members[i].unique_id,members[i].borrow_books,members[i].total_book_borrowed);
            printf("Username: %s\nID: %lld\nStatus: Admin\nBorrowed Books: %d\nTotal book borrowed: %d\n",members[i].username,members[i].unique_id,members[i].borrow_books,members[i].total_book_borrowed);
            printf("____________________________________________________________________________\n\n");

        }
    }
    fclose(file);
    printf("Admin information saved to admin_detaile.txt\n");
}
void remove_student(){
    long long id;
    printf("Enter the Unique ID of the student to remove: ");
    scanf(" %lld", &id);
    for(int i=0;i<member_no;i++){
        if((members[i].unique_id==id) && (members[i].admin_or_not)){
            printf("Student with ID %lld is Admin.You Can not change it.\n",id);
            return;
        }
        else if((members[i].unique_id==id) && (!members[i].admin_or_not)){
            for(int j=i;j<(member_no-1);j++){
                members[j]=members[j+1];
            }
            member_no--;
            printf("Student with ID %lld has been removed.\n",id);
            return;
        }
    }
    printf("Student with ID %lld is not found.\n",id);
}
void add_new_book() {
    if (total_books<MAX_BOOK) {
        printf("Enter book details:\n");
        printf("Title: ");
        scanf(" %[^\n]", books[total_books].books_name);
        printf("Author: ");
        scanf(" %[^\n]", books[total_books].author_name);
        books[total_books].unique_token=total_books;
        //
         FILE *file=fopen("books.txt","a");
        fprintf(file, "%s,%s,%d\n",books[total_books].books_name,books[total_books].author_name,books[total_books].unique_token);
        fclose(file);
        //
        total_books++;
        printf("New book added successfully!\n");
    } else {
        printf("Maximum book limit reached. Cannot add more books.\n");
    }
}

//student page
void view_profile(struct Members student) {
    printf("\nProfile Details:\n");
    printf("Username: %s\n",student.username);
    printf("ID: %lld\n",student.unique_id);
    printf("Status: %s\n",student.admin_or_not?"Admin":"Student");
    printf("Borrowed Books No: %d\n",student.borrow_books);
    printf("Total book borrowed: %d\n",student.total_book_borrowed);
    printf("___________________________________\n");
    if (student.borrow_books!=0) {
        printf("You have borrowed the book:\n");
        printf("Title: %s\n",books[student.borrow_books].books_name);
        printf("Author: %s\n",books[student.borrow_books].author_name);
        printf("Unique Token: %d\n",books[student.borrow_books].unique_token);
    }
}

void available_books() {
    printf("Available Books:\n");
    if (total_books == 0) {
        printf("No books available.\n");
    } else {
        for (int i = 1; i < total_books; i++) {
            printf("Book %d:\n", i);
            printf("Title: %s\n", books[i].books_name);
            printf("Author: %s\n", books[i].author_name);
            printf("Unique Token: %d\n", books[i].unique_token);
            // Display more book-related information if needed
            printf("___________________________________\n");
        }
    }
}
void borrow_book(struct Members *student) {
    if((*student).borrow_books>=1){
        printf("You have already borrowed a book. Please return it before borrowing a new one.\n");
        return;
    }
    int book_choice;
    available_books();
    printf("Enter the number of the book you want to borrow: ");
    scanf("%d", &book_choice);
    if (book_choice>=1 && book_choice<=total_books) {
        printf("You have borrowed the book:\n");
        printf("Title: %s\n",books[book_choice].books_name);
        printf("Author: %s\n",books[book_choice].author_name);
        printf("Unique Token: %d\n",books[book_choice].unique_token);
        (*student).borrow_books=book_choice;
        (*student).total_book_borrowed++;
        saveRegisterMemberinFILE();
        printf("Book borrowed successfully!\n");
    }
    else{
        printf("Invalid book choice. Please select a valid book number.\n");
    }
}
void return_book(struct Members *student) {
    if ((*student).borrow_books==0) {
        printf("You haven't borrowed any books to return.\n");
        return;
    }
    printf("Are you sure you want to return this book? (1 for Yes, 0 for No): ");
    int choice;
    scanf("%d", &choice);
    if (choice==1) {
        printf("You Return Title: %s, Author: %s, Unique Token: %d \n",books[(*student).borrow_books].books_name,books[(*student).borrow_books].author_name,books[(*student).borrow_books].unique_token);
        (*student).borrow_books=0;
        saveRegisterMemberinFILE();
        printf("Book returned successfully!\n");
    }
    else{
        printf("Book return cancelled.\n");
    }
}