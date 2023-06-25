#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@Description:       :
@Date     :2023/03/09 16:24:52
@Author      :chenqi
@version      :1.0
'''
import os

kitti_root = "../data/kitti/kitti-openpdet"
train_set = os.path.join(kitti_root, "ImageSets/trainval.txt")
train = os.path.join(kitti_root, "training/label_2")

result = {}
with open(train_set, 'r') as f:
    for seq in f:
        if seq[-1] == '\n':
            seq = seq[:-1]
        print("process {}...".format(seq))
        label = os.path.join(train, "{}.txt".format(seq))
        with open(label) as l:
            for item in l:
                strs = item.split(' ')
                if result.get(strs[0]) is None:
                    result[strs[0]] = 0
                result[strs[0]] = result[strs[0]] + 1

print(result)