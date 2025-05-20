/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:30:37 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/20 11:28:55 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <iterator>

BtcDB::BtcDB() : std::map<time_t, double>() {}
BtcDB::~BtcDB() {}

/**
 * @brief Computes the total value of a given quantity of Bitcoin based on the exchange rate
 *        at a specific date. If the exact date is not found, it determines the closest rate
 *        using various strategies.
 *
 * @param date The date for which the Bitcoin exchange rate is requested (as a time_t value).
 * @param quantity The quantity of Bitcoin to be exchanged.
 *
 * The result is printed in the format: "<date> => <quantity> = <total>".
 */
void BtcDB::bitcoinExchange(time_t date, double quantity)
{
	BtcDB::const_iterator it_exact = this->find(date);
	double total;

	// Case 1: Exact date is found in the database
	if (it_exact != this->end())
	{
		total = quantity * it_exact->second;
	}
	else
	{
		BtcDB::const_iterator it_lower = this->lower_bound(date);

		// Case 2: Date is after the last available date in the database
		if (it_lower == this->end())
		{
			BtcDB::const_iterator last_element = this->end();
			last_element--;
			total = quantity * last_element->second;
		}
		// Case 3: Date is before the first available date in the database
		else if (it_lower == this->begin())
		{
			total = quantity * it_lower->second;
		}
		// Case 4: Date falls between two available dates
		else
		{
			BtcDB::const_iterator it_prev = it_lower;
			--it_prev;

			double diff_lower = std::difftime(it_lower->first, date);
			double diff_prev = std::difftime(date, it_prev->first);

			// Case 4.1: Closer to the later date
			if (diff_lower < diff_prev)
			{
				total = quantity * it_lower->second;
			}
			// Case 4.2: Closer to the earlier date or equidistant
			else
			{
				total = quantity * it_prev->second;
			}
		}
	}
	std::cout << get_date(date) << " => " << quantity << " = " << total << std::endl;
}
