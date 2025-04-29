/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:59:39 by pepaloma          #+#    #+#             */
/*   Updated: 2025/04/29 23:26:12 by pepaloma         ###   ########.fr       */
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

void parse_db(std::map<std::time_t, double>& db, std::ifstream& dbstream)
{
	std::string line;
	std::stringstream ss;
	std::string key;
	double val;
	
	while (std::getline(dbstream, line))
	{
		if (line == "\n")
			break;
		key = line.substr(0, 10);
		ss.clear();
		ss.str(line.substr(11));
		ss >> val;
		db[strtotime(key)] = val;
	}
}


void parse_input(std::map<std::time_t, double>& input, std::ifstream& inputstream)
{
	std::string line;
	std::stringstream ss;
	std::string key;
	double val;

	while (std::getline(inputstream, line))
	{
		if (line[10] != ' ' && line[11] != '|' && line[12] != ' ')
		{
			std::cerr << "Error: bad input " << line << std::endl;
			exit(1);
		}
		ss.clear();
		ss.str(line.substr(13));
		ss >> val;
		if (ss.fail())
		{
			std::cerr << "Error: parsing number" << std::endl;
			exit(1);
		}
		key = line.substr(0, 10);
		if (strtotime(key) == -1)
		{
			std::cerr << "Error: parsing date" << std::endl;
			exit(1);
		}
		input[strtotime(key)] = val;
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
	std::map<std::time_t, double> db;
	std::map<std::time_t, double> input;
	parse_db(db, dbstream);
	parse_input(input, inputstream);
	std::cout << db.size() << std::endl;
	// search for the occurrences
	bitcoinExchange(input, db);
}
