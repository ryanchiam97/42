/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 20:46:39 by rchiam            #+#    #+#             */
/*   Updated: 2026/04/21 00:05:32 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cout << "Error: s1 cannot be empty" << std::endl;
        return 1;
    }

    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        std::cout << "Error: could not open input file" << std::endl;
        return 1;
    }

    std::string content;
    std::string line;
    while (std::getline(infile, line))
    {
        content += line;
        if (!infile.eof())
            content += "\n";
    }
    infile.close();

    std::string result;
    std::string::size_type start = 0;
    std::string::size_type found = content.find(s1, start);

    while (found != std::string::npos)
    {
        result += content.substr(start, found - start);
        result += s2;
        start = found + s1.length();
        found = content.find(s1, start);
    }
    result += content.substr(start);

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile.is_open())
    {
        std::cout << "Error: could not open output file" << std::endl;
        return 1;
    }

    outfile << result;
    outfile.close();

    return 0;
}
