# Pointers on C

The code in this repository is from *Pointers on C*, which is a great material to learn C and its pointers.

## Compiling and Running

I write a makefile to make compiling and running the code easier, you just need to type the following command in your terminal to run the example program of `1.1-rearrange-string`.

```bash
$ make 1.1
```

## Creating a Project

The `new.sh` is used for creating a project by typing the following command.

```bash
$ ./new.sh 1.1-rearrange-string
```

The shell will create a `1.1-rearrange-string` directory in the root of project, and create a `main.c` file at the project directory with a built-in template. To simplify process of building the code, the shell will append a couple of lines into `Makefile` that following the rules mentioned at "Compiling and Running".
