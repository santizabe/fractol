# fractol 🌀

**fractol** is a graphical project from **42 School** that explores complex numbers and fractals using the **MLX42** graphics library.  
The program renders famous fractals such as **Mandelbrot** and **Julia**, allowing interactive zooming, navigation, and color manipulation.

---

## ✨ Features

- Rendering of:
  - **Mandelbrot set**
  - **Julia set**
- Smooth zoom using the mouse wheel
- Movement using arrow keys
- Dynamic color changes
- High-performance rendering (`-O3`, `-ffast-math`)
- Bonus mode with **Burning ship**

---

## 🧠 Fractals Implemented

### Mandelbrot
The classic Mandelbrot set, generated from the iterative formula:

zₙ₊₁ = zₙ² + c

Where `c` is the point in the complex plane and `z₀ = 0`.

### Julia
A Julia set generated with a fixed complex constant `c` and varying initial values.

Julia supports:
- Custom `(x, y)` complex coordinates
- Optional **mouse-follow mode** with -s

---

## 🖥️ Usage

### Mandelbrot
```bash
./fractol mandelbrot
```

### Julia
```bash
./fractol julia <x> <y>
```
Example:
```bash
./fractol julia -0.8 0.156
```

Julia with Mouse Tracking
```bash
./fractol julia <x> <y> -s
```

⌨️ Controls
Key / Action	Effect
Arrow Keys      Move around the fractal
Mouse Wheel     Zoom in / Zoom out
Mouse Move (-s)	Modify Julia parameters
ESC	Exit the program

🛠️ Compilation
Requirements
- MLX42
- GLFW
- pthread


📚 Learning Outcomes
Complex numbers and mathematical visualization

Event-driven programming

Graphics rendering with MLX42

Optimization and performance tuning in C

🧑‍🎓 Santiago Zapata Bedoya
Project developed as part of the 42 School curriculum.

📜 License
This project is intended for educational purposes under 42 School rules.