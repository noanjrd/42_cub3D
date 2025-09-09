<div align="center">
  <h1>🕹️ Cub3D</h1>
  <p>
    <em>A 3D game inspired by Wolfenstein 3D, built with the <strong>MiniLibX</strong> library.</em>
  </p>
</div>

<hr />

<h2>📖 About the project</h2>
<p>
  <strong>Cub3D</strong> is a project from the <a href="https://42.fr">42 School</a> curriculum.  
  The goal is to create a simple 3D game engine using raycasting, similar to early FPS games.  
  It provides a first-person view inside a maze, allowing the player to move around and interact with the world.
</p>

<h2>✨ Features</h2>
<ul>
  <li>Raycasting engine for 3D rendering</li>
  <li>Player movement and rotation</li>
  <li>Walls textured from .xpm images</li>
  <li>Keyboard input handling</li>
</ul>

<h2>⚙️ Installation</h2>
<pre>
git clone https://github.com/noanjrd/42_cub3D.git
cd cub3D
make
</pre>

<h2>▶️ Usage</h2>
<pre>
./cub3D path/to/map.cub
</pre>
<p>
  Example:
</p>
<pre>
./cub3D maps/map.cub
</pre>

<h2>🗺️ Map format</h2>
<p>
  The map is defined in a <code>.cub</code> file and must follow specific rules:
</p>
<ul>
  <li>North/South/East/West textures defined at the top</li>
  <li>Floor and ceiling colors (RGB)</li>
  <li>Closed map made of 1 (walls) and 0 (empty space)</li>
  <li>Player starting position (N, S, E, W)</li>
</ul>

<h2>🎮 Controls</h2>
<ul>
  <li><kbd>W</kbd>/<kbd>S</kbd> → Move forward/backward</li>
  <li><kbd>A</kbd>/<kbd>D</kbd> → Move left/right</li>
  <li><kbd>←</kbd>/<kbd>→</kbd> → Rotate view</li>
  <li><kbd>ESC</kbd> → Exit the game</li>
</ul>

<h2>📚 What we learned</h2>
<ul>
  <li>How a basic 3D engine works using <strong>raycasting</strong> and the math behind it</li>
  <li>Vector math for movement, direction, and collision detection</li>
  <li>Coordinate systems and mapping 2D grid maps to 3D space</li>
  <li>Working with the <strong>MiniLibX</strong> library for graphics</li>
  <li>Teamwork, Git collaboration, and project organization</li>
</ul>

<h2>📸 Screenshots</h2>
<p align="center">
  <img src="imgs/visual.gif" alt="Gameplay screenshot" width="600"/>
</p>

<h2>👨‍💻 Authors</h2>
<ul>
  <a>This project was made by <strong>JARD Noan</strong> and </a><a href="https://github.com/mpinguet"><strong>PINGUET Macéo</strong>.</a>
</ul>

<hr />

<p align="center">Made with ❤️ at 42 School</p>
