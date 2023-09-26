/*
Shell
=====
Shell adalah program yang membuat proses child untuk menjalankan string perintah yang diberikan.
Shell berupa infinite looping yang berisi siklus fork--exec--wait.
Lengkapilah kode berikut ini untuk membuat program shell sederhana!
Contoh masukan dan keluaran
---------------------------
    $ date
    Tue Dec  9 13:34:17 WIB 2014
    $ whoami
    auriza
    $ exit
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// pecah string per kata
void split_words(char *string, char **words)
{
    int i;
    words[0] = strtok(string, " \n");
    for (i = 0; words[i]; i++)
        words[i+1] = strtok(NULL, " \n");
}

int main()
{
    char cmd[80];                           //  string perintah
    char *args[20];                         //  argumen string perintah

    while (1)
    {
        //  cetak prompt "$ "
        printf("$ ");

        //  baca string perintah
        fgets(cmd, 80, stdin);

        //  pecah string perintah per argumen
        split_words(cmd, args);

        //  jika perintah = "exit"
        //      break
        if (strcmp(args[0], "exit") == 0)
        {
            return 0;
        }

        //  jika perintah = "cd"
        //      ganti direktori
        //      continue
        if (strcmp(args[0], "cd") == 0)
        {
            if (args[1])
            {
                chdir(args[1]);
            }
            continue;
        }
        

        //  buat proses child:
        //      exec string perintah
        //      cetak pesan error
        //      keluar dengan kode -1

        //  tunggu child selesai

        pid_t pid;
        pid = fork();
        if (pid == 0)
        {
            execvp(args[0], args);
            perror(args[0]);
            _exit(-1);
        }
        else if (pid < 0)
        {
            perror("fork");
        }
        else if (pid > 0)
        {
            wait(NULL);
        }
    }

    return 0;
}