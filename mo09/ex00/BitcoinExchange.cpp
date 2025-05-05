/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:30:37 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/05 11:08:08 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <iterator>


time_t strtotime(const std::string& line)
{
	struct std::tm ts;
	
	ts.tm_year = (line[0] - '0') * 1000 + (line[1] - '0') * 100 + (line[2] - '0') * 10 + (line[3] - '0') - 1900;
	if (ts.tm_year < 0)
		return (-1);
	ts.tm_mon = (line[5] - '0') * 10 + (line[6] - '0') - 1;
	if (ts.tm_mon > 11)
		return (-1);
	ts.tm_mday = (line[8] - '0') * 10 + (line[9] - '0');
	if (ts.tm_mday > 31)
		return (-1);
	ts.tm_sec = 0; ts.tm_min = 0; ts.tm_hour = 0; ts.tm_wday = 0; ts.tm_yday = 0; ts.tm_isdst = 0;
	return (std::mktime(&ts));
	
}

void bitcoinExchange(
	const std::map<std::string, double>& db,
	const std::string& line,
	const std::map<std::time_t, std::string>& dates_table
)
{
	if (
		line[10] != ' ' || line[11] != '|' || line[12] != ' '
		|| line[4] != '-' || line[7] != '-' || line.size() < 14
	)
	{
		std::cerr << "Error: bad input " << line << std::endl;
		return ;
	}
	std::string date = line.substr(0, 10);
	std::stringstream ss;
	ss.str(line.substr(13));
	double quantity;
	ss >> quantity;
	if (ss.fail() || !(ss.eof()))
	{
		std::cerr << "Error: bad input " << line << std::endl;
		return ;
	}
	if (quantity < 0)
	{
		std::cerr << "Error: negative number " << line << std::endl;
		return ;
	}
	if (quantity > 1000)
	{
		std::cerr << "Error: too large a number " << line << std::endl;
		return ;
	}
	std::string db_date;
	if (strtotime(date) > 0)
		db_date = dates_table.find(strtotime(date))->second;
	else
	{
		std::cerr << "Error: invalid date" << std::endl;
		return ;
	}
	std::map<std::string, double>::const_iterator it = db.find(db_date);
	double value;
	if (it != db.end())
		value = it->second;
	else
		value = 2;
	std::cout << date << " => " << quantity << " = " << value * quantity << std::endl;
}
