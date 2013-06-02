
#include <stdio.h>

#include <pthread.h>

#define NTHREADS 10

void *thread_function(void *);

// initialization
// mutex1 is used in pthread_mutex_lock(&mutex1);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int  counter = 0;

int main() {

   // we can create up to 10 threads
   pthread_t thread_id[NTHREADS];
   
   int i, j;

   for(i=0; i < NTHREADS; i++) {

      pthread_create( &thread_id[i], NULL, thread_function, NULL );

   }
	
   // wait for threads to terminate
   for(j=0; j < NTHREADS; j++) {

      pthread_join( thread_id[j], NULL); 

   }
  
   /* Now that all threads are complete I can print the final result.     */
   /* Without the join I could be printing a value before all the threads */
   /* have been completed.                                                */

   printf("Final counter value: %d\n", counter);
}

void *thread_function(void *dummyPtr) {

   printf("Thread number %ld\n", pthread_self());

   pthread_mutex_lock( &mutex1 );

   counter++;

   pthread_mutex_unlock( &mutex1 );

}
