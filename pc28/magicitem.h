#include "item.h"

class MagicItem : public Item{
    
    public:
        
        //MagicItem()
        //:Item("magicitem",0), description("no description")
        //{}
        
        MagicItem(string newName = "magicitem", unsigned int newValue = 0, string newDescription = "no description", unsigned int newManaRequired = 0){
            
            setName(newName);
            
            setValue(newValue);
            
            description = newDescription;
            
            manaRequired = newManaRequired;
        }
        
        void setDescription(string newDescription){
            description = newDescription;
        }
        
        void setManaRequired(unsigned int newManaRequired){
            manaRequired = newManaRequired;
        }
        
        string getDescription(){
            return description;
        }
        
        unsigned int getManaRequired(){
            return manaRequired;
        }
        
        string toString(){
            stringstream stream;
            
            stream << getName() << ", $" << getValue() << ", " << description << ", requires " << manaRequired << " mana"; 
            
            return stream.str();
        }
        
        
        
    private:
    
        string description;
        
        unsigned int manaRequired;
    
};