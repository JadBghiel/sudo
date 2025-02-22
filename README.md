# SUDO COMMAND

Recreate the `sudo` command in the Linux terminal

Project for Epitech first year (2025)

### Description

- `my_sudo` allows users to execute commands with the privileges of another user (usually the root user). It prompts the user for their password and checks it against the stored hashed password.

## Getting Started

### Dependencies

- [Linux](https://linux.org/)
- [Make](https://www.gnu.org/software/make/)
- [GCC](https://gcc.gnu.org/)

### Installation

* Download/Clone the repository and enter its directory
* Compile the code by typing `make`

## Usage

**Execution:**

The program can be executed with the command you want to run with elevated privileges passed as arguments

```
./my_sudo <command>
```

The program will prompt for the user's password and execute the command if the password is correct.

## Innerworkings

### Project Structure

#### Approach

For `my_sudo`, I started by implementing the basic functionality of checking the user's password against the stored hashed password in `/etc/shadow`. The program reads the username and password, retrieves the hashed password from the shadow file, and validates the entered password. If the password is correct, the specified command is executed with elevated privileges using `execvp`. The password validation is handled securely using the `getpass` function to avoid exposing the password in the terminal.

### Security Considerations

- The program uses `getpass` to securely read the user's password without echoing it to the terminal.
- It accesses the `/etc/shadow` file, which requires root privileges, so the program must be run with appropriate permissions.

### Example

```sh
./my_sudo ls -l /root
```

This command will prompt for the user's password and, if correct, list the contents of the `/root` directory with elevated privileges.

#### Tools

The allowed functions of this project were all the libC excepted: getpw*, *getsp*, getgr*, *fork*, *clone*, openat*

The rest were custom made functions.

## Acknowledgments

* [Epitech](https://www.epitech.eu/)

## Authors

* **Jad BGHIEL** ([GitHub](https://github.com/JadBghiel) / [LinkedIn](https://www.linkedin.com/in/jadbghiel/))

## License

This project is licensed under the GNU Public License version 3.0 - see the [LICENSE](https://www.gnu.org/licenses/gpl-3.0.html) file for details.
