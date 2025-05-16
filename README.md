# DSA-II-Practice-Project

## How to contribute

1. Check if git is installed

    ```bash
    type git
    ```

    if `git` is installed the expected result is:

    ```bash
    git is /usr/bin/git
    ```

    > git path may change

    else:

    ```bash
    bash: type: git: not found
    ```

    if git is not found, install following the instructions [here](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git).

1. Clone the repository

    ```bash
    git clone https://github.com/npteodoro/DSA-II-Practice-Project.git
    cd DSA-II-Practice-Project
    ```

1. Create your contribuiting branch

    ```bash
    git checkout -b <type>/<alias>
    ```

    example:

    ```bash
    git checkout -b feat/exerc3
    ```

1. Create exercise directory

    ```bash
    mkdir exerc<N>
    cd exerc<N>
    ```

1. Create main.c, main.sh and other .c .h files

1. After your program exercise is complete, commit and push

    ```bash
    git add .
    git commit -m "<type>: <description>"
    git push
    ```

1. Go to the [repository pull request tab](https://github.com/npteodoro/DSA-II-Practice-Project/pulls), click `New pull request`, choose your branch in the compare dropdown, click `Create pull request`, add some description and click `Create pull request`.
