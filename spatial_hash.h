#pragma once
typedef vector<Tank*> spatialCell;

class spatial_hash
{
public:
	int width;
	int height;
	int cell_size;
	int x_start;
	int y_start;
	int cell_amount;

	std::vector<spatialCell> cells;

	spatial_hash(int height, int width, int cell_size, int x, int y);

	void add_tank(Tank* tank);
	void delete_tank(Tank* tank);
	void move_tank(Tank* tank, float x, float y);
	spatialCell* position_to_cell(float x, float y);
	int spatial_hash::get_cell_size();
};