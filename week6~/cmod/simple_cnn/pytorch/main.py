import torch
import torch.nn as nn
import torch.nn.functional as F
import torchvision
import torchvision.transforms as transforms


transform = transforms.Compose(
    [transforms.ToTensor()])

trainset = torchvision.datasets.MNIST(root='./mnist', train=True,
                                        download=True, transform=transform)
trainloader = torch.utils.data.DataLoader(trainset, batch_size=4,
                                          shuffle=True, num_workers=2)

testset = torchvision.datasets.MNIST(root='./mnist', train=False,
                                       download=True, transform=transform)
testloader = torch.utils.data.DataLoader(testset, batch_size=4,
                                         shuffle=False, num_workers=2)

classes = ('0', '1', '2', '3',
           '4', '5', '6', '7', '8', '9')


data_loader = torch.utils.data.DataLoader(dataset=trainset, batch_size=64, shuffle=True, drop_last=True)


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


model = Net()
value = (torch.Tensor(1,1,28,28))
print(model)
print(model(value).shape)

criterion = nn.CrossEntropyLoss()
optimizer = torch.optim.Adam(model.parameters(), lr = 0.002)

total_batch = len(data_loader)
training_epochs=15


for epoch in range(training_epochs):
    avg_cost=0
    for X, Y in data_loader:
        optimizer.zero_grad()
        print(X[0].shape)
        f = open("test_data.txt","w")
        for i in range(28):
            for j in range(28):
                data="{}\n".format(X[0][0][i][j])
                f.write(data)
        print(Y[0])
        break
        hypothesis = model(X)

        cost = criterion(hypothesis, Y)
        cost.backward()
        optimizer.step()

        avg_cost += cost / total_batch
    print('[Epoch:{}] cost = {}'.format(epoch+1, avg_cost))
    break
print('Learning Finish!')

#torch.save(model.state_dict(), "./model/mnist_weight.pth")

#new_net = Net()
#new_net.load_state_dict(torch.load("./model/mnist_weight.pth"))



