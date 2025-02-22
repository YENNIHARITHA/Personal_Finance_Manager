
# Personal Finance Manager

## Overview
The **Personal Finance Manager** is a C-based application that helps users track their income, expenses, and savings. It allows users to manage their finances efficiently by categorizing transactions, generating reports, and analyzing spending patterns.

## Features
- Add and manage income and expenses
- Categorize transactions (e.g., Food, Rent, Salary, etc.)
- View financial summaries and reports
- Calculate total savings
- Simple and user-friendly command-line interface

## Installation
### Prerequisites
- GCC compiler (MinGW for Windows)
- A terminal or command prompt

### Compilation
To compile the program, use the following command:
```sh
gcc personal_finance_manager.c -o Personal_Finance_Manager
```

### Running the Program
Once compiled, run the program using:
```sh
./Personal_Finance_Manager
```
(For Windows, use `Personal_Finance_Manager.exe` instead.)

## Usage
1. **Add an Expense/Income**: Enter transaction details when prompted.
2. **View Report**: Get a summary of your financial transactions.
3. **Exit**: Save and exit the application.

## File Structure
```
├── personal_finance_manager.c   # Main source code
├── personal_finance_manager.h   # Header file (if applicable)
├── transactions.txt             # Stores transaction records
├── README.md                    # Project documentation
```

## Future Enhancements
- Implement a graphical user interface (GUI)
- Add export functionality (CSV, PDF)
- Incorporate machine learning for expense predictions



