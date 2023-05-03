#include <ros.h>
#include <std_msgs/String.h>
#include <DynamixelWorkbench.h>
#include <string>

#if defined(__OPENCM904__)
#define DEVICE_NAME "3" //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
#elif defined(__OPENCR__)
#define DEVICE_NAME ""
#endif

#define BAUDRATE  57600

#define MOTOR1  1
#define MOTOR2  2
#define MOTOR3  3
#define MOTOR4  4
#define MOTOR5  5
#define MOTOR6  6
#define MOTOR7  7
#define MOTOR8  8
#define MOTOR9  9
//#define MOTOR10 10  연결x


//make publisher
std_msgs::String moter_num //string type으로 bookcase_num topic날림
ros::Publisher sceinaro_make("bookcase_num",  &moter_num)


DynamixelWorkbench dxl_wb;
ros::NodeHandle nh;

int motor_open[9] = {0,};
//int sensor_on[9] = {0,};
//int stack[9] = {0,};

uint16_t model_number = 0;
int32_t presentposition[13];
int initial_pos[13] = {0,};
int initial_1 = 0;
int initial_2 = 0;
int initial_3 = 0;
int initial_4 = 0;
int initial_5 = 0;
int initial_6 = 0;
int initial_7 = 0;
int initial_8 = 0;
int initial_9 = 0;
int initial_10 = 0;
uint8_t motor[13] = {0, MOTOR1, MOTOR2, MOTOR3, MOTOR4, MOTOR5, MOTOR6, MOTOR7, MOTOR8, MOTOR9};



void setup() {

  nh.initNode();
  nh.advertise(); //publisher node 생성
  
  Serial.begin(9600);
  Serial2.begin(9600);
}

void inital_func(){
  if (initial_1 == 0) {
    initial_pos[1] = presentposition[1];
    initial_1++;
  }
  
  if (initial_2 == 0) {
    initial_pos[2] = presentposition[2];
    initial_2++;
  }
  
  if (initial_3 == 0) {
    initial_pos[3] = presentposition[3];
    initial_3++;
  } 
  
  if (initial_4 == 0) {
    initial_pos[4] = presentposition[4];
    initial_4++;
  }

  if (initial_5 == 0) {
    initial_pos[5] = presentposition[5];
    initial_5++;
  }

  if (initial_6 == 0) {
    initial_pos[6] = presentposition[6];
    initial_6++;
  }

  if (initial_7 == 0) {
    initial_pos[7] = presentposition[7];
    initial_7++;
  }

  if (initial_8 == 0) {
    initial_pos[8] = presentposition[8];
    initial_8++;
  }

  if (initial_9 == 0) {
    initial_pos[9] = presentposition[9];
    initial_9++;
  }

}


void moter_motion(String tmp_data){
  switch(tmp_data){
    case "book1":
      dxl_wb.goalPosition(motor[1], (int32_t)(initial_pos[1] + 7900));
      motor_open[0] = 1;
      delay(6000);
      dxl_wb.goalPosition(motor[1], (int32_t)(initial_pos[1] + 100));
      motor_open[0] = 0;
      break;
    
    case "book2":
      dxl_wb.goalPosition(motor[2], (int32_t)(initial_pos[2] + 7900));
      motor_open[1] = 1;
      delay(30000);
      dxl_wb.goalPosition(motor[2], (int32_t)(initial_pos[2] + 100));
      motor_open[1] = 0;
      break;

    case "book3":
      dxl_wb.goalPosition(motor[3], (int32_t)(initial_pos[3] + 7900));
      motor_open[2] = 1;
      delay(6000);
      dxl_wb.goalPosition(motor[3], (int32_t)(initial_pos[3] + 100));
      motor_open[2] = 0;
      break;

    case "book4":
      dxl_wb.goalPosition(motor[4], (int32_t)(initial_pos[4] + 7900));
      motor_open[3] = 1;
      delay(6000);
      dxl_wb.goalPosition(motor[4], (int32_t)(initial_pos[4] + 100));
      motor_open[3] = 0;
      break;

    case "book5":
      dxl_wb.goalPosition(motor[5], (int32_t)(initial_pos[5] + 7900));
      motor_open[4] = 1;
      delay(6000);
      dxl_wb.goalPosition(motor[5], (int32_t)(initial_pos[5] + 100));
      motor_open[4] = 0;
      break;

    case "book6":
      dxl_wb.goalPosition(motor[6], (int32_t)(initial_pos[6] +7900));
      motor_open[5] = 1;
      delay(6000);
      dxl_wb.goalPosition(motor[6], (int32_t)(initial_pos[6] + 100));
      motor_open[5] = 0;
      break;

    case "book7":
      dxl_wb.goalPosition(motor[7], (int32_t)(initial_pos[7] +7900));
      motor_open[6] = 1;
      delay(6000);
      dxl_wb.goalPosition(motor[7], (int32_t)(initial_pos[7] + 100));
      motor_open[6] = 0;
      break;

    case "book8":
      dxl_wb.goalPosition(motor[8], (int32_t)(initial_pos[8] +7900));
      motor_open[7] = 1;
      delay(6000);
      dxl_wb.goalPosition(motor[8], (int32_t)(initial_pos[8] + 100));
      motor_open[7] = 0;
      break;

    case "book9":
      dxl_wb.goalPosition(motor[9], (int32_t)(initial_pos[9] +7900));
      motor_open[8] = 1;
      delay(6000);
      dxl_wb.goalPosition(motor[9], (int32_t)(initial_pos[9] + 100));
      motor_open[8] = 0;
      break;

    default:
      break;
  }
  sceinaro_make.publish(&tmp_data)
}

