/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:37:29 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/20 10:58:59 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// [19920104_091532] index:0;amount:42;created
Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = getNbAccounts();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << std::endl;
}

Account::Account(void)
{
	this->_amount = 0;
	this->_accountIndex = getNbAccounts();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << std::endl;
}

// [19920104_091532] index:0;amount:47;closed
Account::~Account(void)
{
	Account::_nbAccounts--;
	Account::_totalNbDeposits -= this->_nbWithdrawals;
	Account::_totalNbDeposits -= this->_nbDeposits;
	Account::_totalAmount -= this->_amount;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}


// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";"
		<< "total:" << Account::getTotalAmount() << ";"
		<< "deposits:" << Account::getNbDeposits() << ";"
		<< "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

// [19920104_091532]
void	Account::_displayTimestamp(void)
{
	char	timestamp_str[20];
    std::time_t t;
	std::time(&t);
    std::tm datetime = *std::localtime(&t);
	std::strftime(timestamp_str, 20, "%Y%m%d_%H%M%S", &datetime);
	std::cout << "[" << timestamp_str << "] ";
}

// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals << std::endl;

}

// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
// [19920104_091532] index:0;p_amount:47;deposit:refused
void	Account::makeDeposit( int deposit )
{
	int	accept = 1;
	int	p_amount;

	if (deposit <= 0)
		accept = 0;

	p_amount = this->_amount;

	if (accept) {
		this->_amount += deposit;
		this->_nbDeposits++;
		Account::_totalNbDeposits++;
		Account::_totalAmount += deposit;
	}
	Account::_displayTimestamp();
	if (accept)
	{
		std::cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:" << p_amount << ";"
			<< "deposit:" << deposit << ";"
			<< "amount:" << this->_amount << ";"
			<< "nb_deposits:" << this->_nbDeposits << std::endl;
		return ;
	}
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << p_amount << ";"
		<< "deposit:" << "refused" << std::endl;
}

// [19920104_091532] index:7;p_amount:16596;withdrawal:7654;amount:8942;nb_withdrawals:1
// [19920104_091532] index:0;p_amount:47;withdrawal:refused
bool	Account::makeWithdrawal( int withdrawal )
{
	bool	accept = true;
	int	p_amount;

	p_amount = this->_amount;
	if (withdrawal <= 0 || withdrawal > p_amount)
		accept = false;

	if (accept) {
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
	}
	Account::_displayTimestamp();
	if (accept)
	{
		std::cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:" << p_amount << ";"
			<< "withdrawal:" << withdrawal << ";"
			<< "amount:" << this->_amount << ";"
			<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return accept;
	}
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << p_amount << ";"
		<< "withdrawal:" << "refused" << std::endl;
	return accept;
}


int		Account::checkAmount( void ) const
{
	return this->_amount;
}
