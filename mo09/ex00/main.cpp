/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:59:39 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/19 18:41:58 by pepaloma         ###   ########.fr       */
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

void create_db(BtcDB& db, std::ifstream& dbstream)
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
			time_t t = date_parser(line.substr(0, 10));
			std::stringstream ss;
			ss.str(line.substr(13));
			if (ss.peek() != EOF)
				throw ("Error: no characters after the quantity allowed. Problem: " + line);
			double quantity;
			ss >> quantity;
			try
			{
				db.bitcoinExchange(t, quantity);
			}
			catch (std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
