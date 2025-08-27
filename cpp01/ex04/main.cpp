/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:57:30 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/27 08:44:39 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include "replace.hpp"

int main(int ac, char **av)
{
    if (ac != 4) {
        std::cout << "Usage: " << av[0] << " <filename> <string 1> <string 2>" << std::endl;
        return 1;
    }

    std::string s1 = av[2];
    std::string s2 = av[3];
    std::string new_filename = std::string(av[1]) + ".replace";

    std::ifstream infile(av[1]);
    if (!infile) {
        std::cerr << "Error: cannot open input file." << std::endl;
        return 1;
    }

    std::ofstream outfile(new_filename.c_str());
    if (!outfile) {
        std::cerr << "Error: cannot create output file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(infile, line))
    {
        mine::replace(line, s1, s2);
        outfile << line << '\n';
    }

    return 0;
}
