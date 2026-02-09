
# Cub3D

<div align="center">

![Demo](imgs/visual.gif)

**A 3D maze exploration game inspired by Wolfenstein 3D**


</div>


## 📖 About

**cub3D** is a raycasting-based 3D game engine project from 42 School's curriculum. This project is an introduction to raycasting techniques, creating a realistic 3D perspective in a 2D game environment, similar to the classic game Wolfenstein 3D.

The player navigates through a maze from a first-person perspective, with textured walls, floor and ceiling colors, and smooth movements and rotations.


## 🎮 Features

- **Raycasting Engine**: Real-time 3D rendering using raycasting algorithms
- **Textured Walls**: Different textures for each cardinal direction (North, South, East, West)
- **Custom Colors**: Configurable floor and ceiling RGB colors
- **Smooth Movement**: WASD keyboard controls for navigation
- **Rotation**: Arrow keys or mouse for camera rotation
- **Map Parsing**: Custom `.cub` file format for level configuration
- **Error Handling**: Comprehensive map validation and error messages


## 🛠️ Installation

### Prerequisites

- **GCC** or compatible C compiler
- **Make**
- **X11** libraries (Linux)

### Clone and Build

```bash
# Clone the repository
git clone https://github.com/noanjrd/42_cub3D.git
cd 42_cub3D

# Build the project
make

# Run with a map
./cub3D maps/map.cub
```

The Makefile will automatically clone and build the MiniLibX library if not present.


## 🎯 Usage

```bash
./cub3D <map_file.cub>
```

### Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` | Rotate camera left |
| `→` | Rotate camera right |
| `ESC` | Exit game |

### Mouse Controls

- **Mouse movement**: Rotate camera (horizontal)


## 🗺️ Map Configuration

Maps are defined in `.cub` files with the following format:

### Texture Paths

```
NO ./assets/north.xpm
SO ./assets/south.xpm
WE ./assets/west.xpm
EA ./assets/east.xpm
```

### Colors (RGB format)

```
F 255,253,85    # Floor color
C 105,201,249   # Ceiling color
```

### Map Layout

- `1` - Wall
- `0` - Empty space
- `N` / `S` / `E` / `W` - Player starting position and orientation

**Example:**

```
1111111111111111111111111
1000000000110000000000001
1011000001110000000N00001
1001000000000000000000001
1111111111111111111111111
```

### Map Rules

- Map must be surrounded by walls (`1`)
- Only one player start position allowed
- Valid characters: `0`, `1`, `N`, `S`, `E`, `W`, and spaces
- Map must be closed (no gaps in walls)


## 📁 Project Structure

```
cub3D/
├── include/
│   └── cub3D.h              # Main header file
├── srcs/
│   ├── main.c               # Entry point
│   ├── exec/                # Game execution and rendering
│   ├── parsing/             # Map and configuration parsing
│   └── utils/               # Utility functions
├── maps/                    # Map files (.cub)
├── assets/                  # Texture files (.xpm)
├── Makefile
└── README.md
```


## 🔧 Compilation Flags

The project compiles with strict flags:

```bash
-Wall -Wextra -Werror
```

For debugging, uncomment the sanitizer flag in the Makefile:

```makefile
FLAGS = -g3 -Wall -Wextra -Werror -fsanitize=address,leak
```

## 🧮 Algorithm Overview

### Raycasting

The raycasting algorithm works by:

1. **Ray projection**: For each vertical stripe on the screen, cast a ray from the player
2. **DDA algorithm**: Use Digital Differential Analysis to find wall intersections
3. **Distance calculation**: Calculate perpendicular distance to avoid fish-eye effect
4. **Wall height**: Calculate wall slice height based on distance
5. **Texture mapping**: Map appropriate texture slice to the wall
6. **Rendering**: Draw the vertical stripe with proper texture and colors


## 🐛 Error Handling

The program validates:

- File extension (`.cub`)
- File accessibility
- Texture file existence
- RGB color format (0-255)
- Map closure (surrounded by walls)
- Single player position
- Valid map characters
- No duplicated configuration parameters

## 📝 Makefile Commands

| Command | Description |
|---------|-------------|
| `make` | Compile the project |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and executable |
| `make re` | Recompile the project |


## 🎓 Learning Outcomes

This project teaches:

- **Graphics programming**: Understanding of 2D to 3D projection
- **Raycasting algorithms**: Implementation of classic game rendering techniques
- **Performance optimization**: Efficient rendering and calculation
- **Memory management**: Proper allocation and deallocation in C
- **Event handling**: Keyboard and mouse input processing
- **File parsing**: Configuration file reading and validation


## 👥 Authors

- **JARD Noan** - [@noanjrd](https://github.com/noanjrd)
- **PINGUET Macéo** - [@mpinguet](https://github.com/mpinguet)


## 📄 License

This project is part of the 42 School curriculum and follows the school's academic policies.

