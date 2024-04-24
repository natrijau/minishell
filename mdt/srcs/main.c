#include "./main.h"

void    parsing_cmd(t_data *data)
{
    //tokeniser chaque node de t_list_cmd
    // stocker dans t_list_split_cmd
    //----> t_lexer
}

// void    lexer(char *entry, t_data *data)
// {
//     //chequer les dollars et "" 
//     while (/* condition */)
//     {
//         /* code */
//     }
    
    

//     //split en fonction des pipes
//--> on a modifie t_list_cmd
//        parsing_cmd(data);
// }



void    init_data(char **envp, t_data *data)
{
    data->envp = envp;
    data->env = NULL;
    data->cmd = NULL;
}

int display_prompt(t_data *data)
{
    (void)data;
    char *entry;
    while(1)
    {
        entry = readline("Minishell>");
        add_history(entry);
        lexer(entry, data);
        printf("test %s\n",entry);
        // if ((ft_strcmp(entry),"exit") == 0)
        // {
            // free(entry);
            // break;        
        // }
        free(entry);
        //sortie (se referer a data)
    }
    return (0);
}

int main(int ac, char **av, char **envp)
{
    t_data  data;

    init_data(envp, &data);
    display_prompt(&data);
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