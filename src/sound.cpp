#include "sound.h"
#include <iostream>
#include <map>

static std::map<std::string, Mix_Chunk*> soundEffects;

void Sound::Init()
{
    // Initialize SDL2 audio subsystem
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return;
    }

    // Initialize SDL2_mixer with default settings
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Failed to initialize SDL_mixer: " << Mix_GetError() << std::endl;
        SDL_Quit();
        return;
    }

    LoadSoundEffect("jump", "../../assets/soundfx/jump.mp3");
    LoadSoundEffect("dash", "../../assets/soundfx/dash.wav");
}

void Sound::StartBgMusic()
{
    Mix_Music* music = Mix_LoadMUS("../../assets/music/background_music.ogg");
    if (!music) {
        std::cerr << "Failed to load music: " << Mix_GetError() << std::endl;
        Mix_CloseAudio();
        SDL_Quit();
    }

    // Play the music (loop indefinitely)
    Mix_VolumeMusic(2);
    Mix_PlayMusic(music, -1);
}

void Sound::LoadSoundEffect(const std::string& name, const std::string& filePath) {
    Mix_Chunk* sound = Mix_LoadWAV(filePath.c_str());
    if (!sound) {
        std::cerr << "Failed to load sound effect (" << filePath << "): " << Mix_GetError() << std::endl;
        return;
    }

    Mix_VolumeChunk(sound, 25);

    if (name == "dash")
    {
        Mix_VolumeChunk(sound, 3);
    }
    
    soundEffects[name] = sound;
}

void Sound::PlaySoundEffect(const std::string& name) {
    auto it = soundEffects.find(name);
    if (it == soundEffects.end()) {
        std::cerr << "Sound effect not found: " << name << std::endl;
        return;
    }

    Mix_PlayChannel(-1, it->second, 0); // Play on the first available channel, no looping
}

void Sound::CleanUp() {
    for (auto& pair : soundEffects) {
        Mix_FreeChunk(pair.second);
    }
    soundEffects.clear();

    Mix_CloseAudio();
    SDL_Quit();
}