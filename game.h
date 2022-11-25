#pragma once

#include "spatial_hash.h"

namespace Tmpl8
{
//forward declarations
class Tank;
class Rocket;
class Smoke;
class Particle_beam;


class Game
{
  public:
    void set_target(Surface* surface) { screen = surface; }
    void init();
    void shutdown();
    void updateSmokes();
    void updateExplosions();
    void updateTanks();
    void updateRockets();
    void update(float deltaTime);
    void draw();
    void tick(float deltaTime);
    void insertion_sort_tanks_health(const std::vector<Tank>& original, std::vector<const Tank*>& sorted_tanks, int begin, int end);
    void measure_performance();
  
    Tank& find_closest_enemy(Tank& current_tank);
    void rocket_collision_check(Rocket& rocket, spatial_hash* sh);

    void mouse_up(int button)
    { /* implement if you want to detect mouse button presses */
    }

    void mouse_down(int button)
    { /* implement if you want to detect mouse button presses */
    }

    void mouse_move(int x, int y)
    { /* implement if you want to detect mouse movement */
    }

    void key_up(int key)
    { /* implement if you want to handle keys */
    }

    void key_down(int key)
    { /* implement if you want to handle keys */
    }

  private:
    Surface* screen;

    vector<Tank> tanks;
    vector<Rocket> rockets;
    vector<Smoke> smokes;
    vector<Explosion> explosions;
    vector<Particle_beam> particle_beams;


    Font* frame_count_font;
    long long frame_count = 0;

    bool lock_update = false;

    spatial_hash* spatial_blue;
    spatial_hash* spatial_red;
    };

}; // namespace Tmpl8