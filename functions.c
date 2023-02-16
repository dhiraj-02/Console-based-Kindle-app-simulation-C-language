typedef struct login_Details
{
    char username[30];
    char password[30];

}LD;


LD login_list[100];


int login_count=0;


typedef struct read_books
{
    char read[30];
}RB;


typedef struct user_details
{
   char name[20];
   char userid[10];
   char city[10];
   int subscription_status;
   int no_of_books_read;
   RB books_read[30];
}USER;



typedef struct books_details
{
    char title[30];
    char genre[30];
    char author[30];
    char dop[15];
    int rating;
    int price;
    int nop;
}BD;
//nop=number of pages



typedef struct suggestions
{
    char sug[30];
}R;



typedef struct recommendations
{
    char title[30];
    char author[30];
    char genre[30];
    int rating;
}REC;



void welcome();

void load_from_file();

void load_users();

void load_login();

void sort_by_priceLH();

void sort_by_priceHL();

void sort_by_rating();

void sort_by_title();

void string_search(char book[30]);

void string_search_rec(char genre_search[30]); //recommendations based on genre

void bubble_sort_rec(REC s[200], int n); //recommendations sorted based on rating(high to low)

void string_search(char[]);

void user_interface(char a[10]);

void purchase_book(char a[30],int b);

void subscription(char a[30],int b);




void load_login()
{
    FILE *fp;

     /// Open the file in read mode

    fp = fopen("login.txt", "r");

    /// Check if the file was successfully opened

    if (fp == NULL)
    {
        printf("FILE NOT FOUND\n\n");
        return;
    }

    /// Until the end of the file, read all the file data

    while(!feof(fp))
    {
        fscanf(fp,"%s%s",login_list[login_count].username, login_list[login_count].password);
        login_count++;
    }

    fclose(fp);

    printf("LOGIN DETAILS LOAD SUCCESS !!!\n\n");
}


int global_count = 0;

int user_count=0;

BD search_list[200];

USER user[50];
/**
Function Name: welcome
Input Params: NILL
Return Type: void
Description: Prints a welcome message
**/

void welcome()
{
    int  i = 0;

    for(i=0;i<80;i++)
        printf("*");

    printf("\n\n\t\t\t\tAMAZON KINDLE\n\n\n");

    for(i=0;i<80;i++)
        printf("*");

    printf("\n\n");
}

/**
Function Name: load_from_file
Input Parameters: NILL
Return Type: void
Description: loads all the data available with recommendation engine into appropriate data structure
**/

void load_users()
{
   FILE *fp;

    fp=fopen("Kindleusers.txt","r");

    if(fp==NULL)
       {
          printf("FILE NOT FOUND\n\n");
            return;
       }

    while(!feof(fp))
    {
        fscanf(fp,"%s%s%s%d%d",user[user_count].name,user[user_count].userid,user[user_count].city,&user[user_count].subscription_status,&user[user_count].no_of_books_read);

        for(int i=0 ; i<user[user_count].no_of_books_read ; i++)
        {
            fscanf(fp,"%s",user[user_count].books_read[i].read);
        }
        user_count++;
    }

    fclose(fp);

    printf("USERS LOADED!!!!\n\n");
}


void load_from_file()
{
    FILE *fp;

    /// Open the file in read mode

    fp = fopen("Kindle.txt", "r");

    /// Check if the file was successfully opened

    if (fp == NULL)
    {
        printf("FILE NOT FOUND\n\n");
        return;
    }

    /// Until the end of the file, read all the file data

    while(!feof(fp))
    {
        fscanf(fp,"%s%s%s%s%d%d%d",search_list[global_count].title, search_list[global_count].genre,search_list[global_count].author,search_list[global_count].dop,&search_list[global_count].rating,&search_list[global_count].price,&search_list[global_count].nop);
        global_count++;
    }

    fclose(fp);

    printf("LOAD SUCCESS !!!\n\n");
}


/**
Function Name: sort_by_priceLH
Input Parameters: NILL
Return Type: void
Description: Sorts the books based on price(in ascending order)
**/

