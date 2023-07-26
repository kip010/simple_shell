#include "shell.h"


/**
 * cd_builtin - Changes the current working directory of the process.
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */

int _mycd(info_t *info)
{
    char *dir;
    char buffer[READ_BUF_SIZE]; // Use READ_BUF_SIZE defined in shell.h
    int chdir_ret;

    // If no argument is given, change directory to the home directory
    if (info->argv[1] == NULL)
    {
        _puts(_getenv(info, "HOME=")), _putchar('\n');
        chdir_ret = chdir(_getenv(info, "HOME="));
    }
    else if (_strcmp(info->argv[1], "-") == 0)
    {
        // If the argument is "-", change directory to the previous working directory
        _puts(_getenv(info, "OLDPWD=")), _putchar('\n');
        chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
    }
    else
    {
        // Change directory to the provided argument
        chdir_ret = chdir(info->argv[1]);
    }

    if (chdir_ret == -1)
    {
        // If chdir returns -1 (error), print an error message
        print_error(info, "can't cd to ");
        _eputs(info->argv[1]), _eputchar('\n');
    }
    else
    {
        // Update environment variables PWD and OLDPWD
        _setenv(info, "OLDPWD", _getenv(info, "PWD="));
        _setenv(info, "PWD", getcwd(buffer, READ_BUF_SIZE));
    }

    return 0;
}

/**
 * _myhelp - Function to display help information.
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
    // Display a temporary message that the help function is not yet implemented
    char **arg_array;
    arg_array = info->argv;
    _puts("help call works. Function not yet implemented \n");

    if (0)
        _puts(*arg_array); // temp att_unused workaround

    return 0;
}

