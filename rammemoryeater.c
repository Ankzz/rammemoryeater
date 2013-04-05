/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

char *module = "rammemoryeater";
char *version = "0.01";

void Usage()
{
    printf("%s [s <size in MB>] [d <delay in seconds>] [h] \n\
            \t -s : Specify size in MB (I do no not eat in KBs buddy)\n\
            \t      Specify this value judiciously. It can make leave your\n\
            \t      machine in non-responsive state, if lot of memory goes off\n\
            \t -d : Specify delay for which Ram Eater shall hold the memory \n\
            \t -v : Specify version of this Ram Eater \n\
            \t -h : To get this help message \n\
          \n", module);
}

void Version()
{
    printf("%s Version %s\n\
           \n"
           "Copyright (C) 2013 Free Software Foundation, Inc.\n"
           "This is free software.  You may redistribute copies\n"
           "of it under the terms of the GNU General Public License\n"
           "<http://www.gnu.org/licenses/gpl.html>.\n"
           "There is NO WARRANTY, to the extent permitted by law.\n"
           "\n"
           "Written by Ankit \n"
           "Report your bugs to <ankzzdev@gmail.com>\n"
           , module, version);
}

size_t getTotalSystemMemory()
{
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    return pages * page_size;
}

void SystemFreeMem()
{
    printf("Free mem [Yet to perfect this value]: %u\n", getTotalSystemMemory());
}

int main(int argc, char **argv)
{
        int size = 10;
        int _s = 10;
        char *cvalue = NULL;
        int c;
        char flag = 1;

        opterr = 0;
        while ((c = getopt (argc, argv, "vShs:d:")) != -1) {
            switch (c)
           {
           case 's':
             size = atoi(optarg);
             size = atoi(optarg);
             break;
           case 'd':
             _s = atoi(optarg);
             break;
           case 'h':
             Usage();
             flag = 0;
             break;
           case 'S':
             SystemFreeMem();
             flag = 0;
             break;
           case 'v':
             Version();
             flag = 0;
             break;
           }
        }

        if(flag) {
            printf("Eating %dMB memory...\n", size);
            while(size-- > 0)
            {
                void *m = malloc(1024*1024);
                memset(m,0,1024*1024);
            }
            printf("Burp!! Sorry! Eaten required RAM.. Now sleeping for %d seconds.. \n", _s);
            sleep(_s);
        }
        return 0;
}
