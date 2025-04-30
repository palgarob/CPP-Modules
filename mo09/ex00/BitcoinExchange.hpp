/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:23:46 by pepaloma          #+#    #+#             */
/*   Updated: 2025/04/30 21:28:21 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <ctime>
#include <string>


void bitcoinExchange(
	const std::map<std::string, double>& db,
	const std::string& line,
	const std::map<std::time_t, std::string>& dates_table
);

time_t strtotime(const std::string& str);
