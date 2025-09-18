#include <iostream>
#include <string>
#include <string_view>

class Dog
{
public:
    Dog(std::string_view name_param, std::string_view breed_param)
    {
        name = name_param;
        breed = breed_param;
    };

    void print_info()
    {
        std::cout << "Dog (" << this << ") : [ name : " << name << " breed : " << breed << " ]" << std::endl;
    }

    // Setters with references (method chaining using &)
    Dog &set_dog_name(std::string_view name)
    {
        this->name = name;
        return *this;
    }
    Dog &set_dog_breed(std::string_view breed)
    {
        this->breed = breed;
        return *this;
    }

private:
    std::string name;
    std::string breed;
};

class Bird
{
public:
    Bird(std::string_view name_param, std::string_view breed_param, int age_param)
    {
        name = name_param;
        breed = breed_param;
        p_age = new int(age_param); // allocate + initialize
    };

    ~Bird()
    {
        delete p_age;
        std::cout << "Bird destructor called for " << name << " at " << this << std::endl;
    };

    void print_info()
    {
        std::cout << "Bird (" << this << ") : [ name : " << name
                  << " breed : " << breed
                  << " age : " << *p_age << "]" << std::endl;
    }

    // Setters with pointers (method chaining using ->)
    Bird *set_Bird_name(std::string_view name)
    {
        this->name = name;
        return this;
    }
    Bird *set_Bird_breed(std::string_view breed)
    {
        this->breed = breed;
        return this; 
    }
    Bird *set_Bird_age(int age)
    {
        *this->p_age = age;
        return this;
    }

private:
    std::string name;
    std::string breed;
    int *p_age{nullptr};
};

int main()
{
    Dog dog1("Fluffy", "Shepherd");
    dog1.print_info();

    // Chained calls using references (&)
    dog1.set_dog_name("Pumba")
        .set_dog_breed("Wire Fox Terrier");
    dog1.print_info();

    Bird bird1("Tweety", "Parrot", 2);
    bird1.print_info();

    // Chained calls using pointers (*)
    bird1.set_Bird_name("Rio")
         ->set_Bird_breed("Macaw")
         ->set_Bird_age(3);
    bird1.print_info();

    return 0;
}
