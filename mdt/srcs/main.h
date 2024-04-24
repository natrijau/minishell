#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <curses.h>
#include <term.h>
#include <stdio.h>

//structure tokens
typedef enum lexer{
    WORD,
    PIPE,
    REDIRECTION,
    QUOTES,
    DOLLAR,
    FILES
}   t_lexer;

//parser --> enlever quotes et dollars + attribuer les tokens
typedef struct s_list_split_cmd
{
    char *word;
    t_lexer *lexer;
    struct s_list_split_cmd *next;
}   t_list_split_cmd;


//liste des commandes entre pipes
typedef struct s_list_cmd
{
    char    *cmd;
    char    **cmd_options;
    int     *fd;
    struct s_list_cmd *next;
}   t_list_cmd;

//liste pour la variable d'environement
typedef struct s_env
{
    char *var;
    struct s_env *next;
}   t_env;


// structure principale
typedef struct s_data
{
    char        **envp;
    t_env       *env;
    t_list_cmd  *cmd;
}   t_data;
