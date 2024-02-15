/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:29:12 by mochida           #+#    #+#             */
/*   Updated: 2024/02/14 22:48:43 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_main.hpp"

TEST(GtestTest, SimpleAssertion) {
    int a = 5;
    EXPECT_EQ(a, 5);
}

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }