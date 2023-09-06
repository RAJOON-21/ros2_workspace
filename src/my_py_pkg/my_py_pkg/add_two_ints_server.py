#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts

class AddTwoIntsServer(Node): 
    def __init__(self):
        super().__init__("add_two_ints_server") 
        self.server_ = self.create_service(AddTwoInts, "add_two_ints", self.callback_add_two_ints)    
        self.get_logger().info("Add Two Ints Server has been started")  
        

    def callback_add_two_ints(self, request, response):
        response.sum = request.a + request.b
        self.get_logger().info("Incoming request\na: %d b: %d" % (request.a, request.b)) 
        self.get_logger().info("Response: %d" % response.sum)
        return response    

def main(args=None):
    rclpy.init(args=args)
    node = AddTwoIntsServer() 
    rclpy.spin(node) 

if __name__ == '__main__':
    main()