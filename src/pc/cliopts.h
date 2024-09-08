#ifndef _CLIOPTS_H
#define _CLIOPTS_H

#include "platform.h"
#include "pc/configfile.h"

enum NetworkType {
    NT_NONE,
    NT_SERVER,
    NT_CLIENT
};

#define IP_MAX_LEN 32
#define PORT_MAX_LEN 16

struct PCCLIOptions  {
    unsigned int SkipIntro;
    unsigned int FullScreen;
    enum NetworkType Network;
    char JoinIp[IP_MAX_LEN];
    unsigned int NetworkPort;
    unsigned int PoolSize;
    char ConfigFile[SYS_MAX_PATH];
    char SavePath[SYS_MAX_PATH];
    char GameDir[SYS_MAX_PATH];
    char PlayerName[MAX_PLAYER_STRING];
};

extern struct PCCLIOptions gCLIOpts;

bool parse_cli_opts(int argc, char* argv[]);

#endif // _CLIOPTS_H
