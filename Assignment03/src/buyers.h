#ifndef BUYERS_H
#define BUYERS_H
struct Buyers{
    char* priority;
    char name[25];
    char seller_name[25];
    double wait_time;
    double start_time;
    double end_time;
    bool bought_ticket;
    int seat_number;
    int arrival_time;
    int sale_time;
};
#endif /* BUYERS_H */


