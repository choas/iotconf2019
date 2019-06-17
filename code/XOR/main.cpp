#include "models/xor_relu.hpp"  //gernerated model file
#include "tensor.hpp"  //useful tensor classes
#include "mbed.h"
#include <stdio.h>

Serial pc(USBTX, USBRX, 115200);  //baudrate := 115200

DigitalIn a(D2);
DigitalIn b(D3);
DigitalOut led(LED1);

int main(void) {
  printf("XOR uTensor cli example (device)\n");

  a.mode(PullDown); 
  b.mode(PullDown); 
  
  while(1) {

    Context ctx;  //creating the context class, the stage where inferences take place 

    float v1 = static_cast< float >( a.read() );
    float v2 = static_cast< float >( b.read() );
    
    //wrapping the input data in a tensor class
    const float input_data [ 2 ] = { v1, v2 };

    Tensor* input_x = new WrappedRamTensor<float>({1, 2}, (float*) input_data);

    get_xor_relu_ctx(ctx, input_x);  // pass the tensor to the context
    S_TENSOR pred_tensor = ctx.get("y_pred:0"); // getting a reference to the output tensor
    ctx.eval(); //trigger the inference

    int pred = *(pred_tensor->read<int>(0, 0));  //getting the result back
    printf("predicted: %d %d %d\r\n", a.read(), b.read(), pred);

    led = pred;

    wait(0.1);
  }

  return 0;
}
