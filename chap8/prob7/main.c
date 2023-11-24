#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[]) {
    int option;
    char *requested_env_var = NULL;
    extern char **environ;

    while ((option = getopt(argc, argv, "e:ugiip")) != -1) {
        switch (option) {
            case 'e':
                requested_env_var = optarg;
                if (requested_env_var != NULL) {
                    char *env_var_value = getenv(requested_env_var);
                    if (env_var_value != NULL) {
                        printf("%s=%s\n", requested_env_var, env_var_value);
                    } else {
                        printf("Error: Environment variable %s not found\n", requested_env_var);
                    }
                } else {
                    printf("Error: Option -e requires an argument\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case 'u':
                printf("My Real User ID: %d(%s)\n", getuid(), getpwuid(getuid())->pw_name);
                printf("My Effective User ID: %d(%s)\n", geteuid(), getpwuid(getuid())->pw_name);
                break;
            case 'g':
                printf("My Real Group ID: %d(%s)\n", getgid(), getpwuid(getuid())->pw_name);
                printf("My Effective Group ID: %d(%s)\n", getegid(), getpwuid(getuid())->pw_name);
                break;
            case 'i':
                printf("My Process ID: %d\n", getpid());
                break;
            case 'p':
                printf("My Parent's Process ID: %d\n", getppid());
                break;
            default:
                for (char **env = environ; *env != NULL; ++env) {
                    printf("%s\n", *env);
                }
        }
    }

    return 0;
}

