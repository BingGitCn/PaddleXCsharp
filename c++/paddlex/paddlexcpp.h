//   Copyright (c) 2020 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _PADDLEXCPP_H_
#define _PADDLEXCPP_H_

namespace PaddleXCpp {

#define _PADDLEX_DEBUG_
#define MAX_CATEGORY_STR_LEN 63
	
#pragma pack (1)
	
	typedef struct cls_result {
//	char category[MAX_CATEGORY_STR_LEN+1];
	int category_id;
	float score;
	}t_cls_result;
	
	typedef struct det_result {
//	char category[MAX_CATEGORY_STR_LEN+1];
	float category_id;
	float score;
	float coordinate[4];
	}t_det_result;
	
#pragma pack ()

	extern "C" __declspec(dllexport) void* __cdecl CreatePaddlexModel(int *model_type,
            										char* model_dir,
            										bool use_gpu = false,
            										bool use_trt = false,
            										bool use_mkl = true,
            										int mkl_thread_num = 4,
            										int gpu_id = 0,
            										char* key = "",
            										bool use_ir_optim = true);
	
	/*
	PaddlexClsPredict�����ӿ�˵��:
	���:
		model:ģ��ָ�룬��CreatePaddlexModel��������ֵ��
		img:��Ҫ�����ͼƬ����ָ��
		height:ͼƬ�߶�(����)
		width:ͼƬ���(����)
		channels:ͼƬͨ����
		category:���ص��������е����IDֵ
		score:���ص��������еķ���
	����ֵ:
		�����Ƿ�ɹ�
	*/
	extern "C" __declspec(dllexport) bool __cdecl PaddlexClsPredict(void* model, unsigned char *img, int height, int width, int channels, int *category, float *score);

	/*
	PaddlexDetPredict�����ӿ�˵��:
	���:
		model:ģ��ָ�룬��CreatePaddlexModel��������ֵ��
		img:��Ҫ�����ͼƬ����ָ��
		height:ͼƬ�߶�(����)
		width:ͼƬ���(����)
		channels:ͼƬͨ����
		result:���ص����������ڲ��ṹΪ:"flost���͵�box_num"+box_num��"���+����+�ع��(xmin, ymin, w, h)"
		visualize:�Ƿ���н�����ӻ���Ĭ�Ͻ��п��ӻ�������ԭͼimg�ϻ���Ԥ���box��
	����ֵ:
		�����Ƿ�ɹ�
	*/
	extern "C" __declspec(dllexport) bool __cdecl PaddlexDetPredict(void* model, unsigned char *img, int height, int width, int channels, int max_box, float *result, bool visualize = true);

	/*
	PaddlexDetPredict�����ӿ�˵��:
	���:
		model:ģ��ָ�룬��CreatePaddlexModel��������ֵ��
		img:��Ҫ�����ͼƬ����ָ��
		height:ͼƬ�߶�(����)
		width:ͼƬ���(����)
		channels:ͼƬͨ����
		label_map:���ص�label_map�������������Ϊint64���ͣ�����Ϊheight*width
		score_map:���ص�score_map�������������Ϊfloat���ͣ�����Ϊheight*width
		visualize:�Ƿ���н�����ӻ���Ĭ�Ͻ��п��ӻ�������ԭͼimg�ϵ��ӷָ�����
	����ֵ:
		�����Ƿ�ɹ�
	*/
	extern "C" __declspec(dllexport) bool __cdecl PaddlexSegPredict(void* model, unsigned char *img, int height, int width, int channels, int64_t *label_map, float *score_map, bool visualize = true);
}  // namespace PaddleXCpp

#endif//_PADDLEXCPP_H_

