<p align="center">
    <img src="assets/sparklebeat.png" width="250"  height="250" alt="Picture of DJ SparkleBeat" />
</p>

# SparkleBeat Game Interaction Code

LibGame allows SparkleBeat to interact with the 3DXChat game world. You are free to use it for your self, it has a pretty easy api to use.
The current version is NOT a library yet but this will soon change once all the basic bugs are fixed (see [issues](https://github.com/silentboy3dx/LibGame/issues))

```C++
#include "LibGame/LibGame.hpp"

using namespace LibGame::Module;

int main() {

    auto &interactions = LibGame::Interactions::GetInstance();
    interactions.GetInteraction<Dances>().Dance(12);

    return 0;
}
```
# LibGame


## Asset path

You have to set the LIBGAME_ASSET_PATH environment variable this will link 
to the game folder the library uses. You can find the asset repository here: [https://github.com/silentboy3dx/sparkle-assets](https://github.com/silentboy3dx/sparkle-assets)



```cmake

```

## Needing implementation in 3th party libraries
