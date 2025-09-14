# ViewFactory GTK Library

A lightweight GTK4-based C library for managing and switching between multiple views using `GtkStack`. Designed to simplify screen creation and navigation in GTK applications.

This project builds both a reusable shared library (`libviewfactory.so`) and a demo executable (`FactoryMethod`) that showcases its usage.

---

## 🧩 Features

- Modular view management via `ViewFactory`
- Named views with easy switching
- CSS styling support using `GtkCssProvider`
- Clean layout using `GtkGrid` and `GtkTextView`
- Shared library output for easy reuse

---

## 📁 Project Structure

├── CMakeLists.txt # Build configuration 
├── inc/ # Public headers 
│ ├── view_factory.h 
│ └── callbacks.h 
├── src/ # Source files 
│ ├── view_factory.c 
│ ├── callbacks.c 
│ └── main.c 
├── style.css # Optional CSS styling 
├── build/ # Generated after build 
│ ├── FactoryMethod # Demo executable 
│ └── lib/ 
│   ├── libviewfactory.so 
│ └── include/ 
│   ├── view_factory.h 
│   └── callbacks.h