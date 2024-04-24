//structure tokens
struct enum lexer{
    WORD,
    PIPE,
    REDIRECTION,
    QUOTES,
    DOLLAR,
    FILES
}   t_lexer;

//parser --> enlever quotes et dollars + attribuer les tokens
struct s_list_split_cmd
{
    char *word;
    t_lexer *lexer;
    struct s_list_split_cmd;
}   t_list_plit_cmd;


//liste des commandes entre pipes
struct s_list_cmd
{
    char    *cmd;
    char    **cmd_options;
    int     *fd;
    struct s_list_cmd *next;
}   t_list_cmd;

//liste pour la variable d'environement
struct s_env
{
    char *var;
    struct s_env *next;
}   t_env;


// structure principale
struct s_data
{
    char        **env;
    char        **av;
    int         ac;
    t_env       *env;
    t_list_cmd  *cmd;
}   t_data;
