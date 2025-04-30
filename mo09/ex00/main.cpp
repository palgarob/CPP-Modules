/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:59:39 by pepaloma          #+#    #+#             */
/*   Updated: 2025/04/30 21:02:43 by pepaloma         ###   ########.fr       */
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

void create_db(std::map<std::string, double>& db, std::ifstream& dbstream)
{
	std::string line;
	std::stringstream ss;
	std::string key;
	double val;
	
	while (std::getline(dbstream, line))
	{
		key = line.substr(0, 10);
		ss.clear();
		ss.str(line.substr(11));
		ss >> val;
		db[key] = val;
	}
}

void create_dates_table(
	std::map<std::time_t, std::string>& dates_table,
	const std::map<std::string, double>& db
)
{
	std::map<std::string, double>::const_iterator it = db.begin();
	std::map<std::string, double>::const_iterator next = it;
	next++;
	for (std::time_t key = 0; key < strtotime("2026-01-01"); key += 86400)
	{
		dates_table[key] = it->first;
		if (next != db.end() && key > strtotime(next->first)) {
			it++; next++;
		}
	}
}

int main(int argc, char **argv)
{
	// Check number of arguments
	if (argc != 2)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		exit(1);
	}
	// open files
	std::ifstream dbstream("data.csv");
	if (dbstream.fail())
	{
		std::cerr << "Error: could not open data base file" << std::endl;
		exit(1);
	}
	std::ifstream inputstream(argv[1]);
	if (inputstream.fail())
	{
		std::cerr << "Error: could not open input file" << std::endl;
		exit(1);
	}
	// create maps
	std::map<std::string, double> db;
	std::map<std::time_t, std::string> dates_table;
	create_db(db, dbstream);
	create_dates_table(dates_table, db);
	// search for the occurrences
	std::string line;
	while (std::getline(inputstream, line))
	{
		bitcoinExchange(db, line, dates_table);
	}
}
