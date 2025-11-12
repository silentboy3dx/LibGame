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



## Asset path and Data Path

You have to set the LIBGAME_ASSET_PATH environment variable this will link 
to the game folder the library uses. You can find the asset repository here: [https://github.com/silentboy3dx/sparkle-assets](https://github.com/silentboy3dx/sparkle-assets)

The moderation module writes data to a json file. You can set the LIBGAME_DATA_PATH environment variable to change the path.

```bash
git clone https://github.com/silentboy3dx/sparkle-assets.git assets
cd assets
echo "export LIBGAME_ASSET_PATH=$PWD" >> ~/.bashrc
echo "export LIBGAME_DATA_PATH=/home/silentboy/documents/sparklebeat/data" >> ~/.bashrc
```

****Replace .bashrc with .zshrc if you are using zsh.****


## License

MIT License

Copyright (c) 2025

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
