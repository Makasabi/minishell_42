# minishell_42

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

