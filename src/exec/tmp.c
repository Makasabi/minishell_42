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
