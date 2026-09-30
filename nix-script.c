// create failsafe for making and moving folders // example at end , create
// functions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
// 77//================== Declerations ===================

char USER[] = "coffee"; // username //must be same here and configuration.nix
char PATH[30];
char command[500];
char folder_name[50] = "NULL";
char file_name[50] = "NULL";

int main(int argc, char *argv[])
{

  snprintf(PATH, sizeof(PATH), "/home/%s", USER);
  (void)argc;
  if (argv[1] == NULL)
  {
    argv[1] = argv[0];
  }
  // 77// ================= Last Stand =====================

  if (strcmp(argv[1], "--execute") != 0)
  {
    fprintf(stderr, "\n usage :  %s  [--execute] to execute\n  ", argv[0]);
    fprintf(stderr, "\n usage : Run as [ root ]  ");
    fprintf(stderr, "\n must have : git  ");
    exit(1);
  }

  // 77// ================= Execution  =====================
  printf("\n\n ==== Begin Execution =====\n  ");

  strcpy(folder_name, "nixos-dotfiles");
  snprintf(
      command, sizeof(command),
      "cd %s && mkdir %s && cd %s &&"
      " git clone https : // github.com/muhammadhafeez77/Nixos-Flakes.git ",
      PATH, folder_name, folder_name);
  system(command);

  snprintf(command, sizeof(command),
           "cd .. && mkdir Pictures && cd - && "
           "cp castle.jpg alena-aenami-dreamy-1k.jpg %s/Pictures && "
           "cd %s/.config && mkdir qtile nvim picom oxwm alacritty tmux ",
           PATH, PATH);
  system(command);

  snprintf(command, sizeof(command),
           "cp /etc/nixos/hardware-configuration.nix %s/%s && "
           "rm -rf /etc/nixos "
           "&& cp -r %s/%s /etc/nixos",
           PATH, folder_name, PATH, folder_name);
  system(command);

  printf("\n");
  return 0;
}
// snprintf(command,sizeof(command), "mkdir %s && cd %s && touch
// %s",folder_name,folder_name,file_name); system(command);
// // ==========================================
//    // 1. Variable-based Dynamic CD (chdir)
//    // ==========================================
//    // Equivalent to: cd /home/user/.config
//    snprintf(path_buffer, sizeof(path_buffer), "%s/.config", PATH);
//
//    if (chdir(path_buffer) == 0) {
//        printf("Successfully moved to: %s\n", path_buffer);
//    } else {
//        perror("Failed to change directory"); // Prints the exact error if it
//        fails
//    }
//
//    // ==========================================
//    // 2. Variable-based Dynamic MKDIR
//    // ==========================================
//    // Equivalent to: mkdir /home/user/nixos-config
//    snprintf(path_buffer, sizeof(path_buffer), "%s/%s", PATH, folder_name);
//
//    // 0755 represents standard Linux directory read/write/execute permissions
//    if (mkdir(path_buffer, 0755) == 0) {
//        printf("Successfully created folder: %s\n", path_buffer);
//    } else {
//        perror("Failed to create directory");
//    }
