#include "node.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

void paint(Graphics^ graph, Brush^ brushE, Brush^ brushT, Font^ drawF, String^ drawS, node* _node, int left, int right, int y)
{
	if (_node == nullptr) return;

	int x = (left + right) / 2;

	graph->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::HighQuality;

	graph->FillEllipse(brushE, x, y, 33, 33);

	drawS = Convert::ToString(_node->get_data());

	graph->DrawString(drawS, drawF, brushT, x, y);

	paint(graph, brushE, brushT, drawF, drawS, _node->get_left(), left, x, y + 40);
	paint(graph, brushE, brushT, drawF, drawS, _node->get_right(), x, right, y + 40);

}