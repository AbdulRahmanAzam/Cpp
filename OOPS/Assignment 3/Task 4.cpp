
#include <iostream>
#include<cmath>
using namespace std;

class Drone
{
private:
    float latitude;
    float longitude;
    float altitude;
    float speed;

public:
    Drone(float latitude, float longitude, float altitude, float speed)
        : latitude(latitude), longitude(longitude), altitude(altitude), speed(speed)
    {
    }

    float getLatitude() const { return latitude; }
    float getLongitude() const { return longitude; }
    float getAltitude() const { return altitude; }
    float getSpeed() const { return speed; }

    void setLatitude(float latitude) { this->latitude = latitude; }
    void setLongitude(float longitude) { this->longitude = longitude; }
    void setAltitude(float altitude) { this->altitude = altitude; }
  
    virtual void adjustAltitude(float meters) = 0;
    virtual void setSpeed(float speed){this->speed=speed;};
};
class Flyable : virtual public Drone
{
public:
Flyable(float latitude, float longitude, float altitude, float speed):Drone(latitude, longitude, altitude, speed){}
    virtual void takeoff() = 0;
    virtual void land() = 0;
    virtual void navigateTo(float latitude, float longitude, float altitude) = 0;
};
class Scannable : virtual public Drone
{
public:
Scannable(float latitude, float longitude, float altitude, float speed):Drone(latitude, longitude, altitude, speed){}
    virtual void scanArea(float radius) = 0;
};
class ReconDrone : public Flyable, public Scannable
{
private:
    int cameraResol;
    int maxFlightTime;

public:
    ReconDrone(float latitude, float longitude, float altitude, float speed, int cameraResol)
        : Flyable(latitude, longitude, altitude, speed),Scannable(latitude, longitude, altitude, speed),Drone(latitude, longitude, altitude, speed), cameraResol(cameraResol), maxFlightTime(0)
    {
    }
    void setCameraResol(int cameraResol) { this->cameraResol = cameraResol; }
    void adjustAltitude(float meters) override
    {
        setAltitude(getAltitude()+meters);
    }
    void takeoff() override
	{
		cout<<"Taking off "<<endl;
	}
   void navigateTo(float latitude, float longitude,float altitude) override
	{
		float a=pow(latitude-getLatitude(),2)+pow(longitude-getLongitude(),2)+pow(altitude-getAltitude(),2);
		float distance=sqrt(a);
		cout<<"Distance is: "<<distance<<endl;
		cout<<"Estimated time is: "<<distance/getSpeed()<<endl;
        scanArea(distance);
	}
	void land()
	{
		cout<<"Landing now "<<endl;
	}
    void scanArea(float radius) override
    {
        int objects;
		objects=3;

		int i;
		try
		{
			if(objects==0) 
			{
				throw objects;
			}
			for(i=1;i<=objects;i++)
			{	
                cout<<"Object number: "<<i+1<<endl;
				setLatitude(i+1.6);
				cout<<"Latitude: "<<getLatitude()<<endl;
				setLongitude(i+1.6);
				cout<<"Longitude: "<<getLongitude()<<endl;
				
			}
		}
		catch(int objects)
		{
			cout<<"failure."<<endl;
		}
    };
};
int main()
{
    cout << "23k-0061 Abdul Rahman Azam" << endl;
    ReconDrone r1(32.4,13.4,44.3,98,560);
    r1.navigateTo(25,23,65);
    return 0;
};
