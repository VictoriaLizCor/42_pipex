# pipex

I guess it's save to say most of us used the pipe `|` character in the termial
to perform an operation between two command like `cat` and `wc`
```shell
cat /etc/passwd | wc -l
```
which is a very famous duo we all used many time, but have you ever wondered how
it works, I mean basically the pipe `|` makes the output of `cat` to be the input
of `wc`, we can also redirect the output of `wc` to file by using `>` character then
the name of the file like this:
```shell
cat /etc/passwd | wc -l > output.txt
```
I asked myself the same question and I decided to make a program to mimic the pipe `|`
and the redirection `>` operation.
I found out it's not that simple to implement such a feature to a program, it involves 
`pipes` obviously and I had to work with processes on a system level using `fork()`, `waitpid()`
and `execve()`, but it was a fun project and I have learnt a lot from it.

|Program name|pipex|
|:----------:|:----|
|Arguments|file1 cmd1 cmd2 file2|
|External functs|• open, close, read, write,<br />malloc, free, perror,<br />strerror, access, dup, dup2,<br />execve, exit, fork, pipe,<br />unlink, wait, waitpid<br />• [My ft_printf library](https://github.com/SolarisCode/ft_printf)|
|Libft|[My own library](https://github.com/SolarisCode/Libft)|
|Description|This project is about handling pipes.|

## How to install:

Clone the repository in the desired directory.
```shell
git clone https://github.com/SolarisCode/pipex.git
```
Then use `make` inside the pervious directory either with `all` or `bonus` rule if you want to use
as many pipes as you want and also gain the functionality of `here_docs` combained with append `>>`
character.
```shell
make all
```
>or
```shell
make bonus
```
The program will be executed as follows:
```shell
./pipex infile "cat -e" "wc -l" outfile
```
just like the it does in the termial:
```shell
< infile cat -e | wc -l outfile
```
And if you complied the bonus part you would be able to run it like this:
```shell
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
It will support `<<` and `>>` when the first parameter is `here_doc`:
```shell
/pipex here_doc LIMITER cmd cmd1 file
```
Just like in the termial:
```shell
cmd << LIMITER | cmd1 >> file
```
>While the `LIMITER` is the word of your choice to end the input for the standard input.

Feel free to contact me if you have a better way to implement any of these functionalities :)
