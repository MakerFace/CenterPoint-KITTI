#include <torch/serialize/tensor.h>
#include <torch/extension.h>
#include <vector>
#include <cuda.h>
#include <cuda_runtime_api.h>

#include "iou3d_cpu.h"
#include "iou3d_nms.h"


PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
	m.def("boxes_overlap_bev_gpu", &boxes_overlap_bev_gpu, "oriented boxes overlap");
	m.def("box_overlap_bev_gpu", &box_overlap_bev_gpu, "oriented pre-box overlap");
	m.def("boxes_iou_bev_gpu", &boxes_iou_bev_gpu, "oriented boxes iou");
	m.def("boxiou_bev_gpu", &box_iou_bev_gpu, "oriented pre-boxe iou");
	m.def("nms_gpu", &nms_gpu, "oriented nms gpu");
	m.def("nms_normal_gpu", &nms_normal_gpu, "nms gpu");
	m.def("boxes_iou_bev_cpu", &boxes_iou_bev_cpu, "oriented boxes iou");
}
