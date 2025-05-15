/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jacobsthal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:07:32 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/13 19:14:09 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>

long jacobsthal(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

bool isJacobsthal(int n) {
	if (n < 0) return false;

	int j0 = 0;
	int j1 = 1;

	if (n == j0 || n == j1) return true;

	int jNext;
	while (true) {
		jNext = j1 + 2 * j0;
		if (jNext == n) return true;
		if (jNext > n) return false;

		j0 = j1;
		j1 = jNext;
	}
}
