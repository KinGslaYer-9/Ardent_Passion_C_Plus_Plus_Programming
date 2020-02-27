#include <iostream>
using namespace std;

class Car	// �⺻ ���� �ڵ���
{
private:
	int gasolineGauge;
public:
	Car(int gasoline) : gasolineGauge(gasoline)
	{ }
	int GetGasGauge()
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car	// ���̺긮�� �ڵ���
{
private:
	int electricGauge;
public:
	HybridCar(int gasoline, int electric)
		: electricGauge(electric), Car(gasoline)
	{ }
	int GetElecGauge()
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar		// ���̺긮�� ����ī
{
private:
	int waterGauge;
public:
	HybridWaterCar(int gasoline, int electric, int water)
		: waterGauge(water), HybridCar(gasoline, electric)
	{ }
	void ShowCurrentGauge()
	{
		cout << "�ܿ� ���ָ�: " << GetGasGauge() << endl;
		cout << "�ܿ� ���ⷮ: " << GetElecGauge() << endl;
		cout << "�ܿ� ���ͷ�: " << waterGauge << endl;
	}
};

int main(void)
{
	HybridWaterCar car1(10, 20, 50);
	car1.ShowCurrentGauge();

	HybridWaterCar car2(200, 300, 10);
	car2.ShowCurrentGauge();
	return 0;
}