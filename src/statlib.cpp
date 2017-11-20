#include "../include/SDL_version.h"
#include <cstdio>
#include <cstdlib>

int main(int /*argn*/, char* /*args*/ [])
{
    SDL_version sdl_v = { 0, 0, 0 };
    SDL_GetVersion(&sdl_v);
    const char* msgTmp = "We use static lnk SDL lib version %d.%d.%d";
    std::printf(msgTmp,
        sdl_v.major,
        sdl_v.minor,
        sdl_v.patch);
    return EXIT_SUCCESS;
}
