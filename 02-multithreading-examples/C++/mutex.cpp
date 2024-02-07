#include <iostream>  // Only for I/O 
#include <thread> // posix threads
#include <mutex>  // mutexes 

// We declare a mutex to lock shared resource
std::mutex mut;

// Declare a counter 
int counter = 0;

void inc(int &myCoolArg)
{ 
    for (int i = 0; i < 1000000; i++) 
    { 
        std::unique_lock<std::mutex> lock(mut);  // You can use a lock guard as well, but generally unique locks are more flexible
        counter++; // increment counter 
        lock.unlock(); // Release the lock
    }
    std::cout << myCoolArg << std::endl;
}

int main(int argc, char *argv[]) 
{
    
    if (argc != 2) 
        {
        std::cout << "Please input the amount of threads to spawn" << std::endl;
        return 1;
        }
    
    int num_threads = atoi(argv[1]);


    std::cout << "Created " << num_threads << " threads" << std::endl; 

    std::thread threads[num_threads];
    int args[] = {41, 42, 43, 44};
    
    for (int i = 0; i < num_threads; ++i)
        {
            // The following line shows simpler way if args are not needed
            // threads[i] = std::thread(inc);
            threads[i] = std::thread([&args, i]() {
                inc(args[i]);
            });
        };
    
    for (int i = 0; i < num_threads; i++)
        { 
            threads[i].join();
         };
    
    std::cout << counter << std::endl; 
}