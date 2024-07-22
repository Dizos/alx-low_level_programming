#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a dog's basic info
 * @name: First member, type = char *
 * @age: Second member, type = float
 * @owner: Third member, type = char *
 * Description: Longer description
 */
struct dog
{
    char *name;
    float age;
    char *owner;
};

/* Function prototype */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /* DOG_H */
