#!/usr/bin/env python3
#-*- coding:utf-8 -*-	# 한글 주석을 달기 위해 사용한다.


''' azure에서 보내는 publish 정보
        std_msgs::Float32 msg;
        msg.data = 0;
        pub.publish(msg);

TrackerNode::TrackerNode(ros::NodeHandle& _nh)
{
	nh=_nh;
	lengthPub = nh.advertise<std_msgs::Float32>("length",1000);	
}
'''

import rospy
from std_msgs.msg import Float32


data = None #전역변수로 선언을 해주고

def callbackFunction(msg): #기본 argument는 구독한 메세지 객체 
    #callback : topic이 발행되는 이벤트가 발생하였을 때 event lisner함수를 콜백함수로 요구
    global data
    data = msg
    rospy.loginfo(data)


def az_subscriber():
    subscriber = rospy.Subscriber(
        name="length", data_class=Float32, callback=callbackFunction)
    rospy.init_node("az_subscriber")
    rate = rospy.Rate(0.5) # 0.5hz

    while not rospy.is_shutdown(): #-> c++에서 ros.ok() 느낌
        rospy.loginfo(rospy.get_time())
        rate.sleep() #100hz가 될때 까지 쉬기



if __name__ == '__main__':
    try:
        az_subscriber()

        if data == 0:
            print("사람이 인식되지 않음")
        elif data >= 1500:
            print("1500 이상")
        else:
            print("1500 이하")
    except rospy.ROSInterruptException:
        pass