# Keystroke Simulation

This program simulates keystrokes based on a sentence provided by the user. It utilizes the Windows API to send virtual key codes to the operating system, effectively mimicking user input. You can use this program to simulate very fast keystrokes on fast-typing tests. It can be used anywhere, since key presses are indistinguishable from normal keyboard presses.

## Usage

1. Clone the repository or download the source code files.
2. Compile the code using a C compiler, such as GCC, on a Windows system.
3. Run the compiled executable.
4. Enter the sentence you want to simulate as keystrokes.
5. Specify the delay between each keystroke in milliseconds.
6. Press ENTER to start the simulation.

The program will display a countdown after pressing ENTER, and then it will begin simulating the keystrokes based on the provided sentence. Each character in the sentence is simulated as a keystroke, with the specified delay between keystrokes.

## How to Run?
1. Open a terminal window and navigate to the project directory.
2. Compile project by running the command `make`.
3. Then type `keystroke_simulation.exe`.
4. Enjoy!

## Requirements

- Windows operating system
- C compiler (e.g., GCC)

## How it Works

1. The program prompts the user to enter the sentence they want to simulate as keystrokes.
2. It then asks for the delay between each keystroke in milliseconds.
3. The program uses the Windows API function `SendInput` to send virtual key codes to the operating system, simulating the keystrokes.
4. It iterates over each character in the sentence and determines the corresponding virtual key code using `VkKeyScanExA`.
5. For the 'i' character, which may not be handled correctly by `VkKeyScanExA`, it uses a workaround by simulating the 'I' key instead.
6. After simulating each keystroke, the program introduces the specified delay using `wait`.
7. The program releases each key to complete the keystroke simulation.

## Simulation
![1](https://github.com/ISO53/Monkey-Type-Key-Simulator/assets/102249575/d767f8f4-9196-483e-aaaf-9c0e5cc1b39a)
![2](https://github.com/ISO53/Monkey-Type-Key-Simulator/assets/102249575/fcff11fa-eaad-4487-9928-faaae51e1f27)
![simulation](https://github.com/ISO53/Monkey-Type-Key-Simulator/assets/102249575/c9acd378-c2ff-4468-b37e-9a0d9d9c4fc3)


## License

This project is licensed under the [GNU General Public License v3.0](LICENSE).
