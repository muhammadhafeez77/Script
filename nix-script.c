// create failsafe for making and moving folders , create functions
// make git repo for themes (fonts , icons )
// it is themes AT GIT_CONFIG run the rg (username ) to find instances of
// username and find command to turn them to user and vice verca . should
// include in this script

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
// 77//================== Declerations ===================

// change "coffee" to your username , must be same here and configuration.nix
// or any other config that has that username.
char PATH[] = "/home/coffee";
char END[] = "sudo chown -R coffee:coffee /home/coffee";

char command[500];
void cd(char path[sizeof(PATH) + 10]);
void killgit();

int main(int argc, char *argv[])
{

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
    exit(EXIT_FAILURE);
  }

  // 77// ================= Execution  =====================
  printf("\n\n\t ==== Begin Execution =====\n  ");

  cd(PATH);
  mkdir("Pictures", 0755);
  mkdir("Downloads", 0755);
  mkdir("Documents", 0755);
  snprintf(command, sizeof(command),
           " git clone https://github.com/muhammadhafeez77/Nixos-Flakes.git "
           "./nixos-dotfiles ");
  system(command);

  cd("nixos-dotfiles");
  killgit();
  system("cp castle.jpg alena-aenami-dreamy-1k.jpg ../Pictures/");
  system("rm castle.jpg alena-aenami-dreamy-1k.jpg ");
  snprintf(
      command, sizeof(command),
      "cp /etc/nixos/hardware-configuration.nix ./hardware-configuration.nix"
      " && rm /etc/nixos/ && cp -r %s/nixos-dotfiles /etc/nixos",
      PATH);
  system(command);

  cd(PATH);
  system("rm .vimrc");
  system("mkdir -p .config");
  cd(".config");

  printf("\n\n\t ===== INSTALLING CONFIGS =====\n\n");

  system("git clone https://github.com/muhammadhafeez77/Themes ./themes");
  cd("themes");
  killgit();
  system("mv gtk-3.0 Mousepad Thunar xfce4 ../");
  system("mv fonts /usr/share/fonts");
  system("mv themes /usr/share/themes");
  system("mv icons /usr/share/icons");

  system("git clone https://github.com/muhammadhafeez77/Qtile ./qtile");
  cd("qtile");
  killgit();
  cd("..");

  system("git clone https://github.com/muhammadhafeez77/Neovim ./nvim");
  cd("nvim");
  system("mv clang-format ../../.clang-format");
  system("mv vimrc ../../.vimrc");
  system("mv README.md CONFIG.md");
  killgit();
  system("mv CONFIG.md README.md");
  cd("..");

  system("git clone https://github.com/muhammadhafeez77/Picom ./picom");
  cd("picom");
  killgit();
  cd("..");

  system("git clone https://github.com/muhammadhafeez77/Oxwm ./oxwm");
  cd("oxwm");
  killgit();
  cd("..");

  system("git clone https://github.com/muhammadhafeez77/Alacritty ./alacritty");
  cd("alacritty");
  killgit();
  cd("..");

  system("git clone https://github.com/muhammadhafeez77/Tmux ./tmux");
  cd("tmux");
  killgit();

  cd(PATH);
  system("mv .bashrc ._backup__bashrc");
  system("mv .zshrc ._backup__zshrc");
  mkdir(".zsh-theme", 0755);

  cd("Documents");
  system("git clone https://github.com/muhammadhafeez77/Zshrc ./zsh");
  cd("zsh");
  killgit();

  system("mv dircolors /usr/bin/");
  system("mv bash-completion zsh-autosuggestions zsh-syntax-highlighting "
         "/usr/share/");
  system("mv bashrc ../../.bashrc");
  system("mv zshrc ../../.zshrc");
  system("mv xiong-chiamiov.zsh-theme ../../.zsh-theme/");
  cd("..");
  system("rm -rf zsh");

  cd("/root");
  system("mv .vimrc ._backup__vimrc ; mkdir -p .config");
  cd(".config");
  system("git clone https://github.com/muhammadhafeez77/Neovim ./nvim");
  cd("nvim");
  system("mv clang-format ../../.clang-format");
  system("mv vimrc ../../.vimrc");
  killgit();

  system(END);
  return EXIT_SUCCESS;
}

void cd(char local_path[sizeof(PATH) + 10])
{
  // local_path[strcspn(local_path, "\n")] == '\0';
  if (strlen(local_path) > 1)
  {
    snprintf(command, sizeof(command), "cd %s", local_path);
    system(command);
  }
  else
  {
    chdir("..");
  }
}
void killgit()
{
  system("rm -rf .git");
  system("rm .gitignore README.md");
}
