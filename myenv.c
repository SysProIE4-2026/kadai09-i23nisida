/*
 *  myenv.c : env コマンドのクローン
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;


int main(int argc , char *argv[], char *envp[]) {
    for (int i=1; argv[i]!=NULL; i++){
        if (putenv(argv[i])!=0) {
            execvp(argv[i], &argv[i]);
            perror(argv[i]);
            return 1;
        }
    }
    for (int i=0; environ[i]!=NULL; i++){
        printf("%s\n", environ[i]);
    }
    return 0;
}

/* 実行例

k.nishida@nishidakaedenoMacBook-Air kadai09-i23nisida % ./myenv printenv LANG
ja_JP.UTF-8
k.nishida@nishidakaedenoMacBook-Air kadai09-i23nisida % ./myenv LANG=C printenv LANG
C
k.nishida@nishidakaedenoMacBook-Air kadai09-i23nisida % date
2026年 7月 2日 木曜日 20時26分33秒 JST
k.nishida@nishidakaedenoMacBook-Air kadai09-i23nisida % ./myenv LC_TIME=ja_JP.UTF-8 TZ=GMT date
2026年 7月 2日 木曜日 11時29分30秒 GMT
k.nishida@nishidakaedenoMacBook-Air kadai09-i23nisida % ls -l myenv.c
-rw-r--r--  1 k.nishida  staff  515  7月  2 20:25 myenv.c
k.nishida@nishidakaedenoMacBook-Air kadai09-i23nisida % ./myenv LC_TIME=ja_JP.UTF-8 TZ=GMT ls -l myenv.c
-rw-r--r--  1 k.nishida  staff  515  7月  2 11:25 myenv.c
k.nishida@nishidakaedenoMacBook-Air kadai09-i23nisida % ./myenv LC_TIME=ja_JP.UTF-8 TZ=GMT              
OSLogRateLimit=64
MallocNanoZone=0
USER=k.nishida
COMMAND_MODE=unix2003
__CFBundleIdentifier=com.microsoft.VSCode
PATH=/Users/k.nishida/Library/Application Support/Code/User/globalStorage/github.copilot-chat/debugCommand:/Users/k.nishida/Library/Application Support/Code/User/globalStorage/github.copilot-chat/copilotCli:/opt/homebrew/bin:/opt/homebrew/sbin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/opt/pkg/env/active/bin:/opt/pmk/env/global/bin:/Users/k.nishida/Library/Application Support/Code/User/globalStorage/github.copilot-chat/debugCommand:/Users/k.nishida/Library/Application Support/Code/User/globalStorage/github.copilot-chat/copilotCli
LOGNAME=k.nishida
SSH_AUTH_SOCK=/var/run/com.apple.launchd.jTF8aIRpQ6/Listeners
HOME=/Users/k.nishida
SHELL=/bin/zsh
TMPDIR=/var/folders/f8/hfc7k6916r5gg5nmf74_8y7w0000gn/T/
__CF_USER_TEXT_ENCODING=0x1F5:0x1:0xE
XPC_SERVICE_NAME=0
XPC_FLAGS=0x0
PWD=/Users/k.nishida/Documents/s/Syspro2/kadai09-i23nisida
HOMEBREW_PREFIX=/opt/homebrew
INFOPATH=/opt/homebrew/share/info:/opt/homebrew/share/info:
LANG=ja_JP.UTF-8
TERM=xterm-256color
TERM_SESSION_ID=44BC2578-00C9-43FC-B7E5-D841CC9CB65F
TERM_PROGRAM_VERSION=1.117.0
HOMEBREW_REPOSITORY=/opt/homebrew
SHLVL=3
HOMEBREW_CELLAR=/opt/homebrew/Cellar
COLORTERM=truecolor
TERM_PROGRAM=vscode
GIT_ASKPASS=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass.sh
VSCODE_GIT_ASKPASS_NODE=/Applications/Visual Studio Code.app/Contents/Frameworks/Code Helper (Plugin).app/Contents/MacOS/Code Helper (Plugin)
VSCODE_GIT_ASKPASS_EXTRA_ARGS=
VSCODE_GIT_ASKPASS_MAIN=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass-main.js
VSCODE_GIT_IPC_HANDLE=/var/folders/f8/hfc7k6916r5gg5nmf74_8y7w0000gn/T/vscode-git-76a5159b36.sock
VSCODE_INJECTION=1
ZDOTDIR=/Users/k.nishida
USER_ZDOTDIR=/Users/k.nishida
OLDPWD=/Users/k.nishida/Documents/s/Syspro2/kadai09-i23nisida
VSCODE_PROFILE_INITIALIZED=1
VSCODE_PYTHON_AUTOACTIVATE_GUARD=1
VSCODE_LOGIN_INITIALIZED=1
_=/Users/k.nishida/Documents/s/Syspro2/kadai09-i23nisida/./myenv
LC_TIME=ja_JP.UTF-8
TZ=GMT
k.nishida@nishidakaedenoMacBook-Air kadai09-i23nisida % ./myenv LC_TIME=ja_JP.UTF-8 TZ=GMT a  
a: No such file or directory

*/
