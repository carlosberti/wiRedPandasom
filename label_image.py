import os, sys

import tensorflow as tf

os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

image_path = sys.argv[1]

image_data = tf.gfile.FastGFile(image_path, 'rb').read()

label_lines = [line.rstrip() for line 
                   in tf.gfile.GFile("retrained_labels.txt")]

with tf.gfile.FastGFile("retrained_graph.pb", 'rb') as f:
    graph_def = tf.GraphDef()
    graph_def.ParseFromString(f.read())
    tf.import_graph_def(graph_def, name='')

with tf.Session() as sess:
    softmax_tensor = sess.graph.get_tensor_by_name('final_result:0')
    
    predictions = sess.run(softmax_tensor, \
             {'DecodeJpeg/contents:0': image_data})
    

    top_k = predictions[0].argsort()[-len(predictions[0]):][::-1]
    
    for i in [0, 1, 2]:
    	print(label_lines[0])
