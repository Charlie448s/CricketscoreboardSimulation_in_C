#include<stdio.h>
void boll();
void run();
void wide();

void wide()
{
   printf("increament the run by 1\n");

}
void noboll()
{
   printf("add run to total and batsmen\n");
}
void run()
{
   int c;
   printf("1 or 2 or 3 or 4 or 6 \n");
   scanf("%d",&c);
   switch(c)
   {
      case 1:printf("/add run to total and stricker batsmen and swap the batsmen/\n");break;
      case 2:printf("/*add run to total and stricker batsmen */\n");break;
      case 3:break;
      case 4:
      case 6:printf("/*add run to total and stricker batsmen */\n");break;
   }
}
void ball()
{
   int c;
   printf("1.run\t2.norun\n");
   scanf("%d",&c);
   switch(c)
   {
      case 1:run();break;
      case 2:return;
   }
}
void main()
{
   int i,j,n=6,out=0,b;
   for(i=0;i<2;i++)
   {
      printf("/change the boller for each over/\n");
      
      for(j=0;j<n;j++)
      {
         printf("1.wide\t2.noboll\t3.ball\t4.out\n");
         scanf("%d",&b);
         switch(b)
         {
            case 1:
            case 2:printf("add run to total\n");n++;break;
            case 3:ball();break;
            case 4:out=1;break;
         }
         if(out==1)
      {
      printf("if out=1 change the batsmen\n");
      out=0;
      }
      }
    
   }
}