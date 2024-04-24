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



struct s_list_cmd
{
    char    *cmd;
    char    **cmd_options;
    int     *fd;
    struct s_list_cmd *next;
}   t_list_cmd;
