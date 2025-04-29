/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:30:37 by pepaloma          #+#    #+#             */
/*   Updated: 2025/04/29 20:43:17 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

time_t	strtotime(std::string& str)
{
	struct std::tm ts;
	
	ts.tm_year = (str[0] - '0') * 1000 + (str[1] - '0') * 100 + (str[2] - '0') * 10 + (str[3] - '0') - 1900;
	ts.tm_mon = (str[5] - '0') * 10 + (str[6] - '0') - 1;
	ts.tm_mday = (str[8] - '0') * 10 + (str[9] - '0');
	ts.tm_sec = 0; ts.tm_min = 0; ts.tm_hour = 0; ts.tm_wday = 0; ts.tm_yday = 0; ts.tm_isdst = 0;
	return (std::mktime(&ts));
}

void format_date(time_t raw_time, char *buffer, size_t buffer_size) {
	struct tm *time_info = gmtime(&raw_time);
	strftime(buffer, buffer_size, "%Y-%m-%d", time_info);
}

void bitcoinExchange(
	const std::map<std::time_t, double>& input,
	const std::map<std::time_t, double>& db
)
{
	
	double mapped_value;
	char date_formatted[11];
	std::map<std::time_t, double>::const_iterator input_iterator = input.begin();
	std::map<std::time_t, double>::const_iterator db_iterator = db.begin();
	for (input_iterator = input_iterator; input_iterator != input.end(); input_iterator++)
	{
		for (db_iterator = db.begin(); db_iterator != db.end(); db_iterator++)
		{
			if (input_iterator->first < db_iterator->first)
			{
				if (db_iterator != db.begin())
					db_iterator--;
				mapped_value = db_iterator->second;
				format_date(db_iterator->first, date_formatted, 11);
				std::cout << date_formatted << " => " << input_iterator->second << " = " << mapped_value * input_iterator->second << std::endl;
				break ;
			}
		}
		if (db_iterator == db.end())
		{
			db_iterator--;
			format_date(db_iterator->first, date_formatted, 11);
			std::cout << date_formatted << " => " << input_iterator->second << " = " << mapped_value * input_iterator->second << std::endl;
		}
	}
}
