class ICar
{
public:

    virtual void EngineStart() = 0;

    virtual void EngineStop() = 0;

    virtual void Refuel(double liters) = 0;

    virtual void RunningIdle() = 0;

protected:

    bool engineIsRunning = false;
};
class IEngine
{
public:

    virtual void Consume(double liters) = 0;

    virtual void Start() = 0;

    virtual void Stop() = 0;

protected:

    bool isRunning = false;
};

class IFuelTank
{
public:

    virtual void Consume(double liters) = 0;

    virtual void Refuel(double liters) = 0;

protected:

    double fillLevel = 0.0;

    bool isOnReserve = false;

    bool isComplete = false;
};

class IFuelTankDisplay
{
protected:

    double fillLevel = 0.0;

    bool isOnReserve = false;

    bool isComplete = false;
};
class FuelTank : public IFuelTank
{
public:

    FuelTank() {
        fillLevel = 20.0;
        UpdateStatus();
    }
    void Consume(double liters) {
        fillLevel -= liters;
        if (fillLevel < 0.0) {
            fillLevel = 0.0;
        }
        UpdateStatus();
    }
    void Refuel(double liters) {
        fillLevel += liters;
        if (fillLevel > 60.0) {
            fillLevel = 60.0;
        }
        UpdateStatus();
    }
    double getFillLevel() {
        return fillLevel;
    }
    double getIsComplete() {
        return isComplete;
    }
    double getIsOnReserve() {
        return isOnReserve;
    }
private:
    void UpdateStatus() {
        isOnReserve = (fillLevel < 5.0);
        isComplete = (fillLevel >= 60.0);
    }
};
class Engine : public IEngine
{
private:
    FuelTank* fueltank;  // Store reference to FuelTank

public:
    // Constructor that accepts a FuelTank reference
    Engine(FuelTank* tank) : fueltank(tank) {}

    void Start() {
        isRunning = true;
    }
    void Stop() {
        isRunning = false;
    }
    void Consume(double liters) {
        if (fueltank != nullptr) {
            fueltank->Consume(liters);  // Safely consume fuel from the tank
        }
    }
};



class FuelTankDisplay : public IFuelTankDisplay
{
private:
    FuelTank* fueltank;
public:
    FuelTankDisplay(FuelTank* fueltank) {
        this->fueltank = fueltank;
    }
    double getFillLevel() {
        return fueltank->getFillLevel();
    }
    double getIsComplete() {
        return fueltank->getIsComplete();
    }
    double getIsOnReserve() {
        return fueltank->getIsOnReserve();
    }
};

class Car : public ICar
{
public:
    FuelTank fueltank;              // Declare fueltank before fuelTankDisplay
    FuelTankDisplay fuelTankDisplay;

private:
    Engine engine;                  // No longer default-initialize, pass fueltank reference
    bool engineIsRunning;

public:
    Car() : fueltank(), fuelTankDisplay(&fueltank), engine(&fueltank) {  // Pass reference to engine
        engineIsRunning = false;
    }

    Car(double initialFuel) : fueltank(), fuelTankDisplay(&fueltank), engine(&fueltank) {  // Pass reference to engine
        fueltank.Refuel(initialFuel - fueltank.getFillLevel());
        engineIsRunning = false;
    }

    bool getEngineIsRunning() const {
        return engineIsRunning;
    }

    void EngineStart() {
        engine.Start();
        engineIsRunning = true;
    }

    void EngineStop() {
        engine.Stop();
        engineIsRunning = false;
    }

    void Refuel(double liters) {
        fueltank.Refuel(liters);
    }

    void RunningIdle() {
        if (engineIsRunning) {
            engine.Consume(0.0003);
            if (fueltank.getFillLevel() <= 0.0) {
                EngineStop();
            }
        }
    }
};


int main() {

}