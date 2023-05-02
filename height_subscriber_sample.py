#!/usr/bin/env python3
#-*- coding:utf-8 -*-	# 한글 주석을 달기 위해 사용한다.

import rospy
from std_msgs.msg import Float32


data = None #전역변수로 선언을 해주고


def callbackFunction(msg): #기본 argument는 구독한 메세지 객체 
    #callback : topic이 발행되는 이벤트가 발생하였을 때 event lisner함수를 콜백함수로 요구
    global data
    data = msg
    rospy.loginfo(data)


def height_subscriber():
    subscriber = rospy.Subscriber(
        name="height", data_class=Float32, callback=callbackFunction)
    rospy.init_node("height_subscriber")
    rate = rospy.Rate(0.5) # 1000hz

    while not rospy.is_shutdown(): #-> c++에서 ros.ok() 느낌

        rospy.loginfo(rospy.get_time())
        rate.sleep() #100hz가 될때 까지 쉬기




if __name__ == '__main__':
    try:
        height_subscriber()
    except rospy.ROSInterruptException:
        pass
