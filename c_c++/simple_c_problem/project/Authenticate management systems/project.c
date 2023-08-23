#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_BOOK 100
#define MAX_MEMBERS 100
struct Students
{
    
};


struct Members
{
   char username[100];
   long long unique_id;
   bool admin_or_not;
};
//landing page
void registerMember(struct Members members[], int *member_no);
void login(struct Members members[], int *member_no);
bool is_unique(struct Members members[],long long id,int member_no);
void loadMembersFromFile(struct Members members[], int *member_no);

//login page
void admin_page(struct Members members[], int *member_no);
void show_student_details(struct Members members[],int member_no);
void show_admin_details(struct Members members[],int member_no);
void saveRegisterMemberinFILE(struct Members members[], int member_no);
void remove_student(struct Members members[],int *member_no);
//student page
void student_page(struct Members student);

int main(){
    struct Members members[MAX_MEMBERS];
    int member_no=0;
    loadMembersFromFile(members, &member_no);
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
        admin_choice=6;
        printf("Admin Page:\n");
        printf("1. Show Student Details\n");
        printf("2. Show Admin Details\n");
        printf("3. Remove Student\n");
        printf("4. save in file\n");
        printf("5. total members\n");
        printf("6. LOGOUT\n");
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
                break;
            case 5:
                printf("Total member: %d\n", *member_no);
                break;
            case 6:
                system("cls");
                printf("Logging out from admin page.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while(admin_choice!=6);
}
void student_page(struct Members student) {
    int student_choice;
    do {
        student_choice=6;
        printf("\nStudent Page:\n");
        printf("1. View Profile\n");
        printf("2. Change Password\n");
        printf("3. View Available Resources\n");
        printf("4. Contact Support\n");
        printf("5. View Announcements\n");
        printf("6. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &student_choice);

        switch(student_choice) {
            case 1:
                // Implement code to view student profile
                break;
            case 2:
                // Implement code to change student password
                break;
            case 3:
                // Implement code to view available resources
                break;
            case 4:
                // Implement code to contact support
                break;
            case 5:
                // Implement code to view announcements
                break;
            case 6:
                system("cls");
                printf("Logging out from student page.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while(student_choice != 6);
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
    FILE *file=fopen("members.txt", "w");
    if(file==NULL){
        printf("ERROR opening file.\n");
        return;
    }
    for(int i=0;i<member_no;i++){
        fprintf(file, "%s,%lld,%hhd\n",members[i].username,members[i].unique_id,members[i].admin_or_not ? 1 : 0);
    }
    fclose(file);
    printf("Member information saved to members.txt\n");
    show_student_details(members, member_no);
    show_admin_details(members, member_no);
}

void loadMembersFromFile(struct Members members[],int *member_no) {
    FILE *file=fopen("members.txt", "r");
    if (file==NULL){
        printf("ERROR opening file for reading.\n");
        return;
    }
    *member_no=0;
    while (*member_no < MAX_MEMBERS && fscanf(file, " %[^,],%lld,%d\n",
          members[*member_no].username,&members[*member_no].unique_id,&members[*member_no].admin_or_not)==3){
        if (is_unique(members,members[*member_no].unique_id,*member_no)){
            (*member_no)++;
        } else {
            printf("Non-unique ID found in file. Skipping entry.\n");
        }
    }
    fclose(file);
    printf("information loaded...\n");
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
                fprintf(file, "Username: %s\nID: %lld\nStatus: %s\n",members[i].username,members[i].unique_id,members[i].admin_or_not ? "Admin" : "Student");
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
            fprintf(file, "Username: %s\nID: %lld\nStatus: %s\n",members[i].username,members[i].unique_id,members[i].admin_or_not ? "Admin" : "Student");
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
            printf("Student with ID %lld is Admin.You Can not change it.\n", id);
            return;
        }
        else if((members[i].unique_id==id) && (!members[i].admin_or_not)){
            for(int j=i;j<(*member_no-1);j++){
                members[j]=members[j+1];
            }
            (*member_no)--;
            printf("Student with ID %lld has been removed.\n", id);
            return;
        }
    }
    printf("Student with ID %lld is not found.\n", id);
}

