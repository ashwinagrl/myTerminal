    
This terminal can execute ls,ps,cp,mv and grep with few options:

1)ls:
	ls [OPTION]
	This works as original command ls.
	This can be executed with following options:
	1) -l 2) -a 3) -s 4) -r 5) -lh 6) -lhS

3)cp:
	cp [OPTION] [SOURCE] [TARGET]
	This works as original command cp.
	This can be executed with following options:
	1) -v 2) -n 3) -i 4) -b
3)mv:
	mv [OPTION] [SOURCE] [TARGET]
	This works as original command mv.
	This can be executed with following options:
	1) -v 2) -n 3) -i 4) -b
4)grep:
	grep [OPTION] PATTERN [FILE]
	This works as original command grep.
	This can be executed with following options:
	1) -c 2) -n 3) -v 4) -i
5)ps:
	ps [OPTION]
	This works as original command ps.
	This can be executed with following options:
	1) -a 2) -d 3) -r 4) -e	

The requirements to execute this terminal are :
-> A Linux Ubuntu machine.
-> GCC should be installed in the machine:
	If GCC is not installed in your machine, do the following:
	Open the terminal on your machine and run the following commands:
		-> "sudo apt update"
		-> "sudo apt install build-essential"
		OR
		-> "sudo apt install gcc"
	To check if install then run the following command:
	        -> "gcc --version"
-> libreadline :
Install libreadline in your machine:
For that run the following command on your terminal:
		-> "sudo apt-get install libreadline8 libreadline-dev"
Now you are ready to run this terminal!

Steps to execute:

-> Change the directory to the directory where the files are located.
-> Now run the following commands: 
    -> "make" (To compile the executable files.)
    -> "./myshell" (To execute the terminal.)

Now you can run whichever command you want to run from the above mentioned commands.


