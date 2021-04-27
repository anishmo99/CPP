class WagonR : public Car{
	public :
	int mileage;
	
	WagonR(int mil){
		Car(false, 4); 
		mileage = mil;
	}

	string getMileage(){
		string s;

		while(mileage){
			s.push_back('0' + (mileage%10));
			mileage /= 10;
		}

		reverse(s.begin(), s.end());
		s += " kmpl";

		return s;
	}
};

class HondaCity : public Car{
	public :
	int mileage;
	
	HondaCity(int mil){
		Car(true, 4);
		mileage = mil;
	}

	string getMileage(){
		string s;

		while(mileage){
			s.push_back('0' + (mileage%10));
			mileage /= 10;
		}

		reverse(s.begin(), s.end());
		s += " kmpl";

		return s;
	}
};

class InnovaCrysta : public Car{
	public :
	int mileage;
	
	InnovaCrysta(int mil){
		Car(false, 6);
		mileage = mil;
	}

	string getMileage(){
		string s;

		while(mileage){
			s.push_back('0' + (mileage%10));
			mileage /= 10;
		}

		reverse(s.begin(), s.end());
		s += " kmpl";

		return s;
	}
};