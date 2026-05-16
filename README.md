# ViewFactory GTK Library

A lightweight GTK4-based C library for managing and switching between multiple views using `GtkStack`. Designed as a simple learning tool for GTK4 and C, with a demo executable that shows how to use the library.

This project builds both a reusable shared library (`libviewfactory.so`) and a demo program (`FactoryMethod`) that demonstrates view switching.

---

## 🧩 Features

- Modular view management via `ViewFactory`
- Named views with easy switching
- GTK4 CSS styling support using `GtkCssProvider`
- Simple demo app for beginners
- Shared library output for reuse in other GTK applications

---

## ✅ Prerequisites

- `cmake` (version 3.10 or newer)
- `pkg-config`
- GTK4 development libraries
  - Debian/Ubuntu: `sudo apt install libgtk-4-dev`
  - Fedora: `sudo dnf install gtk4-devel`
  - Arch Linux: `sudo pacman -Syu gtk4`
  - Windows (MSYS2): install MSYS2 and then `pacman -S mingw-w64-x86_64-gtk4 mingw-w64-x86_64-toolchain`

---

## 🛠️ Build

```bash
mkdir -p build
cd build
cmake ..
make
```

---

## ▶️ Run Demo

From `build/`:

```bash
./FactoryMethod
```

---

## � Use the shared library in another project

After building:

- shared library: `build/lib/libviewfactory.so`
- headers: `build/lib/include`

In another C project, include the headers and link against the library, for example:

```cmake
include_directories("${CMAKE_SOURCE_DIR}/path/to/CViewFactory/build/lib/include")
link_directories("${CMAKE_SOURCE_DIR}/path/to/CViewFactory/build/lib")
add_executable(MyApp src/main.c)
target_link_libraries(MyApp PRIVATE viewfactory ${GTK_LIBRARIES})
```

Or with GCC directly:

```bash
gcc -o MyApp src/main.c -I/path/to/CViewFactory/build/lib/include \
    -L/path/to/CViewFactory/build/lib -lviewfactory $(pkg-config --cflags --libs gtk4)
```

---

## �📁 Project Structure

- `CMakeLists.txt` — build configuration
- `inc/` — public header files
- `src/` — implementation source files
- `style.css` — optional styling for the GTK demo
- `build/` — generated build output (not committed)

---

## 📌 Notes

- The demo app uses `style.css` for styling.
- The shared library is built as `build/lib/libviewfactory.so` and headers are copied to `build/lib/include`.
- This repository is intended to make GTK and basic view management accessible for learners.

---

## 📜 License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

## 💡 Contribution

Contributions are welcome. If you want to help improve the project, please:

- open an issue for bugs or feature suggestions
- submit a pull request with a clear description
- keep changes small and focused
- use the existing C and GTK4 style for new code
