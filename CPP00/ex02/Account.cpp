/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:02:42 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/22 17:52:58 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
: _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{   
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void) { return _nbAccounts; }

int Account::getTotalAmount(void) { return _totalAmount; }

int Account::getNbDeposits(void) { return _totalNbDeposits; }

int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	
	_totalAmount += deposit;
	_totalNbDeposits++;
	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	
	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	_nbWithdrawals++;	
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;

	return true;
}

int Account::checkAmount(void) const { return _amount; }

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	// std::cout << "[19920104_091532] ";
	std::time_t now = std::time(NULL);
	std::tm *localtime = std::localtime(&now);
	
	std::cout << "[";
	std::cout << 1900 + localtime->tm_year;
	std::cout << std::setfill('0') << std::setw(2) << 1 + localtime->tm_mon;
	std::cout << std::setfill('0') << std::setw(2) << localtime->tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << localtime->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << localtime->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << localtime->tm_sec;
	std::cout << "] ";
}
