// PointDrawing.cpp

#include "stdafx.h"
#include "PointDrawing.h"
#include "HPoint.h"

PointDrawing point_drawing;

PointDrawing::PointDrawing(void)
{
	temp_object = NULL;
}

PointDrawing::~PointDrawing(void)
{
}

bool PointDrawing::calculate_item(DigitizedPoint &end)
{
	if(end.m_type == DigitizeNoItemType)return false;

	if(temp_object && temp_object->GetType() != PointType){
		delete temp_object;
		temp_object = NULL;
		temp_object_in_list.clear();
	}

	if(!temp_object){
		temp_object = new HPoint(end.m_point, &wxGetApp().current_color);
		if(temp_object)temp_object_in_list.push_back(temp_object);
	}
	else{
		((HPoint*)temp_object)->m_p = end.m_point;
	}

	return true;
}

void PointDrawing::clear_drawing_objects(bool store_as_previous_objects)
{
	temp_object = NULL;
	temp_object_in_list.clear();
}
