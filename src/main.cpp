#include "bst.h"
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
int main(int argc, char** argv)
{
    if (false) // make false to run unit-tests
    {
        BST bst {};
        bst.add_node(10);
        bst.add_node(20);
        bst.add_node(5);
        // std::cout << bst.get_root() << std::endl;
        // std::cout << bst.get_root()->value << std::endl;
        // std::cout << bst.get_root()->left << std::endl;
        // std::cout << bst.get_root()->right << std::endl;
        // std::cout << bst.get_root()->left->value;
        // std::cout << "hi" << std::endl;
        // BST bst {};
        // std::cout << "hi" << std::endl;
        // EXPECT_EQ(bst.get_root(), nullptr);
        std::cout << bst << std::endl;
        BST bst2 { bst++ };
        std::cout << bst << std::endl;
        std::cout << bst2 << std::endl;

    } else {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret { RUN_ALL_TESTS() };
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}