#include<stdio.h>
#include <string.h>
//This function will return index of a character in KeyString
int getIndex(char a,char* KeyString)
{
    int b=-1;
    for (int i = 0; i < strlen(KeyString); ++i)
    {
        if(KeyString[i]==a)
        {
            b=i;
        }
    }
    return b;
}
//This function will encrypt the given string with the help of key string applying a key
void encrypt(char* CipherText,char* KeyString)
{
    char ch;
    int i, key,j=0;
    printf("Enter key: ");
    scanf("%d", &key);
    for(i = 0; CipherText[i] != '\0'; ++i){
        int index=getIndex(CipherText[i],KeyString);
        int modd = (index+key+j)%strlen(KeyString);
        CipherText[i] = KeyString  [modd];
        j++;
    }

    printf("Encrypted message: %s", CipherText);
}
//This function will decrypt the given string with the help of key string applying bruteforce to get right key
void decryption(char CipherText[100],char* KeyString)
{
    int i;
    for (int key = 1; key <60 ; ++key) {
        int cout_spaces = 0;
        char copy_CipherText[100];
        strcpy(copy_CipherText, CipherText);
        for (i = 0; CipherText[i] != '\0'; ++i)
        {
            int index = getIndex(copy_CipherText[i],KeyString);
            int modd = (index - key - cout_spaces);
            if (modd < 0)
            {
                while(modd<0)
                    modd = strlen(KeyString) + modd;
                modd = modd % strlen(KeyString);
            }
            else
            {
                modd = modd % strlen(KeyString);
            }
            copy_CipherText[i] = KeyString[modd];
            cout_spaces++;
        }
        printf("Offset: %d; Result: %s\n", key, copy_CipherText);
    }
}
int main()
{
    char* KeyString;
    KeyString="hXTFexn39AJ6cmCYgktNuUwBdlKL04R1DSQrH y5q8VpjIZMGivEfasoWOb72zP";
    char CipherText[100];
    printf("Enter a message to Decrypt: ");
    gets(CipherText);
    printf("Cipher Text: %s\n\n",CipherText);
    decryption(CipherText,KeyString);
    return 0;
}