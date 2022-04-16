# Bank
Simple program to demonstrate the basic operations of a bank

## Key funtionalities
- Create an account
- Close an existing account
- Modify an existing account
- Enquire balance
- Deposite money
- Withdraw money

## How to install
```
sudo chmod +x install.sh
./install.sh
```

## How to uninstall
```
sudo chmod +x uninstall.sh
./uninstall.sh
```
## Sample usage
```
bank --help
bank modify --h
bank create -u methmal
bank deposite -n 12345678 -a 1000
bank withdraw -n 12345678 -a 500
bank enquire -n 12345678
bank modify -n 12345678 -u sanuja
```