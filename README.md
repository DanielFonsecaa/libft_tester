# libft_tester
A small tester, simple to read and to see the tests for the libft project on 42

Steps to Run
Clone the repository:

First, clone the repository to your local machine using the following command:


    git clone [<repository-url>](https://github.com/DanielFonsecaa/libft_tester/)
Navigate to the directory containing the .c files:

Move the necessary files into the directory where your .c source files are located, or ensure that the repository's files are in the same directory as your .c files.

    mv <repository-folder>/* <your-c-files-directory>/
    Replace <repository-folder> with the folder you cloned the repo into, and <your-c-files-directory> with the directory where your .c files are located.

Compile the code:

After moving the necessary files, navigate to the directory where the .c files are located, and compile all the files using the following command:

    cc -Wall -Wextra -Werror *.c -o a.out
This will compile all the .c files and produce an executable named a.out.

Run the program:

Finally, run the compiled program with the following command:

    ./a.out
This will execute the program and display the results.

# Disclaimer:
I am not sure how the program behaves if there are fewer files than necessary. Please ensure all the required files are available for proper functionality.
