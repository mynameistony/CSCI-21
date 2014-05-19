#include "item.h"
#include <iomanip>
class FoodItem : public Item {
    
    public:
        
        ~FoodItem(){}
        
        //FoodItem()
        //:Item(), calories(0), unitOfMeasure("nounits"),units(0)
        //{}
        
        FoodItem(string newName = "fooditem", unsigned int newValue = 0, unsigned int newCalories = 0, string newUnitOfMeasure = "nounits", float newUnits = 0.00){
            setName(newName);
            
            setValue(newValue);
            
            calories = newCalories;
            
            unitOfMeasure = newUnitOfMeasure;
            
            units = newUnits;
        }
        
        void setCalories(unsigned int newCalories){
            calories = newCalories;
        }
        
        void setUnitOfMeasure(string newUnitOfMeasure){
            unitOfMeasure = newUnitOfMeasure;
        }
        
        void setUnits(float newUnits){
            units = newUnits; 
        }
        
        unsigned int getCalories(){
            return calories;
        }
        
        string getUnitOfMeasure(){
            return unitOfMeasure;
        }
        
        float getUnits(){
            return units;
        }
        
        string toString(){
            stringstream stream;
            
            stream >> std::fixed;
            stream.precision(2);
            
            stream << getName() << ", $" << getValue() << ", "  << units << " " << unitOfMeasure << ", " << calories << " calories";
            
            return stream.str();
        }
        
        
    private:
    
        unsigned int calories;
    
        string unitOfMeasure;
    
        float units;    
};