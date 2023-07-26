#ifndef SHELL
#define SHELL

/* Standard Library*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <signal.h>
extern char **environ;

/* environment variable */


extern int outside_var;
#define ARRAY_SIZE 10
#define INCREASE_RATE 2
#define STARTING_BUFFER 1024



/* Struct*/ 

/**
 * * funct_built - handling builtin function
 * * @command: accpeting user command
 * * @func_fix: handling builtin command
 * */
typedef struct funct_built
{
	    const char *command;
	        void (*func_fix)(char **);
} funct_built;

/* Dealing with the user pressing control + c*/
void handling_signal_for_user(int _user_signal);
void _pound_handler_for_2_marks(char *_usr_args[], int n, int _id);

/* Practice.c */
void _func_direct(char **_own_args, int i);
void _func_direct_two(char **_own_args, int i);
void _func_direct_three(char **_own_args, int i);
int _args_handler(char **_own_args);

/* Important_func.c*/
int _arguments_handler(char **_arguments);
int _is_exit_function(char **_arguments);

/* Handling_string.c */
void from_integer_string(int _user_input, char _string_for_num[]);

/* Handling_arr.c */
void _free_up_arr(char **_str_array);
int _function_built_in(char **_arugments);
void _pound_handler(char *_user_args[], int n, int _id);
void pound_handler_for_2_dollars(char *_usr_args[], int n, int _id);
void _pound_handler_for_2_marks(char *_usr_args[], int n, int _id);

/* Handling_arguments.c */
void _own_string_trimmer(char *_string);
int _func_mult_cmd(char *_cmd_user);

/* Func_ness.c */
int num_of_iter(const char *_user_cmd, char *_delimeter);
char **_remains_arr(char *_usr_cmd, char *_delimeter);

/* Execute_args.c */
int _exec_cmd(char *_cmd_user);

/* Built_func.c*/
void deal_with_exit(int arg_count, char *arguments[], int cmd_num);


void deal_with_envir_var();
extern char **environ; 
int funct_inside(char **_user_cmd);

/* shell.h */
void handling_for_ctrl_c(int signal);
int main(int argc, char **argv, char **environ);

/* pratice.c */
ssize_t _implement_get_line(char **_user_line, size_t *_actual_sz, FILE *input_stream);
void _release_for_buf(char *_handling_buf);
void _initializing_for_buf(char **_handling_buf, size_t *_handling_buf_size);
ssize_t read_and_adjust_buffer(char **adjusted_buf, size_t *adjusted_buf_size, FILE *data_stream);


/* string_func */
void cpy_string_to_an_arr(char ***_handler_for_des, char **_handler_for_src);

/* getenv_func. */
char *_get_env_var(char *target_name);

/* string_func.c*/
size_t _handler_for_length(const char *_user_str);
char *_str_con_canc(char *_str_a, char *_str_b);
char *func_for_str_copy(char *u, char *v);
int func_for_str_cmp(const char *u, const char *x);

/* string_tokenizer.c */
void *func_for_realloc(void *_str_input, size_t _rem_size, size_t _new_input);
void func_for_mem_cpy(void *old_alloc, void *where, size_t n);
void *func_for_mem_set(void *new_string, int z, size_t n);

#endif
