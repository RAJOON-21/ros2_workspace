#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("add_two_ints_client_no_oop");
    
    auto client = node->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");

    rclcpp::shutdown();
    return 0;
}