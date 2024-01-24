#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#include<time.h>
#define TEAM_COUNT 10
#define PLAYERS_PER_TEAM 11
#define PLAYER_NAME_LENGTH 20
int t,totruninover=0;
int played,target=9999,flag=0,ovr;
int choice1,choice2,other,bwl=6,inc=0,inc1=1;
int gotocount=0;
int i,j,n=6,out=0,b;
char t1[20],t2[20];
char toss[20];
struct players {
    char p[PLAYERS_PER_TEAM][PLAYER_NAME_LENGTH],name[20];
    int run[11];
    int bowlerec[11];
    int bowlerwicket[11];
    int wickets;
    int totalrun;
    int over[50];

   int run6[11],run4[11];
} team[TEAM_COUNT];
int totalover(struct players *team);
void batting();
void bowling();
void ball();
void run();
void wide();
int choosebatsmen();

char *ordinalNumbers[] = {"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth", "tenth"};

int main() {
    FILE *file;
    file = fopen("players.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }

    for (int i = 0; i < TEAM_COUNT; i++) {
        for (int j = 0; j < PLAYERS_PER_TEAM; j++) {
           
            if (fscanf(file, "%s", team[i].p[j]) != 1) {
                fprintf(stderr, "Error reading player name from file.\n");
                fclose(file);
                exit(1);
            }
        }
    }
    

    fclose(file);
    FILE *file1;
    file1 = fopen("country.txt", "r");

    if (file1 == NULL) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }
     for (int i = 0; i < TEAM_COUNT; i++) {
      
           
            if (fscanf(file1, "%s", team[i].name) != 1) {
                fprintf(stderr, "Error reading player name from file.\n");
                fclose(file1);
                exit(1);
            
        }
    }
    
do{
printf("Enter the number of overs\n");
scanf("%d",&ovr);
}while(ovr==0);
    int choice;
    int count = 0;
     printf("");
    printf("1. India\n");
    printf("2. Pakistan\n");
    printf("3. Australia\n");
    printf("4. Afghanistan\n");
    printf("5. Sri Lanka\n");
    printf("6. Bangladesh\n");
    printf("7. New Zealand\n");
    printf("8. Netherlands\n");
    printf("9. West Indies\n");
    printf("10. England\n");

    
    while (count != 2) {
        count++;
        printf("Enter the %s team \n", ordinalNumbers[count - 1]);
        printf("Enter the serial number of team (1-10): ");
        
        // Validate user input
        while (1) {
            scanf("%d", &choice);

            if (choice >= 1 && choice <= 10&& choice!=t) {
                break;
            } else {
                printf("Invalid input. Please enter a number between 1 and 10||no team repetition please : \n");
            }
        }
        t=choice;
        // Consume newline character from input buffer
        getchar();
         char team1[20];
        // Display team and players
        printf("The Team: ");
        
        switch (t) {
            case 1: printf("India\n");strcpy(team1,"India"); break;
            case 2: printf("Pakistan\n");strcpy(team1,"Pakistan"); break;
            case 3: printf("Australia\n"); strcpy(team1,"Australia"); break;
            case 4: printf("Afghanistan\n"); strcpy(team1,"Afghanistan"); break;
            case 5: printf("Sri Lanka\n");strcpy(team1,"Sri Lanka");  break;
            case 6: printf("Bangladesh\n"); strcpy(team1,"Bangladesh"); break;
            case 7: printf("New Zealand\n");strcpy(team1,"Newzealand");  break;
            case 8: printf("Netherlands\n");strcpy(team1,"Netherlands"); break;
            case 9: printf("West Indies\n");strcpy(team1,"WestIndies");  break;
            case 10: printf("England\n");strcpy(team1,"England");break;
            default: printf("Unknown Team\n"); break;
            }
            
        if(count==1){
        strcpy(t1,team1); choice1=choice;}
        else {strcpy(t2,team1);choice2=choice;}     
        printf("Players:\n");
        for (int i = 0; i < PLAYERS_PER_TEAM; i++) {
            printf("\t%s\n", team[choice - 1].p[i]);
        }

        if (count == 1) {
            printf("\nChoose the second team.\n");
        }
        printf("\n");
    }

tosser:
printf("Enter the team which won the toss\n ");
gets(toss);


if(strcmp(toss,t1)==0||strcmp(toss,t2)==0){
printf("The team %s won the toss\n",toss);}
else{ printf("please enter the name of the team correctly\n");
goto tosser;}

printf("What does %s choose\n",toss);
int bat_bowl;
// printf("1.Bowl\n2.bat\n");
// scanf("%d",&bat_bowl);
if(strcmp(team[choice1-1].name,toss)==0){
printf("1.Bat\n2.bowl\n");
scanf("%d",&bat_bowl);
if(bat_bowl==1){
printf("%s choose to bat\n",toss);

 
printf("The opening batsmen are %s and %s \n",team[choice1-1].p[inc],team[choice1-1].p[inc1]);
batting();
}
else{
    printf("The opening batsmen are %s and %s \n",team[choice2-1].p[inc],team[choice2-1].p[inc1]);
    printf("%s choose to bowl\n",toss);
 choice1=choice1+choice2;choice2=choice1-choice2;choice1=choice1-choice2;
 bowling();
 exit(0);
 }}
if(strcmp(team[choice2-1].name,toss)==0){
printf("1.Bat\n2.bowl\n");

scanf("%d",&bat_bowl);
if(bat_bowl==1){
 choice1=choice1+choice2;choice2=choice1-choice2;choice1=choice1-choice2;
printf("%s choose to bat\n",toss);
printf("The opening batsmen are %s and %s \n",team[choice2-1].p[inc],team[choice2-1].p[inc1]);
batting();
}
else{
   
    printf("The opening batsmen are %s and %s \n",team[choice1-1].p[inc],team[choice1-1].p[inc1]);
    printf("%s choose to bowl\n",toss);

 bowling();
 }
}
return 0;
}
void batting(){ 
 team[choice1-1].wickets=0;
  team[choice2-1].bowlerec[bwl]=0;
  team[choice1-1].over[bwl]=0;
 sachin:
 if(gotocount==1)
    printf("\nThe opening batsmen are %s and %s\n",team[choice1-1].p[inc],team[choice1-1].p[inc1]);
 
 printf("==========================================================================================================================\n");
 printf("\n%s vs %s\n",t1,t2);
 sleep(2);
 printf("===========================================================================================================================\n");

 gotocount++;
 
   for(i=0;i<ovr;i++)
   {  if(bwl==10)
          bwl=6;
      team[choice1-1].over[bwl]+=1;  
       
      printf("%s is bowling\n",team[choice2-1].p[bwl]);
      totruninover=0;
      
      for(j=0;j<n;j++)
      {   bhendi: 
        printf("%d over %d ball\n",i+1,j+1);
       
         printf("1.wide\t2.noball\t3.ball\t4.out\n");
         int lower=1,upper=4;
         srand(time(NULL));int temp;
          temp=rand()%(upper-lower+1)+lower;
          if(temp==1){
            switch(temp){
                case 1:temp=rand()%(upper-lower+1)+lower;break;
                case 2:temp=rand()%(upper-lower+1)+lower;break;
                case 3:temp=rand()%(upper-lower+1)+lower;break;
                case 4:temp=rand()%(upper-lower+1)+lower;break;
                
            }    
          }
          b=temp;
          //scanf("%d",&b);
         switch(b)
         { 
            case 1:wide();break;
            case 2:team[choice1-1].totalrun=team[choice1-1].totalrun+1;n++;totruninover++;
            sleep(1);
            printf("Freehit\n");ball();break;
            case 3:ball();break;
            case 4:out=1;break;
            default:printf("Wrong choice \n");n-1;goto bhendi;
         }
         if(flag==1){
            goto trgt;
         }
         if(out==1)
      {
     
     
      printf("The %s takes %s wicket\n",team[choice2-1].name,ordinalNumbers[team[choice1-1].wickets]);
      printf("%s is out at %d\n",team[choice1-1].p[inc],team[choice1-1].run[inc]);
       out=0;
      if(inc<inc1){
        inc=inc1+1;
      }
      else{
        inc=inc+1;
      }
      
      team[choice1-1].wickets+=1;
      team[choice1-1].bowlerwicket[bwl]+=1;
      if(team[choice1-1].wickets==10)
         goto gameover;
         
      printf("The wicket is %d \n",team[choice1-1].wickets);
      printf("The %s enters the field\n ",team[choice1-1].p[inc]);
     
     
      
      }
       
      
   
      }
     team[choice2-1].bowlerec[bwl]+=totruninover;
    bwl++;
    inc=inc1+inc;inc1=inc-inc1;inc=inc-inc1;
    printf("Over completed\n");
    printf("\n%s is at strike now\n",team[choice1-1].p[inc]);
    
    
    
   
   
   }
     if(gotocount==1)
      target=team[choice1-1].totalrun;
    trgt:
    gameover:
     if(gotocount>1)
    team[choice2-1].bowlerec[bwl]+=totruninover;
   
    
   // inc=inc1+inc;inc1=inc-inc1;inc=inc-inc1;
    printf("\n===================================================================================================================\n");
    printf("\n%s scores %d / %d wickets\n ", team[choice1 - 1].name, team[choice1 - 1].totalrun, team[choice1-1].wickets);
    printf("Name\t\tscore\tFours\tSixes\t\n");

    // Find the maximum length of names
    int maxNameLength = 0;
    for (int i = 0; i < 11; i++) {
        int nameLength = strlen(team[choice1 - 1].p[i]);
        if (nameLength > maxNameLength) {
            maxNameLength = nameLength;
        }
    }

    for (int i = 0; i < 11; i++) {
        printf("%-*s\t%d\t%d\t%d\n", maxNameLength, team[choice1 - 1].p[i], team[choice1 - 1].run[i], team[choice1 - 1].run4[i], team[choice1 - 1].run6[i]);
    }

    printf("%s bowling\n", team[choice2 - 1].name);
    printf("Name\t\tover\twickets\teconomy\n");

    for (int i = 6; i < 11; i++) {
        printf("%-*s\t%d\t%d\t%d\n", maxNameLength, team[choice2 - 1].p[i], team[choice1 - 1].over[i], team[choice1 - 1].bowlerwicket[i], team[choice2 - 1].bowlerec[i]);
    }
   choice1=choice1+choice2;choice2=choice1-choice2;choice1=choice1-choice2;
   if(gotocount==1){
   if(strcmp(toss,t1)!=0)
   printf("%s is about bat\n",t1);
   else
   printf("%s is about to bat\n",t2);
   
   sleep(2);
   
//    printf("\nThe opening batsmen are %s and %s\n",team[choice1-1].p[inc],team[choice1-1].p[inc1]);
   inc=0;inc1=1;bwl=6;
   
   goto sachin;}
  if(team[choice1-1].totalrun>team[choice2-1].totalrun)
    printf("\n\t\t\t%s won by %d runs\t\t\t\n",team[choice1-1].name,team[choice1-1].totalrun-team[choice2-1].totalrun);
  else 
     printf("%s won by %d runs",team[choice2-1].name,team[choice2-1].totalrun-team[choice1-1].totalrun);
    
    
  

}
void bowling(){ 
 team[choice1-1].wickets=0;
  team[choice2-1].bowlerec[bwl]=0;
  team[choice1-1].over[bwl]=0;
 sachin:
 if(gotocount==1)
    printf("\nThe opening batsmen are %s and %s\n",team[choice1-1].p[inc],team[choice1-1].p[inc1]);
 printf("==========================================================================================================================\n");
 printf("\n%s vs %s\n",t1,t2);
 sleep(2);
 printf("===========================================================================================================================\n");

 gotocount++;
 
   for(i=0;i<ovr;i++)
   {  if(bwl==10)
          bwl=6;
      team[choice1-1].over[bwl]+=1;  
       
      printf("%s is bowling\n",team[choice2-1].p[bwl]);
      totruninover=0;
      
      for(j=0;j<n;j++)
      {   bhendi: 
        printf("%d over %d ball\n",i+1,j+1);
       
         printf("1.wide\t2.noball\t3.ball\t4.out\n");
          int lower=1,upper=4;
         srand(time(NULL));int temp;
          temp=rand()%(upper-lower+1)+lower;
          if(temp==1){
            switch(temp){
                case 1:temp=rand()%(upper-lower+1)+lower;break;
                case 2:temp=rand()%(upper-lower+1)+lower;break;
                case 3:temp=rand()%(upper-lower+1)+lower;break;
                case 4:temp=rand()%(upper-lower+1)+lower;break;
                
            }    
          }
          b=temp;
           //scanf("%d",&b);
         switch(b)
         { 
            case 1:wide();break;
            case 2:team[choice1-1].totalrun=team[choice1-1].totalrun+1;n++;totruninover++;
            sleep(1);
            printf("Freehit\n");ball();break;
            case 3:ball();break;
            case 4:out=1;break;
            default:printf("Wrong choice \n");n-1;goto bhendi;
         }
         if(flag==1){
            goto trgt;
         }
         if(out==1)
      {
     
     
      printf("The %s takes %s wicket\n",team[choice2-1].name,ordinalNumbers[team[choice1-1].wickets]);
      printf("%s is out at %d\n",team[choice1-1].p[inc],team[choice1-1].run[inc]);
      out=0;
      if(inc<inc1){
        inc=inc1+1;
      }
      else{
        inc=inc+1;
      }
      
      team[choice1-1].wickets+=1;
      team[choice1-1].bowlerwicket[bwl]+=1;
      if(team[choice1-1].wickets==10)
         goto gameover;
         
      printf("The wicket is %d \n",team[choice1-1].wickets);
      printf("The %s enters the field\n ",team[choice1-1].p[inc]);
     
      
      
      }
       
      
   
      }
    team[choice2-1].bowlerec[bwl]+=totruninover;
    bwl++;
    inc=inc1+inc;inc1=inc-inc1;inc=inc-inc1;
    printf("Over completed\n");
    printf("\n%s is at strike now\n",team[choice1-1].p[inc]);
    
    
    
    
   
   }
     if(gotocount==1)
      target=team[choice1-1].totalrun;
    trgt:
    gameover:
    if(gotocount>1)
    team[choice2-1].bowlerec[bwl]+=totruninover;
    
   
    
   // inc=inc1+inc;inc1=inc-inc1;inc=inc-inc1;
    printf("\n===================================================================================================================\n");
    printf("\n%s scores %d / %d wickets\n ", team[choice1 - 1].name, team[choice1 - 1].totalrun, team[choice1-1].wickets);
    printf("Name\t\tscore\tFours\tSixes\t\n");

    // Find the maximum length of names
    int maxNameLength = 0;
    for (int i = 0; i < 11; i++) {
        int nameLength = strlen(team[choice1 - 1].p[i]);
        if (nameLength > maxNameLength) {
            maxNameLength = nameLength;
        }
    }

    for (int i = 0; i < 11; i++) {
        printf("%-*s\t%d\t%d\t%d\n", maxNameLength, team[choice1 - 1].p[i], team[choice1 - 1].run[i], team[choice1 - 1].run4[i], team[choice1 - 1].run6[i]);
    }

    printf("%s bowling\n", team[choice2 - 1].name);
    printf("Name\t\tover\twickets\teconomy\n");

    for (int i = 6; i < 11; i++) {
        printf("%-*s\t%d\t%d\t%d\n", maxNameLength, team[choice2 - 1].p[i], team[choice1 - 1].over[i], team[choice1 - 1].bowlerwicket[i], team[choice2 - 1].bowlerec[i]);
    }
   choice1=choice1+choice2;choice2=choice1-choice2;choice1=choice1-choice2;
   if(gotocount==1){
   if(strcmp(toss,t1)!=0)
   printf("%s is about bat\n",t2);
   else
   printf("%s is about to bat\n",t1);
   
   sleep(2);
   if(gotocount>1)
   printf("\nThe opening batsmen are %s and %s\n",team[choice2-1].p[inc],team[choice2-1].p[inc1]);
   else
     printf("\n\nThe opening batsmen are %s and %s\n",team[choice1-1].p[inc],team[choice1-1].p[inc1]);
   inc1=1;inc=0;bwl=6;
   goto sachin;}
  if(team[choice1-1].totalrun>team[choice2-1].totalrun)
    printf("\n\t\t\t%s won by %d runs\t\t\t\n",team[choice1-1].name,team[choice1-1].totalrun-team[choice2-1].totalrun);
  else 
     printf("%s won by %d runs",team[choice2-1].name,team[choice2-1].totalrun-team[choice1-1].totalrun);
    
    
  

}
void run()
{  int lower=1,upper=6;
         srand(time(NULL));
          
   int c;
   
 
   label:
   printf("1 or 2 or 3 or 4 or 6 \n");
  
   c=rand()%(upper-lower+1)+lower;
    // scanf("%d",&c);
   switch(c)
   {
      case 1:printf("Now %s is at the strike\n",team[choice1-1].p[inc1]);
                    team[choice1-1].run[inc]+=1;inc=inc1+inc;inc1=inc-inc1;inc=inc-inc1;team[choice1-1].totalrun++,totruninover++;break;                                                             break;
      case 2:printf("%s is back to the strike\n",team[choice1-1].p[inc]);
                     team[choice1-1].run[inc]+=2;team[choice1-1].totalrun+=2,totruninover+=2;break;
      case 3:printf("Now %s is at the strike\n",team[choice1-1].p[inc1]);
      team[choice1-1].run[inc]+=3;inc=inc1+inc;inc1=inc-inc1;inc=inc-inc1;team[choice1-1].totalrun+=3,totruninover+=3;break;
      case 4:printf("%s hit a boundary\n",team[choice1-1].p[inc]); 
      team[choice1-1].run[inc]+=4;team[choice1-1].totalrun+=4;team[choice1-1].run4[inc]+=1,totruninover+=4;break;
      case 6:printf("%s hit maximum\n",team[choice1-1].p[inc]);team[choice1-1].run[inc]+=6;team[choice1-1].totalrun+=6,totruninover+=6;
      team[choice1-1].run6[inc]+=1;break;
      default: printf("Invlaid choice \n");goto label;  
   }
   if(gotocount>1)
   if(team[choice1-1].totalrun>target){
    printf("\n\t\t\t%s won\t\t\t\n ",team[choice1-1].name);
    flag=1;
   }


}
void ball()
{  int lower=1,upper=2;
         srand(time(NULL));
          
   int c;
   
   r:
   printf("1.run\t2.norun\n");
   c=rand()%(upper-lower+1)+lower;
   // scanf("%d",&c);
   switch(c)
   {
      case 1:run();break;
      case 2:return;
      default:printf("Please enter the valid choice \n"); goto r;
   }
}

void wide()
{
   printf("1 Extra\n");
  team[choice1-1].totalrun=team[choice1-1].totalrun+1;n++;totruninover++;

}
