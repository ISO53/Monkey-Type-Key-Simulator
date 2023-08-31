#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define TRUE 1
#define FALSE 0
#define KEY_UP KEYEVENTF_KEYUP
#define KEY_DOWN 0x00
#define KEY_PRESSED_STATE_CODE 0x8000
#define KEY_CODE_FOR_i 222
#define MAX_SENTENCE_LENGTH 1024

void holdKey(short);
void releaseKey(short);
void wait(unsigned long);
void simulateKeyStrokes(char *, unsigned long);
void waitWithCount(unsigned long);

int main()
{
    char sentence[MAX_SENTENCE_LENGTH];
    int waitTime;

    printf("\nWrite the sentence to simulate keystrokes.\n--> ");
    fgets(sentence, 250, stdin);

    // Remove the newline character from the sentence
    sentence[strcspn(sentence, "\n")] = '\0';

    printf("\nHow long you wany to wait between keystrokes in miliseconds? (1sec = 1000ms)\n--> ");
    scanf("%d", &waitTime);

    printf("Program will start simulating the keystrokes after 5 seconds!");

    waitWithCount(5000);

    simulateKeyStrokes(sentence, waitTime);

    return 1;
}

void waitWithCount(unsigned long milisecond)
{
    for (int i = (milisecond / 1000); i > 0; i--)
    {
        printf("\n%d", i);
        wait(1000);
    }
}

void wait(unsigned long milisecond)
{
    unsigned long startTime = (unsigned)clock();
    while ((unsigned)clock() - startTime < milisecond)
    {
        // wait
    }
}

void holdKey(short key)
{
    INPUT ip = {};
    ip.type = INPUT_KEYBOARD;
    ip.ki.wVk = key;
    ip.ki.dwFlags = KEY_DOWN;

    SendInput(1, &ip, sizeof(INPUT));
}

void releaseKey(short key)
{
    INPUT ip = {};
    ip.type = INPUT_KEYBOARD;
    ip.ki.wVk = key;
    ip.ki.dwFlags = KEY_UP;

    SendInput(1, &ip, sizeof(INPUT));
}

void pressKey(short key)
{
    holdKey(key);
    releaseKey(key);
}

void simulateKeyStrokes(char *sentence, unsigned long milisec)
{
    int sentenceLength = strlen(sentence);

    for (int i = 0; i < sentenceLength; i++)
    {
        if (sentence[i] == 'i')
        {
            pressKey(222);
        }
        else
        {
            pressKey(VkKeyScanEx(sentence[i], 0));
            wait(milisec);
        }
    }
}
