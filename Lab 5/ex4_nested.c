#include <stdio.h>
#include <math.h>

typedef struct { 
    float x; 
    float y; 
} Vec2;

typedef struct {
    char  name[32];
    Vec2  position;
    Vec2  velocity;
    float health;
} Entity;

void move_entity(Entity *e, float dt);
float distance(Vec2 a, Vec2 b);
void print_entity(const Entity *e);

int main(void) {
    Entity entity1 = {
        "Raul", 
        {0.0f, 0.0f}, 
        {2.0f, 1.0f}, 
        100.f
    };

    Entity entity2 = {
        "Diego", 
        {7.6f, 1.5f}, 
        {3.0f, 3.0f}, 
        120.f
    };

    printf("--First State--\n");
    print_entity(&entity1);
    print_entity(&entity2);

    move_entity(&entity1, 0.5f);
    move_entity(&entity2, 0.5f);
    move_entity(&entity1, 0.5f);

    printf("--Final State--\n");
    print_entity(&entity1);
    print_entity(&entity2);
    printf("The distance between the two entities is %.2f", distance(entity1.position, entity2.position));

}

void move_entity(Entity *e, float dt) {
    e->position.x += e->velocity.x * dt;
    e->position.y += e->velocity.y * dt;
}

float distance(Vec2 a, Vec2 b) {
    float dx = b.x - a.x;
    float dy = b.y -a.y;
    
    return sqrt((dx * dx) + (dy * dy));
}

void print_entity(const Entity *e) {
    printf("--Info--\n");
    printf("Name: %s\n", e->name);
    printf("Position: (%.2f , %.2f)\n", e->position.x, e->position.y);
    printf("Health: %.2f\n",e->health);
}