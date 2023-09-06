#include "rclcpp/rclcpp.hpp"
using namespace std;

class MyNode : public rclcpp::Node
{
public:
    MyNode() : Node("cpp_test"), counter_(0)
    {
        RCLCPP_INFO(this->get_logger(), "Hello, cpp node!");
        timer_ = this->create_wall_timer(chrono::seconds(1),
                                            bind(&MyNode::timerCallback,this));
    }

private:
    void timerCallback()
    {
            counter_++;
            RCLCPP_INFO(this->get_logger(), "Hello %d",counter_);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    int counter_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = make_shared<MyNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}