void sort_by_priceLH()
{
    BD s[200];

    memcpy(&s,&search_list,sizeof(search_list));

    char swap1[30];

    int swap2;

     for(int i=0;i<global_count-1;i++)
    {
        for(int j=0;j<global_count-i-1;j++)
        {
            if(s[j].price>s[j+1].price)
            {
                strcpy(swap1,s[j].title);
                strcpy(s[j].title,s[j+1].title);
                strcpy(s[j+1].title,swap1);
                strcpy(swap1,s[j].genre);
                strcpy(s[j].genre,s[j+1].genre);
                strcpy(s[j+1].genre,swap1);
                strcpy(swap1,s[j].author);
                strcpy(s[j].author,s[j+1].author);
                strcpy(s[j+1].author,swap1);
                strcpy(swap1,s[j].dop);
                strcpy(s[j].dop,s[j+1].dop);
                strcpy(s[j+1].dop,swap1);
                swap2=s[j].rating;
                s[j].rating=s[j+1].rating;
                s[j+1].rating=swap2;
                 swap2=s[j].price;
                s[j].price=s[j+1].price;
                s[j+1].price=swap2;
                 swap2=s[j].nop;
                s[j].nop=s[j+1].nop;
                s[j+1].nop=swap2;
            }
        }
    }

    printf("BOOK_NAME  PRICE\n\n");

    for(int i=1 ; i<global_count ; i++)
    {
        printf("%s %d\n",s[i].title,s[i].price);
    }

     printf("\n\n");
}


/**
Function Name: sort_by_priceHL
Input Parameters: NILL
Return Type: void
Description: Sorts the books based on price(in descending order)
**/

void sort_by_priceHL()
{
    BD s[200];

    memcpy(&s,&search_list,sizeof(search_list));

    char swap1[30];

    int swap2;

     for(int i=0;i<global_count-1;i++)
    {
        for(int j=0;j<global_count-i-1;j++)
        {
            if(s[j].price<s[j+1].price)
            {
                strcpy(swap1,s[j].title);
                strcpy(s[j].title,s[j+1].title);
                strcpy(s[j+1].title,swap1);
                strcpy(swap1,s[j].genre);
                strcpy(s[j].genre,s[j+1].genre);
                strcpy(s[j+1].genre,swap1);
                strcpy(swap1,s[j].author);
                strcpy(s[j].author,s[j+1].author);
                strcpy(s[j+1].author,swap1);
                strcpy(swap1,s[j].dop);
                strcpy(s[j].dop,s[j+1].dop);
                strcpy(s[j+1].dop,swap1);
                swap2=s[j].rating;
                s[j].rating=s[j+1].rating;
                s[j+1].rating=swap2;
                 swap2=s[j].price;
                s[j].price=s[j+1].price;
                s[j+1].price=swap2;
                 swap2=s[j].nop;
                s[j].nop=s[j+1].nop;
                s[j+1].nop=swap2;
            }
        }
    }

     printf("BOOK_NAME  PRICE\n\n");

    for(int i=0 ; i<global_count-1 ; i++)
    {
        printf("%s %d\n",s[i].title,s[i].price);
    }

     printf("\n\n");
}


/**
Function Name: sort_by_rating
Input Parameters: NILL
Return Type: void
Description: Sorts the books based on it's rating
**/

