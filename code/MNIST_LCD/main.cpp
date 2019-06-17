#include "mbed.h"
#include "LCD_DISCO_L476VG.h"


#include "models/deep_mlp.hpp"  //gernerated model file
#include "tensor.hpp"  //useful tensor classes
//#include <stdio.h>
#include "input_data.h"  //contains the first sample taken from the MNIST test set




LCD_DISCO_L476VG lcd;

DigitalOut led_green(LED1);

int main()
{

  printf("Simple MNIST end-to-end uTensor cli example (device)\n");

  Context ctx;  //creating the context class, the stage where inferences take place 
  //wrapping the input data in a tensor class
  Tensor* input_x = new WrappedRamTensor<float>({1, 784}, (float*) input_data);

  get_deep_mlp_ctx(ctx, input_x);  // pass the tensor to the context
  S_TENSOR pred_tensor = ctx.get("y_pred:0");  // getting a reference to the output tensor
  ctx.eval(); //trigger the inference

  int pred_label = *(pred_tensor->read<int>(0, 0));  //getting the result back
  printf("Predicted label: %d\r\n", pred_label);


    lcd.Clear();
    // lcd.DisplayString((uint8_t *)"HELLO");


    uint8_t stemp[7] = {0};

        sprintf((char *)stemp, "L %d", pred_label);
        lcd.DisplayString(stemp);

}

// int main()
// {
//     uint32_t temp = 0;
//     uint8_t stemp[7] = {0};
//     uint8_t title[] = "      DISCOVERY STM32L476";
  
//     printf("Hello\n");
//     led_green = 1;
//     lcd.Clear();
//     lcd.DisplayString((uint8_t *)"HELLO");
//     wait(1);
    
//     printf("Scroll sequence\n");
//     led_green = 0;
//     lcd.Clear();
//     lcd.ScrollSentence(title, 2, 200);
//     lcd.Clear();
  
//     while(1) {
//         printf("BAR = %d\n", temp);
//         sprintf((char *)stemp, "BAR %d", temp);
//         lcd.DisplayString(stemp);
//         lcd.BarLevelConfig((uint8_t)temp);
//         temp++;
//         if (temp > 4) temp = 0;
//         led_green = !led_green;
//         wait(1);
//     }
// }
