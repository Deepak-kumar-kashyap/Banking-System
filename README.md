# Banking System

A simple console-based banking management system implemented in C++. This project demonstrates fundamental concepts in object-oriented programming, file I/O, and data management for simulating real-world banking operations.

## Features

- **Account Creation**: Create new bank accounts with unique account numbers, names, PINs, and initial balances.
- **Secure Login**: Authenticate users using account number and PIN.
- **Banking Operations**:
  - Deposit money into account
  - Withdraw money (with balance checks)
  - Check account balance
  - Transfer money between accounts
- **Transaction History**: View a log of all transactions (deposits, withdrawals, transfers).
- **Data Persistence**: Account data is stored in binary files, and transactions are logged in text files.

## Technologies Used

- **Language**: C++
- **File I/O**: Binary files for account storage, text files for transaction logging
- **Data Structures**: Vectors for temporary data handling
- **Object-Oriented Programming**: Custom `Account` class with encapsulation

## Requirements

- C++ compiler (e.g., g++, MinGW on Windows, or clang++)
- Standard C++ libraries (iostream, fstream, vector, string)

## How to Build

1. Ensure you have a C++ compiler installed.
2. Navigate to the project directory.
3. Compile the source files:

   ```
   g++ main.cpp Account.cpp -o banking_system
   ```

   On Windows, you might need to use `g++ main.cpp Account.cpp -o banking_system.exe`.

## How to Run

1. After building, run the executable:

   ```
   ./banking_system
   ```

   Or on Windows:

   ```
   banking_system.exe
   ```

2. Follow the on-screen menu:
   - Choose option 1 to create a new account.
   - Choose option 2 to login with an existing account number and PIN.
   - Once logged in, use the user menu for banking operations.

## File Structure

- `main.cpp`: Contains the main program logic, menus, and file operations.
- `Account.h`: Header file defining the Account class.
- `Account.cpp`: Implementation of the Account class methods.
- `accounts.dat`: Binary file for storing account data (created automatically).
- `transactions.txt`: Text file for logging transactions (created automatically).

## Usage Example

1. Run the program.
2. Create an account (e.g., Account No: 12345, Name: John Doe, PIN: 1234, Balance: 1000).
3. Login with Account No and PIN.
4. Perform operations like deposit, withdraw, etc.
5. View transaction history.

## Notes

- Account data is stored in binary format for efficiency.
- Transaction logs are in plain text for readability.
- This is a basic implementation for educational purposes and does not include advanced security features like encryption.

## Contributing

Feel free to fork and improve the project. Suggestions for enhancements are welcome!

## License

This project is open-source. Use it as you wish.</content>