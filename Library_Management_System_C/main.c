#include <stdio.h>
#include <string.h>
#define MAX_STR 50

struct Book
{
    int id;
    char title[MAX_STR];
    char author[MAX_STR];
    int isAvailable;
};
int main()
{
    struct Book b1;
    printf("--------------------Menu-------------------\n");
    printf("1. Add New Book\n2. View All Books\n3. Search Book (By ID or Title)\n4. Issue a Book\n5. Return a Book\n6. Exit\n");
    int choice;
    printf("Enter you choice(1-6) - ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        FILE *ptr = fopen("Books.txt", "a");
        int count;
        printf("Enter the number of books you want to enter: ");
        scanf("%d", &count);
        for (int i = 0; i < count; i++)
        {
            printf("Enter book id: ");
            scanf("%d", &b1.id);
            printf("Enter book title: ");
            scanf(" %[^\n]", b1.title);
            printf("Enter author name: ");
            scanf(" %[^\n]", b1.author);
            printf("How many books are there in stock: ");
            scanf(" %d", b1.isAvailable);
            fprintf(ptr, "%d    %s    %s    %d\n", b1.id, b1.title, b1.author, b1.isAvailable);
            printf("Record added successfully!\n");
        }
        fclose(ptr);
        break;
    case 2:
        FILE *ptv = fopen("Books.txt", "r");
        int Book_id;
        int avalable;
        char Book_title[MAX_STR];
        char Book_author[MAX_STR];
        printf("---------Records---------\n");
        while (fscanf(ptv, "%d %s %s %d", &Book_id, Book_title, Book_author, &avalable) != EOF)
        {
            printf("Book id: %d\n", Book_id);
            printf("Book title: %s\n", Book_title);
            printf("Book author: %s\n", Book_author);
            printf("Book avalable: %d\n", avalable);
            printf("\n");
        }
        fclose(ptv);
        break;
    case 3:
        char a[10];
        printf("Enter the basis on which you want to search\n1. id\n2. title\nEnter here - ");
        scanf(" %[^\n]", a);
        if (strcmp(a, "id") == 0)
        {
            FILE *pts = fopen("Books.txt", "r");
            int book_id;
            int inp;
            int Avalable;
            char book_title[MAX_STR];
            char book_author[MAX_STR];
            int found = 0;
            printf("Enter book id - ");
            scanf("%d", &inp);
            while (fscanf(pts, "%d %s %s %d", &book_id, book_title, book_author, &Avalable) != EOF)
            {
                if (inp == book_id)
                {
                    printf("Record found!\n");
                    printf("\n");
                    printf("Book id - %d\n", book_id);
                    printf("Book title - %s\n", book_title);
                    printf("Book author - %s\n", book_author);
                    printf("Book avalable - %d\n", Avalable);
                    found = 1;
                }
            }
            if (found == 0)
            {
                printf("No record found!");
            }
            fclose(pts);
        }
        else if (strcmp(a, "title") == 0)
        {
            FILE *pts = fopen("Books.txt", "r");
            int book_id;
            char inp[MAX_STR];
            int Avalable;
            char book_title[MAX_STR];
            char book_author[MAX_STR];
            int found = 0;
            printf("Enter book title - ");
            scanf(" %[^\n]", inp);
            while (fscanf(pts, "%d %s %s %d", &book_id, book_title, book_author, &Avalable) != EOF)
            {
                if (strcmp(inp, book_title) == 0)
                {
                    printf("Record found!\n");
                    printf("\n");
                    printf("Book id - %d\n", book_id);
                    printf("Book title - %s\n", book_title);
                    printf("Book author - %s\n", book_author);
                    printf("Book avalable - %d\n", Avalable);
                    found = 1;
                }
            }
            if (found == 0)
            {
                printf("No record found!");
            }
            fclose(pts);
        }
        break;
    case 4:
        FILE *ptb = fopen("Issued.txt", "a");
        FILE *ptc = fopen("Books.txt", "r");
        FILE *pte = fopen("temp.txt", "w");
        int found = 0;
        int b_id;
        char b_name[MAX_STR];
        char b_auname[MAX_STR];
        int b_isavalable;
        int x;
        char name[MAX_STR];
        printf("Enter the Book id - ");
        scanf("%d", &x);
        printf("Enter the name of issued person - ");
        scanf(" %[^\n]", name);
        while (fscanf(ptc, "%d %s %s %d", &b_id, b_name, b_auname, &b_isavalable) != EOF)
        {
            if (x == b_id && b_isavalable != 0)
            {
                found = 1;
                fprintf(ptb, "%d    %s    %s    %s\n", b_id, b_name, b_auname, name);
                fprintf(pte, "%d    %s    %s    %d\n", b_id, b_name, b_auname, b_isavalable - 1);
            }
            else if (b_isavalable == 0)
            {
                printf("Book out of stock!");
            }
            else
            {
                fprintf(pte, "%d    %s    %s    %d\n", b_id, b_name, b_auname, b_isavalable);
            }
        }
        if (found == 1)
        {
            printf("Issued successfully");
        }
        else
        {
            printf("Match not found");
        }
        fclose(ptb);
        fclose(ptc);
        fclose(pte);
        remove("Books.txt");
        rename("temp.txt", "Books.txt");
        break;
    case 5:
        FILE *pth = fopen("Issued.txt", "r");
        FILE *pto = fopen("temp1.txt", "w");
        FILE *ptk = fopen("Books.txt", "r");
        FILE *ptm = fopen("temp2.txt", "w");
        int Found = 0;
        int B_id;
        char C_name[MAX_STR];
        char B_name[MAX_STR];
        char B_auname[MAX_STR];
        int X;
        char Name[MAX_STR];
        printf("Enter the Book id - ");
        scanf("%d", &X);
        printf("Enter the name of issued person - ");
        scanf(" %[^\n]", Name);
        while (fscanf(pth, "%d %s %s %s", &B_id, B_name, B_auname, C_name) != EOF)
        {
            if (X == B_id && strcmp(Name, C_name) == 0)
            {
                Found = 1;
            }
            else
            {
                fprintf(pto, "%d    %s    %s    %s\n", B_id, B_name, B_auname, C_name);
            }
        }
        if (Found == 1)
        {
            printf("Returned successfully");
        }
        else
        {
            printf("No such book was issued!");
        }
        int B_isavalable1;
        int B_id1;
        char B_name1[MAX_STR];
        char B_auname1[MAX_STR];
        while (fscanf(ptk, "%d %s %s %d", &B_id1, B_name1, B_auname1, &B_isavalable1) != EOF)
        {
            if (X == B_id1)
            {
                fprintf(ptm, "%d    %s    %s    %d\n", B_id1, B_name1, B_auname1, B_isavalable1 + 1);
            }
            else
            {
                fprintf(ptm, "%d    %s    %s    %d\n", B_id1, B_name1, B_auname1, B_isavalable1);
            }
        }
        fclose(pth);
        fclose(pto);
        fclose(ptk);
        fclose(ptm);
        remove("Issued.txt");
        rename("temp1.txt", "Issued.txt");
        remove("Books.txt");
        rename("temp2.txt", "Books.txt");
        break;
    case 6:
        printf("Come Again!");
        return 0;
        break;
    default:
        printf("Please give a valid input (1-6)");
        break;
    }
    return 0;
}