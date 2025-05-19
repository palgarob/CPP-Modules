/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:23:46 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/19 18:18:39 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <ctime>
#include <string>
#include <stdexcept>

class BtcDB : public std::map<time_t, double>
{
	private:
		BtcDB(const BtcDB& src);
		BtcDB& operator=(const BtcDB& rhs);
	public:
		BtcDB();
		~BtcDB();

		void bitcoinExchange(time_t date, double quantity);
};

time_t date_parser(const std::string& date_string);
const std::string get_date(time_t t);
