#ifndef MAIN_H
#define MAIN_H
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/*Change Directory*/
int changedirectory(char *path);

/*Processes*/
void null_command(char *buff);
void _envout(char *buff, char **env, char **commands);
void _clonse(char *buff, char **commands);
void _freebuffcom(char *buff, char **commands);
void _createpath(char **commands, char *buff, char **env, char **arguv, int counter);

/*String Tokens*/
unsigned int _lookupcommandlength(char *f);
char **_strtokarray(char *str);

/*Exceptions*/
int _putexception(char e);
void _buildexceptmessage(char **arguv, char *_firstcommand, int counter);
void _forkfail(void);

/*Memory Release*/
void free_double_pointer(char **_doubleptr);

/*Environment and Path*/
unsigned int _finddirect(char *pth);
char *cpy_pthmd(char *loc, char *frm, char *command, int _loclen, int _commandlen);
char **_keepenvvariables(char *_firstcommand, char **env_var);
void prntenvvar(char **_userenvvar);
char *get_env_varible(const char *_envname, char **env_var);


/*Supporting Functions*/
unsigned int _strlenfinder(char *_stri);
char *stringcopyconstant(char *_source, const char *dest, int _len);
unsigned int _conststrlen(const char *_strlname);
int string_compare(char *_string1, char *_string2);
char *_strncopier(char *_source, char *_dest, int _len);
char *stringcopyconstant(char *_source, const char *dest, int _len);


/* Signals */
void _signalhandler(int sig_nal);
int changedirectory(char *path);
void _endof(char *buff);

#endif
