#include <graphics.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

void printCurrentTime() {
    time_t rawTime;
    struct tm *currentTime;
    char timeString[12];

    time(&rawTime);
    currentTime = localtime(&rawTime);
    strftime(timeString, sizeof(timeString), "%I:%M:%S %p", currentTime);
    outtextxy(getmaxx() / 2, getmaxy() / 2, timeString);
}

int main() {
    initwindow(400, 400);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    setcolor(RED);

    putenv("TZ=BRT+3");  // Definindo o fuso horário para o Brasil (UTC-3)

    time_t startTime = time(NULL);
    time_t currentTime = startTime;

    while (1) {
        printCurrentTime();
        sleep(1); 
        currentTime = time(NULL);

        if (currentTime - startTime > 61)
            break;

        cleardevice();
    }

    getch();
    closegraph();

    return 0;
}
