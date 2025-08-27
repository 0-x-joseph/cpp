/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:07:24 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/27 08:38:59 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "replace.hpp"


int mine::replace(std::string& line, const std::string& s1, const std::string& s2) {
	if (s1.empty()) return 0; // Avoid infinite loop

	int count = 0;
	size_t pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos) {
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
		++count;
	}
	return count;
}
