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
   int taken_books;
   bool admin_or_not;
};
//landing page
void registerMember(struct Members members[], int *member_no);
void login(struct Members members[], int *member_no);
bool is_unique(struct Members members[],long long id,int member_no);
void loadMembersFromFile(struct Members members[], int *member_no);

//admin page
void admin_page(struct Members members[], int *member_no);
void show_student_details(struct Members members[],int member_no);
void show_admin_details(struct Members members[],int member_no);
void saveRegisterMemberinFILE(struct Members members[], int member_no);
void remove_student(struct Members members[],int *member_no);
void saveBooksToFile();
void loadBooksDetailsFromFile();
void add_new_book();
//student page
void student_page(struct Members student);
void view_profile(struct Members student);
void available_books();
void borrow_book(struct Members student);
void return_book(struct Members student);


int main(){
    struct Members members[MAX_MEMBERS];
    int member_no=0;
    loadMembersFromFile(members, &member_no);
    loadBooksDetailsFromFile();
    int choice;
    do
    {
        choice=4;
        printf("Menu:\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                registerMember(members,&member_no);
                break;
            case 2:
                login(members,&member_no);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }while(choice!=4);
}

void admin_page(struct Members members[], int *member_no) {
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
                show_student_details(members, *member_no);
                break;
            case 2:
                show_admin_details(members, *member_no);
                break;
            case 3:
                remove_student(members, member_no);
                break;
            case 4:
                saveRegisterMemberinFILE(members,*member_no);
                saveBooksToFile();
                break;
            case 5:
                printf("Total member: %d\n", *member_no);
                break;
            case 6:
                add_new_book();
                break;
            case 7:
                available_books();
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
void student_page(struct Members student){
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
                view_profile(student);
                break;
            case 2:
                borrow_book(student);
                break;
            case 3:
                return_book(student);
                break;
            case 4:
                available_books();
                break;
            case 5:
                system("cls");
                printf("Logging out from student page.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while(student_choice != 5);
}


void registerMember(struct Members members[], int *member_no){
    if(*member_no<100){
        char name[100];
        printf("Enter Username: ");
        scanf(" %[^\n]", name);
        long long id;
        printf("Enter Unique id: ");
        scanf(" %lld", &id);
        if(is_unique(members,id,*member_no)){
            members[*member_no].unique_id=id;
            strcpy(members[*member_no].username,name);
            members[*member_no].admin_or_not=false;
            (*member_no)++;
            return;
        }
        else {
            printf("This ID already Exist, Please TRY AGINE\n");
            return;
        }
    }
}

void login(struct Members members[], int *member_no) {
    long long id;
    printf("Enter your Unique ID: ");
    scanf("%lld", &id);
    bool found=false;
    for(int i=0;i<*member_no;i++){
        if(members[i].unique_id==id){
            if(members[i].admin_or_not){
                found=true;

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
                        student_page(members[i]);
                        choise=3;
                        break;
                    case 3:
                        system("cls");
                        printf("3. Back in landing page\n");
                        break;
                        
                    default:
                        printf("Invalid choice. Please select a valid option.\n");
                    }

                    
                } while (choise!=3);
                break;
            }
            else{
                system("cls");
                printf("Student login successful\n");
                student_page(members[i]);
            }
            break;
        }
    }
    if(!found){
        printf("Member not found. Please register or provide a valid Unique ID.\n");
    }
}

void saveRegisterMemberinFILE(struct Members members[], int member_no) {
    FILE *file=fopen("members.txt","w");
    if(file==NULL){
        printf("ERROR opening file.\n");
        return;
    }
    for(int i=0;i<member_no;i++){
        fprintf(file, "%s,%lld,%hhd,%d,%d\n",members[i].username,members[i].unique_id,members[i].admin_or_not ? 1 : 0,members[i].borrow_books,members[i].taken_books);
    }
    fclose(file);
    printf("Member information saved to members.txt\n");
}
void saveBooksToFile() {
    FILE *file=fopen("books.txt","w");
    if (file==NULL) {
        printf("ERROR opening book file for writing.\n");
        return;
    }
    for (int i=0;i<total_books;i++) {
        fprintf(file, "%s,%s,%d\n",books[i].books_name,books[i].author_name,books[i].unique_token);
    }

    fclose(file);
    printf("Book information saved to books.txt\n");
}


void loadMembersFromFile(struct Members members[],int *member_no) {
    FILE *file=fopen("members.txt", "r");
    if (file==NULL){
        printf("ERROR opening file for reading.\n");
        return;
    }
    *member_no=0;
    while (*member_no<MAX_MEMBERS && fscanf(file, " %[^,],%lld,%hhd,%d,%d\n",members[*member_no].username,&members[*member_no].unique_id,&members[*member_no].admin_or_not,&members[*member_no].borrow_books,&members[*member_no].taken_books) == 5){
        if (is_unique(members,members[*member_no].unique_id,*member_no)&& (members[*member_no].borrow_books==1 || members[*member_no].borrow_books==0)){
            (*member_no)++;
        }
        else{
            printf("Non-unique ID found in file. Skipping entry.\n");
        }
    }
    fclose(file);
    printf("information loaded...\n");
}
void loadBooksDetailsFromFile(){
    FILE *file=fopen("books.txt","r");
    if (file==NULL){
        printf("ERROR opening book file for reading.\n");
        return;
    }

    total_books=0;
    while (total_books<MAX_BOOK && fscanf(file, " %[^,],%[^,],%d\n",books[total_books].books_name,books[total_books].author_name,&books[total_books].unique_token)==3){
        total_books++;
    }

    fclose(file);
    printf("Book information loaded...\n");
}




bool is_unique(struct Members members[],long long id,int member_no){
    for (int i = 0; i < member_no; i++)
    {
        if(members[i].unique_id==id) return false;
    }
    return true;
    
}

//login page 

void show_student_details(struct Members members[],int member_no){
    FILE *file=fopen("student_details.txt", "w");
    if(file==NULL){
        printf("ERROR opening file.\n");
        return;
    }
    for(int i=0;i<member_no;i++){
        if (!members[i].admin_or_not){
            fprintf(file, "Username: %s\nID: %lld\nStatus: Student\nBorrowed Books: %d\nTaken Books: %d\n\n\n",members[i].username,members[i].unique_id,members[i].borrow_books,members[i].taken_books);
            printf("Username: %s\nID: %lld\nStatus: Student\nBorrowed Books: %d\nTaken Books: %d\n",members[i].username,members[i].unique_id,members[i].borrow_books,members[i].taken_books);
            printf("____________________________________________________________________________\n\n");
        }
    }
    fclose(file);
    printf("Student information saved to student_details.txt\n");
}
void show_admin_details(struct Members members[],int member_no) {
    FILE *file=fopen("admin_details.txt", "w");
    if(file==NULL){
        printf("ERROR opening file.\n");
        return;
    }
    for (int i=0;i<member_no;i++) {
        if (members[i].admin_or_not) {
            fprintf(file, "Username: %s\nID: %lld\nStatus: Admin\nBorrowed Books: %d\nTaken Books: %d\n\n\n",members[i].username,members[i].unique_id,members[i].borrow_books,members[i].taken_books);
            printf("Username: %s\nID: %lld\nStatus: Student\nBorrowed Books: %d\nTaken Books: %d\n",members[i].username,members[i].unique_id,members[i].borrow_books,members[i].taken_books);
            printf("____________________________________________________________________________\n\n");

        }
    }
    fclose(file);
    printf("Admin information saved to admin_detaile.txt\n");
}
void remove_student(struct Members members[],int *member_no){
    long long id;
    printf("Enter the Unique ID of the student to remove: ");
    scanf(" %lld", &id);
    for(int i=0;i<*member_no;i++){
        if((members[i].unique_id==id) && (members[i].admin_or_not)){
            printf("Student with ID %lld is Admin.You Can not change it.\n",id);
            return;
        }
        else if((members[i].unique_id==id) && (!members[i].admin_or_not)){
            for(int j=i;j<(*member_no-1);j++){
                members[j]=members[j+1];
            }
            (*member_no)--;
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
        books[total_books].unique_token=total_books+1;
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
    printf("Borrowed Books: %d\n",student.borrow_books);
    printf("Taken Books: %d\n",student.taken_books);
}

void available_books() {
    printf("Available Books:\n");
    if (total_books == 0) {
        printf("No books available.\n");
    } else {
        for (int i = 0; i < total_books; i++) {
            printf("Book %d:\n", i + 1);
            printf("Title: %s\n", books[i].books_name);
            printf("Author: %s\n", books[i].author_name);
            printf("Unique Token: %d\n", books[i].unique_token);
            // Display more book-related information if needed
            printf("___________________________________\n");
        }
    }
}
void borrow_book(struct Members student) {
    if(student.borrow_books>=1){
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
        student.borrow_books++;
        student.taken_books++;
        printf("Book borrowed successfully!\n");
    }
    else{
        printf("Invalid book choice. Please select a valid book number.\n");
    }
}

void return_book(struct Members student) {
    if(student.borrow_books==0){
        printf("You haven't borrowed any books to return.\n");
        return;
    }
    printf("You have borrowed the following book:\n");
    printf("Title: %s\n", books[student.taken_books].books_name);
    printf("Author: %s\n", books[student.taken_books].author_name);
    printf("Unique Token: %d\n", books[student.taken_books].unique_token);
    student.borrow_books--;
    printf("Book returned successfully!\n");
}
