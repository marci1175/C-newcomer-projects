#include <iostream>
#include <Windows.h>
int marci;
int timee;
void thread1() {
    timee = 0;
    while (marci < 1000000000) {
        timee = timee + 1;
        Sleep(1000);
    }
}
int main()
{
    //thread handling
    auto thread = CreateThread(nullptr, 0, reinterpret_cast <LPTHREAD_START_ROUTINE> (thread1), nullptr, 0, nullptr);
    if (thread) {
        CloseHandle(thread);
    }



    //actual code
    marci = 0;
    while (1000000000 > marci)  {
        marci = marci + 1;
    }


    //print end
    std::cout << "Finished!\n";
    std::cout << "It took " << timee << " seconds to complete";
}
