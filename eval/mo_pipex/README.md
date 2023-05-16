# pipex

* 42 Core Curriculum - Level 2
* Level 2 in the Holy Graph<br>
* Passed with 100% (mandatory part) on 22th Aug 2022.<br>


## Use

Clone the repository in your terminal and create a folder named pipex (or the name you prefer):<br>
`git clone https://github.com/mochan42/push_swap.git pipex`

Enter into the directory `pipex` (or type in the name of the folder you created):<br>
`cd pipex`

Run the Makefile to compile the programme:<br>
`make` for mandatory part<br>

To run the programme:<br>
`./pipex` `file1` `"cmd1"` `"cmd2"` `file2`

Example: inside the `pipex` folder (or the folder with the name you chose):<br>
- create a file1 : `touch file1`<br>
- write anything you want inside file1<br>
- run : `./pipex` `file1` `"cat"` `"wc -l"` `file2`<br>
- the result of `wc -l` will be written inside file2 (which will be automatically created if need be) and should be the number of lines there are in file1.<br>
