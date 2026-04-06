# Windows Build Tutorial (CLion + Visual Studio + vcpkg) — LibGame

LibGame heeft één externe dependency (OpenCV) en linkt met meerdere interne SparkleLibs:
- LibIO
- LibOS
- LibScreenshots
- LibGraphics

BELANGRIJK:
De installatieprocedures voor deze libraries moeten volledig afgerond zijn
voordat LibGame succesvol kan worden gebouwd.

Locatie van deze library:
C:\Users\jmast\CLionProjects\sparklelibs\sparklelibs\LibGame

------------------------------------------------------------
1. Installeer Visual Studio 2022 Community
------------------------------------------------------------

Open de Visual Studio Installer en vink slechts één workload aan:

    ✔ Desktop development with C++

Dit installeert automatisch:

- MSVC v143 compiler
- Windows SDK (10 of 11)
- CMake tools
- NMake Makefiles
- Visual Studio generator

------------------------------------------------------------
2. Installeer vcpkg
------------------------------------------------------------

    git clone https://github.com/microsoft/vcpkg
    cd vcpkg
    bootstrap-vcpkg.bat

Installeer OpenCV:

    vcpkg install opencv:x64-windows

------------------------------------------------------------
3. Zorg dat alle afhankelijkheden al geïnstalleerd zijn
------------------------------------------------------------

LibGame linkt met:

- LibIO
- LibOS
- LibScreenshots
- LibGraphics

Volg eerst de Windows build tutorials van deze libraries.
Pas wanneer deze succesvol geïnstalleerd zijn, kun je LibGame bouwen.

------------------------------------------------------------
4. Configureer CLion Toolchain
------------------------------------------------------------

Ga naar:

    File → Settings → Build, Execution, Deployment → Toolchains

Selecteer:

- Toolchain: Visual Studio
- C Compiler: cl.exe
- C++ Compiler: cl.exe
- Debugger: bundled

Gebruik GEEN Ninja generator — dit veroorzaakt problemen op Windows.

------------------------------------------------------------
5. Configureer CMake in CLion
------------------------------------------------------------

Ga naar:

    Settings → Build, Execution, Deployment → CMake

Stel in:

- Generator: Visual Studio 17 2022
- Toolchain: Visual Studio
- CMake options:

      -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake

------------------------------------------------------------
6. Verwijder oude build-mappen
------------------------------------------------------------

Verwijder:

    cmake-build-debug/
    cmake-build-release/
    cmake-build-debug-visual-studio/
    build/

------------------------------------------------------------
7. Builden
------------------------------------------------------------

Klik:

- Reload CMake Project
- Build

Je krijgt:

- ✔ OpenCV gevonden via vcpkg
- ✔ MSVC toolchain gevonden
- ✔ Windows SDK gevonden
- ✔ Alle SparkleLibs dependencies gevonden
- ✔ LibGame.dll gebouwd

------------------------------------------------------------
8. Install (Als Administrator)
------------------------------------------------------------

Ga naar de CLion build-map:

    cd LibGame/cmake-build-debug-visual-studio

Voer uit:

    cmake --install . --prefix "C:/Program Files/LibGame"

Dit installeert:

- C:/Program Files/LibGame/bin/LibGame.dll
- C:/Program Files/LibGame/lib/LibGame.lib
- C:/Program Files/LibGame/include/LibGame/...
- C:/Program Files/LibGame/lib/cmake/LibGame/LibGameConfig.cmake

------------------------------------------------------------
Klaar
------------------------------------------------------------

LibGame vereist:
- OpenCV via vcpkg
- Alle SparkleLibs dependencies moeten vooraf geïnstalleerd zijn
- Visual Studio generator
- MSVC v143
- Windows SDK

Wanneer deze voorwaarden zijn voldaan, bouwt LibGame zonder problemen.
