#include "bst.h"
#include <vector>
// inke children nadashte bashe null ptr bezare
BST::Node::Node(int _value, Node* _left, Node* _right)
    : value { _value }
    , left { _left }
    , right { _right }
{
}
BST::Node::Node(const Node& node)
    : value { node.value }
    , left { node.left }
    , right { node.right }
{
}
BST::Node& BST::Node::operator=(const BST::Node& node)
{
    std::cout << "operator = of node" << std::endl;
    // delete value;
    std::cout << "operator = of node" << left << right << std::endl;
    if (left != nullptr) {
        std::cout << "delete left" << std::endl;
        delete left;
    }
    if (right != nullptr) {
        std::cout << "delete right" << std::endl;
        delete right;
    }

    // root? new chi?
    value = node.value;
    std::cout << "value" << value << std::endl;
    if (node.left != nullptr || node.left != 0) {
        left = new Node(*node.left);
        // left = node.left;
        std::cout << "@@@@@@@@@@ left" << std::endl;
    }
    if (node.right != nullptr || node.right != 0) {
        right = new Node();
        std::cout << *node.right << std::endl;
        *right = *node.right;
        std::cout << "@@@@@@@@ right" << std::endl;
    }

    return *this;
}

// BST::Node*& BST::Node::operator=(const BST::Node*& node_pnt)
// {
//     std::cout << "operator = of node*" << std::endl;
//     // delete value;
//     delete left;
//     delete right;
//     // root? new chi?
//     value = node_pnt->value;
//     left = node_pnt->left;
//     right = node_pnt->right;
//     return this;
// }

