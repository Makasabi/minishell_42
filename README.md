# Minishell
A 42 Paris project

![main_img](https://github.com/Makasabi/minishell_42/assets/114622980/2dc3bb9a-04a2-4f2c-b738-fb223311c24c)

## Subject
Minishell is a level 03 project at 42 Paris and an emblematic exercice for any computer science student.

The subject is pretty straightforward : Recode a (limited version) POSIX Shell in C.

The scope is fully 'functionnal' as we were not required to code any graphic interface (opening a new windo, etc) but 'only'interpret and execute the instruction(s) given in the prompt line `➜  Minishe·elle `.
The `./minishell` program is able to run most of the basic instructions a shell can handle, such as echo, ls, cat, cd, mkdir... and even run other executable such prevous 42 projects (think push_swap, fdf, etc).
A set of basic commands also have to be recoded inside our program as to be able to run basic instruction even when `./minishell` is lauched without any environment vairbales (but will get on that later on).
if you have any questions - shoot us an email or ping us on Discord, we'll be happy to help!
 
## Wonderwomen

Minishell is the first group project (within the common core curiculum of 42), which has to be done in pairs. The point of working on a group project is to emulate real life work - where wel'll have to work on projects with bigger scopes and where we will have to review code or get our own code reviewed. Which is why, when working with one or several persons, knowing exactly each other's scope is key to avoid any overlaping or redundancy. Another key learning point was the use of git (branching, merging, etc). By the way, the first thing we did was a [git crash course](https://learngitbranching.js.org/?locale=en).

I was very happy Tiffany asked me to become her Minishell mate! We were lucky enough to be coding in a very similar way so working together and reviewing eachother's code was a breeze! Our respecive professionnal experience was also an asset for us as we apprehended this big piece of a project from a macro perspective first. And on a more personnal level - we became really good friends. So thank you Tiffany !

**We divided the project in roughly 2 main chunks : parsing and execution**

|**[Tiffany](https://github.com/ImJustWan)**|**[Marie](https://github.com/Makasabi)**|
|---|---|
|Prompt|Environment variables|
|Parsing (Token, Lexer, Expansion, Binary tree)|Builtins|
|Pseudo Heredoc|Execution (simple and compplex commands)|
|Signal handling|Exit Status|

____

## Project's Architecture

As mentionned previously, we apprehended this project from a macro perspective. 
We started by creaing a general workflow for our project, hence avoiding any redundancy in our code but also to anticipate the type of data we'd be sending from the parsing phase to the execution phase.

- Parsing
This section starts at the command line which is entered after the prompt `➜  Minishe·elle `.
At this point it is a mere string of characters, and it becomes a glorious binary (or 'syntax') tree.
- Execution
This bit will use all the formated data of the tree to execute every single commands and redirections.

Here is a global representation of the general structure of our code : 
![Minishell_Archi](https://github.com/Makasabi/minishell_42/assets/114622980/0bc6015f-d4bd-410f-90be-9861136db674)
You can see it in extendive details [here](https://miro.com/app/board/uXjVM2vuNQE=/?share_link_id=828445432809).

## Key Learning Points

1. Readling - Collecting instructions from prompt line
2. Parsing
   	1. Lexer - divide command sting in tokens
   	2. Expander - Replace variables with their value
   	3. Parser - analyse tokens and store them in nodes
   	4. Pseudo Heredoc - 
   	5. Tree builder - organise nodes in a logical way
3. Signals handling
4. Environment variables
5. Execution
   	1. Builtins
   	2. Running binary executable form minishell
   	3. Piped commands
   	4. Redirections
   	5. Paths and Access rights
   	6. Exit status
6. External Ressources 
 
Sujet :
https://cdn.intra.42.fr/pdf/pdf/90159/fr.subject.pdf

Google doc:
https://docs.google.com/document/d/1c7IVm0a13f6dmQzApheV4Y5r8KLZjx6FE1nGeYV0tWI/edit?usp=sharing

Documentation
https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf

Git Branching
https://learngitbranching.js.org/?locale=fr_FR

git branch <nom de la branche> => Pour creer une nouvelle branhce
git checkout <nom de la branche> => Pour se pocitionner dans cette branche specifiquement
git merge <nom de la branche> => merge deux commit de deux branches ensemble
git checkout <nom de la branche> | git merge main => merge le contenu de main dans le nom de la branche dans laquelle on se trouve
git rebase =>
git checkout HEAD~4 => remonte HEAD au 4eme parent.
git branch -f main HEAD~3 => bouge (de force : -f) la branche main à trois parents derrière HEAD.
git branch -f <branche d'origine> <branche de destination> => permet de forcer l'emplacement d'une branche
git cherry-pick <commit#> .... <commit #> => On choisi les commit a inclure dans la branche dans laquelle on se trouve actuellement
git rebase -i <where I want to reorganise my commit from>
git commit --amend => Petite modification sur un commit existant (C2 devent C2')
git tag "nom du tag" <commit> => on pointe vers une milestone a laquelle on pourra se referer plus tard. On l'utilise par exemple pour referer a une version du programme
git describe => decrit le statut de chque commit avec ses tag


GIT REMOTE
git clone => clone le repo sur notre machine locale avec la meme tructure de commit et de branches
git fetch => reccupere les commit et branches presentes dans le git distant mais pas dans le notre
			-> The key difference between git fetch and pull is that git pull copies changes from a remote repository directly into your working directory, while git fetch does not. The git fetch command only copies changes into your local Git repo. The git pull command does both.
git checkout -b totallyNotMain o/main => Cette commande crée une nouvelle branche nommée totallyNotMain et la configure pour suivre o/main.
git branch -u o/main foo =>
git push origin <source>:<destination> =>
git fetch origin <source>:<destination> =>
git pull origin <source>:<destination> = git fetch origin <source>:<destination> ; git merge <destination>

My_env usage:
-> use pointer to address of 2D array (***)"my env" for all functions that may alter it's content (variables).
-> For read only function, simple pointer to 2D array (**) can be used.
