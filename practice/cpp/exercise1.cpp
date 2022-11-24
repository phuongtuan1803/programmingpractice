#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void print_a(){
    cout << "Thread A ID: " << std::this_thread::get_id() << endl;
    while (1)
    {
        cout << "Print A" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }    
}


int main(void){
    thread p1(print_a);
    thread p2([](){
        cout << "Thread B ID: " << std::this_thread::get_id() << endl;
        cout << "Print B" << endl;
    });

    p1.join();
    p2.join();

}