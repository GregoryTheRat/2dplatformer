#ifndef SOUND_H
#define SOUND_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

class Sound
{
public:
    static void Init();
    static void StartBgMusic();
    static void PlaySoundEffect(const std::string& name);
    static void CleanUp(); 
private:
    static void LoadSoundEffect(const std::string& name, const std::string& filePath);

};
#endif