/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:47:00 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/12 11:11:01 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

Account::Account ( int initial_deposit )
{
	this->_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";ammount:" << _amount;
	std::cout << ";created" << std::endl;
	_nbAccounts++;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amout:" << _amount;
	std::cout << ";deposite:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	std::cout << "amount:" << _amount;
	std::cout << "nbDeposits:" << _nbDeposits << std::endl;	
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amout:" << _amount;
	std::cout << ";withdrawal:" << withdrawal;
	if (_amount < withdrawal)
	{
		std::cout << ";refused" << std::endl;
		return (false);
	}
	_amount += withdrawal;
	std::cout << ";amount:" << _amount;
	_nbWithdrawals++;
	std::cout << "nb_withdrals:" << _nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return(_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawls:" << _nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
	<< "total:" << getTotalAmount() << ";"
	<< "teposits:" << getNbDeposits() << ";"
	<< "tithdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::_displayTimestamp()
{
	time_t tt;
	time(&tt);
	char c[17];
	std::tm *tp;
	tp = std::localtime(&tt);
	std::strftime(c, 17, "[%Y%m%d_%H%M] ", tp);
	std::cout << c;
}
