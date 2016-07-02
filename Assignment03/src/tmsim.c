#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>     
#include <stdbool.h>
#include <ctype.h>

/*
 *  Solves CS149 Assignment #3 
 *
 *  Authors: 
 *      Tyler Jones, 
 *      Scot Matson
 */

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// seller thread to serve one time slice (1 minute)
void * sell(void * seller_type)
{
    while (true) { // Having more work to do...
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond, &mutex);
        pthread_mutex_unlock(&mutex);

        // Serve any buyer available in this seller queue that is ready
        // now to buy ticket till done with all relevant buyers in their queue
        //..................
    }

    return NULL; // thread exits
}

void wakeup_all_seller_threads() {
    pthread_mutex_lock(&mutex);
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);
}

int main(int argc, char * argv[]) {

    // Type check user input and store N if it is a digit
    int n;
    if (argc != 2) {
       printf("Something something error.... @$%#%@#"); 
       exit(EXIT_FAILURE);
    }
    else {
        if (isdigit(*argv[1])) {
            n = atoi(argv[1]);
        }
    }

    int i;
    pthread_t tids[10];
    char sellerType;

    // Create necessary data structures for the simulator.
    // Create buyers list for each seller ticket queue based on the
    // N value within an hour and have them in the seller queue.
   
    // Create 10 threads representing the 10 sellers.
    sellerType = 'H';
    pthread_create(&tids[i], NULL, sell, &sellerType);
   
    sellerType = 'M';
    for (i = 1; i < 4; i++)
        pthread_create(&tids[i], NULL, sell, &sellerType);

    sellerType = 'L';
    for (i = 4; i < 10; i++)
        pthread_create(&tids[i], NULL, sell, &sellerType);

    // wakeup all seller threads
    wakeup_all_seller_threads();

    // wait for all seller threads to exit
    for (i = 0 ; i < 10 ; i++)
        pthread_join(tids[i], NULL); // This returns 0 on success... probably should catch for error handling

    // Printout simulation results
    exit(EXIT_SUCCESS);
}