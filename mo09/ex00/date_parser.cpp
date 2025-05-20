/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date_parser.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:41:24 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/20 11:30:20 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <sstream>
#include <ctime>
#include <cstring>
#include <iostream>

const std::string get_date(time_t t)
{
		std::tm* ptm = std::localtime(&t);
		char buffer[11];
		std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", ptm);
		return std::string(buffer);
}

static bool isLeap(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static time_t get_time(int year, int month, int day) {
	struct std::tm timeinfo;
	std::memset(&timeinfo, 0, sizeof(struct std::tm));

	timeinfo.tm_year = year - 1900;
	timeinfo.tm_mon = month - 1;
	timeinfo.tm_mday = day;

	time_t result_time = std::mktime(&timeinfo);

	return result_time;
}

time_t date_parser(const std::string& date_string)
{
	int d, m, y;
	char sep1, sep2;
	std::istringstream in(date_string);
	if (!(in >> y >> sep1 >> m >> sep2 >> d) || sep1 != '-' || sep2 != '-')
		throw (std::invalid_argument("Error: wrong date format. Problem: " + date_string));
	if (y < 1970)
		throw (std::invalid_argument("Error: respect epoch. Problem: " + date_string));
	if (m < 1 || m > 12 || d < 1)
		throw (std::invalid_argument("Error: out of range date parameters. Problem: " + date_string));
	static const int daysInMonth[] = {
		0, 31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};
	int maxDays = daysInMonth[m];
	if (m == 2 && isLeap(y)) 
		maxDays = 29;
	if (d > maxDays)
	{
		throw (std::invalid_argument("Error: date doesn't exist. Problem: " + date_string));
	}
	return (get_time(y, m, d));
}
