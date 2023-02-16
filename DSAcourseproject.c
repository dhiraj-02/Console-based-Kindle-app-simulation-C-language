#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.c"



int main()
{
    welcome();

    load_from_file();

    load_users();

    load_login();
    printf("------FUNCTIONS PROVIDED IN THE PROGRAM------\n\n");

    printf("1.SORT THE BOOKS\n   A.BY TITLE ASC\n   B.BY RATING\n   C.PRICE HIGH_TO_LOW\n   D.PRICE LOW_TO_HIGH\n\n");

    printf("2.SEARCH A BOOK\n   A.BY NAME\n   B.BY GENRE\n\n");

    printf("3.TO LOAD USER INTERFACE\n\n\n\n");

    printf("PRE-REQUISITES TO RUN PROGRAM SUCCESSFULLY\n1.BOOK INFO\n2.USER INFO\n3.LOGIN DETAILS\n\n");

    printf("-----------------BOOK DETAILS-------------\n\n");

    printf("TITLE GENRE AUTHOR DOP RATING PRICE NO.OF_PAGES\n\n");


    for(int i=0 ; i<global_count-1 ; i++)
    {
        printf("%s  %s  %s  %s  %d  %d  %d\n",search_list[i].title, search_list[i].genre, search_list[i].author,search_list[i].dop, search_list[i].rating,search_list[i].price,search_list[i].nop);
    }

     printf("\n\n");

      printf("-----------------USER DETAILS-------------\n\n");
       printf("NAME USER_ID CITY SUB_STATUS(1-SUB,0-NOT SUB) NO.OF_BOOKS_READ BOOK_NAMES_PURCHASED_BY_USER\n\n");

     for(int j=0 ; j<user_count-1 ; j++)
     {
         printf("%s  %s  %s %d %d ",user[j].name,user[j].userid,user[j].city,user[j].subscription_status,user[j].no_of_books_read);
         for(int k=0 ; k<user[j].no_of_books_read;k++)
         {
             printf("%s ",user[j].books_read[k].read);
         }
         printf("\n");
     }

     printf("\n\n");

     printf("-----------------LOGIN CREDENTIALS-------------\n\n");
     printf("USER_ID  PASSWORD\n\n");

     for( int k=0 ; k< login_count-1 ; k++)
     {
         printf("ID : %s      PW : %s\n",login_list[k].username,login_list[k].password);
     }
printf("\n\n");
     int choice;
     {
         int a;
         char book[30],id[10],pw[10];
         char genre_search[30];
         while(1)
         {
            printf("MAIN MENU :\n1.TO SORT THE BOOKS\n2.TO SEARCH A BOOK\n3.TO LOAD USER INTERFACE\n4.EXIT\n\nENTER YOUR CHOICE\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1: printf("1.SORT BY BOOK TITLE IN ALPHABETICAL ORDER\n2.SORT BY RATING\n3.SORT BY PRICE HIGH TO LOW\n4.SORT BY PRICE LOW TO HIGH\n\n");
                        scanf("%d",&a);
                        switch(a)
                        {
                            case 1: sort_by_title();
                                    break;
                            case 2: sort_by_rating();
                                    break;
                            case 3: sort_by_priceHL();
                                    break;
                            case 4: sort_by_priceLH();
                                    break;
                            default:printf("INVALID INPUT!!\n\n");
                        }
                        break;

                 case 2: printf("1.TO SEARCH BY BOOK NAME\n2.TO SEARCH BY GENRE \n");
                         scanf("%d",&a);
                         switch(a)
                         {
                             case 1:printf("ENTER THE BOOK NAME\n");
                                    getchar();
                                    gets(book);

                                    for(int l=0;l<strlen(book);l++)
                                    {
                                        if(book[l]==' ')
                                        {
                                            book[l]='-';
                                        }
                                    }
                                    string_search(book);
                                    break;

                             case 2:printf("ENTER THE GENRE YOU WISH TO SEARCH:\n");
                                    getchar();
                                    gets(genre_search);
                                    printf("\n\n");
                                    printf("RATING  BOOK_NAME  AUTHOR\n\n");
                                    for(int l=0;l<strlen(genre_search);l++)
                                    {
                                        if(genre_search[l]==' ')
                                        {
                                            genre_search[l]='-';
                                        }
                                    }
                                    string_search_rec(genre_search);
                                    break;
                         }
                         break;

                  case 3:printf("ENTER THE USER ID :\n");
                         getchar();
                         gets(id);
                         int c=100;
                         for(int i=0 ; i<login_count;i++)
                         {
                             if(strcmp(id,login_list[i].username)==0)
                                c=i;
                         }
                         if(c==100)
                         {
                             printf("USER CANNOT BE FOUND\nRETURNING TO MAIN MENU\n\n");
                             break;
                         }

                         int m=0;
                         printf("\n\n");

                         printf("YOU WILL BE HAVING 3 CHANCES TO PUT THE CORRECT PASSWORD");
                         while(m<3)
                         {
                              printf("ENTER THE PASSWORD : \n");
                          gets(pw);
                          if(strcmp(pw,login_list[c].password)==0)
                          {
                               user_interface(id);
                              m=4;

                          }
                          else
                          {
                            printf("PASSWORD DID NOT MATCH TRY AGAIN!!!!\n");
                            m++;
                          }

                         }
                         if(m==3);
                         printf("INVALID USER ID OR PASSWORD\n\n");

                         break;


                  default: printf("INVALID INPUT!!\n\n");
                           exit(0);
           }
        }
     }
    return 0;
}



