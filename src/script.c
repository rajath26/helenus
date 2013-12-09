#include<stdio.h>
#include<time.h>
#include<sys/time.h>
void main()
{
  int i=0;
  int rand_no;
  char buffer[4096];
 int success = 0;

   struct timeval cur_t;
   gettimeofday(&cur_t,NULL);
   long int sec1 = cur_t.tv_usec;
   for(i=1;i<=10000;i++){
      //rand_no = rand();
      if (i%200 == 0)
          sleep(1);
      rand_no = i;
      sprintf(buffer,"./KVclient 4901 130.126.112.107 3492 \"INSERT:::%d:::HELLO\" 1",rand_no);
      int rc  = system(buffer);
      if ( rc == 0 )
          success++;

      
   }
   gettimeofday(&cur_t,NULL);
   long int sec2 = cur_t.tv_usec;

   printf("\ntime taken : %ld\n", sec2 - sec1);
   printf("\nTOTAL INSERTS: %d\n", success);
}

