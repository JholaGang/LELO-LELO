class BankAccount:
    def __init__(self, account_number, account_holder, balance=0.0):
        self.account_number = account_number
        self.account_holder = account_holder
        self.balance = balance

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            print(f"Deposited ${amount:.2f}. New balance: ${self.balance:.2f}")
        else:
            print("Deposit amount must be positive.")

    def withdraw(self, amount):
        if amount > self.balance:
            print("Insufficient funds.")
        elif amount <= 0:
            print("Withdrawal amount must be positive.")
        else:
            self.balance -= amount
            print(f"Withdrew ${amount:.2f}. New balance: ${self.balance:.2f}")

    def check_balance(self):
        print(f"Account Balance: ${self.balance:.2f}")


class Bank:
    def __init__(self):
        self.accounts = {}

    def create_account(self, account_number, account_holder):
        if account_number in self.accounts:
            print("Account number already exists.")
        else:
            self.accounts[account_number] = BankAccount(account_number, account_holder)
            print(f"Account created for {account_holder} with Account Number: {account_number}")

    def get_account(self, account_number):
        account = self.accounts.get(account_number)
        if not account:
            print("Account not found.")
        return account


# Example usage
bank = Bank()

# Create accounts
bank.create_account(101, "Alice")
bank.create_account(102, "Bob")

# Perform transactions
account = bank.get_account(101)
if account:
    account.deposit(500)
    account.withdraw(200)
    account.check_balance()

account = bank.get_account(102)
if account:
    account.deposit(1000)
    account.withdraw(1500)  # Insufficient funds
    account.check_balance()