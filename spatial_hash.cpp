#include "precomp.h"
#include "spatial_hash.h"


spatial_hash::spatial_hash(int height, int width, int cell_size, int x, int y):height(height),width(width), cell_size(cell_size), y_start(y), x_start(x) 
{
	cell_amount = (height / cell_size) * (width / cell_size);

	for (int i = 0; i < cell_amount; i++) {
		cells.push_back(spatialCell());
	}
}

void spatial_hash::add_tank(Tank* tank) {
	
	spatialCell* cell = position_to_cell(tank->position.x, tank->position.y);

	cell->push_back(tank);
}

void spatial_hash::delete_tank(Tank* tank) {

	spatialCell* cell = position_to_cell(tank->position.x, tank->position.y);

	for (int i = 0; i < cell->size(); i++) {
		if (tank == cell->at(i)) {
			cell->erase(cell->begin()+i);
			return;
		}
	}
}

void spatial_hash::move_tank(Tank* tank, float x, float y) {
	
	delete_tank(tank);

	tank->position.x = x;
	tank->position.y = y;

	add_tank(tank);
}

spatialCell* spatial_hash::position_to_cell(float x, float y) {

	x += x_start;
	y += y_start;

	const int cell_index = floor(x / cell_size) + (floor(y / cell_size) * (width / cell_size));
	return &cells[cell_index];

}

int spatial_hash::get_cell_size() {
	return cell_size;
}

