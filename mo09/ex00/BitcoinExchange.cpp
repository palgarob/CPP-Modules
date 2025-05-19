/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:30:37 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/19 18:34:19 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <iterator>

BtcDB::BtcDB() : std::map<time_t, double>() {}
BtcDB::~BtcDB() {}

void BtcDB::bitcoinExchange(time_t date, double quantity)
{
	BtcDB::const_iterator it_exact = this->find(date);
	double total;
	if (it_exact != this->end())
		total = quantity * it_exact->second;
	else
	{
		BtcDB::const_iterator it_lower = this->lower_bound(date);

		if (it_lower == this->end())
		{
			BtcDB::iterator last_element = this->end();
			last_element--;
			total = quantity * last_element->second;
		}
		else if (it_lower == this->begin())
			total = quantity * it_lower->second;
		else
		{
			BtcDB::const_iterator it_prev = it_lower;
			--it_prev;
	
			double diff_lower = std::difftime(it_lower->first, date);
			double diff_prev = std::difftime(date, it_prev->first);
	
			if (diff_lower < diff_prev) {
				total = quantity * it_lower->second;
			} else {
				total = quantity * it_prev->second;
			}
		}
	}
	std::cout << get_date(date) << " => " << quantity << " = " << total << std::endl;
}