std::ostream& operator<<(std::ostream& os, const BST::Node& node)
{
    os << "Vector: ";
    os << node.value;
    return os;
}
BST::Node*& BST::get_root()
{
    return root;
}
bool BST::add_node(int _value)
{
    auto pnt_new = root;
    if (root == nullptr) {
        BST::Node khers1(_value, nullptr, nullptr);
        root = new Node(khers1);
        std::cout << "poopy " << &khers1 << khers1 << root << *root << root->value << std::endl;

    } else {
        BST::Node khers1(_value, nullptr, nullptr);
        while (true) {
            // std::cout << "miyad tooye while" << std::endl;
            if (_value > pnt_new->value) {
                // std::cout << "miyad tooye >" << std::endl;
                // std::cout << "enter 1";
                // pnt_new = (pnt_new->right);
                std::cout << "adresse baade bozorgtar" << pnt_new << std::endl;
                if (pnt_new->right == nullptr) {
                    pnt_new->right = new Node(khers1);
                    // std::cout << "ina ro mikhaim check konim" << pnt_new << "****" << &khers1 << std::endl;
                    return 1;
                }
                pnt_new = pnt_new->right;

            } else if (_value < pnt_new->value) {

                if (pnt_new->left == nullptr) {
                    pnt_new->left = new Node(khers1);
                    // std::cout << "ina ro mikhaim check konim" << pnt_new << "****" << &khers1 << std::endl;
                    return 1;
                }
                pnt_new = pnt_new->left;
            } else {
                std::cout << "miyad tooye else dige" << std::endl;
                return false;
            }
        }

        // std::cout << "new mikone" << std::endl;
        // std::cout << "ina ro mikhaim check konim" << pnt_new << "****" << &khers1 << std::endl;
    }
    // root->left = new Node(khers1);
}
void BST::bfs(std::function<void(BST::Node*& node)> func)
{

    std::vector<BST::Node*> queue;
    std::vector<int> visited;
    // size_t i = 0;
    auto pnt_standin = root;
    // std::cout << *root << std::endl;

    queue.push_back(pnt_standin);
    // std::cout << "root q" << queue[0] << "      " << queue[0]->value << std::endl;

    std::cout << "inja miyad?";

    while (queue.size() != 0 && queue[0] != nullptr) {
        visited.push_back(queue[0]->value);
        func(queue[0]);
        queue.erase(queue.begin());
        // queue.erase(queue.begin());
        // std::cout << "visited:" << visited[i] << std::endl;

        if (pnt_standin->left != nullptr) {
            queue.push_back(pnt_standin->left);
        }
        if (pnt_standin->right != nullptr) {
            queue.push_back(pnt_standin->right);
        }
        pnt_standin = queue[0];
    }
}
size_t BST::length()
{
    std::vector<Node*> queue;
    std::vector<int> visited;
    // queue[0] = root->value;
    // queue[1] = root->right;
    // queue[2] = root->left;
    size_t i = 0;
    auto pnt_standin = root;
    queue.push_back(pnt_standin);
    while (true) {

        visited.push_back(queue[0]->value);
        std::cout << queue[0] << std::endl;
        std::cout << queue[0]->value << std::endl;
        queue.erase(queue.begin());
        std::cout << "visited:" << visited[i] << std::endl;

        if (pnt_standin->left != nullptr) {
            queue.push_back(pnt_standin->left);
        }
        if (pnt_standin->right != nullptr) {
            queue.push_back(pnt_standin->right);
        }
        if (queue.size() == 0) {
            std::cout << "the lenght we measured:" << i + 1 << std::endl;
            return i + 1;
        }
        i++;
        pnt_standin = queue[0];
        // std::cout << queue[i] << std::endl;
        // std::cout << queue[i]->value << std::endl;
        // std::cout << visited[i] << std::endl;
    }
}
std::ostream& operator<<(std::ostream& os, const BST& bst)
{
    std::cout << "avalin chizi ke cout mishe" << std::endl;
    os << "*******************************************************************************************" << std::endl;
    std::vector<BST::Node*> queue;
    std::vector<int> visited;
    // queue[0] = root->value;
    // queue[1] = root->right;
    // queue[2] = root->left;
    size_t i = 0;
    auto pnt_standin = bst.root;
    std::cout << "ino mikham check konam" << bst.root->value << std::endl;
    queue.push_back(pnt_standin);
    size_t flag { 0 };
    while (flag == 0) {

        visited.push_back(queue[0]->value);
        os << queue[0];
        os << "             ";
        os << "=>";
        os << "value: ";
        os << queue[0]->value;
        queue.erase(queue.begin());
        os << "              ";

        if (pnt_standin->left != nullptr) {
            os << "left:";
            queue.push_back(pnt_standin->left);
            os << pnt_standin->left;
            os << "              ";
        } else {
            os << "left:";
            os << 0;
            os << "            ";
        }
        if (pnt_standin->right != nullptr) {
            os << "right:";
            queue.push_back(pnt_standin->right);
            os << pnt_standin->right;
            os << "             " << std::endl;
        } else {
            os << "right:";
            os << 0;
            os << "            " << std::endl;
        }
        if (queue.size() == 0) {
            os << "*******************************************************************************************" << std::endl;
            std::cout << "ino mikham check konam" << bst.root->value << std::endl;
            return os;
            flag = 1;
        }
        i++;
        // std::cout << "miyad ta inja**" << std::endl;
        pnt_standin = (queue[0]);
        os << std::endl;
        // std::cout << queue[i] << std::endl;
        // std::cout << queue[i]->value << std::endl;
        // std::cout << visited[i] << std::endl;
    }
}
BST::Node** BST::find_node(int value)
{
    Node* pnt_use { root };
    while (true) {
        std::cout << pnt_use->value << value << std::endl;
        if (pnt_use->value == value) {
            std::cout << "miyad inja?" << std::endl;
            auto pnt_ret = new Node*(pnt_use);
            return pnt_ret;
        }
        if (pnt_use->value < value) {
            if (pnt_use->right != nullptr) {
                std::cout << "mire right" << std::endl;
                pnt_use = pnt_use->right;
            } else {
                auto pnt_ret = nullptr;
                return pnt_ret;
            }
        }

        if (pnt_use->value > value) {
            if (pnt_use->left != nullptr) {
                std::cout << "mire left" << std::endl;
                pnt_use = pnt_use->left;
            } else {
                auto pnt_ret = nullptr;
                return pnt_ret;
            }
        }
    }

    // std::vector<Node*> queue;
    // std::vector<int> visited;
    // size_t i = 0;
    // auto pnt_standin = root;
    // queue.push_back(pnt_standin);
    // std::cout << "root q" << queue[0] << std::endl;
    // while (true) {

    //     visited.push_back(queue[0]->value);
    //     if (queue[0]->value == value) {
    //         std::cout << "hi" << std::endl;
    //         // std::cout << "oomad too if?" << value << queue[0]->value << queue[0]->left->value << queue[0]->right->value << std::endl;
    //         std::cout << "hi" << std::endl;
    //         auto pnt_ret = new Node*(queue[0]);
    //         return pnt_ret;
    //     }

    //     // std::cout << queue[0] << std::endl;
    //     // std::cout << queue[0]->value << std::endl;
    //     queue.erase(queue.begin());
    //     // std::cout << "visited:" << visited[i] << std::endl;

    //     if (pnt_standin->left != nullptr) {
    //         queue.push_back(pnt_standin->left);
    //     }
    //     if (pnt_standin->right != nullptr) {
    //         queue.push_back(pnt_standin->right);
    //     }
    //     if (queue.size() == 0) {
    //         auto pnt_ret = nullptr;
    //         return pnt_ret;
    //     }
    //     i++;

    //     pnt_standin = queue[0];
    //     // std::cout << queue[i] << std::endl;
    //     // std::cout << queue[i]->value << std::endl;
    //     // std::cout << visited[i] << std::endl;
    // }
}
BST::Node** BST::find_parrent(int value)
{
    Node* pnt_use { root };
    Node* pnt_parent { nullptr };
    if (root->value == value) {
        // is root ;doesnt have parents
        return 0;
    }
    while (true) {
        std::cout << pnt_use->value << value << std::endl;
        if (pnt_use->value == value) {
            std::cout << "miyad inja?" << std::endl;
            auto pnt_ret = new Node*(pnt_parent);
            return pnt_ret;
        }
        if (pnt_use->value < value) {
            if (pnt_use->right != nullptr) {
                std::cout << "mire right" << std::endl;
                pnt_parent = pnt_use;
                pnt_use = pnt_use->right;
            } else {
                // auto pnt_ret = nullptr;
                // return pnt_ret;
                return 0;
            }
        }

        if (pnt_use->value > value) {
            if (pnt_use->left != nullptr) {
                std::cout << "mire left" << std::endl;
                pnt_parent = pnt_use;
                pnt_use = pnt_use->left;
            } else {
                // auto pnt_ret = nullptr;
                // return pnt_ret;
                return 0;
            }
        }
        // bebin mitooni ino ba find node bezani?
        // std::vector<Node*> queue;
        // std::vector<int> visited;
        // Node** pnt_to_parent;
        // auto pnt_standin = root;
        // queue.push_back(pnt_standin);
        // std::cout << "parent has problems" << std::endl;
        // if (root->value == value) {
        //     // is root ;doesnt have parents
        //     return 0;
        // }
        // while (true) {
        //     // visited.push_back(queue[0]->value);
        //     std::cout << queue[0] << std::endl;
        //     std::cout << queue[0]->value << std::endl;
        //     pnt_to_parent = new Node*(queue[0]);
        //     std::cout << (*pnt_to_parent)->value << std::endl;
        //     queue.erase(queue.begin());
        //     // std::cout << "visited:" << visited[i] << std::endl;
        //     if (pnt_standin->left != nullptr) {
        //         queue.push_back(pnt_standin->left);
        //         if (pnt_standin->left->value == value) {
        //             pnt_to_parent = new Node*(pnt_standin);
        //             std::cout << "pointer to parent we returned" << pnt_to_parent << "    " << (*pnt_to_parent)->value << std::endl;
        //             return pnt_to_parent;
        //         }
        //     }
        //     if (pnt_standin->right != nullptr) {
        //         queue.push_back(pnt_standin->right);
        //         if (pnt_standin->right->value == value) {
        //             pnt_to_parent = new Node*(pnt_standin);
        //             std::cout << "pointer to parent we returned" << pnt_to_parent << (*pnt_to_parent)->value << std::endl;
        //             return pnt_to_parent;
        //         }
        //     }
        //     if (queue.size() == 0) {
        //         // doesnt have parents
        //         return 0;
        //     }
        //     // i++;
        //     pnt_standin = queue[0];
        // }
    }
}
BST::Node** BST::find_successor(int value)
{
    // bebin mitooni ino ba find node bezani?
    BST::Node** pointer_got_from_findnode { this->find_node(value) };
    while (true) {
        Node* node_one_left;
        node_one_left = (*pointer_got_from_findnode)->left;
        std::cout << "one left " << node_one_left->value;
        Node* node_one_left_right;
        node_one_left_right = node_one_left;
        while (true) {
            node_one_left_right = node_one_left_right->right;
            std::cout << node_one_left_right->value << std::endl;
            if (node_one_left_right->right == nullptr) {
                Node** ret_pnt;
                ret_pnt = new Node*(node_one_left_right);
                return ret_pnt;
            }
        }
    }

    // std::vector<Node*> queue;
    // std::vector<int> visited;
    // size_t i = 0;
    // auto pnt_standin = root;
    // queue.push_back(pnt_standin);
    // while (true) {
    //     visited.push_back(queue[0]->value);
    //     if (queue[0]->value == value) {
    //         Node* node_one_left;
    //         node_one_left = queue[0]->left;
    //         Node* node_one_left_right;
    //         node_one_left_right = node_one_left;
    //         while (true) {
    //             node_one_left_right = node_one_left_right->right;
    //             std::cout << node_one_left_right->value << std::endl;
    //             if (node_one_left_right->right == nullptr) {
    //                 std::cout << "ehtemalan in nullptr khare";
    //                 Node** ret_pnt;
    //                 ret_pnt = new Node*(node_one_left_right);
    //                 return ret_pnt;
    //             }
    //         }
    //     }

    //     queue.erase(queue.begin());
    //     if (pnt_standin->left != nullptr) {
    //         queue.push_back(pnt_standin->left);
    //     }
    //     if (pnt_standin->right != nullptr) {
    //         queue.push_back(pnt_standin->right);
    //     }
    //     if (queue.size() == 0) {
    //         auto pnt_ret = nullptr;
    //         return pnt_ret;
    //     }
    //     i++;
    //     pnt_standin = queue[0];
    // }
}
BST::~BST()
{
    std::vector<Node*> nodes;
    bfs([&nodes](BST::Node*& node) { nodes.push_back(node); });
    for (auto& node : nodes)
        delete node;
    std::cout << "we did destruct" << std::endl;
}
BST::BST(const BST& bst)
// : root { bst.root }
{
    // BST temp;
    // delete temp.root;
    root = new BST::Node();
    *root = *bst.root;
    std::cout << "copy constructor of bst" << std::endl;
    std::cout << root->value << std::endl;
}
// aslan motmarn nistam ino
const BST& BST::operator=(const BST& bst)
{
    std::cout << "operator =" << std::endl;
    if (this == &bst) {
        return *this;
    }

    std::cout << bst << std::endl;
    delete root;
    // root = nullptr;
    // root? new chi?
    // std::vector<Node*> queue_for_bst;
    // std::vector<Node*> queue_for_root;
    root = new Node();
    *root = *bst.root;
    // root = bst.root;
    // root = new BST::Node(*bst.root);
    // // auto root_standin { root };
    // queue_for_root.push_back(root);
    // // root = bst.root;
    // // std::cout << root << *root << &root << "     " << bst.root << *(bst.root) << root->left << bst.root->left << std::endl;
    // // *(root->right) = *(bst.root->right);
    // // *(root->right->right) = *(bst.root->right->right);
    // // delete root->left;
    // // auto bst_root_standin { bst.root };
    // // std::cout << "operator =" << std::endl;
    // queue_for_bst.push_back(bst.root);
    // while (true) {
    //     std::cout << "another cycle" << std::endl;
    //     // delete (queue_for_root[0]->right->right->right);
    //     if (queue_for_bst[0]->right != nullptr) {
    //         std::cout << "miyad inja 1?" << std::endl;
    //         std::cout << queue_for_bst[0]->right->value << std::endl;
    //         std::cout << queue_for_root[0]->right->value << std::endl;
    //         (queue_for_root[0]->right) = new Node(*(queue_for_bst[0]->right));

    //         std::cout << "miyad inja 2?" << std::endl;
    //         // root->right = new Node(*(bst.root->right));
    //         std::cout << "value bst aval 0baad rightesh" << queue_for_bst[0]->value << "   " << queue_for_bst.size() << "  " << (queue_for_bst[0]->right)->value << std::endl;
    //         queue_for_bst.push_back(queue_for_bst[0]->right);
    //         queue_for_root.push_back(queue_for_root[0]->right);
    //     }
    //     if (queue_for_bst[0]->left != nullptr) {
    //         queue_for_root[0]->left = new Node(*(queue_for_bst[0]->left));
    //         std::cout << queue_for_bst[0]->value << "   " << queue_for_bst.size() << std::endl;
    //         // root->right = new Node(*(bst.root->right));
    //         queue_for_bst.push_back(queue_for_bst[0]->left);
    //         queue_for_root.push_back(queue_for_root[0]->left);
    //     }

    //     std::cout << queue_for_bst[0] << "   " << queue_for_bst.size() << std::endl;
    //     queue_for_bst.erase(queue_for_bst.begin());
    //     std::cout << "baad az earase" << queue_for_bst[0]->value << "   " << queue_for_bst.size() << std::endl;
    //     queue_for_root.erase(queue_for_root.begin());
    //     std::cout << "baad az earase" << queue_for_root[0]->value << "   " << queue_for_root.size() << std::endl;
    //     if (queue_for_bst.size() == 0) {
    std::cout << bst.root << *bst.root << std::endl;
    std::cout << root << *root << std::endl;
    std::cout << *this << std::endl;
    std::cout << bst << std::endl;
    return *this;
    //  }
    //}

    // root = bst.root;
}
bool BST::delete_node(int value)
{
    BST::Node** pointer_got_from_findnode { this->find_node(value) };
    // node not found
    if (pointer_got_from_findnode == nullptr) {
        return false;
    }

    // has two childs
    if ((*pointer_got_from_findnode)->right != nullptr && (*pointer_got_from_findnode)->left != nullptr) {
        BST::Node** pointer_we_got_parents { this->find_parrent(value) };
        BST::Node** pointer_to_successor { this->find_successor(value) };
        auto child_on_the_left { (*pointer_got_from_findnode)->left };
        auto child_on_the_right { (*pointer_got_from_findnode)->right };
        BST::Node** pointer_we_got_parents_to_successor { this->find_parrent((*pointer_to_successor)->value) };

        if ((*pointer_we_got_parents)->left != nullptr) {
            if ((*pointer_we_got_parents)->left->value == value) {
                // node is on the left of the parent thus we should assign the left pointer of the parrent to the successor

                // if child on the left is == to value?

                delete *pointer_got_from_findnode;
                // std::cout << "parent of successor" << (*pointer_we_got_parents_to_successor)->value << std::cout;
                (*pointer_we_got_parents)->left = *pointer_to_successor;

                (*pointer_to_successor)->left = child_on_the_left;
                (*pointer_to_successor)->right = child_on_the_right;
                std::cout << "in moshkele?2" << std::endl;
                // inja segmentation dari midi

                (*pointer_we_got_parents_to_successor)->right = nullptr;
                std::cout << "info on the deleted stuff" << (*pointer_to_successor)->value << (*pointer_to_successor)->right->value << (*pointer_to_successor)->left->value << std::endl;
                std::cout << "child on the left" << child_on_the_left << std::endl;
                std::cout << "child on the right" << child_on_the_right << std::endl;
                return 1;
            }
        }
        if ((*pointer_we_got_parents)->right != nullptr) {
            if ((*pointer_we_got_parents)->right->value == value) {
                // node is on the right of the parent thus we should assign the right pointer of the parent to the successor
                delete *pointer_got_from_findnode;

                (*pointer_we_got_parents)->right = *pointer_to_successor;

                (*pointer_to_successor)->left = child_on_the_left;
                (*pointer_to_successor)->right = child_on_the_right;

                (*pointer_we_got_parents_to_successor)->right = nullptr;

                return 1;
            }
        }
    }
    // has one child
    if ((*pointer_got_from_findnode)->right != nullptr || (*pointer_got_from_findnode)->left != nullptr) {
        // whether the child is on the right side or left side
        BST::Node** pointer_we_got_parents { this->find_parrent(value) };

        if ((*pointer_got_from_findnode)->right != nullptr) {
            // child is on the right
            std::cout << "in moshkele?1" << std::endl;
            if ((*pointer_we_got_parents)->left != nullptr) {
                std::cout << "in moshkele?2" << std::endl;
                if ((*pointer_we_got_parents)->left->value == value) {
                    // the node we want to delete is on the left side of the parent
                    // child on the right and the node on the left of the parent
                    std::cout << "the node we want to delete is on the left side of the parent" << std::endl;
                    auto pointer_to_child { (*pointer_got_from_findnode)->right };
                    delete *pointer_got_from_findnode;
                    (*pointer_we_got_parents)->left = pointer_to_child;
                    return 1;
                }
            }
            if ((*pointer_we_got_parents)->right != nullptr) {
                if ((*pointer_we_got_parents)->right->value == value) {
                    // the node we want to delete is on the right side of the parent
                    // child is on the right and the node on the right of the parent
                    std::cout << "the node we want to delete is on the right side of the parent" << std::endl;
                    auto pointer_to_child { (*pointer_got_from_findnode)->right };
                    delete *pointer_got_from_findnode;
                    (*pointer_we_got_parents)->right = pointer_to_child;
                }
            }
        } else {
            // the child is on the left
            std::cout << (*pointer_we_got_parents)->left->value << std::endl;
            if ((*pointer_we_got_parents)->left != nullptr) {
                std::cout << "in moshkele?2" << std::endl;
                if ((*pointer_we_got_parents)->left->value == value) {
                    // the node we want to delete is on the left side of the parent
                    // child on the left and the node on the left of the parent
                    std::cout << "the node we want to delete is on the left side of the parent" << std::endl;
                    auto pointer_to_child { (*pointer_got_from_findnode)->left };
                    delete *pointer_got_from_findnode;
                    (*pointer_we_got_parents)->left = pointer_to_child;
                    return 1;
                }
            }
            if ((*pointer_we_got_parents)->right != nullptr) {
                if ((*pointer_we_got_parents)->right->value == value) {
                    // the node we want to delete is on the right side of the parent
                    // child is on the left and the node on the right side of the parent
                    std::cout << "the node we want to delete is on the right side of the parent" << std::endl;
                    auto pointer_to_child { (*pointer_got_from_findnode)->left };
                    delete *pointer_got_from_findnode;
                    (*pointer_we_got_parents)->right = pointer_to_child;
                }
            }
        }
    }
    // has no child
    if ((*pointer_got_from_findnode)->right == nullptr && (*pointer_got_from_findnode)->left == nullptr) {
        BST::Node** pointer_we_got_parents { this->find_parrent(value) };
        std::cout << "value ha " << value << (*pointer_we_got_parents)->right->value << std::endl;
        if ((*pointer_we_got_parents)->right != nullptr) {
            if ((*pointer_we_got_parents)->right->value == value) {
                std::cout << "in moshkele?2" << std::endl;
                delete *pointer_got_from_findnode;
                (*pointer_we_got_parents)->right = nullptr;
            }
        }
        if ((*pointer_we_got_parents)->left != nullptr) {
            if ((*pointer_we_got_parents)->left->value == value) {
                std::cout << "in moshkele?1" << std::endl;
                delete *pointer_got_from_findnode;
                (*pointer_we_got_parents)->left = nullptr;
            }
        }

        return 1;
    }
}