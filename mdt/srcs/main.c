#include "./main.h"

// void    parsing_cmd(t_data *data)
// {
//      tokeniser chaque node de t_list_cmd
//       stocker dans t_list_split_cmd
//      ----> t_lexer
// }

void	check_env(char *dollar, t_data *data)
{
	int	i;
	i = 0;
	while (data->envp[i])
	{
		if (ft_strncmp(data->envp[i], dollar, ft_strlen(dollar)) == 0)
		{
			free(dollar);
			data
		}
		
		/* code */
	}
	
}

void    lexer(t_data *data)
{
	int	i;
	int	start;

	start = 0;
	i = 0;
	//  chequer les dollars et "" 
	while (data->entry[i])
	{
		if (data->entry[i] == '$')
		{	
			while (data->entry[i] != ' ' && data->entry[i])
			{
				i++;
				start++;
			}
			char *add_dollar;
			add_dollar = ft_substr(data->entry, i - start + 1, start);
			check_env(add_dollar, data);
			printf("New env => %s\n", add_dollar);
		}
		if (!data->entry[i])
			i++;
		/* code */
	}
	
	// while (/* condition */)
	// {
		// /* code */
	// }
	
	

	// split en fonction des pipes
// --> on a modifie t_list_cmd
	//    parsing_cmd(data);
}



void    init_data(char **envp, t_data *data)
{
	data->envp = envp;
	data->entry = NULL;
	data->env = NULL;
	data->cmd = NULL;
}

int display_prompt(t_data *data)
{
	while(1)
	{
		data->entry = readline("Minishell>");
		add_history(data->entry);
		lexer(data);
		// printf("test %s\n",entry);
		// if ((ft_strcmp(entry),"exit") == 0)
		// {
			// free(entry);
			// break;        
		// }
		free(data->entry);
		//sortie (se referer a data)
	}
	return (0);
}

int main(int ac, char **av, char **envp)
{
	t_data  data;

	init_data(envp, &data);
	display_prompt(&data);
	(void) av;
	(void) ac;
	(void) envp;
 //   lexer(av);
	return (0);
}
// int	add_cmd_node(t_data *data)
// {
// 	t_list_cmd	*node;

// 	if (data->lst_cmd == NULL)
// 	{
// 		data->lst_cmd = ft_lstnew_cmd(*data->lst_alloc);
// 		if (data->lst_cmd == NULL)
// 			exit_error(data, "Memory allocation issue");
// 		data->lst_cmd->validity = 1;
// 	}
// 	else
// 	{
// 		node = ft_lstnew_cmd(*data->lst_alloc);
// 		if (node == NULL)
// 			exit_error(data, "Memory allocation issue");
// 		node->validity = 1;
// 		ft_lstadd_back_cmd(&(data->lst_cmd), node);
// 	}
// 	return (0);
// }