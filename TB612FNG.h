int STBY; //standby

//Motor A
int PWMA; //Speed control 
int AIN1; //Direction
int AIN2; //Direction

//Motor B
int PWMB; //Speed control 
int BIN1; //Direction
int BIN2; //Direction

class TB612FNG {
  public: 
    TB612FNG(
      int PWMA, int PWMB, int AIN1, int AIN2, int BIN1, int BIN2, int STBY
    )
    void run(int motor, int speed)
    void stop(int motor)
    void standby()
  private:
    int STBY;
    int PWMA;
    int PWMA;
    int AIN1;
    int AIN2;
    int BIN1;
    int BIN2;
}