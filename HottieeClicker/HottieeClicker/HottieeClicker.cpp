

#include<Windows.h>
#include<stdlib.h>
#include<iostream>
#include<random>
#include <cstdlib>
#include <filesystem>

using namespace std;

// Some definitions
bool normal_mode = false;
bool randomize = true;

// Sapphire lite randomization (Attempt)
random_device rd;
mt19937 r(rd());

// Self Destruct Things
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

// Colors stolen from dif
void setcolor(unsigned short color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
}


// call random function
int rand(int left_cps);

int main()
{


    // Menu - Layout copied from some random clicker
    system("cls");
    SetConsoleTitleA("Hottie Clicker");
    setcolor(11);
    cout << R"( 
    __  __      __  __  _              _________      __            
   / / / /___  / /_/ /_(_)__  ___     / ____/ (_)____/ /_____  _____
  / /_/ / __ \/ __/ __/ / _ \/ _ \   / /   / / / ___/ //_/ _ \/ ___/
 / __  / /_/ / /_/ /_/ /  __/  __/  / /___/ / / /__/ ,< /  __/ /    
/_/ /_/\____/\__/\__/_/\___/\___/   \____/_/_/\___/_/|_|\___/_/     
    )" << endl;
    setcolor(3);
    cout << "                                                       toca " << endl;
    setcolor(7);

    // Choose CPS
    int left_cps;

    std::cout << "[+] CPS:" << std::endl;
    std::cout << " -> ";
    setcolor(8);
    std::cin >> left_cps;

    if (left_cps > 20) {
        MessageBoxA(NULL, "Maximum CPS: 20", "Try Again", 0);
        main();
    }

    if (left_cps < 1) {
        MessageBoxA(NULL, "Minimum CPS: 1", "Try Again", 0);
        main();
    }


    system("cls");
    setcolor(11);
    cout << R"(
   __ __     __  __  _           ________     __          
  / // /__  / /_/ /_(_)__ ___   / ___/ (_)___/ /_____ ____
 / _  / _ \/ __/ __/ / -_) -_) / /__/ / / __/  '_/ -_) __/
/_//_/\___/\__/\__/_/\__/\__/  \___/_/_/\__/_/\_\\__/_/   
    )" << endl;
    setcolor(3);
    cout << "                                       toca                                                                                                                                                                                                                                      " << std::endl;

    // Toggle Defs
    bool left_clicker_toggled = false;

    // Instructions
    setcolor(8);
    std::cout << "F4 -> ";
    setcolor(7);
    std::cout << "Self Destruct" << std::endl;

    setcolor(8);
    std::cout << "F5 -> ";
    setcolor(7);
    std::cout << "Hide or Show Menu" << std::endl;


    // On and Off status Display
    setcolor(8);
    std::cout << "[+] Left Clicker -> ";
    setcolor(7);
    std::cout << left_cps << std::endl;

    // Some definitions
    bool breakblocks = true;
    bool randomize = true;

    // Sapphire lite randomization (Attempt)
    random_device rd;
    mt19937 r(rd());

    int left_delay;
    int numerator = randomize ? (r() % (475 + 1 - (475 - 25)) + (475 - 25)) : 520;
    int deviation = randomize ? 3 : 0;
   

    left_cps = (left_cps / 3) -1 ;
        // Autoclick
        while (true)
        {

            randomize = true;
            // Delay Function (Randomizer) if random number divided by 100 is less than 5
           
               left_delay = (numerator / left_cps);
          
             //left_delay =  (numerator / (left_cps - deviation + r() % ((deviation * 2) + 1)));
 
            if (left_clicker_toggled)
            {
                if (breakblocks == false)
                {
                    if (GetAsyncKeyState(VK_LBUTTON))
                    {
                        HWND Window = GetForegroundWindow(); // Get Window
                        if (FindWindowA(("LWJGL"), nullptr) == GetForegroundWindow())
                        {
                            SendMessageW(GetForegroundWindow(), WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0));
                            SendMessageW(GetForegroundWindow(), WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(0, 0));
                            Sleep(rand() % left_delay); // Sleep Delay Time
                        }

                    }
                }
            }

            if (breakblocks == true)
            {
                if (GetAsyncKeyState(VK_LBUTTON))
                {
                    HWND Window = GetForegroundWindow();
                    if (FindWindowA(("LWJGL"), nullptr) == GetForegroundWindow())
                    {
                        SendMessageW(GetForegroundWindow(), WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0));
                        Sleep(rand() % left_delay); // Sleep Delay Time
                    }
                }
            }
        }

        // Menu Options
// Hide and Show Window
        if (GetAsyncKeyState(VK_F5)) {

            Sleep(500);
        }

        /*
        // Switch modes
        if (GetAsyncKeyState(VK_F6)) {
            if (normal_mode == true) {
                normal_mode = false;
            }

            Sleep(200);
        }


        if (GetAsyncKeyState(VK_F7)) {
            if (normal_mode == false) {
                normal_mode = true;
            }

            Sleep(200);
        }
        */


        // Self Destruct
        if (GetAsyncKeyState(VK_F4))
        {
            MessageBoxA(NULL, "Hottiee Clicker sucefully destructed", "Hottiee Clicker", 0);

            // find the exe path
            char buffer[MAX_PATH];
            GetModuleFileNameA(nullptr, buffer, MAX_PATH);

            string executablePath(buffer);
            string executableName = filesystem::path(executablePath).stem().string();


            // Delete Prefetch of the exe path. 
            string command = "del /Q ";
            string path = "C:\\Windows\\Prefetch\\ " + executableName + ".*.pf";
            string path2 = "C:\\Windows\\Prefetch\\cmd.*.pf ";
            system(command.append(path).c_str());
            system(command.append(path2).c_str());


            // Clean DNS Cache
            BOOL(WINAPI * DoDnsFlushResolverCache)();
            *(FARPROC*)&DoDnsFlushResolverCache = GetProcAddress(LoadLibrary("dnsapi.dll"), "DnsFlushResolverCache");
            if (!DoDnsFlushResolverCache) return FALSE;
            return DoDnsFlushResolverCache();

            return 0;
        }
    
}


// Function to generate a randomized click delay
int rand(int left_cps) {
    // Micro adjustments to the ms value generated based on the selected cps
    int numerator = randomize ? (r() % (475 + 1 - (475 - 25)) + (475 - 25)) : 520;

    // Toggle for randomization
    int deviation = randomize ? 3 : 0;

    // Outliers
    if (r() % 100 < 3 && randomize) return r() % (150 + 1 - 100) + 100;

    return r() % 100 < 5 ? (numerator / left_cps) : (numerator / (left_cps - deviation + r() % ((deviation * 2) + 1)));
}