void loop() {
  std_msgs::String data;
  const char *log;
  dxl_wb.init(DEVICE_NAME, BAUDRATE, &log);

  dxl_wb.ping(motor[1], &model_number, &log); // 모터 모델 지정
  dxl_wb.ping(motor[2], &model_number, &log);
  dxl_wb.ping(motor[3], &model_number, &log);
  dxl_wb.ping(motor[4], &model_number, &log);
  dxl_wb.ping(motor[5], &model_number, &log);
  dxl_wb.ping(motor[6], &model_number, &log);
  dxl_wb.ping(motor[7], &model_number, &log);
  dxl_wb.ping(motor[8], &model_number, &log);
  dxl_wb.ping(motor[9], &model_number, &log);
  //dxl_wb.ping(motor[10], &model_number, &log);

  dxl_wb.setExtendedPositionControlMode(motor[1], &log); // 해당 모델 포지션 모드 설정
  dxl_wb.setExtendedPositionControlMode(motor[2], &log);
  dxl_wb.setExtendedPositionControlMode(motor[3], &log);
  dxl_wb.setExtendedPositionControlMode(motor[4], &log);
  dxl_wb.setExtendedPositionControlMode(motor[5], &log);
  dxl_wb.setExtendedPositionControlMode(motor[6], &log);
  dxl_wb.setExtendedPositionControlMode(motor[7], &log);
  dxl_wb.setExtendedPositionControlMode(motor[8], &log);
  dxl_wb.setExtendedPositionControlMode(motor[9], &log);
  //dxl_wb.setExtendedPositionControlMode(motor[10], &log);

  dxl_wb.torqueOn(motor[1], &log); // 토크 활성화
  dxl_wb.torqueOn(motor[2], &log);
  dxl_wb.torqueOn(motor[3], &log);
  dxl_wb.torqueOn(motor[4], &log);
  dxl_wb.torqueOn(motor[5], &log);
  dxl_wb.torqueOn(motor[6], &log);
  dxl_wb.torqueOn(motor[7], &log);
  dxl_wb.torqueOn(motor[8], &log);
  dxl_wb.torqueOn(motor[9], &log);
  //dxl_wb.torqueOn(motor[10], &log);
 
  dxl_wb.getPresentPositionData(motor[1], &presentposition[1], &log); // 초기 위치 지정
  dxl_wb.getPresentPositionData(motor[2], &presentposition[2], &log);
  dxl_wb.getPresentPositionData(motor[3], &presentposition[3], &log);
  dxl_wb.getPresentPositionData(motor[4], &presentposition[4], &log);
  dxl_wb.getPresentPositionData(motor[5], &presentposition[5], &log);
  dxl_wb.getPresentPositionData(motor[6], &presentposition[6], &log);
  dxl_wb.getPresentPositionData(motor[7], &presentposition[7], &log);
  dxl_wb.getPresentPositionData(motor[8], &presentposition[8], &log);
  dxl_wb.getPresentPositionData(motor[9], &presentposition[9], &log);
  //dxl_wb.getPresentPositionData(motor[10], &presentposition[10], &log);

  inital_func()

  while (Serial2.available()) {
    data = Serial2.readStringUntil(' ');
    moter_motion(data)

    //nh.spinOnce();


  }

}