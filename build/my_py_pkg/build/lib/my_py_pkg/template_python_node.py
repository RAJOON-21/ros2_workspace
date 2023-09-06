#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

class MyCustomNode(Node): # Change the name of the class
    def __init__(self):
        super().__init__("node_name") # Change the name of the node
        

def main(args=None):
    rclpy.init(args=args)
    node = MyCustomNode() # Change the name of the class
    rclpy.spin(node) # spin() will block until the node is shutdown
    rclpy.shutdown()

if __name__ == '__main__':
    main()