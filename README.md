# Embedded Devices and Machine Learning Models (uTensor)
 
[Why Machine Learning on The Edge?](https://towardsdatascience.com/why-machine-learning-on-the-edge-92fac32105e6)

[Why the Future of Machine Learning is Tiny](https://petewarden.com/2018/06/11/why-the-future-of-machine-learning-is-tiny/)

## TensorBoard

```sh
cd python
source bin/activate
tensorboard --logdir notebooks/logs
```

[http://localhost:6006/](http://localhost:6006/)

## uTensor convert

```sh
utensor-cli convert ../../python/notebooks/models/deep_mlp.pb --output-nodes=y_pred
```

```sh
mbed compile -m nucleo_f411re -t GCC_ARM --profile=uTensor/build_profile/release.json
```

### logging

```sh
screen /dev/cu.usbmodem14603 115200
```
