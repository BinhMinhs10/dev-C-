#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Add_new_words ();

int Learn ();

int main ()
{
    int mode, flag; FILE *f;
    //
    do
    {
        printf ("Ban hay chon che do hoc (1/ 2/ 3):\n");
        printf ("1. Add-new-words.\n");
        printf ("2. Learn.\n");
        printf ("3. Thoat.\n");
        //__fpurge(stdin);
        scanf ("%d", &mode);
        //
        switch (mode)
        {
            case 1:
            {
                f = fopen ("dictionary.txt", "r+b");
                
                if (f == NULL)
                {
                    printf ("Khong mo duoc tep");
                    exit (1);
                }
                else
                {
                    typedef struct word
                    {
                        char english_word [31];
                        char vietnamese_meaning [100];
                    } word;
                    int i; word ten_new_word;
                    //
                    printf ("Ban hay nhap 10 tu tieng Anh va nghia tieng Viet cua tung tu:\n");
                    for (i = 1; i <= 10; i++)
                    {
                        printf ("%-2d. Word: ", i);
                        fflush(stdin);
                        fgets (ten_new_word. english_word, sizeof(ten_new_word. english_word), stdin);
                        * (ten_new_word. english_word + strlen(ten_new_word. english_word) - 1) = '\0';
                        //
                        printf ("    Vietnamese meaning: ");
                        fflush(stdin);
                        fgets (ten_new_word. vietnamese_meaning, sizeof(ten_new_word. vietnamese_meaning), stdin);
                        * (ten_new_word. vietnamese_meaning + strlen(ten_new_word. vietnamese_meaning) - 1) = '\0';
                    }

                }
            }
            
            case 2:
            {

            }
            
            case 3:
            {
                printf("Thank you\n");
                flag = 0;
                break;
            }
            
            default:
            {
                puts("No command");
                flag = 1;
            }
        }
    }while (flag);
    return 0;
}
