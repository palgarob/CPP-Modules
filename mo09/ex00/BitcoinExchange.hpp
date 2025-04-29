/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:23:46 by pepaloma          #+#    #+#             */
/*   Updated: 2025/04/29 14:34:12 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <ctime>
#include <string>

void bitcoinExchange(
	const std::map<std::time_t, double>& input,
	const std::map<std::time_t, double>& db
);

time_t strtotime(std::string& str);
void format_date(time_t raw_time, char *buffer, size_t buffer_size);
