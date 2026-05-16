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

## 📁 Project Structure

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

Add a license file before publishing this repo publicly. `MIT` is a good choice for educational projects.

---

## 💡 Contribution

Feedback and suggestions are welcome. If you publish this as a public repo, consider adding `CONTRIBUTING.md` for contribution guidelines.
