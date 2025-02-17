#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char String[255];

int alphabetNumber(char);
void displayMenu(char*);
void takeInput(String, String);
void encryptMessage(String, String, String);
void decryptMessage(String, String, String);


int
main()
{
        char MenuOption;
        String PlainText, Key;
        String CipherText;
        system("cls");
        do
        {
                displayMenu(&MenuOption);

                switch(MenuOption)
                {
                case '1':
                        takeInput(PlainText, Key);
                        encryptMessage(PlainText, Key, CipherText);
                        printf("Cipher Text:\n\n%s\n\n", CipherText);
                        break;
                case '2':
                        takeInput(CipherText, Key);
                        decryptMessage(CipherText, Key, PlainText);
                        printf("\n\nPlain Text:\n\n%s\n\n", PlainText);
                        
                default:
                        break;
                }
                
        } while(MenuOption != '3');
        
        return 0;
}

int
alphabetNumber(char TextCharacter)
{
        int Index;

        switch (TextCharacter)
        {
        case 'A':
        case 'a':
                Index = 0;
                break;
        case 'B':
        case 'b':
                Index = 1;
                break;
        case 'C':
        case 'c':
                Index = 2;
                break;
        case 'D':
        case 'd':
                Index = 3;
                break;
        case 'E':
        case 'e':
                Index = 4;
                break;
        case 'F':
        case 'f':
                Index = 5;
                break;
        case 'G':
        case 'g':
                Index = 6;
                break;
        case 'H':
        case 'h':
                Index = 7;
                break;
        case 'I':
        case 'i':
                Index = 8;
                break;
        case 'J':
        case 'j':
                Index = 9;
                break;
        case 'K':
        case 'k':
                Index = 10;
                break;
        case 'L':
        case 'l':
                Index = 11;
                break;
        case 'M':
        case 'm':
                Index = 12;
                break;
        case 'N':
        case 'n':
                Index = 13;
                break;
        case 'O':
        case 'o':
                Index = 14;
                break;
        case 'P':
        case 'p':
                Index = 15;
                break;
        case 'Q':
        case 'q':
                Index = 16;
                break;
        case 'R':
        case 'r':
                Index = 17;
                break;
        case 'S':
        case 's':
                Index = 18;
                break;
        case 'T':
        case 't':
                Index = 19;
                break;
        case 'U':
        case 'u':
                Index = 20;
                break;
        case 'V':
        case 'v':
                Index = 21;
                break;
        case 'W':
        case 'w':
                Index = 22;
                break;
        case 'X':
        case 'x':
                Index = 23;
                break;
        case 'Y':
        case 'y':
                Index = 24;
                break;
        case 'Z':
        case 'z':
                Index = 25;
        }
        return Index;
}

void
displayMenu(char *Input)
{
        printf("\nVigenere Cipher Program\n\n");
        printf("Options:\n(1)Encrypt\t(2)Decrypt\t(3)Terminate\n\n");
        printf("Choose an option: ");
        scanf(" %c", Input);
}

void
takeInput(String Text, String Key)
{
        printf("\n\nEnter the message:\n");
        fgetc(stdin);
        fgets(Text, 254, stdin);
        Text[strlen(Text) - 1] = 0;
        printf("Enter the Key:\n");
        scanf("%s", Key);
}

void
encryptMessage(String PlainText, String Key, String CipherText)
{
        String UpperCaseAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String LowerCaseAlphabet = "abcdefghijklmnopqrstuvwxyz";

        int i;
        int ctr = 0;
        int Index = 0;
        int KeyLength = strlen(Key);
        int PlainTextLength = strlen(PlainText);

        for(i = 0; i < PlainTextLength; i++)
        {
                if(PlainText[i] > 64 && PlainText[i] < 91)
                {
                        Index = (alphabetNumber(PlainText[i]) + alphabetNumber(Key[(i - ctr) % KeyLength])) % 26;
                        CipherText[i] = UpperCaseAlphabet[Index];
                }
                else if((PlainText[i] > 96 && PlainText[i] < 123))
                {
                        Index = (alphabetNumber(PlainText[i]) + alphabetNumber(Key[(i - ctr) % KeyLength])) % 26;
                        CipherText[i] = LowerCaseAlphabet[Index];
                }
                else 
                {
                        CipherText[i] = PlainText[i];
                        ctr++;
                }
        }

        CipherText[PlainTextLength] = 0;
}

void
decryptMessage(String CipherText, String Key, String PlainText)
{
        String UpperCaseAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String LowerCaseAlphabet = "abcdefghijklmnopqrstuvwxyz";

        int i;
        int ctr = 0;
        int Index = 0;
        int KeyLength = strlen(Key);
        int CipherTextLength = strlen(CipherText);

        for(i = 0; i < CipherTextLength; i++)
        {
                if(CipherText[i] > 64 && CipherText[i] < 91)
                {        
                        Index = (alphabetNumber(CipherText[i]) - alphabetNumber(Key[(i - ctr) % KeyLength]) + 26) % 26;
                        PlainText[i] = UpperCaseAlphabet[Index];
                }
                else if(CipherText[i] > 96 && CipherText[i] < 123)
                {
                        Index = (alphabetNumber(CipherText[i]) - alphabetNumber(Key[(i - ctr) % KeyLength]) + 26) % 26;
                        PlainText[i] = LowerCaseAlphabet[Index];
                }
                else
                {
                        PlainText[i] = CipherText[i];
                        ctr++;
                }
        }
        
        PlainText[CipherTextLength] = 0;
}