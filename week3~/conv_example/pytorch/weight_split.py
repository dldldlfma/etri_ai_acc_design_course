import torch
import torch.nn as nn
import torch.nn.functional as F
import torchvision
import torchvision.transforms as transforms

class Net(nn.Module):

    def __init__(self):
        super(Net, self).__init__()
        # 1 input image channel, 6 output channels, 3x3 square convolution
        # kernel
        self.conv1 = nn.Conv2d(1, 6, 5)
        self.conv2 = nn.Conv2d(6, 16, 5)
        # an affine operation: y = Wx + b
        self.fc1 = nn.Linear(16 * 4 * 4, 84)  # 6*6 from image dimension
        self.fc2 = nn.Linear(84, 10)

    def forward(self, x):
        # Max pooling over a (2, 2) window
        x = F.max_pool2d(F.relu(self.conv1(x)), (2, 2))
        # If the size is a square you can only specify a single number
        x = F.max_pool2d(F.relu(self.conv2(x)), 2)
        x = x.view(-1, self.num_flat_features(x))
        x = F.relu(self.fc1(x))
        x = self.fc2(x)
        return x

    def num_flat_features(self, x):
        size = x.size()[1:]  # all dimensions except the batch dimension
        num_features = 1
        for s in size:
            num_features *= s
        return num_features


new_net = Net()
new_net.load_state_dict(torch.load("./model/mnist_weight.pth"))

print(dir(new_net.modules))
print(new_net.modules)

conv1_weight = new_net.conv1.weight
conv1_bias = new_net.conv1.bias
print(new_net.conv1.weight.shape)
print(new_net.conv1.bias.shape)

conv2_weight = new_net.conv2.weight
conv2_bias = new_net.conv2.bias
print(new_net.conv2.weight.shape)
print(new_net.conv2.bias.shape)


fc1_weight = new_net.fc1.weight
fc1_bias = new_net.fc1.bias
print(new_net.fc1.weight.shape)
print(new_net.fc1.bias.shape)


fc2_weight = new_net.fc2.weight
fc2_bias = new_net.fc2.bias
print(new_net.fc2.weight.shape)
print(new_net.fc2.bias.shape)

from pprint import pprint    
conv1_weight_flat = conv1_weight.view(-1)
print(conv1_weight_flat.shape)

conv2_weight_flat = conv2_weight.view(-1)
print(conv2_weight_flat.shape)

fc1_weight_flat = fc1_weight.view(-1)
fc2_weight_flat = fc2_weight.view(-1)


"""
for i in range(conv1_weight.shape[0]):
    for j in range(conv1_weight.shape[1]):
        for k in range(conv1_weight.shape[2]):
            for l in range(conv1_weight.shape[3]):
                print(i*25 + j * 25 + k*5 + l)
                print(conv1_weight[i][j][k][l] == conv1_weight_flat[i*25 + j * 25 + k*5 + l])
"""

f = open("conv1_weight.txt","w")
for i in range(150):
    data = "{}\n".format(conv1_weight_flat[i])
    f.write(data)
f.close

f = open("conv1_bias.txt","w")
for i in range(6):
    data = "{}\n".format(conv1_bias[i])
    f.write(data)
f.close

f = open("conv2_weight.txt","w")
for i in range(conv2_weight_flat.shape[0]):
    data = "{}\n".format(conv2_weight_flat[i])
    f.write(data)
f.close

f = open("conv2_bias.txt","w")
print(conv2_bias.shape[0])
for i in range(conv2_bias.shape[0]):
    data = "{}\n".format(conv2_bias[i])
    f.write(data)
f.close


f = open("fc1_weight.txt","w")
for i in range(fc1_weight_flat.shape[0]):
    data = "{}\n".format(fc1_weight_flat[i])
    f.write(data)
f.close

f = open("fc2_weight.txt","w")
for i in range(fc2_weight_flat.shape[0]):
    data = "{}\n".format(fc2_weight_flat[i])
    f.write(data)
f.close

f = open("fc1_bias.txt","w")
print(fc1_bias.shape[0])
for i in range(fc1_bias.shape[0]):
    data = "{}\n".format(fc1_bias[i])
    f.write(data)
f.close

f = open("fc2_bias.txt","w")
print(fc2_bias.shape[0])
for i in range(fc2_bias.shape[0]):
    data = "{}\n".format(fc2_bias[i])
    f.write(data)
f.close
