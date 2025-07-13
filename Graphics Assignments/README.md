# 🎓 OpenGL Assignments

Three simple OpenGL assignments written in C++ using GLUT.Each file demonstrates different fundamental 3D rendering techniques like transformations, primitive drawing, and camera interaction.

---

## 🧱 `stacked_boxes.cpp` – Assignment 1: Stacked 3D Boxes

### Description:

Draws multiple 3D boxes stacked on top of each other. Each box is smaller than the one below it, creating a tower-like structure.

### Key Concepts:

* 3D transformations (`glTranslatef`, `glScalef`)
* `GL_QUADS` for box faces
* Rotation using arrow keys
* Depth testing

### Compile & Run:

```bash
g++ stacked_boxes.cpp -o stacked_boxes -lGL -lGLU -lglut
./stacked_boxes
```

---

## 🔁 `wire_cones.cpp` – Assignment 2: Wireframe Cones

### Description:

Creates two sets of wireframe cones using circles with increasing and decreasing radii, stacked along the z-axis.

### Key Concepts:

* `GL_LINE_LOOP` for circular wireframes
* `sin`, `cos` for calculating circle points
* Interactive 3D rotation using arrow keys

### Compile & Run:

```bash
g++ wire_cones.cpp -o wire_cones -lGL -lGLU -lglut
./wire_cones
```

---

## 💎 `diamond.cpp` – Assignment 3: Rotating Diamond

### Description:

Draws a diamond shape made of triangle fans that rotates continuously on all 3 axes. Colors change per face for clarity.

### Key Concepts:

* `GL_TRIANGLE_FAN` for 3D diamond geometry
* Real-time rotation using `glutTimerFunc`
* Simple animation

### Compile & Run:

```bash
g++ diamond.cpp -o diamond -lGL -lGLU -lglut
./diamond
```
