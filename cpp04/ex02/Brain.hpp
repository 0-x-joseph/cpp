/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 21:42:44 by ybouryal          #+#    #+#             */
/*   Updated: 2026/01/06 17:53:05 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN__
#define __BRAIN__

#define MAX_IDEAS 100

#include <string>

class Brain {
private:
  std::string ideas[MAX_IDEAS];

public:
  Brain();
  Brain(const Brain &other);
  Brain &operator=(const Brain &other);
  ~Brain();
};

#endif /* __BRAIN__ */
