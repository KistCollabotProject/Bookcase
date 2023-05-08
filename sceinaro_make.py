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


OpenCR 에서 보내는 정보     

ros::Publisher sceinaro_make("bookcase_num",  &moter_num)
std_msgs::String moter_num //string type으로 bookcase_num topic날림

'''

import rospy
from std_msgs.msg import Float32, String


class sceinaro:
    def __init__(self):

        self.ac = None
        self.bookcase = None
        self.sceinaro = None

        rospy.init_node('sceinaro_node', anonymous=True)

        self.subscriber1 = rospy.Subscriber(
            name="ac_information", data_class=String, callback=self.callbackFunction1)

        self.subscriber2 = rospy.Subscriber(
            name="bookcase_num", data_class=String, callback=self.callbackFunction2)
        
        self.subscriber3 = rospy.Subscriber(
            name="bookcase_num", data_class=String, callback=self.callbackFunction2)

        
        self.scei_publisher = rospy.Publisher('sceinaro_num', String, queue_size=10)
        self.rate = rospy.Rate(30) # 0.5hz


    def callbackFunction1(self,msg): #ac를 인식하는 부분
        #callback : topic이 발행되는 이벤트가 발생하였을 때 event lisner함수를 콜백함수로 요구
        self.ac = msg.data
        rospy.loginfo(self.ac)
        #self.publisher.publish(self.ac)\
    
    def callbackFunction2(self,msg):
        self.bookcase = msg.data
        rospy.loginfo(self.bookcase)

    def sceinaro_make(self):
        while not rospy.is_shutdown(): #-> c++에서 ros.ok() 느낌
            bookcase_num = int(self.bookcase[-1])
            if self.ac == "adult": #여기서는 책을 3권 뽑았는지 판단
                
                pass
            elif self.ac == "child":
                if bookcase_num >= 1 and bookcase_num <=3: # 최상단일 경우
                    self.sceinaro = "sceinaro 1"
                    self.publisher.publish(self.sceinaro)
                else: #손에 닿는 경우
                    pass
            else:
                rospy.loginfo("Something was wrong with ac or bookcase_num") 
            self.rate.sleep() #100hz가 될때 까지 쉬기

            


if __name__ == '__main__':
    try:
        s = sceinaro()
        s.acpub_azsub_action()
    except rospy.ROSInterruptException:
        pass
