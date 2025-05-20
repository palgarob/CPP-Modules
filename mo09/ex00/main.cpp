/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:59:39 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/20 12:10:40 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <ctime>
#include <map>
#include <cwchar>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <limits>

static void create_db(BtcDB& db, std::ifstream& dbstream)
{
	std::string line;
	std::stringstream ss;
	time_t key;
	double val;
	
	while (std::getline(dbstream, line))
	{
		if (line == "date,exchange_rate")
			continue ;
		key = date_parser(line.substr(0, 10));
		ss.clear();
		ss.str(line.substr(11));
		if (ss >> val)
			db[key] = val;
	}
}

/* static void check_stream_state(const std::stringstream& ss, const std::string& str)
{
	if (ss.fail())
		throw (std::invalid_argument("Error: use a double for the quantity. Problem: " + str));
} */

int main(int argc, char **argv)
{
	// Check number of arguments
	if (argc != 2)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		return (1);
	}
	// open files
	std::ifstream dbstream("data.csv");
	if (dbstream.fail())
	{
		std::cerr << "Error: could not open data base file" << std::endl;
		return (1);
	}
	std::ifstream inputstream(argv[1]);
	if (inputstream.fail())
	{
		std::cerr << "Error: could not open input file" << std::endl;
		return (1);
	}

	BtcDB db;
	create_db(db, dbstream);
	std::string line;
	while (std::getline(inputstream, line))
	{
		if (line == "date | value")
			continue ;
		try {
			if (line.substr(10, 3) != " | ")
				throw (std::invalid_argument("Error: use the specified pipe format ' | '. Problem: " + line));
			time_t t = date_parser(line.substr(0, 10));
			std::stringstream ss;
			ss.clear();
			ss.str(line.substr(13));
			double quantity;
			ss >> quantity;
			if (ss.fail())
				throw (std::invalid_argument("Error: use a double for the quantity. Problem: " + line));
			if (ss.peek() != EOF)
				throw (std::invalid_argument("Error: no characters after the quantity allowed. Problem: " + line));
			if (quantity < 0)
				throw (std::invalid_argument("Error: no negative numbers allowed. Problem: " + line));
			if (quantity > 1000)
				throw (std::invalid_argument("Error: too large a number. Problem: " + line));
			db.bitcoinExchange(t, quantity);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			continue ;
		}
	}
}