void sort_by_rating()
{
    BD s[200];

    memcpy(&s,&search_list,sizeof(search_list));

    char swap1[30];

    int swap2;

     for(int i=0;i<global_count-1;i++)
    {

        for(int j=0;j<global_count-i-1;j++)

        {

            if(s[j].rating<s[j+1].rating)
            {
                strcpy(swap1,s[j].title);
                strcpy(s[j].title,s[j+1].title);
                strcpy(s[j+1].title,swap1);

                strcpy(swap1,s[j].genre);
                strcpy(s[j].genre,s[j+1].genre);
                strcpy(s[j+1].genre,swap1);

                strcpy(swap1,s[j].author);
                strcpy(s[j].author,s[j+1].author);
                strcpy(s[j+1].author,swap1);

                strcpy(swap1,s[j].dop);
                strcpy(s[j].dop,s[j+1].dop);
                strcpy(s[j+1].dop,swap1);

                swap2=s[j].rating;
                s[j].rating=s[j+1].rating;
                s[j+1].rating=swap2;

                 swap2=s[j].price;
                s[j].price=s[j+1].price;
                s[j+1].price=swap2;

                 swap2=s[j].nop;
                s[j].nop=s[j+1].nop;
                s[j+1].nop=swap2;
            }
        }
    }

    printf("RATING  BOOK_NAME\n\n");

    for(int i=0 ; i<global_count-1 ; i++)
    {
        printf("%d %s\n",s[i].rating,s[i].title);
    }

     printf("\n\n");
}


/**
Function Name: sort_by_title
Input Parameters: NILL
Return Type: void
Description: Sorts the books based on the title
**/

void sort_by_title()
{
    BD s[200];

    memcpy(&s,&search_list,sizeof(search_list));

    char swap1[30];

    int swap2;

     for(int i=0;i<global_count-1;i++)
     {
        for(int j=0;j<global_count-i-1;j++)
        {
            if(strcmp(s[j].title,s[j+1].title)>0)
            {
                strcpy(swap1,s[j].title);
                strcpy(s[j].title,s[j+1].title);
                strcpy(s[j+1].title,swap1);

                strcpy(swap1,s[j].genre);
                strcpy(s[j].genre,s[j+1].genre);
                strcpy(s[j+1].genre,swap1);

                strcpy(swap1,s[j].author);
                strcpy(s[j].author,s[j+1].author);
                strcpy(s[j+1].author,swap1);

                strcpy(swap1,s[j].dop);
                strcpy(s[j].dop,s[j+1].dop);
                strcpy(s[j+1].dop,swap1);

                swap2=s[j].rating;
                s[j].rating=s[j+1].rating;
                s[j+1].rating=swap2;

                 swap2=s[j].price;
                s[j].price=s[j+1].price;
                s[j+1].price=swap2;
                 swap2=s[j].nop;
                s[j].nop=s[j+1].nop;
                s[j+1].nop=swap2;
            }
        }
    }

    for(int i=1 ; i<global_count-1 ; i++)
    {
        printf("%s %d\n",s[i].title,s[i].rating);
    }

    printf("\n\n");

}

/**
Function Name: string_search
Input Parameters: string
Return Type: void
Description: Displays the suggested book/s depending upon the user query.
**/

void string_search(char book[30])
{
    R s[1000];

    int i,j,k,y,z=0;

    int n,m;

    m=strlen(book);

    for(i=0;i<global_count;i++)
    {
        n=strlen(search_list[i].title);

        for (j=0;j<=n-m;j++)
        {
          k=0;
          while(k<m && book[k] == search_list[i].title[j+k])
          {
              k=k+1;
          }
          if(k==m)
          {

              int flag=0;
              for(y=0;y<=z;y++)
              {
                  if(strcmp(s[y].sug,search_list[i].title)==0)
                    flag=1;
              }
              if(flag==1)
                continue;
              if(flag==0)
                    strcpy(s[z].sug,search_list[i].title);
              z++;
          }

        }
    }
    if(z==0)
        printf("NO SUGGESTIONS.\n");

    else
        {
             int x;
             printf(" SEARCH RESULTS :");
              printf("\n-----------------\n");
              printf("\nBOOK NAMES\n\n");
          for(x=0;x<z;x++)
      {
        for(int l=0;l<strlen(s[x].sug);l++)
        {
            if(s[x].sug[l]=='-')
            {
                s[x].sug[l]=' ';
            }
        }

        printf("%s\n\n",strupr(s[x].sug));

    }
        }
        printf("\n\n");
}

/**
Function Name: Brute force string search for recommendations
Input Parameters: string
Return Type: void
Description: Searches the string
**/


