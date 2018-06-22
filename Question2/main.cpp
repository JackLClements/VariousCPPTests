#include <iostream>

struct frog_traits {
    static const char name[];
    static const int number_of_legs = 4;
    static const int number_of_arms = 0;
    static const int weight = 250; // grams
};

struct zebra_traits {
    static const char name[];
    static const int number_of_legs = 4;
    static const int number_of_arms = 0;
    static const int weight = 10000; // grams
};

const char frog_traits::name[] = "frog";
const char zebra_traits::name[] = "zebra";


template <typename T> class Animal{
    public:
        //Constructors
        Animal(){ 
            name = T::name;
            number_of_legs = T::number_of_legs;
            number_of_arms = T::number_of_legs;
            weight = T::weight;
        }
        //Template classes aren't 'real' classes, so no need for rule of 3
        
        //Access methods
        const char* getName() const{
            return name;
        }
        int numArms() const{
            return number_of_arms;
        }
        int numLegs() const{
            return number_of_legs;
        }
        int getWeight() const{
            return weight;
        }
    
    private:
        const char* name; //pointer to memory, so needs to stay const
        int number_of_legs;
        int number_of_arms;
        int weight; //grams        
};

// End of template class

typedef Animal< frog_traits > Frog;
typedef Animal< zebra_traits > Zebra;

template< class T1, class T2 >
void CompareAnimals(const Animal< T1 >& animal1, const Animal< T2 >&
        animal2) {
    std::cout << "The difference between a " << animal1.getName() << " and a " << animal2.getName() << "\n";

    if (animal1.numLegs() != animal2.numLegs()) {
        std::cout << "is that a " << animal1.getName() << " has " << animal1.numLegs() << " legs ";
        std::cout << "and a " << animal2.getName() << " has " << animal2.numLegs() << " legs ";
        std::cout << "\n";
    }

    if (animal1.numArms() != animal2.numArms()) {
        std::cout << "is that a " << animal1.getName() << " has " << animal1.numArms() << " arms ";
        std::cout << "is that a " << animal2.getName() << " has " << animal2.numArms() << " arms ";
        std::cout << "\n";
    }

    std::cout << animal1.getName() << " is ";
    std::cout << ((animal1.getWeight() > animal2.getWeight()) ? "heavier" : "lighter");
    std::cout << " than a " << animal2.getName();
    std::cout << "\n";
}

int main(int argc, char *argv[]) {
    Frog my_frog;
    Zebra my_zebra;

    CompareAnimals(my_frog, my_zebra);
    return 0;
}
