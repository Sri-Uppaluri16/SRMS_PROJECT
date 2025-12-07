#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100   // stack limit

// ---------- GLOBAL STACK ----------
typedef struct {
    int roll;
    char name[50];
    float mark;
} Student;

Student stack[MAX];
int top = -1;   // stack empty

// ---------- LOGIN SYSTEM ----------
char currentUser[50];
char currentRole[20];

int login() {
    char u[50], p[50];

    printf("USERNAME: ");
    scanf("%s", u);
    printf("PASSWORD: ");
    scanf("%s", p);

    // HARD-CODED SAMPLE USERS
    if (strcmp(u,"admin")==0 && strcmp(p,"123")==0) {
        strcpy(currentUser, u);
        strcpy(currentRole, "admin");
        return 1;
    }
    if (strcmp(u,"staff")==0 && strcmp(p,"123")==0) {
        strcpy(currentUser, u);
        strcpy(currentRole, "staff");
        return 1;
    }
    if (strcmp(u,"user")==0 && strcmp(p,"123")==0) {
        strcpy(currentUser, u);
        strcpy(currentRole, "user");
        return 1;
    }
    if (strcmp(u,"guest")==0 && strcmp(p,"123")==0) {
        strcpy(currentUser, u);
        strcpy(currentRole, "guest");
        return 1;
    }

    return 0;
}

// ---------- STACK OPERATIONS ----------
void pushStudent() {
    if (top == MAX - 1) {
        printf("Stack full! Cannot add student.\n");
        return;
    }

    Student s;
    printf("Roll: ");
    scanf("%d", &s.roll);
    printf("Name: ");
    scanf(" %[^\n]", s.name);
    printf("Mark: ");
    scanf("%f", &s.mark);

    top++;
    stack[top] = s;

    printf("Student pushed to stack!\n");
}

void popStudent() {
    if (top == -1) {
        printf("Stack empty! Nothing to delete.\n");
        return;
    }

    printf("Popped Student: %d %s %.2f\n",
            stack[top].roll,
            stack[top].name,
            stack[top].mark);

    top--;
}

// ---------- DISPLAY STACK ----------
void displayStudents() {
    if (top == -1) {
        printf("No students in stack.\n");
        return;
    }

    printf("\nRoll\tName\tMark\n");
    printf("----------------------------\n");

    for (int i = 0; i <= top; i++) {
        printf("%d\t%s\t%.2f\n",
               stack[i].roll,
               stack[i].name,
               stack[i].mark);
    }
}

// ---------- SEARCH STACK ----------
void searchStudent() {
    int find;
    printf("Enter roll to search: ");
    scanf("%d", &find);

    for (int i = 0; i <= top; i++) {
        if (stack[i].roll == find) {
            printf("Found: %d %s %.2f\n",
                   stack[i].roll,
                   stack[i].name,
                   stack[i].mark);
            return;
        }
    }
    printf("Student not found!\n");
}

// ---------- UPDATE STACK ----------
void updateStudent() {
    int find;
    printf("Enter roll to update: ");
    scanf("%d", &find);

    for (int i = 0; i <= top; i++) {
        if (stack[i].roll == find) {
            printf("New Name: ");
            scanf(" %[^\n]", stack[i].name);
            printf("New Mark: ");
            scanf("%f", &stack[i].mark);

            printf("Student updated!\n");
            return;
        }
    }
    printf("Roll not found!\n");
}

// ---------- MENUS ----------
void adminMenu() {
    int c;
    while (1) {
        printf("\nADMIN MENU\n");
        printf("1.Push(Add)\n2.Display\n3.Search\n4.Update\n5.Pop(Delete)\n6.Logout\n");
        scanf("%d",&c);

        if (c==1) pushStudent();
        else if (c==2) displayStudents();
        else if (c==3) searchStudent();
        else if (c==4) updateStudent();
        else if (c==5) popStudent();
        else return;
    }
}

void staffMenu() {
    int c;
    while (1) {
        printf("\nSTAFF MENU\n");
        printf("1.Push(Add)\n2.Display\n3.Search\n4.Update\n5.Logout\n");
        scanf("%d",&c);

        if (c==1) pushStudent();
        else if (c==2) displayStudents();
        else if (c==3) searchStudent();
        else if (c==4) updateStudent();
        else return;
    }
}

void userMenu() {
    int c;
    while (1) {
        printf("\nUSER MENU\n");
        printf("1.Display\n2.Search\n3.Logout\n");
        scanf("%d",&c);

        if (c==1) displayStudents();
        else if (c==2) searchStudent();
        else return;
    }
}

void guestMenu() {
    int c;
    while (1) {
        printf("\nGUEST MENU\n");
        printf("1.Display\n2.Logout\n");
        scanf("%d",&c);

        if (c==1) displayStudents();
        else return;
    }
}

// ---------- MAIN ----------
int main() {
    if (!login()) {
        printf("Invalid login!\n");
        return 0;
    }

    printf("Logged in as: %s\n", currentRole);

    if (strcmp(currentRole,"admin")==0) adminMenu();
    else if (strcmp(currentRole,"staff")==0) staffMenu();
    else if (strcmp(currentRole,"user")==0) userMenu();
    else guestMenu();

    return 0;
}