void string_search_rec(char genre_search[30])
{

    REC s[200];

    //char temp_genre[30];

    int i, j, k;

    int n, m, z=0;

    m=strlen(genre_search);

    for(i=0; i<global_count; i++)
    {
       n=strlen(search_list[i].title);

       for(j=0; j<=n-m; j++)
       {
           k=0;
           while(k<m && genre_search[k]==search_list[i].genre[j+k])
           {
               k++;
           }
           if(k==m)
           {
               int flag=0;
              for(int  y=0;y<=z;y++)
              {
                  if(strcmp(s[y].title,search_list[i].title)==0)
                    flag=1;
              }
              if(flag==1)
                continue;
               strcpy(s[z].title,search_list[i].title);
               strcpy(s[z].author,search_list[i].author);
               strcpy(s[z].genre,search_list[i].genre);
               s[z].rating=search_list[i].rating;
               z++;
           }
       }
    }

    if(z==0)
    {
        printf("NO RECOMMENDATIONS\n");
    }

    else
        bubble_sort_rec(s,z);
}


/**
Function Name: Bubble sort for recommendations
Input Parameters: structure and int
Return Type: void
Description: Sorting technique
**/


void bubble_sort_rec(REC s[200], int n)
{

    int i, j, temp;

    char temp1[30];

    for(i=0;i<=n-2;i++)
    {
        for(j=0;j<=n-2-i;j++)
        {
            if(s[j].rating<s[j+1].rating)
            {
                temp=s[j].rating;
                s[j].rating=s[j+1].rating;
                s[j+1].rating=temp;

                strcpy(temp1,s[j].title);
                strcpy(s[j].title,s[j+1].title);
                strcpy(s[j+1].title,temp1);

                strcpy(temp1,s[j].author);
                strcpy(s[j].author,s[j+1].author);
                strcpy(s[j+1].author,temp1);

                strcpy(temp1,s[j].genre);
                strcpy(s[j].genre,s[j+1].genre);
                strcpy(s[j+1].genre,temp1);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int l=0;l<strlen(s[i].title);l++)
        {
            if(s[i].title[l]=='-')
            {
                s[i].title[l]=' ';
            }
        }
        for(int l=0;l<strlen(s[i].author);l++)
        {
            if(s[i].author[l]=='-')
            {
                s[i].author[l]=' ';
            }
        }
        for(int l=0;l<strlen(s[i].genre);l++)
        {
            if(s[i].genre[l]=='-')
            {
                s[i].genre[l]=' ';
            }
        }




         printf("%d",s[i].rating);

            printf("   ");

        printf("%s",strupr(s[i].title));


printf("         ");
        printf("%s",strupr(s[i].author));






        printf("\n\n\n");
    }
}


void user_interface(char a[10])
{
    int u=40;

    char status[30];

    for(int i=0 ; i < user_count ; i++)
    {
        if(strcmp(a,user[i].userid)==0)
          {
              u=i;
          }
    }

    if(u==40)
    {
        printf("INVALID USER ID\n");
    }

    else
        {
        if(user[u].subscription_status==1)
        strcpy(status,"SUBSCRIBED");

        else
            strcpy(status,"NOT_SUBSCRIBED");
        printf("USERNAME : %s\n\nSUBSCRIPTION STATUS : %s\n\n",user[u].name,status);

        printf("BOOKS PURCHASED : ");

        for(int j=0 ; j<user[u].no_of_books_read ; j++)
        {
          printf("%s  ",user[u].books_read[j].read);
        }

        printf("\n\n");


    int z=0;

    char book[30];

    while(z<3)
    {
        printf("THE CHANGES WILL BE REFLECTED IN KINDLEUSERS FILE\n\n");
        printf("MENU   :      \n1.TO PURCHASE BOOK\n2.SUBSCRIPTION\n3.LOGOUT\n\nENTER YOUR CHOICE\n");

        scanf("%d",&z);

        switch(z)
        {
            case 1: printf("ENTER THE BOOK NAME TO BE PURCHASED\n\n");

                    getchar();

                    gets(book);

                    int flag=0;

                    for(int k=0 ; k<user[u].no_of_books_read ; k++)
                    {
                        if(strcmp(book,user[u].books_read[k].read)==0)
                        {
                           flag=1;
                        }

                    }

                    if(flag==1)
                    {
                        printf("BOOK IS ALREADY PURCHASED\n");
                    }

                    else
                       {
                           printf("%s %d\n",book,u);
                           purchase_book(book,u);
                       }
                        break;

            case 2: subscription(status,u);
            break;


        }
    }
    }
}


void purchase_book(char a[30],int b)
{

    FILE *f;

    f=fopen("Kindleusers.txt","w");

    for(int j=0 ; j<user_count-1 ; j++)
     {
         if(j==b)
         {
             user[j].no_of_books_read++;

              fprintf(f,"%s  %s  %s %d %d ",user[j].name,user[j].userid,user[j].city,user[j].subscription_status,user[j].no_of_books_read);

           for(int k=0 ; k<user[j].no_of_books_read-1;k++)
           {
             fprintf(f,"%s ",user[j].books_read[k].read);
           }

          fprintf(f,"%s ",a);

          fprintf(f,"\n");
         }

        else
            {

             fprintf(f,"%s  %s  %s %d %d ",user[j].name,user[j].userid,user[j].city,user[j].subscription_status,user[j].no_of_books_read);

             for(int k=0 ; k<user[j].no_of_books_read;k++)
             {

             fprintf(f,"%s ",user[j].books_read[k].read);
             }


            fprintf(f,"\n");
            }
     }

     fclose(f);

     load_users();

}

void subscription(char a[30],int b)
{

    if(strcmp(a,"SUBSCRIBED")==0)
     {
        printf("USER %s HAS SUBSCRIBED\n\nPRESS 1 TO CONTINUE WITH SUBSCRIPTION\nPRESS 2 TO CANCEL THE SUBSCRIPTION\n",user[b].name);

        int z;

        scanf("%d",&z);

        if(z==2)
        {
          FILE *f;

          f=fopen("Kindleusers.txt","w");

         for(int j=0 ; j<user_count-1 ; j++)
         {
         int y=0;
         if(j==b)
         {
              fprintf(f,"%s  %s  %s %d %d ",user[j].name,user[j].userid,user[j].city,y,user[j].no_of_books_read);

              for(int k=0 ; k<user[j].no_of_books_read;k++)
              {
                fprintf(f,"%s ",user[j].books_read[k].read);
              }

          fprintf(f,"\n");
         }

         else
            {
         fprintf(f,"%s  %s  %s %d %d ",user[j].name,user[j].userid,user[j].city,user[j].subscription_status,user[j].no_of_books_read);

         for(int k=0 ; k<user[j].no_of_books_read;k++)
         {
             fprintf(f,"%s ",user[j].books_read[k].read);
         }

         fprintf(f,"\n");

            }

     }

     fclose(f);

        }

    }

    else
    {

       printf("USER %s HAS NOT SUBSCRIBED\n\nPRESS 1 TO TAKE THE SUBSCRIPTION\nPRESS 2 TO CONTINUE WITHOUT SUBSCRIPTION\n",user[b].name);

        int z;

        scanf("%d",&z);

        if(z==1)
        {
          FILE *f;

    f=fopen("Kindleusers.txt","w");

    for(int j=0 ; j<user_count-1 ; j++)
     {
         int y=1;

         if(j==b)
         {
              fprintf(f,"%s  %s  %s %d %d ",user[j].name,user[j].userid,user[j].city,y,user[j].no_of_books_read);

         for(int k=0 ; k<user[j].no_of_books_read;k++)
         {
             fprintf(f,"%s ",user[j].books_read[k].read);
         }

          fprintf(f,"\n");

         }

         else
            {

         fprintf(f,"%s  %s  %s %d %d ",user[j].name,user[j].userid,user[j].city,user[j].subscription_status,user[j].no_of_books_read);

         for(int k=0 ; k<user[j].no_of_books_read;k++)
         {
             fprintf(f,"%s ",user[j].books_read[k].read);
         }

         fprintf(f,"\n");

            }
    }

    fclose(f);

        }
    }


    load_users();

}
