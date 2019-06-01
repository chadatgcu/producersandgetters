// Chad Weirick
// CST-221
// This is a sample producers and getters.

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <iostream>

// initializing for a simple balance
int balance = 220;


pthread_cond_t condc;
pthread_cond_t condp;
// the mutex could be there to lock if I was going to run this until an escape/crash
pthread_mutex_t lock;


int get(){
    balance = balance - 1;
    std::cout << "got change $" << balance << "\n";
    return balance;
}

void put(int balance){
    std::cout << "put change $" << balance << "\n";
}

int produce(){
    std::cout << "made balance $" << balance << "\n";
    return balance++;
}

void consume(int i){
    int consumed = i-1;
    std::cout << "used $" << consumed << "\n";
}

void* producer(void* args){
    int i;
    while(1){
        i = produce();
        put(i);
        if(i >= 0){
            break;
        }   
    }
}

void* consumer(void* args){
    int i;
    while(1){
        i = get();
        consume(i);
        if(i >= 0){
            break;
        }
    }
}

int main(){

    // create a producer and a consumer
    pthread_t producerThread;
    pthread_t consumerThread;

    //Initialize producer and consumer threads
    int pThread = pthread_create(&producerThread, NULL, producer, NULL);
    int cThread = pthread_create(&consumerThread, NULL, consumer, NULL);   



    int count = 0;
    while(count < 500){

        // use the join command
        pthread_join(producerThread, NULL);
        pthread_join(consumerThread, NULL);
        count++;
    }
    return 0;
}