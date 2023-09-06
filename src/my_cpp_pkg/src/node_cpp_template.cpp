#include "rclcpp/rclcpp.hpp"

using namespace std;

class MyNode : public rclcpp::Node // CHANGE
{
public:
    MyNode() : Node("cpp_test") // CHANGE NODE NAME
    {
        
    }
    
private:
    
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = make_shared<MyNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}