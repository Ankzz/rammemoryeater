rammemoryeater
==============

A tool which allows you to eat specified amount of RAM memory for specified amount of time on your system. 
Helps stress testing of your application under low memory conditions.

$ rammemoryeater -h
rammemoryeater [s <size in MB>] [d <delay in seconds>] [h] 
               -s : Specify size in MB (I do no not eat in KBs buddy)
            	      Specify this value judiciously. It can make leave your
            	      machine in non-responsive state, if lot of memory goes off
            	 -d : Specify delay for which Ram Eater shall hold the memory 
            	 -v : Specify version of this Ram Eater 
            	 -h : To get this help message

$ rammemoryeater -v
rammemoryeater Version 0.01
           
Copyright (C) 2013 Free Software Foundation, Inc.
This is free software.  You may redistribute copies
of it under the terms of the GNU General Public License
<http://www.gnu.org/licenses/gpl.html>.
There is NO WARRANTY, to the extent permitted by law.

Written by Ankit 
Report your bugs to <ankzzdev@gmail.com>
