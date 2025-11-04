#include <iostream>
#include <time.h>
#include <stdio.h>
#include "../include/Account.hpp"

//static variables must be defined outside the class
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


// timestamp should be year/month/day_hour/minutes/seconds
void Account::_displayTimestamp(void)
{
	time_t rawtime;
	char	ptr[24];
	struct tm *time_info;

	time(&rawtime);
	time_info = localtime (&rawtime);
	strftime(ptr, 24, "[%Y%m%d_%H%M%S] ", time_info);
	std::cout << ptr;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;

	std::cout 	<< "index:" << _accountIndex 
				<< ";amount:" << _amount 
				<< ";created\n";
}

void  Account::makeDeposit(int deposit)
{

	int p_amount = _amount;

	_amount = deposit + p_amount; 
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;

	_displayTimestamp();

	std::cout 	<< "index:" << _accountIndex
				<< ";p_amount:" << p_amount
				<< ";deposit:" << deposit 
				<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits
				<< "\n";
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< "\n";
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount 
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< "\n";
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount;
	if (_amount - withdrawal < 0)
	{
		std::cout	<< ";withdrawal:refused\n";
		return (false);
	}
	else
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		std::cout	<< ";withdrawal:" << withdrawal
					<< ";amount:" << _amount
					<< ";nb_withdrawals:" << _nbWithdrawals
					<< "\n";
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		return(true);
	}
}

int		Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

int	Account::checkAmount( void ) const
{
	return (_amount);
}

Account::~Account()
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed\n";
}
