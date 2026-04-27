Pokémon Battle Simulator 🕹️
A C++ console application built as an Object-Oriented Programming (OOP) project. It simulates turn-based Pokémon battles complete with type matchups, status effects, and trainer management.

✨ Features
Battle Engine: Turn-based battles with speed-based priority. Play vs AI or local PvP.

Mechanics: 8 Pokémon types, 3 move categories (Physical, Special, Status), and dynamic type multipliers loaded from typechart.txt.

Trainer Management: Build a team of up to 6 Pokémon, switch mid-battle, heal, or release them.

Progression: Pokémon evolve after winning battles if they meet their level threshold. Progress is auto-saved to save.txt.

Pokedex: Fully browsable database loaded dynamically from pokemon.txt.

🧠 OOP Concepts Implemented
This project heavily relies on core OOP principles:

Abstract Classes & Polymorphism: Virtual dispatch for moves and Pokémon types (getType(), getDamage(), applyEffect()).

Operator Overloading: Custom <<, >>, and = operators for major classes.

Memory Management: Dynamic allocation (new/delete) and Deep Copy via Rule of Three.

Exception Handling: Robust input and runtime validation using std::invalid_argument, std::out_of_range, etc.

File I/O: Serialization and deserialization for game saves and external databases.
