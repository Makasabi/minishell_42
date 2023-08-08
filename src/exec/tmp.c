// void	ft_extract_rdr(t_minishit *hell, t_node **tree)
// {
// 	if ((*tree)->type == pip)
// 	{
// 		ft_extract_rdr(hell, &(*tree)->left);
// 		ft_extract_rdr(hell, &(*tree)->right);
// 	}
// 	else if ((*tree)->type == cmd)
// 	{
// 		if ((*tree)->left)
// 			ft_extract_rdr(hell, &(*tree)->left);
// 	}
// 	else if ((*tree)->type == rdr)
// 	{
// 		ft_check_rdr(hell, (*tree));
// 		if ((*tree)->left)
// 			ft_extract_rdr(hell, &(*tree)->left);
// 	}
// }




	// ft_extract_rdr(hell, tree);
	
	/*
	1. check for redirections : All file creation are done BEFORE executing any cmd/builtin
	2. extract command from binary tree
	3. check for single-command builtin prompt OR execve/piped prompt
	4. 
		4.a single-command builtin -> launch command
		4.b fork -> check for built-in -> execve or call on builtin function
	


	ifconfig < option  | grep "ether " | cut -d ' ' -f 10 > address
	*/



/* 
REDIR TESTS
	bash-5.1$  cat < infile > gibier < tiffany | echo > outfile > marie > rony
	bash: infile: No such file or directory
	file created : outfile; marie; rony
	NONE of the redir of cat are done -> gibier is not created !!!
	

cat < infile | echo > outfile
ifconfig < option  | grep "ether " | cut -d ' ' -f 10 > address 



Redirection check should only be for access rights. 
File creation should be done upon execution.

To recode this bit
if empty + in_out_put = 0 (readfrom || heredoc) = check for permission if file exists only. If error - stop redir checks ( return error message).
if empty + in_out_put = 1 (= writeto || append) = if file does not exists create or Trunc file / if file exists already : check for access rights. If error - stop redir checks ( return error message)
if readfrom = check if file exists and is accessible. if error : stop redir check alltogether.
if append = check if file exists and is accessible. (create file upon exec)
if writeto = check if file exists and is accessible. (creat file upon exec)
if heredoc = open here_doc.
*/

