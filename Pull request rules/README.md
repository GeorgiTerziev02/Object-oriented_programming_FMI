## Материали от лекции, семинари и практикуми по "Обектно-ориентирано програмиране"
#### летен семестър 2022/2023, спец. Софтуерно инженерство & Информационни системи
- [Материали oт лекции](https://github.com/Justsvetoslavov/Object-oriented_programming_FMI/tree/master/Lectures)
- [Материали от упражнения](https://github.com/Justsvetoslavov/Object-oriented_programming_FMI/tree/master/Seminars)

## Github workflow

0. Star the repository
![star the repo](images/star-the-repo.png)

1. Fork the repository 
    - [How to fork a repository.](https://docs.github.com/en/get-started/quickstart/fork-a-repo)

2. Clone the repository on your local machine 
    - [How to clone a repository.](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository)

    - In GitHub desktop - Repository -> Repository settings... -> Fork behavior -> select To contribute to the parent repository
    ![repo menu](images/repository-settings-menu.png)
    ![repo-settings](images/repository-fork-settings.png)


3. Fetch origin
    - ![fetch origin](images/fetch-origin.png)

4. Create a branch 
    - You should create branch for each **3 tasks**.
    - The branch should be created from the master branch of the original repository. In this way you will always have the latest changes .
    - [About branches.](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/about-branches)
    - [How to create branch.](https://docs.github.com/en/desktop/contributing-and-collaborating-using-github-desktop/making-changes-in-a-branch/managing-branches#creating-a-branch)

4. Add a solution for a task
    - Create a cpp file for each task.
    - **The name of the file should be TaskXX.cpp where XX is the number of the task**<br> e.g. Task01.cpp, Task12.cpp etc. 
    - Copy your solution into the file.

5. Commit solution to a task
    - Commit the file for the task.
    - **Each task should be in seperate commit.**
    - Repeat step 5. and 6. until you have 3 tasks in the new branch. <br />
      Then create a new branch and start from step 4.
    - [About commits.](https://docs.github.com/en/desktop/contributing-and-collaborating-using-github-desktop/making-changes-in-a-branch/committing-and-reviewing-changes-to-your-project#about-commits)

7. Open PR to the original repository to the master branch
    - [How to create pull request.](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/creating-a-pull-request)
    - The pull request should request to merge the changes of your branch in the fork to the master branch of the original repositor.
    - **The title of the Pull Request should be:**
        ```
        Pract.\<number\>: Add \<first task number\> - \<last task number\> | \<name\>
        
        Example:
        Pract.03: Add 01-03 | John Doe
        ```
    - **The description of the pull Request should be**
        ```
        \<name\> \<lastname\>
        \<major\> \<group\> \<fn\>

        Example:
        John Doe 
        SI 2 2MI0600192
        ```


| :boom: **DANGER**|
|:-----------------|
| ***If a pull request has more than 3 tasks or the title or description are not in the format described above, the PR will be rejected and will not be reviewed.***|
